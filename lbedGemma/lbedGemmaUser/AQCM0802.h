
#ifndef MBED_I2CLCD_H
#define MBED_I2CLCD_H

#include "lbedGemma.h"

#define LCD_DISPLAYCONTROL      0x08
// flags for display on/off control
#define LCD_DISPLAYON           0x04
#define LCD_DISPLAYOFF          0x00
#define LCD_CURSORON            0x02
#define LCD_CURSOROFF           0x00
#define LCD_BLINKON             0x01
#define LCD_BLINKOFF            0x00

class AQCM0802 : public XPrint {
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
//
    void setDisplayControl(uint8_t setBit) {
    	_displayControl |= setBit;
    	writeCommand(LCD_DISPLAYCONTROL | _displayControl);
    };
    void resetDisplayControl(uint8_t resetBit) {
    	_displayControl &= ~resetBit;
    	writeCommand(LCD_DISPLAYCONTROL | _displayControl);
    };
    // Turn the display on/off (quickly)
    void noDisplay() {
      resetDisplayControl(LCD_DISPLAYON);
    };
    void display() {
      setDisplayControl(LCD_DISPLAYON);
    };
    // Turns the underline cursor on/off
    void noCursor() {
      resetDisplayControl(LCD_CURSORON);
    };
    void cursor() {
      setDisplayControl(LCD_CURSORON);
    };
    // Turn on and off the blinking cursor
    void noBlink() {
      resetDisplayControl(LCD_BLINKON);
    };
    void blink() {
      setDisplayControl(LCD_BLINKON);
    };

protected:
    virtual int _putc(int value);
    virtual int _getc();
    // 追加 Takemoto
	virtual size_t write(uint8_t c) {
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
    uint8_t	_displayControl;
    char contrast;

};

#endif
