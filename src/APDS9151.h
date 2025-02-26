#pragma once

#include "driver/i2c_master.h"
#include <esp_err.h>

extern i2c_port_num_t i2c_port;
extern gpio_num_t i2c_sda_port;
extern  gpio_num_t i2c_scl_port;
extern  uint8_t data_receive_lenght;
extern uint8_t data_transmit_lenght;
extern i2c_master_bus_handle_t bus_handle;

extern i2c_master_bus_config_t i2c_master_config;
extern i2c_device_config_t dev_cfg;

extern i2c_master_dev_handle_t dev_handle;

esp_err_t initializeI2CMaster();
esp_err_t initializeI2CSlave();
esp_err_t transmitDataToSlave(const uint8_t * data);
uint8_t * readDataOfSlave();
uint8_t * writeAndReadDataOfSlave(const uint8_t * data);