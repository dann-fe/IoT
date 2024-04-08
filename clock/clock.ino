
#include <RichShieldDHT.h>
#include <Wire.h>
#include <RichShieldTM1637.h>
#include <RTClib.h>
#define CLK 10
#define DIO 11
#define button 9
#define button2 8
TM1637 disp(CLK,DIO);
RTC_DS1307 watch;
void setup() {

watch.begin();
//watch.adjust(DateTime(F(__DATE__), F(__TIME__))); 
Serial.begin(9600);
delay(3000);

}

void loop() {
  delay(1000);
  DateTime now = watch.now();
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
