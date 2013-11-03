
#ifndef MBED_I2CLCD_H
#define MBED_I2CLCD_H

#include "lbed.h"

class I2cLCD : public Print {
public:

    enum IconType {
        Mark       =  0x0001,
        Battery_1  =  0x0004,
        Battery_2  =  0x0002,
        Battery_3  =  0x0010,
        Battery_4  =  0x0008,
        NoSound    =  0x0020,
        Lock       =  0x0040,
        ArrowDown  =  0x0080,
        ArrowUp    =  0x0100,
        Input      =  0x0200,
        Alarm      =  0x0400,
        Tell       =  0x0800,
        Antenna    =  0x1000,
    };

    I2cLCD(PinName sda, PinName scl, PinName rp);
#if DOXYGEN_ONLY
    int putc(int c);
    int printf(const char* format, ...);
#endif
    void locate(int column, int row);
    void cls();
    int rows();
    int columns();
    void seticon(IconType type);
    void clearicon(IconType type);
    void puticon(int flg);

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
    DigitalOut _rs;
    int _column;
    int _row;

    char contrast;
    int icon;

};

#endif
