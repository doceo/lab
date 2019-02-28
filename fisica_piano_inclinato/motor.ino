

  
  int dist(){

  
    digitalWrite (TRIG, HIGH);                                        // attraverso il trigger inizia a emettere onde
    delayMicroseconds(10);                                                   // per dieci secondi
    digitalWrite(TRIG,LOW);                                           // e si ferma

  long duration =pulseIn(ECHO, HIGH);                                  //attraverso la funzione pulseIn acquisiamo il segnale tramite il sensore

  long int distanza = 0.036 * duration /2;                                 //calcoliamo la distanza

  Serial.print(" durata: ");                                               //stampiamo sul monitor seriale la durata del segnale e la distanza ottenuta
  Serial.println(duration);
  Serial.print(" distanza: ");

  if (duration >380000) { 
          Serial.println("fuori portata");                                 //segnaliamo se la distanza è fuori dalla portata dello strumento
  
  }else if  (duration == 0) { 
            duration == 1000;
         }

  long int rval = microsecondsToCentimeters(duration);                    //calcoliamo la distanza in centimetri

//////evitiamo una divisione per zero, sostituendo lo zero con 1000
  Serial.print(distanza); 
  Serial.println ("cm");
  Serial.print(rval);
           
 
 
 return rval;

}

long microsecondsToCentimeters(long microseconds)
  {
   return microseconds / cmconv;
  }
  
