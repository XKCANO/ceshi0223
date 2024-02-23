/**
  *******************************************************************************************************
  * @file    fm33lf0xx_fl_led.c
  * @author  FMSH Application Team
  * @brief   Src file of LED FL Module
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
/** @addtogroup FM33LF0xx_FL_Driver_LED
  * @{
  */

/** @addtogroup Private_Macros
  * @{
  */

#define         IS_FL_LED_INSTANCE(INTENCE)                 ((INTENCE) == LED)

#define         IS_FL_LED_COMNUM(__VALUE__)                 (((__VALUE__) == FL_LED_MAX_LINE_COM0)||\
                                                            ((__VALUE__) == FL_LED_MAX_LINE_COM0_1)||\
                                                            ((__VALUE__) == FL_LED_MAX_LINE_COM0_2)||\
                                                            ((__VALUE__) == FL_LED_MAX_LINE_COM0_3)||\
                                                            ((__VALUE__) == FL_LED_MAX_LINE_COM0_4)||\
                                                            ((__VALUE__) == FL_LED_MAX_LINE_COM0_5)||\
                                                            ((__VALUE__) == FL_LED_MAX_LINE_COM0_6)||\
                                                            ((__VALUE__) == FL_LED_MAX_LINE_COM0_7)||\
                                                            ((__VALUE__) == FL_LED_MAX_LINE_COM0_8)||\
                                                            ((__VALUE__) == FL_LED_MAX_LINE_COM0_9))  

#define         IS_FL_LED_COMFLT(__VALUE__)                 (((__VALUE__) == FL_LED_COM_IDLE_STATUS_OUTPUT)||\
                                                            ((__VALUE__) == FL_LED_COM_IDLE_STATUS_FLOAT))
 

#define         IS_FL_LED_DIGPOLAR(__VALUE__)               (((__VALUE__) == FL_LED_DIG_OUTPUT_POLARITY_NORMAL)||\
                                                            ((__VALUE__) == FL_LED_DIG_OUTPUT_POLARITY_INVERT)) 
                                                            
#define         IS_FL_LED_COMPOLAR(__VALUE__)               (((__VALUE__) == FL_LED_COM_OUTPUT_POLARITY_NORMAL)||\
                                                            ((__VALUE__) == FL_LED_COM_OUTPUT_POLARITY_INVERT)) 


#define         IS_FL_LED_CLKSOURCE(__VALUE__)              (((__VALUE__) == FL_CMU_LED_CLK_SOURCE_RCHF)||\
                                                            ((__VALUE__) == FL_CMU_LED_CLK_SOURCE_XTHF)||\
                                                            ((__VALUE__) == FL_CMU_LED_CLK_SOURCE_PLL)||\
                                                            ((__VALUE__) == FL_CMU_LED_CLK_SOURCE_APBCLK))
                                                            

#define         IS_FL_LED_PRESCALER(__VALUE__)              (((__VALUE__) == FL_CMU_LED_PSC_DIV1)||\
                                                            ((__VALUE__) == FL_CMU_LED_PSC_DIV2)||\
                                                            ((__VALUE__) == FL_CMU_LED_PSC_DIV4)||\
                                                            ((__VALUE__) == FL_CMU_LED_PSC_DIV8)||\
                                                            ((__VALUE__) == FL_CMU_LED_PSC_DIV16)||\
                                                            ((__VALUE__) == FL_CMU_LED_PSC_DIV32))
  
  
#define         IS_FL_LED_COMLENGTH(__VALUE__)              (__VALUE__<=255U)  

#define         IS_FL_LED_LSWBLKT(__VALUE__)                (__VALUE__<=31U)   

#define         IS_FL_LED_PHS(__VALUE__)                    (__VALUE__<=255U)  

#define         IS_FL_LED_SCANPRES(__VALUE__)               (__VALUE__<=15U)  

/**
  * @brief  复位对应LED寄存器.

  * @param  LEDx
  * @retval ErrorStatus枚举值:
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_LED_DeInit(LED_Type *LEDx)
{
    assert_param(IS_FL_LED_INSTANCE(LEDx));
    /* 使能外设复位 */
    FL_RMU_EnablePeripheralReset(RMU);
    /* 复位LED外设寄存器 */
    FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_LED);
    FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_LED);
    /* 关闭外设总线始时钟和工作时钟 */
    FL_CMU_DisableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_LED);
    /* 锁定外设复位 */
    FL_RMU_DisablePeripheralReset(RMU);
    return FL_PASS;
}

/**
  * @brief  根据 LED_InitStruct 的配置信息初始化对应外设入口地址的寄存器值.
  * @param  LEDx LEDx
  * @param  LED_InitStruct 指向一个 @ref FL_LED_InitTypeDef 结构体
  *         其中包含了外设的相关配置信息.
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS LED配置成功
  */
FL_ErrorStatus FL_LED_Init(LED_Type *LEDx, FL_LED_InitTypeDef *initStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    if(initStruct !=    NULL)
    {
        assert_param(IS_FL_LED_INSTANCE(LEDx));
        assert_param(IS_FL_LED_COMNUM(initStruct->COMxNum));
        assert_param(IS_FL_LED_COMFLT(initStruct->comFloat));
        assert_param(IS_FL_LED_DIGPOLAR(initStruct->digPolarity));
        assert_param(IS_FL_LED_COMPOLAR(initStruct->comPolarity));
        assert_param(IS_FL_LED_CLKSOURCE(initStruct->clkSource));
        assert_param(IS_FL_LED_PRESCALER(initStruct->Prescaler));
        assert_param(IS_FL_LED_COMLENGTH(initStruct->pwmPeriod));
        assert_param(IS_FL_LED_LSWBLKT(initStruct->lswBlank));
        assert_param(IS_FL_LED_PHS(initStruct->phs));
        assert_param(IS_FL_LED_SCANPRES(initStruct->scanPres));

        /* 外设总线始时钟 */
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_LED);    
        FL_CMU_SetLEDClockSource(initStruct->clkSource); 
        FL_CMU_SetLEDPrescaler(initStruct->Prescaler );
        FL_CMU_EnableGroup1OperationClock(FL_CMU_GROUP1_OPCLKEN_LED);
        
        FL_LED_SetPHS(LED, initStruct->phs);
        FL_LED_SetLineSwitchBlankTime(LED, initStruct->lswBlank);
        FL_LED_SetComIdleStauts(LED, initStruct->comFloat);
        
        /* COMx口个数 */
        FL_LED_SetMaxLine(LED, initStruct->COMxNum);
        /* seg 极性 */
        FL_LED_SetComOutputPolarity(LED, initStruct->comPolarity);
        /* dig 极性 */
        FL_LED_SetDigOutputPolarity(LED, initStruct->digPolarity);
        /* 设置预分频 */
        FL_LED_SetScanPrescaler(LED, initStruct->scanPres);
        /* 设置pwm周期 */
        FL_LED_SetComLength(LED, initStruct->pwmPeriod);
        /* 设置相移 */
        FL_LED_SetPHS(LED, initStruct->phs);
        if(initStruct->pwmEn == FL_ENABLE)
            FL_LED_EnablePwmDimmingEn(LED);
        else
            FL_LED_DisablePwmDimmingEn(LED);        

        
        
        
        status = FL_PASS;
    }
    return status;
}

/**
  * @brief  设置 LED_InitStruct 为默认配置
  * @param  LED_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_LED_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_LED_StructInit(FL_LED_InitTypeDef *initStruct)
{
    if(initStruct != NULL)
    {
        
        initStruct->clkSource           =   FL_CMU_LED_CLK_SOURCE_RCHF;
        initStruct->Prescaler           =   FL_CMU_LED_PSC_DIV1;
        initStruct->COMxNum             =   FL_LED_MAX_LINE_COM0_9;
        initStruct->comFloat            =   FL_LED_COM_IDLE_STATUS_OUTPUT;
        initStruct->comPolarity         =   FL_LED_COM_OUTPUT_POLARITY_NORMAL;
        initStruct->digPolarity         =   FL_LED_DIG_OUTPUT_POLARITY_NORMAL;
        initStruct->pwmEn               =   FL_DISABLE;
        initStruct->pwmPeriod           =   16;
        initStruct->scanPres            =   0;
        initStruct->phs                 =   0;
        initStruct->lswBlank            =   0;
    }
}


/**
  * @brief  设置 LED 显示字端
  * @param  display 指向显示信息的缓存区域，可直接指向LED的DOTx寄存器。
  * @param  com 待显示字段所在COM。范围0-9。
  * @param  dig 待显示字段所在SEG。范围0-15。
  * @param  state 待显示字段状态。0，熄灭；否则，点亮。
  *
  * @retval None
  */
void FL_LED_Display(uint32_t com, uint32_t dig, uint32_t state)
{
    volatile uint32_t *pData = &(LED->DOT0DR);
    if(com>9)
        return;
     if(com>15)
        return;
    if(state != 0)
    {
        state = 1;
    }
    MODIFY_REG(pData[com], 0x1 << dig, state << dig);
}

/**
  * @}
  */
/**
  * @}
  */
/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-10-17**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
