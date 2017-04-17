#include <Stepper.h>
//#include <string.h>
    
    #define OUT1  2
    #define OUT2  3
    #define OUT3  4
    #define OUT4  5
    #define IN1 6
     int steps = 0;
     int _axis;
     bool _dir;
     int index = 1;
     

void setup() {
    Serial.begin(9600);
    pinMode(OUT1, OUTPUT); 
    pinMode(OUT2, OUTPUT); 
    pinMode(OUT3, OUTPUT); 
    pinMode(OUT4, OUTPUT);
    pinMode(IN1, INPUT);
    

}

void loop() {
  
  //Serial.println(index);
  float count = 2165/360*90;
  if(digitalRead(IN1)==LOW && steps!=count)
  {
    
    steps=steps+1;
  stepper_move(OUT1,true,index);
  index= index+1;
  if(index>4)
  {index=1;}
  delay(10);
  //Serial.println(steps);  
  }

}

/* This function is called by the following s/w commands
 *  set1/set2/set3
 *  move
 *  time
*/

/*
float serialGetFloat(){
  char bytes[9], sign;
  int nbytes = 0;
  float fex;
  bool recv = false;
  
  bytes[8] = '\0';
  Serial.println("float");
  while(!recv){
    if (Serial.available() > 0) {
      sign = Serial.read();//Float with eight representation bytes (including dot and sign)
      while(nbytes < 8)
        if(Serial.available() > 0){
          bytes[nbytes] = Serial.read();
          nbytes++;
        }
      fex = strtod(bytes, NULL);
      if(sign=='-')
        fex = 0.0 - fex;
      recv = true;
    }
  }
  Serial.println("_OK_");
  return fex;
}*/

void stepper_move(int _axis,bool _dir, int index)       
        {
          int A;
          int B;
          int C;
          int D;
          int ptr;
          
          if(_axis == OUT1)//For X axis
            {
              A = OUT1;
              B = OUT2;
              C = OUT3;
              D = OUT4;
            }
            /*
            if(_axis ==_stPin1_y)//For Y axis
            {
              A = _stPin1_y;
              B = _stPin2_y;
              C = _stPin3_y;
              D = _stPin4_y;
            }*/
            
          if(_dir == true)//CounterClockwise 
          {
            if(index==1)
            ptr=4;
            if(index==2)
            ptr=3;
            if(index==3)
            ptr=2;
            if(index==4)
            ptr=1;
            
          }     

            if(_dir == false)//Clockwise 
          {
            if(index==1)
            ptr=1;
            if(index==2)
            ptr=2;
            if(index==3)
            ptr=3;
            if(index==4)
            ptr=4;
            
          } 
          /*       //Fullstepping
              if(index == 1) 
              {
                digitalWrite(A, HIGH);
                digitalWrite(B, HIGH);
                digitalWrite(C, LOW);
                digitalWrite(D, LOW);
              }
               if(index == 2)
              {
                digitalWrite(A, LOW);
                digitalWrite(B, HIGH);
                digitalWrite(C, HIGH);
                digitalWrite(D, LOW);
              }  
              if(index == 3)
              {
                digitalWrite(A, LOW);
                digitalWrite(B, LOW);
                digitalWrite(C, HIGH);
                digitalWrite(D, HIGH);
              }
              if(index == 4)
              {
                digitalWrite(A, HIGH);
                digitalWrite(B, LOW);
                digitalWrite(C, LOW);
                digitalWrite(D, HIGH);
              }

              */ 
              //wave drive

               if(ptr==1)
              {
                digitalWrite(A, HIGH);
                digitalWrite(B, LOW);
                digitalWrite(C, LOW);
                digitalWrite(D, LOW);
                //Serial.println("first");
              }
               if(ptr==2)
              {
                digitalWrite(A, LOW);
                digitalWrite(B, HIGH);
                digitalWrite(C, LOW);
                digitalWrite(D, LOW);
                //Serial.println("second");
              }  
              if(ptr==3)
              {
                digitalWrite(A, LOW);
                digitalWrite(B, LOW);
                digitalWrite(C, HIGH);
                digitalWrite(D, LOW);
                //Serial.println("third");
              }
              if(ptr==4)
              {
                digitalWrite(A, LOW);
                digitalWrite(B, LOW);
                digitalWrite(C, LOW);
                digitalWrite(D, HIGH);
                //Serial.println("fourth");
              }
        }
