//written for Arduino-UNO by praveen kumar
#define m11 5                               //left motor pins inputs to L293D
#define m12 4             
#define m21 7                               //right motor pins inputs to L293D
#define m22 6
                                            //inputs from DTMF module(4 bits)
#define D0 A5                               //defining A5 pin as D0
#define D1 A4                               //defining A4 pin as D1
#define D2 A3                               //defining A3 pin as D2
#define D3 A2                               //defining A2 pin as D3

void forward()                              //function to run the motor forward
{
   digitalWrite(m11, HIGH);                 //setting motor1 high
   digitalWrite(m12, LOW);                  //setting motor2 low
   digitalWrite(m21, HIGH);                 //setting motor3 high
   digitalWrite(m22, LOW);                  //srtting mptpr4 low
}

void backward()                              //function to run the motor backward
{
   digitalWrite(m11, LOW);                   //setting motor1 low
   digitalWrite(m12, HIGH);                  //setting motor2 high
   digitalWrite(m21, LOW);                   //setting motor3 low
   digitalWrite(m22, HIGH);                  //setting motor4 high
}

void left()                                   //function to run the motor left
{
   digitalWrite(m11, HIGH);                   //setting motor1 high
   digitalWrite(m12, LOW);                    //setting motor2 low
   digitalWrite(m21, LOW);                    //setting motor3 low
   digitalWrite(m22, LOW);                    //setting motor4 low
}

void right()                                  //function to run the motor right
{
   digitalWrite(m11, LOW);                    //setting motor1 low
   digitalWrite(m12, LOW);                    //setting motor2 low
   digitalWrite(m21, HIGH);                   //setting motor3 HIGH
   digitalWrite(m22, LOW);                    //setting motor4 low
}

void Stop()                                   //function to run the motor stop
{
   digitalWrite(m11, LOW);                    //setting m11 pin low(motor1 first pin)
   digitalWrite(m12, LOW);                    //setting m12 pin low(motor2 second pin)
   digitalWrite(m21, LOW);                    //setting m21 pin low(motor2 third pin)
   digitalWrite(m22, LOW);                    //setting m22 pin low(motor3 fourth pin)
}

void setup()                                  //one time execution code will be placed here
{
  pinMode(D0, INPUT);                         //setting D0 as input
  pinMode(D1, INPUT);                         //setting D1 as input
  pinMode(D2, INPUT);                         //setting D2 as input
  pinMode(D3, INPUT);                         //setting D3 as input

  pinMode(m11, OUTPUT);                       //setting m11 as output
  pinMode(m12, OUTPUT);                       //setting m12 as output
  pinMode(m21, OUTPUT);                       //setting m21 as output
  pinMode(m22, OUTPUT);                       //setting m22 as output
}

void loop()                                       //which runs forever
{

  int temp1=analogRead(D0);                       //reads the inputs from D0 pin and stores in temp1 folder
  int temp2=analogRead(D1);                       //reads the inputs from D1 pin and stores in temp2 folder
  int temp3=analogRead(D2);                       //reads the inputs from D3 pin and stores in temp3 folder
  int temp4=analogRead(D3);                       //reads the inputs from D4 pin and stores in temp4 folder
  if(temp1==0 && temp2>0 && temp3==0 && temp4==0) //condition for detecting 2 input from the keyboard
  forward();

  if(temp1==0 && temp2==0 && temp3>0 && temp4==0) //condition for detecting 4 input from the keyboard
  left();

  if(temp1==0 && temp2>0 && temp3>0 && temp4==0)  //condition for detecting 6 input from the keyboard
  right();

  if(temp1==0 && temp2==0 && temp3==0 && temp4>0) //condition for detecting 8 input from the keyboard
  backward();

  if(temp1>0 && temp2==0 && temp3>0 && temp4==0)  //condition for detecting 5 input from the keyboard
  Stop();
}
