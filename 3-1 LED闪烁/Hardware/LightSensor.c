#include "stm32f10x.h"
#include "Delay.h"

void LightSensor_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB ,ENABLE); // 初始化时钟
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13; 
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOB,&GPIO_InitStruct);
}

uint8_t LightSensor_Get(void){
	return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13);
}


