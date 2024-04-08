#include <NewPing.h>
#define echo 13
#define trig 12
#define vcc 11

#define gnd1 2
#define trig1 4
#define vcc1 5
#define echo1 3
NewPing sonar(trig, echo, 200);
NewPing sonar1(trig1, echo1, 200);
void setup() {
Serial.begin(9600);
delay(3000);
pinMode(vcc, OUTPUT);
digitalWrite(vcc, 1);
pinMode(vcc1, OUTPUT);
digitalWrite(vcc1, 1);
pinMode(gnd1, OUTPUT);
digitalWrite(gnd1, 0);
}

void loop() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping1: ");
  Serial.print(sonar1.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");

}
