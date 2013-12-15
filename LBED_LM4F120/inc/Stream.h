#ifndef LBED_STREAM_H
#define LBED_STREAM_H

#include "Print.h"

class Stream : public Print
{
	private:
	public:
    virtual int available() = 0;
    virtual int read() = 0;
    virtual int peek() = 0;
    virtual void flush() = 0;
	protected:
};
#endif
