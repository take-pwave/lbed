/*
 * HMC5883L.cpp
 *
 *  Created on: 2015/04/18
 *      Author: take
 */
#include "HMC5883L.h"

#define	PI	3.1415926
#define	TO_DEG(rad)	(rad*180.0/PI)
extern "C" {
	extern double sqrt(double);
	extern double atan2(double, double);
};

static float ratio[] = {
		1370, 1090, 820, 660, 440, 390, 330, 230
};

HMC5883L::HMC5883L(PinName sda, PinName scl) :  i2c(sda , scl) {
	//HMC5883L::setup();
}

void HMC5883L::setup() {
	i2c.setup();
	writeReg(REG_CONFIG_A, 0x70);	// 初期設定
}

void HMC5883L::setGain(int gain) {
	writeReg(REG_CONFIG_B, gain << 5);
}

void HMC5883L::writeReg(int reg, int val) {
	char cmds[2];
	cmds[0] = reg;
	cmds[1] = val;
	i2c.write(HMC5883L_ADDR, cmds, 2);
}

int HMC5883L::readReg(int reg) {
	char cmd[1];
	char data[1];
	cmd[0] = reg;
	i2c.write(HMC5883L_ADDR, cmd, 1);
	i2c.read(HMC5883L_ADDR, data, 1);
	return (int)data[0];
}

void HMC5883L::measure() {
	char	cmd[1];
	char	data[6];
	float	r;	// 係数
	int		g;	// 感度
	writeReg(REG_MODE, 0x01);	// シングルモードで測定開始
	// 測定完了まで待つ
	while ((readReg(REG_STATUS) & 0x01) == 0)
		continue;
	// 読込レジスタをREG_X_HIGHにセット
	cmd[0] = REG_X_HIGH;
	i2c.write(HMC5883L_ADDR, cmd, 1);
	// X, Z, Yを読み込む
	i2c.read(HMC5883L_ADDR, data, 6);
	ax = short(((unsigned char)data[0] << 8) | (unsigned char)data[1]);	// X軸の測定結果
	az = short(((unsigned char)data[2] << 8) | (unsigned char)data[3]);	// Z軸の測定結果
	ay = short(((unsigned char)data[4] << 8) | (unsigned char)data[5]);	// Y軸の測定結果
	// 感度を取得
	g = readReg(REG_CONFIG_B) >> 5;
	r = ratio[g];
	// 磁束密度を取得
	x = (float)ax * 1000/r;
	y = (float)ay * 1000/r;
	z = (float)az * 1000/r;
}

int HMC5883L::selfTest() {
	char	cmd[1];
	char	data[6];
	int	ret = -1;
	// Config AレジスターをPositive Self test measurementにセット
	writeReg(REG_CONFIG_A, 0x71);
	// Gain = 5をセット
	setGain(5);
	// 連続測定モードにセット
	writeReg(REG_MODE, 0x00);
	// 6m秒待つ
	wait_ms(6);
	// 100回の測定（Dataシートには回数は規定されていない）
retry:
	// 初期値のセット
	x_min = y_min = z_min = 1000;
	x_max = y_max = z_max = -1000;
	for (int i = 0; i < 100; i++) {
		i2c.read(HMC5883L_ADDR, data, 6);
		ax = short(((unsigned char)data[0] << 8) | (unsigned char)data[1]);	// X軸の測定結果
		az = short(((unsigned char)data[2] << 8) | (unsigned char)data[3]);	// Z軸の測定結果
		ay = short(((unsigned char)data[4] << 8) | (unsigned char)data[5]);	// Y軸の測定結果
		if (ax < x_min)	x_min = ax;
		if (ax > x_max)	x_max = ax;
		if (ax < y_min)	y_min = ay;
		if (ax > y_max)	y_max = ay;
		if (ax < z_min)	z_min = az;
		if (ax > z_max)	z_max = az;
		// レジスターをREG_X_HIGH=0x03にセットし、次のデータを要求
		cmd[0] = REG_X_HIGH;
		i2c.write(HMC5883L_ADDR, cmd, 1);
		// 67 ms待つ
		wait_ms(67);
	}
	// 結果をチェック、すべての軸のminとmaxが243-575の間ならOK
	if ( (243 <= x_min && x_max <= 575)
	  && (243 <= y_min && y_max <= 575)
	  && (243 <= z_min && z_max <= 575)) {
		// 成功 Config Aレジスターを通常の測定モードに戻す
		writeReg(REG_CONFIG_A, 0x70);	// 初期設定
		return 1;
	}
	else {
		int gain = readReg(REG_CONFIG_B) >> 5;
		if (gain < 7) {
			setGain(gain + 1);
			goto retry;
		}
		else {
			// 失敗
			writeReg(REG_CONFIG_A, 0x70);	// 初期設定
			return 0;
		}
	}
	writeReg(REG_CONFIG_A, 0x70);	// 初期設定
	return -1;
}

float HMC5883L::getAbs() {
	return (float)sqrt(x*x + y*y + z*z);
}

float HMC5883L::getHead() {
	double angle = TO_DEG(atan2(y, x));
	if (angle < 0.0)	angle += 360.0;
	return (float)angle;
}

