/**
  *******************************************************************************************************
  * @file    fm33lf0xx_fl_dac.h
  * @author  FMSH Application Team
  * @brief   Head file of DAC FL Module
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
#ifndef __FM33LF0XX_FL_DAC_H
#define __FM33LF0XX_FL_DAC_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33lf0xx_fl_def.h"
/** @addtogroup FM33LF0XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup DAC_FL_ES_INIT DAC Exported Init structures
  * @{
  */

/**
  * @brief FL DAC Init Sturcture definition
  */
typedef struct
{
    /*DAC触发模式使能配置*/
    uint32_t triggerMode;
    /*DAC触发源配置*/
    uint32_t triggerSource;
    /*DAC输出开关配置*/
    uint32_t switchMode;


} FL_DAC_InitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup DAC_FL_Exported_Constants DAC Exported Constants
  * @{
  */

#define    DAC_CR1_EN_Pos                                         (0U)
#define    DAC_CR1_EN_Msk                                         (0x1U << DAC_CR1_EN_Pos)
#define    DAC_CR1_EN                                             DAC_CR1_EN_Msk

#define    DAC_CR2_DMAEN_Pos                                      (1U)
#define    DAC_CR2_DMAEN_Msk                                      (0x1U << DAC_CR2_DMAEN_Pos)
#define    DAC_CR2_DMAEN                                          DAC_CR2_DMAEN_Msk

#define    DAC_CR2_TRGEN_Pos                                      (0U)
#define    DAC_CR2_TRGEN_Msk                                      (0x1U << DAC_CR2_TRGEN_Pos)
#define    DAC_CR2_TRGEN                                          DAC_CR2_TRGEN_Msk

#define    DAC_CFGR_TRGSEL_Pos                                    (2U)
#define    DAC_CFGR_TRGSEL_Msk                                    (0xfU << DAC_CFGR_TRGSEL_Pos)
#define    DAC_CFGR_TRGSEL                                        DAC_CFGR_TRGSEL_Msk

#define    DAC_CFGR_SWIEN_Pos                                     (0U)
#define    DAC_CFGR_SWIEN_Msk                                     (0x1U << DAC_CFGR_SWIEN_Pos)
#define    DAC_CFGR_SWIEN                                         DAC_CFGR_SWIEN_Msk

#define    DAC_SWTRGR_SWTRIG_Pos                                  (0U)
#define    DAC_SWTRGR_SWTRIG_Msk                                  (0x1U << DAC_SWTRGR_SWTRIG_Pos)
#define    DAC_SWTRGR_SWTRIG                                      DAC_SWTRGR_SWTRIG_Msk

#define    DAC_DHR_DHR_Pos                                        (0U)
#define    DAC_DHR_DHR_Msk                                        (0x3ffU << DAC_DHR_DHR_Pos)
#define    DAC_DHR_DHR                                            DAC_DHR_DHR_Msk

#define    DAC_ISR_DMAERR_Pos                                     (3U)
#define    DAC_ISR_DMAERR_Msk                                     (0x1U << DAC_ISR_DMAERR_Pos)
#define    DAC_ISR_DMAERR                                         DAC_ISR_DMAERR_Msk

#define    DAC_ISR_DOU_Pos                                        (0U)
#define    DAC_ISR_DOU_Msk                                        (0x1U << DAC_ISR_DOU_Pos)
#define    DAC_ISR_DOU                                            DAC_ISR_DOU_Msk

#define    DAC_IER_DMAE_IE_Pos                                    (3U)
#define    DAC_IER_DMAE_IE_Msk                                    (0x1U << DAC_IER_DMAE_IE_Pos)
#define    DAC_IER_DMAE_IE                                        DAC_IER_DMAE_IE_Msk

#define    DAC_IER_DOU_IE_Pos                                     (0U)
#define    DAC_IER_DOU_IE_Msk                                     (0x1U << DAC_IER_DOU_IE_Pos)
#define    DAC_IER_DOU_IE                                         DAC_IER_DOU_IE_Msk






#define    FL_DAC_TRGI_SOFTWARE                                   (0x0U << DAC_CFGR_TRGSEL_Pos)
#define    FL_DAC_TRGI_ATIM_TRGO                                  (0x1U << DAC_CFGR_TRGSEL_Pos)
#define    FL_DAC_TRGI_GPTIM0_TRGO                                (0x3U << DAC_CFGR_TRGSEL_Pos)
#define    FL_DAC_TRGI_GPTIM1_TRGO                                (0x4U << DAC_CFGR_TRGSEL_Pos)
#define    FL_DAC_TRGI_BSTIM_TRGO                                 (0x6U << DAC_CFGR_TRGSEL_Pos)
#define    FL_DAC_TRGI_LPTIM_TRGO                                 (0x7U << DAC_CFGR_TRGSEL_Pos)
#define    FL_DAC_TRGI_EXTI                                       (0xaU << DAC_CFGR_TRGSEL_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup DAC_FL_Exported_Functions DAC Exported Functions
  * @{
  */

/**
  * @brief    使能DAC
  * @rmtoll   CR1    EN    FL_DAC_Enable
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_Enable(DAC_Type* DACx)
{
    SET_BIT(DACx->CR1, DAC_CR1_EN_Msk);
}

/**
  * @brief    失能DAC
  * @rmtoll   CR1    EN    FL_DAC_Disable
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_Disable(DAC_Type* DACx)
{
    CLEAR_BIT(DACx->CR1, DAC_CR1_EN_Msk);
}

/**
  * @brief    获取DAC使能状态
  * @rmtoll   CR1    EN    FL_DAC_IsEnabled
  * @param    DACx DAC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DAC_IsEnabled(DAC_Type* DACx)
{
    return (uint32_t)(READ_BIT(DACx->CR1, DAC_CR1_EN_Msk) == DAC_CR1_EN_Msk);
}

/**
  * @brief    使能DAC DMA功能
  * @rmtoll   CR2    DMAEN    FL_DAC_EnableDMAReq
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_EnableDMAReq(DAC_Type* DACx)
{
    SET_BIT(DACx->CR2, DAC_CR2_DMAEN_Msk);
}

/**
  * @brief    失能DAC DMA功能
  * @rmtoll   CR2    DMAEN    FL_DAC_DisableDMAReq
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_DisableDMAReq(DAC_Type* DACx)
{
    CLEAR_BIT(DACx->CR2, DAC_CR2_DMAEN_Msk);
}

/**
  * @brief    获取DAC DMA功能使能状态
  * @rmtoll   CR2    DMAEN    FL_DAC_IsEnabledDMAReq
  * @param    DACx DAC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DAC_IsEnabledDMAReq(DAC_Type* DACx)
{
    return (uint32_t)(READ_BIT(DACx->CR2, DAC_CR2_DMAEN_Msk) == DAC_CR2_DMAEN_Msk);
}

/**
  * @brief    使能DAC触发模式
  * @rmtoll   CR2    TRGEN    FL_DAC_EnableTriggerMode
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_EnableTriggerMode(DAC_Type* DACx)
{
    SET_BIT(DACx->CR2, DAC_CR2_TRGEN_Msk);
}

/**
  * @brief    失能DAC触发模式
  * @rmtoll   CR2    TRGEN    FL_DAC_DisableTriggerMode
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_DisableTriggerMode(DAC_Type* DACx)
{
    CLEAR_BIT(DACx->CR2, DAC_CR2_TRGEN_Msk);
}

/**
  * @brief    获取DAC触发模式使能状态
  * @rmtoll   CR2    TRGEN    FL_DAC_IsEnabledTriggerMode
  * @param    DACx DAC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DAC_IsEnabledTriggerMode(DAC_Type* DACx)
{
    return (uint32_t)(READ_BIT(DACx->CR2, DAC_CR2_TRGEN_Msk) == DAC_CR2_TRGEN_Msk);
}

/**
  * @brief    设置DAC触发源
  * @note     必须在TRGEN为0的情况下修改
  * @rmtoll   CFGR    TRGSEL    FL_DAC_SetTriggerSource
  * @param    DACx DAC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_DAC_TRGI_SOFTWARE
  *           @arg @ref FL_DAC_TRGI_ATIM_TRGO
  *           @arg @ref FL_DAC_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_DAC_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_DAC_TRGI_BSTIM_TRGO
  *           @arg @ref FL_DAC_TRGI_LPTIM_TRGO
  *           @arg @ref FL_DAC_TRGI_EXTI
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_SetTriggerSource(DAC_Type* DACx, uint32_t source)
{
    MODIFY_REG(DACx->CFGR, DAC_CFGR_TRGSEL_Msk, source);
}

/**
  * @brief    获取DAC触发源设置
  * @rmtoll   CFGR    TRGSEL    FL_DAC_GetTriggerSource
  * @param    DACx DAC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_DAC_TRGI_SOFTWARE
  *           @arg @ref FL_DAC_TRGI_ATIM_TRGO
  *           @arg @ref FL_DAC_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_DAC_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_DAC_TRGI_BSTIM_TRGO
  *           @arg @ref FL_DAC_TRGI_LPTIM_TRGO
  *           @arg @ref FL_DAC_TRGI_EXTI
  */
__STATIC_INLINE uint32_t FL_DAC_GetTriggerSource(DAC_Type* DACx)
{
    return (uint32_t)(READ_BIT(DACx->CFGR, DAC_CFGR_TRGSEL_Msk));
}

/**
  * @brief    使能DAC反馈开关
  * @rmtoll   CFGR    SWIEN    FL_DAC_EnableFeedbackSwitch
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_EnableFeedbackSwitch(DAC_Type* DACx)
{
    SET_BIT(DACx->CFGR, DAC_CFGR_SWIEN_Msk);
}

/**
  * @brief    失能DAC反馈开关
  * @rmtoll   CFGR    SWIEN    FL_DAC_DisableFeedbackSwitch
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_DisableFeedbackSwitch(DAC_Type* DACx)
{
    CLEAR_BIT(DACx->CFGR, DAC_CFGR_SWIEN_Msk);
}

/**
  * @brief    获取DAC反馈开关使能状态
  * @rmtoll   CFGR    SWIEN    FL_DAC_IsEnabledFeedbackSwitch
  * @param    DACx DAC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DAC_IsEnabledFeedbackSwitch(DAC_Type* DACx)
{
    return (uint32_t)(READ_BIT(DACx->CFGR, DAC_CFGR_SWIEN_Msk) == DAC_CFGR_SWIEN_Msk);
}

/**
  * @brief    软件触发DAC
  * @rmtoll   SWTRGR    SWTRIG    FL_DAC_EnableSoftwareTrigger
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_EnableSoftwareTrigger(DAC_Type* DACx)
{
    SET_BIT(DACx->SWTRGR, DAC_SWTRGR_SWTRIG_Msk);
}

/**
  * @brief    写入DAC数据
  * @rmtoll   DHR    DHR    FL_DAC_WriteData
  * @param    DACx DAC instance
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_WriteData(DAC_Type* DACx, uint32_t data)
{
    MODIFY_REG(DACx->DHR, (0x3ffU << 0U), (data << 0U));
}

/**
  * @brief    读取DAC数据
  * @rmtoll   DHR    DHR    FL_DAC_ReadData
  * @param    DACx DAC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_DAC_ReadData(DAC_Type* DACx)
{
    return (uint32_t)(READ_BIT(DACx->DHR, (0x3ffU << 0U)) >> 0U);
}

/**
  * @brief    获取DAC DMA错误标志
  * @rmtoll   ISR    DMAERR    FL_DAC_IsActiveFlag_DMAError
  * @param    DACx DAC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DAC_IsActiveFlag_DMAError(DAC_Type* DACx)
{
    return (uint32_t)(READ_BIT(DACx->ISR, DAC_ISR_DMAERR_Msk) == (DAC_ISR_DMAERR_Msk));
}

/**
  * @brief    清除DAC DMA错误标志
  * @rmtoll   ISR    DMAERR    FL_DAC_ClearFlag_DMAError
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_ClearFlag_DMAError(DAC_Type* DACx)
{
    WRITE_REG(DACx->ISR, DAC_ISR_DMAERR_Msk);
}

/**
  * @brief    获取DAC数据输出寄存器更新标志
  * @rmtoll   ISR    DOU    FL_DAC_IsActiveFlag_DataOutputUpdate
  * @param    DACx DAC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DAC_IsActiveFlag_DataOutputUpdate(DAC_Type* DACx)
{
    return (uint32_t)(READ_BIT(DACx->ISR, DAC_ISR_DOU_Msk) == (DAC_ISR_DOU_Msk));
}

/**
  * @brief    清除DAC数据输出寄存器更新标志
  * @rmtoll   ISR    DOU    FL_DAC_ClearFlag_DataOutputUpdate
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_ClearFlag_DataOutputUpdate(DAC_Type* DACx)
{
    WRITE_REG(DACx->ISR, DAC_ISR_DOU_Msk);
}

/**
  * @brief    使能DAC DMA错误中断
  * @rmtoll   IER    DMAE_IE    FL_DAC_EnableIT_DMAError
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_EnableIT_DMAError(DAC_Type* DACx)
{
    SET_BIT(DACx->IER, DAC_IER_DMAE_IE_Msk);
}

/**
  * @brief    失能DAC DMA错误中断
  * @rmtoll   IER    DMAE_IE    FL_DAC_DisableIT_DMAError
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_DisableIT_DMAError(DAC_Type* DACx)
{
    CLEAR_BIT(DACx->IER, DAC_IER_DMAE_IE_Msk);
}

/**
  * @brief    获取DAC DMA错误中断使能状态
  * @rmtoll   IER    DMAE_IE    FL_DAC_IsEnabledIT_DMAError
  * @param    DACx DAC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DAC_IsEnabledIT_DMAError(DAC_Type* DACx)
{
    return (uint32_t)(READ_BIT(DACx->IER, DAC_IER_DMAE_IE_Msk) == DAC_IER_DMAE_IE_Msk);
}

/**
  * @brief    使能DAC数据输出寄存器更新中断
  * @rmtoll   IER    DOU_IE    FL_DAC_EnableIT_DataOutputUpdate
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_EnableIT_DataOutputUpdate(DAC_Type* DACx)
{
    SET_BIT(DACx->IER, DAC_IER_DOU_IE_Msk);
}

/**
  * @brief    失能DAC数据输出寄存器更新中断
  * @rmtoll   IER    DOU_IE    FL_DAC_DisableIT_DataOutputUpdate
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_DisableIT_DataOutputUpdate(DAC_Type* DACx)
{
    CLEAR_BIT(DACx->IER, DAC_IER_DOU_IE_Msk);
}

/**
  * @brief    获取DAC数据输出寄存器更新中断使能状态
  * @rmtoll   IER    DOU_IE    FL_DAC_IsEnabledIT_DataOutputUpdate
  * @param    DACx DAC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DAC_IsEnabledIT_DataOutputUpdate(DAC_Type* DACx)
{
    return (uint32_t)(READ_BIT(DACx->IER, DAC_IER_DOU_IE_Msk) == DAC_IER_DOU_IE_Msk);
}

/**
  * @}
  */

/** @defgroup DAC_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus  FL_DAC_DeInit(DAC_Type *DACx);
FL_ErrorStatus FL_DAC_Init(DAC_Type *DACx, FL_DAC_InitTypeDef  *DAC_InitStruct);
void FL_DAC_StructInit(FL_DAC_InitTypeDef *DAC_InitStruct);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LF0XX_FL_DAC_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-06-26*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
