#include <CapacitiveSensor.h>

#include <Boards.h>
#include <Firmata.h>

CapacitiveSensor sensor = CapacitiveSensor(2,3);

int doReport = 0;
void onReportAnalog(byte pin, int state) {
  doReport = state;
}

void setup() {
  sensor.set_CS_AutocaL_Millis(0xFFFFFFFF);
  
  Firmata.attach(REPORT_ANALOG, onReportAnalog);
  Firmata.begin(57600);
}

void loop() {
  while(Firmata.available())
    Firmata.processInput();

  int sensorValue = sensor.capacitiveSensor(30);

  if (doReport)
    Firmata.sendAnalog(0, sensorValue );

}

