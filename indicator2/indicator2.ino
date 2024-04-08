#include <RichShieldDHT.h>
#include <Wire.h>
#include <RichShieldTM1637.h>

#define CLK 10
#define DIO 11
//#define pot A0
#define button 9
#define sensor A2
DHT dht;
TM1637 disp(CLK,DIO);
void setup() {

 //pinMode(pot, INPUT);
 pinMode(button, INPUT);
 pinMode(sensor, INPUT);
 disp.init();
 dht.begin();
  
}

void loop() {
  //disp.display(digitalRead(button));
  //disp.display(dht.readTemperature());
  disp.display(analogRead(sensor));

}
