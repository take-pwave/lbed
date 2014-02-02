#ifndef LBED_TONE_H
#define LBED_TONE_H

class Tone
{
public:
    Tone();
    Tone(int pin);
    ~Tone() {
        noTone();
    }
    void _setup(int pin);
    /**
     * 指定された周波数のトーンを出力する
     */
    void tone(unsigned int frequency);
    /**
     * 指定された周波数のトーンをduration(ミリ秒)で指定された時間出力する
     */
    void tone(unsigned int frequency, unsigned long duration);
    /**
     * 出力を停止する
     */
    void noTone(void);

private:
	int	_pin;
};
#endif