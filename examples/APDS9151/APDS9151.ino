#include <Arduino.h>
#include "color_sensor/ColorSensor.hpp"

void setup() {
  Serial.begin(115200);
  initialize();

  setMainCtrl(false, false, false, true, true, true);
  setPsLedConfigure(PS_FREQUENCY::__FREQ_60K, PS_CURRENT::__PULSE_CURRENT_100MA);
  setPsMeasRateConfigure(PS_RESOLUTION::__PS_RESOLUTION_8bit, PS_MEASUREMENT_RATE::__PS_MEASUREMENT_RATE_100ms);
  setLsMeasRateConfigure(LS_RESOLUTION::__LS_RESOLUTION_18bit, LS_MEASUREMENT_RATE::__LS_MEASUREMENT_RATE_100ms);
  setLsGainConfigure(GAIN::__GAIN_3);

  Serial.printf("Main Ctrl: %d\n", getMainCtrlConfigure());
  Serial.printf("Part ID: %d\n", getPartID());

}

void loop() {
  int colorGreen = getLsDataGreen();
  int colorBlue = getLsDataBlue();
  int colorRed = getLsDataRed();
  int ir = getLsDataIR();
  int ps = getPsData();

  Serial.printf("R: %d\n", colorRed);
  Serial.printf("G: %d\n", colorGreen);
  Serial.printf("B: %d\n", colorBlue);
  Serial.printf("IR: %d\n", ir);
  Serial.printf("PS: %d\n", ps);
  delay(200);
}