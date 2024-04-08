#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#define joyX A0
#define joyY A1
int appley = random(0, 8);
int applex = random(0, 16);
byte score = 1;
int length = 1;
int snakex = 4;
int snakey = 2;
byte dir = 0; //0 right, 1 down, 2 left, 3 up
int list [128] =  {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};



Adafruit_8x16matrix matrix = Adafruit_8x16matrix();

void stopAll () {
  while (true) {
    matrix.clear();
    matrix.writeDisplay();
  }
}

void toMatrix () {
  for (int i = 0; i < 128; i++) {
    int x1 = i % 16;
    int y1 = (i - x1) / 16;
    y1 = 7 - y1;
    if (list[i] != 0) matrix.drawPixel(y1, x1, LED_ON);
    else             matrix.drawPixel(y1, x1, LED_OFF);
  }
  matrix.writeDisplay();
}
void decrement () {
  for (int i = 0; i < 128; i++) {
    if (list[i] > 0) {
      list[i] = list[i] - 1;
    }
  }
}



void setup() {
  Serial.begin(9600);
  Serial.println("16x8 LED Matrix Test");
  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
  matrix.begin(0x70);  // pass in the address
  matrix.clear();
  // clear display
  list[applex + appley * 16] = -1;
  toMatrix();


}
void loop() {



  //0 right, 1 down, 2 left, 3 up
  if ((analogRead(joyX) > 700) && (dir != 2)) {
    dir = 0;
  }
  if ((analogRead(joyX ) < 300) && (dir != 0)) {
    dir = 2;
  }
  if ((analogRead(joyY) > 700) && (dir != 3)) {
    dir = 1;
  }
  if ((analogRead(joyY) < 300) && (dir != 1)) {
    dir = 3;
  }

  if (dir == 0) {
    snakex = snakex + 1;
    if (snakex > 15) stopAll();
  }
  if (dir == 2) {
    snakex = snakex - 1;
    if (snakex < 0) stopAll();
  }
  if (dir == 3) {
    snakey = snakey + 1;
    if (snakey > 7) stopAll();
  }
  if (dir == 1) {
    snakey = snakey - 1;
    if (snakey < 0) stopAll();
  }


  //0 right, 1 down, 2 left, 3 up

  if ((applex == snakex) && (appley == snakey)) {
    matrix.drawPixel(appley, applex, LED_OFF);
    matrix.writeDisplay();
    score = score + 1;
    applex = random(0, 16);
    appley = random(0, 8);
    list[applex + appley * 16] = -1;
  }
  else
    decrement();
  if (list[snakex + snakey * 16] > 0) {
    stopAll();
  }
  list[snakex + snakey * 16] = score;
  toMatrix();
  delay(300);
}
