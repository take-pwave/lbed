#include "lbed.h"

int main(void) {
	SPI	spi(PD_3, PD_2, PD_0);
	char	*pcChars = "Hello World!\n";
	char	c;
	while((c = *pcChars++)) {
		spi.write(c);
	}
}
