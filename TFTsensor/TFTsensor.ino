#include <TouchScreen.h>
#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>

#define MINPRESSURE 20;
#define MAXPRESSURE 1000;

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
int ID;
byte YP = A1;  // 0...1023
byte XM = A2;
byte YM = 7;
byte XP = 6;

int TS_LEFT = 940;     //1023
int TS_RIGHT  = 185;  //0
int TS_TOP = 950;
int TS_BOTTOM = 170;
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 500);
TSPoint tp;
MCUFRIEND_kbv tft; //name of display

void setup() {
  Serial.begin(9600);
  delay(3000);
  tft.reset();
  Serial.println(tft.readID(), HEX);
  Serial.print(tft.width());
  Serial.print(tft.height());
  tft.begin(0x9320);
  tft.setRotation(0);
  tft.fillScreen(BLACK);
  //tft.setTextSize(2); tft.setCursor(50, tft.width()/2); tft.setTextColor(YELLOW);
  //tft.println("Hello World!");

  /*        --------SQUARE-------

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
}

void loop() {
  tp = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  pinMode(XP, OUTPUT);
  pinMode(YM, OUTPUT);
  if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE) {  
    Serial.println(tp.x);
    Serial.println(tp.y);
    Serial.println(tp.z);
    
  }

}
