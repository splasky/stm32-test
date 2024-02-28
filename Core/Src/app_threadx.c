/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    app_threadx.c
  * @author  MCD Application Team
  * @brief   ThreadX applicative file
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

/* Includes ------------------------------------------------------------------*/
#include "app_threadx.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "main.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define THREAD_STACK_SIZE 1024

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
uint8_t thread_stack1[THREAD_STACK_SIZE];
TX_THREAD thread_ptr1;

uint8_t thread_stack2[THREAD_STACK_SIZE];
TX_THREAD thread_ptr2;

uint8_t thread_stack3[THREAD_STACK_SIZE];
TX_THREAD thread_ptr3;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
VOID ld1_thread_entry(ULONG initial_input);
VOID ld2_thread_entry(ULONG initial_input);
VOID ld3_thread_entry(ULONG initial_input);
/* USER CODE END PFP */

/**
  * @brief  Application ThreadX Initialization.
  * @param memory_ptr: memory pointer
  * @retval int
  */
UINT App_ThreadX_Init(VOID *memory_ptr)
{
  UINT ret = TX_SUCCESS;
  /* USER CODE BEGIN App_ThreadX_MEM_POOL */

  /* USER CODE END App_ThreadX_MEM_POOL */
  /* USER CODE BEGIN App_ThreadX_Init */
  tx_thread_create(&thread_ptr1, "LD1_thread", ld1_thread_entry, 0x1234, thread_stack1, THREAD_STACK_SIZE, 15,15,1,TX_AUTO_START);
  tx_thread_create(&thread_ptr2, "LD2_thread", ld2_thread_entry, 0x1234, thread_stack2, THREAD_STACK_SIZE, 15,15,1,TX_AUTO_START);
  tx_thread_create(&thread_ptr3, "LD3_thread", ld3_thread_entry, 0x1234, thread_stack3, THREAD_STACK_SIZE, 15,15,1,TX_AUTO_START);
  /* USER CODE END App_ThreadX_Init */

  return ret;
}

  /**
  * @brief  MX_ThreadX_Init
  * @param  None
  * @retval None
  */
void MX_ThreadX_Init(void)
{
  /* USER CODE BEGIN  Before_Kernel_Start */

  /* USER CODE END  Before_Kernel_Start */

  tx_kernel_enter();

  /* USER CODE BEGIN  Kernel_Start_Error */

  /* USER CODE END  Kernel_Start_Error */
}

/* USER CODE BEGIN 1 */
VOID ld1_thread_entry(ULONG initial_input){
		while(1){
			HAL_GPIO_TogglePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin);
			tx_thread_sleep(10);
		}
}

VOID ld2_thread_entry(ULONG initial_input){
		while(1){
			HAL_GPIO_TogglePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin);
			tx_thread_sleep(20);
		}
}

VOID ld3_thread_entry(ULONG initial_input){
		while(1){
			HAL_GPIO_TogglePin(LED3_RED_GPIO_Port, LED3_RED_Pin);
			tx_thread_sleep(30);
		}
}
/* USER CODE END 1 */
