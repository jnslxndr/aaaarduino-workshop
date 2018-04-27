/*
 * Random Number Generator for Serial
 */

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(0);
  int value2 = random(1023);
  Serial.print(value);
  Serial.print(":");
  Serial.println(value2);
}
