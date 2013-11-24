#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/ssi.h"
#include "driverlib/pin_map.h"

int main(void) {
	char *pcChars = "Hello World\n";
	long lIdx;

    // The SSI1 peripheral and port D must be enabled for use.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI1);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);

    // Configure the pin muxing for SSI1 functions on port D.
    GPIOPinConfigure(GPIO_PD0_SSI1CLK);
    GPIOPinConfigure(GPIO_PD2_SSI1RX);
    GPIOPinConfigure(GPIO_PD3_SSI1TX);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_1);
    GPIOPinTypeSSI(GPIO_PORTD_BASE, GPIO_PIN_0 | GPIO_PIN_2 | GPIO_PIN_3);

	// SSI を設定します。
	SSIClockSourceSet(SSI1_BASE, SSI_CLOCK_SYSTEM);
	SSIConfigSetExpClk(SSI1_BASE, SysCtlClockGet(), SSI_FRF_MOTO_MODE_0,
			SSI_MODE_MASTER, 500000, 8);
	// SSI モジュールをイネーブルします。
	SSIEnable(SSI1_BASE);

	// データを送信します。
	lIdx = 0;
	while (pcChars[lIdx]) {
		SSIDataPut(SSI1_BASE, pcChars[lIdx++]);
		while (SSIBusy(SSI1_BASE))
			continue;
	}
}
