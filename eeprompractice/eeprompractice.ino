#include <EEPROM.h>
byte two30 = 230;
int five00 = 500;
long five4000 = 54000;
byte two30_2 = 230;
long two00000 = 200000;
byte one00 = 100;
bool one = 1;
void setup() {
  Serial.begin(960);
  delay(3000);
  EEPROM.write(0, two30);
  EEPROM.put(1, five00);
  EEPROM.put(3, five4000);
  EEPROM.write(7, two30_2);
  EEPROM.put(8, two00000);
  EEPROM.write(12, one00);
  EEPROM.write(13, one);
  /*----------------------------------------------*/
  Serial.println(EEPROM.read(0, two30));
  Serial.println(EEPROM.get(1, five00));
  Serial.println(EEPROM.get(3, five4000));
  Serial.println(EEPROM.read(7, two30_2));
  Serial.println(EEPROM.get(8, two00000));
  Serial.println(EEPROM.read(12, one00));
  Serial.println(EEPROM.read(13, one));
}


void loop() {
  // put your main code here, to run repeatedly:

}
