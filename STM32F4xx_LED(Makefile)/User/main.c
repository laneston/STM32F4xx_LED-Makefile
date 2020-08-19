/**
  ******************************************************************************
  * @author  Lanceli
  * @version V1.0.1
  * @date    09-May-2020
  * @brief   Project entrance.
  *          
  ******************************************************************************
  * @attention
  * This project is for learning only. If it is for commercial use, please contact the author.
  *
  * website:developerlab.cn
  *
  * Copyright (c) 2020 Lanceli All rights reserved.
  ******************************************************************************
  */
	
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup Template_Project
  * @{
  */
	
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
	DelayTimer_Init(TIM2_Period);
	led_init();
	
	while(1)
	{
		led_conversion(LED1);
		Delay_ms(500);
	}
}

/*End of file*********************************************/
