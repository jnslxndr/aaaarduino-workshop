#include <Boards.h>
#include <Firmata.h>
#include <Grove_LED_Bar.h>

Grove_LED_Bar bar(9, 8, 0);

void analogWriteCallBack(byte channel, int value) {
  switch(channel) {
    case 0:
    bar.setLevel(map(value, 0, 255, 0, 10));
    break;
  }
}

void setup() {
  Firmata.setFirmwareVersion(FIRMATA_FIRMWARE_MAJOR_VERSION, FIRMATA_FIRMWARE_MINOR_VERSION);
  Firmata.attach(ANALOG_MESSAGE, analogWriteCallBack);
  Firmata.begin();
  
  pinMode(2, OUTPUT);
  bar.begin();
}

void loop() {

  int sensor = analogRead(0);

  Firmata.sendAnalog(0, sensor);

  while (Firmata.available()) {
    Firmata.processInput();
  }
}
