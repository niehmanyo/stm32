#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "led.h"
#include "OLED.h"

typedef struct {
	int x; 
	int y;
} struct_t; 

typedef enum {
	MONDAY = 1,
	TUESDAY = 2
} week;

void ligth_and_scring(){
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	Delay_ms(500);
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
	GPIO_SetBits(GPIOA,GPIO_Pin_2);
	Delay_ms(500);
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	Delay_ms(500);
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
	GPIO_SetBits(GPIOA,GPIO_Pin_2);
	Delay_ms(500);
}

void Ultraman(void){
	led_Init();
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	GPIO_SetBits(GPIOA,GPIO_Pin_2);
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
	Delay_s(5);
	GPIO_SetBits(GPIOA,GPIO_Pin_0);
	while(1){
		ligth_and_scring();
		
	}
}
void Red_and_Blue(){
		led_Blue_OFF();
		led_Red_ON();
		Delay_s(1);
		led_Blue_ON();
		led_Red_OFF();
		Delay_s(1);
}

int main(void){
	led_Init();
	OLED_Init();
	OLED_ShowChar(1,1,'A');
	
	OLED_ShowString(1,3,"Damn Crazy!");
	//FMQInit();
	//LightSensor_Init();
	/*
	
	led_Blue_OFF();
		led_Red_ON();
		voice_ON();
		Delay_s(1);
		led_Blue_ON();
		led_Red_OFF();
		//voice_OFF();
		Delay_s(1);
	*/
	Red_and_Blue();
	while(1){
		
		
	}
	
}
