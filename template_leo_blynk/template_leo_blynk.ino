//===================================================================================
// Template Blynk LEO
//===================================================================================
// Blynk Token ------------------------------------------------
#define BLYNK_TEMPLATE_ID "TMPL4kZi2AvWe"
#define BLYNK_TEMPLATE_NAME "blank"
#define BLYNK_AUTH_TOKEN "jDiEBAODBREBJEJnB5-m6yLFlQeBus8M"
// WIFI login -------------------------------------------------
char ssid[] = "MIF-2.4GHz";
char pass[] = "e7sP4yysywbz";
// constant for Blynk -----------------------------------------
#define BLYNK_PRINT Serial
#define ESP8266_BAUD 9600
#define EspSerial Serial1
char auth[] = BLYNK_AUTH_TOKEN;
// libraries --------------------------------------------------
// #include "Servo.h"
#include <Wire.h>
//#include <RTClib.h>

// libraries blynk --------------------------------------------
//#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// constant pin -----------------------------------------------
#define yellow 7
#define green 5
#define blue 6
#define K1 8
#define K2 9
#define red 4
#define pot A0
#define Lsensor A2
#define buzzer 3

// constant common --------------------------------------------
// const float pi = 3.14;
// variables --------------------------------------------------
// int count = 0;
bool stat = 0;
byte sec = 0;
byte statsem = 0; //0-red 1-yellow 2-green
bool onoff = 0;
// prepare other hardware -------------------------------------
//DHT dht;
//RTC_DS1307 watch;

// prepare hardware -------------------------------------------
ESP8266 wifi(&EspSerial); // prepare blynk --------------------
BlynkTimer timer;         // prepare time

// ============================================================
// functions blynk --------------------------------------------
/*BLYNK_CONNECTED() { // function ready blynk -------------------
  digitalWrite(yellow, 1);
  }*/
/*BLYNK_WRITE(V0) {   // example tranfer from blynk ------------
  bool value = param.asInt();
  digitalWrite(green, value);
  }*/
BLYNK_WRITE(V1) {   // example tranfer from blynk ------------
  byte value = param.asInt();
  analogWrite(blue, value);
}
BLYNK_WRITE(V7) {
  onoff = param.asInt();
}
BLYNK_WRITE(V2) {   // example tranfer from blynk ------------
  bool value = param.asInt();
  if (value == 1) {
    tone(buzzer, 500);
  }
  else {
    noTone(buzzer);
  }
}

void control () {   // example tranfer to blynk ---------------
  Blynk.virtualWrite(V3, analogRead(Lsensor));
  // Blynk.virtualWrite(V10,dht.readTemperature());
  // Blynk.virtualWrite(V11,dht.readHumidity());
  Blynk.virtualWrite(V4, analogRead(pot));
  Blynk.virtualWrite(V5, digitalRead(K1));

}
void control2 () {    // 0-red on, green off    1-red off yellow-on  2 yellow off green on
  if (onoff == 1) {
    if (statsem == 0) {
      digitalWrite(red, 1);
      digitalWrite(green, 0);
    }
    if (statsem == 1) {
      digitalWrite(red, 0);
      digitalWrite(yellow, 1);
    }
    if (statsem == 2) {
      digitalWrite(yellow, 0);
      digitalWrite(green, 1);
    }
    statsem = statsem + 1;
    if (statsem == 3) {
      statsem = 0;
    }
  }
  else {
    digitalWrite(red, 0);
    digitalWrite(yellow, 0);
    digitalWrite(green, 0);
  }
}
void control3 () {
  tone(buzzer, 500, 1000);
  /*
    sec = sec + 1;
    Serial.println(sec);
    if(sec == 10) {
    tone(buzzer, 500);
    sec = 0;
    }
    else {
    noTone(buzzer);
    }
  */
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
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(Lsensor, INPUT);
  pinMode(pot, INPUT);
  pinMode(buzzer, OUTPUT);
  // prepare variable ------------------------------------------
  //
  // prepare hardware -----------------------------------------
  //disp.init();
  // dht.begin();
  Wire.begin();
  // watch.begin();
  //delay(2000);
  // watch.adjust(DateTime(2023, 10, 7, 1, 0, 0));

  // prepare blynk --------------------------------------------
  Blynk.begin(auth, wifi, ssid, pass);
  timer.setInterval(100L, control);
  timer.setInterval(1000L, control2);
  timer.setInterval(10000L, control3);

}
// ===========================================================
void loop() {
  //  DateTime now = watch.now();
  //  Serial.println(now.second());
  // work programm -------------------------------------------
  //disp.display(dht.readHumidity());
  //delay(2000);
  //disp.display(dht.readTemperature());
  //delay(2000);
  // work blynk ----------------------------------------------
  Blynk.run(); timer.run();
}
// ===========================================================
