#include <Stepper.h>
int dir=8;
int stepp=9;
int microSecDelay = 20000;
int ms3=12;
int ms2=11;
int ms1=10;

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
  digitalWrite(ms3, HIGH);
  }

void loop()
{
  digitalWrite(stepp, HIGH);       // Step motor
  delay(30);
  
  //delayMicroseconds(microSecDelay);  // Wait microseconds
  digitalWrite(stepp, LOW);        // Step motor
  delay(30);

  //delayMicroseconds(microSecDelay);  // Wait microseconds
  }
