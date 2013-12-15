#ifndef LBED_TICKER_H
#define LBED_TICKER_H

/**
 * Ticker
 *
 * The Ticker interface is used to setup a recurring interrupt to repeatedly
 * call a function at a specified rate.
 */
// 今回の実装は、タイマーをTimer0A、1個固定とした。
class Ticker
{
private:
public:
	Ticker();
	/**
	 * Attach a function to be called by the Ticker , specifiying the interval in seconds.
	 */
	void 	 attach(void(*fptr)(void), float t);
	/**
	 * Detach the function.
	 */
	void 	 detach();
protected:
	float			_period;
	unsigned long	_scale;	// prescle factor init_timer16PWMのperiodがSysclock/1000を超えたときに1000にする。デフォルト1
};
#endif
