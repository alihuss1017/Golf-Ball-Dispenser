const int trigPin = 3; //emitter
const int echoPin = 2; //receiver

long duration;
int distance;

void setupUltrasonic() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
}

int readUltrasonic() 
{
  digitalWrite(trigPin, LOW); // no emission of signal
  delayMicroseconds(2); // 2 microsecond delay
  digitalWrite(trigPin, HIGH); // emission of signal 
  delayMicroseconds(10); //10 microsecond wait
  digitalWrite(trigPin, LOW); //stop sending emission
  duration = pulseIn(echoPin, HIGH); // receive time taken of reflected signal going back to sensor
  distance= duration*0.034/2; // formula received from a forum in calculating distance
  Serial.print("Distance: ");
  Serial.println(distance); //prints distance in serial monitor
  return distance; //this distance will be used in the conditional logic for golf ball dispensing.
}