#include <Stepper.h>
int dir=2;
int stepp=3;
int microSecdelay = 0;
int ms3=8;
int ms2=9;
int ms1=10;
int count=0;
int dir1=11;
int stepp1=12; 
int ms11=6;
int ms22=5;
int ms33=4;
int pulse = 1600;
int FREQ = 200;

void setup()
{
  DDRD = DDRD | B11111100; 
  pinMode(dir, OUTPUT);       // Assign output mode to pin for direction
  pinMode(stepp, OUTPUT);      // Assign output mode to pin for setp
  //digitalWrite(dir, HIGH);     // Initialize dir pin 
  //digitalWrite(stepp, LOW);    // Initialize step pin
  pinMode(dir1, OUTPUT);       // Assign output mode to pin for direction
  pinMode(stepp1, OUTPUT);      // Assign output mode to pin for setp
  //digitalWrite(dir1, HIGH);     // Initialize dir pin 
  //digitalWrite(stepp1, LOW);    // Initialize step 
//  pinMode(ms3, OUTPUT);
//  pinMode(ms2, OUTPUT);
//  pinMode(ms1, OUTPUT);
//  pinMode(ms33, OUTPUT);
//  pinMode(ms22, OUTPUT);
//  pinMode(ms11, OUTPUT);
  
  digitalWrite(ms1, HIGH); // 1/8th microstepping
  digitalWrite(ms2, HIGH);  
  digitalWrite(ms3, LOW);
  digitalWrite(ms11, HIGH);
  digitalWrite(ms22, HIGH);  
  digitalWrite(ms33, LOW);

  Serial.begin(9600);
  FREQUENCY();
  
  }
void PASS()
{
  digitalWrite(stepp, LOW);       // Pulso nÃ­vel baixo 
  delayMicroseconds (microSecdelay);   // Atraso de X microsegundos
  digitalWrite(stepp1, LOW);       // Pulso nÃ­vel baixo 
  delayMicroseconds (microSecdelay);   // Atraso de X microsegundos  
  digitalWrite(stepp, HIGH);      // Pilso nÃ­vel alto
  delayMicroseconds (microSecdelay);   // Atraso de X microsegundos  
  digitalWrite(stepp1, HIGH);      // Pilso nÃ­vel alto
  delayMicroseconds (microSecdelay);   // Atraso de X microsegundos 
}

void FREQUENCY()
{
  microSecdelay = 10000000/(2*FREQ);
}

void forward()
{
  digitalWrite(dir, HIGH);
  digitalWrite(dir1, HIGH);
}

void Reverse()
{
 digitalWrite(dir, LOW);
 digitalWrite(dir1, LOW); 
}

void Test()
{
  forward();
  for(count=0;count<50;count++)
  //while(count<10 && reverse==0)
  { 
    PASS();
    delay(20);
   
//  Serial.println("forward");
//  Serial.println(count);
//  digitalWrite(dir, HIGH);     // Initialize dir pin 
//  digitalWrite(stepp, HIGH);       // Step motor
// delay(100);
// // delayMicroseconds(2500);
//  
//  //delayMicroseconds(microSecDelay);  // Wait microseconds
//  digitalWrite(stepp, LOW);        // Step motor
// delay(100);
//  //delayMicroseconds(2500);
//  digitalWrite(dir1, HIGH);     // Initialize dir pin 
//  digitalWrite(stepp1, HIGH);       // Step motor
// delay(100);
//  //delayMicroseconds(2500);
//  
//  //delayMicroseconds(microSecDelay);  // Wait microseconds
//  digitalWrite(stepp1, LOW);        // Step motor
// delay(100);
//  //delayMicroseconds(2500);
//  //count++;
//  //forward=0;
  }
delay(1500);

Reverse();
  for(count=50;count>=0;count--)
 // while(count>=10 && forward==0)
  {
    PASS();
    delay(20);
  }
//  Serial.println("Reverse");
//  Serial.println(count);
//  digitalWrite(dir, LOW);     // Initialize dir pin 
//  digitalWrite(stepp, HIGH);       // Step motor
// delay(100);
//  //delayMicroseconds(2500);
//  //delayMicroseconds(microSecDelay);  // Wait microseconds
//  digitalWrite(stepp, LOW);        // Step motor
//  delay(100);
// // delayMicroseconds(2500);
//  digitalWrite(dir1, LOW);     // Initialize dir pin 
//  digitalWrite(stepp1, HIGH);       // Step motor
//  delay(100);
//  //delayMicroseconds(2500);
//  //delayMicroseconds(microSecDelay);  // Wait microseconds
//  digitalWrite(stepp1, LOW);        // Step motor
//  delay(100);
  //delayMicroseconds(2500);
  //count--;
  
delay(1500);
  //delayMicroseconds(microSecDelay);  // Wait microseconds
  }

void loop()
{
  FREQ = 200;
  FREQUENCY();
  pulse = 1600;
  Test();
}


