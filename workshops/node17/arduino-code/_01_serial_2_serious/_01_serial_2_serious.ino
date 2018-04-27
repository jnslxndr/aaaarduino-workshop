#include <Boards.h>
#include <Firmata.h>

void setup() {
  Firmata.begin();
}

void loop() {
  Firmata.sendAnalog(0,analogRead(0));
}
