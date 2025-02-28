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
#include "esp32-hal-log.h"
#include "vector"

extern i2c_port_num_t i2c_port;
extern gpio_num_t i2c_sda_port;
extern  gpio_num_t i2c_scl_port;
extern  uint8_t data_receive_lenght;
extern uint8_t data_transmit_lenght;
extern i2c_master_bus_handle_t bus_handle;

extern i2c_master_bus_config_t i2c_master_config;
extern i2c_device_config_t dev_cfg;

extern i2c_master_dev_handle_t dev_handle;

void initalize();
esp_err_t write_register(uint8_t reg, uint8_t data);
esp_err_t read_register(uint8_t reg, uint8_t len, uint8_t *data);

uint8_t get_main_ctrl();

uint8_t get_ls_data_green();
uint8_t get_ls_data_blue();
uint8_t get_ls_data_red();
uint8_t get_ir_result();
uint8_t get_ir_result();
uint8_t get_main_status();
uint8_t get_configure();
uint8_t get_part_id();
uint8_t get_ps_data();
esp_err_t device_is_conected();
void get_rgb();