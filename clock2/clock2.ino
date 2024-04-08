#include <RTClib.h>
#include <Wire.h>
#include <RichShieldTM1637.h>


#define CLK 10
#define DIO 11
#define button 9
#define button1 8
#define buzzer 3

// 20-00
byte alarmhour = 20;
byte alarmminute = 03;

bool stat = 0;  //0=min.sec 1=hour.min

TM1637 disp(CLK, DIO);

RTC_DS1307 watch;
void setup() {
  watch.begin();
  watch.adjust(DateTime(2023, 10, 7, 1, 0, 0));
  Serial.begin(9600);
  delay(3000);
  disp.init();
  pinMode(button, INPUT_PULLUP);
  pinMode(button1, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  DateTime now = watch.now();

  float min1 = now.minute();
  min1 = min1 / 100;
  float hour1 = now.hour();
  float t = (min1 + hour1);
  disp.display(t);

  delay(5000);

}

void loop() {
  delay(1000);
  DateTime now = watch.now();
  float min1 = now.minute();
  min1 = min1 / 100;
  float hour1 = now.hour();
  float t = (min1 + hour1);

  float sec1 = now.second();
  sec1 = sec1 / 100;
  float min2 = now.minute();
  float t2 = (sec1 + min2);

  if (digitalRead(button1) == 0) {
    stat = 0;
    Serial.println(stat);
  }
  if (digitalRead(button) == 0) {
    stat = 1;
    Serial.println(stat);
  }
  if (stat == 0) {
    disp.display(t2);
  }
  else {
    disp.display(t);
  }

  if((now.hour() == alarmhour) && (now.minute() == alarmminute)) {
      analogWrite(buzzer, 500);
  }
  Serial.println(min1);
  Serial.println(hour1);
  Serial.println(t);
  Serial.print(now.year());
  Serial.print(":");
  Serial.print(now.day());
  Serial.print(":");
  Serial.println(now.month());
  Serial.print(now.hour());
  Serial.print(":");
  Serial.print(now.minute());
  Serial.print(":");
  Serial.println(now.second());
}
