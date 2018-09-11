
//script modificato a partire da un algoritmo pubblicato su https://www.lombardoandrea.com/l298n-motore-dc-arduino/



//definizione dei pin
static int In1 = A2; //pin digitale per determinare gli stati logici da inviare al modulo
static int In2 = A3; //pin digitale per determinare gli stati logici da inviare al modulo
static int ENA = A1; //pin digitale tramite il quale inviare un segnale di tipo PWM tramite la funzione analgWrite()

static int In3 = 10; //pin digitale per determinare gli stati logici da inviare al modulo
static int In4 = 9; //pin digitale per determinare gli stati logici da inviare al modulo
static int ENB = A0; //pin digitale tramite il quale inviare un segnale di tipo PWM tramite la funzione analgWrite()
 
//variabili usate per gestire e mostrare i valori di operaizone
int potenza;  //valore in uscita dal pin 11
 
void avviamotore() {
 
  //inizializzo variabili
  potenza = 0;
 
  //definisco tipologia pin
  pinMode(In1, OUTPUT); //output perche' definisce lo stato logico del pin IN1 del modulo L298N
  pinMode(In2, OUTPUT); //output perche' definisce lo stato logico del pin IN2 del modulo L298N
  pinMode(ENA, OUTPUT);  //output perche' definisce il valore PWM del pin EN1 del modulo L298N

  pinMode(In3, OUTPUT); //output perche' definisce lo stato logico del pin IN3 del modulo L298N
  pinMode(In4, OUTPUT); //output perche' definisce lo stato logico del pin IN4 del modulo L298N
  pinMode(ENB, OUTPUT);  //output perche' definisce il valore PWM del pin EN2 del modulo L298N

  fermo();
 
}
 
 
void avanti(int potenza) {

   //Definisco il senso di marcia del motore
  /*
    mA |   mB  | Evento
  -----|-------|----------------------
  LOW  | LOW   | fermo
  LOW  | HIGH  | Movimento in un senso
  HIGH | LOW   | Movimento senso opposto
  HIGH | HIGH  | Fermo
  */
  
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  
  //invio costantemente il valore PWM della potenza in modo da far variare la velocita' del motore in base alla posizione del potenziometro
  analogWrite(ENA, potenza);
  analogWrite(ENB, potenza);
}


void indietro(int potenza) {

   //Definisco il senso di marcia del motore
  /*
    mA |   mB  | Evento
  -----|-------|----------------------
  LOW  | LOW   | fermo
  LOW  | HIGH  | Movimento in un senso
  HIGH | LOW   | Movimento senso opposto
  HIGH | HIGH  | Fermo
  */
  
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  
  //invio costantemente il valore PWM della potenza in modo da far variare la velocita' del motore in base alla posizione del potenziometro
  analogWrite(ENA, potenza);
  analogWrite(ENB, potenza);
  Serial.print("POTENZA: ");
  Serial.println(potenza);
}


void fermo() {
 
  analogWrite(ENA, LOW);
  analogWrite(ENB, LOW);
}

void destra(int potenza) {

   //Definisco il senso di marcia del motore
  /*
    mA |   mB  | Evento
  -----|-------|----------------------
  LOW  | LOW   | fermo
  LOW  | HIGH  | Movimento in un senso
  HIGH | LOW   | Movimento senso opposto
  HIGH | HIGH  | Fermo
  */
  
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  
  //invio costantemente il valore PWM della potenza in modo da far variare la velocita' del motore in base alla posizione del potenziometro
  analogWrite(ENA, potenza);
  analogWrite(ENB, LOW);
}

void sinistra(int potenza) {

   //Definisco il senso di marcia del motore
  /*
    mA |   mB  | Evento
  -----|-------|----------------------
  LOW  | LOW   | fermo
  LOW  | HIGH  | Movimento in un senso
  HIGH | LOW   | Movimento senso opposto
  HIGH | HIGH  | Fermo
  */
  
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  
  //invio costantemente il valore PWM della potenza in modo da far variare la velocita' del motore in base alla posizione del potenziometro
  analogWrite(ENA, LOW);
  analogWrite(ENB, potenza);
}

  // la funzione dist() restituisce un valore booleano TRUE se rileva un ostacolo a distanza maggiore di 30cm
  
  int dist(){

    int trovato = false;                                                     // imposta la variabile che restituisce a false
  
    digitalWrite (TRIG, HIGH);                                        // attraverso il trigger inizia a emettere onde
    delayMicroseconds(10);                                                   // per dieci secondi
    digitalWrite(TRIG,LOW);                                           // e si ferma

  long duration =pulseIn(ECHO, HIGH);                                  //attraverso la funzione pulseIn acquisiamo il segnale tramite il sensore

  long int distanza = 0.036 * duration /2;                                 //calcoliamo la distanza

  Serial.print(" durata: ");                                               //stampiamo sul monitor seriale la durata del segnale e la distanza ottenuta
  Serial.println(duration);
  Serial.print(" distanza: ");

  if (duration >380000) { 
          Serial.println("fuori portata");                                 //segnaliamo se la distanza è fuori dalla portata dello strumento
  
  }else { 
           Serial.print(distanza); 
           Serial.println ("cm");
           Serial.println (" ");
         }
       
//////evitiamo una divisione per zero, sostituendo lo zero con 1000
 if (duration == 0)
   duration == 1000;
   
   long int rval = microsecondsToCentimeters(duration);                    //calcoliamo la distanza in centimetri
 
 
 return rval;

}

long microsecondsToCentimeters(long microseconds)
  {
   return microseconds / cmconv;
  }
  
