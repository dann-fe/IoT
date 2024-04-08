//===================================================================================
// Template v 001
//===================================================================================
// ----- global define ----------------------------------------------
//
// ----- libraries --------------------------------------------------
// #include <NewPing.h>
// ----- constant pin -----------------------------------------------
#define redbut 11
#define bluebut 13
#define buzzer 6
#define redled A3
#define blueled A0
// ----- constant common --------------------------------------------
// const float pi = 3.14;
// ----- variables --------------------------------------------------
int val = 300;
long count1 = 0;
// ----- prepare hardware -------------------------------------------

// ==================================================================
// functions common -------------------------------------------------
// void control() {}
// ==================================================================
void setup() {
  // Serial monitor -------------------------------------------------
  Serial.begin(9600); delay(3000);
  // ----- prepare pins ---------------------------------------------
  pinMode(redbut, INPUT);
  pinMode(bluebut, INPUT  );
  pinMode(buzzer, OUTPUT);
  pinMode(blueled, OUTPUT);
  pinMode(redled, OUTPUT);
  // ----- prepare variable -----------------------------------------
  //
  // ----- prepare hardware -----------------------------------------
 count1 = millis();
} // ================================================================
void loop() { // ----- work programm -----------------------------------------

  if (digitalRead(redbut) == 0) {

    val = val + 50;
    if (val>3000) val = 3000;
    digitalWrite(redled, 1);
    if((millis() - count1)>300) {
    digitalWrite(redled, 0);
    }
  }
  if (digitalRead(bluebut) == 0) {
    if (val<300) val = 300;
    digitalWrite(redled, 1);
    if((millis() - count1)>300) {
    digitalWrite(blueled, 0);
    }
  }
  Serial.println(val);
  tone(buzzer, val);
} // ================================================================
