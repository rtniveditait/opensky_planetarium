/*
#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper1(stepsPerRevolution, 8, 9, 10, 11);
Stepper myStepper2(stepsPerRevolution, 4, 5, 6, 7);

void setup() {
  // set the speed at 60 rpm:
  myStepper1.setSpeed(100);
  myStepper2.setSpeed(100);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper1.step(stepsPerRevolution);
  delay(1000);
  myStepper2.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper1.step(-stepsPerRevolution);
  myStepper2.step(-stepsPerRevolution);
  delay(500);
} */
#include <Stepper.h>
#include<AccelStepper.h>
#define HALFSTEP 8
int in1Pin = 8;
int in2Pin = 9;
int in3Pin = 10;
int in4Pin = 11;

AccelStepper motor1(HALFSTEP, in1Pin, in2Pin, in3Pin, in4Pin);
//const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
//Stepper myStepper1(stepsPerRevolution, 8, 9, 10, 11);
//Stepper myStepper2(stepsPerRevolution, 4, 5, 6, 7);

void setup() {
  // set the speed at 60 rpm:
  motor1.setMaxSpeed(1000);
 // myStepper2.setSpeed(100);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  
  motor1.run();
 // motor1.step(HALFSTEP);
  delay(1000);
  //motor2.step(HALFSTEP);
  //delay(500);

  // step one revolution in the other direction:
 // Serial.println("counterclockwise");
  //myStepper1.step(-stepsPerRevolution);
 // myStepper2.step(-stepsPerRevolution);
 // delay(500);
 
}




