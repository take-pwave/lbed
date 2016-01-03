#include "ADT7410.h"
 
 
 // constructor takes paramters and initializes I2C bus
ADT7410::ADT7410(PinName sda, PinName scl, char addr, int hz)
        : i2c(sda, scl)
        , busAddr(addr)
{
    i2c.frequency(hz);
}
 
// destructor
ADT7410::~ADT7410() {
}
 
// read 13 bit temperature
float ADT7410::getTemp() {
 
    char wReg[1] = {TEMP_REG_ADDR};
    char rReg[2] = {0,0};
    float tFin = 0;
    int tRaw = 0;
 
    // set address pointer to temperature register
    i2c.write(busAddr, wReg, 1);
 
    // read temperature register, two bytes
    i2c.read(busAddr, rReg, 2);
 
    // temperature returned is only 13 bits
    // discard alarm flags in lower bits
    tRaw = (rReg[0] << 8) | (rReg[1]);
    tRaw >>= 3;
 
    // handle positive and negative temperatures
    // results in two's complement
    if ( tRaw & 0x1000) {
        tFin = (float) (tRaw - 8192) / 16;
    } else {
        tFin = (float) tRaw  / 16;
    }
     
    return tFin;
}
 
void ADT7410::setConfig(char regVal) {
 
    char wReg[2] = {CONFIG_REG_ADDR, regVal};
    i2c.write(busAddr, wReg, 2);
    return;
}
 
char ADT7410::getConfig() {
 
    char rReg[1] = {0};
    char wReg[1] = {CONFIG_REG_ADDR};
    // need to add repeat to supress stop
   i2c.write(busAddr, wReg, 1, 1); 
   i2c.read(busAddr, rReg, 1);
    return rReg[0];
}
 
 
// reset the sensor
void ADT7410::reset() {
 
    char wReg[1] = {RESET};
    i2c.write(busAddr, wReg, 1);
    // wait for sensor to reload and convert
    wait_ms(250);
    return;
}
 
