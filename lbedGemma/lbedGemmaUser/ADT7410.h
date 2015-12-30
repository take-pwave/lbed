/*
Copyright (c) 2011 Tom Kreyche tkreyche@well.com
 
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
 
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
 
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
 
 
#ifndef ADT7410_H
#define ADT7410_H
 
// #include "mbed.h"
#include "lbedGemma.h"
 
// sensor register addresses
// only a partial list, don't use them all
#define TEMP_REG_ADDR 0x00
#define CONFIG_REG_ADDR 0x03
#define RESET 0x2F
 
// configuration register values
// only a partial list, don't use them all
#define ONE_SPS_MODE 0x40
 
/**
*
* Example:
* @code
*
* #include "mbed.h"
* #include "ADT7410.h"
*
* ADT7410 tempSens1(p28, p27, 0x90, 100000);
*
* int main() {
*
*   // reset sensor to default values
*   tempSens1.reset();
*
*   // read the config register, should be default
*   printf("Config: 0x%x\n", tempSens1.getConfig());
*
*   // reduce sample rate to save power
*   tempSens1.setConfig(ONE_SPS_MODE);
*
*   // check config register was set correctly
*   printf("Config: 0x%x\n", tempSens1.getConfig());
*
*   // get temperature every two seconds
*   while (1) {
*       printf("Deg C %f\n", tempSens1.getTemp());
*       wait(2);
*   }
* }
*
* @endcode
*/
 
 
 
class ADT7410 {
 
public:
 
    /** Create a temperature sensor object 
    * @param sda I2C data
    * @param scl I2C clock
    * @param addr I2C bus address
    * @param hz I2C bus speed
    */
    ADT7410(PinName sda, PinName scl, char addr, int hz);
 
    /** Destroys object
    */
    ~ADT7410();
 
    /** Reads the current temperature
    */
    float getTemp();
 
    /** Change config register, currently only used to reduce power via 1SPS mode
    * @param regVal new config register value, see datasheet for details
    */
    void setConfig(char regVal);
 
    /** Read back config register
    */
    char getConfig();
 
    /** Reset sensor to default setting
    */
    void reset();
 
private:
    I2C i2c;
    char busAddr;
 
};
 
#endif