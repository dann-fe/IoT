#include "EEPROM.h"


#define check 111
byte brightness;
void setup() {
  Serial.begin(9600);
  delay(3000);    // EEPROM.write(address, value)     EEPROM.put(address, value)
  
  if(EEPROM.read(check)==255){
brightness = 120;
EEPROM.write(check, 0b01010101);


  
  {
  // new arduino
  }
  else {
  brightness = EEPROM.read(112);
  
  
  }


  
                     // old arduino
  
  Serial.println(EEPROM.read(101)); //check
  Serial.println(EEPROM.read(102)); //brightness

  Serial.println(EEPROM.read(brightness));

}

void loop() {
  // put your main code here, to run repeatedly:

}
