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
byte points = 0;
byte dir = 0; // 0 - stop no movement 1 - left 2 -right
MCUFRIEND_kbv tft;

byte screen[88] = {
  0, 0, 0, 0, 0, 0, 0, 0,  // 0 - 7
  0, 0, 0, 0, 0, 0, 0, 0,  // 8 - 15
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,  // 1 - bottom line - 1
  0, 0, 0, 0, 0, 0, 0, 0,  // 2 - move all down 
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,  // 72 - 79
  0, 0, 0, 0, 0, 0, 0, 0   // 80 - 87

};
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 500);
TSPoint tp;

void check() {
  int count = 0;
  for (int i = 80; i <= 87; ++i ) {
    count = count + screen[i];
  }
  if (count == 8) {
    for (int i = 79; i >= 0; --i) {
      screen[i + 8] = screen[i];
    }
    points = points + 1;
    Serial.println(points);
  }
}


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


void fall() {
  while (y < 10 && screen[(y + 1) * 8 + x] == 0) {
    screen[y * 8 + x] = 0;
    y = y + 1;
    screen[y * 8 + x] = 1;
    toScreen();
    delay(50);

  }
  check();
  y = 0;
  x = random(0, 8);
  if (screen[y * 8 + x] == 1) {
    while (true) {
      screen[y * 8 + x] == 1;
      delay(50);
      screen[y * 8 + x] == 0;
      delay(50);
    }
  }
  screen[y * 8 + x] = 1;
  toScreen();
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
  tft.fillRect(255, 20, 50, 50, YELLOW); //doewn
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
    if ((posx > 14 && posx < 75) && (posy > 169 && posy < 219)) {
      //    x = x - 1;
      dir = 1;
    }
    if ((posx > 254 && posx < 305) && (posy > 169 && posy < 220)) {
      //    x = x + 1;
      dir = 2;
    }
    if ((posx > 254 && posx < 305) && (posy > 19 && posy < 70)) {
      fall();
    }
  }

  if ((millis() - timer) > 500) {
    timer = millis();
    screen[y * 8 + x] = 0;
    if ((dir == 1) && (x > 0) && (screen[y * 8 - 1 + x] == 0)) {
      x = x - 1;
    }
    if ((dir == 2) && (x < 7) && (screen[y * 8 + 1 + x] == 0)) {
      x = x + 1;
    }
    dir = 0;
    y = y + 1;
    
    screen[y * 8 + x] = 1;   
    toScreen();
    if (y == 10 || screen[(y + 1) * 8 + x] == 1) {
      check();
      y = 0;
      x = random(0, 8);
      if (screen[y * 8 + x] == 1) {
        while (true) {
          screen[y * 8 + x] == 1;
          delay(50);
          screen[y * 8 + x] == 0;
          delay(50);
        }
      }
      screen[y * 8 + x] = 1;
      toScreen();
    }
  }
}
