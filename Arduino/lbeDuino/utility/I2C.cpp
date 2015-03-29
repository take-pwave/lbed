#include "Arduino.h"
#include "SoftI2CMaster.h"
#include "lbed.h"

I2C::I2C(int sda, int scl)
{	
	_sda = sda;
	_scl = scl;
}

void I2C::setup()
{
    _i2c.setPins(_scl, _sda, false);
    _i2c.i2c_init();
}

int I2C::write(int address, const char *data, int length, bool repeated)
{
	unsigned char addr = (unsigned char)address>>1;
	_i2c.beginTransmission(addr);
	for (int i = 0; i < length; i++) {
		_i2c.write(*data++);
	}
	return _i2c.endTransmission();
}

int I2C::read(int address, char *data, int length, bool repeated)
{
	int	ret = 0;
	unsigned char addr = (unsigned char)address>>1;
	_i2c.beginTransmission(addr);
	_i2c.requestFrom((int)addr);
	for (ret = 0; ret < length; ret++) {
		*data++ = _i2c.read();
	}
	_i2c.endTransmission();
    return ret;
}
