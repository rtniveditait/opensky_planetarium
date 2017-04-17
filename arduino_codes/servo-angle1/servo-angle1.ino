/*
 Moving the servo motor according to the angles given through serial monitor.
 precision is 1 degree, If you give less than one degree it can't move.
*/

#include <Servo.h>
//#include <VarSpeedServo.h>

Servo myServo;  // create servo object to control a servo
int val;    // variable to read the value from the analog pin
//int servoPin = 9;

void setup() {
  myServo.attach(9,0,360);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); 

}

void loop() {
  if (Serial.available()) // check for input on the serial monitor
{
  int val = Serial.parseInt(); // returns valid integer number received from serial read(Converts into angles)
 //myServo.slowmove(val,15);
  myServo.write(val);     //sets the servo position according to the input value
  Serial.println(val);
  delay(1000);
  
}
 
}

