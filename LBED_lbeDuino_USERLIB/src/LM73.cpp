#include "lbed.h"
#include "LM73.h"

LM73::LM73(PinName sda, PinName scl) : i2c(sda, scl)
{
	char cmd[2];
	// LM73設定
	cmd[0]    = 0x04;	// register 4
	cmd[1]    = 0x60;   	// 14bit resolution
	i2c.write( LM73_ADDR, cmd, 2);
	// ポインタを0にしておく(readするだけで温度が読めるようになる)
	cmd[0]    = 0x00; 
	i2c.write( LM73_ADDR, cmd, 1);
}

LM73::~LM73()
{
}

float LM73::read()
{
	char cmd[2];
    // I2C.readの仕様を間違えており、writeで0x00を書き込んでからデータを取得していた。
	// これを修正するため、writeを追加しました。
    cmd[0] = 0;
    i2c.write(LM73_ADDR, cmd, 1);	// 温度の読み取りコマンドを送る

	i2c.read( LM73_ADDR, cmd, 2); // Send command string    
	int int_val = cmd[0] <<1 | cmd[1]>>7;
	int ceil_val = ((cmd[1] & 0x7f)*200) >>8;
	return float(int_val + ceil_val/100.0);
}
