/**
  ****************************************************************************************************
  * @file    fm33lf0xx_fl_pmu.c
  * @author  FMSH Application Team
  * @brief   Src file of PMU FL Module
  ****************************************************************************************************
  * @attention
  *
  * Copyright (c) [2021] [Fudan Microelectronics]
  * THIS SOFTWARE is licensed under Mulan PSL v2.
  * You can use this software according to the terms and conditions of the Mulan PSL v2.
  * You may obtain a copy of Mulan PSL v2 at:
  *          http://license.coscl.org.cn/MulanPSL2
  * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
  * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
  * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
  * See the Mulan PSL v2 for more details.
  *
  ****************************************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "fm33lf0xx_fl.h"

/** @addtogroup FM33LF0XX_FL_Driver
  * @{
  */

/** @addtogroup PMU
  * @{
  */
 
#ifdef FL_PMU_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup UART_FL_Private_Macros
  * @{
  */
															 
#define         IS_FL_PMU_INSTANCE(INSTANCE)                (((INSTANCE) == PMU))

#define         IS_FL_PMU_MODE(__VALUE__)                   (((__VALUE__) == FL_PMU_POWER_MODE_ACTIVE)||\
                                                             ((__VALUE__) == FL_PMU_POWER_MODE_SLEEP_OR_DEEPSLEEP))

#define         IS_FL_PMU_DEEPSLEEP(__VALUE__)              (((__VALUE__) == FL_PMU_SLEEP_MODE_DEEP)||\
                                                             ((__VALUE__) == FL_PMU_SLEEP_MODE_NORMAL))

#define         IS_FL_PMU_WAKEUPFREQUENCY(__VALUE__)        (((__VALUE__) == FL_PMU_RCHF_WAKEUP_FREQ_8MHZ)||\
                                                             ((__VALUE__) == FL_PMU_RCHF_WAKEUP_FREQ_16MHZ)||\
                                                             ((__VALUE__) == FL_PMU_RCHF_WAKEUP_FREQ_24MHZ))


#define         IS_FL_PMU_WAKEUPDELAY(__VALUE__)            (((__VALUE__) == FL_PMU_WAKEUP_DELAY_0US)||\
                                                             ((__VALUE__) == FL_PMU_WAKEUP_DELAY_2US)||\
                                                             ((__VALUE__) == FL_PMU_WAKEUP_DELAY_4US)||\
                                                             ((__VALUE__) == FL_PMU_WAKEUP_DELAY_8US))

/**
  *@}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup PMU_FL_EF_Init
  * @{
  */
 
/**
  * @brief  复位pmu外设
  *
  * @param  外设入口地址
  *
  * @retval 返回错误状态，可能值:
  *         -FL_PASS 外设寄存器值回复复位值
  *         -FL_FAIL 位成功执行
  */
FL_ErrorStatus FL_PMU_Sleep_DeInit(PMU_Type *PMUx)
{
    FL_ErrorStatus status = FL_FAIL;
    /* 参数合法性检测 */
    assert_param(IS_FL_PMU_INSTANCE(PMUx));
    PMUx->CR   = 0x00060000U;
    PMUx->WKTR = 0xC0000001U;

    status = FL_PASS;
    return status;
}

/**
  * @brief  根据lpm_initstruct结构体包含的配置信息配置pmu寄存器
  *
  * @note   为更好的睡眠功耗用户可能需要根据实际应用，调用 @ref fm33lf0xx_fl_pmu.h中的其他接口
  *          来完成睡眠前的模式配置，包括睡眠行为和唤醒后的行为(注：此函数会关闭BOR)
  * @param  PMUx  外设入口地址
  * @param  LPM_InitStruct 指向一个 @ref FL_PMU_SleepInitTypeDef 类型的结构体，它包含指定PMU外设的配置信息
  *
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS PMU配置成功
  */
FL_ErrorStatus FL_PMU_Sleep_Init(PMU_Type *PMUx, FL_PMU_SleepInitTypeDef *LPM_InitStruct)
{
    FL_ErrorStatus status = FL_FAIL;
	if(LPM_InitStruct != NULL)
	{
		/* 参数合法性检查 */
		assert_param(IS_FL_PMU_INSTANCE(PMUx));
		assert_param(IS_FL_PMU_MODE(LPM_InitStruct->powerMode)); 
		assert_param(IS_FL_PMU_DEEPSLEEP(LPM_InitStruct->deepSleep));
		assert_param(IS_FL_PMU_WAKEUPFREQUENCY(LPM_InitStruct->wakeupFrequency));
		assert_param(IS_FL_PMU_WAKEUPDELAY(LPM_InitStruct->wakeupDelay));
		/* 唤醒时间 */
		FL_PMU_SetWakeupDelay(PMUx, LPM_InitStruct->wakeupDelay);
		/* 唤醒后RCHF的频率 */
		FL_PMU_SetRCHFWakeupFrequency(PMUx, LPM_InitStruct->wakeupFrequency);
		if(LPM_InitStruct->deepSleep == FL_PMU_SLEEP_MODE_DEEP)
		{
			FL_PMU_SetFlashStopSignalClearMode(PMUx, LPM_InitStruct->sleepStop);
		}
		/* M0系统控制器，一般配置为0即可*/
		SCB->SCR = 0;
		/* 睡眠模式 */
		FL_PMU_SetSleepMode(PMUx, LPM_InitStruct->deepSleep);
			
		status = FL_PASS;
	}
    return status;
}

/**
  * @brief  LPM_InitStruct 为默认配置
  * @param  LPM_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_PMU_SleepInitTypeDef structure
  *         结构体
  * @retval None
  */
void FL_PMU_StructInit(FL_PMU_SleepInitTypeDef *LPM_InitStruct)
{
	if(LPM_InitStruct != NULL)
	{
		LPM_InitStruct->powerMode          		    = FL_PMU_POWER_MODE_SLEEP_OR_DEEPSLEEP;
		LPM_InitStruct->deepSleep           		= FL_PMU_SLEEP_MODE_NORMAL;
		LPM_InitStruct->wakeupFrequency     	    = FL_PMU_RCHF_WAKEUP_FREQ_8MHZ;
		LPM_InitStruct->wakeupDelay            		= FL_PMU_WAKEUP_DELAY_2US;
		LPM_InitStruct->sleepStop         			= FL_PMU_STPCLR_SYNCHRONOUS;
	}
}

/**
  * @}
  */

#endif /* FL_PMU_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/

