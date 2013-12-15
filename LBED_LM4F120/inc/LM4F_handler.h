#ifndef LBED_HANDLER_H
#define LBED_HANDLER_H
#ifdef __cplusplus
extern "C" {
#endif

extern void Timer0AIntHandler(void);
extern void setUserTimer0AFunc(void (*func)(void));
extern void clearUserTimer0AFunc();

#ifdef __cplusplus
}
#endif

#endif
