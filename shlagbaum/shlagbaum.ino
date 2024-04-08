#include <Servo.h>;
#define sensor A0
#define srv 7
Servo servo1;

void setup() {
  pinMode(sensor, INPUT );
  servo1.attach(srv);
  servo1.write(0);  // set servo to mid-point

}

void loop() {
  if(analogRead(sensor)>500){
    servo1.write(90);
    delay(2000);
    servo1.write(0);
  }
  else {
    servo1.write(0);
    delay(2000);
  }

}
