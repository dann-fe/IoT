#include "EEPROM.h"   // 512 0...511

#define check 10
#define pot A3
#define led 9
#define but 13
void setup() {
  Serial.begin(9600);
  delay(3000);    // EEPROM.write(address, value)     EEPROM.put(address, value)

  //for(int i2=0; i2<10; i2++) {
  //  EEPROM.write(i2, 255);
  //}



  for (int i=0; i<11; i++) {
    Serial.println(EEPROM.read(i));
  }
  if (EEPROM.read(10) != 55) {
      EEPROM.write(10, 55);

    // new controler
  }

    // old controller

}

void loop() {
  // put your main code here, to run repeatedly:

}
