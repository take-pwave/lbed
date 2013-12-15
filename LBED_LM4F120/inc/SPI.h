#ifndef LBED_SPI_H
#define LBED_SPI_H

#include <PinNames.h>

#define	NULL			0L

typedef	unsigned char uint8_t;


/* Class: SPI
 *  A SPI Master, used for communicating with SPI slave devices
 *
 * The default format is set to 8-bits, mode 0, and a clock frequency of 1MHz
 *
 * Most SPI devices will also require Chip Select and Reset signals. These
 * can be controlled using <DigitalOut> pins
 *
 * Example:
 * > // Send a byte to a SPI slave, and record the response
 * >
 * > #include "mbed.h"
 * >
 * > SPI device(p5, p6, p7); // mosi, miso, sclk
 * >
 * > int main() {
 * >     int response = device.write(0xFF);
 * > }
 */ 
class SPI /*: public Base*/ {

public:

    /* Constructor: SPI
     *  Create a SPI master connected to the specified pins
     *
     * Variables:
     *  mosi - SPI Master Out, Slave In pin
     *  miso - SPI Master In, Slave Out pin
     *  sclk - SPI Clock pin
     *  name - (optional) A string to identify the object     
     *
     * Pin Options:
     *  (5, 6, 7) or (11, 12, 13)
     *
     *  mosi or miso can be specfied as NC if not used
     */
    SPI(PinName mosi, PinName miso, PinName sclk, const char *name = NULL);

    /* Function: format
     *  Configure the data transmission format
     *
     * Variables:
     *  bits - Number of bits per SPI frame (4 - 16)
     *  mode - Clock polarity and phase mode (0 - 3)
     *
     * > mode | POL PHA 
     * > -----+--------	 
     * >   0  |  0   0 
     * >   1  |  0   1
     * >   2  |  1   0 
     * >   3  |  1   1
     */
    void format(int bits, int mode = 0);

    /* Function: frequency
     *  Set the spi bus clock frequency
     *
     * Variables:
     *  hz - SCLK frequency in hz (default = 1MHz)
     */
    void frequency(int hz = 1000000);

    /* Function: write
     *  Write to the SPI Slave and return the response
     *
     * Variables:
     *  value - Data to be sent to the SPI slave
     *  returns - Response from the SPI slave
    */
    int write(int value);


protected:
    const char *    _name;
	PinName _mosi;
    PinName _miso;
    PinName _sclk;
    int _bits;
    unsigned long _hz;
    int _mode;

    unsigned long _base;
    unsigned long _ulMode;

private:

};

#endif

