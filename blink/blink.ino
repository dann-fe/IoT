//===================================================================================
// Template v 001
//===================================================================================
// ----- global define ----------------------------------------------
//
// ----- libraries --------------------------------------------------
// #include <NewPing.h>
// ----- constant pin -----------------------------------------------
 #define ledr 8
 #define ledb 6
 #define yellow 10
// ----- constant common --------------------------------------------
// const float pi = 3.14;
// ----- variables --------------------------------------------------
long count = 0;
long count1 = 0;
long count2 = 0;
// ----- prepare hardware -------------------------------------------
// Servo servo1;
// ==================================================================
// functions common -------------------------------------------------
// void control() {}
// ==================================================================
void setup() {
  // Serial monitor -------------------------------------------------
  Serial.begin(9600); delay(3000);
  // ----- prepare pins ---------------------------------------------
   pinMode(ledr,OUTPUT);
   pinMode(ledb,OUTPUT);
   pinMode(yellow,OUTPUT);
  // ----- prepare variable -----------------------------------------
  //
  // ----- prepare hardware -----------------------------------------
  count = millis();
  count1 = millis();
  count2 = millis();
} // ================================================================
void loop() { // ----- work programm -----------------------------------------
if((millis()-count)>900) {
  digitalWrite(ledr, !digitalRead(ledr));
  count = millis();
}
if((millis()-count1)>300) {
  digitalWrite(ledb, !digitalRead(ledb));
  count1 = millis();
}
if((millis()-count2)>100) {
  digitalWrite(yellow, !digitalRead(yellow));
  count2 = millis();
}
} // ================================================================
