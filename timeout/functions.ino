
bool timeout(unsigned long started_time, double pause){

 bool timeout = false;
  if(micros()-started_time > pause) timeout = true;

  return timeout;
  
}

