//CAN FIND ALL COMMENTS ON ULTRASONIC MODULE IN ULTRASONICACTUATOR SKETCH

const int trigPin = 3;
const int echoPin = 2;

long duration;
int distance;

void setupUltrasonic() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
}

int readUltrasonic() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  return distance; //distance used in combinational logic for dispensing
}