#ifndef LBED_RTC8564_H
#define LBED_RTC8564_H

#include "lbed.h"

#define	NOT_APPLICABLE	(0x80)

class RTC8564 {
public:
	RTC8564(PinName sda, PinName scl);
	void setup();
	~RTC8564();

	unsigned char s,m,h,D,W,M;
	short		  Y;

	void read_rtc();

	void reset();

	void set_time(
			unsigned short Y,	// 年
			unsigned char M,	// 月
			unsigned char D,	// 日
			unsigned char h,	// 時
			unsigned char m,	// 分
			unsigned char s);	// 秒
	void command(unsigned char reg, unsigned char dat);
	void set_alarm(
			unsigned char h,
			unsigned char m
	);
	void clear_alarm_flag();
protected:
	unsigned char read(unsigned char reg);
    I2C    _i2c;
private:
    // 10進から16進のBCDコードに変換
    unsigned char dec2Bcd(unsigned char val) { return (unsigned char)((val/10) << 4 | val%10); }
    // 16進のBCDコードから10進に変換
    unsigned char bcd2Dec(unsigned char val) { return (unsigned char)((val/16) *10 + val%16); }
    // y,m, dから曜日を計算する(０を日曜日として0-6を返す)
    unsigned char zeller(int y, int m, int d) {
    	if (m < 3) {
    		y--;
    		m += 12;
    	}
    	return (unsigned char)( y + y/4 - y/100 + y/400 + ( 13*m + 8 )/5 + d )%7;
    }
};
#endif
