/** TMP006 Temperature methods.
 *  Used for interfacing the TMP006 with the mbed.
 *
 * Example:
 * @code
 * #include "mbed.h"
 * #include "TMP006.h"

 * #define Address 0x80
 *
 * TMP006 sensor(p9, p10, Address);
 *
 * int main()
 * {
 * while(1) {
 *   printf("TTemperature: %f F \r \n", sensor.readObjTempF(Address));
 *   wait(0.5);
 * }
 * }
 * @endcode
 */


#ifndef TMP006_H
#define TMP006_H

#include "lbed.h"
#include <math.h>

// Constants for calculating object temperature
#define TMP006_B0 -0.0000294
#define TMP006_B1 -0.00000057
#define TMP006_B2 0.00000000463
#define TMP006_C2 13.4
#define TMP006_TREF 298.15
#define TMP006_A2 -0.00001678
#define TMP006_A1 0.00175
#define TMP006_S0 6.4  // * 10^-14

// Configuration Settings
#define TMP006_CFG_RESET    0x8000
#define TMP006_CFG_MODEON   0x7000
#define TMP006_CFG_1SAMPLE  0x0000
#define TMP006_CFG_2SAMPLE  0x0200
#define TMP006_CFG_4SAMPLE  0x0400
#define TMP006_CFG_8SAMPLE  0x0600
#define TMP006_CFG_16SAMPLE 0x0800
#define TMP006_CFG_DRDYEN   0x0100
#define TMP006_CFG_DRDY     0x0080

// Registers to read thermopile voltage and sensor temperature
#define TMP006_VOBJ  0x00
#define TMP006_TAMB 0x01
#define TMP006_CONFIG 0x02

class TMP006
{
public:

    // Constructor
    TMP006(PinName sda, PinName scl, int addr);

    /** Configures sensor, use before reading from it */
    void config(uint8_t addr, uint16_t samples);

    /** Read raw sensor temperature */
    int16_t readRawDieTemperature(uint8_t addr);

    /** Read raw thermopile voltage */
    int16_t readRawVoltage(uint8_t addr);

    /** Calculate object temperature (C) based on raw sensor temp and thermopile voltage */
    double readObjTempC(uint8_t addr);

    /** Calculate object temperature (F) based on raw sensor temp and thermopile voltage */
    double readObjTempF(uint8_t addr);

    /** Caculate sensor temperature (C) based on raw reading */
    double readDieTempC(uint8_t addr);

    /** Caculate sensor temperature (F) based on raw reading */
    double readDieTempF(uint8_t addr);

    /*!
    Destroys instance.
    */
    ~TMP006();

    //int16_t read(uint8_t addr, uint8_t pointer);


private:

    I2C m_i2c;
    int m_addr;

};

#endif
