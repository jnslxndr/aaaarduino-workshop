void setup() {
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
}

void loop() {
  if ( Serial.available()) {
    int data = Serial.read();
    if (data == 0x01) {
      digitalWrite(2, HIGH);
    } else {
      digitalWrite(2, LOW);
    }
  }
  Serial.write(digitalRead(3));
}
