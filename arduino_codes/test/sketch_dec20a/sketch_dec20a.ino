//1024 steps = 360 Degree
//#include<AccelStepper.h>
#include <Stepper.h>
#define HALFSTEP 8
int in1Pin = 8;
int in2Pin = 10;
int in3Pin = 9;
int in4Pin = 11;
//  motor1.setMaxSpeed(1000.0);
int in5Pin = 4;
int in6Pin = 6;
int in7Pin = 5;
int in8Pin = 7;
 
Stepper motor1(512, in1Pin, in2Pin, in3Pin, in4Pin);
Stepper motor2(512, in5Pin, in6Pin, in7Pin, in8Pin);  
 
void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  //motor1.setMaxSpeed(1000.0);
  pinMode(in5Pin, OUTPUT);
  pinMode(in6Pin, OUTPUT);
  pinMode(in7Pin, OUTPUT);
  pinMode(in8Pin, OUTPUT);
 
  // this line is for Leonardo's, it delays the serial interface
  // until the terminal window is opened
  while (!Serial);
  
  Serial.begin(9600);
  motor1.setSpeed(20);
 motor2.setSpeed(20);
}
 
void loop()
{
  if (Serial.available())
  {
    int steps1 = Serial.parseInt();
    int steps2 = Serial.parseInt();
    if(abs(steps1)>=abs(steps2))
    {
      int div = abs(steps1/steps2);
      if(steps1<0)
      {
        div = div * -1;
      }
      Serial.println(div);
//      int mod = 
    while(steps2!=0)
    {
      motor1.step(div);
      steps1 = steps1 -div;
      if(steps2>0)
      {
        motor2.step(1);
        steps2--;
      }
      else if(steps2<0)
      {
        motor2.step(-1);
        steps2++;
      }
//      Serial.print(steps1);
//      Serial.print(":");
//      Serial.println(steps2);
    }
    motor1.step(steps1);
    }
    else
    {
      int div = abs(steps2/steps1);
      if(steps2<0)
      {
        div = div * -1;
      }
      Serial.println(div);
//      int mod = 
    while(steps1!=0)
    {
      motor2.step(div);
      steps2 = steps2 -div;
      if(steps1>0)
      {
        motor1.step(1);
        steps1--;
      }
      else if(steps1<0)
      {
        motor1.step(-1);
        steps1++;
      }
    }
    motor2.step(steps2);
    }
  }
}
