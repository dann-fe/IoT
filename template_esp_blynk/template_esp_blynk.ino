//===================================================================================
// Template Blynk Leonardo
//===================================================================================
// Blynk Token ------------------------------------------------
#define BLYNK_TEMPLATE_ID "TMPLwHO9_Ha6"
#define BLYNK_DEVICE_NAME "arduino uno"
#define BLYNK_AUTH_TOKEN "k7gLj64uaxa9B5Fm6uh9-0n8cYY2GDwm"
// WIFI login -------------------------------------------------
char ssid[] = "UPC5850460;
char pass[] = "e7sP4yysywbz";
// constant for Blynk -----------------------------------------
#define BLYNK_PRINT Serial
char auth[] = BLYNK_AUTH_TOKEN;
// libraries --------------------------------------------------
 #include "Servo.h"
// libraries blynk --------------------------------------------
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// constant pin -----------------------------------------------
 #define buzzer 5
 #define srv 7
// constant common --------------------------------------------
// const float pi = 3.14; 
// variables --------------------------------------------------
// int count = 0;
// prepare other hardware -------------------------------------
  Servo servo1;
// prepare hardware -------------------------------------------
BlynkTimer timer;         // prepare time
// ============================================================
// functions blynk --------------------------------------------
BLYNK_CONNECTED() { // function ready blynk -------------------
}
BLYNK_WRITE(V0) {   // example tranfer from blynk -------------
   // int value = param.asInt();
}
BLYNK_WRITE(V2) {   // example tranfer from blynk -------------
  servo1.write(param.asInt());
}
BLYNK_WRITE(V1) {   // example tranfer from blynk -------------
   if (param.asInt() == 1) {
    tone(buzzer, 500);
   }
   else {
    noTone(buzzer);
   }
}

void control () {   // example tranfer to blynk ---------------
   //Blynk.virtualWrite(V0,0);
}
// functions common -------------------------------------------
//
// ============================================================
void setup() {
  // Serial monitor and Serial WIFI ---------------------------
  Serial.begin(9600); delay(3000);
  // prepare pins ---------------------------------------------
  pinMode(buzzer, OUTPUT);
  // pinMode(led,OUTPUT);
  // ledcSetup(0, 1000, 8); ledcAttachPin(led, 0); ledcWrite(1, 0);
  // prepare variable ------------------------------------------
  //
  // prepare hardware -----------------------------------------
  servo1.attach(srv);
  // prepare blynk --------------------------------------------
  //Blynk.begin(auth, ssid, pass);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  timer.setInterval(500L, control);
}
// ===========================================================
void loop() {
  // work programm -------------------------------------------
  //
  // work blynk ----------------------------------------------
  Blynk.run(); timer.run();
} // ===========================================================
