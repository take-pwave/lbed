
#ifndef LBED_AQCM0802_H
#define LBED_AQCM0802_H

#include "lbed.h"

class AQCM0802 : public Print {
public:
	AQCM0802(PinName sda, PinName scl);
	void setup();
#if DOXYGEN_ONLY
    int putc(int c);
    int printf(const char* format, ...);
#endif
    void locate(int column, int row);
    void cls();
    int rows();
    int columns();

protected:
    virtual int _putc(int value);
    virtual int _getc();
    // 追加 Takemoto
	virtual int write(const char c) {
		_putc(c);
		return 1;
	}

    int address(int column, int row);
    void character(int column, int row, int c);
    void writeCommand( int cmd );
    void writeData( int data );

    I2C    _i2c;
    int _column;
    int _row;

    char contrast;

};

#endif
