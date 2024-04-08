#include <EEPROM.h>


#define led 11
#define led2 9
int count = 12300;  // 2 byte
int count1;
long count2;
void setup() {
  Serial.begin(9600); 
  delay(3000);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT); 
  //EEPROM.write(0,20);   // 0...512  1 byte
  //EEPROM.write(1,255);   // 0...512
  //EEPROM.write(2, 10);
  EEPROM.put(3,count);
  Serial.println(EEPROM.read(0));
  Serial.println(EEPROM.read(1));
  Serial.println(EEPROM.read(2));
  Serial.println(EEPROM.read(3));
  EEPROM.get(4, count1);
  EEPROM.get(6, count2);
  EEPROM.get(10, count3);
  
  Serial.println(count1);
  //Serial.println(EEPROM.read(4));
  
}

void loop() {
  analogWrite(led, EEPROM.read(0));
  analogWrite(led2, EEPROM.read(2));
  delay(300);
  analogWrite(led, 0);
  analogWrite(led2, 0);
  delay(300);
  
}
