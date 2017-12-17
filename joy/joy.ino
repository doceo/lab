
/*
 * Il seguente script è costruito a partire dagli esempi forniti dalle diverse librerie
 * utilizzate e personalizzato in modo opportuno.
 * in particolare servirà ad acquisire le direttive da un Joypad e pilotare 
 * un'auto che verifica il colore degli oggetti che incontra, restiuisce il dato e sul joy viene 
 * ripetuto il colore tramite led RGB
 * 
 */

#include <SPI.h>
#include "RF24.h"

/****************** User Config ***************************/
/***      Set this radio as radio number 0 or 1         ***/
bool radioNumber = 0;

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(7,8);
/**********************************************************/

byte addresses[][6] = {"1Node","2Node"};

// Used to control whether this node is sending or receiving
bool role = 0;

// di seguito le impostazioni utili all'acquisizione dei dati dal joypad


int X = A1;    // select the input pin for the potentiometer
int Y = A2;      // select the pin for the LED
int tap = 3;  // variable to store the value coming from the sensor

int asseX, asseY, clic;



void setup() {

  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  pinMode(tap, INPUT);
  
  Serial.begin(115200);
  Serial.println(F("RF24/examples/GettingStarted"));
//  Serial.println(F("*** PRESS 'T' to begin transmitting to the other node"));
  
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
}

void loop() {
    asseX = map(analogRead(X), 0, 1024, 0, 10); 
    asseY= map(analogRead(Y), 0, 1024, 0, 10);
    clic= digitalRead(tap);


    String message = (String)asseX + "." + (String)asseY + "." + (String)clic;
    Serial.println(message);
    
    radio.stopListening();                                    // First, stop listening so we can talk.
    
    
    Serial.println(F("Now sending"));


     if (!radio.write( &message, sizeof(message) )){          //invia i valori acquisiti sottoforma di strinva X.Y.Click
       Serial.println(F("failed"));
     }
        
    radio.startListening();                                    // Now, continue listening
    
    unsigned long started_waiting_at = micros();               // Set up a timeout period, get the current microseconds
    boolean timeout = false;                                   // Set up a variable to indicate if a response was received or not
    
    while ( ! radio.available() ){                             // While nothing is received
      if (micros() - started_waiting_at > 200000 ){            // If waited longer than 200ms, indicate timeout and exit while loop
          timeout = true;
          break;
      }      
    }
        
    if ( timeout ){                                             // Describe the results
        Serial.println(F("Failed, response timed out."));
    }else{
        unsigned long got_time;                                 // Grab the response, compare, and send to debugging spew
        radio.read( &got_time, sizeof(unsigned long) );
        unsigned long end_time = micros();
        
        // Spew it
        Serial.print(F("Sent "));
        Serial.print(message);
        Serial.print(F(", Got response "));

    }

delay(5000);
} // Loop

