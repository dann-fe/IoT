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
int TS_LEFT = 940;
int TS_RIGHT  = 185;
int TS_TOP = 950;
int TS_BOT = 170;

int x = 50;
int y = 10;
int y2 = random(0,239+1);
int x2 = 300;

long timewhite;
long timewhite2;
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
  /*
        --------SQUARE-------

    tft.drawLine(50, 50, 100, 50, WHITE);
    tft.drawLine(100, 50, 100, 100, WHITE);
    tft.drawLine(100, 100, 50, 100, WHITE);
    tft.drawLine(50, 100, 50, 50, WHITE);

        --------TRIANGLE--------

    tft.drawLine(80, 195, 160, 195, WHITE);  // 80
    tft.drawLine(80, 195, 120, 126, WHITE);  // 69
    tft.drawLine(120, 126, 160, 195, WHITE);



    tft.fillRect(10, 10, 20, 20, CYAN);
    tft.drawCircle(tft.width()/2, tft.height()/2, 20, MAGENTA);
    tft.drawPixel(70, 140, BLUE);
  */
  tft.fillRect(y, x, 4, 4, WHITE);
  timewhite = millis();
  timewhite2 = millis();
}
void loop() {
  // put your main code here, to run repeatedly:
  /* tp = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    pinMode(XP, OUTPUT);
    pinMode(YM, OUTPUT);
    if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE) {  // z = pressure
     Serial.print("x=");
       Serial.println(tp.x); // down 930 up 280 (y0 y240)
       Serial.print("y=");
       Serial.println(tp.y); // left 950 down 220 (x0 x320)
       Serial.print("pressure=");
       Serial.println(tp.z);
     tft.fillRect(y, x, 4, 4, BLACK);

     x = map(tp.y, 910, 220, 0, 320);
     y = map(tp.x, 910, 200, 0, 240);
     Serial.print("x = "); Serial.print(tp.y); Serial.print(" "); Serial.println(x);
     Serial.print("y = "); Serial.print(tp.x); Serial.print(" "); Serial.println(y);
     //tft.drawPixel(y, x, WHITE);

     tft.fillRect(y, x, 4, 4, WHITE);

    }*/
  if ((millis() - timewhite) > 1000) {
    timewhite = millis();
    tft.fillRect(y, x, 4, 4, BLACK);
    y = y + 10;
    if (y >= 200) {
      y = 10;
    }
    tft.fillRect(y, x, 4, 4, WHITE);
  }
  if ((millis() - timewhite2) > 500) {
    timewhite2 = millis();
    tft.fillRect(y2, x2, 8, 8, BLACK);
    x2 = x2 - 10;
    if (x2 <= 10) {
      x2 = 300;
      y2 = random(0,239+1);
    }
    tft.fillRect(y2, x2, 8, 8, BLUE);
  }

  /* for (y = 10; y < 200; y = y + 10) {
     tft.fillRect(y, x, 4, 4, BLACK);
     tft.fillRect(y, x, 4, 4, WHITE);
     Serial.println(y);
     delay(1000);
    }

    for ( y = 200; y > 10; y = y - 10) {
     tft.fillRect(y, x, 4, 4, BLACK);
     tft.fillRect(y, x, 4, 4, WHITE);
     Serial.println(y);
     delay(1000);

    }

    for (x2 = 300; x2 > 10; x2 = x2-10) {
     tft.fillRect(y2, x2, 8, 8, BLACK);
     tft.fillRect(y2, x2, 8, 8, BLUE);
     Serial.println(x2);
     delay(500);
    }

    for ( x2 = 10; x2 < 300; x2 = x2 + 10) {
     tft.fillRect(y2, x2, 8, 8, BLACK);
     tft.fillRect(y2, x2, 8, 8, WHITE);
     Serial.println(x2);
     delay(500);

    }*/


}
