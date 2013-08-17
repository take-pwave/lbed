#include "SerialCDC.h"
#include "PinNames.h"
#include "LPC13xx.h"
#include "_usb.h"
#include "_cdc_usbcfg.h"
#include "_usbhw.h"
#include "_usbcore.h"
#include "_cdc.h"
#include "_cdcuser.h"

SerialCDC::SerialCDC()
	: _tx(-1)
	, _rx(-1)
{
	setup(USBTX, USBRX, "default");
}

SerialCDC::SerialCDC(PinName tx, PinName rx, const char *name)
	: _tx(-1)
	, _rx(-1)
{
	setup(tx, rx, name);
}

void SerialCDC::setup(PinName tx, PinName rx, const char *name)
{
	_tx = tx;
	_rx = rx;
	_available = false;
	USBIOClkConfig();
	CDC_Init ();					// CDC Initialization
	USB_Init(); 					// USB Initialization
	USB_Connect(1);   				// USB Connect
	while (!USB_Configuration)
		continue;					// wait until USB is configured
}

int SerialCDC::write(const char c) {
	unsigned int i;
	unsigned char cbuf;
	cbuf = c;
	while(!CDC_DepInEmpty)
		;
	USB_WriteEP (CDC_DEP_IN, (unsigned char *)&cbuf, 1);
	for (i=0; i<10000; i++) {
		if (!CDC_DepInEmpty)
			break;
	}
	return (1);
}

int SerialCDC::read() {
	int		numAvailByte = 0;
	char	c;

	CheckSerialState();
	do {
		CDC_OutBufAvailChar (&numAvailByte);
		if (numAvailByte > 0) {
			int numBytesToRead = 1;
			int numBytesRead = CDC_RdOutBuf (&c, &numBytesToRead);
		}
	} while (numAvailByte <= 0);
	return (c);
}

void SerialCDC::CheckSerialState (void)
{
	unsigned short temp = CDC_GetSerialState();
	if (_serialState != temp) {
		_serialState = temp;
		CDC_NotificationIn();		// send SERIAL_STATE notification
	}
}
