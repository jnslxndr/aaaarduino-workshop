#include <CapacitiveSensor.h>

#include <Boards.h>
#include <Firmata.h>


CapacitiveSensor sensor = CapacitiveSensor(2,3);

const int MINIMUM_SAMPLING_INTERVAL = 10;
int samplingInterval = MINIMUM_SAMPLING_INTERVAL;

void onSysEx(byte command, byte argc, byte *argv) {
  switch ( command ) {
  case SAMPLING_INTERVAL:
    // retrieve the sample rate
    if (argc > 1) {
      samplingInterval = argv[0] + (argv[1] << 7);
      if (samplingInterval < MINIMUM_SAMPLING_INTERVAL) 
        samplingInterval = MINIMUM_SAMPLING_INTERVAL;
      }
      break;
  }
}

int doReport = 0;
void onReportAnalog(byte pin, int state) {
  doReport = state;
}


void setup() {
  sensor.set_CS_AutocaL_Millis(0xFFFFFFFF);
  
  Firmata.attach(REPORT_ANALOG, onReportAnalog);
  Firmata.attach(START_SYSEX, onSysEx);
  Firmata.begin(57600);
}

void loop() {
  while(Firmata.available())
    Firmata.processInput();

  int sensorValue = sensor.capacitiveSensor(30);

  if (doReport) {
    Firmata.sendAnalog(0, sensorValue );
  }
  
  delay(samplingInterval);
}

