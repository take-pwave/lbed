#include "lbed.h"
#include "MCP4922.h"
#include "math.h"
#define	PI	3.1415926
#define	SAMPLE 4096
#define	sin(x)	sinf(x)

int main(void) {
	// PD_2は使用していないので、未接続で実行
	MCP4922	mcp4922(PD_3, PD_2, PD_0, PE_1, PE_2);	// mosi, miso, sclk, cs, ldac
	// 10MHzにセット
	mcp4922.frequency(16000000);
	while(1) {
		for (int i=0; i < 4096; i+=4) {
			int sineValue = (int)(0xFFF*(1 + sin(2*PI*i/SAMPLE))/2);
			mcp4922.write(sineValue);
			//mcp4922.write(i);
		}
	}
}
