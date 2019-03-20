/*

  i sensori sono distanti 20cm
 
*/


#define POSIZIONE_1 10
#define POSIZIONE_2 8

float distanza = 0.2; //in metri
float vel;

int count = 0;

int pos1, pos2;
long int temp1, temp2;
double deltaT;

int passato = 0;

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(POSIZIONE_1, INPUT);
  pinMode(POSIZIONE_2, INPUT);

}

void loop() {


pos1 = digitalRead(POSIZIONE_1);
pos2 = digitalRead(POSIZIONE_2);

  if(!pos1){
    Serial.print(count);
    Serial.print(" sensore 1: ");
    temp1 = millis();
    Serial.println(temp1);
    passato++;
  }
 
  if(!pos2){
    Serial.println(count);
    Serial.print(" sensore 2: ");
    temp2 = millis();
    Serial.println(temp2);
    passato++;
  }

deltaT = (temp2-temp1)/1000;
vel = distanza/deltaT;

if (passato == 2) {
  Serial.print("vel= ");
  Serial.println(vel);
  passato = 0;
}


delay(200);
count++;
 
}
