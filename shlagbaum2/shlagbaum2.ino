//===================================================================================
// Shlagbaum2
//===================================================================================
// ----- global define ----------------------------------------------
//
// ----- libraries --------------------------------------------------
 #include <NewPing.h>
 #include <Servo.h>
// ----- constant pin -----------------------------------------------
 #define srv A0
 #define red 13
 #define yellow 12
 #define green 11
 #define vcc 3
 #define trig 4
 #define echo 5
 #define gnd 6
// ----- constant common --------------------------------------------
// const float pi = 3.14;
// ----- variables --------------------------------------------------
// int count = 0;
// ----- prepare hardware -------------------------------------------
 Servo servo1;
 NewPing sonar(trig, echo, 200);
// ==================================================================
// functions common -------------------------------------------------
// void control() {}
// ==================================================================
void setup() {
  // Serial monitor -------------------------------------------------
  Serial.begin(9600); delay(3000);
  // ----- prepare pins ---------------------------------------------
   //pinMode(srv,OUTPUT);
   pinMode(red,OUTPUT);
   pinMode(yellow,OUTPUT);
   pinMode(green,OUTPUT);
   pinMode(vcc, OUTPUT);
   digitalWrite(vcc, 1);
   //pinMode(trig, INPUT);
   //pinMode(echo, INPUT);
   pinMode(gnd, OUTPUT);
   digitalWrite(gnd, 0);
   digitalWrite(red, 1);
   digitalWrite(yellow, 1);
   digitalWrite(green, 1);
   delay(3000);
   digitalWrite(red, 0);
   digitalWrite(yellow, 0);
   digitalWrite(green, 0);
   delay(1000);
   digitalWrite(red, 1);
 
  // ----- prepare variable -----------------------------------------
  //
  // ----- prepare hardware -----------------------------------------
   servo1.attach(srv);
   servo1.write(0);
} // ================================================================
void loop() { // ----- work programm -----------------------------------------
  delay(300);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");


  if(sonar.ping_cm() < 10) {
    digitalWrite(red, 0);
    digitalWrite(yellow, 1);
     digitalWrite(green, 1);
    servo1.write(90);
    delay(1000);
    digitalWrite(yellow, 0);
    digitalWrite(green, 0);
    delay(1000);
  }
  else {
    digitalWrite(green, 0);
    delay(300);
    digitalWrite(yellow, 1);
    servo1.write(0);
    delay(1000);
    digitalWrite(red, 1);
    digitalWrite(yellow, 0);
  }
} // ================================================================
