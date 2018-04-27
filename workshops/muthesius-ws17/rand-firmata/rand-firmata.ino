#include <Boards.h>
#include <Firmata.h>

/*
 * Random Number Generator for Firmata
 */

void setup() {
  Firmata.begin(57600);
}

void loop() {
  int value = analogRead(0);
  int value2 = random(1023);

  Firmata.sendAnalog(0, value);
  Firmata.sendAnalog(1, value2);
  
}


