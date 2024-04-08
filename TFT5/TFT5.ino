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
int ID;
byte YP = A1;
byte XM = A2;
byte YM = 7;
byte  XP = 6;
MCUFRIEND_kbv tft;
int x = tft.height() / 2;
int y = 10;
int bulletx = x + 3;
int bullety = y + 20;
int enemyy = 160;
int enemyx = random(40, 280);
long timeenemy = 0;
long timebullet = 0;
long timeship = 0;
long timeenemycomesback = 0;
bool bulletstart = 0;
byte timeshipcounter = 0;
byte ship[99] = {
  0, 0, 1, 1, 1, 1, 1, 0, 0,
  1, 1, 2, 2, 2, 2, 2, 1, 1,
  1, 1, 2, 2, 2, 2, 2, 1, 1,
  1, 1, 1, 2, 2, 2, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 0, 0, 1, 1
};
byte bullet[30] = {
  0, 2, 2, 2, 0,
  2, 1, 1, 1, 2,
  2, 1, 1, 1, 2,
  2, 1, 1, 1, 2,
  2, 1, 1, 1, 2,
  0, 2, 2, 2, 0
};
byte meteorite[54] = {
  1, 0, 1, 1, 0, 1,
  1, 1, 1, 1, 1, 1, 
  0, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 0,
  0, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1,
  1, 0, 0, 0, 0, 0
};
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 500);
TSPoint tp;
void drawShip(bool color) {  //0-off-blue 1-on-yellow
  if (color == 0) {
    tft.fillRect(y, x, 11, 9, BLUE);
  }
  else {
    for (int i = 0; i < 99; ++i) {
      int x1 = i % 9;
      int y1 = i / 9;
      x1 = x1 + x;
      y1 = y1 + y;

      if (ship[i] == 1) {
        tft.drawPixel(y1, x1,  YELLOW);
      }
      if (ship[i] == 2) {
        tft.drawPixel(y1, x1, RED);
      }
      if (ship[i] == 0) {
        tft.drawPixel(y1, x1,  BLUE);
      }
    }
  }

}
void drawBullet(bool color) {
  if (color == 0) {
    tft.fillRect(bullety, bulletx, 6, 5, BLUE);
  }
  else {
    for (int i = 0; i < 30; ++i) {
      int x2 = i % 5;
      int y2 = i / 5;
      x2 = x2 + bulletx;
      y2 = y2 + bullety;
      if (bullet[i] == 1) {
        tft.drawPixel(y2, x2,  YELLOW);
      }
      if (bullet[i] == 2) {
        tft.drawPixel(y2, x2, MAGENTA);
      }
      if (bullet[i] == 0) {
        tft.drawPixel(y2, x2, BLUE);
      }
    }
  }
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(3000);
  tft.reset();
  Serial.println(tft.readID(), HEX);
  Serial.print(tft.width());
  Serial.print(tft.height());
  tft.begin(0x9320);
  tft.setRotation(0);
  tft.fillScreen(BLUE);
  tft.setTextSize(2); tft.setCursor(50, tft.width() / 2); tft.setTextColor(WHITE);  //  5x5
  //tft.fillRect(y, x, 15, 15, YELLOW);
  drawShip(1);
  delay(10000);

  tft.fillRect(190, 270, 50, 50, GREEN);
  tft.fillRect(190, 0, 50, 50, GREEN);
  tft.fillRect(190, 135, 50, 50, RED);
  tft.fillRect(enemyy, enemyx, 20, 20, MAGENTA);
  timeenemy = millis();
  timebullet = millis();
  timeship = millis();
  timeenemycomesback = millis();

}
void loop() {
  // put your main code here, to run repeatedly:
  tp = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  pinMode(XP, OUTPUT);
  pinMode(YM, OUTPUT);
  if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE) {  // z = pressure
    int x1 = map(tp.y, 910, 220, 0, 320);
    int y1 = map(tp.x, 910, 200, 0, 240);   //down 0-80     center 81 - 160    up 161 - 239

    if (x1 > 270 && x1 < 320 && y1 > 190 && y1 < 240) {
      drawShip(0);
      x = x + 15;
      drawShip(1);
      
    }
    if (x1 > 0 && x1 < 50 && y1 > 190 && y1 < 240) {
      drawShip(0);
      x = x - 15;
      drawShip(1);
      
    }
    /*if (x1 > 135 && x1 < 180 && y1 > 190 && y1 < 240) {
      bulletx = x + 3;
      bullety = y + 20;
      tft.fillRect(bullety, bulletx, 10, 10, BLACK);
      if (millis() - timebullet > 200) {
        timebullet = millis();
        tft.fillRect(bullety, bulletx, 10, 10, BLUE);
        bullety = bullety + 10;
        tft.fillRect(bullety, bulletx, 10, 10, BLACK);
      }
      tft.fillRect(190, 135, 50, 50, RED);
      }*/
    if (x1 > 135 && x1 < 180 && y1 > 190 && y1 < 240 && bulletstart == 0) {
      bulletx = x + 3;
      bullety = y + 20;
      bulletstart = 1;
      drawBullet(1);
    }
  }

  if ((millis() - timebullet) > 200 && bulletstart == 1) {
    timebullet = millis();
    drawBullet(0);
    bullety = bullety + 10;
    drawBullet(1);
    if (bullety == 180) {
      drawBullet(0);
      bulletstart = 0;

      tft.fillRect(190, 135, 50, 50, RED);
      tft.fillRect(190, 270, 50, 50, GREEN);
      tft.fillRect(190, 0, 50, 50, GREEN);
    }
  }

  if ((millis() - timeenemy) > 500) {
    timeenemy = millis();
    tft.fillRect(enemyy, enemyx, 20, 20, BLUE);
    enemyy = enemyy - 10;
    if (enemyy < 10) {
      enemyy = 160;
      enemyx = random(20, 300);
    }
    tft.fillRect(enemyy, enemyx, 20, 20, MAGENTA);
  }
  if (((enemyy - bullety) < 10) &&  ((enemyx - bulletx) < 10) && ((bulletx - enemyx) < 20)) {
    bulletstart = 0;
    tft.fillRect(enemyy, enemyx, 20, 20, BLUE);
    drawBullet(0);
    enemyy = 160;
    enemyx = random(20, 300);
  }
  if (((enemyy - y) < 10) &&  ((enemyx - x) < 5) && ((x - enemyx) < 20)) {
    tft.fillRect(enemyy, enemyx, 20, 20, BLUE);
    for (byte i = 0; i <= 3; i++) {
      tft.fillRect(y - 3, x - 3, 20, 20, YELLOW);
      delay(200);
      tft.fillRect(y - 3, x - 3, 20, 20, RED);
      delay(200);
    }
    tft.fillRect(y - 3, x - 3, 20, 20, BLUE);
    /*if ((millis() - timeship) > 50) {
      tft.fillRect(y, x, 15, 15, RED);
      timeshipcounter = timeshipcounter + 1;
      }*/
    enemyy = 160;
    enemyx = random(20, 300);

  }
  drawShip(1);
} // 320x240x3 byte
