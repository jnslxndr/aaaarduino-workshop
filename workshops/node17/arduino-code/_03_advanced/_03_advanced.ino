#include <Boards.h>
#include <Firmata.h>
#include <FirmataConstants.h>
#include <FirmataDefines.h>
#include <FirmataMarshaller.h>
#include <FirmataParser.h>

void setup() {
  Firmata.setFirmwareNameAndVersion("Simple Analog Reporter", 1, 0);
  Firmata.begin();
  Firmata.write(START_SYSEX);
  Firmata.write(CAPABILITY_RESPONSE);
  Firmata.write(PIN_MODE_ANALOG);
  Firmata.write(10); // 10 = 10-bit resolution
  Firmata.write(0x7F);
  Firmata.endSysex();
}

void loop() {
  //Firmata.sendString("Hello World");
  Firmata.sendAnalog(0, analogRead(0));
  delay(10);
}
