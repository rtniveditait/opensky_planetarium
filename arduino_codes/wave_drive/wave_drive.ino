#include <Stepper.h>

    #define IN1  2
    #define IN2  3
    #define IN3  4
    #define IN4  5
     int Steps = 0;

void setup() {
    Serial.begin(9600);
    pinMode(IN1, OUTPUT); 
    pinMode(IN2, OUTPUT); 
    pinMode(IN3, OUTPUT); 
    pinMode(IN4, OUTPUT); 

}

void loop() {
   
         digitalWrite(IN1, HIGH); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, LOW);
       delay(1000);
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, HIGH);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, LOW);
              delay(1000);

         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, HIGH);
         digitalWrite(IN4, LOW);
             delay(1000);

         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, HIGH);
       delay(1000);

   
}
