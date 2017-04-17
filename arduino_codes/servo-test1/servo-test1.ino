#include <Servo.h>
Servo myservo;

void setup() 
    { 
      myservo.attach(9); 
      Serial.begin(9600);
      myservo.write(0); //or another starting value
    } 


    void loop() 
    { 
      //reset the values each loop but only reprint
      //them to the servo if you hit the while loop
      int angle = 0;

      while(Serial.available() > 0){
        //Get char in and convert to int
        char a = Serial.read();
        int c = (int)a - 48;
        //values will come in one character at a time
        //so you need to increment by a power of 10 for
        //each character that is read
        angle *= 10;
        //then add the 1's column
        angle += c;
        //then write the angle inside the loop
        //if you do it outside you will keep writing 0
        Serial.println(angle);//TODO this is a check. comment out when you are happy
        myservo.write(angle);
      }


    }
