#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#define joyX A0
#define joyY A1
//byte applex = random(0, 16);
//byte appley = random(0, 8);
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
  //matrix.drawPixel(appley, applex, LED_ON);
 // matrix.writeDisplay();

}
void loop() {


  int x = analogRead(joyX);  //left 0 right 1000
  int y = analogRead(joyY);   // up-1000 down-0
  Serial.println(x);
  Serial.print(x);
  Serial.println(y);
  matrix.drawPixel(y, x, LED_ON);
  matrix.writeDisplay();
  delay(300);
  matrix.drawPixel(y, x, LED_OFF);
  matrix.writeDisplay();

 /* if ((appley == y) && (applex == x)) {
    applex = random(0,16);
    appley = random(0,8);
    matrix.drawPixel(appley, applex, LED_OFF);
    matrix.drawPixel(appley, applex, LED_ON);
    matrix.writeDisplay();
    count = count + 1;
    Serial.println(count);*/
  

}
