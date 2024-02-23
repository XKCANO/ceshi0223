/*
* Copyright (c) 2008, XingLan Technology
* File name : NUC1xx_Timer_api.H
* Version: 0.6
* 32bit MCU : NUC1xx
* Cortex: Cortex-M0
* Compiler: 
*   Keil ARM 4.11 Compiler
*   IAR  ARM 5.40 Compiler
*
* Author : Tom (pengfengboy@163.com)
*
* Description : 
* 	1:initialize the timer module
*
* History :
* 	02/18/2011 : adds the SetTimer0 function.
*
*/
#ifndef __STM32L0_TIMER_H
#define __STM32L0_TIMER_H
/* --------------------------------------------------------------------------- */
#include "stdint.h"
/* --------------------------------------------------------------------------- */
#define 	TIMER_SIZE		15
/* --------------------------------------------------------------------------- */
/******************  Bit definition for TIM_CCMR1 register  *******************/
#define 	TIM_CCMR1_CC1S_OUTPUT					((uint32_t)0x00000000U)
#define 	TIM_CCMR1_OC1M_PWM_MODE1      ((uint32_t)0x00000060U)
#define 	TIM_CCMR1_OC1M_PWM_MODE2      ((uint32_t)0x00000070U)
#define 	TIM_CCMR1_CC2S_OUTPUT					((uint32_t)0x00000000U)
#define 	TIM_CCMR1_OC2M_PWM_MODE1      ((uint32_t)0x00006000U)
#define 	TIM_CCMR1_OC2M_PWM_MODE2      ((uint32_t)0x00007000U)
/* --------------------------------------------------------------------------- */
/*******************  Bit definition for TIM_CR1 register  ********************/
#define 	TIM_CR1_CMS_EDGE_MODE					((uint32_t)0x00000000U)
#define 	TIM_CR1_CMS_CENTER_MODE1			((uint32_t)0x00000020U)
#define 	TIM_CR1_CMS_CENTER_MODE2			((uint32_t)0x00000040U)
#define 	TIM_CR1_CMS_CENTER_MODE3			((uint32_t)0x00000060U)
/* --------------------------------------------------------------------------- */
/*******************  Bit definition for PWM_CMR register  *******************/ 
#define   PWM_CMR_MC4_MODE1             ((uint32_t)0x00001000)
#define   PWM_CMR_MC4_MODE2             ((uint32_t)0x00002000)
#define   PWM_CMR_MC4_MODE3             ((uint32_t)0x00003000)
/* --------------------------------------------------------------------------- */
#define WDG_WriteAccess_Enable     ((uint32_t)0x1ACCE551)
#define WDG_WriteAccess_Disable    ((uint32_t)0x00000000)
/* --------------------------------------------------------------------------- */


/* --------------------------------------------------------------------------- */
typedef struct
{
	uint32_t t[TIMER_SIZE];
	unsigned short period;
	unsigned char step;
	unsigned char mode;
}TIMER_TypeDef;
/* --------------------------------------------------------------------------- */
extern TIMER_TypeDef Timer;
/* --------------------------------------------------------------------------- */


/* --------------------------------------------------------------------------- */
typedef struct
{
	uint32_t data[4];
}RANDOM_TypeDef;
/* --------------------------------------------------------------------------- */
extern RANDOM_TypeDef Random;
/* --------------------------------------------------------------------------- */


/* --------------------------------------------------------------------------- */
void SetSystemTickTimer(void);
void CheckSystemTickTimer(void);
void KillSystemTickTimer(void);
/* --------------------------------------------------------------------------- */
void OpenPWM(void);
void ClosePWM(void);
void OpenLpTimer(void);
void CloseLpTimer(void);
/* --------------------------------------------------------------------------- */
#endif
