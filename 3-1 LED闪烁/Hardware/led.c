#include "stm32f10x.h"
void led_Blue_ON(void){
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);
}

void led_Blue_OFF(void){
	GPIO_SetBits(GPIOA,GPIO_Pin_0);
}

void led_Red_ON(void){
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
}

void led_Red_OFF(void){
	GPIO_SetBits(GPIOA,GPIO_Pin_2);
}

void voice_ON(void){
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
}

void voice_OFF(void){
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
}

void led_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA ,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_2; 
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	//led_Blue_OFF();
	//led_Red_OFF();
	
	
}	

void FMQInit(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB ,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_All; 
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOB,&GPIO_InitStruct);
	voice_OFF();
}



