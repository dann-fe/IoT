#include <Adafruit_GFX.h>
#include <TouchScreen.h>
#include <MCUFRIEND_kbv.h>

#define MINPRESSURE 20
#define MAXPRESSURE 1000

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define BROWN   0x8241
#define ORANGE  0xe444
int ID;
byte YP = A1;
byte XM = A2;
byte YM = 7;
byte  XP = 6;
int x = 3;
int y = 0;
long timer = 0;
MCUFRIEND_kbv tft;

byte screen[88] = {
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0

};
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 500);
TSPoint tp;

void toScreen() {  //0-off-blue 1-on-yellow

  for (int i = 0; i < 88; ++i) {
    int x1 = i % 8;
    int y1  = i / 8;
    int x2 = x1 * 20 + 80;
    int y2 = y1 * 20 + 15;
    if (screen[i] == 1) {
      tft.fillRect(x2, y2, 20, 20,  RED);
    }
    if (screen[i] == 0) {
      tft.fillRect(x2, y2, 20, 20,  BLACK);
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(3000);
  randomSeed(analogRead(A7));
  tft.reset();
  Serial.println(tft.readID(), HEX);
  Serial.print(tft.width());
  Serial.print(tft.height());
  tft.begin(0x9320);
  tft.setRotation(1);
  tft.fillScreen(BLACK);
  tft.fillRect(10, 0, 5, 5, WHITE);  // x,y
  //tft.fillRect(0, 0, 30, 319, GREEN);
  //tft.setTextSize(2); tft.setCursor(50, tft.width() / 2); tft.setTextColor(WHITE);  //  5x5
  tft.fillRect(0, 0, 80, 240, BLUE);
  tft.fillRect(239, 0, 80, 239, BLUE);
  tft.fillRect(80 - 5, 0, 5, 239, YELLOW);
  tft.fillRect(240, 0, 5, 239, YELLOW);
  tft.fillRect(80 - 5, 235, 160, 5, YELLOW);
  tft.fillRect(255, 20, 50, 50, YELLOW); //up
  tft.fillRect(255, 170, 50, 50, YELLOW); //right
  tft.fillRect(15, 170, 50, 50, YELLOW); //left
  timer = millis();
  screen[y * 8 + x] = 1;
  toScreen();



}
void loop() {
  tp = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  pinMode(XP, OUTPUT);
  pinMode(YM, OUTPUT);
  if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE) {
    int posy = map(tp.x, 180, 900, 0, 239);
    int posx = map(tp.y, 960, 180, 0, 319);
  }

  if ((millis() - timer) > 500) {
    timer = millis();
    screen[y * 8 + x] = 0;
    y = y + 1;
    screen[y * 8 + x] = 1;
    Serial.println(1);
    toScreen();
    Serial.println(2);

    if (y == 10 || screen[(y + 1) * 8 + x]) {
      y = 0;
      x = random(0, 8);
      screen[y * 8 + x] = 1;
      toScreen();
    }
  }
}
