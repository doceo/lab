#include <Servo.h>

Servo servo;  

int livelloAcqua, umidUno, umidDue;

int sogliaUmidita = 500;
int sogliaAcqua = 100;

int pinLivelloAcqua = 3;
int pinPompa = 4;
int pinUmidUno = 1;
int pinUmidDue = 2;
int cicalino = 8;

int attesaAcqua = 3000;
int attesaServo = 2000;

int angoloVasoUno =120;
int angoloVasoDue =45; 
int angoloRiposo = 90;


void setup() {

Serial.begin(9600);
  
pinMode(pinUmidUno, INPUT);
pinMode(pinUmidDue, INPUT);
pinMode(pinLivelloAcqua, INPUT);

pinMode(pinPompa, OUTPUT);
pinMode(cicalino, OUTPUT);


servo.attach(9);
servo.write(angoloRiposo);

digitalWrite(pinPompa, HIGH);
}

void loop() {

umidUno = analogRead(pinUmidUno);
umidDue = analogRead(pinUmidDue);
livelloAcqua = 800; //analogRead(pinLivelloAcqua);

Serial.println(umidUno);
Serial.println(umidDue);
Serial.println(livelloAcqua);

if ((livelloAcqua > sogliaAcqua ) && (umidUno < sogliaUmidita)){

  innaffia(angoloVasoUno);
//servo.write(angoloVasoUno);
//  delay(attesaServo);
//  
//  digitalWrite(pinPompa, LOW);
//  digitalWrite(cicalino, HIGH);
//  
//  delay(attesaAcqua);
//  
//  digitalWrite(pinPompa, HIGH);
//  digitalWrite(cicalino, LOW);
//  
//  delay(attesaServo);
//  
//  servo.write(angoloRiposo);
  
}
livelloAcqua = 800; //analogRead(livelloAcqua);


if ((livelloAcqua > sogliaAcqua ) && (umidDue < sogliaUmidita)){

  innaffia(angoloVasoDue);

}

delay(6000);

}


void innaffia(int angolo){

  servo.write(angolo);
  delay(attesaServo);
  digitalWrite(pinPompa, LOW);
  digitalWrite(cicalino, HIGH);

  delay(attesaAcqua);
  digitalWrite(pinPompa, HIGH);
  digitalWrite(cicalino, LOW);

  delay(attesaServo);
  servo.write(angoloRiposo);

  
}
