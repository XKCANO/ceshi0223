/*
The ultra-low-power STM32L031x4/6 devices include three general-purpose timers, 
one low- power timer (LPTM), two watchdog timers and the SysTick timer.
1, General-purpose timers (TIM2, TIM21 and TIM22)
2, Low-power Timer (LPTIM)
3, SysTick timer
   < This timer is dedicated to the OS, but could also be used as a standard downcounter.
   It is based on a 24-bit downcounter with autoreload capability and a programmable clock source.
   It features a maskable system interrupt generation when the counter reaches '0'. >
4, Independent watchdog (IWDG)
5, Window watchdog (WWDG)
   < The window watchdog is based on a 7-bit downcounter that can be set as free-running. 
	 It can be used as a watchdog to reset the device when a problem occurs. It is clocked from the main clock. 
	 It has an early warning interrupt capability and the counter can be frozen in debug mode.>
*/
#include <stdio.h>
#include "fm33lf0xx_fl.h"
#include "FM33LF0_Timer.h"

/* =========================================================================== */
TIMER_TypeDef Timer;
/* =========================================================================== */

/*
System Tick Timer is a 24-bit downcounter.
HCLK: 32MHz
*/
void SetSystemTickTimer(void)
{
	SysTick->LOAD = 32000;	//1ms
	SysTick->VAL = 32000;
	
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}
/*
** Check System Tick Timer
*/
void CheckSystemTickTimer(void)
{
	uint32_t i;
	if((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) != 0)
	{
		i = 0;
		do{
			Timer.t[i]++;
			i++;
		}while(i < TIMER_SIZE);
	}
}
/*
** Kill System Tick Timer
*/
void KillSystemTickTimer(void)
{
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

/* 
** Set ATimer External Trigger
** PCLK: 32MHz
*/

void OpenPWM(void)
{
	CMU->PCLKCR4 |= FL_CMU_GROUP4_BUSCLK_ATIM;
	CMU->OPCER1 |= FL_CMU_GROUP1_OPCLKEN_ATIM;
	
	ATIM->ARR = 565;
	ATIM->CR1 |= (0 << ATIM_CR1_DIR_Pos) + FL_ATIM_COUNTER_ALIGNED_EDGE + FL_ATIM_CLK_DIVISION_DIV1 + ATIM_CR1_ARPE_Msk;
	ATIM->PSC |= 0;
	ATIM->EGR |= ATIM_EGR_UG_Msk;
	ATIM->CCER	= 0;
	ATIM->CR2	|= FL_ATIM_OC_IDLE_STATE_HIGH + FL_ATIM_OCN_IDLE_STATE_HIGH;
	ATIM->CCMR1 |= FL_ATIM_CHANNEL_MODE_OUTPUT + FL_ATIM_OC_MODE_PWM1 + (0 << ATIM_CCMR_OCCE_Pos);
	ATIM->CCER |= ATIM_CCER_CCNE_Msk + ATIM_CCER_CCOE_Msk;
	ATIM->CCR1 = 283;
	ATIM->ISR |= ATIM_ISR_UIF_Msk;
	ATIM->RCR = 0;
	
	ATIM->CR1 |= ATIM_CR1_CEN_Msk;
	ATIM->BDTR |= ATIM_BDTR_MOE_Msk;
}

void ClosePWM(void)
{
	ATIM->CR1 = 0;
	ATIM->CR2 = 0;
	ATIM->ARR = 0;
	ATIM->PSC = 0;
	ATIM->EGR = 0;
	ATIM->CCER	= 0;
	ATIM->CCR1 = 0;
	ATIM->RCR = 0;
	ATIM->ISR = 0;
	ATIM->BDTR = 0;
	
	CMU->PCLKCR4 &= ~FL_CMU_GROUP4_BUSCLK_ATIM;
	CMU->OPCER1 &= ~FL_CMU_GROUP1_OPCLKEN_ATIM;
}


/*
	LPTIM16配置 开启中断			10秒一次中断
*/
void OpenLpTimer(void)
{
	CMU->PCLKCR1 |= FL_CMU_GROUP1_BUSCLK_LPTIM16;
	CMU->OPCCR1 |= FL_CMU_LPTIM16_CLK_SOURCE_RCLP;
	CMU->OPCER1 |= FL_CMU_GROUP1_OPCLKEN_LPTIM16;
	
	LPTIM16->CFGR |= FL_LPTIM16_CLK_SOURCE_INTERNAL + FL_LPTIM16_PSC_DIV8 + FL_LPTIM16_OPERATION_MODE_NORMAL +
									 FL_LPTIM16_ENCODER_MODE_DISABLE + FL_LPTIM16_ONE_PULSE_MODE_CONTINUOUS;
	LPTIM16->ARR = 40960;
	LPTIM16->IER |= LPTIM16_IER_OVIE_Msk;
	LPTIM16->ISR |= LPTIM16_ISR_OVIF_Msk;
	
	NVIC->ICER[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)LPTIM16_IRQn) & 0x1FUL));
	NVIC->IP[_IP_IDX(LPTIM16_IRQn)]  = ((uint32_t)(NVIC->IP[_IP_IDX(LPTIM16_IRQn)]  & ~(0xFFUL << _BIT_SHIFT(LPTIM16_IRQn))) |
       (((1 << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL) << _BIT_SHIFT(LPTIM16_IRQn)));
	NVIC->ISER[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)LPTIM16_IRQn) & 0x1FUL));
	
	LPTIM16->CR |= LPTIM16_CR_EN_Msk;
	
}

void CloseLpTimer(void)
{
	LPTIM16->ARR = 0;
	LPTIM16->IER = 0;
	LPTIM16->ISR = 0;
	LPTIM16->CFGR = 0;
	LPTIM16->CR = 0;
	
	CMU->PCLKCR1 &= ~FL_CMU_GROUP1_BUSCLK_LPTIM16;
	CMU->OPCCR1 &= ~FL_CMU_LPTIM16_CLK_SOURCE_RCLP;
	CMU->OPCER1 &= ~FL_CMU_GROUP1_OPCLKEN_LPTIM16;
	
	NVIC_DisableIRQ(LPTIM16_IRQn);
}


/*---------------------------------------------------------------------------------------------------------*/

