void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {

  // put your main code here, to run repeatedly:
    unsigned long started_waiting_at = micros();               
    double intervallo = 10.0;                              

    bool finepausa = timeout(started_waiting_at, intervallo); 
    Serial.println(finepausa);
  

}
