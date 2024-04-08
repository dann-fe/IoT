#define buzzer 8
#define button 12
#define button2 2
void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT);
  pinMode(button2, INPUT);

}

void loop() {
  if (digitalRead(button) == 0) {
    tone(buzzer, 523);
    delay(500);

    tone(buzzer, 587);
    delay(500);

    tone(buzzer, 659);
    delay(500);

    tone(buzzer, 698);
    delay(500);

    tone(buzzer, 783);
    delay(500);

    tone(buzzer, 880);
    delay(500);

    tone(buzzer, 987);
    delay(500);
    noTone(buzzer);

  }


  if (digitalRead(button2) == 0) {
    tone(buzzer, 987);
    delay(500);

    tone(buzzer, 880);
    delay(500);

    tone(buzzer, 783);
    delay(500);

    tone(buzzer, 698);
    delay(500);

    tone(buzzer, 659);
    delay(500);

    tone(buzzer, 587);
    delay(500);

    tone(buzzer, 523);
    delay(500);
    noTone(buzzer);

  }
  

}
