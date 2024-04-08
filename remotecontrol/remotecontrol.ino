#include <IRremote.h>

#define ir 2
#define red 4
#define yellow 7
#define blue 6
IRrecv irrecv(ir);
decode_results results;
void setup() {
  Serial.begin(9600);
  delay(3000);
  irrecv.enableIRIn();
  pinMode (red, OUTPUT);
  pinMode (blue, OUTPUT);
  pinMode (yellow, OUTPUT);

}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    if (results.value == 2155829415) {
      digitalWrite(yellow, !digitalRead(yellow));
    }

    if (results.value == 2155829925) {
      digitalWrite(blue, !digitalRead(blue));
    }
    irrecv.resume(); // Receive the next value
    delay(100);
  }
}
