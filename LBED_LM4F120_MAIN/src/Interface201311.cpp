#include "lbed.h"
#include "MCP4922.h"
#include "math.h"
#define	PI	3.1415926
#define	SAMPLE 4096
#define	sin(x)	sinf(x)

// データ：	元の音声とそのフーリエ係数
// 母音 /ア/,サンプリング周波数: 8 KHz
const int	N_DATA	= 65;
const short	snOrg[N_DATA] = {
		-56,	139,	439,	785,	1041,	1277,	1180,	934,	564,	133,
		-147,	-131,	-9,		343,	684,	860,	991,	926,	773,	634,
		501,	481,	695,	961,	1293,	1459,	1356,	1022,	613,	229,
		118,	206,	437,	698,	794,	680,	430,	68,		-192,	-325,
		-365,	-312,	-278,	-299,	-350,	-494,	-731,	-939,	-1077,	-1211,
		-1289,	-1382,	-1446,	-1511,	-1639,	-1645,	-1580,	-1425,	-1139,	-808,
		-608,	-420,	-362,	-288,	-68
};
// フーリエ係数
const int	HARMO_MAX = 15;
const float	an[HARMO_MAX + 1] = {
		20.61,	-376.22,	305.13,	257.95,	45.26,	-47.79,	-205.22,	-94.12,
		-8.32,	-19.58,		19.21,	-0.73,	-2.51,	7.29,	0.97,		-2.58
};
const float	bn[HARMO_MAX + 1] = {
		0.00,	949.63,		246.53,	181.33,	111.38,	38.06,	143.08,		-269.01,
		51.38,	-34.27,		19.66,	13.44,	5.81,	5.36,	-0.37,		3.62
};

void synthesis(const float an[], const float bn[], short vn[], int order, int nData) {
	const float	PI2 = 2.0*3.1415926;
	const float	PI2_T = PI2/(float)nData;

	for (int n = 0; n < nData; n++) {
		vn[n] = (short)an[0];
		for (int k = 1; k <= order; k++) {
			float kPi2T = k*PI2_T;
			vn[n] += (short)(an[k]*cos(kPi2T*n) + bn[k]*sin(kPi2T*n));
		}
	}
}
// 8KHzのタイミングでデータをDACに送るためにok変数とTickerを使用する
volatile bool	ok = false;
void getTiming() {
	ok = true;
}

#define	N_TO 	(N_DATA - 1)
#define FS		(8000)
#define	COUNT	(5)
#define	DC		(2048)		// 12bit分は、4096でその半分の値を0とする

int main(void) {
	Serial pc(PA_1, PA_0);
	pc.baud(19200);
	Ticker timer;
	timer.attach(&getTiming, 1.0/FS);

	// PD_2は使用していないので、未接続で実行
	MCP4922	mcp4922(PD_3, PD_2, PD_0, PE_1, PE_2);	// mosi, miso, sclk, cs, ldac
	// 10MHzにセット
	mcp4922.frequency(16000000);

	short	sn[N_TO];
	short	vn[N_TO];
	int		order = 15;
	sn[0] = (snOrg[0] + snOrg[N_TO])/2;	// サンプリングデータの先頭と最後の平均をsn[0]の値とする
	// サンプリングデータをsnにセット
	for (int n = 1; n < N_TO; n++)
		sn[n] = snOrg[n];
	// フーリエ係数から「ア」を音声合成
	synthesis(an, bn, vn, order, N_TO);
	pc.println("Input Order:[1-9]");
	while(1) {
		if (pc.available()) {
			// フーリエ係数の次数を変更する
			char c = pc.read();
			order = c - '0';
			synthesis(an, bn, vn, order, N_TO);
		}
		for (int count = 0; count < COUNT; count++) {	// 5回繰り返す
			for (int n = 0; n < N_TO; n++) {
				// 出力タイミングまで待つ
				while(!ok) continue;
				mcp4922.write(sn[n] + DC, vn[n] + DC);
				ok = false;
			}
		}
	}
}
