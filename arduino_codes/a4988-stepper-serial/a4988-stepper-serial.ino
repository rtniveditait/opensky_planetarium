    /*     Simple Stepper Motor Control Exaple Code
     *      
     *  by Dejan Nedelkovski, www.HowToMechatronics.com
     *  
     */
    // defines pins numbers
    #include <Stepper.h>
    const int stepPin = 5; 
    const int dirPin = 4; 
     
    void setup() {
      // Sets the two pins as Outputs
      pinMode(stepPin,OUTPUT); 
      pinMode(dirPin,OUTPUT);
      while (!Serial);
  
  Serial.begin(9600);
  //motor.setSpeed(20);
      //Serial.begin(9600);
    }
    void loop() {
      
   /*    
        if(Serial.available())
      { 
         digitalWrite(dirPin,HIGH);
        int steps = Serial.parseInt();
        digitalWrite(stepPin, steps);
       // delayMicroseconds(1000); 
        } */
     digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
      // Makes 200 pulses for making one full cycle rotation
      for(int x = 0; x < 200; x++) {
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(1000); 
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(1000); 
      }
      delay(1000); // One second delay
      
      digitalWrite(dirPin, LOW); //Changes the rotations direction
      // Makes 400 pulses for making two full cycle rotation
      for(int x = 0; x < 2000; x++) {
        digitalWrite(stepPin,HIGH);
        delayMicroseconds(1000);
        digitalWrite(stepPin,LOW);
        delayMicroseconds(1000);
      }
      delay(1000); 
    }
