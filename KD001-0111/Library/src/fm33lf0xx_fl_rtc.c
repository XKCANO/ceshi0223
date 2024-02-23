/**
  *******************************************************************************************************
  * @file    fm33lf0xx_fl_rtc.c
  * @author  FMSH Application Team
  * @brief   Src file of RTC FL Module
  *******************************************************************************************************
  * @attention
  *
  * Copyright (c) [2021] [Fudan Microelectronics]
  * THIS SOFTWARE is licensed under Mulan PSL v2.
  * You can use this software according to the terms and conditions of the Mulan PSL v2.
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

/** @addtogroup RTC
  * @{
  */

#ifdef FL_RTC_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup RTC_FL_Private_Macros
  * @{
  */
#define IS_RTC_INSTANCE(RTCx)                     ((RTCx) == RTC)

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup RTC_FL_EF_Init
  * @{
  */
/**
  * @brief  复位对应RTCx寄存器.
  * @param  RTCx
  * @retval ErrorStatus枚举值:
  *           -FL_PASS 外设寄存器值恢复复位值
  *           -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_RTC_DeInit(RTC_Type *RTCx)
{
    FL_ErrorStatus status = FL_FAIL;
    if(RTCx != NULL)
    {
        /* Check the parameters */
        assert_param(IS_RTC_INSTANCE(RTCx));
        RTCx->IER       = 0x00000000U;
        RTCx->WER       = 0xACACACACU;
        RTCx->ADJUST    = 0x00000000U;
        RTCx->ADSIGN    = 0x00000000U;
        RTCx->ALARM     = 0x00000000U;
        RTCx->BCDDAY    = 0x00000000U;
        RTCx->BCDHOUR   = 0x00000000U;
        RTCx->BCDMIN    = 0x00000000U;
        RTCx->BCDMONTH  = 0x00000000U;
        RTCx->BCDSEC    = 0x00000000U;
        RTCx->BCDWEEK   = 0x00000000U;
        RTCx->BCDYEAR   = 0x00000000U;
        RTCx->SBSCNT    = 0x00000000U;
        RTCx->TMSEL     = 0x00000000U;
        RTCx->CR        = 0x00000000U;
        RTCx->WER       = 0x00000000U;
        status = FL_PASS;
    }
    return status;
}
/**
  * @brief  配置实时时钟相关.
  * @param  RTCx Timer Instance
  * @param  initStruct 指向一个 @ref FL_RTC_InitTypeDef(时基配置结构体)
  * @retval ErrorStatus枚举值
  *            -FL_FAIL 配置过程发生错误
  *            -FL_PASS 成功
  */
FL_ErrorStatus FL_RTC_Init(RTC_Type *RTCx, FL_RTC_InitTypeDef *initStruct)
{
    /* 参数检查 */
    assert_param(IS_RTC_INSTANCE(RTCx));
    /* 时钟总线使能配置 */
    FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_RTC);
    /* 配置时间 */
    (void)FL_RTC_ConfigTime(RTCx, initStruct);
    return FL_PASS;
}

/**
  * @brief  设置实时时钟
  * @param  RTCx Timer Instance
  * @param  initStruct 指向一个 @ref FL_RTC_InitTypeDef(时基配置结构体)
  * @retval ErrorStatus枚举值
  *            -FL_FAIL 配置过程发生错误
  *            -FL_PASS 成功
  */
FL_ErrorStatus FL_RTC_ConfigTime(RTC_Type *RTCx, FL_RTC_InitTypeDef *initStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    if(initStruct != NULL)
    {
        /* 使能时间配置 */
        FL_RTC_WriteEnable(RTCx);
        /* 配置秒 */
        FL_RTC_WriteSecond(RTCx, initStruct->second);
        /* 配置分钟 */
        FL_RTC_WriteMinute(RTCx, initStruct->minute);
        /* 配置小时 */
        FL_RTC_WriteHour(RTCx, initStruct->hour);
        /* 配置日期 */
        FL_RTC_WriteDay(RTCx, initStruct->day);
        /* 配置周 */
        FL_RTC_WriteWeek(RTCx, initStruct->week);
        /* 配置月 */
        FL_RTC_WriteMonth(RTCx, initStruct->month);
        /* 配置年 */
        FL_RTC_WriteYear(RTCx, initStruct->year);
        /* 锁定时间配置 */
        FL_RTC_WriteDisable(RTCx);
        status = FL_PASS;
    }
    return status;
}
/**
  * @brief  获取实时时间并保存到指定结构体中
  * @param  RTCx Timer Instance
  * @param  initStruct 指向一个 @ref FL_RTC_InitTypeDef(时基配置结构体)
  * @retval ErrorStatus枚举值
  *            -FL_FAIL 配置过程发生错误
  *            -FL_PASS 成功
  */
FL_ErrorStatus FL_RTC_GetTime(RTC_Type *RTCx, FL_RTC_InitTypeDef *initStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    if(initStruct != NULL)
    {
        /* 配置秒 */
        initStruct->second = FL_RTC_ReadSecond(RTCx);
        /* 配置分钟 */
        initStruct->minute  = FL_RTC_ReadMinute(RTCx);
        /* 配置小时 */
        initStruct->hour = FL_RTC_ReadHour(RTCx);
        /* 配置日期 */
        initStruct->day = FL_RTC_ReadDay(RTCx);
        /* 配置周 */
        initStruct->week = FL_RTC_ReadWeek(RTCx);
        /* 配置月 */
        initStruct->month = FL_RTC_ReadMonth(RTCx);
        /* 配置年 */
        initStruct->year = FL_RTC_ReadYear(RTCx);
        status = FL_PASS;
    }
    return status;
}
/**
  * @brief    设置 initStruct 为默认配置
  * @param     initStruct 指向需要将值设置为默认配置的结构体 @ref FL_RTC_InitTypeDef 结构体
  *
  * @retval    None
  */

void FL_RTC_StructInit(FL_RTC_InitTypeDef *initStruct)
{
    if(initStruct != NULL)
    {
        /*  */
        initStruct->year    = 0x00;
        initStruct->month   = 0x00;
        initStruct->day     = 0x00;
        initStruct->week    = 0x00;
        initStruct->hour    = 0x00;
        initStruct->minute  = 0x00;
        initStruct->second  = 0x00;
    }
}

/**
  * @}
  */

#endif /* FL_RTC_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/

