#ifndef LBED_I2C_H
#define LBED_I2C_H

class I2C {
public:
    I2C(){}
	/** SCL、SDAはスイッチマトリックスで設定する */
	I2C(char sda, char scl);
	/** 100KHz固定なのでダミー関数とする */
	void frequency(int hz) {}
	int read(int address, char *data, int length, bool repeated = false);
	int write(int address, const char *data, int length, bool repeated = false);
    /* Arduino 固有のメソッド */
    void setup();
	/** 以下使い方が分からないのでダミー関数 */
	int read(int ack) {
		return -1;
	}
	int write(int data) {
		return -1;
	}
	void start(void) {}
	void stop(void) {}
};

#endif
