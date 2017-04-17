
// point A to B (200 steps)

int RST = A0;              // Porta digital D08 - reset do A4988
int SLP = A1;              // Porta digital D09 - dormir (sleep) A4988
int ENA = 7;              // Porta digital D07 - ativa (enable) A4988
int MS1 = 6;              // Porta digital D04 - MS1 do A4988
int MS2 = 5;              // Porta digital D05 - MS2 do A4988
int MS3 = 3;              // Porta digital D06 - MS3 do A4988
int DIR = 2;              // Porta digital D03 - direÃ§Ã£o (direction) do A4988
int STP = 13;              // Porta digital D02 - passo(step) do A4988
int atraso = 0;           // Atraso no pulso em microsegundos
float FREQ = 200;       // FrequÃªncias dos pulsos (100.7 Hz medido com scope = 100 Hz)
boolean sentido = true;   // Variavel de sentido 
int CONTADOR = 3200;       // NÃºmero de pulsos (passos por volta) 

// FULL = 200 passos / HALF = 400 passos / P1_4 = 800 passos / P1_8 = 1600 passos / P1_16 = 3200 passos

void setup()
{
  Serial.begin(9600);  
  
  DDRD = DDRD | B11111100;  // Configura Portas D02 atÃ© D07 como saÃ­da 
  digitalWrite(ENA, HIGH);  // Desativa o chip A4988 
 
  P1_16();                // Configura modo de avanÃ§o do motor FULL, HALF, P1_4, P1_8 ou P1_16
  
  DDRB = 0x0F;              // Configura Portas D08,D09,D10 e D11 como saÃ­da 
  digitalWrite(SLP, HIGH);  // Desativa sleep do A4988 
  rst_A4988();              // Reseta o chip A4988 
  digitalWrite(ENA, LOW);   // Ativa o chip A4988 
  
  FREQUENCIA();             // Calcula o perÃ­odo do sinal STEP   
  //Serial.println(atraso) ;  // Imprime na Console, o tempo em microseguindos
}

void rst_A4988()
{
  digitalWrite(RST, LOW);     // Realiza o reset do A4988
  delay (100);                 // Atraso de 10 milisegundos 
  digitalWrite(RST, HIGH);    // Libera o reset do A4988     
}

void HOR()                      // Configura o sentido de rotaÃ§Ã£o do Motor 
{
  digitalWrite(DIR, HIGH);      // Configura o sentido HORÃRIO   
}

void AHR()                      // Configura o sentido de rotaÃ§Ã£o do Motor 
{ 
  digitalWrite(DIR, LOW);       // Configura o sentido ANTI-HORÃRIO
}

void PASSO()                    // Pulso do passo do Motor 
{
  digitalWrite(STP, LOW);       // Pulso nÃ­vel baixo 
  delayMicroseconds (atraso);   // Atraso de X microsegundos 
  digitalWrite(STP, HIGH);      // Pilso nÃ­vel alto
  delayMicroseconds (atraso);   // Atraso de X microsegundos    
}

void FREQUENCIA()                 // Configura quantos pulsos por segundo (Hz) 
{
  atraso = 1000000 / (2*FREQ);    // calculo do tempo de atraso (1/2 periodo) em us
}

/*void FULL()
{
  digitalWrite(MS1, LOW);    // Configura modo Passo completo (Full step) 
  digitalWrite(MS2, LOW);
  digitalWrite(MS3, LOW);   
}

/*void HALF()
{
  digitalWrite(MS1, HIGH);    // Configura modo Meio Passo (Half step) 
  digitalWrite(MS2, LOW);
  digitalWrite(MS3, LOW);   
}

void P1_4()
{
  digitalWrite(MS1, LOW);    // Configura modo Micro Passo 1/4
  digitalWrite(MS2, HIGH);
  digitalWrite(MS3, LOW);   
}

void P1_8()
{
  digitalWrite(MS1, HIGH);    // Configura modo Micro Passo 1/8
  digitalWrite(MS2, HIGH);
  digitalWrite(MS3, LOW);   
}
*/
void P1_16()
{
  digitalWrite(MS1, HIGH);    // Configura modo Micro Passo 1/16
  digitalWrite(MS2, HIGH);
  digitalWrite(MS3, HIGH);   
}

void TesteMotor()
{
  HOR();
  for(int i=0; i <= 200; i++)              // Incrementa o Contador
   {
     PASSO();  // AvanÃ§a um passo no Motor  
     delay(100);
   }
   delay (5) ;                                // Atraso de 500 mseg 
  AHR();
  for(int i=0; i <= 200; i++)              // Incrementa o Contador
   {
     PASSO();                                   // AvanÃ§a um passo no Motor  
   delay(5);
   }
   
   delay (1000) ;                                // Atraso de 500 mseg 
}
   
void loop()
{
 /* FULL();
  FREQ = 200;
  FREQUENCIA();
  CONTADOR = 200; 
  Serial.print(atraso);
  Serial.println(" us Full, 200 passos, 200 Hz");
  Serial.println();
  TesteMotor(); 
 /*
  HALF();
  FREQ = 600;
  FREQUENCIA();
  CONTADOR = 400; 
  Serial.print(atraso);
  Serial.println(" us Half, 200 passos, 600 Hz");
  Serial.println();
  TesteMotor(); 
  

  P1_4();
  FREQ = 1600;
  FREQUENCIA();
  CONTADOR = 800; 
  Serial.print(atraso);
  Serial.println(" us Micro 1/4, 800 passos, 1600 Hz");
  Serial.println();
  TesteMotor();    

  P1_8();
  FREQ = 3600;
  FREQUENCIA();
  CONTADOR = 1600; 
  Serial.print(atraso);
  Serial.println(" us Micro 1/8, 1600 passos, 3600 Hz");
  Serial.println();
  TesteMotor(); 
*/
  P1_16();
  FREQ = 10;
  FREQUENCIA();
  CONTADOR = 3200; 
  Serial.print(atraso);
  Serial.println(" us Micro 1/16, 3200 passos, 6600 Hz");
  Serial.println();
  TesteMotor(); 
  
}

