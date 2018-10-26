void setup() {
  pinMode(9, OUTPUT);
}

void loop() {
  int x = analogRead(2);
  digitalWrite(9, HIGH);
  delayMicroseconds(1000);
  digitalWrite(9, LOW);
  delay(x * 2);
  

}
