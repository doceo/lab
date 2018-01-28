#include <ESP8266WiFi.h>

const int threshold = 100;  // threshold value to decide when the detected sound is a knock or not
#define PIEZO 13

int temp = 900000;
int ledState = LOW;         // variable used to store the last LED status, to toggle the light


void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
   pinMode(PIEZO, INPUT); 
  //richiamo la funzione che gestisce la connessione
  connectWifi();
}
 
void loop() {
  
int  sensorReading = analogRead(PIEZO);

  // if the sensor reading is greater than the threshold:
  if (sensorReading >= threshold) {
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, HIGH);
    // toggle the status of the ledPin:
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println("Knock!");
  }
  delay(500);  // delay to avoid overloading the serial port buffer
  digitalWrite(LED_BUILTIN, LOW);
}
 
