/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"
#include "stm32g0xx_ll_crc.h"
#include "stm32g0xx_ll_bus.h"
#include "stm32g0xx_ll_cortex.h"
#include "stm32g0xx_ll_rcc.h"
#include "stm32g0xx_ll_system.h"
#include "stm32g0xx_ll_utils.h"
#include "stm32g0xx_ll_pwr.h"
#include "stm32g0xx_ll_gpio.h"
#include "stm32g0xx_ll_dma.h"

#include "stm32g0xx_ll_exti.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PASSIVE_Pin GPIO_PIN_0
#define PASSIVE_GPIO_Port GPIOA
#define BATT_Pin GPIO_PIN_1
#define BATT_GPIO_Port GPIOA
#define START_Pin GPIO_PIN_2
#define START_GPIO_Port GPIOA
#define START_EXTI_IRQn EXTI2_3_IRQn
#define SET_Pin GPIO_PIN_3
#define SET_GPIO_Port GPIOA
#define SET_EXTI_IRQn EXTI2_3_IRQn
#define RESET_Pin GPIO_PIN_4
#define RESET_GPIO_Port GPIOA
#define RESET_EXTI_IRQn EXTI4_15_IRQn
#define ACTIVE_Pin GPIO_PIN_5
#define ACTIVE_GPIO_Port GPIOA
#define SPI_CS_Pin GPIO_PIN_8
#define SPI_CS_GPIO_Port GPIOA
#define DC_Pin GPIO_PIN_9
#define DC_GPIO_Port GPIOA
#define RST_Pin GPIO_PIN_10
#define RST_GPIO_Port GPIOA
#define BUSY_Pin GPIO_PIN_12
#define BUSY_GPIO_Port GPIOA
#define STATUS_Pin GPIO_PIN_6
#define STATUS_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
extern uint16_t batteryVoltageMinimum;

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */