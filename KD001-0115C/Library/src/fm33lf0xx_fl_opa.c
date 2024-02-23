/**
  *******************************************************************************************************
  * @file    fm33lg0xx_fl_opa.c
  * @author  FMSH Application Team
  * @brief   Src file of OPA FL Module
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

/** @addtogroup FM33Lf0XX_FL_Driver
  * @{
  */

/** @addtogroup OPA
  * @{
  */

#ifdef FL_OPA_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup OPA_FL_Private_Macros
  * @{
  */


#define         IS_OPA_ALL_INSTANCE(INTENCE)               (((INTENCE) == OPA1)||((INTENCE) == OPA2))


#define         IS_FL_OPA_INP_CHANNAL(__VALUE__)           (((__VALUE__) == FL_OPA_INP_SOURCE_INP1)||\
                                                            ((__VALUE__) == FL_OPA_INP_SOURCE_INP2)||\
                                                            ((__VALUE__) == FL_OPA_INP_SOURCE_DAC))


/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup OPA_FL_EF_Init
 * @{
 */

/**
  * @brief  复位OPA 外设寄存器值为复位值
  * @param  外设入口地址
  * @retval 返回错误状态，可能值：
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_OPA_DeInit(OPA_Type *OPAx)
{
    /* 入口参数合法性断言 */
    assert_param(IS_OPA_ALL_INSTANCE(OPAx));
    /* 使能外设复位 */
    FL_RMU_EnablePeripheralReset(RMU);
    /* 复位外设寄存器 */
    FL_RMU_EnableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_OPACR);
    FL_RMU_DisableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_OPACR);
    /* 关闭外设总线始时钟和工作时钟 */
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_OPA);
    /* 锁定外设复位 */
    FL_RMU_DisablePeripheralReset(RMU);
    return FL_PASS;
}

/**
  * @brief  根据 OPA_InitStruct.
  * @param  OPAx
  * @param  OPA_InitStruct 指向一个 @ref FL_OPA_InitTypeDef 结构体
  *         其中包含了外设的相关配置信息.
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS OPA配置成功
  */
FL_ErrorStatus FL_OPA_Init(OPA_Type *OPAx, FL_OPA_InitTypeDef *initStruct)
{
    FL_ErrorStatus status = FL_PASS;
    /* 入口参数检查 */
    assert_param(IS_OPA_ALL_INSTANCE(OPAx));
    assert_param(IS_FL_OPA_INP_CHANNAL(initStruct->INP));

    /*总线时钟使能*/
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_OPA);
    /*配置正向输入*/
    FL_OPA_SetINPSource(OPAx, initStruct->INP);

    return status;
}
/**
  * @brief  FL_OPA_InitTypeDef 为默认配置
  * @param  FL_OPA_InitTypeDef 指向需要将值设置为默认配置的结构体 @ref FL_OPA_InitTypeDef structure
  *         结构体
  * @retval None
  */

void FL_OPA_StructInit(FL_OPA_InitTypeDef *initStruct)
{
    initStruct->INP              = FL_OPA_INP_SOURCE_INP1;
}

/**
  * @}
  */

#endif /* FL_OPA_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
