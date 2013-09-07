#ifndef PCF2123_H
#define PCF2123_H

#include "lbed.h"


class PCF2123
{
public:
    /** General parameters for PCF2123 */
    enum  {
    	SUBADDR			= (1 << 4),
    	WRITE_BIT		= (0 << 7),
    	READ_BIT		= (1 << 7),
    	REG_CTRL1		= 0x00,
    	REG_CTRL2		= 0x01,
        REG_SC			= 0x02,
        REG_MN			= 0x03,
        REG_HR			= 0x04,
        REG_DM			= 0x05,
        REG_DW			= 0x06,
        REG_MO			= 0x07,
        REG_YR			= 0x08,
        ALARM_MINITE	= 0x09,
        ALARM_HOUR		= 0x0a,
        ALARM_DAY		= 0x0b,
        ALARM_WEEK		= 0x0c,
        RESET			= 0x58,
        START_READ		= 0x92,
        READ_NEXT		= 0xFF,
        MODE24			= 0x00,
        AIE				= 0x02,
        SPI_FREQUENCY	= 500000    /**< SPI (sclk) SPI_FREQUENCY  */
    };

	//!Creates an instance of the class.
	PCF2123(PinName mosi, PinName miso, PinName sclk, PinName sel);

	/*!
	Destroys instance.
	*/
	~PCF2123();

	unsigned char S,M,H,D,W,N,Y;

	void read_rtc();

	void reset();

	void set_time(
			unsigned char s,
			unsigned char m,
			unsigned char h,
			unsigned char d,
			unsigned char w,
			unsigned char n,
			unsigned char y);
	void command(unsigned char reg, unsigned char dat);
	void set_alarm(
			unsigned char h,
			unsigned char m
	);
protected:
	unsigned char read(unsigned char reg);
	SPI			_spi;
	DigitalOut	_sel;
  
private:


};

#endif
