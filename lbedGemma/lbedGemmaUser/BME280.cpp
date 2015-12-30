/**
 *  BME280 Combined humidity and pressure sensor library
 *
 *  @author  Toyomasa Watarai
 *  @version 1.0
 *  @date    06-April-2015
 *
 *  Library for "BME280 temperature, humidity and pressure sensor module" from Switch Science
 *    https://www.switch-science.com/catalog/2236/
 *
 *  For more information about the BME280:
 *    http://ae-bst.resource.bosch.com/media/products/dokumente/bme280/BST-BME280_DS001-09.pdf
 */

//#include "mbed.h"
#include "lbedGemma.h"
#include "BME280.h"

BME280::BME280(PinName sda, PinName scl, char slave_adr)
    :
    i2c(sda, scl),
    address(slave_adr),
    t_fine(0)
{
    //initialize();
}

//+++ add H.TAKEMOTO
void BME280::setup() {
	i2c.setup();
	initialize();
}
//---

void BME280::initialize()
{
    char cmd[18];

    cmd[0] = 0xf2; // ctrl_hum
    cmd[1] = 0x01; // Humidity oversampling x1
    i2c.write(address, cmd, 2);

    cmd[0] = 0xf4; // ctrl_meas
    cmd[1] = 0x27; // Temparature oversampling x1, Pressure oversampling x1, Normal mode
    i2c.write(address, cmd, 2);

    cmd[0] = 0xf5; // config
    cmd[1] = 0xa0; // Standby 1000ms, Filter off
    i2c.write(address, cmd, 2);

    cmd[0] = 0x88; // read dig_T regs
    i2c.write(address, cmd, 1);
    i2c.read(address, cmd, 6);

    dig_T1 = (uint16_t)(((uint8_t)cmd[1] << 8) | (uint8_t)cmd[0]);
    dig_T2 = (int16_t)(((uint8_t)cmd[3] << 8) | (uint8_t)cmd[2]);
    dig_T3 = (int16_t)(((uint8_t)cmd[5] << 8) | (uint8_t)cmd[4]);

    //DEBUG_PRINT("dig_T = 0x%x, 0x%x, 0x%x\n", dig_T1, dig_T2, dig_T3);

    cmd[0] = 0x8E; // read dig_P regs
    i2c.write(address, cmd, 1);
    i2c.read(address, cmd, 18);

    dig_P1 = (uint16_t)(((uint8_t)cmd[ 1] << 8) | (uint8_t)cmd[ 0]);
    dig_P2 = (int16_t)(((uint8_t)cmd[ 3] << 8) | (uint8_t)cmd[ 2]);
    dig_P3 = (int16_t)(((uint8_t)cmd[ 5] << 8) | (uint8_t)cmd[ 4]);
    dig_P4 = (int16_t)(((uint8_t)cmd[ 7] << 8) | (uint8_t)cmd[ 6]);
    dig_P5 = (int16_t)(((uint8_t)cmd[ 9] << 8) | (uint8_t)cmd[ 8]);
    dig_P6 = (int16_t)(((uint8_t)cmd[11] << 8) | (uint8_t)cmd[10]);
    dig_P7 = (int16_t)(((uint8_t)cmd[13] << 8) | (uint8_t)cmd[12]);
    dig_P8 = (int16_t)(((uint8_t)cmd[15] << 8) | (uint8_t)cmd[14]);
    dig_P9 = (int16_t)(((uint8_t)cmd[17] << 8) | (uint8_t)cmd[16]);

    //DEBUG_PRINT("dig_P = 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n", dig_P1, dig_P2, dig_P3, dig_P4, dig_P5, dig_P6, dig_P7, dig_P8, dig_P9);

    cmd[0] = 0xA1; // read dig_H regs
    i2c.write(address, cmd, 1);
    i2c.read(address, cmd, 1);
     cmd[1] = 0xE1; // read dig_H regs
    i2c.write(address, &cmd[1], 1);
    i2c.read(address, &cmd[1], 7);

    dig_H1 = (int16_t)cmd[0];
    dig_H2 = (int16_t)(((uint8_t)cmd[2] << 8) | (uint8_t)cmd[1]);
    dig_H3 = (int16_t)cmd[3];
    dig_H4 = (int16_t)(((uint8_t)cmd[4] << 4) | ((uint8_t)cmd[5] & 0x0f));
    dig_H5 = (int16_t)(((uint8_t)cmd[6] << 4) | (((uint8_t)cmd[5]>>4) & 0x0f));
    dig_H6 = cmd[7];

    //DEBUG_PRINT("dig_H = 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n", dig_H1, dig_H2, dig_H3, dig_H4, dig_H5, dig_H6);
}

float BME280::getTemperature()
{
    uint32_t temp_raw;
    float tempf;
    char cmd[4];

    cmd[0] = 0xfa; // temp_msb
    i2c.write(address, cmd, 1);
    i2c.read(address, &cmd[1], 1);

    cmd[0] = 0xfb; // temp_lsb
    i2c.write(address, cmd, 1);
    i2c.read(address, &cmd[2], 1);

    cmd[0] = 0xfc; // temp_xlsb
    i2c.write(address, cmd, 1);
    i2c.read(address, &cmd[3], 1);

    // Arduino版は、intが16bitなので、キャストがうまく処理できないので、領域を割り当て計算する。
    uint32_t data[4];
    for (int i = 0; i < 4; i++)	data[i] = (uint8_t)cmd[i];
    temp_raw = (data[1] << 12) | (data[2] << 4) | (data[3] >> 4);

    int32_t var1, var2, temp;

    // Arduino版では、キャストを追加
    var1 = ((((temp_raw >> 3) - ((int32_t)dig_T1 << 1))) * ((int32_t)dig_T2)) >> 11;
    var2 = (((((temp_raw >> 4) - ((int32_t)dig_T1)) * ((temp_raw >> 4) - ((int32_t)dig_T1))) >> 12) * ((int32_t)dig_T3)) >> 14;

    t_fine = var1 + var2;
    temp = (t_fine * 5 + 128) >> 8;
    tempf = (float)temp;

    return (tempf/100.0f);
}

float BME280::getPressure()
{
    uint32_t press_raw;
    float pressf;
    char cmd[4];

    cmd[0] = 0xf7; // press_msb
    i2c.write(address, cmd, 1);
    i2c.read(address, &cmd[1], 1);

    cmd[0] = 0xf8; // press_lsb
    i2c.write(address, cmd, 1);
    i2c.read(address, &cmd[2], 1);

    cmd[0] = 0xf9; // press_xlsb
    i2c.write(address, cmd, 1);
    i2c.read(address, &cmd[3], 1);

    // Arduino版は、intが16bitなので、キャストがうまく処理できないので、領域を割り当て計算する。
    uint32_t data[4];
    for (int i = 0; i < 4; i++)	data[i] = (uint8_t)cmd[i];
    press_raw = (data[1] << 12) | (data[2] << 4) | (data[3] >> 4);

    int32_t var1, var2;
    uint32_t press;

    // Arduino版では、キャストを追加
    var1 = ((uint32_t)t_fine >> 1) - (int32_t)64000;
    var2 = (((var1 >> 2) * (var1 >> 2)) >> 11) * (int32_t)dig_P6;
    var2 = var2 + ((var1 * (int32_t)dig_P5) << 1);
    var2 = (var2 >> 2) + ((int32_t)dig_P4 << 16);
    var1 = (((dig_P3 * (((var1 >> 2)*(var1 >> 2)) >> 13)) >> 3) + (((int32_t)dig_P2 * var1) >> 1)) >> 18;
    var1 = ((32768 + var1) * (int32_t)dig_P1) >> 15;
    if (var1 == 0) {
        return 0;
    }
    press = ((((int32_t)1048576 - press_raw) - (var2 >> 12))) * 3125;
    if(press < 0x80000000) {
        press = (press << 1) / (int32_t)var1;
    } else {
        press = (press / (uint32_t)var1) * 2;
    }
    var1 = ((int32_t)dig_P9 * ((int32_t)(((press >> 3) * (press >> 3)) >> 13))) >> 12;
    var2 = (((int32_t)(press >> 2)) * (int32_t)dig_P8) >> 13;
    press = (press + ((var1 + var2 + dig_P7) >> 4));

    pressf = (float)press;
    return (pressf/100.0f);
}

float BME280::getHumidity()
{
    uint32_t hum_raw;
    float humf;
    char cmd[4];

    cmd[0] = 0xfd; // hum_msb
    i2c.write(address, cmd, 1);
    i2c.read(address, &cmd[1], 1);

    cmd[0] = 0xfd; // hum_lsb
    i2c.write(address, cmd, 1);
    i2c.read(address, &cmd[2], 1);

    hum_raw = (cmd[1] << 8) | cmd[2];

    int32_t v_x1;

    // Arduino版では、キャストを追加
    v_x1 = t_fine - (int32_t)76800;
    v_x1 =  (((((hum_raw << 14) -(((int32_t)dig_H4) << 20) - (((int32_t)dig_H5) * v_x1)) +
               ((int32_t)16384)) >> 15) * (((((((v_x1 * (int32_t)dig_H6) >> 10) *
                                            (((v_x1 * ((int32_t)dig_H3)) >> 11) + 32768)) >> 10) + (int32_t)2097152) *
                                            (int32_t)dig_H2 + 8192) >> 14));
    v_x1 = (v_x1 - (((((v_x1 >> 15) * (v_x1 >> 15)) >> 7) * (int32_t)dig_H1) >> 4));
    v_x1 = (v_x1 < 0 ? 0 : v_x1);
    v_x1 = (v_x1 > 419430400 ? 419430400 : v_x1);

    humf = (float)(v_x1 >> 12);

    return (humf/1024.0f);
}


