#include <Arduino.h>
#include "APDS9151.h"
void setup() {
  Serial.begin(115200);
  ESP_ERROR_CHECK(initializeI2CMaster());
  ESP_ERROR_CHECK(initializeI2CSlave());
}

void loop() {
  uint8_t * data = readDataOfSlave();
  Serial.println(*(data));
}