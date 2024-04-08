// hello!
#define led 13 
#define yellow 12
#define green 11
void setup() {

pinMode(led, OUTPUT);
pinMode(yellow, OUTPUT);
pinMode(green, OUTPUT);
}

void loop() {
digitalWrite(led, 1);
digitalWrite(yellow, 0);// HIGH, 1 , true
digitalWrite(green, 0);
delay(1000);
digitalWrite(led, 0);
digitalWrite(yellow, 1);
digitalWrite(green, 0);
delay(1000);  
digitalWrite(led, 0);
digitalWrite(yellow, 0);
digitalWrite(green, 1);
delay(1000);
}
