#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#define joyX A0
#define joyY A1
int applex = random(0,16);
int appley = random(0,8);
int lenght = 1;
int snakex = 3;
int snakey = 4;
byte dir = 0; // 0 right; 1 down; 2 left; 3 up;
Adafruit_8x16matrix matrix = Adafruit_8x16matrix();

void setup() {
  Serial.begin(9600);
  Serial.println("16x8 LED Matrix Test");
  matrix.begin(0x70);  // pass in the address
  matrix.clear();      // clear display
  matrix.writeDisplay();
  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
  matrix.drawPixel(appley, applex, LED_ON);
  matrix.writeDisplay();
  toMatrix();
}
void loop() {
  matrix.drawPixel(snakey, snakex, LED_ON);
  matrix.writeDisplay();
  delay(500);
  matrix.drawPixel(snakey, snakex, LED_OFF);
  matrix.writeDisplay();
  if(dir == 0) {
  snakex = snakex + 1;
  if (snakex > 15) {
    snakex = 0;
  }
  }

  if(dir == 1) {
  snakey = snakey - 1;
  if (snakey < 0) {
    snakey = 7;
  }
  }


if(dir == 2) {
  snakex = snakex - 1;
  if (snakex < 0) {
    snakex = 15;
  }
  }


if(dir == 3) {
  snakey = snakey + 1;
  if (snakey > 7) {
    snakex = 0;
  }
  }









  
  snakex = snakex - 1;
  if(snakex < 0) {
    snakex = 15;
  }
  snakey = snakey - 1;
  if(snakey < 0) {
    snakey = 7;
  }

  snakey = snakey + 1;
  if(snakey > 7) {
    snakey = 0;
  }
  
}
