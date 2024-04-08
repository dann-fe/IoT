//===================================================================================
// Template v 001
//===================================================================================
// ----- global define ----------------------------------------------
//
// ----- libraries --------------------------------------------------
#include <NewPing.h>
// ----- constant pin -----------------------------------------------
// #define gnd 7
#define buzzer 6
#define trig 11
#define echo 2
// #define vcc 2

// ----- constant common --------------------------------------------
// const float pi = 3.14;
// ----- variables --------------------------------------------------
// int count = 0;
// ----- prepare hardware -------------------------------------------
// Servo servo1;
NewPing sonar(trig, echo, 50);
// ==================================================================
// functions common -------------------------------------------------
// void control() {}
// ==================================================================
void setup() {
  // Serial monitor -------------------------------------------------
  Serial.begin(9600); delay(3000);
  // ----- prepare pins ---------------------------------------------
  pinMode(buzzer, OUTPUT);
  //pinMode(vcc,OUTPUT);// 0...1023    x = pot*3 +300
  //digitalWrite(vcc, 1);
  //pinMode(gnd,OUTPUT);
  //digitalWrite(gnd,0);

  tone(buzzer, 500);          // min 300  max 3300
  delay(1000);
  noTone(buzzer);
  // ----- prepare variable -----------------------------------------
  //
  // ----- prepare hardware -----------------------------------------
  // servo.attach();
} // ================================================================
void loop() { // ----- work programm --------------------------------
  Serial.print(sonar.ping_cm());
  int var = sonar.ping_cm() * 60 + 300;
  tone(buzzer, var);

} // ================================================================
