#include <Boards.h>
#include <Firmata.h>

void digitalWriteCallback(byte port, int value) {
  digitalWrite(2, value);
}

void setup() {
  Firmata.setFirmwareVersion(FIRMATA_FIRMWARE_MAJOR_VERSION, FIRMATA_FIRMWARE_MINOR_VERSION);
  Firmata.attach(DIGITAL_MESSAGE, digitalWriteCallback);
  Firmata.begin();
  
  pinMode(2, OUTPUT);
}

void loop() {

  int sensor = analogRead(0);

  Firmata.sendAnalog(0, sensor);

  while (Firmata.available()) {
    Firmata.processInput();
  }
}
