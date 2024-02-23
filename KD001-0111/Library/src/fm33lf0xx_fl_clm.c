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
  * @brief  ����ָ����CLM����
  * @param  CLMx  ������ڵ�ַ
  * @param  CLM_InitStruct ָ�� @ref FL_CLM_InitTypeDef �Ľṹ�壬������CLM����Ĵ�����������Ϣ
  * @retval ִ�н��
  *         -FL_FAIL ���ù��̷�������
  *         -FL_PASS CLM����Ĵ������óɹ�
  */
FL_ErrorStatus FL_CLM_Init(CLM_Type *CLMx, FL_CLM_InitTypeDef  *CLM_InitStruct)
{
    FL_ErrorStatus status = FL_PASS;
    /* У������Ƿ���ȷ */
    assert_param(IS_FL_CLM_INSTANCE(CLMx));  
    assert_param(IS_FL_CLM_MODE_INSTANCE(CLM_InitStruct->mode));
    assert_param(IS_FL_CLM_MONITORCLOCK_INSTANCE(CLM_InitStruct->monitorclock));
    if(CLMx == CLM0)
    {   /* ����CLM0����ʱ�� */
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_CLM0);
    }
    else
    {   /* ����CLM1����ʱ�� */
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_CLM1);
    }
    /* ����CLMx�Ĺ���ģʽ */
    FL_CLM_SetWorkingMode(CLMx,CLM_InitStruct->mode);
    /* ����CLMx�ĳ�ʱ��λ���� */
    if(CLM_InitStruct->timeoutReset == FL_ENABLE)
    {
        FL_CLM_EnableTimeOutReset(CLMx);
    }
    else
    {
        FL_CLM_DisableTimeOutReset(CLMx);
    }
    /* ����CLMx�Ĳο����� */
    FL_CLM_WriteReferenceClockCycle(CLMx,CLM_InitStruct->referenceclockCycle);
    /* ����CLMx�ļ��ʱ�� */
    FL_CLM_SetMonitorClock(CLMx,CLM_InitStruct->monitorclock);
    /* ����CLMx��ʱ�Ӽ�رȽϸ���ֵ */
    FL_CLM_WriteCompareHighThreshold(CLMx,CLM_InitStruct->CompareHighThreshold);
    /* ����CLMx��ʱ�Ӽ�رȽϵ���ֵ */
    FL_CLM_WriteCompareLowThreshold(CLMx,CLM_InitStruct->CompareLowThreshold);
    return status;
}


/**
  * @brief  �ָ�CLM����Ĵ�������λֵ
  * @param  CLMx  ������ڵ�ַ
  * @retval ִ�н��
  *         -FL_PASS CLM����Ĵ���ֵ�ָ���λֵ
  *         -FL_FAIL δ�ɹ�ִ��
  */
FL_ErrorStatus FL_CLM_DeInit(CLM_Type *CLMx)
{
    FL_ErrorStatus status = FL_PASS;
    /* ��ںϷ��Լ�� */
    assert_param(IS_FL_CLM_INSTANCE(CLMx));
    if(CLMx == CLM0)
    {
        /* ���踴λʹ�� */
        FL_RMU_EnablePeripheralReset(RMU);
        FL_RMU_EnableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_CLM0);
        FL_RMU_DisableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_CLM0);
        FL_RMU_DisablePeripheralReset(RMU);
        FL_CMU_DisableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_CLM0);
    }
    else
    {
        /* ���踴λʹ�� */
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
