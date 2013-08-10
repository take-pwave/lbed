#ifndef LPCDEVICE_H_
#define LPCDEVICE_H_


#if __USE_CMSIS == CMSISv2p00_LPC13xx
#include "LPC13xx.h"
#elif __USE_CMSIS == CMSISv2p00_LPC11xx
#include "LPC11xx.h"
#else
#include "default.h"
#endif

#endif /* LPCDEVICE_H_ */
