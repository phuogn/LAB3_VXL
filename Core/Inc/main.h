/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f1xx_hal.h"

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
#define SEGMENT4B_Pin GPIO_PIN_13
#define SEGMENT4B_GPIO_Port GPIOC
#define SEGMENT5B_Pin GPIO_PIN_14
#define SEGMENT5B_GPIO_Port GPIOC
#define SEGMENT6B_Pin GPIO_PIN_15
#define SEGMENT6B_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_0
#define LED1_GPIO_Port GPIOA
#define LED2_Pin GPIO_PIN_1
#define LED2_GPIO_Port GPIOA
#define LED3_Pin GPIO_PIN_2
#define LED3_GPIO_Port GPIOA
#define LED4_Pin GPIO_PIN_3
#define LED4_GPIO_Port GPIOA
#define LED5_Pin GPIO_PIN_4
#define LED5_GPIO_Port GPIOA
#define LED6_Pin GPIO_PIN_5
#define LED6_GPIO_Port GPIOA
#define LED7_Pin GPIO_PIN_6
#define LED7_GPIO_Port GPIOA
#define LED8_Pin GPIO_PIN_7
#define LED8_GPIO_Port GPIOA
#define MODE_Pin GPIO_PIN_0
#define MODE_GPIO_Port GPIOB
#define TIME_UP_Pin GPIO_PIN_1
#define TIME_UP_GPIO_Port GPIOB
#define TIME_DOWN_Pin GPIO_PIN_2
#define TIME_DOWN_GPIO_Port GPIOB
#define SEGMENT3A_Pin GPIO_PIN_10
#define SEGMENT3A_GPIO_Port GPIOB
#define SEGMENT4A_Pin GPIO_PIN_11
#define SEGMENT4A_GPIO_Port GPIOB
#define SEGMENT5A_Pin GPIO_PIN_12
#define SEGMENT5A_GPIO_Port GPIOB
#define SEGMENT6A_Pin GPIO_PIN_13
#define SEGMENT6A_GPIO_Port GPIOB
#define SEGMENT7A_Pin GPIO_PIN_14
#define SEGMENT7A_GPIO_Port GPIOB
#define SEGMENT3B_Pin GPIO_PIN_15
#define SEGMENT3B_GPIO_Port GPIOB
#define LED9_Pin GPIO_PIN_8
#define LED9_GPIO_Port GPIOA
#define LED10_Pin GPIO_PIN_9
#define LED10_GPIO_Port GPIOA
#define LED11_Pin GPIO_PIN_10
#define LED11_GPIO_Port GPIOA
#define LED12_Pin GPIO_PIN_11
#define LED12_GPIO_Port GPIOA
#define SEGMENT1B_Pin GPIO_PIN_12
#define SEGMENT1B_GPIO_Port GPIOA
#define SEGMENT7B_Pin GPIO_PIN_13
#define SEGMENT7B_GPIO_Port GPIOA
#define SEGMENT2B_Pin GPIO_PIN_15
#define SEGMENT2B_GPIO_Port GPIOA
#define APPLY_Pin GPIO_PIN_3
#define APPLY_GPIO_Port GPIOB
#define LED7A1_Pin GPIO_PIN_4
#define LED7A1_GPIO_Port GPIOB
#define LED7A2_Pin GPIO_PIN_5
#define LED7A2_GPIO_Port GPIOB
#define LED7B1_Pin GPIO_PIN_6
#define LED7B1_GPIO_Port GPIOB
#define LED7B2_Pin GPIO_PIN_7
#define LED7B2_GPIO_Port GPIOB
#define SEGMENT1A_Pin GPIO_PIN_8
#define SEGMENT1A_GPIO_Port GPIOB
#define SEGMENT2A_Pin GPIO_PIN_9
#define SEGMENT2A_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
