#include <AFMotor.h>


AF_DCMotor R_motor(2);           // defines Right motor connector
AF_DCMotor L_motor(1);           // defines Left motor connector
// declare variables
int distancecm=100;
const int trigPin = A0;
const int echoPin = A1;
// defines variables
long duration;
int distance;
int cmconv = 59;                                  // Variabile di conversione . 


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  L_motor.setSpeed(200);        // sets L motor speed
  R_motor.setSpeed(140); 

 
  R_motor.run(RELEASE);         //turns L motor on
  L_motor.run(RELEASE);         //turns R motor on
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW

  L_motor.run(FORWARD);      //moves motor L Forward
  R_motor.run(FORWARD); 

if (dist()<4){
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)

    R_motor.run(RELEASE);         //turns L motor on
  L_motor.run(RELEASE); 
}

}

 
  int dist(){

  int distMax = 30;  
  int trovato = false;                                                     // imposta la variabile che restituisce a false
    
  digitalWrite (trigPin, HIGH);                                        // attraverso il trigger inizia a emettere onde
  delayMicroseconds(10);                                                   // per dieci secondi
  digitalWrite(trigPin,LOW);                                           // e si ferma

  long duration =pulseIn(echoPin, HIGH);                                  //attraverso la funzione pulseIn acquisiamo il segnale tramite il sensore

  long int distanza = 0.036 * duration /2;                                 //calcoliamo la distanza

  Serial.print(" durata: ");                                               //stampiamo sul monitor seriale la durata del segnale e la distanza ottenuta
  Serial.println(duration);
  Serial.print(" distanza: ");

  if (duration >38000) { 
          Serial.println("fuori portata");                                 //segnaliamo se la distanza è fuori dalla portata dello strumento
  
  }else { 
           Serial.print(distanza); 
           Serial.println ("cm");
           Serial.println (" ");
         }
         
//evitiamo una divisione per zero, sostituendo lo zero con 1000
if (duration == 0)
   duration == 1000;
   
   long int rval = microsecondsToCentimeters(duration);                    //calcoliamo la distanza in centimetri
 
 
 return rval;

}

long microsecondsToCentimeters(long microseconds)
  {
   return microseconds / cmconv;
  }
  
  
