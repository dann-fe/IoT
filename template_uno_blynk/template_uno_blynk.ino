//===================================================================================
// Template Blynk UNO
//===================================================================================
// Blynk Token ------------------------------------------------
#define BLYNK_TEMPLATE_ID "TMPLwHO9_Ha6"
#define BLYNK_TEMPLATE_NAME "arduino uno"
#define BLYNK_AUTH_TOKEN "k7gLj64uaxa9B5Fm6uh9-0n8cYY2GDwm"
// WIFI login -------------------------------------------------
char ssid[] = "MIF-2.4GHz";
char pass[] = "e7sP4yysywbz";
// constant for Blynk -----------------------------------------
#define BLYNK_PRINT Serial
#define ESP8266_BAUD 9600
#define RX A4 //7
#define TX A5 //8
char auth[] = BLYNK_AUTH_TOKEN;
// libraries --------------------------------------------------
// #include "Servo.h"
// libraries blynk --------------------------------------------
#include <SoftwareSerial.h>
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
//#include <Wire.h>
//#include "RichShieldDHT.h"
//#include "RichShieldTM1637.h"
// constant pin -----------------------------------------------
#define yellow 7
#define greenbrightness 5
#define bluebrightness 6
#define K1 8
#define K2 9
#define red 4
#define pot A0
#define brightnesssensor A2
#define buzzer 3
//#define CLK 10//CLK of the TM1637 IC connect to D10 of OPEN-SMART UNO R3
//#define DIO 11//DIO of the TM1637 IC connect to D11 of OPEN-SMART UNO R3
// constant common --------------------------------------------
// const float pi = 3.14;
// variables --------------------------------------------------
// int count = 0;
// prepare other hardware -------------------------------------
//TM1637 disp(CLK,DIO);
//DHT dht;
// prepare hardware -------------------------------------------
SoftwareSerial EspSerial(RX, TX); // RX, TX
ESP8266 wifi(&EspSerial); // prepare blynk --------------------
BlynkTimer timer;         // prepare time
// ============================================================
// functions blynk --------------------------------------------
BLYNK_CONNECTED() { // function ready blynk -------------------
  digitalWrite(yellow, 1);
}
//BLYNK_WRITE(V1) {   // example tranfer from blynk ------------
//bool value = param.asInt();
// digitalWrite(red, value);
//}
void control () {   // example tranfer to blynk ---------------
  //Blynk.virtualWrite(V5,digitalRead(K1));
 // Blynk.virtualWrite(V10,dht.readTemperature());
 // Blynk.virtualWrite(V11,dht.readHumidity());
}
// functions common -------------------------------------------
//
// ============================================================
void setup() {
  // Serial monitor and Serial WIFI ---------------------------
  Serial.begin(9600);
  EspSerial.begin(ESP8266_BAUD);
  delay(3000);
  // prepare pins ---------------------------------------------
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(greenbrightness, OUTPUT);
  pinMode(bluebrightness, OUTPUT);
  pinMode(brightnesssensor, INPUT);
  pinMode(pot, INPUT);
  pinMode(buzzer, OUTPUT);
  // prepare variable ------------------------------------------
  //
  // prepare hardware -----------------------------------------
  //disp.init();  
 // dht.begin();
  // prepare blynk --------------------------------------------
  Blynk.begin(auth, wifi, ssid, pass);
  timer.setInterval(100L, control);
}
// ===========================================================
void loop() {
  // work programm -------------------------------------------
  //disp.display(dht.readHumidity());
  //delay(2000);
  //disp.display(dht.readTemperature());
  //delay(2000);
  // work blynk ----------------------------------------------
  Blynk.run(); timer.run();
}
// ===========================================================
