#include "APDS9151.h"


i2c_port_num_t i2c_port = -1;
gpio_num_t i2c_sda_port = GPIO_NUM_21;
gpio_num_t i2c_scl_port = GPIO_NUM_22;

i2c_master_bus_handle_t i2c__master_bus_handle;

i2c_master_bus_config_t i2c_master_bus_configure = {
    .i2c_port = i2c_port,
    .sda_io_num = i2c_sda_port,
    .scl_io_num = i2c_scl_port,
    .clk_source = I2C_CLK_SRC_DEFAULT,
    .glitch_ignore_cnt = 7,
    .intr_priority = 0,
};

i2c_device_config_t apds9151_i2c_configure = {
    .dev_addr_length = I2C_ADDR_BIT_LEN_7,
    .device_address = 0x52,
    .scl_speed_hz = 100000,
};

i2c_master_dev_handle_t apds9151_dev_handle;


void initalize()
{
    ESP_ERROR_CHECK(i2c_new_master_bus(&i2c_master_bus_configure, &i2c__master_bus_handle));
    ESP_ERROR_CHECK(i2c_master_bus_add_device(i2c__master_bus_handle, &apds9151_i2c_configure, &apds9151_dev_handle));
}

esp_err_t write_register(uint8_t reg, uint8_t data)
{
    uint8_t buff[2] = {reg, data};
    return i2c_master_transmit(apds9151_dev_handle, buff, sizeof(buff), 1000 / portTICK_PERIOD_MS);
}

esp_err_t read_register(uint8_t reg, uint8_t len, uint8_t *data)
{
    return i2c_master_transmit_receive(apds9151_dev_handle, &reg, 1, data, len, 1000 / portTICK_PERIOD_MS);
}

uint8_t getMainCtrlConfigure()
{
    uint8_t main_ctrl;
    ESP_ERROR_CHECK(read_register(registers::__MAIN_CTRL_ADDR, 1, &main_ctrl));
    return main_ctrl;
}

uint8_t getPsLedConfigure()
{
    uint8_t psLed;
    ESP_ERROR_CHECK(read_register(registers::__PS_LED_ADDR, 1, &psLed));
    return psLed;
}

uint8_t getPsPulsesConfigure()
{
    uint8_t psPulses;
    ESP_ERROR_CHECK(read_register(registers::__PS_PULSES_ADDR, 1, &psPulses));
    return psPulses;
}

uint8_t getPsMeasRateConfigure()
{
    uint8_t psMeasRate;
    ESP_ERROR_CHECK(read_register(registers::__PS_MEAS_RATE_ADDR, 1, &psMeasRate));
    return psMeasRate;
}

uint8_t getLsMeasRateConfigure()
{
    uint8_t psMeasRate;
    ESP_ERROR_CHECK(read_register(registers::__LS_MEAS_RATE_ADDR, 1, &psMeasRate));
    return psMeasRate;
}

uint8_t getLsGainConfigure()
{
    uint8_t psMeasRate;
    ESP_ERROR_CHECK(read_register(registers::__LS_GAIN_ADDR, 1, &psMeasRate));
    return psMeasRate;
}

uint8_t getPartID()
{
    uint8_t partId;
    ESP_ERROR_CHECK(read_register(registers::__PART_ID_ADDR, 1, &partId));
    return partId;
}

uint8_t getMainStatus()
{
    uint8_t mainStatus;
    ESP_ERROR_CHECK(read_register(registers::__MAIN_STATUS_ADDR, 1, &mainStatus));
    return mainStatus;
}

uint8_t getInterruptConfigure()
{
    uint8_t intCfg;
    ESP_ERROR_CHECK(read_register(registers::__INT_CFG_ADDR, 1, &intCfg));
    return intCfg;
}

uint8_t getPersistInterruptConfigure()
{
    uint8_t intPst;
    ESP_ERROR_CHECK(read_register(registers::__INT_PST_ADDR, 1, &intPst));
    return intPst;
}

uint32_t getLsDataGreen()
{
    uint8_t data[3];
    ESP_ERROR_CHECK(read_register(registers::__LS_DATA_GREEN_0_ADDR, 3, data));
    uint32_t greenColor = to_20_bit(data);
    return greenColor;
}

uint32_t getLsDataBlue()
{
    uint8_t data[3];
    ESP_ERROR_CHECK(read_register(registers::__LS_DATA_BLUE_0_ADDR, 3, data));
    uint32_t blueColor = to_20_bit(data);
    return blueColor;
}

uint32_t getLsDataRed()
{
    uint8_t data[3];
    ESP_ERROR_CHECK(read_register(registers::__LS_DATA_RED_0_ADDR, 3, data));
    uint32_t redColor = to_20_bit(data);
    return redColor;
}

uint32_t getLsDataIR()
{
    uint8_t data[3];
    ESP_ERROR_CHECK(read_register(registers::__LS_DATA_IR_0_ADDR, 3, data));
    uint32_t ir = to_20_bit(data);
    return ir;
}

uint32_t to_20_bit(uint8_t data[3])
{
    return (((uint32_t)data[2] << 16) | ((uint16_t)(data[1] << 8)) | (data[0]));
}