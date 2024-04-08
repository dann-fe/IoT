
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#define joyX A0
#define joyY A1
byte score = 0;
int x = 3;
int y = 0;
int dir = 0;
int list [64] =  {     //[x + y * 8]  [(x + (y + 1) * 8)]
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0
};

Adafruit_8x16matrix matrix = Adafruit_8x16matrix();
void deleterow () {
  int count = 0;
  for (byte i = 56; i < 64; i++) {
    count = count + list[i];
  }
  if (count == 8) {
    score = score + 1;
    Serial.println(score);
    addscore ();
    for (int forx = 0; forx < 8; forx++) {
      for (int fory = 0; fory < 8; fory++) {
        if (list[forx + fory * 8] == 1) {
          list[forx + fory * 8] = 0;
          break;
        }
      }
    }
  }
}


void addscore () {  //score

  int x2 =  (score-1) % 8;
  int y2 =  ((score - 1) - x2) / 8;
  matrix.drawPixel(y2, x2 + 8, LED_ON);
  matrix.writeDisplay();

}
void stopAll () {
  while (true) {
    matrix.clear();
    matrix.writeDisplay();
  }
}

void toMatrix () {
  for (int i = 0; i < 64; i++) {
    int x1 = i % 8;
    int y1 = (i - x1) / 8;
    y1 = 7 - y1;
    if (list[i] != 0)matrix.drawPixel(y1, x1, LED_ON);
    else             matrix.drawPixel(y1, x1, LED_OFF);
  }
  matrix.writeDisplay();
}
void setup() {
  Serial.begin(9600);
  Serial.println("16x8 LED Matrix Test");
  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
  matrix.begin(0x70);  // pass in the address
  matrix.clear();
  matrix.writeDisplay();
  // clear display
  list[x + y * 8] = 1;
  toMatrix();


}
void loop() {

  delay(800);
  list[x + y * 8] = 0;
  toMatrix();

  if ((analogRead(joyX)) < 300) {
    x = x - 1;
    if (x < 0) {
      x = 0;
    }
  }

  if ((analogRead(joyX) > 700)) {
    x = x + 1;
    if (x > 7) {
      x = 7;
    }
  }

  if ((y < 7) && (list[x + (y + 1) * 8] == 0 )) {
    y = y + 1;
  }
  else {
    list[x + y * 8] = 1;
    deleterow();
    toMatrix();
    y = 0;
    x = random(0, 8);
  }

  list[x + y * 8] = 1;
  toMatrix();



}
