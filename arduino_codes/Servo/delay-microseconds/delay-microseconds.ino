#include <Servo.h>
int servoPin = 9;   // pin attached to servo
int pos = 1500;     // initial servo position 

void setup() {                
  pinMode(servoPin, OUTPUT);     
}

void loop() {
  digitalWrite(servoPin, HIGH);   // start PPM pulse
  delayMicroseconds(pos);         // wait pulse diration
 // Serial.println(pos);
  digitalWrite(servoPin, LOW);    // complete the pulse
    // Note: delayMicroseconds() is limited to 16383µs
    // see http://arduino.cc/en/Reference/DelayMicroseconds
    // Hence delayMicroseconds(20000L-pos); has been replaced by:
  
  Serial.println(servoPin);
  delayMicroseconds(5000-pos);   // adjust to 5ms period
  delay(15);                      // pad out 5ms to 20ms PPM period
}
