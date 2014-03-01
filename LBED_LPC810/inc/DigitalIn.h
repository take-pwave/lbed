#ifndef LBED_DIGITALIN_H
#define LBED_DIGITALIN_H

class DigitalIn {
public:
	DigitalIn();
	DigitalIn(char pin);
	int read();

	operator int()
	{
		return read();
	}

	/*
	 * LPC_IOCONにセットする値がわからないので、ダミーとする
	 */
	void mode(int pull) {
	}
private:
	void setup(char pin);
protected:
	char	_pin;
};
#endif
