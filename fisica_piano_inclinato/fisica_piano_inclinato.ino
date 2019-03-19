
/**********************************************************

la posizione dei sensori è presa dal più alto al più basso
posizione 1 2 
la distanza tra 1-2 e 3-4 è 10 cm


***********************************************************/


#define MIN_DIST 20

#define TRIGGER_1 11
#define ECHO_1 A0

#define TRIGGER_2 7
#define ECHO_2 A2


int cmconv = 59; 
int count = 0;
int dist_sens = 10;
int dist_disc = 100;

bool pos1 = 0;
bool pos2 = 0;

double vel;

int sonarTrigger[] = {TRIGGER_1, TRIGGER_2};
int sonarEcho[] = {ECHO_1, ECHO_2};

long duration, temp1, temp2;

long int rval;

double distanza;

void setup() {

    pinMode(TRIGGER_1, OUTPUT);
    pinMode(ECHO_1, INPUT);

    pinMode(TRIGGER_2, OUTPUT);
    pinMode(ECHO_2, INPUT);
    
    Serial.begin(115200);  
//    radio.begin();


  
}

//configuriamo tutto quello che serve per i motori


void loop() {

//dist();
  


/**********************************************
 * RILEVAZIONE PRIMO SENSORRE
 * 
 **********************************************/

    digitalWrite (TRIGGER_1, HIGH);                                        // attraverso il trigger inizia a emettere onde
    delayMicroseconds(10);                                                   // per dieci secondi
    digitalWrite(TRIGGER_1,LOW);                                           // e si ferma
  
    duration = pulseIn(ECHO_1, HIGH);                                  //attraverso la funzione pulseIn acquisiamo il segnale tramite il sensore

//    Serial.println();
//    Serial.println(i);
//    Serial.println();

    distanza = 0.01715 * duration; 
  
    if (duration >380000) { 
            Serial.println("fuori portata");                                 //segnaliamo se la distanza è fuori dalla portata dello strumento
    
    }else if  (duration == 0) { 
              duration == 1000;
           }
  
    rval = microsecondsToCentimeters(duration); 
  
    if (rval<5){

      Serial.println();
      Serial.print(count);
      Serial.print(" - tempo1 ");
      temp1=millis();
      Serial.println(temp1);

      pos1=1;
      
    }


/**********************************************
 * RILEVAZIONE SECONDO SENSORRE
 * 
 **********************************************/

    digitalWrite (TRIGGER_2, HIGH);                                        // attraverso il trigger inizia a emettere onde
    delayMicroseconds(10);                                                   // per dieci secondi
    digitalWrite(TRIGGER_2,LOW);                                           // e si ferma
  
    duration = pulseIn(ECHO_2, HIGH);                                  //attraverso la funzione pulseIn acquisiamo il segnale tramite il sensore

//    Serial.println();
//    Serial.println(i);
//    Serial.println();

    distanza = 0.01715 * duration; 
  
    if (duration >380000) { 
            Serial.println("fuori portata");                                 //segnaliamo se la distanza è fuori dalla portata dello strumento
    
    }else if  (duration == 0) { 
              duration == 1000;
           }
  
    rval = microsecondsToCentimeters(duration); 
  
    if (rval<5){
      Serial.println();
      Serial.print(count);
      Serial.print(" - tempo2 ");
      temp2=millis();
      Serial.println(temp2);

      pos2=1;
 
    }

if (pos1==1&&pos2==1){
  vel = 10/(temp2-temp1);
  Serial.println("vel= ");
  Serial.println(vel);
  pos1=0;
  pos2=0;
}


count++;

delay(200);

} // Loop
