void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:


int ser, vel;

if (Serial.available() )
  { 
    ser = Serial.read();
    if( ser=='avanti')
    {
      vel = Serial.read();
      avanti(vel);
    }
    else if (ser == 'indietro')
    {
         
      vel = Serial.read();
      indietro(vel);
     }
     else if ( ser == 'destra')
     {
      vel = Serial.read();
      indietro(vel);
     }
     
     else if ( ser == 'sinistra')
     {
      vel = Serial.read();
      indietro(vel);
     }
      delay(1500);
     fermo();
     
  }
  
}



