#include <Arduino.h>
#include "APDS9151.h"
void setup() {
  Serial.begin(115200);
  initalize();
  delay(200);
  ESP_ERROR_CHECK(write_register(registers::__MAIN_CTRL_ADDR, data_main_ctrl::__LS_EN | data_main_ctrl::__PS_EN | data_main_ctrl::__RGB_MODE));
  Serial.print("Main ctrl: ");
  Serial.println(get_main_ctrl());
}

void loop() {
  Serial.printf("Green: %d \n", get_ls_data_green());
  Serial.printf("Red: %d \n", get_ls_data_red());
  Serial.printf("Blue: %d \n", get_ls_data_blue());
  Serial.printf("Ir: %d \n", get_ls_data_ir());
  delay(200);
}