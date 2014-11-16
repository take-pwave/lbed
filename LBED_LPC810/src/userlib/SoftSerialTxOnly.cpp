/*
 * SoftSerialTxOnly.cpp
 *
 *  Created on: 2014/11/03
 *      Author: take
 */

#include "lbed.h"
#include "SoftSerialTxOnly.h"
#include "LPC8xx.h"

// 4800bps
#define SERIAL_TIME_PER_BIT1    105
#define SERIAL_TIME_PER_BIT2    104

SoftSerialTxOnly::SoftSerialTxOnly(PinName pin) : _out(pin) {

}

int SoftSerialTxOnly::_putc(int value) {
	uint8_t data = value;
	_out = 0;
	wait_us(SERIAL_TIME_PER_BIT1);

	uint8_t i;
	for (int cnt = 0, i=0x01; cnt < 8; i<<=1, cnt++) {
		if (data & i)
			_out = 1;
		else
			_out = 0;
		wait_us(SERIAL_TIME_PER_BIT2);
	}
	_out = 1;
	wait_us(SERIAL_TIME_PER_BIT1);

	return value;
}
