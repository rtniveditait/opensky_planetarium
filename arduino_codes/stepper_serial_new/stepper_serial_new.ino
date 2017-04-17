//1024 steps = 360 Degree
//#include<AccelStepper.h>
#include <Stepper.h>
#define HALFSTEP 8
int in1Pin = 2;
int in2Pin = 4;
int in3Pin = 3;
int in4Pin = 5;
//  motor1.setMaxSpeed(1000.0);
int in5Pin = A0;
int in6Pin = A2;
int in7Pin = A1;
int in8Pin = A3;
 
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
    motor1.step(steps1);
  motor2.step(steps2);
  }
}
