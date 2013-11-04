#ifndef MY_SERIAL_H
#define MY_SERIAL_H

#include "platform.h"
#include "Stream.h"
#include "PinNames.h"
#define	NULL	0

class Serial : public Stream
{
	public:
	Serial();
	Serial(PinName tx, PinName rx, const char *name = NULL);
	void	setup(PinName tx, PinName rx, const char *name = NULL);
	void	baud(unsigned int baudrate);

	void	begin(unsigned int baudrate);
	void	end() {}
	virtual int write(const char c);
	virtual int read();
	virtual int available();
	// dummy function
	virtual int peek() { return 0; }
	virtual void flush() {}

	protected:
	PinName		_tx;
	PinName		_rx;
	bool		_available;

	private:
};
#endif
