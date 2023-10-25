/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MCO_Pin GPIO_PIN_0
#define MCO_GPIO_Port GPIOF
#define EN_A_Pin GPIO_PIN_0
#define EN_A_GPIO_Port GPIOA
#define INPUT_A_1_Pin GPIO_PIN_1
#define INPUT_A_1_GPIO_Port GPIOA
#define CS_XL_Pin GPIO_PIN_2
#define CS_XL_GPIO_Port GPIOA
#define INPUT_A_2_Pin GPIO_PIN_3
#define INPUT_A_2_GPIO_Port GPIOA
#define INPUT_B_1_Pin GPIO_PIN_4
#define INPUT_B_1_GPIO_Port GPIOA
#define INPUT_B_2_Pin GPIO_PIN_5
#define INPUT_B_2_GPIO_Port GPIOA
#define CS_MAG_Pin GPIO_PIN_7
#define CS_MAG_GPIO_Port GPIOA
#define XSHUT_Pin GPIO_PIN_0
#define XSHUT_GPIO_Port GPIOB
#define INT_MAG_Pin GPIO_PIN_12
#define INT_MAG_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define VCP_RX_Pin GPIO_PIN_15
#define VCP_RX_GPIO_Port GPIOA
#define SDA_Pin GPIO_PIN_5
#define SDA_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
extern TIM_HandleTypeDef htim3;

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
