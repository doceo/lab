
/**********************************************************

la posizione dei sensoti è presa dal più alto al più basso
posizione 1 2 3 4
la distanza tra 1-2 e 3-4 è 10 cm


***********************************************************/


#define MIN_DIST 20

#define TRIGGER_1 11
#define ECHO_1 A0

#define TRIGGER_2 9
#define ECHO_2 A1

#define TRIGGER_3 7
#define ECHO_3 A2

#define TRIGGER_4 4
#define ECHO_4 A3


int cmconv = 59; 
int count = 0;
int dist_sens = 10;
int dist_disc = 100;



double v1, v2, acc;

int sonarTrigger[] = {TRIGGER_1, TRIGGER_2, TRIGGER_3, TRIGGER_4};
int sonarEcho[] = {ECHO_1, ECHO_2, ECHO_3, ECHO_4};

long tempi[]{0, 0, 0, 0};

void setup() {

    pinMode(TRIGGER_1, OUTPUT);
    pinMode(ECHO_1, INPUT);

    pinMode(TRIGGER_2, OUTPUT);
    pinMode(ECHO_2, INPUT);

    pinMode(TRIGGER_3, OUTPUT);
    pinMode(ECHO_3, INPUT);

    pinMode(TRIGGER_4, OUTPUT);
    pinMode(ECHO_4, INPUT);

    
    Serial.begin(115200);  
//    radio.begin();


  
}

//configuriamo tutto quello che serve per i motori


void loop() {

dist();
  
Serial.println();
Serial.println(count);
Serial.println();


//calcoliamo la velocità nel primo e nel secondo tratto
//v1 = vel(1);
//Serial.print("Vel. tratto 1: ");
//Serial.print(v1);
//Serial.print(tempi[0]);
//Serial.print(" - ");
//Serial.println(tempi[1]);

//
//v2 = vel(2);
//Serial.print("Vel. tratto 2: ");
//Serial.print(v2);
//Serial.print(tempi[2]);
//Serial.print(" - ");
//Serial.println(tempi[3]);
//
////calcoliamo l'accellerazione
//
//acc = (v1+v2)/(tempi[3]-tempi[0]);

//Serial.print("accellerazione: ");
//Serial.print(acc);
count ++;
delay(200);

} // Loop
