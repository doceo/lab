int red = A6;
int green = A5;
int blue = A7;

void setup() 
{
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);
}


void loop() 
{
analogWrite(blue, random(255)); //la funzione random genera dei numeri casuali in modo da creare dei colori casuali analogWrite(red, random(255)); analogWrite(green, random(255));
analogWrite(red, random(255));
analogWrite(green, random(255));
delay(500);
}
