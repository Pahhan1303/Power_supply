#ifndef _XPT2046_H_
#define _XPT2046_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_spi.h"
#include "stm32f1xx_ll_rcc.h"
#include "stm32f1xx_ll_utils.h"

#define	XPT2046_ACCURACY 	1
#define	XPT2046_REVERSED 	1
#define	XPT2046_MIRROR_X 	0
#define	XPT2046_MIRROR_Y 	0

#define RAW_MIN_X	200
#define RAW_MAX_X	3800
#define OUT_MIN_X	0
#define OUT_MAX_X	239

#define RAW_MIN_Y	300 //400
#define RAW_MAX_Y	3850
#define OUT_MIN_Y	0
#define OUT_MAX_Y	319

//#define	XPT2046_SPI 		SPI1
#define	XPT2046_NSS_SOFT	0
#define	XPT2046_NSS_PORT 	GPIOA
#define	XPT2046_NSS_PIN 	LL_GPIO_PIN_4

#define	XPT2046_ADDR_I 	0x80
#define	XPT2046_ADDR_X 	0xD0
#define	XPT2046_ADDR_Y 	0x90

void XPT2046_Init(void);
uint16_t getRaw(uint8_t address);
uint16_t getX(void);
uint16_t getY(void);

#ifdef __cplusplus
}
#endif

#endif /* _XPT2046_H_ */
