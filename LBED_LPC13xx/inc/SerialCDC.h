#ifndef MY_SERIAL_CDC_H
#define MY_SERIAL_CDC_H

#include "platform.h"
#include "Stream.h"
#include "PinNames.h"
#include "Serial.h"

class SerialCDC : public Serial
{
	public:
	SerialCDC();
	SerialCDC(PinName tx, PinName rx, const char *name = NULL);
	void	setup(PinName tx, PinName rx, const char *name = NULL);

	void	begin(unsigned int baudrate);
	virtual int write(const char c);
	virtual int read();
	virtual int available() { return _available; }
	// dummy function
	void	baud(unsigned int baudrate) {
		_available = true;			// 利用可能にセット
	}
	void	end() {}
	virtual int peek() { return 0; }
	virtual void flush() {}

	protected:
	void	CheckSerialState (void);
	PinName		_tx;
	PinName		_rx;
	bool		_available;

	private:
	unsigned short _serialState;
};
#endif
