/**
  *******************************************************************************************************
  * @file    fm33lf0xxxx_fl_clm.c
  * @author  FMSH Application Team
  * @brief   Src file of CLM FL Module
  *******************************************************************************************************
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
  *******************************************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "fm33lf0xx_fl.h"

/** @addtogroup FM33LF0XX_FL_Driver
  * @{
  */

/** @addtogroup CLM
  * @{
  */

#ifdef FL_CLM_DRIVER_ENABLED

#define         IS_FL_CLM_INSTANCE(INSTANCE)                (((INSTANCE) == CLM0) || \
                                                             ((INSTANCE) == CLM1))

#define         IS_FL_CLM_MODE_INSTANCE(__VALUE__)          (((__VALUE__) == FL_CLM_WORKMODE_INTERRUPT) || \
                                                             ((__VALUE__) == FL_CLM_WORKMODE_RESET))

#define         IS_FL_CLM_MONITORCLOCK_INSTANCE(__VALUE__)  (((__VALUE__) == FL_CLM_MONCLK_RCHF) || \
                                                             ((__VALUE__) == FL_CLM_MONCLK_PLL)  || \
                                                             ((__VALUE__) == FL_CLM_MONCLK_XTHF))

/* Private macros ------------------------------------------------------------*/
/** @addtogroup CLM_FL_Private_Macros
  * @{
  */
/**
  * @brief  配置指定的CLM外设
  * @param  CLMx  外设入口地址
  * @param  CLM_InitStruct 指向 @ref FL_CLM_InitTypeDef 的结构体，它包含CLM外设寄存器的配置信息
  * @retval 执行结果
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS CLM外设寄存器配置成功
  */
FL_ErrorStatus FL_CLM_Init(CLM_Type *CLMx, FL_CLM_InitTypeDef  *CLM_InitStruct)
{
    FL_ErrorStatus status = FL_PASS;
    /* 校验参数是否正确 */
    assert_param(IS_FL_CLM_INSTANCE(CLMx));  
    assert_param(IS_FL_CLM_MODE_INSTANCE(CLM_InitStruct->mode));
    assert_param(IS_FL_CLM_MONITORCLOCK_INSTANCE(CLM_InitStruct->monitorclock));
    if(CLMx == CLM0)
    {   /* 开启CLM0总线时钟 */
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_CLM0);
    }
    else
    {   /* 开启CLM1总线时钟 */
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_CLM1);
    }
    /* 配置CLMx的工作模式 */
    FL_CLM_SetWorkingMode(CLMx,CLM_InitStruct->mode);
    /* 配置CLMx的超时复位功能 */
    if(CLM_InitStruct->timeoutReset == FL_ENABLE)
    {
        FL_CLM_EnableTimeOutReset(CLMx);
    }
    else
    {
        FL_CLM_DisableTimeOutReset(CLMx);
    }
    /* 配置CLMx的参考周期 */
    FL_CLM_WriteReferenceClockCycle(CLMx,CLM_InitStruct->referenceclockCycle);
    /* 配置CLMx的监控时钟 */
    FL_CLM_SetMonitorClock(CLMx,CLM_InitStruct->monitorclock);
    /* 配置CLMx的时钟监控比较高阈值 */
    FL_CLM_WriteCompareHighThreshold(CLMx,CLM_InitStruct->CompareHighThreshold);
    /* 配置CLMx的时钟监控比较低阈值 */
    FL_CLM_WriteCompareLowThreshold(CLMx,CLM_InitStruct->CompareLowThreshold);
    return status;
}


/**
  * @brief  恢复CLM外设寄存器到复位值
  * @param  CLMx  外设入口地址
  * @retval 执行结果
  *         -FL_PASS CLM外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_CLM_DeInit(CLM_Type *CLMx)
{
    FL_ErrorStatus status = FL_PASS;
    /* 入口合法性检查 */
    assert_param(IS_FL_CLM_INSTANCE(CLMx));
    if(CLMx == CLM0)
    {
        /* 外设复位使能 */
        FL_RMU_EnablePeripheralReset(RMU);
        FL_RMU_EnableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_CLM0);
        FL_RMU_DisableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_CLM0);
        FL_RMU_DisablePeripheralReset(RMU);
        FL_CMU_DisableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_CLM0);
    }
    else
    {
        /* 外设复位使能 */
        FL_RMU_EnablePeripheralReset(RMU);
        FL_RMU_EnableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_CLM1);
        FL_RMU_DisableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_CLM1);
        FL_RMU_DisablePeripheralReset(RMU);
        FL_CMU_DisableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_CLM1);
    }

    return status;
}


#endif

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
