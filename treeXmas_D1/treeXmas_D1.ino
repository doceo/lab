//static const uint8_t D0   = 16; 
//static const uint8_t D1   = 5;
//static const uint8_t D2   = 4;
//static const uint8_t D3   = 0;
//static const uint8_t D4   = 2; 
//static const uint8_t D5   = 14;
//static const uint8_t D6   = 12;
//static const uint8_t D7   = 13;
//static const uint8_t D8   = 15;
//static const uint8_t D9   = 3;
//static const uint8_t D10  = 1;

int s0 = 15;
int s1 = 12;
int s2 = 14;
int s3 = 4;


  int muxChannel[16][4]={
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    {0,0,1,0}, //channel 4
    {1,0,1,0}, //channel 5
    {0,1,1,0}, //channel 6
    {1,1,1,0}, //channel 7
    {0,0,0,1}, //channel 8
    {1,0,0,1}, //channel 9
    {0,1,0,1}, //channel 10
    {1,1,0,1}, //channel 11
    {0,0,1,1}, //channel 12
    {1,0,1,1}, //channel 13
    {0,1,1,1}, //channel 14
    {1,1,1,1}  //channel 15
  }
//Mux in "SIG" pin
int SIG_pin = 0;

void setup(){
  pinMode(s0, OUTPUT); 
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 
  pinMode(s3, OUTPUT); 

  pinMode(SIG_pin, OUTPUT);

  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);

  digitalWrite (SIG_pin, HIGH);
  Serial.begin(9600);
}

void loop(){

  //Loop through and read all 16 values
  //Reports back Value at channel 6 is: 346
  for(int i = 0; i < 16; i ++){
    Serial.print("Value at channel ");
    Serial.print(i);
    Serial.print("is : ");
     digitalWrite(controlPin[i], muxChannel[channel][i]);

    delay(1000);


    
  }

}




  //read the value at the SIG pin

}
