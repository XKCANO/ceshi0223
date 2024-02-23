/**
  *******************************************************************************************************
  * @file    fm33lf0xx_fl_divas.h
  * @author  FMSH Application Team
  * @brief   Head file of DIVAS FL Module
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
#ifndef __FM33LF0XX_FL_DIVAS_H
#define __FM33LF0XX_FL_DIVAS_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33lf0xx_fl_def.h"
/** @addtogroup FM33LF0XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup DIVAS_FL_ES_INIT DIVAS Exported Init structures
  * @{
  */

/**
  * @brief FL DIVAS Init Sturcture definition
  */

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup DIVAS_FL_Exported_Constants DIVAS Exported Constants
  * @{
  */
#define    FL_DIVAS_SR_BUSY_TIMEOUT                                (0xFFFU)

#define    DIVAS_SR_DIVBYZERO_Pos                                 (1U)
#define    DIVAS_SR_DIVBYZERO_Msk                                 (0x1U << DIVAS_SR_DIVBYZERO_Pos)
#define    DIVAS_SR_DIVBYZERO                                     DIVAS_SR_DIVBYZERO_Msk

#define    DIVAS_SR_BUSY_Pos                                      (0U)
#define    DIVAS_SR_BUSY_Msk                                      (0x1U << DIVAS_SR_BUSY_Pos)
#define    DIVAS_SR_BUSY                                          DIVAS_SR_BUSY_Msk

#define    DIVAS_CR_MODE_Pos                                      (0U)
#define    DIVAS_CR_MODE_Msk                                      (0x1U << DIVAS_CR_MODE_Pos)
#define    DIVAS_CR_MODE                                          DIVAS_CR_MODE_Msk

#define    DIVAS_CR_SQR_TIME_Pos                                  (28U)
#define    DIVAS_CR_SQR_TIME_Msk                                  (0xfU << DIVAS_CR_SQR_TIME_Pos)
#define    DIVAS_CR_SQR_TIME                                      DIVAS_CR_SQR_TIME_Msk

#define    DIVAS_CR_DIV_TIME_Pos                                  (24U)
#define    DIVAS_CR_DIV_TIME_Msk                                  (0xfU << DIVAS_CR_DIV_TIME_Pos)
#define    DIVAS_CR_DIV_TIME                                      DIVAS_CR_DIV_TIME_Msk




#define    FL_DIVAS_MODE_DIV                                      (0x0U << DIVAS_CR_MODE_Pos)
#define    FL_DIVAS_MODE_ROOT                                     (0x1U << DIVAS_CR_MODE_Pos)


#define    FL_DIVAS_SQRT_1CYCLE                                   (0x0U << DIVAS_CR_SQR_TIME_Pos)
#define    FL_DIVAS_SQRT_2CYCLES                                  (0x1U << DIVAS_CR_SQR_TIME_Pos)
#define    FL_DIVAS_SQRT_3CYCLES                                  (0x2U << DIVAS_CR_SQR_TIME_Pos)
#define    FL_DIVAS_SQRT_4CYCLES                                  (0x3U << DIVAS_CR_SQR_TIME_Pos)
#define    FL_DIVAS_SQRT_5CYCLES                                  (0x4U << DIVAS_CR_SQR_TIME_Pos)
#define    FL_DIVAS_SQRT_6CYCLES                                  (0x5U << DIVAS_CR_SQR_TIME_Pos)
#define    FL_DIVAS_SQRT_7CYCLES                                  (0x6U << DIVAS_CR_SQR_TIME_Pos)
#define    FL_DIVAS_SQRT_8CYCLES                                  (0x7U << DIVAS_CR_SQR_TIME_Pos)
#define    FL_DIVAS_SQRT_9CYCLES                                  (0x8U << DIVAS_CR_SQR_TIME_Pos)
#define    FL_DIVAS_SQRT_10CYCLES                                 (0x9U << DIVAS_CR_SQR_TIME_Pos)
#define    FL_DIVAS_SQRT_11CYCLES                                 (0xaU << DIVAS_CR_SQR_TIME_Pos)
#define    FL_DIVAS_SQRT_12CYCLES                                 (0xbU << DIVAS_CR_SQR_TIME_Pos)
#define    FL_DIVAS_SQRT_13CYCLES                                 (0xcU << DIVAS_CR_SQR_TIME_Pos)
#define    FL_DIVAS_SQRT_14CYCLES                                 (0xdU << DIVAS_CR_SQR_TIME_Pos)
#define    FL_DIVAS_SQRT_15CYCLES                                 (0xeU << DIVAS_CR_SQR_TIME_Pos)
#define    FL_DIVAS_SQRT_16CYCLES                                 (0xfU << DIVAS_CR_SQR_TIME_Pos)


#define    FL_DIVAS_DIV_1CYCLE                                    (0x0U << DIVAS_CR_DIV_TIME_Pos)
#define    FL_DIVAS_DIV_2CYCLES                                   (0x1U << DIVAS_CR_DIV_TIME_Pos)
#define    FL_DIVAS_DIV_3CYCLES                                   (0x2U << DIVAS_CR_DIV_TIME_Pos)
#define    FL_DIVAS_DIV_4CYCLES                                   (0x3U << DIVAS_CR_DIV_TIME_Pos)
#define    FL_DIVAS_DIV_5CYCLES                                   (0x4U << DIVAS_CR_DIV_TIME_Pos)
#define    FL_DIVAS_DIV_6CYCLES                                   (0x5U << DIVAS_CR_DIV_TIME_Pos)
#define    FL_DIVAS_DIV_7CYCLES                                   (0x6U << DIVAS_CR_DIV_TIME_Pos)
#define    FL_DIVAS_DIV_8CYCLES                                   (0x7U << DIVAS_CR_DIV_TIME_Pos)
#define    FL_DIVAS_DIV_9CYCLES                                   (0x8U << DIVAS_CR_DIV_TIME_Pos)
#define    FL_DIVAS_DIV_10CYCLES                                  (0x9U << DIVAS_CR_DIV_TIME_Pos)
#define    FL_DIVAS_DIV_11CYCLES                                  (0xaU << DIVAS_CR_DIV_TIME_Pos)
#define    FL_DIVAS_DIV_12CYCLES                                  (0xbU << DIVAS_CR_DIV_TIME_Pos)
#define    FL_DIVAS_DIV_13CYCLES                                  (0xcU << DIVAS_CR_DIV_TIME_Pos)
#define    FL_DIVAS_DIV_14CYCLES                                  (0xdU << DIVAS_CR_DIV_TIME_Pos)
#define    FL_DIVAS_DIV_15CYCLES                                  (0xeU << DIVAS_CR_DIV_TIME_Pos)
#define    FL_DIVAS_DIV_16CYCLES                                  (0xfU << DIVAS_CR_DIV_TIME_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup DIVAS_FL_Exported_Functions DIVAS Exported Functions
  * @{
  */

/**
  * @brief    Write Dividend Register
  * @rmtoll   OPRD        FL_DIVAS_WriteOperand
  * @param    DIVASx DIVAS instance
  * @param    number 
  * @retval   None
  */
__STATIC_INLINE void FL_DIVAS_WriteOperand(DIVAS_Type* DIVASx, int32_t number)
{
    MODIFY_REG(DIVASx->OPRD, (0xffffffffU << 0U), (number << 0U));
}

/**
  * @brief    Read Dividend Register
  * @rmtoll   OPRD        FL_DIVAS_ReadOperand
  * @param    DIVASx DIVAS instance
  * @retval   
  */
__STATIC_INLINE int32_t FL_DIVAS_ReadOperand(DIVAS_Type* DIVASx)
{
    return (int32_t)(READ_BIT(DIVASx->OPRD, (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    Write 16bit Signed Divisor
  * @rmtoll   SOR        FL_DIVAS_WriteDivisor
  * @param    DIVASx DIVAS instance
  * @param    number 
  * @retval   None
  */
__STATIC_INLINE void FL_DIVAS_WriteDivisor(DIVAS_Type* DIVASx, int16_t number)
{
    MODIFY_REG(DIVASx->SOR, (0xffffU << 0U), (number << 0U));
}

/**
  * @brief    Read 16bit Signed Divisor
  * @rmtoll   SOR        FL_DIVAS_ReadDivisor
  * @param    DIVASx DIVAS instance
  * @retval   
  */
__STATIC_INLINE int32_t FL_DIVAS_ReadDivisor(DIVAS_Type* DIVASx)
{
    return (int32_t)(READ_BIT(DIVASx->SOR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Read 32bit Signed QUTO 
  * @rmtoll   QUOT        FL_DIVAS_ReadQuotient
  * @param    DIVASx DIVAS instance
  * @retval   
  */
__STATIC_INLINE int32_t FL_DIVAS_ReadQuotient(DIVAS_Type* DIVASx)
{
    return (int32_t)(READ_BIT(DIVASx->QUOT, (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    Read 16bit Signed Reminder 
  * @rmtoll   REMD        FL_DIVAS_ReadResidue
  * @param    DIVASx DIVAS instance
  * @retval   
  */
__STATIC_INLINE int16_t FL_DIVAS_ReadResidue(DIVAS_Type* DIVASx)
{
    return (int16_t)(READ_BIT(DIVASx->REMD, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Read 16bit Unsigned Square Root
  * @rmtoll   ROOT        FL_DIVAS_ReadRoot
  * @param    DIVASx DIVAS instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_DIVAS_ReadRoot(DIVAS_Type* DIVASx)
{
    return (uint32_t)(READ_BIT(DIVASx->ROOT, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get divided by 0 flag
  * @rmtoll   SR    DIVBYZERO    FL_DIVAS_IsActiveFlag_DividedZero
  * @param    DIVASx DIVAS instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DIVAS_IsActiveFlag_DividedZero(DIVAS_Type* DIVASx)
{
    return (uint32_t)(READ_BIT(DIVASx->SR, DIVAS_SR_DIVBYZERO_Msk) == (DIVAS_SR_DIVBYZERO_Msk));
}

/**
  * @brief    Get Busy flag
  * @rmtoll   SR    BUSY    FL_DIVAS_IsActiveFlag_Busy
  * @param    DIVASx DIVAS instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DIVAS_IsActiveFlag_Busy(DIVAS_Type* DIVASx)
{
    return (uint32_t)(READ_BIT(DIVASx->SR, DIVAS_SR_BUSY_Msk) == (DIVAS_SR_BUSY_Msk));
}

/**
  * @brief    Set Work Mode
  * @rmtoll   CR    MODE    FL_DIVAS_SetMode
  * @param    DIVASx DIVAS instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_DIVAS_MODE_DIV
  *           @arg @ref FL_DIVAS_MODE_ROOT
  * @retval   None
  */
__STATIC_INLINE void FL_DIVAS_SetMode(DIVAS_Type* DIVASx, uint32_t mode)
{
    MODIFY_REG(DIVASx->CR, DIVAS_CR_MODE_Msk, mode);
}

/**
  * @brief    Get Work Mode
  * @rmtoll   CR    MODE    FL_DIVAS_GetMode
  * @param    DIVASx DIVAS instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_DIVAS_MODE_DIV
  *           @arg @ref FL_DIVAS_MODE_ROOT
  */
__STATIC_INLINE uint32_t FL_DIVAS_GetMode(DIVAS_Type* DIVASx)
{
    return (uint32_t)(READ_BIT(DIVASx->CR, DIVAS_CR_MODE_Msk));
}

/**
  * @brief    Set SQRT Calculate Period
  * @rmtoll   CR    SQR_TIME    FL_DIVAS_SQRT_SetPeriod
  * @param    DIVASx DIVAS instance
  * @param    period This parameter can be one of the following values:
  *           @arg @ref FL_DIVAS_SQRT_1CYCLE
  *           @arg @ref FL_DIVAS_SQRT_2CYCLES
  *           @arg @ref FL_DIVAS_SQRT_3CYCLES
  *           @arg @ref FL_DIVAS_SQRT_4CYCLES
  *           @arg @ref FL_DIVAS_SQRT_5CYCLES
  *           @arg @ref FL_DIVAS_SQRT_6CYCLES
  *           @arg @ref FL_DIVAS_SQRT_7CYCLES
  *           @arg @ref FL_DIVAS_SQRT_8CYCLES
  *           @arg @ref FL_DIVAS_SQRT_9CYCLES
  *           @arg @ref FL_DIVAS_SQRT_10CYCLES
  *           @arg @ref FL_DIVAS_SQRT_11CYCLES
  *           @arg @ref FL_DIVAS_SQRT_12CYCLES
  *           @arg @ref FL_DIVAS_SQRT_13CYCLES
  *           @arg @ref FL_DIVAS_SQRT_14CYCLES
  *           @arg @ref FL_DIVAS_SQRT_15CYCLES
  *           @arg @ref FL_DIVAS_SQRT_16CYCLES
  * @retval   None
  */
__STATIC_INLINE void FL_DIVAS_SQRT_SetPeriod(DIVAS_Type* DIVASx, uint32_t period)
{
    MODIFY_REG(DIVASx->CR, DIVAS_CR_SQR_TIME_Msk, period);
}

/**
  * @brief    Get SQRT Calculate Period
  * @rmtoll   CR    SQR_TIME    FL_DIVAS_SQRT_GetPeriod
  * @param    DIVASx DIVAS instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_DIVAS_SQRT_1CYCLE
  *           @arg @ref FL_DIVAS_SQRT_2CYCLES
  *           @arg @ref FL_DIVAS_SQRT_3CYCLES
  *           @arg @ref FL_DIVAS_SQRT_4CYCLES
  *           @arg @ref FL_DIVAS_SQRT_5CYCLES
  *           @arg @ref FL_DIVAS_SQRT_6CYCLES
  *           @arg @ref FL_DIVAS_SQRT_7CYCLES
  *           @arg @ref FL_DIVAS_SQRT_8CYCLES
  *           @arg @ref FL_DIVAS_SQRT_9CYCLES
  *           @arg @ref FL_DIVAS_SQRT_10CYCLES
  *           @arg @ref FL_DIVAS_SQRT_11CYCLES
  *           @arg @ref FL_DIVAS_SQRT_12CYCLES
  *           @arg @ref FL_DIVAS_SQRT_13CYCLES
  *           @arg @ref FL_DIVAS_SQRT_14CYCLES
  *           @arg @ref FL_DIVAS_SQRT_15CYCLES
  *           @arg @ref FL_DIVAS_SQRT_16CYCLES
  */
__STATIC_INLINE uint32_t FL_DIVAS_SQRT_GetPeriod(DIVAS_Type* DIVASx)
{
    return (uint32_t)(READ_BIT(DIVASx->CR, DIVAS_CR_SQR_TIME_Msk));
}

/**
  * @brief    Set Div Calculate Period
  * @rmtoll   CR    DIV_TIME    FL_DIVAS_DIV_SetPeriod
  * @param    DIVASx DIVAS instance
  * @param    period This parameter can be one of the following values:
  *           @arg @ref FL_DIVAS_DIV_1CYCLE
  *           @arg @ref FL_DIVAS_DIV_2CYCLES
  *           @arg @ref FL_DIVAS_DIV_3CYCLES
  *           @arg @ref FL_DIVAS_DIV_4CYCLES
  *           @arg @ref FL_DIVAS_DIV_5CYCLES
  *           @arg @ref FL_DIVAS_DIV_6CYCLES
  *           @arg @ref FL_DIVAS_DIV_7CYCLES
  *           @arg @ref FL_DIVAS_DIV_8CYCLES
  *           @arg @ref FL_DIVAS_DIV_9CYCLES
  *           @arg @ref FL_DIVAS_DIV_10CYCLES
  *           @arg @ref FL_DIVAS_DIV_11CYCLES
  *           @arg @ref FL_DIVAS_DIV_12CYCLES
  *           @arg @ref FL_DIVAS_DIV_13CYCLES
  *           @arg @ref FL_DIVAS_DIV_14CYCLES
  *           @arg @ref FL_DIVAS_DIV_15CYCLES
  *           @arg @ref FL_DIVAS_DIV_16CYCLES
  * @retval   None
  */
__STATIC_INLINE void FL_DIVAS_DIV_SetPeriod(DIVAS_Type* DIVASx, uint32_t period)
{
    MODIFY_REG(DIVASx->CR, DIVAS_CR_DIV_TIME_Msk, period);
}

/**
  * @brief    Get Div Calculate Period
  * @rmtoll   CR    DIV_TIME    FL_DIVAS_DIV_GetPeriod
  * @param    DIVASx DIVAS instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_DIVAS_DIV_1CYCLE
  *           @arg @ref FL_DIVAS_DIV_2CYCLES
  *           @arg @ref FL_DIVAS_DIV_3CYCLES
  *           @arg @ref FL_DIVAS_DIV_4CYCLES
  *           @arg @ref FL_DIVAS_DIV_5CYCLES
  *           @arg @ref FL_DIVAS_DIV_6CYCLES
  *           @arg @ref FL_DIVAS_DIV_7CYCLES
  *           @arg @ref FL_DIVAS_DIV_8CYCLES
  *           @arg @ref FL_DIVAS_DIV_9CYCLES
  *           @arg @ref FL_DIVAS_DIV_10CYCLES
  *           @arg @ref FL_DIVAS_DIV_11CYCLES
  *           @arg @ref FL_DIVAS_DIV_12CYCLES
  *           @arg @ref FL_DIVAS_DIV_13CYCLES
  *           @arg @ref FL_DIVAS_DIV_14CYCLES
  *           @arg @ref FL_DIVAS_DIV_15CYCLES
  *           @arg @ref FL_DIVAS_DIV_16CYCLES
  */
__STATIC_INLINE uint32_t FL_DIVAS_DIV_GetPeriod(DIVAS_Type* DIVASx)
{
    return (uint32_t)(READ_BIT(DIVASx->CR, DIVAS_CR_DIV_TIME_Msk));
}

FL_ErrorStatus FL_DIVAS_DeInit(DIVAS_Type *DIVASx);
FL_ErrorStatus FL_DIVAS_Init(DIVAS_Type *DIVASx);
uint32_t FL_DIVAS_Hdiv_Calculation(DIVAS_Type *DIVASx, int32_t DivisorEnd, int16_t Divisor, int32_t *Quotient, int16_t *Residue);
uint32_t FL_DIVAS_Root_Calculation(DIVAS_Type *DIVASx, uint32_t Root, uint16_t *Result);


/**
  * @}
  */

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LF0XX_FL_DIVAS_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-05-22*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
