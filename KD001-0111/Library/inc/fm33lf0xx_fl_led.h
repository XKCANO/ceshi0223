/**
  *******************************************************************************************************
  * @file    fm33fl0xx_fl_led.h
  * @author  FMSH Application Team
  * @brief   Head file of LED FL Module
  *******************************************************************************************************
  * @attention
  *
  * Copyright (c) [2019] [Fudan Microelectronics]
  * THIS SOFTWARE is licensed under the Mulan PSL v1.
  * can use this software according to the terms and conditions of the Mulan PSL v1.
  * You may obtain a copy of Mulan PSL v1 at:
  * http://license.coscl.org.cn/MulanPSL
  * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
  * IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
  * PURPOSE.
  * See the Mulan PSL v1 for more details.
  *
  *******************************************************************************************************
  */


/* Define to prevent recursive inclusion---------------------------------------------------------------*/
#ifndef __FM33FL0XX_FL_LED_H
#define __FM33FL0XX_FL_LED_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33lf0xx_fl_def.h"
/** @addtogroup FM33FL0XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup LED_FL_ES_INIT LED Exported Init structures
  * @{
  */

/**
  * @brief FL LED Init Sturcture definition
  */
typedef struct
{
    /* COM个数 */
    uint32_t COMxNum;
    /* 空闲时com口状态 */
    uint32_t comFloat;
    /* com 极性 */
    uint32_t comPolarity;
    /* DIG 极性 */
    uint32_t digPolarity;
    /* pwm使能 */
    uint32_t pwmEn;
    /* pwm 周期 */
    uint32_t pwmPeriod;
    /* scan 预分频 */
    uint32_t scanPres;
    /* 相移 */
    uint32_t phs;  
    /* 行切换空闲时间*/
    uint32_t lswBlank;  
    /* 时钟源*/
    uint32_t clkSource; 
    /* 时钟分频系数*/
    uint32_t Prescaler;
    
} FL_LED_InitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup LED_FL_Exported_Constants LED Exported Constants
  * @{
  */

#define    LED_CR_DDMAEN_Pos                                      (3U)
#define    LED_CR_DDMAEN_Msk                                      (0x1U << LED_CR_DDMAEN_Pos)
#define    LED_CR_DDMAEN                                          LED_CR_DDMAEN_Msk

#define    LED_CR_PDMAEN_Pos                                      (2U)
#define    LED_CR_PDMAEN_Msk                                      (0x1U << LED_CR_PDMAEN_Pos)
#define    LED_CR_PDMAEN                                          LED_CR_PDMAEN_Msk

#define    LED_CR_PWMEN_Pos                                       (1U)
#define    LED_CR_PWMEN_Msk                                       (0x1U << LED_CR_PWMEN_Pos)
#define    LED_CR_PWMEN                                           LED_CR_PWMEN_Msk

#define    LED_CR_LEDEN_Pos                                       (0U)
#define    LED_CR_LEDEN_Msk                                       (0x1U << LED_CR_LEDEN_Pos)
#define    LED_CR_LEDEN                                           LED_CR_LEDEN_Msk

#define    LED_CFGR_PHS_Pos                                       (24U)
#define    LED_CFGR_PHS_Msk                                       (0xffU << LED_CFGR_PHS_Pos)
#define    LED_CFGR_PHS                                           LED_CFGR_PHS_Msk

#define    LED_CFGR_LSW_BLKT_Pos                                  (19U)
#define    LED_CFGR_LSW_BLKT_Msk                                  (0x1fU << LED_CFGR_LSW_BLKT_Pos)
#define    LED_CFGR_LSW_BLKT                                      LED_CFGR_LSW_BLKT_Msk

#define    LED_CFGR_COM_FLT_Pos                                   (18U)
#define    LED_CFGR_COM_FLT_Msk                                   (0x1U << LED_CFGR_COM_FLT_Pos)
#define    LED_CFGR_COM_FLT                                       LED_CFGR_COM_FLT_Msk

#define    LED_CFGR_DIG_POLAR_Pos                                 (17U)
#define    LED_CFGR_DIG_POLAR_Msk                                 (0x1U << LED_CFGR_DIG_POLAR_Pos)
#define    LED_CFGR_DIG_POLAR                                     LED_CFGR_DIG_POLAR_Msk

#define    LED_CFGR_COM_POLAR_Pos                                 (16U)
#define    LED_CFGR_COM_POLAR_Msk                                 (0x1U << LED_CFGR_COM_POLAR_Pos)
#define    LED_CFGR_COM_POLAR                                     LED_CFGR_COM_POLAR_Msk

#define    LED_CFGR_COM_LENGTH_Pos                                (8U)
#define    LED_CFGR_COM_LENGTH_Msk                                (0xffU << LED_CFGR_COM_LENGTH_Pos)
#define    LED_CFGR_COM_LENGTH                                    LED_CFGR_COM_LENGTH_Msk

#define    LED_CFGR_SCAN_PRES_Pos                                 (4U)
#define    LED_CFGR_SCAN_PRES_Msk                                 (0xfU << LED_CFGR_SCAN_PRES_Pos)
#define    LED_CFGR_SCAN_PRES                                     LED_CFGR_SCAN_PRES_Msk

#define    LED_CFGR_MAX_LINE_Pos                                  (0U)
#define    LED_CFGR_MAX_LINE_Msk                                  (0xfU << LED_CFGR_MAX_LINE_Pos)
#define    LED_CFGR_MAX_LINE                                      LED_CFGR_MAX_LINE_Msk

#define    LED_IER_FEIE_Pos                                       (1U)
#define    LED_IER_FEIE_Msk                                       (0x1U << LED_IER_FEIE_Pos)
#define    LED_IER_FEIE                                           LED_IER_FEIE_Msk

#define    LED_IER_LSIE_Pos                                       (0U)
#define    LED_IER_LSIE_Msk                                       (0x1U << LED_IER_LSIE_Pos)
#define    LED_IER_LSIE                                           LED_IER_LSIE_Msk

#define    LED_ISR_FEIF_Pos                                       (1U)
#define    LED_ISR_FEIF_Msk                                       (0x1U << LED_ISR_FEIF_Pos)
#define    LED_ISR_FEIF                                           LED_ISR_FEIF_Msk

#define    LED_ISR_DONIF_Pos                                      (0U)
#define    LED_ISR_DONIF_Msk                                      (0x1U << LED_ISR_DONIF_Pos)
#define    LED_ISR_DONIF                                          LED_ISR_DONIF_Msk

#define    LED_PWMCRA_CR3_Pos                                     (24U)
#define    LED_PWMCRA_CR3_Msk                                     (0xffU << LED_PWMCRA_CR3_Pos)
#define    LED_PWMCRA_CR3                                         LED_PWMCRA_CR3_Msk

#define    LED_PWMCRA_CR2_Pos                                     (16U)
#define    LED_PWMCRA_CR2_Msk                                     (0xffU << LED_PWMCRA_CR2_Pos)
#define    LED_PWMCRA_CR2                                         LED_PWMCRA_CR2_Msk

#define    LED_PWMCRA_CR1_Pos                                     (8U)
#define    LED_PWMCRA_CR1_Msk                                     (0xffU << LED_PWMCRA_CR1_Pos)
#define    LED_PWMCRA_CR1                                         LED_PWMCRA_CR1_Msk

#define    LED_PWMCRA_CR0_Pos                                     (0U)
#define    LED_PWMCRA_CR0_Msk                                     (0xffU << LED_PWMCRA_CR0_Pos)
#define    LED_PWMCRA_CR0                                         LED_PWMCRA_CR0_Msk

#define    LED_PWMCRB_CR7_Pos                                     (24U)
#define    LED_PWMCRB_CR7_Msk                                     (0xffU << LED_PWMCRB_CR7_Pos)
#define    LED_PWMCRB_CR7                                         LED_PWMCRB_CR7_Msk

#define    LED_PWMCRB_CR6_Pos                                     (16U)
#define    LED_PWMCRB_CR6_Msk                                     (0xffU << LED_PWMCRB_CR6_Pos)
#define    LED_PWMCRB_CR6                                         LED_PWMCRB_CR6_Msk

#define    LED_PWMCRB_CR5_Pos                                     (8U)
#define    LED_PWMCRB_CR5_Msk                                     (0xffU << LED_PWMCRB_CR5_Pos)
#define    LED_PWMCRB_CR5                                         LED_PWMCRB_CR5_Msk

#define    LED_PWMCRB_CR4_Pos                                     (0U)
#define    LED_PWMCRB_CR4_Msk                                     (0xffU << LED_PWMCRB_CR4_Pos)
#define    LED_PWMCRB_CR4                                         LED_PWMCRB_CR4_Msk

#define    LED_PWMCRC_CR11_Pos                                    (24U)
#define    LED_PWMCRC_CR11_Msk                                    (0xffU << LED_PWMCRC_CR11_Pos)
#define    LED_PWMCRC_CR11                                        LED_PWMCRC_CR11_Msk

#define    LED_PWMCRC_CR10_Pos                                    (16U)
#define    LED_PWMCRC_CR10_Msk                                    (0xffU << LED_PWMCRC_CR10_Pos)
#define    LED_PWMCRC_CR10                                        LED_PWMCRC_CR10_Msk

#define    LED_PWMCRC_CR9_Pos                                     (8U)
#define    LED_PWMCRC_CR9_Msk                                     (0xffU << LED_PWMCRC_CR9_Pos)
#define    LED_PWMCRC_CR9                                         LED_PWMCRC_CR9_Msk

#define    LED_PWMCRC_CR8_Pos                                     (0U)
#define    LED_PWMCRC_CR8_Msk                                     (0xffU << LED_PWMCRC_CR8_Pos)
#define    LED_PWMCRC_CR8                                         LED_PWMCRC_CR8_Msk

#define    LED_PWMCRD_CR15_Pos                                    (24U)
#define    LED_PWMCRD_CR15_Msk                                    (0xffU << LED_PWMCRD_CR15_Pos)
#define    LED_PWMCRD_CR15                                        LED_PWMCRD_CR15_Msk

#define    LED_PWMCRD_CR14_Pos                                    (16U)
#define    LED_PWMCRD_CR14_Msk                                    (0xffU << LED_PWMCRD_CR14_Pos)
#define    LED_PWMCRD_CR14                                        LED_PWMCRD_CR14_Msk

#define    LED_PWMCRD_CR13_Pos                                    (8U)
#define    LED_PWMCRD_CR13_Msk                                    (0xffU << LED_PWMCRD_CR13_Pos)
#define    LED_PWMCRD_CR13                                        LED_PWMCRD_CR13_Msk

#define    LED_PWMCRD_CR12_Pos                                    (0U)
#define    LED_PWMCRD_CR12_Msk                                    (0xffU << LED_PWMCRD_CR12_Pos)
#define    LED_PWMCRD_CR12                                        LED_PWMCRD_CR12_Msk

#define    LED_DOT_DATA_Pos                                       (0U)
#define    LED_DOT_DATA_Msk                                       (0x0000ffffU << LED_DOT_DATA_Pos)
#define    LED_DOT_DATA                                           LED_DOT_DATA_Msk

#define    LED_DMACR_DDTRIG_Pos                                   (8U)
#define    LED_DMACR_DDTRIG_Msk                                   (0x1U << LED_DMACR_DDTRIG_Pos)
#define    LED_DMACR_DDTRIG                                       LED_DMACR_DDTRIG_Msk

#define    LED_DMACR_DOTDR_LEN_Pos                                (4U)
#define    LED_DMACR_DOTDR_LEN_Msk                                (0xfU << LED_DMACR_DOTDR_LEN_Pos)
#define    LED_DMACR_DOTDR_LEN                                    LED_DMACR_DOTDR_LEN_Msk

#define    LED_DMACR_PWMCR_LEN_Pos                                (0U)
#define    LED_DMACR_PWMCR_LEN_Msk                                (0x7U << LED_DMACR_PWMCR_LEN_Pos)
#define    LED_DMACR_PWMCR_LEN                                    LED_DMACR_PWMCR_LEN_Msk

#define    LED_DPCAR_ADDR_Pos                                     (0U)
#define    LED_DPCAR_ADDR_Msk                                     (0xffffffffU << LED_DPCAR_ADDR_Pos)
#define    LED_DPCAR_ADDR                                         LED_DPCAR_ADDR_Msk

#define    LED_DDRAR_ADDR_Pos                                     (0U)
#define    LED_DDRAR_ADDR_Msk                                     (0xffffffffU << LED_DDRAR_ADDR_Pos)
#define    LED_DDRAR_ADDR                                         LED_DDRAR_ADDR_Msk

#define    LED_CCOM_ACT_COM_Pos                                   (0U)
#define    LED_CCOM_ACT_COM_Msk                                   (0x3ffU << LED_CCOM_ACT_COM_Pos)
#define    LED_CCOM_ACT_COM                                       LED_CCOM_ACT_COM_Msk



#define    FL_LED_DOT_REG0                                        (0x0U << 0U)
#define    FL_LED_DOT_REG1                                        (0x1U << 0U)
#define    FL_LED_DOT_REG2                                        (0x2U << 0U)
#define    FL_LED_DOT_REG3                                        (0x3U << 0U)
#define    FL_LED_DOT_REG4                                        (0x4U << 0U)
#define    FL_LED_DOT_REG5                                        (0x5U << 0U)
#define    FL_LED_DOT_REG6                                        (0x6U << 0U)
#define    FL_LED_DOT_REG7                                        (0x7U << 0U)
#define    FL_LED_DOT_REG8                                        (0x8U << 0U)
#define    FL_LED_DOT_REG9                                        (0x9U << 0U)



#define    FL_LED_COM_IDLE_STATUS_OUTPUT                          (0x0U << LED_CFGR_COM_FLT_Pos)
#define    FL_LED_COM_IDLE_STATUS_FLOAT                           (0x1U << LED_CFGR_COM_FLT_Pos)


#define    FL_LED_DIG_OUTPUT_POLARITY_NORMAL                          (0x0U << LED_CFGR_DIG_POLAR_Pos)
#define    FL_LED_DIG_OUTPUT_POLARITY_INVERT                          (0x1U << LED_CFGR_DIG_POLAR_Pos)


#define    FL_LED_COM_OUTPUT_POLARITY_NORMAL                          (0x0U << LED_CFGR_COM_POLAR_Pos)
#define    FL_LED_COM_OUTPUT_POLARITY_INVERT                          (0x1U << LED_CFGR_COM_POLAR_Pos)


#define    FL_LED_MAX_LINE_COM0                                   (0x1U << LED_CFGR_MAX_LINE_Pos)
#define    FL_LED_MAX_LINE_COM0_1                                 (0x2U << LED_CFGR_MAX_LINE_Pos)
#define    FL_LED_MAX_LINE_COM0_2                                 (0x3U << LED_CFGR_MAX_LINE_Pos)
#define    FL_LED_MAX_LINE_COM0_3                                 (0x4U << LED_CFGR_MAX_LINE_Pos)
#define    FL_LED_MAX_LINE_COM0_4                                 (0x5U << LED_CFGR_MAX_LINE_Pos)
#define    FL_LED_MAX_LINE_COM0_5                                 (0x6U << LED_CFGR_MAX_LINE_Pos)
#define    FL_LED_MAX_LINE_COM0_6                                 (0x7U << LED_CFGR_MAX_LINE_Pos)
#define    FL_LED_MAX_LINE_COM0_7                                 (0x8U << LED_CFGR_MAX_LINE_Pos)
#define    FL_LED_MAX_LINE_COM0_8                                 (0x9U << LED_CFGR_MAX_LINE_Pos)
#define    FL_LED_MAX_LINE_COM0_9                                 (0xaU << LED_CFGR_MAX_LINE_Pos)

#define    FL_LED_REQUEST_BY_FRAME_END                            (0x0U << LED_DMACR_DDTRIG_Pos)
#define    FL_LED_REQUEST_BY_TRIG_SYNC                            (0x1U << LED_DMACR_DDTRIG_Pos)


#define    FL_LED_DOT_DR0                                         (0x1U << LED_DMACR_DOTDR_LEN_Pos)
#define    FL_LED_DOT_DR0_1                                       (0x2U << LED_DMACR_DOTDR_LEN_Pos)
#define    FL_LED_DOT_DR0_2                                       (0x3U << LED_DMACR_DOTDR_LEN_Pos)
#define    FL_LED_DOT_DR0_3                                       (0x4U << LED_DMACR_DOTDR_LEN_Pos)
#define    FL_LED_DOT_DR0_4                                       (0x5U << LED_DMACR_DOTDR_LEN_Pos)
#define    FL_LED_DOT_DR0_5                                       (0x6U << LED_DMACR_DOTDR_LEN_Pos)
#define    FL_LED_DOT_DR0_6                                       (0x7U << LED_DMACR_DOTDR_LEN_Pos)
#define    FL_LED_DOT_DR0_7                                       (0x8U << LED_DMACR_DOTDR_LEN_Pos)
#define    FL_LED_DOT_DR0_8                                       (0x9U << LED_DMACR_DOTDR_LEN_Pos)
#define    FL_LED_DOT_DR0_9                                       (0xaU << LED_DMACR_DOTDR_LEN_Pos)

#define    FL_LED_PWM_CRA                                         (0x1U << LED_DMACR_PWMCR_LEN_Pos)
#define    FL_LED_PWM_CRA_B                                       (0x2U << LED_DMACR_PWMCR_LEN_Pos)
#define    FL_LED_PWM_CRA_C                                       (0x3U << LED_DMACR_PWMCR_LEN_Pos)
#define    FL_LED_PWM_CRA_D                                       (0x4U << LED_DMACR_PWMCR_LEN_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup LED_FL_Exported_Functions LED Exported Functions
  * @{
  */

/**
  * @brief    Enable LED DotDMA
  * @rmtoll   CR    DDMAEN    FL_LED_EnableDotDmaEn
  * @param    LEDx LED instance
  * @retval   None
  */
__STATIC_INLINE void FL_LED_EnableDotDmaEn(LED_Type* LEDx)
{
    SET_BIT(LEDx->CR, LED_CR_DDMAEN_Msk);
}

/**
  * @brief    Disable LED DotDMA
  * @rmtoll   CR    DDMAEN    FL_LED_DisableDotDmaEn
  * @param    LEDx LED instance
  * @retval   None
  */
__STATIC_INLINE void FL_LED_DisableDotDmaEn(LED_Type* LEDx)
{
    CLEAR_BIT(LEDx->CR, LED_CR_DDMAEN_Msk);
}

/**
  * @brief    Get LED DotDMA State
  * @rmtoll   CR    DDMAEN    FL_LED_IsEnabledDotDmaEn
  * @param    LEDx LED instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_LED_IsEnabledDotDmaEn(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->CR, LED_CR_DDMAEN_Msk) == LED_CR_DDMAEN_Msk);
}

/**
  * @brief    Enable LED PWM DMA
  * @rmtoll   CR    PDMAEN    FL_LED_EnablePwmDmaEn
  * @param    LEDx LED instance
  * @retval   None
  */
__STATIC_INLINE void FL_LED_EnablePwmDmaEn(LED_Type* LEDx)
{
    SET_BIT(LEDx->CR, LED_CR_PDMAEN_Msk);
}

/**
  * @brief    Disable LED PWM DMA
  * @rmtoll   CR    PDMAEN    FL_LED_DisablePwmDmaEn
  * @param    LEDx LED instance
  * @retval   None
  */
__STATIC_INLINE void FL_LED_DisablePwmDmaEn(LED_Type* LEDx)
{
    CLEAR_BIT(LEDx->CR, LED_CR_PDMAEN_Msk);
}

/**
  * @brief    Get LED Blink PWM DMA
  * @rmtoll   CR    PDMAEN    FL_LED_IsEnabledPwmDmaEn
  * @param    LEDx LED instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_LED_IsEnabledPwmDmaEn(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->CR, LED_CR_PDMAEN_Msk) == LED_CR_PDMAEN_Msk);
}

/**
  * @brief    Enable LED PWM Dimming
  * @rmtoll   CR    PWMEN    FL_LED_EnablePwmDimmingEn
  * @param    LEDx LED instance
  * @retval   None
  */
__STATIC_INLINE void FL_LED_EnablePwmDimmingEn(LED_Type* LEDx)
{
    SET_BIT(LEDx->CR, LED_CR_PWMEN_Msk);
}

/**
  * @brief    Disable LED PWM Dimming
  * @rmtoll   CR    PWMEN    FL_LED_DisablePwmDimmingEn
  * @param    LEDx LED instance
  * @retval   None
  */
__STATIC_INLINE void FL_LED_DisablePwmDimmingEn(LED_Type* LEDx)
{
    CLEAR_BIT(LEDx->CR, LED_CR_PWMEN_Msk);
}

/**
  * @brief    Get LED PWM Dimming State
  * @rmtoll   CR    PWMEN    FL_LED_IsEnabledPwmDimmingEn
  * @param    LEDx LED instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_LED_IsEnabledPwmDimmingEn(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->CR, LED_CR_PWMEN_Msk) == LED_CR_PWMEN_Msk);
}

/**
  * @brief    Enable LED 
  * @rmtoll   CR    LEDEN    FL_LED_Enable
  * @param    LEDx LED instance
  * @retval   None
  */
__STATIC_INLINE void FL_LED_Enable(LED_Type* LEDx)
{
    SET_BIT(LEDx->CR, LED_CR_LEDEN_Msk);
}

/**
  * @brief    Disable LED 
  * @rmtoll   CR    LEDEN    FL_LED_Disable
  * @param    LEDx LED instance
  * @retval   None
  */
__STATIC_INLINE void FL_LED_Disable(LED_Type* LEDx)
{
    CLEAR_BIT(LEDx->CR, LED_CR_LEDEN_Msk);
}

/**
  * @brief    Get LED State
  * @rmtoll   CR    LEDEN    FL_LED_IsEnabled
  * @param    LEDx LED instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_LED_IsEnabled(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->CR, LED_CR_LEDEN_Msk) == LED_CR_LEDEN_Msk);
}

/**
  * @brief    Set LED PHS Time
  * @rmtoll   CFGR    PHS    FL_LED_SetPHS
  * @param    LEDx LED instance
  * @param    phs This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetPHS(LED_Type* LEDx, uint32_t phs)
{
    MODIFY_REG(LEDx->CFGR, LED_CFGR_PHS_Msk, phs<<24);
}

/**
  * @brief    Get LED PHS Time
  * @rmtoll   CFGR    PHS    FL_LED_GetPHS
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetPHS(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->CFGR, LED_CFGR_PHS_Msk));
}

/**
  * @brief    Set Line Switch Blank Time
  * @rmtoll   CFGR    LSW_BLKT    FL_LED_SetLineSwitchBlankTime
  * @param    LEDx LED instance
  * @param    blankTimeUs This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetLineSwitchBlankTime(LED_Type* LEDx, uint32_t blankTimeUs)
{
    MODIFY_REG(LEDx->CFGR, LED_CFGR_LSW_BLKT_Msk, blankTimeUs<<19);
}

/**
  * @brief    Get Line Switch Blank Time
  * @rmtoll   CFGR    LSW_BLKT    FL_LED_GetLineSwitchBlankTime
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetLineSwitchBlankTime(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->CFGR, LED_CFGR_LSW_BLKT_Msk));
}

/**
  * @brief    Set COM Idle Stauts
  * @rmtoll   CFGR    COM_FLT    FL_LED_SetComIdleStauts
  * @param    LEDx LED instance
  * @param    status This parameter can be one of the following values:
  *           @arg @ref FL_LED_COM_IDLE_STATUS_OUTPUT
  *           @arg @ref FL_LED_COM_IDLE_STATUS_FLOAT
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetComIdleStauts(LED_Type* LEDx, uint32_t status)
{
    MODIFY_REG(LEDx->CFGR, LED_CFGR_COM_FLT_Msk, status);
}

/**
  * @brief    Get COM  Idle Stauts
  * @rmtoll   CFGR    COM_FLT    FL_LED_GetComIdleStauts
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_LED_COM_IDLE_STATUS_OUTPUT
  *           @arg @ref FL_LED_COM_IDLE_STATUS_FLOAT
  */
__STATIC_INLINE uint32_t FL_LED_GetComIdleStauts(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->CFGR, LED_CFGR_COM_FLT_Msk));
}

/**
  * @brief    Set LED Dig Pin Output Polarity
  * @rmtoll   CFGR    DIG_POLAR    FL_LED_SetSegDigOutputPolarity
  * @param    LEDx LED instance
  * @param    polarity This parameter can be one of the following values:
  *           @arg @ref FL_LED_OUTPUT_POLARITY_NORMAL
  *           @arg @ref FL_LED_OUTPUT_POLARITY_INVERT
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetDigOutputPolarity(LED_Type* LEDx, uint32_t polarity)
{
    MODIFY_REG(LEDx->CFGR, LED_CFGR_DIG_POLAR_Msk, polarity);
}

/**
  * @brief    Get LED Dig Pin Output Polarity
  * @rmtoll   CFGR    DIG_POLAR    FL_LED_GetSegDigOutputPolarity
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_LED_OUTPUT_POLARITY_NORMAL
  *           @arg @ref FL_LED_OUTPUT_POLARITY_INVERT
  */
__STATIC_INLINE uint32_t FL_LED_GetDigOutputPolarity(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->CFGR, LED_CFGR_DIG_POLAR_Msk));
}

/**
  * @brief    Set LED Com Pin Output Polarity
  * @rmtoll   CFGR    COM_POLAR    FL_LED_SetSegComOutputPolarity
  * @param    LEDx LED instance
  * @param    polarity This parameter can be one of the following values:
  *           @arg @ref FL_LED_OUTPUT_POLARITY_NORMAL
  *           @arg @ref FL_LED_OUTPUT_POLARITY_INVERT
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetComOutputPolarity(LED_Type* LEDx, uint32_t polarity)
{
    MODIFY_REG(LEDx->CFGR, LED_CFGR_COM_POLAR_Msk, polarity);
}

/**
  * @brief    Get LED Com Pin Output Polarity
  * @rmtoll   CFGR    COM_POLAR    FL_LED_GetSegComOutputPolarity
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_LED_OUTPUT_POLARITY_NORMAL
  *           @arg @ref FL_LED_OUTPUT_POLARITY_INVERT
  */
__STATIC_INLINE uint32_t FL_LED_GetComOutputPolarity(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->CFGR, LED_CFGR_COM_POLAR_Msk));
}

/**
  * @brief    Set LED Com Length Time
  * @rmtoll   CFGR    COM_LENGTH    FL_LED_SetComLength
  * @param    LEDx LED instance
  * @param    comLength This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetComLength(LED_Type* LEDx, uint32_t comLength)
{
    MODIFY_REG(LEDx->CFGR, LED_CFGR_COM_LENGTH_Msk, comLength<<8);
}

/**
  * @brief    Get LED Com Length Time
  * @rmtoll   CFGR    COM_LENGTH    FL_LED_GetComLength
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetComLength(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->CFGR, LED_CFGR_COM_LENGTH_Msk));
}

/**
  * @brief    Set LED Scan Prescaler Time
  * @rmtoll   CFGR    SCAN_PRES    FL_LED_SetScanPrescaler
  * @param    LEDx LED instance
  * @param    Prescaler This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetScanPrescaler(LED_Type* LEDx, uint32_t Prescaler)
{
    MODIFY_REG(LEDx->CFGR, LED_CFGR_SCAN_PRES_Msk, Prescaler<<4);
}

/**
  * @brief    Get LED Scan Prescaler Time
  * @rmtoll   CFGR    SCAN_PRES    FL_LED_GetScanPrescaler
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetScanPrescaler(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->CFGR, LED_CFGR_SCAN_PRES_Msk));
}

/**
  * @brief    Set Max Line
  * @rmtoll   CFGR    MAX_LINE    FL_LED_SetMaxLine
  * @param    LEDx LED instance
  * @param    maxLine This parameter can be one of the following values:
  *           @arg @ref FL_LED_MAX_LINE_COM0
  *           @arg @ref FL_LED_MAX_LINE_COM0_1
  *           @arg @ref FL_LED_MAX_LINE_COM0_2
  *           @arg @ref FL_LED_MAX_LINE_COM0_3
  *           @arg @ref FL_LED_MAX_LINE_COM0_4
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetMaxLine(LED_Type* LEDx, uint32_t maxLine)
{
    MODIFY_REG(LEDx->CFGR, LED_CFGR_MAX_LINE_Msk, maxLine);
}

/**
  * @brief    Get Max Line
  * @rmtoll   CFGR    MAX_LINE    FL_LED_GetMaxLine
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_LED_MAX_LINE_COM0
  *           @arg @ref FL_LED_MAX_LINE_COM0_1
  *           @arg @ref FL_LED_MAX_LINE_COM0_2
  *           @arg @ref FL_LED_MAX_LINE_COM0_3
  *           @arg @ref FL_LED_MAX_LINE_COM0_4
  *           @arg @ref FL_LED_MAX_LINE_COM0_5
  *           @arg @ref FL_LED_MAX_LINE_COM0_6
  *           @arg @ref FL_LED_MAX_LINE_COM0_7
  *           @arg @ref FL_LED_MAX_LINE_COM0_8
  *           @arg @ref FL_LED_MAX_LINE_COM0_9
  */
__STATIC_INLINE uint32_t FL_LED_GetMaxLine(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->CFGR, LED_CFGR_MAX_LINE_Msk));
}

/**
  * @brief    Enable LED Frame End IRQ
  * @rmtoll   IER    FEIE    FL_LED_EnableIT_FrameEnd
  * @param    LEDx LED instance
  * @retval   None
  */
__STATIC_INLINE void FL_LED_EnableIT_FrameEnd(LED_Type* LEDx)
{
    SET_BIT(LEDx->IER, LED_IER_FEIE_Msk);
}

/**
  * @brief    Disable LED Frame End IRQ
  * @rmtoll   IER    FEIE    FL_LED_DisableIT_FrameEnd
  * @param    LEDx LED instance
  * @retval   None
  */
__STATIC_INLINE void FL_LED_DisableIT_FrameEnd(LED_Type* LEDx)
{
    CLEAR_BIT(LEDx->IER, LED_IER_FEIE_Msk);
}

/**
  * @brief    Getable LED Frame End IRQ
  * @rmtoll   IER    FEIE    FL_LED_IsEnabledIT_FrameEnd
  * @param    LEDx LED instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_LED_IsEnabledIT_FrameEnd(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->IER, LED_IER_FEIE_Msk) == LED_IER_FEIE_Msk);
}

/**
  * @brief    Enable LED Line Switch IRQ
  * @rmtoll   IER    LSIE    FL_LED_EnableIT_LineSwitch
  * @param    LEDx LED instance
  * @retval   None
  */
__STATIC_INLINE void FL_LED_EnableIT_LineSwitch(LED_Type* LEDx)
{
    SET_BIT(LEDx->IER, LED_IER_LSIE_Msk);
}

/**
  * @brief    Disable LED Line Switch IRQ
  * @rmtoll   IER    LSIE    FL_LED_DisableIT_LineSwitch
  * @param    LEDx LED instance
  * @retval   None
  */
__STATIC_INLINE void FL_LED_DisableIT_LineSwitch(LED_Type* LEDx)
{
    CLEAR_BIT(LEDx->IER, LED_IER_LSIE_Msk);
}

/**
  * @brief    Getable LED Line Switch IRQ
  * @rmtoll   IER    LSIE    FL_LED_IsEnabledIT_LineSwitch
  * @param    LEDx LED instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_LED_IsEnabledIT_LineSwitch(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->IER, LED_IER_LSIE_Msk) == LED_IER_LSIE_Msk);
}

/**
  * @brief    Get LED Frame End Flag
  * @rmtoll   ISR    FEIF    FL_LED_IsActiveFlag_FrameEnd
  * @param    LEDx LED instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_LED_IsActiveFlag_FrameEnd(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->ISR, LED_ISR_FEIF_Msk) == (LED_ISR_FEIF_Msk));
}

/**
  * @brief    Clear LED Frame EndF Flag
  * @rmtoll   ISR    FEIF    FL_LED_ClearFlag_FrameEnd
  * @param    LEDx LED instance
  * @retval   None
  */
__STATIC_INLINE void FL_LED_ClearFlag_FrameEnd(LED_Type* LEDx)
{
    WRITE_REG(LEDx->ISR, LED_ISR_FEIF_Msk);
}

/**
  * @brief    Get LED Line Switch Flag
  * @rmtoll   ISR    DONIF    FL_LED_IsActiveFlag_LineSwitch
  * @param    LEDx LED instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_LED_IsActiveFlag_LineSwitch(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->ISR, LED_ISR_DONIF_Msk) == (LED_ISR_DONIF_Msk));
}

/**
  * @brief    Clear LED Line Switch Flag
  * @rmtoll   ISR    DONIF    FL_LED_ClearFlag_LineSwitch
  * @param    LEDx LED instance
  * @retval   None
  */
__STATIC_INLINE void FL_LED_ClearFlag_LineSwitch(LED_Type* LEDx)
{
    WRITE_REG(LEDx->ISR, LED_ISR_DONIF_Msk);
}

/**
  * @brief    Set LED Dig3 PWM
  * @rmtoll   PWMCRA    CR3    FL_LED_SetDig3PwmCr
  * @param    LEDx LED instance
  * @param    cr This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetDig3PwmCr(LED_Type* LEDx, uint32_t cr)
{
    MODIFY_REG(LEDx->PWMCRA, LED_PWMCRA_CR3_Msk, cr<<24);
}

/**
  * @brief    Get LED Dig3 PWM
  * @rmtoll   PWMCRA    CR3    FL_LED_GetDig3PwmCr
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetDig3PwmCr(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->PWMCRA, LED_PWMCRA_CR3_Msk));
}

/**
  * @brief    Set LED Dig2 PWM
  * @rmtoll   PWMCRA    CR2    FL_LED_SetDig2PwmCr
  * @param    LEDx LED instance
  * @param    cr This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetDig2PwmCr(LED_Type* LEDx, uint32_t cr)
{
    MODIFY_REG(LEDx->PWMCRA, LED_PWMCRA_CR2_Msk, cr<<16);
}

/**
  * @brief    Get LED Dig2 PWM
  * @rmtoll   PWMCRA    CR2    FL_LED_GetDig2PwmCr
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetDig2PwmCr(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->PWMCRA, LED_PWMCRA_CR2_Msk));
}

/**
  * @brief    Set LED Dig1 PWM
  * @rmtoll   PWMCRA    CR1    FL_LED_SetDig1PwmCr
  * @param    LEDx LED instance
  * @param    cr This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetDig1PwmCr(LED_Type* LEDx, uint32_t cr)
{
    MODIFY_REG(LEDx->PWMCRA, LED_PWMCRA_CR1_Msk, cr<<8);
}

/**
  * @brief    Get LED Dig1 PWM
  * @rmtoll   PWMCRA    CR1    FL_LED_GetDig1PwmCr
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetDig1PwmCr(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->PWMCRA, LED_PWMCRA_CR1_Msk));
}

/**
  * @brief    Set LED Dig0 PWM
  * @rmtoll   PWMCRA    CR0    FL_LED_SetDig0PwmCr
  * @param    LEDx LED instance
  * @param    cr This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetDig0PwmCr(LED_Type* LEDx, uint32_t cr)
{
    MODIFY_REG(LEDx->PWMCRA, LED_PWMCRA_CR0_Msk, cr<<0);
}

/**
  * @brief    Get LED Dig0 PWM
  * @rmtoll   PWMCRA    CR0    FL_LED_GetDig0PwmCr
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetDig0PwmCr(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->PWMCRA, LED_PWMCRA_CR0_Msk));
}

/**
  * @brief    Set LED Dig7 PWM
  * @rmtoll   PWMCRB    CR7    FL_LED_SetDig7PwmCr
  * @param    LEDx LED instance
  * @param    cr This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetDig7PwmCr(LED_Type* LEDx, uint32_t cr)
{
    MODIFY_REG(LEDx->PWMCRB, LED_PWMCRB_CR7_Msk, cr<<24);
}

/**
  * @brief    Get LED Dig7 PWM
  * @rmtoll   PWMCRB    CR7    FL_LED_GetDig7PwmCr
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetDig7PwmCr(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->PWMCRB, LED_PWMCRB_CR7_Msk));
}

/**
  * @brief    Set LED Dig6 PWM
  * @rmtoll   PWMCRB    CR6    FL_LED_SetDig6PwmCr
  * @param    LEDx LED instance
  * @param    cr This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetDig6PwmCr(LED_Type* LEDx, uint32_t cr)
{
    MODIFY_REG(LEDx->PWMCRB, LED_PWMCRB_CR6_Msk, cr<<16);
}

/**
  * @brief    Get LED Dig6 PWM
  * @rmtoll   PWMCRB    CR6    FL_LED_GetDig6PwmCr
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetDig6PwmCr(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->PWMCRB, LED_PWMCRB_CR6_Msk));
}

/**
  * @brief    Set LED Dig5 PWM
  * @rmtoll   PWMCRB    CR5    FL_LED_SetDig5PwmCr
  * @param    LEDx LED instance
  * @param    cr This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetDig5PwmCr(LED_Type* LEDx, uint32_t cr)
{
    MODIFY_REG(LEDx->PWMCRB, LED_PWMCRB_CR5_Msk, cr<<8);
}

/**
  * @brief    Get LED Dig5 PWM
  * @rmtoll   PWMCRB    CR5    FL_LED_GetDig5PwmCr
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetDig5PwmCr(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->PWMCRB, LED_PWMCRB_CR5_Msk));
}

/**
  * @brief    Set LED Dig4 PWM
  * @rmtoll   PWMCRB    CR4    FL_LED_SetDig4PwmCr
  * @param    LEDx LED instance
  * @param    cr This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetDig4PwmCr(LED_Type* LEDx, uint32_t cr)
{
    MODIFY_REG(LEDx->PWMCRB, LED_PWMCRB_CR4_Msk, cr<<0);
}

/**
  * @brief    Get LED Dig4 PWM
  * @rmtoll   PWMCRB    CR4    FL_LED_GetDig4PwmCr
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetDig4PwmCr(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->PWMCRB, LED_PWMCRB_CR4_Msk));
}

/**
  * @brief    Set LED Dig11 PWM
  * @rmtoll   PWMCRC    CR11    FL_LED_SetDig11PwmCr
  * @param    LEDx LED instance
  * @param    cr This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetDig11PwmCr(LED_Type* LEDx, uint32_t cr)
{
    MODIFY_REG(LEDx->PWMCRC, LED_PWMCRC_CR11_Msk, cr<<24);
}

/**
  * @brief    Get LED Dig11 PWM
  * @rmtoll   PWMCRC    CR11    FL_LED_GetDig11PwmCr
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetDig11PwmCr(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->PWMCRC, LED_PWMCRC_CR11_Msk));
}

/**
  * @brief    Set LED Dig10 PWM
  * @rmtoll   PWMCRC    CR10    FL_LED_SetDig10PwmCr
  * @param    LEDx LED instance
  * @param    cr This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetDig10PwmCr(LED_Type* LEDx, uint32_t cr)
{
    MODIFY_REG(LEDx->PWMCRC, LED_PWMCRC_CR10_Msk, cr<<16);
}

/**
  * @brief    Get LED Dig10 PWM
  * @rmtoll   PWMCRC    CR10    FL_LED_GetDig10PwmCr
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetDig10PwmCr(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->PWMCRC, LED_PWMCRC_CR10_Msk));
}

/**
  * @brief    Set LED Dig9 PWM
  * @rmtoll   PWMCRC    CR9    FL_LED_SetDig9PwmCr
  * @param    LEDx LED instance
  * @param    cr This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetDig9PwmCr(LED_Type* LEDx, uint32_t cr)
{
    MODIFY_REG(LEDx->PWMCRC, LED_PWMCRC_CR9_Msk, cr<<8);
}

/**
  * @brief    Get LED Dig9 PWM
  * @rmtoll   PWMCRC    CR9    FL_LED_GetDig9PwmCr
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetDig9PwmCr(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->PWMCRC, LED_PWMCRC_CR9_Msk));
}

/**
  * @brief    Set LED Dig8 PWM
  * @rmtoll   PWMCRC    CR8    FL_LED_SetDig8PwmCr
  * @param    LEDx LED instance
  * @param    cr This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetDig8PwmCr(LED_Type* LEDx, uint32_t cr)
{
    MODIFY_REG(LEDx->PWMCRC, LED_PWMCRC_CR8_Msk, cr<<0);
}

/**
  * @brief    Get LED Dig8 PWM
  * @rmtoll   PWMCRC    CR8    FL_LED_GetDig8PwmCr
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetDig8PwmCr(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->PWMCRC, LED_PWMCRC_CR8_Msk));
}

/**
  * @brief    Set LED Dig15 PWM
  * @rmtoll   PWMCRD    CR15    FL_LED_SetDig15PwmCr
  * @param    LEDx LED instance
  * @param    cr This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetDig15PwmCr(LED_Type* LEDx, uint32_t cr)
{
    MODIFY_REG(LEDx->PWMCRD, LED_PWMCRD_CR15_Msk, cr<<24);
}

/**
  * @brief    Get LED Dig15 PWM
  * @rmtoll   PWMCRD    CR15    FL_LED_GetDig15PwmCr
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetDig15PwmCr(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->PWMCRD, LED_PWMCRD_CR15_Msk));
}

/**
  * @brief    Set LED Dig14 PWM
  * @rmtoll   PWMCRD    CR14    FL_LED_SetDig14PwmCr
  * @param    LEDx LED instance
  * @param    cr This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetDig14PwmCr(LED_Type* LEDx, uint32_t cr)
{
    MODIFY_REG(LEDx->PWMCRD, LED_PWMCRD_CR14_Msk, cr<<16);
}

/**
  * @brief    Get LED Dig14 PWM
  * @rmtoll   PWMCRD    CR14    FL_LED_GetDig14PwmCr
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetDig14PwmCr(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->PWMCRD, LED_PWMCRD_CR14_Msk));
}

/**
  * @brief    Set LED Dig13 PWM
  * @rmtoll   PWMCRD    CR13    FL_LED_SetDig13PwmCr
  * @param    LEDx LED instance
  * @param    cr This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetDig13PwmCr(LED_Type* LEDx, uint32_t cr)
{
    MODIFY_REG(LEDx->PWMCRD, LED_PWMCRD_CR13_Msk, cr<<8);
}

/**
  * @brief    Get LED Dig13 PWM
  * @rmtoll   PWMCRD    CR13    FL_LED_GetDig13PwmCr
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetDig13PwmCr(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->PWMCRD, LED_PWMCRD_CR13_Msk));
}

/**
  * @brief    Set LED Dig12 PWM
  * @rmtoll   PWMCRD    CR12    FL_LED_SetDig12PwmCr
  * @param    LEDx LED instance
  * @param    cr This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetDig12PwmCr(LED_Type* LEDx, uint32_t cr)
{
    MODIFY_REG(LEDx->PWMCRD, LED_PWMCRD_CR12_Msk, cr<<0);
}

/**
  * @brief    Get LED Dig12 PWM
  * @rmtoll   PWMCRD    CR12    FL_LED_GetDig12PwmCr
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetDig12PwmCr(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->PWMCRD, LED_PWMCRD_CR12_Msk));
}

/**
  * @brief    Write LED Dot Data
  * @rmtoll   DOT    DATA    FL_LED_WriteDotData
  * @param    LEDx LED instance
  * @param    reg This parameter can be one of the following values:
  *           @arg @ref FL_LED_DOT_REG0
  *           @arg @ref FL_LED_DOT_REG1
  *           @arg @ref FL_LED_DOT_REG2
  *           @arg @ref FL_LED_DOT_REG3
  *           @arg @ref FL_LED_DOT_REG4
  *           @arg @ref FL_LED_DOT_REG5
  *           @arg @ref FL_LED_DOT_REG6
  *           @arg @ref FL_LED_DOT_REG7
  *           @arg @ref FL_LED_DOT_REG8
  *           @arg @ref FL_LED_DOT_REG9
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void FL_LED_WriteDotData(LED_Type* LEDx, uint32_t reg, uint32_t data)
{
    volatile uint32_t *pData = &(LEDx->DOT0DR);
    MODIFY_REG(pData[reg], LED_DOT_DATA_Msk, data);
}

/**
  * @brief    Read LED Dot Data
  * @rmtoll   DOT    DATA    FL_LED_ReadDotData
  * @param    LEDx LED instance
  * @param    reg This parameter can be one of the following values:
  *           @arg @ref FL_LED_DOT_REG0
  *           @arg @ref FL_LED_DOT_REG1
  *           @arg @ref FL_LED_DOT_REG2
  *           @arg @ref FL_LED_DOT_REG3
  *           @arg @ref FL_LED_DOT_REG4
  *           @arg @ref FL_LED_DOT_REG5
  *           @arg @ref FL_LED_DOT_REG6
  *           @arg @ref FL_LED_DOT_REG7
  *           @arg @ref FL_LED_DOT_REG8
  *           @arg @ref FL_LED_DOT_REG9
  * @retval   
  */
__STATIC_INLINE uint32_t FL_LED_ReadDotData(LED_Type* LEDx, uint32_t reg)
{
    volatile uint32_t *pData = &(LEDx->DOT0DR);
    return (uint32_t)(READ_BIT(pData[reg], LED_DOT_DATA_Msk));
}

/**
  * @brief    Set LED Dma trig
  * @rmtoll   DMACR    DDTRIG    FL_LED_SetDmaDdtrig
  * @param    LEDx LED instance
  * @param    trig This parameter can be one of the following values:
  *           @arg @ref FL_LED_REQUEST_BY_FRAME_END
  *           @arg @ref FL_LED_REQUEST_BY_TRIG_SYNC
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetDmaDdtrig(LED_Type* LEDx, uint32_t trig)
{
    MODIFY_REG(LEDx->DMACR, LED_DMACR_DDTRIG_Msk, trig);
}

/**
  * @brief    Get LED Dma trig
  * @rmtoll   DMACR    DDTRIG    FL_LED_GetDmaDdtrig
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_LED_REQUEST_BY_FRAME_END
  *           @arg @ref FL_LED_REQUEST_BY_TRIG_SYNC
  */
__STATIC_INLINE uint32_t FL_LED_GetDmaDdtrig(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->DMACR, LED_DMACR_DDTRIG_Msk));
}

/**
  * @brief    Set Dot Dr Len
  * @rmtoll   DMACR    DOTDR_LEN    FL_LED_SetDotDrLen
  * @param    LEDx LED instance
  * @param    len This parameter can be one of the following values:
  *           @arg @ref FL_LED_DOT_DR0
  *           @arg @ref FL_LED_DOT_DR0_1
  *           @arg @ref FL_LED_DOT_DR0_2
  *           @arg @ref FL_LED_DOT_DR0_3
  *           @arg @ref FL_LED_DOT_DR0_4
  *           @arg @ref FL_LED_DOT_DR0_5
  *           @arg @ref FL_LED_DOT_DR0_6
  *           @arg @ref FL_LED_DOT_DR0_7
  *           @arg @ref FL_LED_DOT_DR0_8
  *           @arg @ref FL_LED_DOT_DR0_9
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetDotDrLen(LED_Type* LEDx, uint32_t len)
{
    MODIFY_REG(LEDx->DMACR, LED_DMACR_DOTDR_LEN_Msk, len);
}

/**
  * @brief    Get Dot Dr Len
  * @rmtoll   DMACR    DOTDR_LEN    FL_LED_GetDotDrLen
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_LED_DOT_DR0
  *           @arg @ref FL_LED_DOT_DR0_1
  *           @arg @ref FL_LED_DOT_DR0_2
  *           @arg @ref FL_LED_DOT_DR0_3
  *           @arg @ref FL_LED_DOT_DR0_4
  *           @arg @ref FL_LED_DOT_DR0_5
  *           @arg @ref FL_LED_DOT_DR0_6
  *           @arg @ref FL_LED_DOT_DR0_7
  *           @arg @ref FL_LED_DOT_DR0_8
  *           @arg @ref FL_LED_DOT_DR0_9
  */
__STATIC_INLINE uint32_t FL_LED_GetDotDrLen(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->DMACR, LED_DMACR_DOTDR_LEN_Msk));
}

/**
  * @brief    Set Pwm Cr Len
  * @rmtoll   DMACR    DOTDR_LEN    FL_LED_SetPwmCrLen
  * @param    LEDx LED instance
  * @param    len This parameter can be one of the following values:
  *           @arg @ref FL_LED_PWM_CRA
  *           @arg @ref FL_LED_PWM_CRA_B
  *           @arg @ref FL_LED_PWM_CRA_C
  *           @arg @ref FL_LED_PWM_CRA_D
  * @retval   None
  */
__STATIC_INLINE void FL_LED_SetPwmCrLen(LED_Type* LEDx, uint32_t len)
{
    MODIFY_REG(LEDx->DMACR, LED_DMACR_PWMCR_LEN_Msk, len);
}

/**
  * @brief    Get Pwm Cr Len
  * @rmtoll   DMACR    DOTDR_LEN    FL_LED_GetPwmCrLen
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_LED_PWM_CRA
  *           @arg @ref FL_LED_PWM_CRA_B
  *           @arg @ref FL_LED_PWM_CRA_C
  *           @arg @ref FL_LED_PWM_CRA_D
  */
__STATIC_INLINE uint32_t FL_LED_GetPwmCrLen(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->DMACR, LED_DMACR_PWMCR_LEN_Msk));
}

/**
  * @brief    Set LED DMA PWM Cr Address
  * @rmtoll   DPCAR    ADDR    FL_LED_WriteDmaPwmCrAddress
  * @param    LEDx LED instance
  * @param    addr 
  * @retval   None
  */
__STATIC_INLINE void FL_LED_WriteDmaPwmCrAddress(LED_Type* LEDx, uint32_t addr)
{
    MODIFY_REG(LEDx->DPCAR, (0xffffffffU << 0U), (addr << 0U));
}

/**
  * @brief    Get LED DMA PWM Cr Address
  * @rmtoll   DPCAR    ADDR    FL_LED_ReadDmaPwmCrAddress
  * @param    LEDx LED instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_LED_ReadDmaPwmCrAddress(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->DPCAR, (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    Set LED DMA Dot Dr Address
  * @rmtoll   DDRAR    ADDR    FL_LED_WriteDmaDotDrAddress
  * @param    LEDx LED instance
  * @param    addr 
  * @retval   None
  */
__STATIC_INLINE void FL_LED_WriteDmaDotDrAddress(LED_Type* LEDx, uint32_t addr)
{
    MODIFY_REG(LEDx->DDRAR, (0xffffffffU << 0U), (addr << 0U));
}

/**
  * @brief    Get LED DMA Dot Dr Address
  * @rmtoll   DDRAR    ADDR    FL_LED_ReadDmaDotDrAddress
  * @param    LEDx LED instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_LED_ReadDmaDotDrAddress(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->DDRAR, (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    Get LED Current COM
  * @rmtoll   CCOM    ACT_COM    FL_LED_GetCurrentCom
  * @param    LEDx LED instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_LED_GetCurrentCom(LED_Type* LEDx)
{
    return (uint32_t)(READ_BIT(LEDx->CCOM, LED_CCOM_ACT_COM_Msk));
}

/**
  * @}
  */

/** @defgroup LED_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_LED_DeInit(LED_Type *LEDx);
FL_ErrorStatus FL_LED_Init(LED_Type *LEDx, FL_LED_InitTypeDef *initStruct);
void FL_LED_StructInit(FL_LED_InitTypeDef *initStruct);
void FL_LED_Display(uint32_t com, uint32_t dig, uint32_t state);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FL0XX_FL_LED_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-06-28*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
