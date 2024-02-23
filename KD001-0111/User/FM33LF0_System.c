#include "FM33LF0_System.h"
#include "Macro_definition.h"
#include "fm33lf0xx_fl_conf.h"
#include "fm33lf0xx.h"
#include "Keyboard_api.h"
#include "FM33LF0_IIC.h"
#include "Lcd_api.h"


/*
** Clear SRAM
** 0x2000 0000 - 0x2000 1FFF 8KB SRAM
*/
void ClearSRAM(void)
{
	uint32_t i, l;
	l = __get_MSP();
	l = (l & 0x00001FFF) / 4;
	i = 0;
	do{
		((uint32_t *)SRAM_BASE)[i] = 0;
		i++;
	}while(i < l);
}

void SYS_CLOCK_Init(void)
{
	if((CMU->RCHFCR & CMU_RCHFCR_EN_Msk) == 0)
	{
	  CMU->RCHFCR |= CMU_RCHFCR_EN_Msk;
	}
	CMU->RCHFCR |= FL_CMU_RCHF_FREQUENCY_32MHZ;
	CMU->RCHFTR = RCHF32M_LDT_TRIM;
	__NOP();
	__NOP();
	__NOP();
	//AHB Clock: 32MHz
	CMU->SYSCLKCR &= ~(CMU_SYSCLKCR_STCLKSEL_Msk + CMU_SYSCLKCR_AHBPRES_Msk + CMU_SYSCLKCR_APBPRES_Msk);
	//APB Clock: 2MHz = 32MHz / 16
	CMU->SYSCLKCR |= (FL_CMU_APBCLK_PSC_DIV16 + CMU_SYSCLKCR_SLP_ENEXTI_Msk);
	//RCLP校准
	CMU->RCLPTR = *(uint32_t *)0x1FFFFB20;
	
	CMU->PCLKCR1 |= FL_CMU_GROUP1_BUSCLK_PAD;	
	
	//Flash配置
	FLASH->RDCR |= FL_FLASH_READ_WAIT_1CYCLE;
	FLASH->PFCR |= FLASH_PFCR_PRFTEN_Msk;
	
	//看门狗
	CMU->PCLKCR1 |= 0x20U;      
  IWDT->SERV = IWDT_RELOAD_KEY;
	IWDT->CR = 0x807;
}


void KEY_GPIO(void)
{
	//PA15为中断输入11000000
	GPIO->EXTISEL = 0xC0;
	
	GPIO->EXTIEDS = 0xFFFFFF7F;
	GPIO->EXTIDF = 0x08;
	
	//休眠使能外部中断采样
	CMU->SYSCLKCR |= CMU_SYSCLKCR_SLP_ENEXTI_Msk;
	CMU->OPCER1 |= FL_CMU_GROUP1_OPCLKEN_EXTI ;
	CMU->OPCCR1 |= CMU_OPCCR1_EXTICKS_Msk;
	
	GPIO->EXTISEL |= (FL_GPIO_EXTI_INPUT_GROUP3 << 6U);
	GPIO->EXTIDF |= FL_GPIO_EXTI_LINE_3;
	GPIO->EXTIEDS |= 0xFFFFFF7F;
	GPIO->EXTIISR |= FL_GPIO_EXTI_LINE_3;
	NVIC->ICPR[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)GPIO_IRQn) & 0x1FUL));
	
	
	NVIC->ICER[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)GPIO_IRQn) & 0x1FUL));
	NVIC->IP[_IP_IDX(GPIO_IRQn)]  = ((uint32_t)(NVIC->IP[_IP_IDX(GPIO_IRQn)]  & ~(0xFFUL << _BIT_SHIFT(GPIO_IRQn))) |
       (((2 << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL) << _BIT_SHIFT(GPIO_IRQn)));
	NVIC->ISER[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)GPIO_IRQn) & 0x1FUL));
}



//各个外设GPIO初始化
void SYS_GPIO_Init(void)
{
	//PA 0111 1000 0000 0000
	//   |||| |||| |||| |||+--> COM1
	//   |||| |||| |||| ||+---> COM2
	//   |||| |||| |||| |+----> COM3
	//   |||| |||| |||| +-----> COM4
	//
	//   |||| |||| |||+-------> SEG11
	//   |||| |||| ||+--------> SEG10
	//   |||| |||| |+---------> SEG9
	//   |||| |||| +----------> SEG8
	//
	//   |||| |||+------------> SEG7
	//   |||| ||+-------------> SEG6
	//   |||| |+--------------> SEG5
	//   |||| +---------------> SCL
	//
	//   |||+-----------------> SDA
	//   ||+------------------> RX
	//   |+-------------------> TX
	//   +--------------------> NC
	
	GPIOA->DO = 0x7800;
	
	GPIOA->ODEN = (1 << GPIO_PIN12) + (1 << GPIO_PIN11);
	
	GPIOA->PUDEN = 0;
	
	GPIOA->FCR = (FL_GPIO_MODE_INPUT << FCR_GPIO_PIN15) + (FL_GPIO_MODE_DIGITAL << FCR_GPIO_PIN14) + (FL_GPIO_MODE_DIGITAL << FCR_GPIO_PIN13) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN12) +
	             (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN11) + (FL_GPIO_MODE_ANALOG << FCR_GPIO_PIN10) + (FL_GPIO_MODE_ANALOG << FCR_GPIO_PIN9) + (FL_GPIO_MODE_ANALOG << FCR_GPIO_PIN8) +
							 (FL_GPIO_MODE_ANALOG << FCR_GPIO_PIN7) + (FL_GPIO_MODE_ANALOG << FCR_GPIO_PIN6) + (FL_GPIO_MODE_ANALOG << FCR_GPIO_PIN5) + (FL_GPIO_MODE_ANALOG << FCR_GPIO_PIN4) +
							 (FL_GPIO_MODE_ANALOG << FCR_GPIO_PIN3) + (FL_GPIO_MODE_ANALOG << FCR_GPIO_PIN2) + (FL_GPIO_MODE_ANALOG << FCR_GPIO_PIN1) + (FL_GPIO_MODE_ANALOG << FCR_GPIO_PIN0);
	
	GPIOA->DSR = 0xFFFFFFFF;

	GPIOA->INEN = (1 << GPIO_PIN15);//(1 << GPIO_PIN13);
	
	
	//PB 0000 0001 0000 0000
	//   |||| |||| |||| |||+--> NC
	//   |||| |||| |||| ||+---> NC
	//   |||| |||| |||| |+----> PWM-OUT
	//   |||| |||| |||| +-----> NC
	//
	//   |||| |||| |||+-------> SEG4
	//   |||| |||| ||+--------> SEG3
	//   |||| |||| |+---------> SEG2
	//   |||| |||| +----------> SEG1
	//
	//   |||| |||+------------> LCD
	//   |||| ||+-------------> LED-G
	//   |||| |+--------------> LED-R
	//   |||| +---------------> LED-Y
	//
	//   |||+-----------------> DIN-PWM
	//   ||+------------------> DIN-PWM1
	//   |+-------------------> NC
	//   +--------------------> R-TEST
	GPIOB->DO = 0x0100;
	
	GPIOB->ODEN = 0;

  GPIOB->PUDEN = 0;

  GPIOB->FCR = (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN15) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN14) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN13) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN12) +
	             (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN11) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN10) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN9) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN8) +
							 (FL_GPIO_MODE_ANALOG << FCR_GPIO_PIN7) + (FL_GPIO_MODE_ANALOG << FCR_GPIO_PIN6) + (FL_GPIO_MODE_ANALOG << FCR_GPIO_PIN5) + (FL_GPIO_MODE_ANALOG << FCR_GPIO_PIN4) +
							 (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN3) + (FL_GPIO_MODE_DIGITAL << FCR_GPIO_PIN2) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN1) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN0);
	
	GPIOB->DSR = 0xFFFFFFFF;

	GPIOB->INEN = 0;
	
	GPIOB->ANEN &= (0 << FL_GPIO_PIN_2);
	
	//复用为ATIM_CH
	GPIOB->DFS |= (FL_GPIO_PINREMAP_FUNCTON4 << FCR_GPIO_PIN2);
	
	//PC 0000 0010 1110 0011
	//   |||| |||| |||| |||+--> OPA-
	//   |||| |||| |||| ||+---> OPA+
	//   |||| |||| |||| |+----> NC
	//   |||| |||| |||| +-----> NC
	//
	//   |||| |||| |||+-------> NC
	//   |||| |||| ||+--------> OPA-OUT
	//   |||| |||| |+---------> ADC-Lppm
	//   |||| |||| +----------> ADC-Hppm
	//
	//   |||| |||+------------> BTS-EN
	//   |||| ||+-------------> BTS(Battery sample)
	//   |||| |+--------------> AHT21-POWER
	//   |||| +---------------> NC
	//
	//   |||+-----------------> NC
	//   ||+------------------> NC
	//   |+-------------------> NRST
	//   +--------------------> NC
	
	GPIOC->DO = 0x02E3;
	
	GPIOC->ODEN = (1 << GPIO_PIN9) + (1 << GPIO_PIN7) + (1 << GPIO_PIN6) + (1 << GPIO_PIN5) + (1 << GPIO_PIN1) + (1 << GPIO_PIN0);

  GPIOC->PUDEN = (1 << GPIO_PIN14);

  GPIOC->FCR = (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN15) + (FL_GPIO_MODE_DIGITAL << FCR_GPIO_PIN14) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN13) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN12) +
	             (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN11) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN10) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN9) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN8) +
							 (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN7) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN6) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN5) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN4) +
							 (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN3) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN2) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN1) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN0);
	
	GPIOC->DSR = 0xFFFFFFFF;

	GPIOC->INEN = 0;
	
	//PD 0000 0000 0011 1100
	//   |||| |||| |||| |||+--> NC
	//   |||| |||| |||| ||+---> NC
	//   |||| |||| |||| |+----> CS
	//   |||| |||| |||| +-----> SCLK
	//
	//   |||| |||| |||+-------> SDIO(MISO)
	//   |||| |||| ||+--------> FCSB(MOSI)
	//   |||| |||| |+---------> GPIO_1
	//   |||| |||| +----------> SWCLK
	//
	//   |||| |||+------------> SWDIO
	//   |||| ||+-------------> NC
	//   |||| |+--------------> NC
	//   |||| +---------------> NC
	//
	//   |||+-----------------> NC
	//   ||+------------------> NC
	//   |+-------------------> NC
	//   +--------------------> NC
	
	GPIOD->DO = 0x003C;
	
	GPIOD->ODEN =  (1 << GPIO_PIN2) + (1 << GPIO_PIN3) + (1 << GPIO_PIN4) + (1 << GPIO_PIN5);

  GPIOD->PUDEN = (1 << GPIO_PIN7) + (1 << GPIO_PIN8);

  GPIOD->FCR = (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN15) + (FL_GPIO_MODE_DIGITAL << FCR_GPIO_PIN14) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN13) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN12) +
	             (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN11) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN10) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN9) + (FL_GPIO_MODE_DIGITAL << FCR_GPIO_PIN8) +
							 (FL_GPIO_MODE_DIGITAL << FCR_GPIO_PIN7) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN6) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN5) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN4) +
							 (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN3) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN2) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN1) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN0);
	
	GPIOD->DSR = 0xFFFFFFFF;

	GPIOD->INEN = 0;
	
}
//设置睡眠
void GotoDeepSleep(void)
{
	RMU->PDRCR |= RMU_PDRCR_EN_Msk;
	RMU->BORCR |= RMU_BORCR_ENB_Msk;
	PMU->CR &= ~PMU_CR_PMOD_Msk;
	PMU->CR |= FL_PMU_POWER_MODE_SLEEP_OR_DEEPSLEEP + (0x1 << 9);
  __WFI();
}


