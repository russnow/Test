#ifndef MAIN_H
#define MAIN_H

#include "mcu_ini.h"


#include "stm32l1xx_rcc.h"
#include "stm32l1xx_gpio.h"
#include "stm32l1xx_usart.h"

#include "stm32l1xx.h"
#define BLUE_ON()   	GPIO_SetBits(GPIOB, GPIO_Pin_6);
#define BLUE_OFF()  	GPIO_ResetBits(GPIOB, GPIO_Pin_6);
#define GREEN_ON() 		GPIO_SetBits(GPIOB, GPIO_Pin_7);
#define GREEN_OFF() 	GPIO_ResetBits(GPIOB, GPIO_Pin_7);
#define DELAY 				50

#define MODE_BLUE 		0
#define MODE_GREEN		1
	
#define BUTTON_READ()		GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)

#endif
