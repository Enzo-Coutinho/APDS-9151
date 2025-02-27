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
    .scl_speed_hz = 400000,
};

i2c_master_dev_handle_t dev_handle;


void initalize()
{
    ESP_ERROR_CHECK(i2c_new_master_bus(&i2c_master_config, &bus_handle));
    ESP_ERROR_CHECK(i2c_master_bus_add_device(bus_handle, &dev_cfg, &dev_handle));
}

esp_err_t writeRegister(uint8_t reg, uint8_t data)
{
    uint8_t buff[2] = {reg, data};
    return i2c_master_transmit(dev_handle, buff, sizeof(data), 1000 / portTICK_PERIOD_MS);
}

esp_err_t writeBlockRegister(uint8_t reg, uint8_t data)
{
    uint8_t buff[3] = {reg, data};
    return i2c_master_transmit(dev_handle, buff, sizeof(data), 1000 / portTICK_PERIOD_MS);
}

void readRegister(uint8_t reg, uint8_t len, uint8_t *data)
{
    ESP_ERROR_CHECK(i2c_master_transmit_receive(dev_handle, &reg, 1, data, len, 1000 / portTICK_PERIOD_MS));
}

uint8_t get_ls_data_green()
{
    uint8_t data[1];
    readRegister(registers::__LS_DATA_GREEN_0_ADDR, 1, data);
    uint8_t greenColor = data[0];
    return greenColor;

}
uint8_t get_ls_data_blue()
{
    uint8_t data[1];
    readRegister(registers::__LS_DATA_BLUE_0_ADDR, 1, data);
    uint8_t blueColor = data[0];
    return blueColor;
}

uint8_t get_ls_data_red()
{
    uint8_t data[1];
    readRegister(registers::__LS_DATA_RED_0_ADDR, 1, data);
    uint8_t redColor = data[0];
    return redColor;
}

uint8_t get_ir_result()
{
    uint8_t data[1];
    readRegister(registers::__LS_DATA_IR_0_ADDR, 1, data);
    uint8_t ir = data[0];
    return ir;
}

uint8_t get_main_status()
{
    uint_least8_t data[1];
    readRegister(registers::__MAIN_STATUS_ADDR, 1, data);
    uint_least8_t status = data[0];
    return status;
}

uint8_t get_part_id()
{
    uint8_t data[1];
    readRegister(registers::__PART_ID_ADDR, 1, data);
    uint8_t status = data[0];
    return status;
}

uint8_t get_ps_data()
{
    uint8_t data;
    readRegister(registers::__PS_DATA_0_ADDR, 1, & data);
    uint8_t status = data;
    return status;
}

esp_err_t device_is_conected()
{
    return i2c_master_probe(bus_handle, dev_cfg.device_address, 1000 / portTICK_PERIOD_MS);
}

uint8_t get_configure()
{
    uint8_t data[1];
    readRegister(registers::__INT_CFG_ADDR, 1, data);
    return data[0];
}