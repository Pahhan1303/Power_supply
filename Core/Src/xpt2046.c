#include "xpt2046.h"

//extern SPI_TypeDef XPT2046_SPI;

inline static float remap(float x, float in_min, float in_max, float out_min, float out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void XPT2046_Init(void)
{
	if (XPT2046_NSS_SOFT)	LL_GPIO_ResetOutputPin(XPT2046_NSS_PORT, XPT2046_NSS_PIN);
	while(!LL_SPI_IsActiveFlag_TXE(SPI1)) {}
	LL_SPI_TransmitData8(SPI1, (uint8_t)XPT2046_ADDR_I);
	while(!LL_SPI_IsActiveFlag_RXNE(SPI1)) {}
	while(!LL_SPI_IsActiveFlag_TXE(SPI1)) {}
	LL_SPI_TransmitData8(SPI1, 0x00);
	while(!LL_SPI_IsActiveFlag_RXNE(SPI1)) {}
	while(!LL_SPI_IsActiveFlag_TXE(SPI1)) {}
	LL_SPI_TransmitData8(SPI1, 0x00);
	while(!LL_SPI_IsActiveFlag_RXNE(SPI1)) {}
	if (XPT2046_NSS_SOFT)	LL_GPIO_SetOutputPin(XPT2046_NSS_PORT, XPT2046_NSS_PIN);
}

uint16_t getRaw(uint8_t address)
{
	uint8_t data;
	uint16_t LSB, MSB;
	if (XPT2046_NSS_SOFT)	LL_GPIO_ResetOutputPin(XPT2046_NSS_PORT, XPT2046_NSS_PIN);
	LL_mDelay(1);
	while(!LL_SPI_IsActiveFlag_TXE(SPI1)) {}
	LL_SPI_TransmitData8(SPI1, address);
	while(!LL_SPI_IsActiveFlag_RXNE(SPI1)) {}
	address = 0x00;
	while(!LL_SPI_IsActiveFlag_TXE(SPI1)) {}
	LL_SPI_TransmitData8(SPI1, address);
	while(!LL_SPI_IsActiveFlag_RXNE(SPI1)) {}
	data = LL_SPI_ReceiveData8(SPI1);
	MSB = data;   
	address = 0x00;
	while(!LL_SPI_IsActiveFlag_TXE(SPI1)) {}
	LL_SPI_TransmitData8(SPI1, address);
	while(!LL_SPI_IsActiveFlag_RXNE(SPI1)) {}
	data = LL_SPI_ReceiveData8(SPI1);
	LSB = data;
	if (XPT2046_NSS_SOFT)	LL_GPIO_SetOutputPin(XPT2046_NSS_PORT, XPT2046_NSS_PIN);
	return ((MSB << 8) | (LSB)) >> 3;
}

inline static uint16_t X(void)
{
	uint16_t x;
	x = (uint16_t) remap(getRaw(XPT2046_ADDR_X), RAW_MIN_X, RAW_MAX_X, OUT_MIN_X, OUT_MAX_X);
	if (XPT2046_MIRROR_X) x = OUT_MAX_X - x;
	if (x > OUT_MIN_X && x < OUT_MAX_X) return x;
	else return 0;
}

inline static uint16_t Y(void)
{
	uint16_t y;
	y = (uint16_t) remap(getRaw(XPT2046_ADDR_Y), RAW_MIN_Y, RAW_MAX_Y, OUT_MIN_Y, OUT_MAX_Y);
	if (XPT2046_MIRROR_Y) y = OUT_MAX_Y - y;
	if (y > OUT_MIN_Y && y < OUT_MAX_Y) return y;
	else return 0;
}

uint16_t getX(void)
{
	if (XPT2046_ACCURACY)
	{
		uint16_t x[2] = { 1, 2 };
		while (x[0] != x[1])
		{
			if (XPT2046_REVERSED) { x[0] = Y(); x[1] = Y(); }
			else { x[0] = X(); x[1] = X(); }
		}
		return x[0];
	} 
	else if (XPT2046_REVERSED) return Y(); else return X();
}

uint16_t getY(void)
{
	if (XPT2046_ACCURACY)
	{
		uint16_t y[2] = { 1, 2 };
		while (y[0] != y[1])
		{
			if (XPT2046_REVERSED) { y[0] = X(); y[1] = X(); }
			else { y[0] = Y(); y[1] = Y(); }
		}
		return y[0];
	}
	else if (XPT2046_REVERSED) return X(); else return Y();
}
