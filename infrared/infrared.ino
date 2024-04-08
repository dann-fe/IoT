#include <IRremote.h>
#define ir 2
#define red 4
#define blue 6
IRrecv irrecv(ir);
decode_results results;
void setup() {
  Serial.begin(9600);
  delay(3000);
  irrecv.enableIRIn();
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);

}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    if (results.value == 551494365)   digitalWrite(red, 1);
    if (results.value == 551494365)   digitalWrite(red, 0);
    if (results.value == 2155845735)   digitalWrite(blue, 1);
    if (results.value == 2155845735)   digitalWrite(blue, 0);

    irrecv.resume(); // Receive the next value
    delay(100);
    
  }
}
