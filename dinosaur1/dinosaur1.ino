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
MCUFRIEND_kbv tft;
byte dinostart = 0; // 0 = stop 1 = move 2- down
int dinox = 20;
int dinoy = 30;
long dinotime;
int cactusx = 280;
int cactusy = 30;
long cactustime;
int birdx = 270;
int birdy = 100;
long birdtime;
byte dino[200] = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,

};
byte dinoanimation[200] = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};
byte dinoanimation2[200] = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};
byte cactus[200] = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};
byte bird[200] = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 500);
TSPoint tp;

void drawDino(bool color) {  //0-off-blue 1-on-yellow
  if (color == 0) {
    tft.fillRect(dinoy, dinox, 20, 10, BLUE);
  }
  else {
    for (int i = 0; i < 200; ++i) {
      int x1 = i % 10;
      int y1 = i / 10;
      x1 = x1 + dinox;
      y1 = y1 + dinoy;

      if (dino[i] == 1) {
        tft.drawPixel(y1, x1,  YELLOW);
      }
      if (dino[i] == 0) {
        tft.drawPixel(y1, x1,  BLUE);
      }
    }
  }

}
void drawDinoanimation(bool color) {  //0-off-blue 1-on-yellow
  if (color == 0) {
    tft.fillRect(dinoy, dinox, 20, 10, BLUE);
  }
  else {
    for (int i = 0; i < 200; ++i) {
      int x1 = i % 10;
      int y1 = i / 10;
      x1 = x1 + dinox;
      y1 = y1 + dinoy;

      if (dino[i] == 1) {
        tft.drawPixel(y1, x1,  BLACK);
      }
      if (dino[i] == 0) {
        tft.drawPixel(y1, x1,  BLUE);
      }
    }
  }

}
void drawDinoanimation2(bool color) {  //0-off-blue 1-on-yellow
  if (color == 0) {
    tft.fillRect(dinoy, dinox, 20, 10, BLUE);
  }
  else {
    for (int i = 0; i < 200; ++i) {
      int x1 = i % 10;
      int y1 = i / 10;
      x1 = x1 + dinox;
      y1 = y1 + dinoy;

      if (dino[i] == 1) {
        tft.drawPixel(y1, x1,  WHITE);
      }
      if (dino[i] == 0) {
        tft.drawPixel(y1, x1,  BLUE);
      }
    }
  }

}
void drawCactus(bool color) {
  if (color == 0) {
    tft.fillRect(cactusy, cactusx, 20, 10, BLUE);
  }
  else {
    for (int i = 0; i < 200; ++i) {
      int x1 = i % 10;
      int y1 = i / 10;
      x1 = x1 + cactusx;
      y1 = y1 + cactusy;
      if (cactus[i] == 1) {
        tft.drawPixel(y1, x1,  ORANGE);
      }
      if (cactus[i] == 0) {
        tft.drawPixel(y1, x1,  BLUE);
      }
    }
  }
}
void drawBird(bool color) {
  if (color == 0) {
    tft.fillRect(birdy, birdx, 10, 20, BLUE);
  }
  else {
    for (int i = 0; i < 200; ++i) {
      int x1 = i % 20;
      int y1 = i / 20;
      x1 = x1 + birdx;
      y1 = y1 + birdy;
      if (bird[i] == 1) {
        tft.drawPixel(y1, x1,  BROWN);
      }
      if (bird[i] == 0) {
        tft.drawPixel(y1, x1,  BLUE);
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
  tft.fillRect(0, 0, 30, 319, GREEN);
  tft.setTextSize(2); tft.setCursor(50, tft.width() / 2); tft.setTextColor(WHITE);  //  5x5
  delay(1000);
  dinotime = millis();
  cactustime = millis();
  birdtime = millis();
  drawDino(1);
  drawCactus(1);
  drawBird(1);

}
void loop() {
  tp = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  pinMode(XP, OUTPUT);
  pinMode(YM, OUTPUT);
  if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE && dinostart == 0) {
    dinostart = 1;
    dinotime = millis();
  }
  if (dinostart == 1 && (millis() - dinotime) > 50) {
    dinotime = millis();
    drawDino(0);
    dinoy = dinoy + 10;
    if (dinoy > 100) {
      drawDino(0);
      dinostart = 2;

    }
    drawDino(1);
  }

  if (dinostart == 2 && (millis() - dinotime) > 50) {
    dinotime = millis();
    drawDino(0);
    dinoy = dinoy - 10;
    if (dinoy < 30) {
      drawDino(0);
      dinoy = 30;
      dinox = 20;
      dinostart = 0;
    }
    drawDino(1);
    tft.fillRect(0, 0, 30, 319, GREEN);
  }
  if ((millis() - birdtime) > 330) {
    birdtime = millis();
    drawBird (0);
    birdx = birdx - 10;
    if (birdx < - 10) {
      birdx = 270;
      birdy = 100;
    }
    drawBird(1);
  }
  if ((millis() - cactustime) > 400) {
    cactustime = millis();
    drawCactus (0);
    cactusx = cactusx - 10;
    if (cactusx < - 10) {
      cactusx = 280;
      cactusy = 30;
    }
    drawCactus(1);
  }
  if ((cactusx - dinox) < 5 && (dinox - cactusx) < 5 && (dinoy - cactusy) < 10) {
    drawDino(0);
    delay(300);
    for (int i = 0; i < 5; i++) {
      drawDinoanimation(1);
      delay(150);
      drawDinoanimation2(1);
      delay(150);
    }
    tft.fillScreen(BLACK);
    tft.setRotation(1);
    tft.setTextSize(2); tft.setCursor(140, 115); tft.setTextColor(WHITE,BLACK);  //  5x5
   
    tft.print("GAME OVER");
    while(true) {
      
    }
  }
  if ((birdy - dinoy) < 5 && (dinoy - birdy) < 10 && (dinox - birdx) < 10 && (birdx - dinox) < 5) {
    drawDino(0);
    delay(300);
    for (int i = 0; i < 5; i++) {
      drawDinoanimation(1);
      delay(150);
      drawDinoanimation2(1);
      delay(150);
    }
    tft.fillScreen(BLACK);
    tft.setRotation(1);
    tft.setTextSize(2); tft.setCursor(140, 115); tft.setTextColor(WHITE,BLACK);  //  5x5
   
    tft.print("GAME OVER");
    while(true) {
      
    }
  }
}
/*

    tp = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    pinMode(XP, OUTPUT);
    pinMode(YM, OUTPUT);
    if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE) {  // z = pressure
     int x1 = map(tp.y, 910, 220, 0, 320);
     int y1 = map(tp.x, 910, 200, 0, 240);   //down 0-80     center 81 - 160    up 161 - 239

     if (x1 > 0 && x1 < 320 && y1 > 0 && y < 240) {
       drawShip(0);
       x = x + 15;
       drawShip(1);

     }
     if (x1 > 0 && x1 < 50 && y1 > 190 && y1 < 240) {
       drawShip(0);
       x = x - 15;
       drawShip(1);

     }
     if (x1 > 135 && x1 < 180 && y1 > 190 && y1 < 240) {
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
       }
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
     drawMeteorite(0);
     enemyy = enemyy - 10;
     if (enemyy < 10) {
       enemyy = 160;
       enemyx = random(20, 300);
     }
     drawMeteorite(1);
    }
    if (((enemyy - bullety) < 10) &&  ((enemyx - bulletx) < 10) && ((bulletx - enemyx) < 20)){
     bulletstart = 0;
     drawMeteorite(0);
     drawBullet(0);
     enemyy = 160;
     enemyx = random(20, 300);
    }
    if (((enemyy - y) < 10) &&  ((enemyx - x) < 5) && ((x - enemyx) < 20)) {
     drawMeteorite(0);
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
       }
     enemyy = 160;
     enemyx = random(20, 300);
*/
