int ENABLE1 = 9;
int FWD1 = 7;
int REV1 = 6;

int ENABLE2 = 8;
int FWD2 = 5;
int REV2 = 4;

int Speed = 255;

void setupActuator() {

  pinMode(ENABLE1, OUTPUT); 
  pinMode(ENABLE2, OUTPUT);

  pinMode(FWD1, OUTPUT);
  pinMode(REV1, OUTPUT);

  pinMode(FWD2, OUTPUT);
  pinMode(REV2, OUTPUT);

}

void Forward() { //actuator will extend (blocking mechanism)

  digitalWrite(ENABLE1, HIGH); 
  analogWrite(REV1, 0); 
  analogWrite(FWD1, Speed);
  
  digitalWrite(ENABLE2, HIGH);
  analogWrite(REV2, 0); 
  analogWrite(FWD2, Speed);

}

void Stop() { // actuator will retract (releasing mechanism)

  digitalWrite(ENABLE1, LOW);
  analogWrite(FWD1, 0); 
  analogWrite(REV1, 0);

  digitalWrite(ENABLE2, LOW);
  analogWrite(FWD2, 0); 
  analogWrite(REV2, 0);

}