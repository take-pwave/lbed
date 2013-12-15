#include "MCP4922.h"
#include "lbed.h"

#define	HIGHT	(1)
#define LOW		(0)

MCP4922::MCP4922(PinName mosi, PinName miso, PinName sclk, PinName cs, PinName ldac)
	: SPI(mosi, miso, sclk), _ldac(ldac), _cs(cs)
{
}

void MCP4922::write(int value) {
	_ldac = HIGHT;
	_cs = LOW;
	SPI::write((value >> 8) | 0x30);
	SPI::write(value & 0xFF);
	_cs = HIGHT;
	_ldac = LOW;
}

void MCP4922::write(int valueA, int valueB) {
	_ldac = HIGHT;
	_cs = LOW;
	SPI::write((valueA >> 8) | 0x70);
	SPI::write(valueA & 0xFF);
	_cs = HIGHT;
	_ldac = LOW;
	wait_us(1);
	_ldac = HIGHT;
	_cs = LOW;
	SPI::write((valueB >> 8) | 0xF0);
	SPI::write(valueB & 0xFF);
	_cs = HIGHT;
	_ldac = LOW;
}

void MCP4922::frequency(int hz) {
	SPI::frequency(hz);
}
