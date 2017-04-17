// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 9; 
// Create a servo object 
Servo Servo1; 
int pos = 0;
int angle;
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 
   Serial.begin(9600);
   Serial.println("Ready");
   Serial.println("Enter angle1 = ");
   
}
void loop(){ 
 
 if (Serial.available()>0)
 { angle = Serial.read();

    if(angle == '1')
    {
      Serial.println("rotate 15 degree");
      Servo1.write(10);
      delay(1000);
    }
 if(angle == '2')
 {
  Serial.println("rotate 30 degree");
      Servo1.write(60);
      delay(1000);
 }
  if(angle == '3')
 {
  Serial.println("rotate 45 degree");
      Servo1.write(90);
          delay(1000);
 }
 if(angle == '4')
 {
  Serial.println("rotate 360 degree");
      Servo1.write(360);
      delay(1000);
 
 }
  }
 } 
 
  // Make servo go to 90 degrees 
 /* Servo1.write(45); 
   delay(1000); 
    Servo1.write(90); 
   delay(1000); 
    Servo1.write(135 ); 
   delay(1000); 
   // Make servo go to 180 degrees 
 Servo1.write(180); 
   delay(1000); */
   
