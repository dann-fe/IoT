#include <Adafruit_NeoPixel.h>
#define leds A3
#define numbers 4
Adafruit_NeoPixel pixel = Adafruit_NeoPixel(numbers, leds, NEO_GRB + NEO_KHZ800);
void setup() {
  pixel.begin(); /*
  pixel.setPixelColor(0, 250,250,0);
  pixel.setPixelColor(1, 100,0,100);
  pixel.setPixelColor(2, 0,100,100);
  pixel.setPixelColor(3, 250,250,250);
  pixel.show(); */
}

void loop() {
  /*
    pixel.setPixelColor(0, 150,75,0);
    pixel.setPixelColor(1, 255,192,203);
    pixel.setPixelColor(2, 144, 238, 144);
    pixel.setPixelColor(3, 250,250,250);
    pixel.show();*/

  
    pixel.setPixelColor(0, 250,0,0);
    pixel.show();
    delay(300);
    pixel.setPixelColor(0, 0, 0, 0);
    pixel.show();
    delay(300);
    pixel.setPixelColor(1, 255, 115, 0);
    pixel.show();
    delay(300);
    pixel.setPixelColor(1, 0, 0, 0);
    pixel.show();
    delay(300);
    pixel.setPixelColor(2, 255, 255, 0);
    pixel.show();
    delay(300);
    pixel.setPixelColor(2, 0, 0, 0);
    pixel.show();
    delay(300);
    pixel.setPixelColor(3, 0, 255, 4);
    pixel.show();
    delay(300);
    pixel.setPixelColor(3, 0, 0, 0);
    pixel.show();
    delay(300);
    pixel.setPixelColor(4, 2, 200, 235);
    pixel.show();
    delay(300);
    pixel.setPixelColor(4, 0, 0, 0);
    pixel.show();
    delay(300);
    pixel.setPixelColor(0, 1, 14, 110);
    pixel.show();
    delay(300);
    pixel.setPixelColor(0, 0, 0, 0);
    pixel.show();
    delay(300);
    pixel.setPixelColor(1, 153, 0, 173);
    pixel.show();
    delay(300);
    pixel.setPixelColor(1, 0, 0, 0);
    pixel.show();
    delay(300);
  
  for (int i = 0; i < 4; i = i + 1) {
    pixel.setPixelColor(i, 250, 0, 0);
    pixel.show();
    delay(300);
    pixel.setPixelColor(i, 0, 0, 0);
    pixel.show();
    delay(300);
  }
}
