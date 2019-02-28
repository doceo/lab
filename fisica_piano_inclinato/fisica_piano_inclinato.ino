



#define MIN_DIST 20
int cmconv = 59; 

#define TRIG A5
#define ECHO A4

  
void setup() {

    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);

    Serial.begin(115200);  
    radio.begin();

  
}

//configuriamo tutto quello che serve per i motori


void loop() {
  
  
/****************** Ping Out Role ***************************/  

Serial.print("distanza: ");
Serial.println(dist());
    
    if( radio.available()){
                                                
      while (radio.available()) {                      
        radio.read( &myData, sizeof(myData) );            
      }

      Y = (int)myData.asseY;
      X = (int)myData.asseX;

      Serial.print(" vel e ster ricevuti sono: ");
      Serial.print(Y);
      Serial.print(",");
      Serial.println(X);


//delay(500);
    }

} // Loop
