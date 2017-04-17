
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 400;  // change this to fit the number of steps per revolution
// for your motor
//const int stepsPerRevolution2 = 200;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper1(stepsPerRevolution, 4, 6, 5, 7);
Stepper myStepper2(stepsPerRevolution, 8, 10, 9, 11);
//Stepper motor2(512, in5Pin, in6Pin, in7Pin, in8Pin); 
void setup() {
  // set the speed at 60 rpm:
  myStepper1.setSpeed(30);
   myStepper2.setSpeed(30);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper1.step(stepsPerRevolution);
  myStepper2.step(stepsPerRevolution);  
 
  // myStepper1.step(-stepsPerRevolution);
 // myStepper2.step(stepsPerRevolution);  
  //myStepper1.step(stepsPerRevolution2);
  delay(2000);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
 // myStepper1.step(-stepsPerRevolution);
// myStepper2.step(stepsPerRevolution); 
   myStepper1.step(-stepsPerRevolution);
  myStepper2.step(-stepsPerRevolution);
 // myStepper.step(stepsPerRevolution2);
  delay(2000);
}

