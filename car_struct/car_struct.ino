
/*
* Getting Started example sketch for nRF24L01+ radios
* This is an example of how to send data from one node to another using data structures
* Updated: Dec 2014 by TMRh20
*/

#include <SPI.h>
#include "RF24.h"

byte addresses[][6] = {"1Node","2Node"};


#define MIN_DIST 20
int cmconv = 59; 

#define TRIG A5
#define ECHO A4
/****************** User Config ***************************/
/***      Set this radio as radio number 0 or 1         ***/
bool radioNumber = 0;

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(7,8);
/**********************************************************/



/**
* Create a data structure for transmitting and receiving data
* This allows many variables to be easily sent and received in a single transmission
* See http://www.cplusplus.com/doc/tutorial/structures/
*/

struct dataStruct{
  int asseX;
  int asseY;
  unsigned long temp;
}myData;


  int vel= 0;
  int ster = 0;
  int X = 1;
  int Y = 1;
  
void setup() {

    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);

 
    Serial.begin(115200);
 
  
    radio.begin();

  // Set the PA Level low to prevent power supply related issues since this is a
 // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  radio.setPALevel(RF24_PA_LOW);
  
  // Open a writing and reading pipe on each radio, with opposite addresses
  if(radioNumber){
    radio.openWritingPipe(addresses[1]);
    radio.openReadingPipe(1,addresses[0]);
  }else{
    radio.openWritingPipe(addresses[0]);
    radio.openReadingPipe(1,addresses[1]);
  }
  
  // Start the radio listening for data
  radio.startListening();
  
  avviamotore();
  
}

//configuriamo tutto quello che serve per i motori


void loop() {
  
  
/****************** Ping Out Role ***************************/  

Serial.print("distanza: ");
Serial.println(dist());
    
    if( radio.available()){
                                                           // Variable for the received timestamp
      while (radio.available()) {                          // While there is data ready
        radio.read( &myData, sizeof(myData) );             // Get the payload
      }

      Y = (int)myData.asseY;
      X = (int)myData.asseX;

      Serial.print(" vel e ster ricevuti sono: ");
      Serial.print(Y);
      Serial.print(",");
      Serial.println(X);

          
 
      vel = map (Y, -20, 20, -512, 512);
      ster = map (X, -20, 20, -512, 512);

      Serial.print(" vel e ster mappati sono: ");
      Serial.print(vel);
      Serial.print(",");
      Serial.println(ster);

      //i casi in cui il joypad si muove solo in avanti, indietro o è fermo

//
if (vel > 0 && dist() < MIN_DIST ) {
    avanti(vel);
    Serial.println("avanti");
    
}else if(vel<0){
  Serial.println("indietro");
  indietro(abs(vel));
  }else{
  fermo();
}

if (ster>0){
  destra(ster);
  Serial.println("destra");

  
 }else if(ster<0){
  sinistra(abs(ster));
  Serial.println("sinistra");

 }

//delay(500);
    }

} // Loop
