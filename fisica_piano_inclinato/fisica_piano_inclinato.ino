



#define MIN_DIST 20
#define TRIGGER A5
#define ECHO A4

int cmconv = 59; 
int count = 0;
  
void setup() {

    pinMode(TRIGGER, OUTPUT);
    pinMode(ECHO, INPUT);

    Serial.begin(115200);  
//    radio.begin();

  
}

//configuriamo tutto quello che serve per i motori


void loop() {
  
  
dist();  
count ++;
delay(50);

} // Loop
