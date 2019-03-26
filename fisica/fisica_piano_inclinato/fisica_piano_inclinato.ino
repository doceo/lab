
/***********************************************************************************
  ************************************************************************************
  * A/S 2018/2019 - Liceo G.B.Vico
  * Esercitazione di fisica - Piano Inclinato
  * Prof.ssa Francesca Aurelio - Fisica
  * Prof. Diomede Mazzone - Coding
  * 
  * lungo un piano inclinato sono posti 4 sensori ad infrarosso a distanza costante.
  * i sensori rilevano un ostacolo con un angolo di rilevamento di circa 35°
  * 
  * Arduino salva il tempo in millisecondi dei 4 passaggi e superato il quarto sensore
  * restitusce a monitor gli intervalli di tempo, intesi come differenze tra i tempi
  * rilevati.
  * 
  * Poichè il piano inclinato prevede anche angolazioni elevate si è scelto di
  * utilizzare cicli di while per la rilevazione del passaggio ad ogni singolo sensore,
  * così da avere una frequenza di verifica dei sensori quanto più alta possibile.
  
  ************************************************************************************
  ************************************************************************************/


#define POSIZIONE_1 5
#define POSIZIONE_2 3
#define POSIZIONE_3 13
#define POSIZIONE_4 10

/*
 *
 * Memorizzo le distanze reali tra i sensori perchè in alcune esercitazioni potrebbe
 * tornare utile restituire in output anche le velocità lungo i tratti
 *
*/

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

 /* 
 * i cicli while sono bloccanti, quindi l'unica istruzione  
 * in esecuzione è la verifica del singolo sensore, fino a 
 * che non cambia stato. Una volta che cambia il valore 
 * rilevato cambia stato rimane bloccato in ascolto del 
 * sensore successivo.
 *
 */   
  
  
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
  
 
 /*
 * le istruzioni successive servono alla visualizzazione
 * dei dati tramite porta seriale, direttamente 
 * al monitor del PC.
 */
  
  
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

  /*
  * incrementa la variabile che tiene conto del numero di 
  * lanci effettuati
  */
  
  count ++;

//delay(200);

 
}
