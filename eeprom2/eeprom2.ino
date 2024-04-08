#include "EEPROM.h"   // 512 0...511

#define but 13
#define pot A2
#define led 9

void setup() {
  int brightness = 0;
  Serial.begin(9600);
  delay(3000);    // EEPROM.write(address, value)     EEPROM.put(address, value)
  pinMode(but, INPUT);
  pinMode(pot, INPUT);
  pinMode(led, OUTPUT);
}
void loop() {
  int brightness = analogRead(pot); //0...1023   0....255
  Serial.println(brightness);

  analogWrite(led, brightness / 4);

  if (digitalRead(but) == 0) {
    //EEPROM.put(0, brightness);
    Serial.println(EEPROM.get(0, brightness));
    delay(1000);
  }

}
