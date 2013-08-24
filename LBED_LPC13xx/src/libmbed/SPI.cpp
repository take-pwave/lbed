#include "platform.h"
#include "PinNames.h"
#include "SPI.h"

#include "type.h"
#include "_ssp.h"
#include <math.h>

//using namespace mbed;

SPI::SPI(PinName mosi, PinName miso, PinName sclk, const char *name) :
	_mosi(-1), _miso(-1), _sclk(-1), _bits(8), _hz(1000000), _mode(0),
			_delay(0) {
	_name = (char *) name;
	// ハードSPIのみをサポート（ピン固定）
	if (mosi == MOSI && (miso == MISO || miso == NC) && sclk == SCKL) {
		_spi = LPC_SSP0;
		SSP_IOConfig(SSP_NUM); /* initialize SSP port, share pins with SPI1 on port2(p2.0-3). */
		SSP_Init(SSP_NUM);
		// 8bits, mode=0;
		format(_bits, _mode);
		// 1MHz
		frequency(_hz);
		// バッファの初期化（例題に習った）
		for (int i = 0; i < SSP_BUFSIZE; i++) {
			src_addr[i] = 0;
			dest_addr[i] = 0;
		}
	}
}

void SPI::format(int bits, int mode) {
	int	DSS = bits - 1;
	int FRF = 0x00 * SSPCR0_FRF;	// SPI
	int POLPHA = 0;
	switch (mode) {
	case 0:	// POL:0, PHA:0
		POLPHA = 0; break;
	case 1: // POL:0, PHA:1
		POLPHA = SSPCR0_SPH; break;
	case 2: // POL:1, PHA:0
		POLPHA = SSPCR0_SPO; break;
	case 3: // POL:1, PHA:1
		POLPHA = SSPCR0_SPH + SSPCR0_SPO; break;
	}
	_spi->CR0 &= (0xFFFF & (DSS + FRF + POLPHA));
}

void SPI::frequency(int hz) {
	// mbedのソースを参考にプリスケールCPSRとSCRを決める
    uint32_t PCLK = SystemCoreClock;
    int prescaler;

    for (prescaler = 2; prescaler <= 254; prescaler += 2) {
        int prescale_hz = PCLK / prescaler;

        // calculate the divider
        int divider = floor(((float)prescale_hz / (float)hz) + 0.5);

        // check we can support the divider
        if (divider < 256) {
            // prescaler
        	_spi->CPSR = prescaler;

            // divider
        	_spi->CR0 &= ~(0xFFFF << 8);
        	_spi->CR0 |= (divider - 1) << 8;
            return;
        }
    }
}

int SPI::write(int value) {
	int len = (_bits + 7)/8;
	int i;
	for (i = len-1; i >= 0; i--) {
		src_addr[i] = value & 0xFF;
		value = value >> 8;
	}
	return SSP_Send(SSP_NUM, src_addr, len);
}

