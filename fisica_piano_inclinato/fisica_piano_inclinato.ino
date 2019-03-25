/*

  i sensori sono distanti 20cm
 
*/


#define POSIZIONE_1 10
#define POSIZIONE_2 13
#define POSIZIONE_3 3
#define POSIZIONE_4 5

float sUno = 0.2; //in metri
float sDue = 0.52;
float sTre = 0.2;
float vel;

int count = 1;

int posUno, posDue, posTre, posQuattro;
long int temp1, temp2, temp3, temp4;
long int deltaTUno, deltaTDue, deltaTTre;

bool pasUno, pasDue, pasTre, pasQuattro;

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

}

void loop() {

  if(!digitalRead(POSIZIONE_1)){

//    Serial.print("\n\n\n");
//    Serial.print(count);
//    Serial.print(" sensore 1: ");
    temp1 = millis();
//    Serial.println(temp1);
    pasUno = true;
  }
 
  if(!digitalRead(POSIZIONE_2) && pasUno){
//    Serial.print(count);
//    Serial.print(" sensore 2: ");
    temp2 = millis();
//    Serial.println(temp2);
    pasDue = true;

  }

  if(!digitalRead(POSIZIONE_3) && pasDue){
//    Serial.print(count);
//    Serial.print(" sensore 3: ");
    temp3 = millis();
//    Serial.println(temp3);
    pasTre = true;
  }

  if(!digitalRead(POSIZIONE_4) && pasTre){
//    Serial.print(count);
//    Serial.print(" sensore 4: ");
    temp4 = millis();
//    Serial.println(temp4);
    pasQuattro = true;
  }

if (pasQuattro) {
  
  deltaTUno = abs(temp2 - temp1);
  deltaTDue = abs(temp3 - temp2);
  deltaTTre = abs(temp4 - temp3);
  
  Serial.println();
  Serial.print("Lancio numero ");
  Serial.println(count);
  Serial.println();
  
  Serial.print("Intervalli di tempo rilevati: \n T1: ");
  Serial.print(deltaTUno);
  Serial.print("    S1: ");
  Serial.print(sUno);
  Serial.println(" metri");
  Serial.print(" T2: ");
  Serial.print(deltaTDue);
  Serial.print("    S2: ");
  Serial.print(sDue);
  Serial.println(" metri");
  Serial.print(" T3: ");
  Serial.print(deltaTTre);
  Serial.print("    S3: ");
  Serial.print(sTre);
  Serial.println(" metri");
    
  pasUno = pasDue = pasTre = pasQuattro = false;

  count ++;
}

//delay(200);

 
}
