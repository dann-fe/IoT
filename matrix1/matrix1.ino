#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#define joyX A0
#define joyY A1
int applex = 8;
int appley = 3;
int count = 0;
Adafruit_8x16matrix matrix = Adafruit_8x16matrix();

void setup() {
  Serial.begin(9600);
  Serial.println("16x8 LED Matrix Test");
  matrix.begin(0x70);  // pass in the address
  matrix.clear();      // clear display
  //matrix.drawPixel(x, y, LED_ON);
  //matrix.drawPixel(3, 12, LED_ON);
  //matrix.drawPixel(7, 11, LED_ON);
  //matrix.drawPixel(5, 10, LED_ON);
  // matrix.writeDisplay();
  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
  matrix.drawPixel(appley, applex, LED_ON);
  matrix.writeDisplay();

}
void loop() {
  matrix.drawPixel(appley, applex, LED_OFF);
  matrix.writeDisplay();
  if (analogRead(joyY) > 750) {
    appley = appley + 1;
    if (appley > 7) {
      appley = 0;
    }
  }

  if (analogRead(joyY) < 250) {
    appley = appley - 1;
    if (appley < 0) {
      appley = 7;
    }
  }
  if (analogRead(joyX) > 750) {
    applex = applex + 1;
    if (applex > 15) {
      applex = 0;
    }
  }
  if (analogRead(joyX) < 250) {
    applex = applex - 1;
    if (applex < 0) {
      applex = 15;
    }
  }
  matrix.drawPixel(appley, applex, LED_ON);
  matrix.writeDisplay();
  delay(100);

  


}
