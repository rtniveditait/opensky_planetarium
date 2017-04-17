// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 9; 
// Create a servo object 
Servo Servo1; 
//int pos = 0;
//int servodata;
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 
   Serial.begin(9600);
   Serial.println("Ready");
   
}
void loop(){ 
 
  // Make servo go to 90 degrees 
  Servo1.write(45); 
   delay(1000); 
    Servo1.write(90); 
   delay(1000); 
    Servo1.write(135 ); 
   delay(1000); 
   // Make servo go to 180 degrees 
 Servo1.write(180); 
   delay(1000); 
   
}
