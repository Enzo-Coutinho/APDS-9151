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
};

i2c_device_config_t dev_cfg = {
    .dev_addr_length = I2C_ADDR_BIT_LEN_7,
    .device_address = 0x52,
    .scl_speed_hz = 100000,
};

i2c_master_dev_handle_t dev_handle;


esp_err_t initializeI2CMaster()
{
    return i2c_new_master_bus(&i2c_master_config, &bus_handle);
}

esp_err_t initializeI2CSlave()
{
    return i2c_master_bus_add_device(bus_handle, &dev_cfg, &dev_handle);
}

esp_err_t transmitDataToSlave(const uint8_t * data)
{
    return i2c_master_transmit(dev_handle, data, data_transmit_lenght, -1);
}

uint8_t * readDataOfSlave()
{
    uint8_t * data_rd = new uint8_t;
    data_rd = nullptr;
    ESP_ERROR_CHECK(i2c_master_receive(dev_handle, data_rd, data_receive_lenght, -1));
    return data_rd;
}

uint8_t * writeAndReadDataOfSlave(const uint8_t * data)
{
    uint8_t buf[20] = {0x0A};
    uint8_t * buffer = new uint8_t[8];
    ESP_ERROR_CHECK(i2c_master_transmit_receive(dev_handle, buf, data_receive_lenght, buffer, data_transmit_lenght, -1));
    return buffer;
}