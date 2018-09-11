alime
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
bool radioNumber = 1;

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(7,8);
/**********************************************************/



/**
* Create a data structure for transmitting and receiving data
* This allows many variables to be easily sent and received in a single transmission
* See http://www.cplusplus.com/doc/tutorial/structures/
*/

int Y = A1;    // select the input pin for the potentiometer
int X = A0;      // select the pin for the LED
int tap = 3;  // variable to store the value coming from the sensor

char color;

struct dataStruct{
  int asseX;
  int asseY;
//  bool clic;
  unsigned long temp;
}myData;

void setup() {

  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  pinMode(tap, INPUT);
  
  Serial.begin(115200);
  Serial.println(F("RF24/examples/GettingStarted_HandlingData"));
  Serial.println(F("*** PRESS 'T' to begin transmitting to the other node"));
  
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
  
//  myData.value = 1.22;
  // Start the radio listening for data
  radio.startListening();
}




void loop() {
  
  
/****************** Ping Out Role ***************************/  

    
    radio.stopListening();                                    // First, stop listening so we can talk.
    
    
    Serial.println(F("Now sending"));
    
    int vel= map(analogRead(X), 0, 880, -20, 20);
    if(abs(vel)<5) vel = 0;
    
    int ster= map(analogRead(Y), 0, 880, -20, 20);
    if(abs(ster)<5) ster = 0;
 

    myData.asseX = vel ; 
    myData.asseY= ster;
 //   myData.clic= digitalRead(tap);
    myData.temp = micros();

    Serial.println(myData.asseX);
    Serial.println(myData.asseY);
    Serial.println(myData.temp);

    //uso il monitor seriale per tarare gli ingressi
    Serial.println();
    Serial.print("X= ");
    Serial.println(analogRead(X));
    Serial.print("Y= ");
    Serial.println(analogRead(Y));
     
     if (!radio.write( &myData, sizeof(myData) )){
       Serial.println(F("failed"));
     }
        
    radio.startListening();                                    // Now, continue listening
    
    unsigned long started_waiting_at = micros();               // Set up a timeout period, get the current microseconds
    boolean timeout = false;                                   // Set up a variable to indicate if a response was received or not
    
    while ( !radio.available() ){                             // While nothing is received
      if (micros() - started_waiting_at > 200000 ){            // If waited longer than 200ms, indicate timeout and exit while loop
          timeout = true;
          break;
      }      
    }
        
 

    // Try again 1s later
    //delay(1000);



} // Loop
