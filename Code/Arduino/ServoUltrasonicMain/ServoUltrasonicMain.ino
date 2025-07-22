#include <Servo.h>
Servo s1;
bool state = false;
void setup() {               

  // initialize the digital pins as an output.
  s1.attach(9);
  setupUltrasonic();
}

void loop() {
  if (readUltrasonic() < 10 && state == false) {
  s1.write(0); // rotates away from pipe (allows dispensing)
  delay(1000); //wait 1 second
  s1.detach(); // stop
  delay(1000); // wait 1 second
  s1.attach(9); // continue
  s1.write(90); // rotate back to blocking position
  delay(1000); // wait 1 second
  s1.detach(); //stop
  delay(1000);//wait 1 second
  s1.attach(9); //continue
  }
  while (state) { // this condition ensures that the customer must remove the nearby object and then place it near the sensor to dispense another object
    if (readUltrasonic() < 10) {
      state = false;
    }
  }
 }

