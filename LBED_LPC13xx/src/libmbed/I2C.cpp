#include "platform.h"
#include "PinNames.h"
#include "I2C.h"

#include "LPC13xx.h"			/* LPC13xx Peripheral Registers */
#include "type.h"
#include "_i2c.h"

extern volatile uint32_t I2CCount;
extern volatile uint8_t I2CMasterBuffer[BUFSIZE];
extern volatile uint8_t I2CSlaveBuffer[BUFSIZE];

extern volatile uint32_t I2CMasterState;
extern volatile uint32_t I2CReadLength, I2CWriteLength;

I2C::I2C(PinName sda, PinName scl, const char *name) {
	_name = (char *) name;
	if (I2CInit((uint32_t) I2CMASTER) == FALSE) /* initialize I2c */
	{
		while (1)
			; /* Fatal error */
	}
}

int I2C::read(int address, char *data, int length, bool repeated) {
    for (int i = 0; i < length; i++)
    	I2CSlaveBuffer[i] = 0x00;
    I2CReadLength = length;
    I2CWriteLength = 0;
    getI2CMasterBuffer()[0] = address | RD_BIT;
    I2CEngine();
    for (int i = 0; i < length; i++)
    	data[i] = getI2CSlaveBuffer()[i];
    return length;
}

int I2C::read(int ack) {
    I2CReadLength = 1;
    I2CEngine();
	return getI2CSlaveBuffer()[0];
}

int I2C::write(int address, const char *data, int length, bool repeated) {
    I2CWriteLength = length+1;
    I2CReadLength = 0;
    getI2CMasterBuffer()[0] = address;
    for (int i = 0; i < length; i++)
    	getI2CMasterBuffer()[i+1] = data[i];
    I2CEngine();
    return 1;
}

int I2C::write(int ack) {
    I2CWriteLength = 2;
    I2CReadLength = 0;
    getI2CMasterBuffer()[1] = ack;
    I2CEngine();
    return 1;
}

