/*
 Moving the servo motor according to the angles given through serial monitor.
 precision is 1 degree, If you give less than one degree it can't move.
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); 
}

void loop() {
  if (Serial.available()) // check for input on the serial monitor
{
  int val = Serial.parseInt(); // returns valid integer number received from serial read(Converts into angles)
  myservo.write(val);     //sets the servo position according to the input value
  Serial.println(val);
  delay(1000);
}
 
}

