//===================================================================================
// Template v 001
//===================================================================================
// ----- global define ----------------------------------------------
//
// ----- libraries --------------------------------------------------
// #include <NewPing.h>
// ----- constant pin -----------------------------------------------
#define red 4    // 3,5,6,9,10,11
#define green 5
#define blue 6
#define yellow 7
#define k1 8
#define k2 9
#define buzzer 3
#define pot A0
#define temperature A1
#define bright A2 
// ----- constant common --------------------------------------------
// const float pi = 3.14;
// ----- variables --------------------------------------------------
// int count = 0;
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
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(k1, INPUT_PULLUP);
  pinMode(k2, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  // ----- prepare variable -----------------------------------------
  //
  // ----- prepare hardware -----------------------------------------
  // servo.attach();
} // ================================================================
void loop() { // ----- work programm -----------------------------------------
  digitalWrite(yellow, 1);
  if (digitalRead(k1) == 0)     {
    digitalWrite(red, 1);
    tone(buzzer, 350);
  }
  else     {
    digitalWrite(red, 0);
    noTone(buzzer);
  }
  
  if (digitalRead(k2) == 0)     digitalWrite(blue, 1);
  else     digitalWrite(blue, 0);

  Serial.print("pot:");
  Serial.println(analogRead(A0));
  Serial.print("temperature:");
  Serial.println(analogRead(A1));
  Serial.print("bright:");
  Serial.println(analogRead(A2));
  analogWrite(green, analogRead(pot)/4);
} // ================================================================
