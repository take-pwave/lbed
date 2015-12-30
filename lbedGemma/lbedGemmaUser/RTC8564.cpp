#include "RTC8564.h"
#include "lbedGemma.h"

#define    RTC_8564_ADDR    (0x51 << 1)

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

void RTC8564::clear_alarm_flag() {
	char ctrl2[]= {CTRL2};
	_i2c.read(RTC_8564_ADDR, ctrl2, 1);
	// アラームが設定されており、アラームフラッグが1の時にリセット
	if (ctrl2[0]&AIE_BIT &&  ctrl2[0]&AF_BIT)
		command(CTRL2,			AIE_BIT);	// アラーム割り込み可能にする
}

void RTC8564::set_alarm(
		unsigned char h,	// 時を10進でセット、比較対象外にする場合には、0x80を指定
		unsigned char m		// 分を10進でセット、比較対象外にする場合には、0x80を指定
)
{
	// 分
	if (m == NOT_APPLICABLE)
		command(ALARM_MINITE, NOT_APPLICABLE);
	else
		command(ALARM_MINITE, dec2Bcd(m));
	// 時
	if (h == NOT_APPLICABLE)
		command(ALARM_HOUR, NOT_APPLICABLE);
	else
		command(ALARM_HOUR, dec2Bcd(h));
	command(ALARM_DAY,		NOT_APPLICABLE); // 比較対象外
	command(ALARM_WEEK,		NOT_APPLICABLE); // 比較対象外
	command(CTRL2,			AIE_BIT);	// アラーム割り込み可能にする
	clear_alarm_flag();
}

RTC8564::RTC8564(PinName sda, PinName scl) : _i2c(sda , scl) {
	//RTC8664::setup();
}

RTC8564::~RTC8564() {}

void RTC8564::setup() {
    // このタイミングでセットアップする
    _i2c.setup();
    RTC8564::reset();
}

void RTC8564::read_rtc() {
	char buf[7];
	buf[0] = SEC;
	// 秒レジスターをセット
    _i2c.write(RTC_8564_ADDR, buf, 1);
	// 順番に読み込む
	_i2c.read(RTC_8564_ADDR, buf, 7);
	s = bcd2Dec(((unsigned char)buf[0])&0x7F);
	m = bcd2Dec(((unsigned char)buf[1])&0x7F);	// 未使用 bitを取り除く
	h = bcd2Dec(((unsigned char)buf[2])&0x3F);	// 未使用 bitを取り除く
	D = bcd2Dec(((unsigned char)buf[3])&0x3F);	// 未使用 bitを取り除く
	W = ((unsigned char)buf[4])&0x03;			// 未使用 bitを取り除く
	M = bcd2Dec(((unsigned char)buf[5])&0x1F);	// 未使用 bitを取り除く
	Y = bcd2Dec((unsigned char)buf[6]) + 2000;
}

void RTC8564::set_time(
		unsigned short Y_,
		unsigned char M_,
		unsigned char D_,
		unsigned char h_,
		unsigned char m_,
		unsigned char s_) {
	command(CTRL1, 0x20); // stop
	command(CTRL2, 0x00);
	command(CTRLT, 0x00);
	command(CKOUT, 0x83); // 7:FE=1 10:FD=11 (1Hz)
	command(YEAR,  dec2Bcd((unsigned char)(Y_%100))); // 年
	command(MONTH, dec2Bcd(M_)); // 月
	command(DAY,   dec2Bcd(D_)); // 日
	command(HOUR,  dec2Bcd(h_)); // 時
	command(MIN,   dec2Bcd(m_)); // 分
	command(SEC,   dec2Bcd(s_)); // 秒
	command(WDAY,  zeller(2000+Y_, M_, D_)); // 曜日（日曜日0）
	command(CTRL1, 0x00); // start
}

void RTC8564::reset() {
    // RTC8564初期化
	command(CTRL1, 0x20); // stop
	command(CTRL2, 0x00);
	command(CTRLT, 0x00);
	command(CKOUT, 0x83); // 7:FE=1 10:FD=11 (1Hz)
	command(CTRL1, 0x00); // start
}

void RTC8564::command(unsigned char reg, unsigned char dat) {
	char cmds[2];
	cmds[0] = reg;
	cmds[1] = dat;
	_i2c.write(RTC_8564_ADDR,cmds, 2);
}
