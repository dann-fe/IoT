byte count = 0h0FF;
void setup() {
  Serial.begin(9600);
  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(count,DEC);
  Serial.println(count,BIN);
  Serial.println(count,HEX);
  delay(1000);
}
