#ifndef MCP_4922_H
#define MCP_4922_H

#include "lbed.h"

class MCP4922 : public SPI
{
public:
	MCP4922(PinName mosi, PinName miso, PinName sclk, PinName cs, PinName ldac);
	void write(int value);
	void write(int valueA, int valueB);
	void frequency(int hz = 1000000);
private:
	DigitalOut	_ldac;
	DigitalOut	_cs;
};
#endif
