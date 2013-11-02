 
#ifndef MBED_WAIT_API_H
#define MBED_WAIT_API_H

#ifdef __cplusplus
extern "C" {
#endif

/* Function: wait_ms
 *  Waits a number of milliseconds.
 *
 * Variables:
 *  ms - the whole number of milliseconds to wait
 */
void wait_ms(int ms);

/* Function: wait_us
 *  Waits a number of microseconds.
 *
 * Variables:
 *  us - the whole number of microseconds to wait
 */
void wait_us(int us);

void wait_init(void);

void wait(double s);

#ifdef __cplusplus
}
#endif

#endif
