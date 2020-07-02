
#define SensoreAcqua A3
#define buzzer 7 


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(SensoreAcqua, INPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int livello = analogRead(SensoreAcqua);
  // print out the value you read:
  Serial.println(livello);
  
  if (livello > 800) suona(100);
  else if(livello > 500) suona(300);
  else if(livello >200) suona(600);
  
  
  delay(100);        // delay in between reads for stability
}


void suona(int tempo){

  digitalWrite(buzzer, HIGH);
  delay(tempo);
  digitalWrite(buzzer, LOW);

  
}
