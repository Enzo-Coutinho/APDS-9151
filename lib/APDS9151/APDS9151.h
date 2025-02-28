#pragma once

#include "Arduino.h"
#include "driver/i2c_master.h"
#include "memory_address.h"
#include <esp_err.h>
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

extern i2c_port_num_t i2c_port;
extern gpio_num_t i2c_sda_port;
extern  gpio_num_t i2c_scl_port;
extern  uint8_t data_receive_lenght;
extern uint8_t data_transmit_lenght;

extern i2c_master_bus_handle_t i2c__master_bus_handle;
extern i2c_master_bus_config_t i2c_master_bus_configure;
extern i2c_device_config_t apds9151_i2c_configure;
extern i2c_master_dev_handle_t apds9151_dev_handle;

void initalize();

esp_err_t write_register(uint8_t reg, uint8_t data);
esp_err_t read_register(uint8_t reg, uint8_t len, uint8_t *data);
uint32_t to_20_bit(uint8_t data[3]);

esp_err_t device_is_conected();

uint8_t getMainCtrlConfigure();
uint8_t getPsLedConfigure();
uint8_t getPsPulsesConfigure();
uint8_t getPsMeasRateConfigure();
uint8_t getLsMeasRateConfigure();
uint8_t getLsGainConfigure();
uint8_t getPartID();
uint8_t getMainStatus();

uint8_t getInterruptConfigure();
uint8_t getPersistInterruptConfigure();
uint16_t getPsThresholdUpConfigure();
uint16_t getPsThresholdLowConfigure();
uint16_t getLsThresholdUpConfigure();
uint16_t getLsThresholdLowConfigure();
uint16_t getLsThresholdVarianceConfigure();
uint16_t getPsCAN();

uint32_t getLsDataGreen();
uint32_t getLsDataBlue();
uint32_t getLsDataRed();
uint32_t getLsDataIR();
uint8_t getPsData();

void setMainCtrl(bool SAI_PS, bool SAI_LS, bool SW_RESET, bool RGB_MODE, bool LS_EN, bool PS_EN);
void setPsLedConfigure(PS_FREQUENCY ledPulseFreq, PS_CURRENT ledCurrent);
void setPsPulsesConfigure(PS_PULSES numberOfLedPulses);
void setPsMeasRateConfigure(PS_RESOLUTION psResolution, PS_MEASUREMENT_RATE psMeasurementRate);
void setLsMeasRateConfigure(LS_RESOLUTION lsResolution, LS_MEASUREMENT_RATE lsMeasurementRate);
void setLsGainConfigure(GAIN gain);
void setInterruptionConfigure();
void setPersistInterruptionConfigure();
void setPsThresholdUpValue();
void setPsThresholdLowValue();
void setPsCANValue();
void setLsThresholdLowValue();
void setLsThresholdUpValue();
void setLsThresholdVarianceValue();