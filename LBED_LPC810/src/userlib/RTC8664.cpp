#include "RTC8664.h"
#include "lbed.h"

#define    RTC_8664_ADDR    (0x51 << 1)

#define CTRL1 0x00
#define CTRL2 0x01
#define SEC   0x02
#define MIN   0x03
#define HOUR  0x04
#define DAY   0x05
#define WDAY  0x06
#define MONTH 0x07
#define YEAR  0x08
#define ALARM_MINITE	0x09
#define ALARM_HOUR		0x0a
#define ALARM_DAY		0x0b
#define ALARM_WEEK		0x0c

#define CKOUT 0x0d // CLKOUT frequency 7:FE 1:FD1 0:FD0
#define CTRLT 0x0e // Timer Control 7:TE 1:TD1 0:TD0

#define	AF_BIT	0x08
#define	AIE_BIT	0x02

void RTC8664::clear_alarm_flag() {
	char ctrl2[]= {CTRL2};
	_i2c.read(RTC_8664_ADDR, ctrl2, 1);
	// アラームが設定されており、アラームフラッグが1の時にリセット
	if (ctrl2[0]&AIE_BIT &&  ctrl2[0]&AF_BIT)
		command(CTRL2,			AIE_BIT);	// アラーム割り込み可能にする
}

void RTC8664::set_alarm(
		unsigned char h,	// 時を16進でセット、比較対象外にする場合には、0x80を指定
		unsigned char m		// 分を16進でセット、比較対象外にする場合には、0x80を指定
)
{
	command(ALARM_MINITE,	m); // 分
	command(ALARM_MINITE,	h); // 時
	command(ALARM_DAY,		0x80); // 比較対象外
	command(ALARM_WEEK,		0x80); // 比較対象外
	command(CTRL2,			AIE_BIT);	// アラーム割り込み可能にする
}

RTC8664::RTC8664(PinName sda, PinName scl) : _i2c(sda , scl) {
	//RTC8664::setup();
}

void RTC8664::setup() {
	RTC8664::reset();
}

void RTC8664::read_rtc() {
	char buf[7];
	buf[0] = SEC;
	// 秒レジスターをセット
	// 順番に読み込む
	_i2c.read(RTC_8664_ADDR, buf, 7);
	S = (unsigned char)buf[0];
	M = ((unsigned char)buf[1])&0x3F;	// 未使用 bitを取り除く
	H = ((unsigned char)buf[2])&0x3F;	// 未使用 bitを取り除く
	D = ((unsigned char)buf[3])&0x3F;	// 未使用 bitを取り除く
	W = ((unsigned char)buf[4])&0x03;	// 未使用 bitを取り除く
	N = ((unsigned char)buf[5])&0x1F;	// 未使用 bitを取り除く
	Y = (unsigned char)buf[6];
}

void RTC8664::set_time(
		unsigned char s,
		unsigned char m,
		unsigned char h,
		unsigned char d,
		unsigned char w,
		unsigned char n,
		unsigned char y) {
	command(CTRL1, 0x20); // stop
	command(CTRL2, 0x00);
	command(CTRLT, 0x00);
	command(CKOUT, 0x83); // 7:FE=1 10:FD=11 (1Hz)
	command(YEAR,  y); // 年 (下位2桁)
	command(MONTH, n); // 月
	command(DAY,   d); // 日
	command(HOUR,  h); // 時
	command(MIN,   m); // 分
	command(SEC,   s); // 秒
	command(WDAY,  w); // 曜日（日曜日0）
	command(CTRL1, 0x00); // start
}

void RTC8664::reset() {
    // RTC8564初期化
	command(CTRL1, 0x20); // stop
	command(CTRL2, 0x00);
	command(CTRLT, 0x00);
	command(CKOUT, 0x83); // 7:FE=1 10:FD=11 (1Hz)
	command(CTRL1, 0x00); // start
}

void RTC8664::command(unsigned char reg, unsigned char dat) {
	char cmds[2];
	cmds[0] = reg;
	cmds[1] = dat;
	_i2c.write(RTC_8664_ADDR,cmds, 2);
}
