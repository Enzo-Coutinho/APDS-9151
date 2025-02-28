#include "APDS9151.h"


i2c_port_num_t i2c_port = -1;
gpio_num_t i2c_sda_port = GPIO_NUM_21;
gpio_num_t i2c_scl_port = GPIO_NUM_22;
uint8_t data_receive_lenght = 8;
uint8_t data_transmit_lenght = 8;
i2c_master_bus_handle_t bus_handle;

i2c_master_bus_config_t i2c_master_config = {
    .i2c_port = i2c_port,
    .sda_io_num = i2c_sda_port,
    .scl_io_num = i2c_scl_port,
    .clk_source = I2C_CLK_SRC_DEFAULT,
    .glitch_ignore_cnt = 7,
    .intr_priority = 0,
};

i2c_device_config_t dev_cfg = {
    .dev_addr_length = I2C_ADDR_BIT_LEN_7,
    .device_address = 0x52,
    .scl_speed_hz = 100000,
};

i2c_master_dev_handle_t dev_handle;


void initalize()
{
    ESP_ERROR_CHECK(i2c_new_master_bus(&i2c_master_config, &bus_handle));
    ESP_ERROR_CHECK(i2c_master_bus_add_device(bus_handle, &dev_cfg, &dev_handle));
}

esp_err_t write_register(uint8_t reg, uint8_t data)
{
    uint8_t buff[2] = {reg, data};
    Serial.printf("Register: %d \n", reg);
    Serial.printf("Data: %d \n", data);
    ESP_ERROR_CHECK(i2c_master_transmit(dev_handle, buff, sizeof(buff), 1000 / portTICK_PERIOD_MS));
    return ESP_OK;
}

esp_err_t read_register(uint8_t reg, uint8_t len, uint8_t *data)
{
    return i2c_master_transmit_receive(dev_handle, &reg, 1, data, len, 1000 / portTICK_PERIOD_MS);
}

uint8_t get_main_ctrl()
{
    uint8_t main_ctrl;
    ESP_ERROR_CHECK(read_register(registers::__MAIN_CTRL_ADDR, 1, &main_ctrl));
    return main_ctrl;
}

uint32_t get_ls_data_green()
{
    uint8_t data[3];
    ESP_ERROR_CHECK(read_register(registers::__LS_DATA_GREEN_0_ADDR, 3, data));
    uint32_t greenColor = (((uint32_t)data[2] << 16) | ((uint16_t)(data[1] << 8)) | (data[0]));
    return greenColor;
}

uint32_t get_ls_data_blue()
{
    uint8_t data[3];
    ESP_ERROR_CHECK(read_register(registers::__LS_DATA_BLUE_0_ADDR, 3, data));
    uint32_t blueColor = (((uint32_t)data[2] << 16) | ((uint16_t)(data[1] << 8)) | (data[0]));
    return blueColor;
}

uint32_t get_ls_data_red()
{
    uint8_t data[3];
    ESP_ERROR_CHECK(read_register(registers::__LS_DATA_RED_0_ADDR, 3, data));
    uint32_t redColor = (((uint32_t)data[2] << 16) | ((uint16_t)(data[1] << 8)) | (data[0]));
    return redColor;
}

uint32_t get_ls_data_ir()
{
    uint8_t data[3];
    ESP_ERROR_CHECK(read_register(registers::__LS_DATA_IR_0_ADDR, 3, data));
    uint32_t ir = (((uint32_t)data[2] << 16) | ((uint16_t)(data[1] << 8)) | (data[0]));
    return ir;
}