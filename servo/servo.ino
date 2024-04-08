#include <Servo.h> 
#include <Servo.h>
#define srv 8
#define button 13
#define button2 10
Servo servo1;
Servo servo2;

void setup() 
{ 
  pinMode(button,OUTPUT);
  pinMode(button2,OUTPUT);
  servo1.attach(srv);
  servo1.write(0);  // set servo to mid-point
  servo2.attach(srv)
  servo2.write(0)
} 

void loop() {
  if(digitalRead(button) == 0) {
    servo1.write(90);
    delay(1000);
  }
  else {
  servo1.write(0);
  delay(1000);
  }


  if(digitalRead(button2) == 0) {
    servo2.write(180);
    delay(1000);
  }
  else {
  servo2.write(0);
  delay(1000);
  }
  } 
