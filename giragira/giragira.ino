int sensorPin = A0;
int ledPin = 13;
int sensorValue = 0;

int iniziaGirare;
int tempoGiro = 4000;

 
void setup() {
  // put your setup code here, to run once:
  pinMode (ledPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int rnd =random (0,100);
  bool giro= rnd % 2;
//  Serial.println(giro);
 
 
  
  sensorValue = analogRead(sensorPin);

   if (sensorValue>100){
          Serial.println (sensorValue, DEC);
//        if(micros()-iniziaGirare > tempoGiro){
//        Serial.println("fermo");
//        fermo();
//        }else if{
    
      iniziaGirare=micros();
      if (giro) destra();
      else sinistra();

      delay(2000);

  }

fermo();
}
