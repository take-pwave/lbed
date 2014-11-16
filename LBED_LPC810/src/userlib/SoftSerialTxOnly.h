/*
 * SoftSerialTxOnly.h
 *
 *  Created on: 2014/11/03
 *      Author: take
 */

#ifndef SOFTSERIALTXONLY_H_
#define SOFTSERIALTXONLY_H_
#include "lbed.h"

class SoftSerialTxOnly : public Print {
public:
	SoftSerialTxOnly(PinName pin);

protected:
    virtual int _putc(int value);
    virtual int _getc() { return -1; };

    virtual int write(const char c) {
		_putc(c);
		return 1;
	}

    DigitalOut	_out;
};

#endif /* SOFTSERIALTXONLY_H_ */
