/*

  i sensori sono distanti 20cm
 
*/


#define POSIZIONE_1 10
#define POSIZIONE_2 8
#define POSIZIONE_1 6
#define POSIZIONE_2 4

float distanza = 0.2; //in metri
float vel;

int count = 0;

int posUno, posDue, posTre, posQuattro;
long int temp1, temp2, temp3, temp4;
long int deltaTUno, deltaTDue;

bool pasUno, pasDue, pasTre, pasQuattro, pasDeltaT;

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(POSIZIONE_1, INPUT);
  pinMode(POSIZIONE_2, INPUT);
  pinMode(POSIZIONE_3, INPUT);
  pinMode(POSIZIONE_4, INPUT);

pasUno = false;
pasDue = false; 
pasTre = false;
pasQuattro = false;
pasDeltaT = false;

}

void loop() {

posUno = digitalRead(POSIZIONE_1);
posDue = digitalRead(POSIZIONE_2);
posTre = digitalRead(POSIZIONE_3);
posQuattro = digitalRead(POSIZIONE_4);

  if(!posUno && !pasUno){

    Serial.print("\n\n\n");
    Serial.print(count);
    Serial.print(" sensore 1: ");
    temp1 = millis();
    Serial.println(temp1);
    pasUno = true;
  }
 
  if(!posDue && !pasDue){
    Serial.print(count);
    Serial.print(" sensore 2: ");
    temp2 = millis();
    Serial.println(temp2);
    pasDue = true;
    delay(100);
  }

if (pasUno && pasDue) {
  
  deltaTUno = temp2-temp1;
  
  Serial.println();
  Serial.print("Tempo impiegato in millisecondi: ");
  Serial.println(deltaT);

  pasUno = pasDue = false;

  pasDeltaT = true;
  
  vel = (distanza/deltaTUno)*1000;
  Serial.print("velocità: ");
  Serial.print(vel);
  Serial.println(" m/s");
}

posTre = digitalRead(POSIZIONE_3);
posQuattro = digitalRead(POSIZIONE_4);

  if(!posTre && !pasTre){

    Serial.print("\n\n\n");
    Serial.print(count);
    Serial.print(" sensore 3: ");
    temp1 = millis();
    Serial.println(temp3);
    pasTre = true;
  }
 
  if(!posQuattro && !pasQuattro && pasDeltaT){
    Serial.print(count);
    Serial.print(" sensore 4: ");
    temp2 = millis();
    Serial.println(temp2);
    pasQuattro = true;
    delay(100);
  }

if (pasUno && pasDue) {
  
  deltaT = temp2-temp1;
  
  Serial.println();
  Serial.print("Tempo impiegato in millisecondi: ");
  Serial.println(deltaT);

  pasUno = pasDue = false;
  vel = (distanza/deltaT)*1000;
  Serial.print("velocità: ");
  Serial.print(vel);
  Serial.println(" m/s");
}




//delay(200);
count++;
 
}
