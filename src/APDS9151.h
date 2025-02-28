#pragma once

#include "driver/i2c_master.h"
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
extern i2c_master_bus_handle_t bus_handle;

extern i2c_master_bus_config_t i2c_master_config;
extern i2c_device_config_t dev_cfg;

extern i2c_master_dev_handle_t dev_handle;

enum registers {
    __MAIN_CTRL_ADDR = 0x00,
    __PS_LED_ADDR = 0x01,
    __PS_PULSES_ADDR = 0x02,
    __PS_MEAS_RATE_ADDR = 0x03,
    __LS_MEAS_RATE_ADDR = 0x04,
    __LS_GAIN_ADDR = 0x05,
    __PART_ID_ADDR = 0x06,
    __MAIN_STATUS_ADDR = 0x07,
    __PS_DATA_0_ADDR = 0x08,
    __PS_DATA_1_ADDR = 0x09,
    __LS_DATA_IR_0_ADDR = 0x0A,
    __LS_DATA_IR_1_ADDR = 0x0B,
    __LS_DATA_IR_2_ADDR = 0x0C,
    __LS_DATA_GREEN_0_ADDR = 0x0D,
    __LS_DATA_GREEN_1_ADDR = 0x0E,
    __LS_DATA_GREEN_2_ADDR = 0x0F,
    __LS_DATA_BLUE_0_ADDR = 0x10,
    __LS_DATA_BLUE_1_ADDR = 0x11,
    __LS_DATA_BLUE_2_ADDR = 0x12,
    __LS_DATA_RED_0_ADDR = 0x13,
    __LS_DATA_RED_1_ADDR = 0x14,
    __LS_DATA_RED_2_ADDR = 0x15,
    __INT_CFG_ADDR = 0x19,
    __INT_PST = 0x1A,
    __PS_THRES_UP_0 = 0x1B,
    __PS_THRES_UP_1 = 0x1C,
    __PS_THRES_LOW_0 = 0x1D,
    __PS_THRES_LOW_1 = 0x1E,
    __PS_CAN_0 = 0x1F,
    __PS_CAN1 = 0x20,
    __LS_THRES_UP_0 = 0x21,
    __LS_THRES_UP_1 = 0x22,
    __LS_THRES_UP_2 = 0x23,
    __LS_THRES_LOW_0 = 0x24,
    __LS_THRES_LOW_1 = 0x25,
    __LS_THRES_LOW_2 = 0x26,
    __LS_THRES_VAR = 0x27,
};

enum data_main_ctrl {
    __SAI_PS = 0x40,
    __SAI_LS = 0x20,
    __SW_RESET = 0x10,
    __RGB_MODE = 0x04,
    __LS_EN = 0x02,
    __PS_EN = 0x01,
};

enum ps_freq {
    __FREQ_60K = 0x30,
    __FREQ_70K = 0x40,
    __FREQ_80K = 0x50,
    __FREQ_90K = 0x60,
    __FREQ_100K = 0x70,
    __PULSE_CURRENT_2_5MA = 0x00,
    __PULSE_CURRENT_5MA = 0x01,
    __PULSE_CURRENT_10MA = 0x02,
    __PULSE_CURRENT_25MA = 0x03,
    __PULSE_CURRENT_50MA = 0x04,
    __PULSE_CURRENT_75MA = 0x05,
    __PULSE_CURRENT_100MA = 0x06,
    __PULSE_CURRENT_125MA = 0x07,
};

enum resolution_ps {
    __PS_RESOLUTION_8bit = 0x00,
    __PS_RESOLUTION_9bit = 0x08,
    __PS_RESOLUTION_10bit = 0x10,
    __PS_RESOLUTION_11bit = 0x18,
    __PS_MEASUREMENT_RATE_6_25ms = 0x01,    
    __PS_MEASUREMENT_RATE_12_5ms = 0x02,
    __PS_MEASUREMENT_RATE_25ms = 0x03,
    __PS_MEASUREMENT_RATE_50ms = 0x04,
    __PS_MEASUREMENT_RATE_100ms = 0x05,
    __PS_MEASUREMENT_RATE_200ms = 0x06,
    __PS_MEASUREMENT_RATE_400ms = 0x07,
};

enum ps_pulses {
    __PS_PULSES_0 = 0b00000000,
    __PS_PULSES_8 = 0b00001000,
    __PS_PULSES_32 = 0b00100000,
    __PS_PULSES_255 = 0b11111111,
};

enum resolution_ls {
    __LS_RESOLUTION_20bit = 0x00,
    __LS_RESOLUTION_19bit = 0x10,
    __LS_RESOLUTION_18bit = 0x20,  // default
    __LS_RESOLUTION_17bit = 0x30,
    __LS_RESOLUTION_16bit = 0x40,
    __LS_RESOLUTION_13bit = 0x50,
    __LS_MEASUREMENT_RATE_25ms = 0x00,
    __LS_MEASUREMENT_RATE_50ms = 0x01,
    __LS_MEASUREMENT_RATE_100ms = 0x02, // default
    __LS_MEASUREMENT_RATE_200ms = 0x03,
    __LS_MEASUREMENT_RATE_500s = 0x04,
    __LS_MEASUREMENT_RATE_1000s = 0x05,
    __LS_MEASUREMENT_RATE_2000ms_0 = 0x06,
    __LS_MEASUREMENT_RATE_2000ms_1 = 0x07,
};

enum gain {
    __GAIN_1 = 0x00,
    __GAIN_3 = 0x01, // default
    __GAIN_6 = 0x02,
    __GAIN_9 = 0x03,
    __GAIN_18 = 0x04,
};

enum interrupt {
    __PS_INT_EN = 0x01,
    __PS_LOGIC_MODE = 0x02,
    __LS_INT_EN = 0x04,
    __LS_VAR_MODE = 0x08,
    __LS_INT_SEL_IR_CHANNEL = 0x00,
    __LS_INT_SEL_ALS_CHANNEL = 0x10,
    __LS_INT_SEL_GEEN_CHANNEL = 0x20,
    __LS_INT_SEL_RED_CHANNEL = 0x30,
};

void initalize();
esp_err_t writeRegister(uint8_t reg, uint8_t data);
esp_err_t readRegister();
uint32_t get_ls_data_green();
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