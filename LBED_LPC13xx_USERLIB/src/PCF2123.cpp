#include "lbed.h"
#include "PCF2123.h"

PCF2123::PCF2123(PinName mosi, PinName miso, PinName sclk, PinName sel)
	: _spi(mosi, miso, sclk)
	, _sel(sel)
{
	_sel = 0;
	_spi.frequency(SPI_FREQUENCY);
    wait_ms( 1 );
}

PCF2123::~PCF2123()
{
}

unsigned char PCF2123::read(unsigned char reg)
{
	int val = _spi.write(reg);
	return val;
}

void PCF2123::command(unsigned char reg, unsigned char dat)
{
	_sel = 1;
	_spi.write(reg);
	_spi.write(dat);
	_sel = 0;
}

void PCF2123::read_rtc()
{
	_sel = 1;
	read((READ_BIT|SUBADDR|REG_SC));
	S = read(READ_NEXT);
	M = read(READ_NEXT);
	H = read(READ_NEXT);
	D = read(READ_NEXT);
	W = read(READ_NEXT);
	N = read(READ_NEXT);
	Y = read(READ_NEXT);
	_sel = 0;
}
void	PCF2123::reset() {
    // initialize RTC
	command((WRITE_BIT|SUBADDR|REG_CTRL1),RESET);	// Send a software reset command
	wait_us(1);
	command((WRITE_BIT|SUBADDR|REG_CTRL1), 0x20);	// Stop the counter first
	wait_us(1);
	_sel = 1;
	int ret = read((READ_BIT|SUBADDR|REG_CTRL1));
	_sel = 0;
	command((WRITE_BIT|SUBADDR|REG_CTRL1), 0x00);	// Start the counter
	wait_us(1);
}

void 	PCF2123::set_time(
		unsigned char s,
		unsigned char m,
		unsigned char h,
		unsigned char d,
		unsigned char w,
		unsigned char n,
		unsigned char y)
{
	reset();
	command((WRITE_BIT|SUBADDR|REG_CTRL1), 0x20);	// Stop the counter first
	wait_us(1);
	_sel = 1;
	read((WRITE_BIT|SUBADDR|REG_SC));
	read(s);
	read(m);
	read(h);
	read(d);
	read(w);
	read(n);
	read(y);
	_sel = 0;
	wait_us(1);
	command((WRITE_BIT|SUBADDR|REG_CTRL1), 0x00);	// Start the counter
	wait_us(1);
}

void	PCF2123::set_alarm(
		unsigned char h,
		unsigned char m
)
{
	command((WRITE_BIT|SUBADDR|REG_CTRL2), 0x02);	// アラーム割り込みを可能にする
	wait_us(1);
	command((WRITE_BIT|SUBADDR|ALARM_DAY), 0x80);	// 日付は使用しない
	wait_us(1);
	command((WRITE_BIT|SUBADDR|ALARM_HOUR), h);
	wait_us(1);
	command((WRITE_BIT|SUBADDR|ALARM_MINITE), m);
	wait_us(1);
	command((WRITE_BIT|SUBADDR|ALARM_WEEK), 0x80);	// 曜日は使用しない
	wait_us(1);
}
