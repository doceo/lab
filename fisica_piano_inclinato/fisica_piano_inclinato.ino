
/**********************************************************

la posizione dei sensoti è presa dal più alto al più basso
posizione 1 2 3 4
la distanza tra 1-2 e 3-4 è 10 cm


***********************************************************/


#define MIN_DIST 20

#define TRIGGER_1 A5
#define ECHO_1 A4

#define TRIGGER_2 A5
#define ECHO_2 A4

#define TRIGGER_3 A5
#define ECHO_3 A4

#define TRIGGER_4 A5
#define ECHO_4 A4


int cmconv = 59; 
int count = 0;
int pos;

double v1, v2, acc;

int sonarTrigger[] = {TRIGGER_1, TRIGGER_2, TRIGGER_3, TRIGGER_4};
int sonarEcho[] = {ECHO_1, ECHO_2, ECHO_3, ECHO_4};

long tempo1, tempo2, tempo3, tempo4;

long tempi[]{tempo1, tempo2, tempo3, tempo4};

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

Serial.println(count);

//calcoliamo la velocità nel primo e nel secondo tratto
v1 = vel(1);

v2 = vel(2);

//calcoliamo l'accellerazione

acc = (v1+v2)/2;

count ++;
delay(30);

} // Loop
