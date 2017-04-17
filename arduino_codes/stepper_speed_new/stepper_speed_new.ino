//1024 steps = 360 Degree
#include<AccelStepper.h>
//#include <Stepper.h>
#define HALFSTEP 8
int in1Pin = 8;
int in2Pin = 9;
int in3Pin = 10;
int in4Pin = 11;
//  motor1.setMaxSpeed(1000.0);
/*int in5Pin = 4;
int in6Pin = 5;
int in7Pin = 6;
int in8Pin = 7; */
 
AccelStepper motor1(HALFSTEP, in1Pin, in2Pin, in3Pin, in4Pin);
//Stepper motor2(512, in5Pin, in6Pin, in7Pin, in8Pin);  
 
void setup()
{
  motor1.setMaxSpeed(1000.0);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  
  /*pinMode(in5Pin, OUTPUT);
  pinMode(in6Pin, OUTPUT);
  pinMode(in7Pin, OUTPUT);
  pinMode(in8Pin, OUTPUT);*/
 
  // this line is for Leonardo's, it delays the serial interface
  // until the terminal window is opened
  while (!Serial);
  
  Serial.begin(9600);
  motor1.setSpeed(20);
    motor1.setAcceleration(1);
//  motor2.setSpeed(20);
}
 
void loop()
{
  if (Serial.available())
  {
    int steps = Serial.parseInt();    
    //motor1.moveTo(steps);
    motor1.runSpeed();
    //motor2.step(steps);
  }
}
