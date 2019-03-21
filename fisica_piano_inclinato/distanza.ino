

//  
//void dist(){
//
//
////  for(int i=0; i<5; i++){
////    tempi[i]=0;
////  }
//  
//  for (int i=0; i<5; i++){
//  
//    digitalWrite (sonarTrigger[i], HIGH);                                        // attraverso il trigger inizia a emettere onde
//    delayMicroseconds(10);                                                   // per dieci secondi
//    digitalWrite(sonarTrigger[i],LOW);                                           // e si ferma
//  
//    long duration = pulseIn(sonarEcho[i], HIGH);                                  //attraverso la funzione pulseIn acquisiamo il segnale tramite il sensore
//
////    Serial.println();
////    Serial.println(i);
////    Serial.println();
//
//    double distanza = 0.01715 * duration; 
//  
//    if (duration >380000) { 
//            Serial.println("fuori portata");                                 //segnaliamo se la distanza è fuori dalla portata dello strumento
//    
//    }else if  (duration == 0) { 
//              duration == 1000;
//           }
//  
//    long int rval = microsecondsToCentimeters(duration); 
//  
//    if (rval<5) tempi[i]=millis();
//
// //   Serial.println(distanza);
//  }
//
//  
//for(int i=0; i<5; i++) {
//  Serial.println(tempi[i]);
//  
//}
//}  
//                                  //calcoliamo la distanza

//  long int distanza = 0.036 * duration /2;                                 //calcoliamo la distanza
 

//  Serial.println("");
//  Serial.print("istante ");
//  Serial.print(count);
//  Serial.print(" - al millisecondo ");
//  Serial.print(millis());
//  Serial.print(" - durata: ");                                               //stampiamo sul monitor seriale la durata del segnale e la distanza ottenuta
//  Serial.println(duration);
//  Serial.print(" distanza: ");

                   //calcoliamo la distanza in centimetri

//////evitiamo una divisione per zero, sostituendo lo zero con 1000
//  Serial.print(distanza); 
//  Serial.println (" cm");
//  Serial.print(rval);
 
 



long microsecondsToCentimeters(long microseconds)
  {
   return microseconds / cmconv;
  }
