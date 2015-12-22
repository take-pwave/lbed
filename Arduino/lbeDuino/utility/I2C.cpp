#include "Arduino.h"
#include "Wire.h"
#include "lbed.h"

I2C::I2C(int sda, int scl)
{	
}

void I2C::setup()
{
    // Wire.begin();	// Arduinoの違いにより、beginの引数が異なるため、スケッチのsetupで定義してもらうように変更
}

int I2C::write(int address, const char *data, int length, bool repeated)
{
	unsigned char addr = (unsigned char)address>>1;
	Wire.beginTransmission(addr);
	for (int i = 0; i < length; i++) {
		Wire.write(*data++);
	}
	return Wire.endTransmission();
}

int I2C::read(int address, char *data, int length, bool repeated)
{
	int	ret = 0;
	unsigned char addr = (unsigned char)address>>1;
	Wire.beginTransmission(addr);
	Wire.requestFrom((int)addr, length);
	for (ret = 0; ret < length; ret++) {
		// wait for available
		while(!Wire.available()) continue;
		*data++ = Wire.read();
	}
	Wire.endTransmission();
    return ret;
}
