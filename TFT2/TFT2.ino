#include <EEPROM.h>
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
int dir = 0;  //0=stop  1=up  -1=down

byte bullet = 0; //0=stop 1=bullet 1 2=bullet 2
int bulletx;
int bullety;
int bullet2x;
int bullet2y;
int x = 50;  // up
int y = 10;
int y2 = random(0, 239 + 1); // left
int x2 = 300;
int x1;  // sensor
int y1;
long timewhite;
long timewhite2;
long timewhite3;
long timewhite4;
MCUFRIEND_kbv tft;
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 500);
TSPoint tp;

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
  tft.fillScreen(BLACK);
  tft.setTextSize(2); tft.setCursor(50, tft.width() / 2); tft.setTextColor(WHITE);
  //tft.fillRect(y, x, 7, 7, WHITE);
  //tft.drawPixel(y,x,RED);
  delay(10000);
  timewhite = millis();
  timewhite2 = millis();
  timewhite3 = millis();
  timewhite4 = millis();
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("bulletx ");
  Serial.println(bulletx);
  Serial.print("x1 ");
  Serial.println(x1);
  tp = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  pinMode(XP, OUTPUT);
  pinMode(YM, OUTPUT);
  if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE) {  // z = pressure
    tft.fillRect(y1, x1, 4, 4, BLACK);
    x1 = map(tp.y, 910, 220, 0, 320);
    y1 = map(tp.x, 910, 200, 0, 240);   //down 0-80     center 81 - 160    up 161 - 239
    if (y1 <= 80 && x1 <= 150) {
      dir = -1;
    }
    if (y1 >= 161 && x1 <= 150) {
      dir = 1;
    }
    if (y1 >= 81 && y1 <= 160 && x1 <= 150) {
      dir = 0;
    }
    if (bullet == 0 && x1 > 150) {
      bullet = 1; //   byte - 0 1 2
      bulletx = x + 15;
      bullety = y;
      if (bullet == 2) {
       // Serial.println(bullet);
        //bullet = 2;
        bullet2x = x + 15;
        bullet2y = y;
      }
    }
    //Serial.println(dir);
    
  }
  if (bullet == 1 && (millis() - timewhite3) > 500) {
    timewhite3 = millis();
    tft.fillRect(bullety, bulletx, 7, 7, BLACK);
    bulletx = bulletx + 15;
    tft.fillRect(bullety, bulletx, 7, 7, CYAN);
    if (bulletx == 320) {
      tft.fillRect(bullety, bulletx, 7, 7, BLACK);
      bullet = 2;
      x1 = 0;
      Serial.print("bullet: ");
      Serial.println(bullet);

    }
  }
  if (bullet == 2 && (millis() - timewhite4) > 500 && x1 > 150) {
    timewhite4 = millis();
    tft.fillRect(bullet2y, bullet2x, 7,7, BLACK);
    bullet2x = bullet2x + 15;
    tft.fillRect(bullet2y, bullet2x, 7,7, CYAN);
    if (bullet2x >= 320) {
      tft.fillRect(bullet2y, bullet2x, 7, 7, BLACK);
      
    }
  }
  if ((millis() - timewhite) > 1000) {
    timewhite = millis();
    tft.fillRect(y, x, 3, 3, BLACK);
    y = y + (10*dir);
    
    if (y >= 200  || y <= 10 ) {
      dir = 0;
    }
    tft.fillRect(y, x, 3, 3, WHITE);
    if (x >= x2 && x <= (x2+3) && y >= (y2-3) && y <= y2) {
      tft.fillRect(y, x, 3, 3, RED);  
      delay(3000);
    }
  }
  if ((millis() - timewhite2) > 500) {
    timewhite2 = millis();
    tft.fillRect(y2, x2, 7, 7, BLACK);
    x2 = x2 - 10;
    if (x2 <= 10) {
      x2 = 300;
      y2 = random(10, 239 - 10);
    }
    tft.fillRect(y2, x2, 7, 7, BLUE);
  }
  }
