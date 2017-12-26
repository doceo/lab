

char colore (){

  int redColor = 0;
  int greenColor = 0;
  int blueColor = 0;

  char color;

  
// inizializziamo il sensore di lettura del rosso
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);

  // lettura del sensore
  redFrequency = pulseIn(sensorOut, LOW);
  
  // 70 e 120 sono valori campione, andrebbero ricampionati sullo
  //sketch di realizzazione
  redColor = map(redFrequency, 70, 120, 255,0);
  
  //  stampiamo sul monitor seriale
  //  Serial.print("R = ");
  //  Serial.print(redColor);
  //  delay(100);
  
  // set per acquisizione del verde
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // lettura del sensore
  greenFrequency = pulseIn(sensorOut, LOW);
  
  // 100, 199 sono parametri scelti arbitrariamente
  greenColor = map(greenFrequency, 100, 199, 255, 0);
  
  // Printing the GREEN (G) value  
  //  Serial.print(" G = ");
  //  Serial.print(greenColor);
  //  delay(100);
 
  // set per acquisizione del blue
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // lettura del sensore
  blueFrequency = pulseIn(sensorOut, LOW);

  // 38, 84 sono parametri scelti arbitrariamente
  blueColor = map(blueFrequency, 38, 84, 255, 0);
  
  // per stampare sul monitor seriale
  //  Serial.print(" B = ");
  //  Serial.print(blueColor);
  //  delay(100);

  // Checks the current detected color and prints
  // a message in the serial monitor
  if(redColor > greenColor && redColor > blueColor){
      Serial.println(" - RED detected!");
      color = 'R';
  }
  if(greenColor > redColor && greenColor > blueColor){
    Serial.println(" - GREEN detected!");
      color = 'G';
  }
  if(blueColor > redColor && blueColor > greenColor){
    Serial.println(" - BLUE detected!");
      color = 'B';
  }

  return color;
  
}

