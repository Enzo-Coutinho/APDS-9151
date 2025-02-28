#include <Arduino.h>
#include "APDS9151.h"
void setup() {
  Serial.begin(115200);
  initalize();
  delay(200);
  ESP_ERROR_CHECK(write_register(registers::__MAIN_CTRL_ADDR, data_main_ctrl::__LS_EN | data_main_ctrl::__PS_EN | data_main_ctrl::__RGB_MODE));
}

void loop() {
  uint32_t green = getLsDataGreen();
  uint32_t red = getLsDataRed();
  uint32_t blue = getLsDataBlue();
  if(green > 2500)
  {
    Serial.printf("Verde!!! \n");
  } else if(blue > 2500)
  {
    Serial.printf("Azul!!! \n");
  } else if(red > 2500)
  {
    Serial.printf("Vermelho!!! \n");
  } else {
    Serial.printf("Nenhuma!!! \n");
  }
  delay(200);
}