
/*
* Getting Started example sketch for nRF24L01+ radios
* This is an example of how to send data from one node to another using data structures
* Updated: Dec 2014 by TMRh20
*/

#include <SPI.h>
#include "RF24.h"

byte addresses[][6] = {"1Node","2Node"};


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


  int redFrequency = 0;
  int greenFrequency = 0;
  int blueFrequency = 0;


  int vel= 0;
  int ster = 0;
  int X = 1;
  int Y = 1;
  
void setup() {

  avviaSensoreColore();
 
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
  fermo();
  


}

//configuriamo tutto quello che serve per i motori


void loop() {
  
  
/****************** Ping Out Role ***************************/  

    
    if( radio.available()){
                                                           // Variable for the received timestamp
      while (radio.available()) {                          // While there is data ready
        radio.read( &myData, sizeof(myData) );             // Get the payload
      }

      Y = myData.asseY;
      X = myData.asseX;

      Serial.print(" vel e ster sono: ");
      Serial.print(Y);
      Serial.print(",");
      Serial.println(X);

      vel = abs(Y);
      ster = abs(X);
      
      if (vel > 10 && ster <10 ) {
        
        avanti(vel);
        Serial.print("avanti ");
        Serial.println(vel);

      }else if (vel < -10 abs(ster) <=10){

        indietro(abs(vel));
        Serial.print("indietro ");
        Serial.println(vel);

      
      }else {
        fermo();
      }


      if (ster > 10 ) {
        
        destra(abs(vel));
        Serial.print("destra ");
        Serial.println(vel);
      
      }else if (vel < -10){
        Serial.print("sinistra ");
        Serial.println(vel);

        sinistra(abs(vel));
      }
      

     
      radio.stopListening();                               // First, stop listening so we can talk  
      char color = colore();                               // ricavo il colore ottenuto
      radio.write( &color, sizeof(color) );              // Send the final one back.      
      radio.startListening();                              // Now, resume listening so we catch the next packets.     
      Serial.print(F("Invia il colore "));
      switch (color){
        case 'R':
          Serial.println("Rosso");
          break;
        case 'G':
          Serial.println("Verde");
          break;
        case 'B':
          Serial.println("Blue");
          break;
        case 'I':
          Serial.println("Indefinito");
          break;          
      }


 }




} // Loop
