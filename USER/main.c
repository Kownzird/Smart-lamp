#include "led.h"
#include "delay.h"
#include "sys.h"
#include "pwm.h"
#include "usart.h"
#include "usart2.h"
#include "rgb.h"
#include "string.h"
#include "stdlib.h"
#include "rgb.h"
#include "ld3320.h"


//u8 nAsrStatus=0;	


int main(void)
 {
	 int i;
	 u16 led_R_pwmval;
	 u16 led_G_pwmval;
	 u16 led_B_pwmval;
	 
	 
	 delay_init();	    	 //延时函数初始化
	 //uart_init(9600);
	 USART2_Init(9600);	
	 LED_Init();
	  
 	 TIM1_CH1_PWM_Init(255,0);	 //不分频。PWM频率=72000000/900=80Khz
	 TIM1_CH4_PWM_Init(255,0);
	 TIM1_CH3_PWM_Init(255,0);
	 
	 
	 
	 for(i=0;i<3;i++)
	 {
		TIM_SetCompare4(TIM1,255);	
		 delay_ms(500);
		 TIM_SetCompare4(TIM1,0);	
		 delay_ms(500);
	 }
	 
	printf("开始进入进入语音识别：\r\n");
	 
	LD3320_main();
	 
	while(1);
	return 0;
	
}
 
