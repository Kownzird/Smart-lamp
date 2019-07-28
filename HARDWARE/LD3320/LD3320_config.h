#ifndef _LD3320_CONFIG_H__
#define _LD3320_CONFIG_H__

///ʶ���루�ͻ��޸Ĵ���
#define CODE_KD	1	 //����
#define CODE_GD	  2	 //�ص�
#define CODE_DLD	3 //������
#define CODE_ZCLD	4	 //��������
#define CODE_GLD	5  //������
#define CODE_LSW	6  //��ɫ��
#define CODE_ZCSW	7  //����ɫ��
#define CODE_NSW	8  //ůɫ��
#define CODE_KQLY	9  //��������
#define CODE_GBLY	10  //�ر�����

//�����������Ŷ���
#define BT_PIN							GPIO_Pin_8
#define BT_GPIO_PORT				GPIOB
#define BT_GPIO_CLK					RCC_APB2Periph_GPIOB



///LED������ض���
#define LED1_PIN							GPIO_Pin_5
#define LED1_GPIO_PORT				GPIOB
#define LED1_GPIO_CLK					RCC_APB2Periph_GPIOB
/*
#define LED2_PIN							GPIO_Pin_8
#define LED2_GPIO_PORT				GPIOB
#define LED2_GPIO_CLK					RCC_APB2Periph_GPIOB

#define LED3_PIN							GPIO_Pin_8
#define LED3_GPIO_PORT				GPIOF
#define LED3_GPIO_CLK					RCC_APB2Periph_GPIOF

#define LED4_PIN							GPIO_Pin_9
#define LED4_GPIO_PORT				GPIOF
#define LED4_GPIO_CLK					RCC_APB2Periph_GPIOF
*/
#define LED1_ON()								GPIO_SetBits(GPIOB,GPIO_Pin_5)
#define BT_ON()								GPIO_SetBits(GPIOB,GPIO_Pin_8)
//#define LED3_ON()								GPIO_SetBits(GPIOF,GPIO_Pin_8)
//#define LED4_ON()								GPIO_SetBits(GPIOF,GPIO_Pin_9)

#define LED1_OFF()							GPIO_ResetBits(GPIOB,GPIO_Pin_5)
#define BT_OFF()							GPIO_ResetBits(GPIOB,GPIO_Pin_8)
//#define LED3_OFF()							GPIO_ResetBits(GPIOF,GPIO_Pin_8)
//#define LED4_OFF()							GPIO_ResetBits(GPIOF,GPIO_Pin_9)

///LD3320������ض���
#define LD3320RST_PIN					GPIO_Pin_15		
#define LD3320RST_GPIO_PORT		GPIOB
#define LD3320RST_GPIO_CLK		RCC_APB2Periph_GPIOB
#define LD_RST_H() 						GPIO_SetBits(GPIOB, GPIO_Pin_15)
#define LD_RST_L() 						GPIO_ResetBits(GPIOB, GPIO_Pin_15)

#define LD3320CS_PIN					GPIO_Pin_4		
#define LD3320CS_GPIO_PORT		GPIOA
#define LD3320CS_GPIO_CLK			RCC_APB2Periph_GPIOA
#define LD_CS_H()							GPIO_SetBits(GPIOA, GPIO_Pin_4)
#define LD_CS_L()							GPIO_ResetBits(GPIOA, GPIO_Pin_4)

#define LD3320IRQ_GPIO_CLK		RCC_APB2Periph_GPIOB
#define LD3320IRQ_PIN					GPIO_Pin_12
#define LD3320IRQ_GPIO_PORT		GPIOB
#define LD3320IRQEXIT_PORTSOURCE		GPIO_PortSourceGPIOB
#define LD3320IRQPINSOURCE		GPIO_PinSource12
#define LD3320IRQEXITLINE			EXTI_Line12
#define LD3320IRQN						EXTI15_10_IRQn

#define LD3320WR_PIN					GPIO_Pin_13
#define LD3320WR_GPIO_PORT		GPIOB
#define LD3320WR_GPIO_CLK			RCC_APB2Periph_GPIOB
#define LD_SPIS_H()  					GPIO_SetBits(GPIOB, GPIO_Pin_13)
#define LD_SPIS_L()  					GPIO_ResetBits(GPIOB, GPIO_Pin_13)

#define	LD3320SPI							SPI1
#define LD3320SPI_CLK					RCC_APB2Periph_SPI1						

#define LD3320SPIMISO_PIN					GPIO_Pin_6
#define LD3320SPIMISO_GPIO_PORT		GPIOA
#define LD3320SPIMISO_GPIO_CLK		RCC_APB2Periph_GPIOA

#define LD3320SPIMOSI_PIN					GPIO_Pin_7
#define LD3320SPIMOSI_GPIO_PORT		GPIOA
#define LD3320SPIMOSI_GPIO_CLK		RCC_APB2Periph_GPIOA

#define LD3320SPISCK_PIN					GPIO_Pin_5
#define LD3320SPISCK_GPIO_PORT		GPIOA
#define LD3320SPISCK_GPIO_CLK			RCC_APB2Periph_GPIOA

#endif
