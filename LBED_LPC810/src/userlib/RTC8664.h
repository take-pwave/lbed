#ifndef LBED_RTC8664_H
#define LBED_RTC8664_H

#include "lbed.h"
class RTC8664 {
public:
	RTC8664(PinName sda, PinName scl);
	void setup();
	~RTC8664();

	unsigned char S,M,H,D,W,N,Y;

	void read_rtc();

	void reset();

	void set_time(
			unsigned char s,	// 秒
			unsigned char m,	// 分
			unsigned char h,	// 時
			unsigned char d,	// 日
			unsigned char w,	// 曜日（日曜日0）
			unsigned char n,	// 月
			unsigned char y);	// 年下位2桁
	void command(unsigned char reg, unsigned char dat);
	void set_alarm(
			unsigned char h,
			unsigned char m
	);
	void clear_alarm_flag();
protected:
	unsigned char read(unsigned char reg);
    I2C    _i2c;
};
#endif
