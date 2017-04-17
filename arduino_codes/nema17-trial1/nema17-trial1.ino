#include <Stepper.h>
int dir=2;
int stepp=3;
int microSecDelay = 20000;
int ms3=8;
int ms2=9;
int ms1=10;
int count = 0;

void setup()
{
  pinMode(dir, OUTPUT);       // Assign output mode to pin for direction
  pinMode(stepp, OUTPUT);      // Assign output mode to pin for setp
  digitalWrite(dir, HIGH);     // Initialize dir pin 
  digitalWrite(stepp, LOW);    // Initialize step pin

  pinMode(ms3, OUTPUT);
  pinMode(ms2, OUTPUT);
  pinMode(ms1, OUTPUT);

  digitalWrite(ms1, HIGH);
  digitalWrite(ms2, HIGH);  
  digitalWrite(ms3, LOW);

  Serial.begin(9600);
  
  }

void loop()
{
  for(count=0;count<80;count++)
  //while(count<10 && reverse==0)
  {
  Serial.println("forward");
  Serial.println(count);
  digitalWrite(dir, HIGH);     // Initialize dir pin 
  digitalWrite(stepp, HIGH);       // Step motor
  delay(500);
  
  //delayMicroseconds(microSecDelay);  // Wait microseconds
  digitalWrite(stepp, LOW);        // Step motor
  delay(500);
  //count++;
  //forward=0;
  }

  for(count=80;count>=0;count--)
 // while(count>=10 && forward==0)
  {
  Serial.println("Reverse");
  Serial.println(count);
  digitalWrite(dir, LOW);     // Initialize dir pin 
  digitalWrite(stepp, HIGH);       // Step motor
  delay(500);
  
  //delayMicroseconds(microSecDelay);  // Wait microseconds
  digitalWrite(stepp, LOW);        // Step motor
  delay(500);
  //count--;
  }

  //delayMicroseconds(microSecDelay);  // Wait microseconds
  }
