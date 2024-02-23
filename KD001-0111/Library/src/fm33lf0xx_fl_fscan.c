 /**    
  *******************************************************************************************************
  * @file    fm33lf0xx_fl_fscan.c
  * @author  FMSH Application Team
  * @brief   Src file of FSCAN FL Module
  *******************************************************************************************************   
  * @attention    
  * Copyright (c) 2023, SHANGHAI FUDAN MICROELECTRONICS GROUP CO., LTD.(FUDAN MICROELECTRONICS./ FUDAN MICRO.)    
  * All rights reserved.    
  *    
  * Processor:                   FM33LF0xx   
  * http:                        http://www.fmdevelopers.com.cn/    
  *    
  * Redistribution and use in source and binary forms, with or without    
  * modification, are permitted provided that the following conditions are met    
  *    
  * 1. Redistributions of source code must retain the above copyright notice,    
  *    this list of conditions and the following disclaimer.    
  *    
  * 2. Redistributions in binary form must reproduce the above copyright notice,    
  *    this list of conditions and the following disclaimer in the documentation    
  *    and/or other materials provided with the distribution.    
  *    
  * 3. Neither the name of the copyright holder nor the names of its contributors    
  *    may be used to endorse or promote products derived from this software    
  *    without specific prior written permission.    
  *    
  * 4. To provide the most up-to-date information, the revision of our documents     
  *    on the World Wide Web will be the most Current. Your printed copy may be      
  *    an earlier revision. To verify you have the latest information avaliable,    
  *    refer to: http://www.fmdevelopers.com.cn/.    
  *    
  * THIS SOFTWARE IS PROVIDED BY FUDAN MICRO "AS IS" AND ANY EXPRESSED:     
  * ORIMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES     
  * OF MERCHANTABILITY NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE    
  * ARE DISCLAIMED.IN NO EVENT SHALL FUDAN MICRO OR ITS CONTRIBUTORS BE LIABLE     
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL     
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS     
  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER    
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,     
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISINGIN ANY WAY OUT OF THE     
  * USE OF THIS SOFTWARE, EVEN IF ADVISED OFTHE POSSIBILITY OF SUCH DAMAGE.    
  *
  *******************************************************************************************************
  */    

/* Includes ------------------------------------------------------------------*/
#include "fm33lf0xx_fl.h"
/** @addtogroup FM33LF0XX_FL_Driver
  * @{
  */

/** @addtogroup FSCAN
  * @{
  */

#ifdef FL_FSCAN_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup FSCAN_FL_Private_Macros
  * @{
  */


#define     IS_FSCAN_INSTANCE(INSTANCE)                     (((INSTANCE) == FSCAN))
                                                         
#define     IS_FSCAN_SJW(__VALUE__)                        (((__VALUE__) == FL_FSCAN_SJW_1Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_SJW_2Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_SJW_3Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_SJW_4Tq))
                                                         
#define     IS_FSCAN_TS1(__VALUE__)                        (((__VALUE__) == FL_FSCAN_TS1_1Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS1_2Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS1_3Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS1_4Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS1_5Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS1_6Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS1_7Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS1_8Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS1_9Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS1_10Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS1_11Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS1_12Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS1_13Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS1_14Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS1_15Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS1_16Tq))
                                                         
#define     IS_FSCAN_TS2(__VALUE__)                        (((__VALUE__) == FL_FSCAN_TS2_1Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS2_2Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS2_3Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS2_4Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS2_5Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS2_6Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS2_7Tq) ||\
                                                          ((__VALUE__) == FL_FSCAN_TS2_8Tq)) 
            
#define    IS_FSCAN_TX_PRIORITY(__VALUE__)                 (((__VALUE__) == FL_FSCAN_TX_PRIORITY_ID) ||\
                                                          ((__VALUE__) == FL_FSCAN_TX_PRIORITY_BUFFER))
           
           
#define    IS_FSCAN_FILTER_EN(__VALUE__)                   (((__VALUE__) == FL_ENABLE) ||\
                                                          ((__VALUE__) == FL_DISABLE))
           
#define    IS_FSCAN_AFx(__VALUE__)                         (((__VALUE__) == FL_FSCAN_FILTER1) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTER2) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTER3) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTER4) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTER5) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTER6) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTER7) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTER8) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTER9) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTER10) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTER11) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTER12) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTER13) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTER14) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTER15) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTER16))
           
#define    IS_FSCAN_AFMRx(__VALUE__)                       (((__VALUE__) == FL_FSCAN_FILTERMASK1) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTERMASK2) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTERMASK3) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTERMASK4))
           
#define    IS_FSCAN_AFIRx(__VALUE__)                       (((__VALUE__) == FL_FSCAN_FILTERID1) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTERID2) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTERID3) ||\
                                                          ((__VALUE__) == FL_FSCAN_FILTERID4))
                                                                                              
#define    IS_FSCAN_MODE(__VALUE__)                        (((__VALUE__) == FL_FSCAN_MODE_NORMAL)   ||\
                                                          ((__VALUE__) == FL_FSCAN_MODE_LOOPBACK) ||\
                                                          ((__VALUE__) == FL_FSCAN_MODE_CONFIG)   ||\
                                                          ((__VALUE__) == FL_FSCAN_MODE_SLEEP))
           
           
#define    IS_FSCAN_CLK(__VALUE__)                         (((__VALUE__) == FL_CMU_FSCAN_CLK_SOURCE_RCHF) ||\
                                                          ((__VALUE__) == FL_CMU_FSCAN_CLK_SOURCE_XTHF) ||\
                                                          ((__VALUE__) == FL_CMU_FSCAN_CLK_SOURCE_PLL)  ||\
                                                          ((__VALUE__) == FL_CMU_FSCAN_CLK_SOURCE_APBCLK))
           
#define    IS_FSCAN_ABOM(__VALUE__)                        (((__VALUE__) == FL_FSCAN_AUTO_MANAGE_HARDWARE)      ||\
                                                          ((__VALUE__) == FL_FSCAN_AUTO_MANAGE_SOFTWARE_WAIT) ||\
                                                          ((__VALUE__) == FL_FSCAN_AUTO_MANAGE_SOFTWARE_INTERGRATION))
           
#define    IS_FSCAN_WAKEUP(__VALUE__)                      (((__VALUE__) == FL_ENABLE) ||\
                                                          ((__VALUE__) == FL_DISABLE))
           
#define    IS_FSCAN_SRR(__VALUE__)                         (((__VALUE__) == FL_FSCAN_SRR_BIT_LOW) ||\
                                                          ((__VALUE__) == FL_FSCAN_SRR_BIT_HIGH))
                                                                          
#define    IS_FSCAN_STD1SRR(__VALUE__)                     (((__VALUE__) == FL_FSCAN_STD1SRR_BIT_LOW) ||\
                                                          ((__VALUE__) == FL_FSCAN_STD1SRR_BIT_HIGH))
                                                                          
#define    IS_FSCAN_STD2SRR(__VALUE__)                     (((__VALUE__) == FL_FSCAN_STD2SRR_BIT_LOW) ||\
                                                          ((__VALUE__) == FL_FSCAN_STD2SRR_BIT_HIGH))
                                                                          
#define    IS_FSCAN_IDE(__VALUE__)                         (((__VALUE__) == FL_FSCAN_IDE_BIT_LOW) ||\
                                                          ((__VALUE__) == FL_FSCAN_IDE_BIT_HIGH))
                                                                          
#define    IS_FSCAN_STD1IDE(__VALUE__)                     (((__VALUE__) == FL_FSCAN_STD1IDE_BIT_LOW) ||\
                                                          ((__VALUE__) == FL_FSCAN_STD1IDE_BIT_HIGH))
                                                                          
#define    IS_FSCAN_STD2IDE(__VALUE__)                     (((__VALUE__) == FL_FSCAN_STD2IDE_BIT_LOW) ||\
                                                          ((__VALUE__) == FL_FSCAN_STD2IDE_BIT_HIGH))
                                                                          
#define    IS_FSCAN_RTR(__VALUE__)                         (((__VALUE__) == FL_FSCAN_RTR_BIT_LOW) ||\
                                                          ((__VALUE__) == FL_FSCAN_RTR_BIT_HIGH))
           
           
#define    IS_FSCAN_ID29_MASK(__VALUE__)                    ((__VALUE__) <= 0x1FFFFFFFU)
#define    IS_FSCAN_ID11_MASK(__VALUE__)                    ((__VALUE__) <= 0x7FFU)
                                                                          
#define    IS_FSCAN_STD1ID29_MASK(__VALUE__)                ((__VALUE__) <= 0X1FFFFFFFU)
#define    IS_FSCAN_STD1ID11_MASK(__VALUE__)                ((__VALUE__) <= 0x7FFU)
                                                                          
#define    IS_FSCAN_STD2ID29_MASK(__VALUE__)                ((__VALUE__) <= 0X1FFFFFFFU)
#define    IS_FSCAN_STD2ID11_MASK(__VALUE__)                ((__VALUE__) <= 0x7FFU)
           
#define    IS_FSCAN_SRR_MASK(__VALUE__)                    (((__VALUE__) == FL_ENABLE) ||\
                                                          ((__VALUE__) == FL_DISABLE))
           
#define    IS_FSCAN_IDE_MASK(__VALUE__)                    (((__VALUE__) == FL_ENABLE) ||\
                                                          ((__VALUE__) == FL_DISABLE))
           
#define    IS_FSCAN_STD1SRR_MASK(__VALUE__)                (((__VALUE__) == FL_ENABLE) ||\
                                                          ((__VALUE__) == FL_DISABLE))
                                                         
#define    IS_FSCAN_STD1IDE_MASK(__VALUE__)                (((__VALUE__) == FL_ENABLE) ||\
                                                          ((__VALUE__) == FL_DISABLE))
                                                         
#define    IS_FSCAN_STD2SRR_MASK(__VALUE__)                (((__VALUE__) == FL_ENABLE) ||\
                                                          ((__VALUE__) == FL_DISABLE))
                                                         
#define    IS_FSCAN_STD2IDE_MASK(__VALUE__)                (((__VALUE__) == FL_ENABLE) ||\
                                                          ((__VALUE__) == FL_DISABLE))
           
#define    IS_FSCAN_RTR_MASK(__VALUE__)                    (((__VALUE__) == FL_ENABLE) ||\
                                                          ((__VALUE__) == FL_DISABLE))
                                                         
#define    IS_FSCAN_MASKMODE(__VALUE__)                    (((__VALUE__) == FL_FSCAN_MASKMODE_ID) ||\
                                                          ((__VALUE__) == FL_FSCAN_MASKMODE_MASK))
           
#define    IS_FSCAN_IDMODE(__VALUE__)                      (((__VALUE__) == FL_FSCAN_IDMODE_16BIT) ||\
                                                          ((__VALUE__) == FL_FSCAN_IDMODE_32BIT))
/**
  * @}
  */

/* Private consts ------------------------------------------------------------*/
/** @addtogroup FSCAN_FL_Private_Consts
  * @{
  */


/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/



/* Exported functions --------------------------------------------------------*/
/** @addtogroup FSCAN_FL_EF_Init
  * @{
  */

/**
  * @brief  FSCAN初始化
  * @param  FSCANx外设入口地址
  * @param  FSCAN_InitStruct 指向一个@ref FL_FSCAN_InitTypeDef  结构体的指针
  * @retval 错误状态可能值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 配置成功
  */
FL_ErrorStatus FL_FSCAN_Init(FSCAN_Type *FSCANx, FL_FSCAN_InitTypeDef *FSCAN_InitStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    if(FSCAN_InitStruct != NULL)
    {
        /*参数检查*/
        assert_param(IS_FSCAN_INSTANCE(FSCANx));
        assert_param(IS_FSCAN_SJW(FSCAN_InitStruct->SJW));
        assert_param(IS_FSCAN_TS1(FSCAN_InitStruct->TS1));
        assert_param(IS_FSCAN_TS2(FSCAN_InitStruct->TS2));
        assert_param(IS_FSCAN_TX_PRIORITY(FSCAN_InitStruct->TXPriority));
        assert_param(IS_FSCAN_CLK(FSCAN_InitStruct->clockSource));
        assert_param(IS_FSCAN_MODE(FSCAN_InitStruct->mode));
        assert_param(IS_FSCAN_WAKEUP(FSCAN_InitStruct->wakeup));
        assert_param(IS_FSCAN_ABOM(FSCAN_InitStruct->ABOM));
        /*时钟总线配置*/
        if(FSCANx == FSCAN)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_FSCAN);
            FL_CMU_EnableGroup2OperationClock(FL_CMU_GROUP2_OPCLKEN_FSCAN);
            /*FSCAN时钟源选择*/
            FL_CMU_SetFSCANClockSource(FSCAN_InitStruct->clockSource);
        }
        else
        {

        }
        /*复位FSCAN模块*/
        FL_FSCAN_EnableSoftwareReset(FSCANx);
        FL_FSCAN_SetAutoBusOffManagement(FSCANx, FSCAN_InitStruct->ABOM);
        FL_FSCAN_SetTXPriority(FSCANx, FSCAN_InitStruct->TXPriority);
        /*设置重同步宽度*/
        FL_FSCAN_WriteSyncJumpWidth(FSCANx, FSCAN_InitStruct->SJW);
        /*设置时间段11*/
        FL_FSCAN_WriteTimeSegment1Length(FSCANx, FSCAN_InitStruct->TS1);
        /*设置时间段22*/
        FL_FSCAN_WriteTimeSegment2Length(FSCANx, FSCAN_InitStruct->TS2);
        /*设置波特率*/
        FL_FSCAN_WriteBaudRatePrescaler(FSCANx, FSCAN_InitStruct->BRP);
        if(FSCAN_InitStruct->wakeup == FL_ENABLE)
        {
            FL_FSCAN_EnableWakeup(FSCANx);
        }
        else
        {
            FL_FSCAN_DisableWakeup(FSCANx);
        }
        if(FSCAN_InitStruct->AREN  == FL_ENABLE)
        {
            FL_FSCAN_EnableAutoResend(FSCANx);
        }
        else
        {
            FL_FSCAN_DisableAutoResend(FSCANx);
        }
        if(FSCAN_InitStruct->mode == FL_FSCAN_MODE_NORMAL)
        {
            FL_FSCAN_DisableSleepMode(FSCANx);
            FL_FSCAN_DisableLoopBackMode(FSCANx);    /* Normal模式 */
            FL_FSCAN_Enable(FSCANx);
        }
        else if(FSCAN_InitStruct->mode == FL_FSCAN_MODE_LOOPBACK)
        {
            FL_FSCAN_EnableLoopBackMode(FSCANx);    /* Loop Back模式*/
            FL_FSCAN_DisableSleepMode(FSCANx);
            FL_FSCAN_Enable(FSCANx);
        }
        else if(FSCAN_InitStruct->mode == FL_FSCAN_MODE_SLEEP)
        {
            FL_FSCAN_EnableSleepMode(FSCANx);         /*Sleep模式*/
            FL_FSCAN_DisableLoopBackMode(FSCANx);
            FL_FSCAN_Enable(FSCANx);
        }
        else
        {
            FL_FSCAN_Disable(FSCANx);    /* Configuration模式 */
        }
        status = FL_PASS;
    }
    return status;
}

/**
  * @brief  设置 FSCAN_InitStruct 为默认模式
  * @param  FSCAN_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_FSCAN_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_FSCAN_StructInit(FL_FSCAN_InitTypeDef *FSCAN_InitStruct)
{
    if(FSCAN_InitStruct != NULL)
    {
        FSCAN_InitStruct->mode = FL_FSCAN_MODE_NORMAL;
        FSCAN_InitStruct->BRP = 0;
        FSCAN_InitStruct->clockSource = FL_CMU_FSCAN_CLK_SOURCE_RCHF;
        FSCAN_InitStruct->SJW = FL_FSCAN_SJW_1Tq;
        FSCAN_InitStruct->TS1 = FL_FSCAN_TS1_5Tq;
        FSCAN_InitStruct->TS2 = FL_FSCAN_TS2_4Tq;
        FSCAN_InitStruct->ABOM = FL_FSCAN_AUTO_MANAGE_HARDWARE;
        FSCAN_InitStruct->AREN = FL_ENABLE;
        FSCAN_InitStruct->TXPriority = FL_FSCAN_TX_PRIORITY_BUFFER;
        FSCAN_InitStruct->wakeup = FL_DISABLE;
    }
}

/**
  * @brief  FSCAN滤波器初始化
  * @param  FSCANx外设入口地址
  * @param  filterX This parameter can be one of the following values:
  *           @arg @ref FL_FSCAN_FILTER1
  *           @arg @ref FL_FSCAN_FILTER2
  *           @arg @ref FL_FSCAN_FILTER3
  *           @arg @ref FL_FSCAN_FILTER4
  *           @arg @ref FL_FSCAN_FILTER5
  *           @arg @ref FL_FSCAN_FILTER6
  *           @arg @ref FL_FSCAN_FILTER7
  *           @arg @ref FL_FSCAN_FILTER8
  *           @arg @ref FL_FSCAN_FILTER9
  *           @arg @ref FL_FSCAN_FILTER10
  *           @arg @ref FL_FSCAN_FILTER11
  *           @arg @ref FL_FSCAN_FILTER12
  *           @arg @ref FL_FSCAN_FILTER13
  *           @arg @ref FL_FSCAN_FILTER14
  *           @arg @ref FL_FSCAN_FILTER15
  *           @arg @ref FL_FSCAN_FILTER16
  * @param  FSCAN_InitFilterStruct 指向一个@ref FL_FSCAN_FilterInitTypeDef  结构体的指针
  * @retval 错误状态可能值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 配置过程
  */
FL_ErrorStatus FL_FSCAN_FilterInit(FSCAN_Type *FSCANx, FL_FSCAN_FilterInitTypeDef *FSCAN_FilterInitStruct, uint32_t filterX)
{
    FL_ErrorStatus status = FL_FAIL;
    if(FSCAN_FilterInitStruct != NULL)
    {
        assert_param(IS_FSCAN_SRR(FSCAN_FilterInitStruct->filterIdSRR));
        assert_param(IS_FSCAN_IDE(FSCAN_FilterInitStruct->filterIdIDE));
        assert_param(IS_FSCAN_STD1SRR(FSCAN_FilterInitStruct->filterSTD1IdSRR));
        assert_param(IS_FSCAN_STD1IDE(FSCAN_FilterInitStruct->filterSTD1IdIDE));
        assert_param(IS_FSCAN_STD2SRR(FSCAN_FilterInitStruct->filterSTD2IdSRR));
        assert_param(IS_FSCAN_STD2IDE(FSCAN_FilterInitStruct->filterSTD2IdIDE));
        assert_param(IS_FSCAN_RTR(FSCAN_FilterInitStruct->filterIdRTR));
        assert_param(IS_FSCAN_FILTER_EN(FSCAN_FilterInitStruct->filterEn));
        assert_param(IS_FSCAN_ID29_MASK(FSCAN_FilterInitStruct->filterMaskIdExtend));
        assert_param(IS_FSCAN_ID11_MASK(FSCAN_FilterInitStruct->filterMaskIdStandard));
        assert_param(IS_FSCAN_STD1ID29_MASK(FSCAN_FilterInitStruct->filterSTD1MaskIdExtend));
        assert_param(IS_FSCAN_STD1ID11_MASK(FSCAN_FilterInitStruct->filterSTD1MaskIdStandard));
        assert_param(IS_FSCAN_STD2ID29_MASK(FSCAN_FilterInitStruct->filterSTD2MaskIdExtend));
        assert_param(IS_FSCAN_STD2ID11_MASK(FSCAN_FilterInitStruct->filterSTD2MaskIdStandard));
        assert_param(IS_FSCAN_SRR_MASK(FSCAN_FilterInitStruct->filterMaskIdSRR));
        assert_param(IS_FSCAN_IDE_MASK(FSCAN_FilterInitStruct->filterMaskIdIDE));
        assert_param(IS_FSCAN_STD1SRR_MASK(FSCAN_FilterInitStruct->filterSTD1MaskIdSRR));
        assert_param(IS_FSCAN_STD1IDE_MASK(FSCAN_FilterInitStruct->filterSTD1MaskIdIDE));
        assert_param(IS_FSCAN_STD2SRR_MASK(FSCAN_FilterInitStruct->filterSTD2MaskIdSRR));
        assert_param(IS_FSCAN_STD2IDE_MASK(FSCAN_FilterInitStruct->filterSTD2MaskIdIDE));
        assert_param(IS_FSCAN_RTR_MASK(FSCAN_FilterInitStruct->filterMaskIdRTR));
        assert_param(IS_FSCAN_IDMODE(FSCAN_FilterInitStruct->filterIDMode));
        assert_param(IS_FSCAN_MASKMODE(FSCAN_FilterInitStruct->filterMaskMode));
        assert_param(IS_FSCAN_AFx(filterX));
        while(FL_FSCAN_IsActiveFlag_FilterBusy(FSCANx) != 0)
        {
        }
        /* 掩码模式设置*/
        FL_FSCAN_Filter_SetMaskMode(FSCANx, filterX, FSCAN_FilterInitStruct->filterMaskMode);
        /* ID模式设置*/
        FL_FSCAN_Filter_SetIDMode(FSCANx, filterX, FSCAN_FilterInitStruct->filterIDMode);
        /* 滤波器32bit模式 */
        if(FSCAN_FilterInitStruct->filterIDMode  == FL_FSCAN_IDMODE_32BIT)
        {
            if(FSCAN_FilterInitStruct->filterIdIDE == FL_FSCAN_IDE_BIT_HIGH)
            {   /* 滤波器ID设置 */
                FL_FSCAN_FilterEXT_WriteIDCompare(FSCANx, filterX, ((FSCAN_FilterInitStruct->filterIdExtend) >> 18) & 0X000007FFU);
                FL_FSCAN_FilterEXT_WriteEXTIDCompare(FSCANx, filterX, (FSCAN_FilterInitStruct->filterIdExtend) & 0X0003FFFFU);
                /* 滤波器ID掩码设置 */
                FL_FSCAN_FilterEXT_WriteIDCompareMask(FSCANx, filterX, ((FSCAN_FilterInitStruct->filterMaskIdExtend) >> 18) & 0X000007FFU);
                FL_FSCAN_FilterEXT_WriteEXTIDCompareMask(FSCANx, filterX, (FSCAN_FilterInitStruct->filterMaskIdExtend) & 0X0003FFFFU);
            }
            else
            {   /* 滤波器ID设置 */
                FL_FSCAN_FilterEXT_WriteIDCompare(FSCANx, filterX, (FSCAN_FilterInitStruct->filterIdStandard) & 0X000007FFU);
                /* 滤波器ID掩码设置 */
                FL_FSCAN_FilterEXT_WriteIDCompareMask(FSCANx, filterX, (FSCAN_FilterInitStruct->filterMaskIdStandard) & 0X000007FFU);
            }
            FL_FSCAN_FilterEXT_SetSRRCompare(FSCANx, filterX, FSCAN_FilterInitStruct->filterIdSRR);
            /* 滤波器ID设置 */
            FL_FSCAN_FilterEXT_SetIDECompare(FSCANx, filterX, FSCAN_FilterInitStruct->filterIdIDE);
            FL_FSCAN_FilterEXT_SetRTRCompare(FSCANx, filterX, FSCAN_FilterInitStruct->filterIdRTR);
            if((FSCAN_FilterInitStruct->filterMaskIdSRR) == FL_ENABLE)   
            {   /* SRR参与滤波器比较 */
                FL_FSCAN_FilterEXT_EnableSRRCompare(FSCANx, filterX);
            }
            else
            {
                FL_FSCAN_FilterEXT_DisableSRRCompare(FSCANx, filterX);
            }
            if((FSCAN_FilterInitStruct->filterMaskIdIDE) == FL_ENABLE)
            {   /* IDE位参与滤波器比较 */
                FL_FSCAN_FilterEXT_EnableIDECompare(FSCANx, filterX);
            }
            else
            {
                FL_FSCAN_FilterEXT_DisableIDECompare(FSCANx, filterX);
            }
            if((FSCAN_FilterInitStruct->filterMaskIdRTR) == FL_ENABLE)
            {   /* RTR位参与滤波器比较 */
                FL_FSCAN_FilterEXT_EnableRTRCompare(FSCANx, filterX);
            }
            else
            {
                FL_FSCAN_FilterEXT_DisableRTRCompare(FSCANx, filterX);
            }
        }
        else /* 滤波器16bit模式 */
        {
            /* 滤波器低16位参数设置 */
            if(FSCAN_FilterInitStruct->filterSTD1IdIDE == FL_FSCAN_STD1IDE_BIT_HIGH)
            {   /* 滤波器1 ID设置 */
                FL_FSCAN_FilterSTD1_WriteIDCompare(FSCANx, filterX, ((FSCAN_FilterInitStruct->filterSTD1IdExtend) >> 18) & 0X000007FFU);
                FL_FSCAN_FilterSTD1_WriteEXTIDCompare(FSCANx, filterX, ((FSCAN_FilterInitStruct->filterSTD1IdExtend >> 15)) & 0X7U);
                /* 滤波器1 ID掩码设置 */
                FL_FSCAN_FilterSTD1_WriteIDCompareMask(FSCANx, filterX, (FSCAN_FilterInitStruct->filterSTD1MaskIdExtend >> 18) & 0X000007FFU);
                FL_FSCAN_FilterSTD1_WriteEXTIDCompareMask(FSCANx, filterX, (FSCAN_FilterInitStruct->filterSTD1MaskIdExtend >> 15) & 0X7U);
            }
            else
            {   /* 滤波器1 ID设置 */
                FL_FSCAN_FilterSTD1_WriteIDCompare(FSCANx, filterX, (FSCAN_FilterInitStruct->filterSTD1IdStandard) & 0X000007FFU);
                /* 滤波器1 ID掩码设置 */
                FL_FSCAN_FilterSTD1_WriteIDCompareMask(FSCANx, filterX, (FSCAN_FilterInitStruct->filterSTD1MaskIdStandard) & 0X000007FFU);
            }
            FL_FSCAN_FilterSTD1_SetSRRCompare(FSCANx, filterX, FSCAN_FilterInitStruct->filterSTD1IdSRR);
            FL_FSCAN_FilterSTD1_SetIDECompare(FSCANx, filterX, FSCAN_FilterInitStruct->filterSTD1IdIDE);
            if((FSCAN_FilterInitStruct->filterSTD1MaskIdSRR) == FL_ENABLE)
            {   /* SRR参与滤波器比较 */
                FL_FSCAN_FilterSTD1_EnableSRRCompare(FSCANx, filterX);
            }
            else
            {
                FL_FSCAN_FilterSTD1_DisableSRRCompare(FSCANx, filterX);
            }
            if((FSCAN_FilterInitStruct->filterSTD1MaskIdIDE) == FL_ENABLE)
            {   /* IDE位参与滤波器比较 */
                FL_FSCAN_FilterSTD1_EnableIDECompare(FSCANx, filterX);
            }
            else
            {
                FL_FSCAN_FilterSTD1_DisableIDECompare(FSCANx, filterX);
            }
            /* 滤波器高16位参数设置 */
            if(FSCAN_FilterInitStruct->filterSTD2IdIDE == FL_FSCAN_STD2IDE_BIT_HIGH)
            {   /* 滤波器2 ID设置 */
                FL_FSCAN_FilterSTD2_WriteIDCompare(FSCANx, filterX, ((FSCAN_FilterInitStruct->filterSTD2IdExtend) >> 18) & 0X000007FFU);
                FL_FSCAN_FilterSTD2_WriteEXTIDCompare(FSCANx, filterX, ((FSCAN_FilterInitStruct->filterSTD2IdExtend >> 15)) & 0X7U);
                /* 滤波器2 ID掩码设置 */
                FL_FSCAN_FilterSTD2_WriteIDCompareMask(FSCANx, filterX, ((FSCAN_FilterInitStruct->filterSTD2MaskIdExtend) >> 18) & 0X000007FFU);
                FL_FSCAN_FilterSTD2_WriteEXTIDCompareMask(FSCANx, filterX, ((FSCAN_FilterInitStruct->filterSTD2MaskIdExtend) >> 15) & 0X7U);
            }
            else
            {   /* 滤波器2 ID设置 */
                FL_FSCAN_FilterSTD2_WriteIDCompare(FSCANx, filterX, (FSCAN_FilterInitStruct->filterSTD2IdStandard) & 0X000007FFU);
                /* 滤波器2 ID掩码设置 */
                FL_FSCAN_FilterSTD2_WriteIDCompareMask(FSCANx, filterX, ((FSCAN_FilterInitStruct->filterSTD2MaskIdStandard)) & 0X000007FFU);
            }
            FL_FSCAN_FilterSTD2_SetSRRCompare(FSCANx, filterX, FSCAN_FilterInitStruct->filterSTD2IdSRR);
            FL_FSCAN_FilterSTD2_SetIDECompare(FSCANx, filterX, FSCAN_FilterInitStruct->filterSTD2IdIDE);
            if((FSCAN_FilterInitStruct->filterSTD2MaskIdSRR) == FL_ENABLE)
            {   /* SRR参与滤波器比较 */
                FL_FSCAN_FilterSTD2_EnableSRRCompare(FSCANx, filterX);
            }
            else
            {
                FL_FSCAN_FilterSTD2_DisableSRRCompare(FSCANx, filterX);
            }
            if((FSCAN_FilterInitStruct->filterSTD2MaskIdIDE) == FL_ENABLE)
            {   /* IDE位参与滤波器比较 */
                FL_FSCAN_FilterSTD2_EnableIDECompare(FSCANx, filterX);
            }
            else
            {
                FL_FSCAN_FilterSTD2_DisableIDECompare(FSCANx, filterX);
            }
        }
        if((FSCAN_FilterInitStruct->filterEn) == FL_ENABLE)
        {   /* 滤波器使能 */
            FL_FSCAN_Filter_Enable(FSCANx, filterX);
        }
        else
        {
            FL_FSCAN_Filter_Disable(FSCANx, filterX);
        }
        status = FL_PASS;
    }
    return status;
}
/**
  * @brief  设置FSCAN_FilterInitStruct 为默认配置
  * @param  FSCAN_FilterInitStruct 指向需要将值设置为默认的结构体 @ref FL_FSCAN_FilterInitTypeDef 结构体
  *
  * @retval None
  */
void FL_FSCAN_StructFilterInit(FL_FSCAN_FilterInitTypeDef *FSCAN_FilterInitStruct)
{
    if(FSCAN_FilterInitStruct != NULL)
    {
        FSCAN_FilterInitStruct->filterEn = FL_DISABLE;
        FSCAN_FilterInitStruct->filterIdExtend = 0;
        FSCAN_FilterInitStruct->filterMaskIdStandard = 0x7FF;
        FSCAN_FilterInitStruct->filterIdIDE = FL_FSCAN_IDE_BIT_LOW;
        FSCAN_FilterInitStruct->filterMaskIdIDE = FL_DISABLE;
        FSCAN_FilterInitStruct->filterMaskIdExtend = 0x1FFFFFFF;
        FSCAN_FilterInitStruct->filterIdRTR = FL_FSCAN_RTR_BIT_LOW;
        FSCAN_FilterInitStruct->filterMaskIdRTR = FL_DISABLE;
        FSCAN_FilterInitStruct->filterIdSRR = FL_FSCAN_SRR_BIT_LOW;
        FSCAN_FilterInitStruct->filterMaskIdSRR = FL_DISABLE;
        FSCAN_FilterInitStruct->filterIdStandard = 0;
        FSCAN_FilterInitStruct->filterSTD1IdExtend = 0;
        FSCAN_FilterInitStruct->filterSTD1MaskIdStandard = 0x7FF;
        FSCAN_FilterInitStruct->filterSTD1IdIDE = FL_FSCAN_IDE_BIT_LOW;
        FSCAN_FilterInitStruct->filterSTD1MaskIdIDE = FL_DISABLE;
        FSCAN_FilterInitStruct->filterSTD1MaskIdExtend = 0x1FFFFFFF;
        FSCAN_FilterInitStruct->filterSTD1IdSRR = FL_FSCAN_SRR_BIT_LOW;
        FSCAN_FilterInitStruct->filterSTD1MaskIdSRR = FL_DISABLE;
        FSCAN_FilterInitStruct->filterSTD1IdStandard = 0;
        FSCAN_FilterInitStruct->filterSTD2IdExtend = 0;
        FSCAN_FilterInitStruct->filterSTD2MaskIdStandard = 0x7FF;
        FSCAN_FilterInitStruct->filterSTD2IdIDE = FL_FSCAN_IDE_BIT_LOW;
        FSCAN_FilterInitStruct->filterSTD2MaskIdIDE = FL_DISABLE;
        FSCAN_FilterInitStruct->filterSTD2MaskIdExtend = 0x1FFFFFFF;
        FSCAN_FilterInitStruct->filterSTD2IdSRR = FL_FSCAN_SRR_BIT_LOW;
        FSCAN_FilterInitStruct->filterSTD2MaskIdSRR = FL_DISABLE;
        FSCAN_FilterInitStruct->filterSTD2IdStandard = 0;
    }
}


/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/** @defgroup FSCAN_FL_Private_Functions FSCAN Private Functions
  * @{
  */

/* #error 在此处编写私有函数，并删除该行 */

/**
  * @}
  */

#endif /* FL_FSCAN_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/

