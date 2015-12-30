#ifndef HMC5883L_H
#define HMC5883L_H

#include "lbedGemma.h"

//  HMC5883L I2C address
#define    HMC5883L_ADDR (0x1E << 1)

#define	REG_CONFIG_A	0x00
#define	REG_CONFIG_B	0x01
#define	REG_MODE		0x02
#define	REG_X_HIGH		0x03
#define	REG_X_LOW		0x04
#define	REG_Y_HIGH		0x05
#define	REG_Y_LOW		0x06
#define	REG_Z_HIGH		0x07
#define	REG_Z_LOW		0x08
#define	REG_STATUS		0x09
#define	REG_A			0x0A
#define	REG_B			0x0B
#define	REG_C			0x0C


class HMC5883L {
public:
	HMC5883L(PinName sda, PinName scl);
	void 			setup();
	void			setGain(int gain);
	void			writeReg(int reg, int val);	// レジスタに値を書き込む
	int				readReg(int reg);				// レジスタの値を取得
	void 			measure();	// 測定を実行
	float			getAbs();	// 全磁力を返す
	float			getHead();	// 北からの方位角を返す（単位 度）
	float			x, y, z;	// 測定地（単位 mGa）
private:
	I2C 			i2c;
	float			ax, ay, az;	// 測定データを保持
};

#endif
