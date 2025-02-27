#include <Arduino.h>
#include "APDS9151.h"
void setup() {
  Serial.begin(115200);
  initalize();
  //uint8_t initial_configure[2] = {registers::__MAIN_CTRL_ADDR, data_main_ctrl::__SW_RESET};
  /*
  uint8_t pro_configure[2] = {registers::__MAIN_CTRL_ADDR, data_main_ctrl::__RGB_MODE | data_main_ctrl::__LS_EN | data_main_ctrl::__PS_EN};
  ESP_ERROR_CHECK(writeRegister(initial_configure[0], initial_configure[1]));
  ESP_ERROR_CHECK(writeRegister(pro_configure[0], pro_configure[1]));
  ESP_ERROR_CHECK(writeRegister(registers::__LS_MEAS_RATE_ADDR, __LS_RESOLUTION_17bit | __LS_MEASUREMENT_RATE_25ms));
  ESP_ERROR_CHECK(writeRegister(__LS_GAIN_ADDR, __GAIN_3));
  ESP_ERROR_CHECK(writeRegister(registers::__PS_PULSES_ADDR, ps_freq::__FREQ_60K | __PULSE_CURRENT_100MA));
  ESP_ERROR_CHECK(writeRegister(registers::__PS_PULSES_ADDR, ps_pulses::__PS_PULSES_8));
  ESP_ERROR_CHECK(writeRegister(registers::__PS_MEAS_RATE_ADDR, resolution_ps::__PS_RESOLUTION_8bit | resolution_ps::__PS_MEASUREMENT_RATE_100ms));
  */
  ESP_ERROR_CHECK(device_is_conected());
  ESP_ERROR_CHECK(writeRegister(registers::__INT_CFG_ADDR, interrupt::__LS_VAR_MODE));
}

void loop() {
  Serial.println(get_ls_data_green());
  delay(20);
}