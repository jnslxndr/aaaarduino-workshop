#include <CapacitiveSensor.h>

#include <Boards.h>
#include <Firmata.h>

CapacitiveSensor sensor = CapacitiveSensor(2,3);

void setup() {
  sensor.set_CS_AutocaL_Millis(0xFFFFFFFF);
  
  Firmata.begin(57600);
}

void loop() {
  int sensorValue = sensor.capacitiveSensor(30);

  if (doReport) {
    Firmata.sendAnalog(0, sensorValue );
  }
}

