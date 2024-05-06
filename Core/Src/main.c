/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ili9341.h"
#include "xpt2046.h"
#include <stdio.h>

#include "fonts/Font_3_Tiny.h"
#include "fonts/Font_3_PicoPixel.h"
#include "fonts/Font_3_TomThumb_Extended.h"
#include "fonts/Font_5_Org.h"
#include "fonts/Font_8_Sinclair.h"
#include "fonts/Font_8_Sinclair_Inverted.h"
#include "fonts/Font_8_Tiny.h"
#include "fonts/Font_8_Myke.h"
#include "fonts/Font_8_Default.h"
#include "fonts/Font_8_Retro.h"
#include "fonts/Font_9_Mono.h"
#include "fonts/Font_9_Mono_Bold.h"
#include "fonts/Font_9_Mono_Bold_Oblique.h"
#include "fonts/Font_9_Mono_Oblique.h"
#include "fonts/Font_9_Sans.h"
#include "fonts/Font_9_Sans_Bold.h"
#include "fonts/Font_9_Sans_Bold_Oblique.h"
#include "fonts/Font_9_Sans_Oblique.h"
#include "fonts/Font_9_Serif.h"
#include "fonts/Font_9_Serif_Bold.h"
#include "fonts/Font_9_Serif_Bold_Italic.h"
#include "fonts/Font_9_Serif_Italic.h"
#include "fonts/Font_12_Mono.h"
#include "fonts/Font_12_Mono_Bold.h"
#include "fonts/Font_12_Mono_Bold_Oblique.h"
#include "fonts/Font_12_Mono_Oblique.h"
#include "fonts/Font_12_Sans.h"
#include "fonts/Font_12_Sans_Bold.h"
#include "fonts/Font_12_Sans_Bold_Oblique.h"
#include "fonts/Font_12_Sans_Oblique.h"
#include "fonts/Font_12_Serif.h"
#include "fonts/Font_12_Serif_Bold.h"
#include "fonts/Font_12_Serif_Bold_Italic.h"
#include "fonts/Font_12_Serif_Italic.h"
#include "fonts/Font_16_Arial.h"
#include "fonts/Font_16_Arial_Bold.h"
#include "fonts/Font_16_Arial_Italic.h"
#include "fonts/Font_16_Default.h"
#include "fonts/Font_16_FranklinGothic.h"
#include "fonts/Font_16_Hallfetica.h"
#include "fonts/Font_16_Nadianne.h"
#include "fonts/Font_16_Sinclair.h"
#include "fonts/Font_16_Sinclair_Inverted.h"
#include "fonts/Font_16_Swiss_Outline.h"
#include "fonts/Font_16_Matrix_Full.h"
#include "fonts/Font_16_Matrix_Full_Slash.h"
#include "fonts/Font_16_Matrix_Num.h"
#include "fonts/Font_16_Arial_Round.h"
#include "fonts/Font_16_OCR.h"
#include "fonts/Font_16_Segment_16_Full.h"
#include "fonts/Font_16_Grotesk.h"
#include "fonts/Font_16_Grotesk_Bold.h"
#include "fonts/Font_16_Retro.h"
#include "fonts/Font_18_Mono.h"
#include "fonts/Font_18_Mono_Bold.h"
#include "fonts/Font_18_Mono_Bold_Oblique.h"
#include "fonts/Font_18_Mono_Oblique.h"
#include "fonts/Font_18_Sans.h"
#include "fonts/Font_18_Sans_Bold.h"
#include "fonts/Font_18_Sans_Bold_Oblique.h"
#include "fonts/Font_18_Sans_Oblique.h"
#include "fonts/Font_18_Serif.h"
#include "fonts/Font_18_Serif_Bold.h"
#include "fonts/Font_18_Serif_Bold_Italic.h"
#include "fonts/Font_18_Serif_Italic.h"
#include "fonts/Font_24_Matrix_Num.h"
#include "fonts/Font_24_Inconsola.h"
#include "fonts/Font_24_Ubuntu.h"
#include "fonts/Font_24_Ubuntu_Bold.h"
#include "fonts/Font_24_Segment_7_Num.h"
#include "fonts/Font_24_Segment_16_Full.h"
#include "fonts/Font_24_Mono.h"
#include "fonts/Font_24_Mono_Bold.h"
#include "fonts/Font_24_Mono_Bold_Oblique.h"
#include "fonts/Font_24_Mono_Oblique.h"
#include "fonts/Font_24_Grotesk.h"
#include "fonts/Font_24_Grotesk_Bold.h"
#include "fonts/Font_24_Sans.h"
#include "fonts/Font_24_Sans_Bold.h"
#include "fonts/Font_24_Sans_Bold_Oblique.h"
#include "fonts/Font_24_Sans_Oblique.h"
#include "fonts/Font_24_Serif.h"
#include "fonts/Font_24_Serif_Bold.h"
#include "fonts/Font_24_Serif_Bold_Italic.h"
#include "fonts/Font_24_SerifItalic.h"
#include "fonts/Font_32_Dingbats.h"
#include "fonts/Font_32_Special.h"
#include "fonts/Font_32_Calibri_Bold.h"
#include "fonts/Font_32_Arial_Num_Plus.h"
#include "fonts/Font_32_Matrix_Num.h"
#include "fonts/Font_32_Segment_7_Full.h"
#include "fonts/Font_32_Segment_7_Num_Plus.h"
#include "fonts/Font_32_Segment_16_Full.h"
#include "fonts/Font_32_Segment_18_Full.h"
#include "fonts/Font_32_Grotesk.h"
#include "fonts/Font_32_Grotesk_Bold.h"
#include "fonts/Font_40_Segment_16_Full.h"
#include "fonts/Font_48_Battery.h"
#include "fonts/Font_48_Segment_16_Num.h"
#include "fonts/Font_64_Segment_16_Num.h"
#include "fonts/Font_64_Segment_7_Num.h"
//#include "fonts/Font_96_Segment_7_Num.h"
//#include "fonts/Font_96_Segment_16_Num.h"
//#include "fonts/Font_128_Segment_16_Num.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define ADC_sSamp	4
#define ADC_coef	4
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
uint64_t millis = 0;

__IO uint16_t ADC_Data[3] = { 0 };
__IO uint8_t fl_adc;
__IO uint16_t mVolt = 0;
__IO uint16_t mAmp = 0;
__IO uint32_t mWatt = 0;
__IO uint16_t set_mVolt = 0;
__IO uint16_t set_mAmp = 0;

uint8_t touchIRQ = 0;
uint16_t touchX = 0, touchY = 0;

uint8_t scr = 0;
uint8_t l_scr = 254;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_SPI1_Init(void);
static void MX_SPI2_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM4_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
void loop(void);
void mainScr(void);
void settScrInit(void);
void settScr(void);
void writeNum(uint16_t x, uint16_t y, uint32_t num, const GFXfont *font,
		uint32_t color, uint8_t numAfterDot, char lBuff[]);
uint8_t isTouch(uint16_t xWindow, uint16_t yWindow, uint16_t width, uint16_t height);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_AFIO);
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

	/* System interrupt init*/
	NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	/* SysTick_IRQn interrupt configuration */
	NVIC_SetPriority(SysTick_IRQn,
			NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 15, 0));

	/** NOJTAG: JTAG-DP Disabled and SW-DP Enabled
	 */
	LL_GPIO_AF_Remap_SWJ_NOJTAG();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_DMA_Init();
	MX_SPI1_Init();
	MX_SPI2_Init();
	MX_ADC1_Init();
	MX_TIM4_Init();
	MX_TIM3_Init();
	/* USER CODE BEGIN 2 */
	LL_DMA_ConfigTransfer(DMA1, LL_DMA_CHANNEL_1,
			LL_DMA_DIRECTION_PERIPH_TO_MEMORY | LL_DMA_MODE_CIRCULAR
					| LL_DMA_PERIPH_NOINCREMENT | LL_DMA_MEMORY_INCREMENT
					| LL_DMA_PDATAALIGN_HALFWORD | LL_DMA_MDATAALIGN_HALFWORD
					| LL_DMA_PRIORITY_HIGH);
	LL_DMA_ConfigAddresses(DMA1, LL_DMA_CHANNEL_1,
			LL_ADC_DMA_GetRegAddr(ADC1, LL_ADC_DMA_REG_REGULAR_DATA),
			(uint32_t) &ADC_Data, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
	LL_DMA_SetDataLength(DMA1, LL_DMA_CHANNEL_1, 3);
	LL_DMA_EnableIT_TC(DMA1, LL_DMA_CHANNEL_1);
	LL_DMA_EnableIT_TE(DMA1, LL_DMA_CHANNEL_1);
	LL_DMA_EnableChannel(DMA1, LL_DMA_CHANNEL_1);

	LL_ADC_Enable(ADC1);
	uint8_t wait_loop_index = ((LL_ADC_DELAY_ENABLE_CALIB_ADC_CYCLES * 32) >> 1);
	while (wait_loop_index != 0) {
		wait_loop_index--;
	}
	LL_ADC_StartCalibration(ADC1);
	while (LL_ADC_IsCalibrationOnGoing(ADC1) != 0) {
	}

	LL_ADC_REG_StartConversionSWStart(ADC1);
	LL_TIM_EnableIT_UPDATE(TIM3);
	LL_TIM_EnableCounter(TIM3);
	LL_TIM_EnableCounter(TIM4);
	LL_TIM_SetCounter(TIM4, 32767);
	LL_SYSTICK_EnableIT();

	LL_SPI_Enable(SPI1);
	LL_SPI_Enable(SPI2);
	LCD_Init();
	XPT2046_Init();

	char buff_enc[10] = "0";
	char l_buff_enc[10] = "0";

	uint64_t l_touchIRQ = 0;
	uint8_t isPressed = 0;
	uint8_t i;

	uint64_t prev_millis = 0;
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1) {
		uint32_t enc = LL_TIM_GetCounter(TIM4);

		if (isPressed && LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_3))
			isPressed = 0;
		if (millis - l_touchIRQ > 100
				&& !LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_3) && !isPressed) {
			touchX = getX();
			touchY = getY();
			if (touchX && touchY && touchY != 0x0DB) {
				LCD_Rect_Fill(touchX, touchY, 1, 1, WHITE);
				l_touchIRQ = millis;
				touchIRQ = 1;
				isPressed = 1;
			}
			//LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_6);
		}

		if (millis - prev_millis > 100) {
			prev_millis = millis;
			switch (scr) {
			case 0:
				mainScr();
				break;
			case 1:
				if (scr != l_scr) {
					settScrInit();
					l_scr = scr;
				}
				settScr();
				break;
			}

			sprintf(buff_enc, "enc:%ld", enc);
			LCD_FontRw(1, 239, buff_enc, l_buff_enc, _9_Sans, 1, YELLOW,
			BLACK);
			for (i = 0; i < 10; i++)
				l_buff_enc[i] = buff_enc[i];
		}
	}
	/* USER CODE END WHILE */

	/* USER CODE BEGIN 3 */

	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	LL_FLASH_SetLatency(LL_FLASH_LATENCY_2);
	while (LL_FLASH_GetLatency() != LL_FLASH_LATENCY_2) {
	}
	LL_RCC_HSE_Enable();

	/* Wait till HSE is ready */
	while (LL_RCC_HSE_IsReady() != 1) {

	}
	LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE_DIV_1, LL_RCC_PLL_MUL_9);
	LL_RCC_PLL_Enable();

	/* Wait till PLL is ready */
	while (LL_RCC_PLL_IsReady() != 1) {

	}
	LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
	LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_2);
	LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
	LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

	/* Wait till System clock is ready */
	while (LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL) {

	}
	LL_Init1msTick(72000000);
	LL_SetSystemCoreClock(72000000);
	LL_RCC_SetADCClockSource(LL_RCC_ADC_CLKSRC_PCLK2_DIV_6);
}

/**
 * @brief ADC1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_ADC1_Init(void) {

	/* USER CODE BEGIN ADC1_Init 0 */

	/* USER CODE END ADC1_Init 0 */

	LL_ADC_InitTypeDef ADC_InitStruct = { 0 };
	LL_ADC_CommonInitTypeDef ADC_CommonInitStruct = { 0 };
	LL_ADC_REG_InitTypeDef ADC_REG_InitStruct = { 0 };

	LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	/* Peripheral clock enable */
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_ADC1);

	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOA);
	/**ADC1 GPIO Configuration
	 PA0-WKUP   ------> ADC1_IN0
	 PA1   ------> ADC1_IN1
	 PA2   ------> ADC1_IN2
	 */
	GPIO_InitStruct.Pin = LL_GPIO_PIN_0 | LL_GPIO_PIN_1 | LL_GPIO_PIN_2;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/* ADC1 DMA Init */

	/* ADC1 Init */
	LL_DMA_SetDataTransferDirection(DMA1, LL_DMA_CHANNEL_1,
	LL_DMA_DIRECTION_PERIPH_TO_MEMORY);

	LL_DMA_SetChannelPriorityLevel(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PRIORITY_LOW);

	LL_DMA_SetMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MODE_NORMAL);

	LL_DMA_SetPeriphIncMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PERIPH_NOINCREMENT);

	LL_DMA_SetMemoryIncMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MEMORY_INCREMENT);

	LL_DMA_SetPeriphSize(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PDATAALIGN_HALFWORD);

	LL_DMA_SetMemorySize(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MDATAALIGN_HALFWORD);

	/* USER CODE BEGIN ADC1_Init 1 */

	/* USER CODE END ADC1_Init 1 */

	/** Common config
	 */
	ADC_InitStruct.DataAlignment = LL_ADC_DATA_ALIGN_RIGHT;
	ADC_InitStruct.SequencersScanMode = LL_ADC_SEQ_SCAN_ENABLE;
	LL_ADC_Init(ADC1, &ADC_InitStruct);
	ADC_CommonInitStruct.Multimode = LL_ADC_MULTI_INDEPENDENT;
	LL_ADC_CommonInit(__LL_ADC_COMMON_INSTANCE(ADC1), &ADC_CommonInitStruct);
	ADC_REG_InitStruct.TriggerSource = LL_ADC_REG_TRIG_SOFTWARE;
	ADC_REG_InitStruct.SequencerLength = LL_ADC_REG_SEQ_SCAN_ENABLE_3RANKS;
	ADC_REG_InitStruct.SequencerDiscont = LL_ADC_REG_SEQ_DISCONT_DISABLE;
	ADC_REG_InitStruct.ContinuousMode = LL_ADC_REG_CONV_CONTINUOUS;
	ADC_REG_InitStruct.DMATransfer = LL_ADC_REG_DMA_TRANSFER_UNLIMITED;
	LL_ADC_REG_Init(ADC1, &ADC_REG_InitStruct);

	/** Configure Regular Channel
	 */
	LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_0);
	LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_0,
	LL_ADC_SAMPLINGTIME_55CYCLES_5);

	/** Configure Regular Channel
	 */
	LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_2, LL_ADC_CHANNEL_1);
	LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_1,
	LL_ADC_SAMPLINGTIME_55CYCLES_5);

	/** Configure Regular Channel
	 */
	LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_3, LL_ADC_CHANNEL_2);
	LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_2,
	LL_ADC_SAMPLINGTIME_55CYCLES_5);
	/* USER CODE BEGIN ADC1_Init 2 */

	/* USER CODE END ADC1_Init 2 */

}

/**
 * @brief SPI1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_SPI1_Init(void) {

	/* USER CODE BEGIN SPI1_Init 0 */

	/* USER CODE END SPI1_Init 0 */

	LL_SPI_InitTypeDef SPI_InitStruct = { 0 };

	LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	/* Peripheral clock enable */
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI1);

	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOA);
	/**SPI1 GPIO Configuration
	 PA4   ------> SPI1_NSS
	 PA5   ------> SPI1_SCK
	 PA6   ------> SPI1_MISO
	 PA7   ------> SPI1_MOSI
	 */
	GPIO_InitStruct.Pin = LL_GPIO_PIN_4 | LL_GPIO_PIN_5 | LL_GPIO_PIN_7;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LL_GPIO_PIN_6;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_FLOATING;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/* USER CODE BEGIN SPI1_Init 1 */

	/* USER CODE END SPI1_Init 1 */
	/* SPI1 parameter configuration*/
	SPI_InitStruct.TransferDirection = LL_SPI_FULL_DUPLEX;
	SPI_InitStruct.Mode = LL_SPI_MODE_MASTER;
	SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
	SPI_InitStruct.ClockPolarity = LL_SPI_POLARITY_LOW;
	SPI_InitStruct.ClockPhase = LL_SPI_PHASE_1EDGE;
	SPI_InitStruct.NSS = LL_SPI_NSS_HARD_OUTPUT;
	SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV256;
	SPI_InitStruct.BitOrder = LL_SPI_MSB_FIRST;
	SPI_InitStruct.CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE;
	SPI_InitStruct.CRCPoly = 10;
	LL_SPI_Init(SPI1, &SPI_InitStruct);
	/* USER CODE BEGIN SPI1_Init 2 */

	/* USER CODE END SPI1_Init 2 */

}

/**
 * @brief SPI2 Initialization Function
 * @param None
 * @retval None
 */
static void MX_SPI2_Init(void) {

	/* USER CODE BEGIN SPI2_Init 0 */

	/* USER CODE END SPI2_Init 0 */

	LL_SPI_InitTypeDef SPI_InitStruct = { 0 };

	LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	/* Peripheral clock enable */
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_SPI2);

	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOB);
	/**SPI2 GPIO Configuration
	 PB12   ------> SPI2_NSS
	 PB13   ------> SPI2_SCK
	 PB15   ------> SPI2_MOSI
	 */
	GPIO_InitStruct.Pin = LL_GPIO_PIN_12 | LL_GPIO_PIN_13 | LL_GPIO_PIN_15;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/* USER CODE BEGIN SPI2_Init 1 */

	/* USER CODE END SPI2_Init 1 */
	/* SPI2 parameter configuration*/
	SPI_InitStruct.TransferDirection = LL_SPI_FULL_DUPLEX;
	SPI_InitStruct.Mode = LL_SPI_MODE_MASTER;
	SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
	SPI_InitStruct.ClockPolarity = LL_SPI_POLARITY_LOW;
	SPI_InitStruct.ClockPhase = LL_SPI_PHASE_1EDGE;
	SPI_InitStruct.NSS = LL_SPI_NSS_HARD_OUTPUT;
	SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV2;
	SPI_InitStruct.BitOrder = LL_SPI_MSB_FIRST;
	SPI_InitStruct.CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE;
	SPI_InitStruct.CRCPoly = 10;
	LL_SPI_Init(SPI2, &SPI_InitStruct);
	/* USER CODE BEGIN SPI2_Init 2 */

	/* USER CODE END SPI2_Init 2 */

}

/**
 * @brief TIM3 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM3_Init(void) {

	/* USER CODE BEGIN TIM3_Init 0 */

	/* USER CODE END TIM3_Init 0 */

	LL_TIM_InitTypeDef TIM_InitStruct = { 0 };

	/* Peripheral clock enable */
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM3);

	/* TIM3 interrupt Init */
	NVIC_SetPriority(TIM3_IRQn,
			NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 1, 0));
	NVIC_EnableIRQ(TIM3_IRQn);

	/* USER CODE BEGIN TIM3_Init 1 */

	/* USER CODE END TIM3_Init 1 */
	TIM_InitStruct.Prescaler = 35999;
	TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
	TIM_InitStruct.Autoreload = 19;
	TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
	LL_TIM_Init(TIM3, &TIM_InitStruct);
	LL_TIM_DisableARRPreload(TIM3);
	LL_TIM_SetClockSource(TIM3, LL_TIM_CLOCKSOURCE_INTERNAL);
	LL_TIM_SetTriggerOutput(TIM3, LL_TIM_TRGO_UPDATE);
	LL_TIM_DisableMasterSlaveMode(TIM3);
	/* USER CODE BEGIN TIM3_Init 2 */

	/* USER CODE END TIM3_Init 2 */

}

/**
 * @brief TIM4 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM4_Init(void) {

	/* USER CODE BEGIN TIM4_Init 0 */

	/* USER CODE END TIM4_Init 0 */

	LL_TIM_InitTypeDef TIM_InitStruct = { 0 };

	LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	/* Peripheral clock enable */
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM4);

	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOB);
	/**TIM4 GPIO Configuration
	 PB6   ------> TIM4_CH1
	 PB7   ------> TIM4_CH2
	 */
	GPIO_InitStruct.Pin = LL_GPIO_PIN_6 | LL_GPIO_PIN_7;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
	LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/* USER CODE BEGIN TIM4_Init 1 */

	/* USER CODE END TIM4_Init 1 */
	LL_TIM_SetEncoderMode(TIM4, LL_TIM_ENCODERMODE_X2_TI1);
	LL_TIM_IC_SetActiveInput(TIM4, LL_TIM_CHANNEL_CH1,
	LL_TIM_ACTIVEINPUT_DIRECTTI);
	LL_TIM_IC_SetPrescaler(TIM4, LL_TIM_CHANNEL_CH1, LL_TIM_ICPSC_DIV1);
	LL_TIM_IC_SetFilter(TIM4, LL_TIM_CHANNEL_CH1, LL_TIM_IC_FILTER_FDIV16_N5);
	LL_TIM_IC_SetPolarity(TIM4, LL_TIM_CHANNEL_CH1, LL_TIM_IC_POLARITY_RISING);
	LL_TIM_IC_SetActiveInput(TIM4, LL_TIM_CHANNEL_CH2,
	LL_TIM_ACTIVEINPUT_DIRECTTI);
	LL_TIM_IC_SetPrescaler(TIM4, LL_TIM_CHANNEL_CH2, LL_TIM_ICPSC_DIV1);
	LL_TIM_IC_SetFilter(TIM4, LL_TIM_CHANNEL_CH2, LL_TIM_IC_FILTER_FDIV16_N5);
	LL_TIM_IC_SetPolarity(TIM4, LL_TIM_CHANNEL_CH2, LL_TIM_IC_POLARITY_RISING);
	TIM_InitStruct.Prescaler = 0;
	TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
	TIM_InitStruct.Autoreload = 65535;
	TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
	LL_TIM_Init(TIM4, &TIM_InitStruct);
	LL_TIM_EnableARRPreload(TIM4);
	LL_TIM_SetTriggerOutput(TIM4, LL_TIM_TRGO_RESET);
	LL_TIM_DisableMasterSlaveMode(TIM4);
	/* USER CODE BEGIN TIM4_Init 2 */

	/* USER CODE END TIM4_Init 2 */

}

/**
 * Enable DMA controller clock
 */
static void MX_DMA_Init(void) {

	/* Init with LL driver */
	/* DMA controller clock enable */
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);

	/* DMA interrupt init */
	/* DMA1_Channel1_IRQn interrupt configuration */
	NVIC_SetPriority(DMA1_Channel1_IRQn,
			NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0, 0));
	NVIC_EnableIRQ(DMA1_Channel1_IRQn);

}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {
	LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	/* USER CODE BEGIN MX_GPIO_Init_1 */
	/* USER CODE END MX_GPIO_Init_1 */

	/* GPIO Ports Clock Enable */
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOC);
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOD);
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOA);
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOB);

	/**/
	LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_13);

	/**/
	LL_GPIO_ResetOutputPin(LCD_DC_GPIO_Port, LCD_DC_Pin);

	/**/
	GPIO_InitStruct.Pin = LL_GPIO_PIN_13;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	LL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	/**/
	GPIO_InitStruct.Pin = TOUCH_IRQ_Pin;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
	LL_GPIO_Init(TOUCH_IRQ_GPIO_Port, &GPIO_InitStruct);

	/**/
	GPIO_InitStruct.Pin = LCD_DC_Pin;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	LL_GPIO_Init(LCD_DC_GPIO_Port, &GPIO_InitStruct);

	/* USER CODE BEGIN MX_GPIO_Init_2 */
	/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
#define yBase_v	39
#define yBase_a	yBase_v + 38
#define yBase_w	yBase_a + 38
#define xOffset	153 + 2

void mainScr(void) {
	static uint8_t subScr = 0;
	static uint8_t l_subScr = 254;

	uint8_t i;
	static uint32_t color;

	static char l_buff_v[6];
	static char l_buff_a[6];
	static char l_buff_w[6];
	static char l_buff_setv[6];
	static char l_buff_seta[6];

	static uint64_t changeColorT;

	if (scr != l_scr) {
		LCD_Rect_Fill(0, 0, 320, 240, BLACK);
		LCD_Rect(0, 0, 320, 240, 1, BLUE);

		LCD_Font(122 + xOffset, yBase_v - 2, "V", _18_Sans, 1, GREEN);
		LCD_Font(122 + xOffset, yBase_a - 2, "A", _18_Sans, 1, YELLOW);

		LCD_Font(122, yBase_v - 2, "V", _18_Sans, 1, GREEN);
		LCD_Font(122, yBase_a - 2, "A", _18_Sans, 1, YELLOW);
		LCD_Font(122, yBase_w - 2, "W", _18_Sans, 1, MAGENTA);

		for (i = 0; i < 5; i++) {
			l_buff_v[i] = 0;
			l_buff_a[i] = 0;
			l_buff_w[i] = 0;
		}
		subScr = 0;
		l_subScr = 254;
		l_scr = scr;
	}

	if (subScr != l_subScr) {
		for (i = 0; i < 5; i++) {
			l_buff_setv[i] = 0;
			l_buff_seta[i] = 0;
		}
		writeNum(xOffset, yBase_v, set_mVolt, _24_Segment_7_Num, GREEN, 2,
				l_buff_setv);
		writeNum(xOffset, yBase_a, set_mAmp, _24_Segment_7_Num, YELLOW, 3,
				l_buff_seta);

		color = BLACK;
		l_subScr = subScr;
	}

	writeNum(2, yBase_v, mVolt, _24_Segment_7_Num, GREEN, 2, l_buff_v);
	writeNum(2, yBase_a, mAmp, _24_Segment_7_Num, YELLOW, 3, l_buff_a);

	switch (subScr) {
	case 0:
		if (isTouch(xOffset, 0, xOffset, 38)) {
			subScr = 1;
			touchIRQ = 0;
		} else if (isTouch(xOffset, yBase_v, xOffset, 38)) {
			subScr = 2;
			touchIRQ = 0;
		}
		break;
	case 1:

		if (millis - changeColorT > 500) {
			if (color == BLACK) {
				color = GREEN;
			} else {
				color = BLACK;
				LCD_Font(xOffset, yBase_v, l_buff_setv, _24_Segment_7_Num, 1,
						BLACK);
				for (i = 0; i < 5; i++)
					l_buff_setv[i] = 0;

			}
			changeColorT = millis;
		}
		if (color == GREEN) {
			writeNum(xOffset, yBase_v, set_mVolt, _24_Segment_7_Num, color, 2,
					l_buff_setv);

		}
		if (isTouch(xOffset, 0, xOffset, 38)) {
			subScr = 0;
			touchIRQ = 0;
		}
		break;
	case 2:
		if (millis - changeColorT > 500) {
			if (color == BLACK) {
				color = YELLOW;
			} else {
				color = BLACK;
				LCD_Font(xOffset, yBase_a, l_buff_seta, _24_Segment_7_Num, 1,
						BLACK);
				for (i = 0; i < 5; i++)
					l_buff_seta[i] = 0;
			}
			changeColorT = millis;
		}
		if (color == YELLOW) {
			writeNum(xOffset, yBase_a, set_mAmp, _24_Segment_7_Num, color, 3,
					l_buff_seta);

		}
		if (isTouch(xOffset, yBase_v, xOffset, 38)) {
			subScr = 0;
			touchIRQ = 0;
		}
		break;
	}

	if (mWatt < 10000)
		writeNum(2, yBase_w, mWatt, _24_Segment_7_Num, MAGENTA, 3, l_buff_w);
	else if (mWatt < 100000)
		writeNum(2, yBase_w, mWatt, _24_Segment_7_Num, MAGENTA, 2, l_buff_w);
	else
		writeNum(2, yBase_w, mWatt, _24_Segment_7_Num, MAGENTA, 1, l_buff_w);
	if (isTouch(270, 190, 50, 50)) {
		scr = 1;
		touchIRQ = 0;
	}
}

void settScrInit(void) {
	LCD_Rect_Fill(0, 0, 320, 240, BLACK);
}

void settScr(void) {
	char buff[6];
	sprintf(buff, "hello");
	LCD_Font(0, 193, buff, _9_Sans, 1, MAGENTA);
	if (isTouch(270, 190, 50, 50)) {
		scr = 0;
		touchIRQ = 0;
	}
}

void writeNum(uint16_t x, uint16_t y, uint32_t num, const GFXfont *font,
		uint32_t color, uint8_t numAfterDot, char lBuff[]) {
	char buff[6] = "0";
	if (numAfterDot == 1) {
		sprintf(buff, "%03ld.%01ld", num / 1000, (num % 1000) / 100);

	} else if (numAfterDot == 2) {
		sprintf(buff, "%02ld.%02ld", num / 1000, (num % 1000) / 10);

	} else if (numAfterDot == 3) {
		sprintf(buff, "%01ld.%03ld", num / 1000, num % 1000);

	}

	LCD_FontRw(x, y, buff, lBuff, font, 1, color,
	BLACK);
	memcpy((void*) lBuff, (void*) buff, (sizeof(char) * 5));
}

uint8_t isTouch(uint16_t xWindow, uint16_t yWindow, uint16_t width, uint16_t height) {
	if (touchIRQ && touchX > xWindow && touchX < xWindow + width
			&& touchY > yWindow && touchY < yWindow + height)
		return 1;
	else
		return 0;
}

void TIM3_Callback(void) {
	if (LL_TIM_IsActiveFlag_UPDATE(TIM3)) {
		LL_TIM_ClearFlag_UPDATE(TIM3);

		LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_13);

		uint16_t ADC_filt[3] = { 0 };
		for (uint8_t i = 0; i < ADC_sSamp; i++) {
			fl_adc = 0;
			while (!fl_adc) {
			}
			ADC_filt[0] += ADC_Data[0];
			ADC_filt[1] += ADC_Data[1];
			ADC_filt[2] += ADC_Data[2];
		}
		ADC_filt[0] /= ADC_sSamp;
		ADC_filt[1] /= ADC_sSamp;
		ADC_filt[2] /= ADC_sSamp;

		mVolt += ((ADC_filt[0] * 8) - mVolt) >> ADC_coef;
		mAmp += ((ADC_filt[1] * 2) - mAmp) >> ADC_coef;
		mWatt = (mVolt * mAmp) / 1000;

		LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_13);
	}
}

void ADC_DMA_TransferComplete_Callback() {
	fl_adc = 1;
}

void SysTick_Callback() {
	millis++;
}
/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	while (1) {
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
