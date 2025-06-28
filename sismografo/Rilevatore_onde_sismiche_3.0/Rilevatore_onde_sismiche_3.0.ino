#include "Wire.h"
#include <MPU6050_light.h>

float x1 = 0;
float maxx = 0;
float minx = 0;
float distx = 0;
float y1 = 0;
float maxy = 0;
float miny = 0;
float disty = 0;
float z1 = 0;
float maxz = 0;
float minz = 0;
float distz = 0;
float errX[2];
float errY[2];
float errZ[2];
int buzzer = 7;
int ledR = 2;
int ledG = 3;
int ledV = 4;




MPU6050 mpu(Wire);
unsigned long timer = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledV, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Wire.begin();
  
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while(status!=0){ } // stop everything if could not connect to MPU6050
  
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(200);
  mpu.calcOffsets(); // gyro and accelero
  Serial.println("Done!\n");
  
  
    errX[1] = -1000;
    errY[1] = -1000;
    errZ[1] = -1000;
  
    errX[0] = 1000;
    errY[0] = 1000;
    errZ[0] = 1000;
  

  for (int i=0; i<10; i++){    
    mpu.update();

    x1 = mpu.getAccX();
    
    if (x1>errX[1]) {
      errX[1] = x1;
    }
    
    if (x1<errX[0]) {
      errX[0] = x1;
    }
    delay(200);
 }

 for (int i=0; i<10; i++){    
    mpu.update();

    y1 = mpu.getAccY();
    
    if (y1>errY[1]) {
      errY[1] = y1;
    }
    
    if (y1<errY[0]) {
      errY[0] = y1;
    }
    delay(200);
 }

 for (int i=0; i<10; i++){    
    mpu.update();

    z1 = mpu.getAccZ();
    
    if (z1>errZ[1]) {
      errZ[1] = z1;
    }
    
    if (z1<errZ[0]) {
      errZ[0] = z1;
    }
    delay(200);
 }
 
    errX[1] += 0.02;
    errY[1] += 0.02;
    errZ[1] += 0.02;
  
    errX[0] -= 0.02;
    errY[0] -= 0.02;
    errZ[0] -= 0.02;

 for (int i=0; i<2; i++){
    Serial.println(errX[i]);
    Serial.println(errY[i]);
    Serial.println(errZ[i]);
    Serial.println("---------");
 }

}

void loop() {
  mpu.update();

  x1 = mpu.getAccX();

  if(x1>errX[1]){

    digitalWrite(ledV, HIGH); // sets the digital pin 13 on
    delay(100);            // waits for a second
    digitalWrite(ledV, LOW);
    if (x1>errX[1] + 0.05){
      digitalWrite(buzzer, HIGH); // sets the digital pin 13 on
      delay(100);
      digitalWrite(buzzer, LOW);
    }
    Serial.print("X = ");
    Serial.println(x1);
  } 
  
  if(x1<errX[0]){
    
    digitalWrite(ledV, HIGH); // sets the digital pin 13 on
    delay(100);            // waits for a second
    digitalWrite(ledV, LOW);
    if (x1<errX[0] - 0.05){
      digitalWrite(buzzer, HIGH); // sets the digital pin 13 on
      delay(100);
      digitalWrite(buzzer, LOW);
    }
    Serial.print("X = ");
    Serial.println(x1);
  }

  y1 = mpu.getAccY();

    if(y1>errY[1]){

    digitalWrite(ledG, HIGH); // sets the digital pin 13 on
    delay(100);            // waits for a second
    digitalWrite(ledG, LOW);
    if (y1>errY[1] + 0.05){
      digitalWrite(buzzer, HIGH); // sets the digital pin 13 on
      delay(100);
      digitalWrite(buzzer, LOW);
    }
    Serial.print("Y = ");
    Serial.println(y1);
  } 
  
  if(y1<errY[0]){
    
    digitalWrite(ledG, HIGH); // sets the digital pin 13 on
    delay(100);            // waits for a second
    digitalWrite(ledG, LOW);
    if (y1<errY[0] - 0.05){
      digitalWrite(buzzer, HIGH); // sets the digital pin 13 on
      delay(100);
      digitalWrite(buzzer, LOW);
    }
    Serial.print("Y = ");
    Serial.println(y1);
  }

  z1 = mpu.getAccZ();

    if(z1>errZ[1]){

    digitalWrite(ledR, HIGH); // sets the digital pin 13 on
    delay(100);            // waits for a second
    digitalWrite(ledR, LOW);
    if (z1>errZ[1] + 0.05){
      digitalWrite(buzzer, HIGH); // sets the digital pin 13 on
      delay(100);
      digitalWrite(buzzer, LOW);
    }
    Serial.print("Z = ");
    Serial.println(z1);
  } 
  
  if(z1<errZ[0]){
    
    digitalWrite(ledR, HIGH); // sets the digital pin 13 on
    delay(100);            // waits for a second
    digitalWrite(ledR, LOW);
    if (z1<errZ[0] - 0.05){
      digitalWrite(buzzer, HIGH); // sets the digital pin 13 on
      delay(100);
      digitalWrite(buzzer, LOW);
    }
    Serial.print("Z = ");
    Serial.println(z1);
  }


}


