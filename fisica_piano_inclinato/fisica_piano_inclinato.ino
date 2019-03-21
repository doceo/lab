/*
  INFRAROSSO
  i sensori sono distanti 20cm
 
*/

/*
  LCD
* LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

 
*/

#include <LiquidCrystal.h>

#define POSIZIONE_1 10
#define POSIZIONE_2 8

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


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

  lcd.begin(16, 2);

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
  
  String rigaUno = "DeltaT " + deltaT;
  // print the number of seconds since reset:
  lcd.setCursor(0, 0);
  lcd.print(rigaUno);

  String rigaDue = String(distanza,3) + " dist. ";
  // print the number of seconds since reset:
  lcd.setCursor(0, 1);
  lcd.print(rigaDue);
  
}


//delay(200);
count++;
 
}
