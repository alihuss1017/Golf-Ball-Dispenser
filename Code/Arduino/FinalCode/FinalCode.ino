#include <Servo.h>
Servo s1;
Servo s2;
bool state = false;
void setup() {               

  // initialize the digital pins as an output.
  s1.attach(9);
  s2.attach(10);
  setupUltrasonic();
}

void loop() {
  if (readUltrasonic() < 10 && state == false) {
  s1.write(0);
  delay(1000);
  s1.detach();
  delay(1000);
  s1.attach(9);
  s1.write(90);
  delay(1000);
  s1.detach();
  delay(1000);
  s1.attach(9); // code from lines 15-24 do the same as our first iteration code in dispensing one golf ball. However, this time the top servo lets one golf ball in between itself and the bottom servo.
  s2.write(0);
  delay(1000);
  s2.detach();
  delay(1000);
  s2.attach(10);
  s2.write(90);
  delay(1000);
  s2.detach();
  delay(1000);
  s2.attach(10); //code from lines 25-34 cause the bottom servo to rotate away from pipe (allows dispensing) and then goes back to original position.
  state = true;
  }
  while (state) { //this condition ensures that the customer must remove the nearby object and then place it near the sensor to dispense another object
    if (readUltrasonic() < 10) {
      state = false;
    }
  }
 }

