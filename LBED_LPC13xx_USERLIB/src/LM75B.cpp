#include "lbed.h"
#include "LM75B.h"

LM75B::LM75B(PinName sda, PinName scl) : i2c(sda, scl)
{
	char cmd[2];
	// LM73設定
	cmd[0]    = 0x00;	// register 0
	cmd[1]    = 0x28;   // 温度レジスタを選択
	i2c.write( LM75_ADDR, cmd, 2);
}

LM75B::~LM75B()
{
}

float LM75B::read()
{
	char cmd[2];
    // I2C.readの仕様を間違えており、writeで0x00を書き込んでからデータを取得していた。
	// これを修正するため、writeを追加しました。
    cmd[0] = 0;
    i2c.write(LM75_ADDR, cmd, 1);	// 温度の読み取りコマンドを送る

	i2c.read( LM75_ADDR, cmd, 2); // Send command string
	unsigned int int_val = cmd[0] <<3 | cmd[1]>>5;
	return float(int_val*125/1000.0);
}
