#include <Arduino.h>
#include "APDS9151.h"
void setup() {
  Serial.begin(115200);
  initalize();
  delay(5000);
  ESP_ERROR_CHECK(write_register(registers::__MAIN_CTRL_ADDR, data_main_ctrl::__LS_EN | data_main_ctrl::__PS_EN | data_main_ctrl::__RGB_MODE));
  Serial.print("Main ctrl: ");
  Serial.println(get_main_ctrl());
}

void loop() {
  Serial.print("LS Green color: ");
  Serial.println(get_ls_data_green());
}