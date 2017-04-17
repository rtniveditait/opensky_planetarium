int pulPin = 10;
int dirPin = 11;
int enblPin = 12;
int pulPin1 = 3;
int dirPin1 = 4;
int enblPin1 = 5;
int ledPin = 13;

int loops = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pulPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enblPin, OUTPUT);
   pinMode(pulPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(enblPin1, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  digitalWrite(pulPin, LOW);
   digitalWrite(pulPin1, LOW);
  digitalWrite(ledPin, LOW);
  digitalWrite(enblPin, LOW);
  digitalWrite(enblPin1, LOW);
  digitalWrite(dirPin, LOW);
digitalWrite(dirPin1, LOW);
  
  Serial.begin(9600);
  Serial.println("init");
  
  digitalWrite(enblPin, HIGH);
  delay(100);
  digitalWrite(enblPin, LOW);
   digitalWrite(enblPin1, HIGH);
  delay(100);
  digitalWrite(enblPin1, LOW);
}

void loop() {
  // put your main code here, to run repeatedly: 
  digitalWrite(pulPin, HIGH);
    digitalWrite(pulPin1, HIGH);
  digitalWrite(ledPin, HIGH);
  digitalWrite(pulPin, LOW);
   digitalWrite(pulPin1, LOW);
  digitalWrite(ledPin, LOW);
    
  
  delay(1000);
}
