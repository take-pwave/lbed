 
#ifndef MBED_WAIT_API_H
#define MBED_WAIT_API_H

#ifdef __cplusplus
extern "C" {
#endif
/* wait APIの初期化 */
void wait_init();
/* msで与えられたミリ秒待つ */
void wait_ms(int ms);
/* 仮のビジーウェイト版 */
void wait_us(int us);


#ifdef __cplusplus
}
#endif

#endif
