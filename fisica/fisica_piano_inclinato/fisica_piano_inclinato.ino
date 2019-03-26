/*

  i sensori sono distanti 20cm
 
*/

#define POSIZIONE_1 5
#define POSIZIONE_2 3
#define POSIZIONE_3 13
#define POSIZIONE_4 10

float sUno = 0.2; //in metri
float sDue = 0.2;
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

while(digitalRead(POSIZIONE_1)){
//Serial.println("1");
}
temp1 = millis();

while(digitalRead(POSIZIONE_2)){
//Serial.println("2");
}
temp2 = millis();

while(digitalRead(POSIZIONE_3)){
//Serial.println("3");  
}

temp3 = millis();

while(digitalRead(POSIZIONE_4)){
//Serial.println("4");  
}

temp4 = millis();
//  Serial.println(temp1);
//  Serial.println(temp2);
//  Serial.println(temp3);
//  Serial.println(temp4);
  
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

//delay(200);

 
}
