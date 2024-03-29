/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */


/*
 *
 *  Chrono v2.0
 changelog:
 0.2 probably working sensors
 0.3 working settings
 0.4 battery state pointer
 0.5 working chronograph(only minutes and seconds- without decimals)
 0.6 working low stop mode
 0.7 working new V2 display
 0.8 working sensors!
 0.9 now you cant change layouts and color schemes
 1.0 now sleeps also in chrono mode
 1.0.1 added dontSleepFlag
 1.1 new interface
 1.1.1 better pressure reading- compare
 1.2 properly working chronograph
 1.3 working humidity sensor
 1.3.1 reverted normal pressure reading
 1.3.2 sensor read optimization
 1.3.4 correct order of set time HAL functions
 1.3.5 better power consumption
 1.3.6 correct battery reading
 1.3.7 fixed stuck at button press
 1.3.8 better pressure pointer
 1.4 new settings. corrected GUI Paint
 1.5 working chrono, finally. added halfHour counter.
 1.5.1 chrono halfHours fix.
 1.5.2 longer wake up times, faster SPI
 1.5.3 new layout
 1.5.4 long wake up as init, systick suspend
 1.5.4 more volatile variables
 1.5.5 corrected button interrupt - else if :/
 1.5.6 mode as volatile...\
 1.6 more clean code
 1.7 changed gTime to sTime
 1.7.1 better battery management
 1.8 added altimeter and temp compensation
 1.9 better button management
 2.0 added compass
 2.0.1 - better magnetometer reading
 2.0.2 - better chrono(added date counting)
 2.0.3 - magnetometer correction for new pcb
 2.0.4 properly display minus temperatures
 2.0.5 fixed bad button reading
 2.0.6 mode backup
 2.0.7 better lifetime
 2.1 new sensor, new layouts
 2.2 working meter
 2.21 constant voltage correction switched to gain
 2.3 added dont sleep 10sedonds after release reset.
 2.4 added button lock
 2.5 calling clock config after cutton press
 2.6 better buttons work, customized for touch buttons, autolock if underwater
 2.7 fixes, auto close settings, Status LED- ready for touch sensors
 2.7.1 refresh at automatic settings close
 2.7.2 turn off chrono if it starts under water
 2.7.3 properly set layout and color scheme after setting auto-close
 2.7.4 increased magnetometer divider
 2.8 added moon phase
 2.8.1 corrected moon phase
 3.0 - autocalibrating compass, new analog interface for compass
 3.1 - better lock indicator
 3.11 - better lifetime
 3.2- dont refresh screen if battery is low
 3.3 -added flash backup
 3.4 - properly working chronograph
 3.4.1 -corrected flagBatteryLow flag name

 todo:
 -already did


 -fast seconds refresh holding reset button

 -chronograph not enough precised
 -low power modes-working modes(second synchro/minute synchro)
 EPD sleep
 -sleep and 1Hz refresh if chrono working
 -sleep and 0,2Hz refresh if chrono stop(wakeUp Counter)
 -working sensors
 -chronograph for decimals
 -make choro decimals to display 0 if chrono working
 -program battery alert and safety sleep.
 -fix cut date frame by date number
 loosen interfaceDrawIndex

 exit settings if underwater
 auto exit settings
 enter settings only in long press


 current consumption:
 idle: 8.64mA
 stop mode: 0,1mA



 PCB changelog
 0.5.2 - ring and base fitted to new V2 display
 0.5.3 - wider holes spacing
 0.5.6 - taller FFC connector-in case for too short display stripe
 1.0 - added meter connector, new charger, new magnetometer


 instructions:

 press start to start chrono
 press start to stop the chrono
 press start during chrono working, to resume counting
 press reset to reset chrono
 hold reset for fast refresh
 hold reset and press set to full refresh
 press set to go to settings


 in settings:

 press set to exit settings
 press reset to go next value
 press start to increment current value
 holding start, press and hold set. holding set button, press start to decrement value
 *
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Display_EPD/EPD_1in54_V2.h"
#include "Display_Config/DEV_Config.h"
#include "Display_GUI/GUI_Paint.h"

#include "interface.h"
#include "rtc.h"
#include "settings.h"
#include "buttons.h"
#include "sensing.h"
#include "timers.h"

#include <stdlib.h>

#include "EEPROM_Emul/eeprom_emul.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
 ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

I2C_HandleTypeDef hi2c1;

RTC_HandleTypeDef hrtc;

SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim3;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_I2C1_Init(void);
static void MX_ADC1_Init(void);
static void MX_RTC_Init(void);
static void MX_SPI1_Init(void);
static void MX_TIM3_Init(void);
static void MX_CRC_Init(void);
/* USER CODE BEGIN PFP */
void onSleep(void);
void onWakeUp(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_I2C1_Init();
  MX_ADC1_Init();
  MX_RTC_Init();
  MX_SPI1_Init();
  MX_TIM3_Init();
  MX_CRC_Init();
  /* USER CODE BEGIN 2 */

	//EPD test
	//EPD_1in54_V2_test();
	//										INITIALISATION
	//										RTC INITIALISATION
	rtcInit();

	//										SENSORS INITIALISATION

	sensingInit();

	//										TIMERS INITIALISATION
	timersInit();

	//										INTERFACE

	while (flagBatteryLow) {
		onSleep();
		onWakeUp();

		sensingRead();
	}

	layout = 2;  //select startup layout and color
	colorScheme = COLOR_SCHEME_BLACK;

	flagClockConfig = 0;

	interfaceSelectLayout(layout);  //set layout and color
	interfaceSelectColorScheme(colorScheme);
	interfaceInit();

	interfaceClear();	//clear framebuffer

	interfaceUpdate(INTERFACE_UPDATE_FULL);	//change update mode

	interfaceDrawLayer(1);
	interfaceDrawLayer(2);
	interfaceDrawLayer(3);

	interfaceWrite();

	//										FLASH RESTORE SECTION

	flashWriteFlag = 0;
	uint16_t virtualAdress[NB_OF_VARIABLES];
	uint16_t timeBackup[3];

	for (uint8_t varIndex = 1; varIndex <= 3; varIndex++) {
		virtualAdress[varIndex - 1] = varIndex;
	}

	HAL_FLASH_Unlock();

	uint8_t flashStatus = EE_Init(EE_CONDITIONAL_ERASE);

	if(flashStatus == EE_WRITE_ERROR){
		EE_Format(EE_CONDITIONAL_ERASE);
		flashStatus = EE_Init(EE_CONDITIONAL_ERASE);
	}

	if (flashStatus != EE_OK) {
		Error_Handler();
	}

	for (uint8_t i = 0; i < 3; i++) {
		if(EE_ReadVariable16bits(virtualAdress[i], &timeBackup[i])!= EE_OK){
//			Error_Handler();
		}
	}

	HAL_FLASH_Lock();

	actual.year = (uint8_t) (timeBackup[0] >> 8);
	actual.month = (uint8_t) (timeBackup[0]);

	actual.day = (uint8_t) (timeBackup[1] >> 8);
	actual.hour = (uint8_t) (timeBackup[1]);

	actual.minute = (uint8_t) (timeBackup[2] >> 8);
	actual.second = (uint8_t) (timeBackup[2]);

	if (actual.year > 100)
		actual.year = 20;
	if (actual.month > 12)
		actual.month = 4;
	if (actual.day > 31)
		actual.day = 20;
	if (actual.hour > 24)
		actual.hour = 10;
	if (actual.minute > 59)
		actual.minute = 0;
	if (actual.second > 59)
		actual.second = 0;

	rtcSetTime();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  //									MAIN LOOP

	  		if (flagClockConfig == 1) {
	  			SystemClock_Config();
	  			flagClockConfig = 0;
	  		}

	  		//									SENSING SECTION
	  		sensingRead();

	  		//									RTC SECTION
	  		rtcGetTime();


	  		//									FLASH BACKUP SECTION
	  		if (flashWriteFlag == 1) {

	  			timeBackup[0] = (((uint16_t) actual.year) << 8) | actual.month;
	  			timeBackup[1] = (((uint16_t) actual.day) << 8) | actual.hour;
	  			timeBackup[2] = (((uint16_t) actual.minute) << 8)
	  					| actual.second;

	  			HAL_FLASH_Unlock();

	  			if (EE_Init(EE_CONDITIONAL_ERASE) != EE_OK) {
	  				Error_Handler();
	  			}

	  			for (uint8_t i = 0; i < 3; i++) {
	  				if(EE_WriteVariable16bits(virtualAdress[i], timeBackup[i])!= EE_OK){
	  					Error_Handler();
	  				}

	  			}

	  			HAL_FLASH_Lock();

	  			flashWriteFlag = 0;
	  		}

	  		//									BATTERY SECURE SECTION

	  		while (flagBatteryLow) {

	  			if (!flagBatteryWarningPrinted) {
	  				interfaceDrawBatteryWarning();
	  				mode = MODE_NORMAL;
	  				flagBatteryWarningPrinted = 1;
	  			}

	  			onSleep();
	  			onWakeUp();

	  			sensingRead();
	  		}

	  		//									DISPLAY REFRESH SECTION
	  		if (interfaceUpdateMode == INTERFACE_UPDATE_FULL) {	//switch to partial if full was selected
	  			interfaceUpdate(INTERFACE_UPDATE_PARTIAL);
	  		}
	  		if (flagInterfaceFullUpdate == 1) {	//switch to full if flag are active. Flag can be set via RESET button
	  			interfaceUpdate(INTERFACE_UPDATE_FULL);
	  			flagInterfaceFullUpdate = 0;
	  		}

	  		//									NORMAL MODE
	  		if (flagSettings == FLAG_SETTINGS_OFF && !flagBatteryLow) {

	  			interfaceClear();	//clear framebuffer
	  			interfaceDrawLayer(1);
	  			interfaceDrawLayer(2);
	  			interfaceDrawLayer(3);
	  			interfaceWrite();	//burn framebuffer

	  			//								SETTINGS MODE

	  		} else if (flagSettings == FLAG_SETTINGS_ON && !flagBatteryLow) {

	  			interfaceClear();	//clear framebuffer
	  			settingsDrawSubs(); //draw settings interface
	  			settingsDrawData();
	  			settingsDrawPointer();
	  			interfaceWrite();	//burn framebuffer

	  		}

	  		//									LOW POWER SECTION-SLEEP

	  		//conditions for sleep mode
	  		if ((flagSettings == FLAG_SETTINGS_OFF //settings off
	  		&& flagDontSleep != 1 //dont sleep flag inactive
	  		&& HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin) == 1) //reset dont pressed
	  		&& !(mode == MODE_CHRONO && chrono.minute < 1) //if chrono counts more than 1 minute
	  				&& LPMode == 1 //if low power mode active
	  				&& counterForce >= ON_TIME) { //force timer inactive

	  			//to do before sleep mode
	  			onSleep();
	  			//to do after wake up
	  			onWakeUp();
	  		}

	  		flagDontSleep = 0; // is set via another button, for fast display refresh after pressing
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV1;
  RCC_OscInitStruct.PLL.PLLN = 8;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SEQ_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.LowPowerAutoPowerOff = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.NbrOfConversion = 3;
  hadc1.Init.DiscontinuousConvMode = ENABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.Overrun = ADC_OVR_DATA_OVERWRITTEN;
  hadc1.Init.SamplingTimeCommon1 = ADC_SAMPLETIME_19CYCLES_5;
  hadc1.Init.SamplingTimeCommon2 = ADC_SAMPLETIME_19CYCLES_5;
  hadc1.Init.OversamplingMode = DISABLE;
  hadc1.Init.TriggerFrequencyMode = ADC_TRIGGER_FREQ_HIGH;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLINGTIME_COMMON_1;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_REGULAR_RANK_2;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_5;
  sConfig.Rank = ADC_REGULAR_RANK_3;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief CRC Initialization Function
  * @param None
  * @retval None
  */
static void MX_CRC_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* Peripheral clock enable */
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_CRC);

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  LL_CRC_SetInputDataReverseMode(CRC, LL_CRC_INDATA_REVERSE_NONE);
  LL_CRC_SetOutputDataReverseMode(CRC, LL_CRC_OUTDATA_REVERSE_NONE);
  LL_CRC_SetPolynomialCoef(CRC, LL_CRC_DEFAULT_CRC32_POLY);
  LL_CRC_SetPolynomialSize(CRC, LL_CRC_POLYLENGTH_32B);
  LL_CRC_SetInitialData(CRC, LL_CRC_DEFAULT_CRC_INITVALUE);
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x10707DBC;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef sDate = {0};

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */

  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutRemap = RTC_OUTPUT_REMAP_NONE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  hrtc.Init.OutPutPullUp = RTC_OUTPUT_PULLUP_NONE;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN Check_RTC_BKUP */

  /* USER CODE END Check_RTC_BKUP */

  /** Initialize RTC and set the Time and Date
  */
  sTime.Hours = 10;
  sTime.Minutes = 10;
  sTime.Seconds = 0;
  sTime.SubSeconds = 0;
  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  sTime.StoreOperation = RTC_STOREOPERATION_RESET;
  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
  sDate.WeekDay = RTC_WEEKDAY_TUESDAY;
  sDate.Month = RTC_MONTH_APRIL;
  sDate.Date = 20;
  sDate.Year = 20;

  if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }

  /** Enable the WakeUp
  */
  if (HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, 60, RTC_WAKEUPCLOCK_CK_SPRE_16BITS) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 3199;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 19999;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, SPI_CS_Pin|DC_Pin|RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(STATUS_GPIO_Port, STATUS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : START_Pin SET_Pin RESET_Pin */
  GPIO_InitStruct.Pin = START_Pin|SET_Pin|RESET_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SPI_CS_Pin DC_Pin RST_Pin */
  GPIO_InitStruct.Pin = SPI_CS_Pin|DC_Pin|RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : BUSY_Pin */
  GPIO_InitStruct.Pin = BUSY_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(BUSY_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : STATUS_Pin */
  GPIO_InitStruct.Pin = STATUS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(STATUS_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI2_3_IRQn, 2, 0);
  HAL_NVIC_EnableIRQ(EXTI2_3_IRQn);

  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 2, 0);
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

}

/* USER CODE BEGIN 4 */
void onSleep(void) {
	//			EPD_1IN54_V2_Sleep();
	//			DEV_Module_Exit();
	HAL_GPIO_WritePin(STATUS_GPIO_Port, STATUS_Pin, 0);
	HAL_SuspendTick();
	HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
	//			HAL_PWR_EnterSTOPMode(PWR_MAINREGULATOR_ON, PWR_STOPENTRY_WFI);
}
void onWakeUp(void) {
	HAL_ResumeTick();
	SystemClock_Config();
	HAL_GPIO_WritePin(STATUS_GPIO_Port, STATUS_Pin, 1);
//	HAL_ADC_Start_DMA(&hadc1, (uint32_t*) adcReading, 3);
	//			DEV_Module_Init();
	//			interfaceUpdate(INTERFACE_UPDATE_PARTIAL);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
