#define led 9
#define led2 10
#define led3 8
#define buzzer 6
long count = 0;
long count2 = 0;
long count3 = 0;
long count4 = 0;
boolean stat4 = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  count = millis();
  count2 = millis();
  count3 = millis();
  count4 = millis();
}

void loop() {
  if ((millis() - count) > 500) {
    digitalWrite(led, !digitalRead(led));
    count = millis();
  }
  if ((millis() - count2) > 2000) {
    digitalWrite(led2, !digitalRead(led2));
    count2 = millis();
  }
  if ((millis() - count3) > 100) {
    digitalWrite(led3, !digitalRead(led3));
    count3 = millis();
  }
  if ((millis() - count4) > 500) {
    if (stat4 == true)  tone(buzzer, 540);
    else noTone(buzzer);
    stat4 =!stat4;
    count4 = millis();
  }
}
