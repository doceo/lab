/*

  i sensori sono distanti 20cm
 
*/


#define POSIZIONE_1 10
#define POSIZIONE_2 8

float distanza = 0.2; //in metri
float vel;

int count = 0;

int posUno, posDue;
long int temp1, temp2;
long int deltaT;

bool pasUno, pasDue;

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(POSIZIONE_1, INPUT);
  pinMode(POSIZIONE_2, INPUT);

}

void loop() {

posUno = digitalRead(POSIZIONE_1);
posDue = digitalRead(POSIZIONE_2);

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
