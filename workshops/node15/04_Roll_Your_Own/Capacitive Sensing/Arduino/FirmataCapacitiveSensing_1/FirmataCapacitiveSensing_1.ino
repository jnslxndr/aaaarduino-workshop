#include <CapacitiveSensor.h>

#include <Boards.h>
#include <Firmata.h>

CapacitiveSensor sensor = CapacitiveSensor(2,3);

int test = 0;
String s = "";

void setup() {  
  Firmata.begin(57600);
}

void loop() {
  
  int sensorValue = sensor.capacitiveSensor(30);

  Firmata.sendAnalog(0, sensorValue);
  
}

