bool state = false;
void setup() {               

  // initialize the digital pins as an output.

  setupActuator();
  setupUltrasonic();

}

void loop() {
 if (readUltrasonic() < 10) { // if distance is less than 10
   if (!state) {
   Forward(); //retracts (allows golf ball to go through)
 }
   delay(300); // wait 300 ms
   state = true;
   while (state) {
   Stop(); // extends
   if(readUltrasonic() > 10) {
     state = false;
   }
   }
 }

}



