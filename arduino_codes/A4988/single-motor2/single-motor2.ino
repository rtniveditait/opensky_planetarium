//#include <Stepper.h>
//int RST = A0;
//int SLP = A1;
//int ENA = 7;
int dir=2;
int stepp=3;
int microdelay = 0;
int ms3=8;
int ms2=9;
int ms1=10;
int count = 0;
float FREQ = 200;

int CONTADOR = 3200;
boolean sentido = true;

void setup()
{
   Serial.begin(9600);  
  DDRD = DDRD | B11111100;  // Configura Portas D02 atÃ© D07 como saÃ­da 
//  digitalWrite(ENA, HIGH);  // Desativa o chip A4988 
////  digitalWrite(ENA1, HIGH);  // Desativa o chip A4988 
////   P1_8();                  // Configura modo de avanÃ§o do motor FULL, HALF, P1_4, P1_8 ou P1_16
//   
//  DDRB = 0x0F;              // Configura Portas D08,D09,D10 e D11 como saÃ­da 
//  digitalWrite(SLP, HIGH);  // Desativa sleep do A4988 
// // digitalWrite(SLP1, HIGH);  // Desativa sleep do A4988 
////  rst_A4988();              // Reseta o chip A4988 
//  digitalWrite(ENA, LOW);   // Ativa o chip A4988 
////  digitalWrite(ENA1, LOW);   // Ativa o chip A4988 

//  FREQUENCY(); 
//  pinMode(dir, OUTPUT);       // Assign output mode to pin for direction
//  pinMode(stepp, OUTPUT);      // Assign output mode to pin for setp
//  digitalWrite(dir, HIGH);     // Initialize dir pin 
//  digitalWrite(stepp, LOW);    // Initialize step pin

//  pinMode(ms3, OUTPUT);
//  pinMode(ms2, OUTPUT);
//  pinMode(ms1, OUTPUT);

  digitalWrite(ms1, LOW);
  digitalWrite(ms2, HIGH);  
  digitalWrite(ms3, LOW);

 // Serial.begin(9600);
  
  }

//void rst_A4988()
//{
//  digitalWrite(RST,LOW);     // Realiza o reset do A4988
//  //digitalWrite(RST1,LOW);     // Realiza o reset do A4988
//  delay (100);                 // Atraso de 10 milisegundos 
//  digitalWrite(RST,HIGH);    // Libera o reset do A4988   
// // digitalWrite(RST1,HIGH);    // Libera o reset do A4988  
//  //delay (100);                 // Atraso de 10 milisegundos 
//    
//}

//void FREQUENCY()
//{
//  microdelay = 10000000/(2*FREQ);
//}

void Forward()
{
 digitalWrite(dir, HIGH);
}

void Reverse()
{
 digitalWrite(dir, LOW);
}

void PASS()
{
  digitalWrite(stepp, LOW);
  delayMicroseconds(microdelay);
  digitalWrite(stepp, HIGH);
  delayMicroseconds(microdelay);
}

void MOT()
{
  Forward();
  for (int i=0; i<=150; i++)
  { 
  PASS();
  delay(10); 
  Serial.println("forward");
  }
  delay(2000);
  
  Reverse();
  for (int i=0; i<=150
  ; i++)
  { 
   PASS();
  delay(10);
  Serial.println("Reverse");
  }
  delay(2000);
 
}
void loop()
{
  FREQ = 200;
  CONTADOR = 3200;
 // FREQUENCY();
  Serial.println(microdelay);
  Serial.println();
  MOT();
}
  /*for(count=0;count<15;count++)
  //while(count<10 && reverse==0)
  {
  Serial.println("forward");
  Serial.println(count);
  digitalWrite(dir, HIGH);     // Initialize dir pin 
  digitalWrite(stepp, LOW);       // Step motor
  delay(500);
  
  //delayMicroseconds(microSecDelay);  // Wait microseconds
  digitalWrite(stepp, HIGH);        // Step motor
  delay(500);
  //count++;
  //forward=0;
  }

  for(count=15;count>=0;count--)
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
  */
  
  
