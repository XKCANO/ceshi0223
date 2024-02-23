/**
  *******************************************************************************************************
  * @file    fm33lf0xx_fl_adc.h
  * @author  FMSH Application Team
  * @brief   Head file of ADC FL Module
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
#ifndef __FM33LF0XX_FL_ADC_H
#define __FM33LF0XX_FL_ADC_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33lf0xx_fl_def.h"
/** @addtogroup FM33LF0XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup ADC_FL_ES_INIT ADC Exported Init structures
  * @{
  */
#define ADC_VREF    (*((uint16_t *)(0x1FFFFB0C)))    /*  vref1P0电压值（*10000） */
#define ADC_TS      (*((uint16_t *)(0x1FFFFB10)))    /*  PTAT电压值（*10000） */
/**
  * @brief FL ADC Init Sturcture definition
  */
typedef struct
{
    /**ADC时钟分频系数配置**/
    uint32_t clockPrescaler;
    /**ADC参考源选择**/
    uint32_t referenceSource;

} FL_ADC_CommonInitTypeDef;

typedef struct
{
    /** 连续转换模式配置 */
    FL_FunState scanacq_continuousMode;
    /** 单次自动转换模式配置 */
    uint32_t scanacq_autoMode;
    /** 通道扫描顺序配置 */
    uint32_t scanacq_Direction;       
    /** 触发源选择 */
    uint32_t triggerSource;
    /** 通道采样时间配置 */
    uint32_t ChannelTime;    
    /** 等待模式配置 */
    FL_FunState waitMode;
    /** 覆盖模式配置 */
    FL_FunState overrunMode;
    /** 过采样使能配置 */
    FL_FunState oversamplingMode;
    /** 过采样率配置 */
    uint32_t overSampingMultiplier;
    /** 过采样移位配置 */
    uint32_t oversamplingShift;
    
    
} FL_ADC_InitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup ADC_FL_Exported_Constants ADC Exported Constants
  * @{
  */

#define    ADC_ACQ_ISR_OVR_Pos                                    (16U)
#define    ADC_ACQ_ISR_OVR_Msk                                    (0x1fU << ADC_ACQ_ISR_OVR_Pos)
#define    ADC_ACQ_ISR_OVR                                        ADC_ACQ_ISR_OVR_Msk

#define    ADC_ACQ_ISR_SOCIF_Pos                                  (8U)
#define    ADC_ACQ_ISR_SOCIF_Msk                                  (0x1fU << ADC_ACQ_ISR_SOCIF_Pos)
#define    ADC_ACQ_ISR_SOCIF                                      ADC_ACQ_ISR_SOCIF_Msk

#define    ADC_ACQ_ISR_EOCIF_Pos                                  (0U)
#define    ADC_ACQ_ISR_EOCIF_Msk                                  (0x1fU << ADC_ACQ_ISR_EOCIF_Pos)
#define    ADC_ACQ_ISR_EOCIF                                      ADC_ACQ_ISR_EOCIF_Msk

#define    ADC_ACQ_IER_OVRIE_Pos                                  (16U)
#define    ADC_ACQ_IER_OVRIE_Msk                                  (0x1fU << ADC_ACQ_IER_OVRIE_Pos)
#define    ADC_ACQ_IER_OVRIE                                      ADC_ACQ_IER_OVRIE_Msk

#define    ADC_ACQ_IER_SOCIE_Pos                                  (8U)
#define    ADC_ACQ_IER_SOCIE_Msk                                  (0x1fU << ADC_ACQ_IER_SOCIE_Pos)
#define    ADC_ACQ_IER_SOCIE                                      ADC_ACQ_IER_SOCIE_Msk

#define    ADC_ACQ_IER_EOCIE_Pos                                  (0U)
#define    ADC_ACQ_IER_EOCIE_Msk                                  (0x1fU << ADC_ACQ_IER_EOCIE_Pos)
#define    ADC_ACQ_IER_EOCIE                                      ADC_ACQ_IER_EOCIE_Msk

#define    ADC_GISR_SCAN_CH_Pos                                   (16U)
#define    ADC_GISR_SCAN_CH_Msk                                   (0xffffU << ADC_GISR_SCAN_CH_Pos)
#define    ADC_GISR_SCAN_CH                                       ADC_GISR_SCAN_CH_Msk

#define    ADC_GISR_ACQ_ID_Pos                                    (8U)
#define    ADC_GISR_ACQ_ID_Msk                                    (0x1fU << ADC_GISR_ACQ_ID_Pos)
#define    ADC_GISR_ACQ_ID                                        ADC_GISR_ACQ_ID_Msk

#define    ADC_GISR_AWD_AH_Pos                                    (6U)
#define    ADC_GISR_AWD_AH_Msk                                    (0x1U << ADC_GISR_AWD_AH_Pos)
#define    ADC_GISR_AWD_AH                                        ADC_GISR_AWD_AH_Msk

#define    ADC_GISR_AWD_UL_Pos                                    (5U)
#define    ADC_GISR_AWD_UL_Msk                                    (0x1U << ADC_GISR_AWD_UL_Pos)
#define    ADC_GISR_AWD_UL                                        ADC_GISR_AWD_UL_Msk

#define    ADC_GISR_BUSY_Pos                                      (3U)
#define    ADC_GISR_BUSY_Msk                                      (0x1U << ADC_GISR_BUSY_Pos)
#define    ADC_GISR_BUSY                                          ADC_GISR_BUSY_Msk

#define    ADC_GISR_EOCNT_Pos                                     (2U)
#define    ADC_GISR_EOCNT_Msk                                     (0x1U << ADC_GISR_EOCNT_Pos)
#define    ADC_GISR_EOCNT                                         ADC_GISR_EOCNT_Msk

#define    ADC_GISR_EOS_Pos                                       (1U)
#define    ADC_GISR_EOS_Msk                                       (0x1U << ADC_GISR_EOS_Pos)
#define    ADC_GISR_EOS                                           ADC_GISR_EOS_Msk

#define    ADC_GIER_AWD_AHIE_Pos                                  (6U)
#define    ADC_GIER_AWD_AHIE_Msk                                  (0x1U << ADC_GIER_AWD_AHIE_Pos)
#define    ADC_GIER_AWD_AHIE                                      ADC_GIER_AWD_AHIE_Msk

#define    ADC_GIER_AWD_ULIE_Pos                                  (5U)
#define    ADC_GIER_AWD_ULIE_Msk                                  (0x1U << ADC_GIER_AWD_ULIE_Pos)
#define    ADC_GIER_AWD_ULIE                                      ADC_GIER_AWD_ULIE_Msk

#define    ADC_GIER_EOCNTIE_Pos                                   (2U)
#define    ADC_GIER_EOCNTIE_Msk                                   (0x1U << ADC_GIER_EOCNTIE_Pos)
#define    ADC_GIER_EOCNTIE                                       ADC_GIER_EOCNTIE_Msk

#define    ADC_GIER_EOSIE_Pos                                     (1U)
#define    ADC_GIER_EOSIE_Msk                                     (0x1U << ADC_GIER_EOSIE_Pos)
#define    ADC_GIER_EOSIE                                         ADC_GIER_EOSIE_Msk

#define    ADC_CR1_ACQEN_Pos                                      (16U)
#define    ADC_CR1_ACQEN_Msk                                      (0x1fU << ADC_CR1_ACQEN_Pos)
#define    ADC_CR1_ACQEN                                          ADC_CR1_ACQEN_Msk

#define    ADC_CR1_SCH_SWRST_Pos                                  (2U)
#define    ADC_CR1_SCH_SWRST_Msk                                  (0x1U << ADC_CR1_SCH_SWRST_Pos)
#define    ADC_CR1_SCH_SWRST                                      ADC_CR1_SCH_SWRST_Msk

#define    ADC_CR1_RR_SWRST_Pos                                   (1U)
#define    ADC_CR1_RR_SWRST_Msk                                   (0x1U << ADC_CR1_RR_SWRST_Pos)
#define    ADC_CR1_RR_SWRST                                       ADC_CR1_RR_SWRST_Msk

#define    ADC_CR1_ADEN_Pos                                       (0U)
#define    ADC_CR1_ADEN_Msk                                       (0x1U << ADC_CR1_ADEN_Pos)
#define    ADC_CR1_ADEN                                           ADC_CR1_ADEN_Msk

#define    ADC_CR2_SWTRIG_Pos                                     (0U)
#define    ADC_CR2_SWTRIG_Msk                                     (0x1fU << ADC_CR2_SWTRIG_Pos)
#define    ADC_CR2_SWTRIG                                         ADC_CR2_SWTRIG_Msk

#define    ADC_CFGR1_RPTLEN_Pos                                   (16U)
#define    ADC_CFGR1_RPTLEN_Msk                                   (0xffffU << ADC_CFGR1_RPTLEN_Pos)
#define    ADC_CFGR1_RPTLEN                                       ADC_CFGR1_RPTLEN_Msk

#define    ADC_CFGR1_SOCIF_CFG_Pos                                (8U)
#define    ADC_CFGR1_SOCIF_CFG_Msk                                (0x1U << ADC_CFGR1_SOCIF_CFG_Pos)
#define    ADC_CFGR1_SOCIF_CFG                                    ADC_CFGR1_SOCIF_CFG_Msk

#define    ADC_CFGR1_PCLK_PSC_Pos                                 (5U)
#define    ADC_CFGR1_PCLK_PSC_Msk                                 (0x7U << ADC_CFGR1_PCLK_PSC_Pos)
#define    ADC_CFGR1_PCLK_PSC                                     ADC_CFGR1_PCLK_PSC_Msk

#define    ADC_CFGR1_VCM_CTRL_Pos                                 (4U)
#define    ADC_CFGR1_VCM_CTRL_Msk                                 (0x1U << ADC_CFGR1_VCM_CTRL_Pos)
#define    ADC_CFGR1_VCM_CTRL                                     ADC_CFGR1_VCM_CTRL_Msk

#define    ADC_CFGR1_INJ_MODE_Pos                                 (3U)
#define    ADC_CFGR1_INJ_MODE_Msk                                 (0x1U << ADC_CFGR1_INJ_MODE_Pos)
#define    ADC_CFGR1_INJ_MODE                                     ADC_CFGR1_INJ_MODE_Msk

#define    ADC_CFGR1_REFNSEL_Pos                                  (2U)
#define    ADC_CFGR1_REFNSEL_Msk                                  (0x1U << ADC_CFGR1_REFNSEL_Pos)
#define    ADC_CFGR1_REFNSEL                                      ADC_CFGR1_REFNSEL_Msk

#define    ADC_CFGR1_PEFSEL_Pos                                   (0U)
#define    ADC_CFGR1_PEFSEL_Msk                                   (0x1U << ADC_CFGR1_PEFSEL_Pos)
#define    ADC_CFGR1_PEFSEL                                       ADC_CFGR1_PEFSEL_Msk

#define    ADC_CFGR2_AVGR_OVSS_Pos                                (21U)
#define    ADC_CFGR2_AVGR_OVSS_Msk                                (0xfU << ADC_CFGR2_AVGR_OVSS_Pos)
#define    ADC_CFGR2_AVGR_OVSS                                    ADC_CFGR2_AVGR_OVSS_Msk

#define    ADC_CFGR2_AVGR_OVSR_Pos                                (18U)
#define    ADC_CFGR2_AVGR_OVSR_Msk                                (0x7U << ADC_CFGR2_AVGR_OVSR_Pos)
#define    ADC_CFGR2_AVGR_OVSR                                    ADC_CFGR2_AVGR_OVSR_Msk

#define    ADC_CFGR2_AVGEN_Pos                                    (16U)
#define    ADC_CFGR2_AVGEN_Msk                                    (0x3U << ADC_CFGR2_AVGEN_Pos)
#define    ADC_CFGR2_AVGEN                                        ADC_CFGR2_AVGEN_Msk

#define    ADC_CFGR2_WAIT_F_Pos                                   (11U)
#define    ADC_CFGR2_WAIT_F_Msk                                   (0x1U << ADC_CFGR2_WAIT_F_Pos)
#define    ADC_CFGR2_WAIT_F                                       ADC_CFGR2_WAIT_F_Msk

#define    ADC_CFGR2_AUTO_SCAN_Pos                                (10U)
#define    ADC_CFGR2_AUTO_SCAN_Msk                                (0x1U << ADC_CFGR2_AUTO_SCAN_Pos)
#define    ADC_CFGR2_AUTO_SCAN                                    ADC_CFGR2_AUTO_SCAN_Msk

#define    ADC_CFGR2_CONT_MOD_Pos                                 (9U)
#define    ADC_CFGR2_CONT_MOD_Msk                                 (0x1U << ADC_CFGR2_CONT_MOD_Pos)
#define    ADC_CFGR2_CONT_MOD                                     ADC_CFGR2_CONT_MOD_Msk

#define    ADC_CFGR2_OVRM_Pos                                     (8U)
#define    ADC_CFGR2_OVRM_Msk                                     (0x1U << ADC_CFGR2_OVRM_Pos)
#define    ADC_CFGR2_OVRM                                         ADC_CFGR2_OVRM_Msk

#define    ADC_CFGR2_SCANDIR_Pos                                  (2U)
#define    ADC_CFGR2_SCANDIR_Msk                                  (0x1U << ADC_CFGR2_SCANDIR_Pos)
#define    ADC_CFGR2_SCANDIR                                      ADC_CFGR2_SCANDIR_Msk

#define    ADC_CFGR2_DMAEN_Pos                                    (0U)
#define    ADC_CFGR2_DMAEN_Msk                                    (0x1U << ADC_CFGR2_DMAEN_Pos)
#define    ADC_CFGR2_DMAEN                                        ADC_CFGR2_DMAEN_Msk

#define    ADC_OSR_CALEN_Pos                                      (16U)
#define    ADC_OSR_CALEN_Msk                                      (0x1U << ADC_OSR_CALEN_Pos)
#define    ADC_OSR_CALEN                                          ADC_OSR_CALEN_Msk

#define    ADC_OSR_OS_CALI_Pos                                    (0U)
#define    ADC_OSR_OS_CALI_Msk                                    (0x1fffU << ADC_OSR_OS_CALI_Pos)
#define    ADC_OSR_OS_CALI                                        ADC_OSR_OS_CALI_Msk

#define    ADC_ACQ_SR_REQ_Pos                                     (0U)
#define    ADC_ACQ_SR_REQ_Msk                                     (0x1fU << ADC_ACQ_SR_REQ_Pos)
#define    ADC_ACQ_SR_REQ                                         ADC_ACQ_SR_REQ_Msk

#define    ADC_HLTR_AWD_HT_Pos                                    (16U)
#define    ADC_HLTR_AWD_HT_Msk                                    (0xffffU << ADC_HLTR_AWD_HT_Pos)
#define    ADC_HLTR_AWD_HT                                        ADC_HLTR_AWD_HT_Msk

#define    ADC_HLTR_AWD_LT_Pos                                    (0U)
#define    ADC_HLTR_AWD_LT_Msk                                    (0xffffU << ADC_HLTR_AWD_LT_Pos)
#define    ADC_HLTR_AWD_LT                                        ADC_HLTR_AWD_LT_Msk

#define    ADC_ACQ0_CR_CHSEL_Pos                                  (9U)
#define    ADC_ACQ0_CR_CHSEL_Msk                                  (0x1fU << ADC_ACQ0_CR_CHSEL_Pos)
#define    ADC_ACQ0_CR_CHSEL                                      ADC_ACQ0_CR_CHSEL_Msk

#define    ADC_ACQ0_CR_TRIGSEL_Pos                                (4U)
#define    ADC_ACQ0_CR_TRIGSEL_Msk                                (0x1fU << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    ADC_ACQ0_CR_TRIGSEL                                    ADC_ACQ0_CR_TRIGSEL_Msk

#define    ADC_ACQ0_CR_SMTS_Pos                                   (0U)
#define    ADC_ACQ0_CR_SMTS_Msk                                   (0xfU << ADC_ACQ0_CR_SMTS_Pos)
#define    ADC_ACQ0_CR_SMTS                                       ADC_ACQ0_CR_SMTS_Msk

#define    ADC_ACQ1_CR_CHSEL_Pos                                  (9U)
#define    ADC_ACQ1_CR_CHSEL_Msk                                  (0x1fU << ADC_ACQ1_CR_CHSEL_Pos)
#define    ADC_ACQ1_CR_CHSEL                                      ADC_ACQ1_CR_CHSEL_Msk

#define    ADC_ACQ1_CR_TRIGSEL_Pos                                (4U)
#define    ADC_ACQ1_CR_TRIGSEL_Msk                                (0x1fU << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    ADC_ACQ1_CR_TRIGSEL                                    ADC_ACQ1_CR_TRIGSEL_Msk

#define    ADC_ACQ1_CR_SMTS_Pos                                   (0U)
#define    ADC_ACQ1_CR_SMTS_Msk                                   (0xfU << ADC_ACQ1_CR_SMTS_Pos)
#define    ADC_ACQ1_CR_SMTS                                       ADC_ACQ1_CR_SMTS_Msk

#define    ADC_ACQ2_CR_CHSEL_Pos                                  (9U)
#define    ADC_ACQ2_CR_CHSEL_Msk                                  (0x1fU << ADC_ACQ2_CR_CHSEL_Pos)
#define    ADC_ACQ2_CR_CHSEL                                      ADC_ACQ2_CR_CHSEL_Msk

#define    ADC_ACQ2_CR_TRIGSEL_Pos                                (4U)
#define    ADC_ACQ2_CR_TRIGSEL_Msk                                (0x1fU << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    ADC_ACQ2_CR_TRIGSEL                                    ADC_ACQ2_CR_TRIGSEL_Msk

#define    ADC_ACQ2_CR_SMTS_Pos                                   (0U)
#define    ADC_ACQ2_CR_SMTS_Msk                                   (0xfU << ADC_ACQ2_CR_SMTS_Pos)
#define    ADC_ACQ2_CR_SMTS                                       ADC_ACQ2_CR_SMTS_Msk

#define    ADC_ACQ3_CR_CHSEL_Pos                                  (9U)
#define    ADC_ACQ3_CR_CHSEL_Msk                                  (0x1fU << ADC_ACQ3_CR_CHSEL_Pos)
#define    ADC_ACQ3_CR_CHSEL                                      ADC_ACQ3_CR_CHSEL_Msk

#define    ADC_ACQ3_CR_TRIGSEL_Pos                                (4U)
#define    ADC_ACQ3_CR_TRIGSEL_Msk                                (0x1fU << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    ADC_ACQ3_CR_TRIGSEL                                    ADC_ACQ3_CR_TRIGSEL_Msk

#define    ADC_ACQ3_CR_SMTS_Pos                                   (0U)
#define    ADC_ACQ3_CR_SMTS_Msk                                   (0xfU << ADC_ACQ3_CR_SMTS_Pos)
#define    ADC_ACQ3_CR_SMTS                                       ADC_ACQ3_CR_SMTS_Msk

#define    ADC_SCANACQ_CR_TRIGSEL_Pos                             (4U)
#define    ADC_SCANACQ_CR_TRIGSEL_Msk                             (0x1fU << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    ADC_SCANACQ_CR_TRIGSEL                                 ADC_SCANACQ_CR_TRIGSEL_Msk

#define    ADC_SCANACQ_CR_SMTS_Pos                                (0U)
#define    ADC_SCANACQ_CR_SMTS_Msk                                (0xfU << ADC_SCANACQ_CR_SMTS_Pos)
#define    ADC_SCANACQ_CR_SMTS                                    ADC_SCANACQ_CR_SMTS_Msk

#define    ADC_ACQ0_DR_RESULT_Pos                                 (0U)
#define    ADC_ACQ0_DR_RESULT_Msk                                 (0xffffU << ADC_ACQ0_DR_RESULT_Pos)
#define    ADC_ACQ0_DR_RESULT                                     ADC_ACQ0_DR_RESULT_Msk

#define    ADC_ACQ1_DR_RESULT_Pos                                 (0U)
#define    ADC_ACQ1_DR_RESULT_Msk                                 (0xffffU << ADC_ACQ1_DR_RESULT_Pos)
#define    ADC_ACQ1_DR_RESULT                                     ADC_ACQ1_DR_RESULT_Msk

#define    ADC_ACQ2_DR_RESULT_Pos                                 (0U)
#define    ADC_ACQ2_DR_RESULT_Msk                                 (0xffffU << ADC_ACQ2_DR_RESULT_Pos)
#define    ADC_ACQ2_DR_RESULT                                     ADC_ACQ2_DR_RESULT_Msk

#define    ADC_ACQ3_DR_RESULT_Pos                                 (0U)
#define    ADC_ACQ3_DR_RESULT_Msk                                 (0xffffU << ADC_ACQ3_DR_RESULT_Pos)
#define    ADC_ACQ3_DR_RESULT                                     ADC_ACQ3_DR_RESULT_Msk

#define    ADC_SCANACQ_DR_RESULT_Pos                              (0U)
#define    ADC_SCANACQ_DR_RESULT_Msk                              (0xffffU << ADC_SCANACQ_DR_RESULT_Pos)
#define    ADC_SCANACQ_DR_RESULT                                  ADC_SCANACQ_DR_RESULT_Msk

#define    ADC_SCANACQ_DR_CHID_Pos                                (16U)
#define    ADC_SCANACQ_DR_CHID_Msk                                (0x1fU << ADC_SCANACQ_DR_CHID_Pos)
#define    ADC_SCANACQ_DR_CHID                                    ADC_SCANACQ_DR_CHID_Msk



#define    FL_ADC_ACQ0                                            (0x1U << 0U)
#define    FL_ADC_ACQ1                                            (0x1U << 1U)
#define    FL_ADC_ACQ2                                            (0x1U << 2U)
#define    FL_ADC_ACQ3                                            (0x1U << 3U)
#define    FL_ADC_SCAN_ACQ                                        (0x1U << 4U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH0                 (0x0U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH1                 (0x1U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH2                 (0x2U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH3                 (0x3U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH4                 (0x4U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH5                 (0x5U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH6                 (0x6U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH7                 (0x7U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH8                 (0x8U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH9                 (0x9U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH10                (0xaU << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH11                (0xbU << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TS                  (0xcU << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_AVREF               (0xdU << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_OPA1                (0xeU << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_OPA2                (0xfU << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFP               (0x10U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN               (0x11U << 9U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH0                            (0x1U << 0U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH1                            (0x1U << 1U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH2                            (0x1U << 2U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH3                            (0x1U << 3U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH4                            (0x1U << 4U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH5                            (0x1U << 5U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH6                            (0x1U << 6U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH7                            (0x1U << 7U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH8                            (0x1U << 8U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH9                            (0x1U << 9U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH10                           (0x1U << 10U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH11                           (0x1U << 11U)
#define    FL_ADC_SCANACQ_INTERNAL_TS                             (0x1U << 12U)
#define    FL_ADC_SCANACQ_INTERNAL_AVREF                          (0x1U << 13U)
#define    FL_ADC_SCANACQ_INTERNAL_OPA1                           (0x1U << 14U)
#define    FL_ADC_SCANACQ_INTERNAL_OPA2                           (0x1U << 15U)
#define    FL_ADC_SCANACQ_INTERNAL_VREFP                          (0x1U << 16U)
#define    FL_ADC_SCANACQ_INTERNAL_VREFN                          (0x1U << 17U)
#define    FL_ADC_ALL_CHANNEL                                     (0x3ffffU << 0U)
#define    FL_ADC_ACQ_TRGI_SOFE_TRG                               (0x0U << 4U)
#define    FL_ADC_ACQ_TRGI_LUT0_TRG0                              (0x1U << 4U)
#define    FL_ADC_ACQ_TRGI_LUT1_TRG0                              (0x2U << 4U)
#define    FL_ADC_ACQ_TRGI_LUT2_TRG0                              (0x3U << 4U)
#define    FL_ADC_ACQ_TRGI_LUT3_TRG0                              (0x4U << 4U)
#define    FL_ADC_ACQ_TRGI_ATIM_TRG0                              (0x5U << 4U)
#define    FL_ADC_ACQ_TRGI_ATIM_TRG02                             (0x7U << 4U)
#define    FL_ADC_ACQ_TRGI_GPTIM0_TRG0                            (0x9U << 4U)
#define    FL_ADC_ACQ_TRGI_GPTIM1_TRG0                            (0xaU << 4U)
#define    FL_ADC_ACQ_TRGI_COMP1_TRG0                             (0x13U << 4U)
#define    FL_ADC_ACQ_TRGI_COMP2_TRG0                             (0x14U << 4U)
#define    FL_ADC_ACQ_TRGI_COMP3_TRG0                             (0x15U << 4U)
#define    FL_ADC_ACQ_TRGI_COMP4_TRG0                             (0x16U << 4U)
#define    FL_ADC_ACQ_TRGI_LPTIM_TRG0                             (0x17U << 4U)
#define    FL_ADC_ACQ_TRGI_BSTIM_TRG0                             (0x18U << 4U)
#define    FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK                      (0x1U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_4_ADCCLK                      (0x2U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_8_ADCCLK                      (0x3U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_12_ADCCLK                     (0x4U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_16_ADCCLK                     (0x5U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_32_ADCCLK                     (0x6U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_64_ADCCLK                     (0x7U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_80_ADCCLK                     (0x8U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_96_ADCCLK                     (0x9U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK                    (0xaU << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_160_ADCCLK                    (0xbU << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_192_ADCCLK                    (0xcU << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_256_ADCCLK                    (0xdU << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_320_ADCCLK                    (0xeU << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK                    (0xfU << 0U)



#define    FL_ADC_SOC_EDGE_MODE_RISE                              (0x0U << ADC_CFGR1_SOCIF_CFG_Pos)
#define    FL_ADC_SOC_EDGE_MODE_FALL                              (0x1U << ADC_CFGR1_SOCIF_CFG_Pos)


#define    FL_ADC_APBCLK_PSC_DIV1                                 (0x1U << ADC_CFGR1_PCLK_PSC_Pos)
#define    FL_ADC_APBCLK_PSC_DIV2                                 (0x2U << ADC_CFGR1_PCLK_PSC_Pos)
#define    FL_ADC_APBCLK_PSC_DIV3                                 (0x3U << ADC_CFGR1_PCLK_PSC_Pos)
#define    FL_ADC_APBCLK_PSC_DIV4                                 (0x4U << ADC_CFGR1_PCLK_PSC_Pos)
#define    FL_ADC_APBCLK_PSC_DIV5                                 (0x5U << ADC_CFGR1_PCLK_PSC_Pos)
#define    FL_ADC_APBCLK_PSC_DIV6                                 (0x6U << ADC_CFGR1_PCLK_PSC_Pos)


#define    FL_ADC_VCM_MODE_PERIODIC                               (0x0U << ADC_CFGR1_VCM_CTRL_Pos)
#define    FL_ADC_VCM_MODE_CONTINUOUS                             (0x1U << ADC_CFGR1_VCM_CTRL_Pos)


#define    FL_ADC_INJ_MODE_DELAY                                  (0x0U << ADC_CFGR1_INJ_MODE_Pos)
#define    FL_ADC_INJ_MODE_IMMEDIA                                (0x1U << ADC_CFGR1_INJ_MODE_Pos)


#define    FL_ADC_Negative_Peference_VSSA                         (0x0U << ADC_CFGR1_REFNSEL_Pos)
#define    FL_ADC_Negative_Peference_VREFN                        (0x1U << ADC_CFGR1_REFNSEL_Pos)


#define    FL_ADC_REF_SOURCE_VDDA                                 (0x0U << ADC_CFGR1_PEFSEL_Pos)
#define    FL_ADC_REF_SOURCE_VREFP                                (0x1U << ADC_CFGR1_PEFSEL_Pos)


#define    FL_ADC_OVERSAMPLING_SHIFT_0B                           (0x0U << ADC_CFGR2_AVGR_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_1B                           (0x1U << ADC_CFGR2_AVGR_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_2B                           (0x2U << ADC_CFGR2_AVGR_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_3B                           (0x3U << ADC_CFGR2_AVGR_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_4B                           (0x4U << ADC_CFGR2_AVGR_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_5B                           (0x5U << ADC_CFGR2_AVGR_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_6B                           (0x6U << ADC_CFGR2_AVGR_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_7B                           (0x7U << ADC_CFGR2_AVGR_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_8B                           (0x8U << ADC_CFGR2_AVGR_OVSS_Pos)


#define    FL_ADC_OVERSAMPLING_MUL_2X                             (0x0U << ADC_CFGR2_AVGR_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_4X                             (0x1U << ADC_CFGR2_AVGR_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_8X                             (0x2U << ADC_CFGR2_AVGR_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_16X                            (0x3U << ADC_CFGR2_AVGR_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_32X                            (0x4U << ADC_CFGR2_AVGR_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_64X                            (0x5U << ADC_CFGR2_AVGR_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_128X                           (0x6U << ADC_CFGR2_AVGR_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_256X                           (0x7U << ADC_CFGR2_AVGR_OVSR_Pos)


#define    FL_ADC_OVERSAMPLING_MODE_DISABLE                       (0x0U << ADC_CFGR2_AVGEN_Pos)
#define    FL_ADC_OVERSAMPLING_MODE_ENABLE_AVERAGE                (0x1U << ADC_CFGR2_AVGEN_Pos)


#define    FL_ADC_SCANACQ_CONV_MODE_SEMIAUTO                      (0x0U << ADC_CFGR2_AUTO_SCAN_Pos)
#define    FL_ADC_SCANACQ_CONV_MODE_AUTO                          (0x1U << ADC_CFGR2_AUTO_SCAN_Pos)


#define    FL_ADC_SCANACQ_SCAN_DIR_BACKWARD                       (0x0U << ADC_CFGR2_SCANDIR_Pos)
#define    FL_ADC_SCANACQ_SCAN_DIR_FORWARD                        (0x1U << ADC_CFGR2_SCANDIR_Pos)



#define    FL_ADC_SCANACQ_TRGI_SOFE_TRGO                          (0x0U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_LUT0_TRGO                          (0x1U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_LUT1_TRGO                          (0x2U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_LUT2_TRGO                          (0x3U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_LUT3_TRGO                          (0x4U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_ATIM_TRGO                          (0x5U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_ATIM_TRGO2                         (0x7U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_GPTIM0_TRGO                        (0x9U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_GPTIM1_TRGO                        (0xaU << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_COMP1_TRGO                         (0x13U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_COMP2_TRGO                         (0x14U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_COMP3_TRGO                         (0x15U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_COMP4_TRGO                         (0x16U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_LPTIM_TRGO                         (0x17U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_BSTIM_TRGO                         (0x18U << ADC_SCANACQ_CR_TRIGSEL_Pos)


#define    FL_ADC_SCANACQ_SAMPLING_TIME_2_ADCCLK                  (0x1U << ADC_SCANACQ_CR_SMTS_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_TIME_4_ADCCLK                  (0x2U << ADC_SCANACQ_CR_SMTS_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_TIME_8_ADCCLK                  (0x3U << ADC_SCANACQ_CR_SMTS_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_TIME_12_ADCCLK                 (0x4U << ADC_SCANACQ_CR_SMTS_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_TIME_16_ADCCLK                 (0x5U << ADC_SCANACQ_CR_SMTS_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_TIME_32_ADCCLK                 (0x6U << ADC_SCANACQ_CR_SMTS_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_TIME_64_ADCCLK                 (0x7U << ADC_SCANACQ_CR_SMTS_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_TIME_80_ADCCLK                 (0x8U << ADC_SCANACQ_CR_SMTS_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_TIME_96_ADCCLK                 (0x9U << ADC_SCANACQ_CR_SMTS_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_TIME_128_ADCCLK                (0xaU << ADC_SCANACQ_CR_SMTS_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_TIME_160_ADCCLK                (0xbU << ADC_SCANACQ_CR_SMTS_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_TIME_192_ADCCLK                (0xcU << ADC_SCANACQ_CR_SMTS_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_TIME_256_ADCCLK                (0xdU << ADC_SCANACQ_CR_SMTS_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_TIME_320_ADCCLK                (0xeU << ADC_SCANACQ_CR_SMTS_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_TIME_512_ADCCLK                (0xfU << ADC_SCANACQ_CR_SMTS_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup ADC_FL_Exported_Functions ADC Exported Functions
  * @{
  */

/**
  * @brief    获取ADC 数据冲突标志

  * @rmtoll   ACQ_ISR    OVR    FL_ADC_IsActiveFlag_Overrun
  * @param    ADCx ADC instance
  * @param    acqx_ovr This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_Overrun(ADC_Type *ADCx, uint32_t acqx_ovr)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_ISR, ((acqx_ovr & 0x1f) << 0x10U)) == ((acqx_ovr & 0x1f) << 0x10U));
}

/**
  * @brief    清除ADC 数据冲突标志

  * @rmtoll   ACQ_ISR    OVR    FL_ADC_ClearFlag_Overrun
  * @param    ADCx ADC instance
  * @param    acqx_ovr This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_Overrun(ADC_Type *ADCx, uint32_t acqx_ovr)
{
    WRITE_REG(ADCx->ACQ_ISR, ((acqx_ovr & 0x1f) << 0x10U));
}

/**
  * @brief    获取ADC 转换开始标志

  * @rmtoll   ACQ_ISR    SOCIF    FL_ADC_IsActiveFlag_StartOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_soc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_StartOfConversion(ADC_Type *ADCx, uint32_t acqx_soc)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_ISR, ((acqx_soc & 0x1f) << 0x8U)) == ((acqx_soc & 0x1f) << 0x8U));
}

/**
  * @brief    清除ADC 转换开始标志

  * @rmtoll   ACQ_ISR    SOCIF    FL_ADC_ClearFlag_StartOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_soc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_StartOfConversion(ADC_Type *ADCx, uint32_t acqx_soc)
{
    WRITE_REG(ADCx->ACQ_ISR, ((acqx_soc & 0x1f) << 0x8U));
}

/**
  * @brief    获取ADC 转换结束标志

  * @rmtoll   ACQ_ISR    EOCIF    FL_ADC_IsActiveFlag_EndOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_eoc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_EndOfConversion(ADC_Type *ADCx, uint32_t acqx_eoc)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_ISR, ((acqx_eoc & 0x1f) << 0x0U)) == ((acqx_eoc & 0x1f) << 0x0U));
}

/**
  * @brief    清除ADC 转换结束标志

  * @rmtoll   ACQ_ISR    EOCIF    FL_ADC_ClearFlag_EndOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_eoc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_EndOfConversion(ADC_Type *ADCx, uint32_t acqx_eoc)
{
    WRITE_REG(ADCx->ACQ_ISR, ((acqx_eoc & 0x1f) << 0x0U));
}

/**
  * @brief    使能ADC 数据冲突中断
  * @rmtoll   ACQ_IER    OVRIE    FL_ADC_EnableIT_Overrun
  * @param    ADCx ADC instance
  * @param    acqx_ovr This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_Overrun(ADC_Type *ADCx, uint32_t acqx_ovr)
{
    SET_BIT(ADCx->ACQ_IER, ((acqx_ovr & 0x1f) << 0x10U));
}

/**
  * @brief    失能ADC数据冲突中断
  * @rmtoll   ACQ_IER    OVRIE    FL_ADC_DisableIT_Overrun
  * @param    ADCx ADC instance
  * @param    acqx_ovr This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_Overrun(ADC_Type *ADCx, uint32_t acqx_ovr)
{
    CLEAR_BIT(ADCx->ACQ_IER, ((acqx_ovr & 0x1f) << 0x10U));
}

/**
  * @brief    获取ADC数据冲突中断使能状态
  * @rmtoll   ACQ_IER    OVRIE    FL_ADC_IsEnabledIT_Overrun
  * @param    ADCx ADC instance
  * @param    acqx_ovr This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_Overrun(ADC_Type *ADCx, uint32_t acqx_ovr)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_IER, ((acqx_ovr & 0x1f) << 0x10U)) == ((acqx_ovr & 0x1f) << 0x10U));
}

/**
  * @brief    使能ADC 单次转换开始中断
  * @rmtoll   ACQ_IER    SOCIE    FL_ADC_EnableIT_StartOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_soc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_StartOfConversion(ADC_Type *ADCx, uint32_t acqx_soc)
{
    SET_BIT(ADCx->ACQ_IER, ((acqx_soc & 0x1f) << 0x8U));
}

/**
  * @brief    失能ADC 单次转换开始中断
  * @rmtoll   ACQ_IER    SOCIE    FL_ADC_DisableIT_StartOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_soc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_StartOfConversion(ADC_Type *ADCx, uint32_t acqx_soc)
{
    CLEAR_BIT(ADCx->ACQ_IER, ((acqx_soc & 0x1f) << 0x8U));
}

/**
  * @brief    获取ADC 单次转换开始中断使能状态
  * @rmtoll   ACQ_IER    SOCIE    FL_ADC_IsEnabledIT_StartOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_soc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_StartOfConversion(ADC_Type *ADCx, uint32_t acqx_soc)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_IER, ((acqx_soc & 0x1f) << 0x8U)) == ((acqx_soc & 0x1f) << 0x8U));
}

/**
  * @brief    使能ADC 单次转换完成中断
  * @rmtoll   ACQ_IER    EOCIE    FL_ADC_EnableIT_EndOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_eoc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_EndOfConversion(ADC_Type *ADCx, uint32_t acqx_eoc)
{
    SET_BIT(ADCx->ACQ_IER, ((acqx_eoc & 0x1f) << 0x0U));
}

/**
  * @brief    失能ADC单次转换完成中断
  * @rmtoll   ACQ_IER    EOCIE    FL_ADC_DisableIT_EndOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_eoc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_EndOfConversion(ADC_Type *ADCx, uint32_t acqx_eoc)
{
    CLEAR_BIT(ADCx->ACQ_IER, ((acqx_eoc & 0x1f) << 0x0U));
}

/**
  * @brief    获取ADC单次转换完成中断使能状态
  * @rmtoll   ACQ_IER    EOCIE    FL_ADC_IsEnabledIT_EndOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_eoc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_EndOfConversion(ADC_Type *ADCx, uint32_t acqx_eoc)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_IER, ((acqx_eoc & 0x1f) << 0x0U)) == ((acqx_eoc & 0x1f) << 0x0U));
}

/**
  * @brief    获取Scan_ACQ正在扫描的通道ID
  * @rmtoll   GISR    SCAN_CH    FL_ADC_GetScanACQ_ChannelID
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_GetScanACQ_ChannelID(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GISR, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    获取正在工作的ACQx ID
  * @rmtoll   GISR    ACQ_ID    FL_ADC_GetWorkingACQID
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_GetWorkingACQID(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GISR, (0x1fU << 8U)) >> 8U);
}

/**
  * @brief    获取ADC 模拟看门狗低于上限标志

  * @rmtoll   GISR    AWD_AH    FL_ADC_IsActiveFlag_AnalogWDGAboveHigh
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_AnalogWDGAboveHigh(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GISR, ADC_GISR_AWD_AH_Msk) == (ADC_GISR_AWD_AH_Msk));
}

/**
  * @brief    清除ADC 模拟看门狗低于上限标志


  * @rmtoll   GISR    AWD_AH    FL_ADC_ClearFlag_AnalogWDGAboveHigh
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_AnalogWDGAboveHigh(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->GISR, ADC_GISR_AWD_AH_Msk);
}

/**
  * @brief    获取ADC 模拟看门狗低于下限标志

  * @rmtoll   GISR    AWD_UL    FL_ADC_IsActiveFlag_AnalogWDGUnderLow
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_AnalogWDGUnderLow(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GISR, ADC_GISR_AWD_UL_Msk) == (ADC_GISR_AWD_UL_Msk));
}

/**
  * @brief    清除ADC 模拟看门狗低于下限标志


  * @rmtoll   GISR    AWD_UL    FL_ADC_ClearFlag_AnalogWDGUnderLow
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_AnalogWDGUnderLow(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->GISR, ADC_GISR_AWD_UL_Msk);
}

/**
  * @brief    获取ADC 忙标志

  * @rmtoll   GISR    BUSY    FL_ADC_IsActiveFlag_Busy
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_Busy(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GISR, ADC_GISR_BUSY_Msk) == (ADC_GISR_BUSY_Msk));
}

/**
  * @brief    清除ADC 连续模式完成标志
  * @rmtoll   GISR    EOCNT    FL_ADC_ClearFlag_ContinuousModeComplete
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_ContinuousModeComplete(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->GISR, ADC_GISR_EOCNT_Msk);
}

/**
  * @brief    获取ADC 连续模式完成标志
  * @rmtoll   GISR    EOCNT    FL_ADC_IsActiveFlag_ContinuousModeComplete
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_ContinuousModeComplete(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GISR, ADC_GISR_EOCNT_Msk) == (ADC_GISR_EOCNT_Msk));
}

/**
  * @brief    获取ADC 转换序列结束标志

  * @rmtoll   GISR    EOS    FL_ADC_IsActiveFlag_EndOfSequence
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_EndOfSequence(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GISR, ADC_GISR_EOS_Msk) == (ADC_GISR_EOS_Msk));
}

/**
  * @brief    清除ADC 转换序列结束标志

  * @rmtoll   GISR    EOS    FL_ADC_ClearFlag_EndOfSequence
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_EndOfSequence(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->GISR, ADC_GISR_EOS_Msk);
}

/**
  * @brief    使能ADC模拟看门狗低于上限中断
  * @rmtoll   GIER    AWD_AHIE    FL_ADC_EnableIT_AnalogWDGAboveHigh
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_AnalogWDGAboveHigh(ADC_Type *ADCx)
{
    SET_BIT(ADCx->GIER, ADC_GIER_AWD_AHIE_Msk);
}

/**
  * @brief    失能ADC模拟看门狗低于上限中断
  * @rmtoll   GIER    AWD_AHIE    FL_ADC_DisableIT_AnalogWDGAboveHigh
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_AnalogWDGAboveHigh(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->GIER, ADC_GIER_AWD_AHIE_Msk);
}

/**
  * @brief    获取ADC模拟看门狗低于上限中断使能状态
  * @rmtoll   GIER    AWD_AHIE    FL_ADC_IsEnabledIT_AnalogWDGAboveHigh
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_AnalogWDGAboveHigh(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GIER, ADC_GIER_AWD_AHIE_Msk) == ADC_GIER_AWD_AHIE_Msk);
}

/**
  * @brief    使能ADC模拟看门狗低于下限中断
  * @rmtoll   GIER    AWD_ULIE    FL_ADC_EnableIT_AnalogWDGUnderLow
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_AnalogWDGUnderLow(ADC_Type *ADCx)
{
    SET_BIT(ADCx->GIER, ADC_GIER_AWD_ULIE_Msk);
}

/**
  * @brief    失能ADC模拟看门狗低于下限中断
  * @rmtoll   GIER    AWD_ULIE    FL_ADC_DisableIT_AnalogWDGUnderLow
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_AnalogWDGUnderLow(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->GIER, ADC_GIER_AWD_ULIE_Msk);
}

/**
  * @brief    获取ADC模拟看门狗低于下限中断使能状态
  * @rmtoll   GIER    AWD_ULIE    FL_ADC_IsEnabledIT_AnalogWDGUnderLow
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_AnalogWDGUnderLow(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GIER, ADC_GIER_AWD_ULIE_Msk) == ADC_GIER_AWD_ULIE_Msk);
}

/**
  * @brief    使能ADC 连续模式完成中断
  * @rmtoll   GIER    EOCNTIE    FL_ADC_EnableIT_ContinuousModeComplete
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_ContinuousModeComplete(ADC_Type *ADCx)
{
    SET_BIT(ADCx->GIER, ADC_GIER_EOCNTIE_Msk);
}

/**
  * @brief    失能ADC 连续模式完成中断
  * @rmtoll   GIER    EOCNTIE    FL_ADC_DisableIT_ContinuousModeComplete
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_ContinuousModeComplete(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->GIER, ADC_GIER_EOCNTIE_Msk);
}

/**
  * @brief    获取ADC 连续模式完成中断使能状态
  * @rmtoll   GIER    EOCNTIE    FL_ADC_IsEnabledIT_ContinuousModeComplete
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_ContinuousModeComplete(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GIER, ADC_GIER_EOCNTIE_Msk) == ADC_GIER_EOCNTIE_Msk);
}

/**
  * @brief    使能ADC 转换序列完成中断
  * @rmtoll   GIER    EOSIE    FL_ADC_EnableIT_EndOfSequence
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_EndOfSequence(ADC_Type *ADCx)
{
    SET_BIT(ADCx->GIER, ADC_GIER_EOSIE_Msk);
}

/**
  * @brief    失能ADC转换序列完成中断
  * @rmtoll   GIER    EOSIE    FL_ADC_DisableIT_EndOfSequence
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_EndOfSequence(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->GIER, ADC_GIER_EOSIE_Msk);
}

/**
  * @brief    获取ADC转换序列完成中断使能状态
  * @rmtoll   GIER    EOSIE    FL_ADC_IsEnabledIT_EndOfSequence
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_EndOfSequence(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GIER, ADC_GIER_EOSIE_Msk) == ADC_GIER_EOSIE_Msk);
}

/**
  * @brief    使能ACQx
  * @rmtoll   CR1    ACQEN    FL_ADC_EnableACQ
  * @param    ADCx ADC instance
  * @param    acqx_en This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableACQ(ADC_Type *ADCx, uint32_t acqx_en)
{
    SET_BIT(ADCx->CR1, ((acqx_en & 0x1f) << 0x10U));
}

/**
  * @brief    失能ACQx
  * @rmtoll   CR1    ACQEN    FL_ADC_DisableACQ
  * @param    ADCx ADC instance
  * @param    acqx_en This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableACQ(ADC_Type *ADCx, uint32_t acqx_en)
{
    CLEAR_BIT(ADCx->CR1, ((acqx_en & 0x1f) << 0x10U));
}

/**
  * @brief    获取ACQx使能状态
  * @rmtoll   CR1    ACQEN    FL_ADC_IsEnabledACQ
  * @param    ADCx ADC instance
  * @param    acqx_en This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledACQ(ADC_Type *ADCx, uint32_t acqx_en)
{
    return (uint32_t)(READ_BIT(ADCx->CR1, ((acqx_en & 0x1f) << 0x10U)) == ((acqx_en & 0x1f) << 0x10U));
}

/**
  * @brief    使能SCAN_ACQ通道复位
  * @rmtoll   CR1    SCH_SWRST    FL_ADC_EnableScanACQChannelReset
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableScanACQChannelReset(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CR1, ADC_CR1_SCH_SWRST_Msk);
}

/**
  * @brief    使能Round Robin复位
  * @rmtoll   CR1    RR_SWRST    FL_ADC_EnableRoundRobinReset
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableRoundRobinReset(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CR1, ADC_CR1_RR_SWRST_Msk);
}

/**
  * @brief    使能ADC
  * @rmtoll   CR1    ADEN    FL_ADC_Enable
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_Enable(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CR1, ADC_CR1_ADEN_Msk);
}

/**
  * @brief    失能ADC
  * @rmtoll   CR1    ADEN    FL_ADC_Disable
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_Disable(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CR1, ADC_CR1_ADEN_Msk);
}

/**
  * @brief    获取ADC使能状态
  * @rmtoll   CR1    ADEN    FL_ADC_IsEnabled
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabled(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CR1, ADC_CR1_ADEN_Msk) == ADC_CR1_ADEN_Msk);
}

/**
  * @brief    使能ACQx 软件触发转换
  * @rmtoll   CR2    SWTRIG    FL_ADC_EnableACQSWConversion
  * @param    ADCx ADC instance
  * @param    acqx_sw This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableACQSWConversion(ADC_Type *ADCx, uint32_t acqx_sw)
{
    SET_BIT(ADCx->CR2, ((acqx_sw & 0x1f) << 0x0U));
}

/**
  * @brief    设置ADC在连续模式下重复次数
  * @rmtoll   CFGR1    RPTLEN    FL_ADC_SetRepeatLength
  * @param    ADCx ADC instance
  * @param    count 
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetRepeatLength(ADC_Type *ADCx, uint32_t count)
{
    MODIFY_REG(ADCx->CFGR1, (0xffffU << 16U), (count << 16U));
}

/**
  * @brief    读取ADC在连续模式下重复次数
  * @rmtoll   CFGR1    RPTLEN    FL_ADC_GetRepeatLength
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_GetRepeatLength(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    设置ADC开始采样转换边沿配置
  * @rmtoll   CFGR1    SOCIF_CFG    FL_ADC_SetSOCEdgeMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SOC_EDGE_MODE_RISE
  *           @arg @ref FL_ADC_SOC_EDGE_MODE_FALL
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetSOCEdgeMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_SOCIF_CFG_Msk, mode);
}

/**
  * @brief    读取ADC开始采样转换边沿配置
  * @rmtoll   CFGR1    SOCIF_CFG    FL_ADC_GetSOCEdgeMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_SOC_EDGE_MODE_RISE
  *           @arg @ref FL_ADC_SOC_EDGE_MODE_FALL
  */
__STATIC_INLINE uint32_t FL_ADC_GetSOCEdgeMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_SOCIF_CFG_Msk));
}

/**
  * @brief    设置ADC APBCLK分频
  * @rmtoll   CFGR1    PCLK_PSC    FL_ADC_SetAPBPrescaler
  * @param    ADCx ADC instance
  * @param    psc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV1
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV2
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV3
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV4
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV5
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV6
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetAPBPrescaler(ADC_Type *ADCx, uint32_t psc)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_PCLK_PSC_Msk, psc);
}

/**
  * @brief    读取ADC APBCLK分频
  * @rmtoll   CFGR1    PCLK_PSC    FL_ADC_GetAPBPrescaler
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV1
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV2
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV3
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV4
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV5
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV6
  */
__STATIC_INLINE uint32_t FL_ADC_GetAPBPrescaler(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_PCLK_PSC_Msk));
}

/**
  * @brief    设置ADC VCM模式
  * @rmtoll   CFGR1    VCM_CTRL    FL_ADC_SetVCMMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_VCM_MODE_PERIODIC
  *           @arg @ref FL_ADC_VCM_MODE_CONTINUOUS
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetVCMMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_VCM_CTRL_Msk, mode);
}

/**
  * @brief    读取ADC VCM模式
  * @rmtoll   CFGR1    VCM_CTRL    FL_ADC_GetVCMMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_VCM_MODE_PERIODIC
  *           @arg @ref FL_ADC_VCM_MODE_CONTINUOUS
  */
__STATIC_INLINE uint32_t FL_ADC_GetVCMMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_VCM_CTRL_Msk));
}

/**
  * @brief    设置ADC注入模式
  * @rmtoll   CFGR1    INJ_MODE    FL_ADC_SetInjectionMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_INJ_MODE_DELAY
  *           @arg @ref FL_ADC_INJ_MODE_IMMEDIA
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetInjectionMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_INJ_MODE_Msk, mode);
}

/**
  * @brief    读取ADC通道扫描顺序
  * @rmtoll   CFGR1    INJ_MODE    FL_ADC_GetInjectionMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_INJ_MODE_DELAY
  *           @arg @ref FL_ADC_INJ_MODE_IMMEDIA
  */
__STATIC_INLINE uint32_t FL_ADC_GetInjectionMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_INJ_MODE_Msk));
}

/**
  * @brief    设置ADC 负基准
  * @rmtoll   CFGR1    REFNSEL    FL_ADC_SetNegativePeference
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_Negative_Peference_VSSA
  *           @arg @ref FL_ADC_Negative_Peference_VREFN
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetNegativePeference(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_REFNSEL_Msk, mode);
}

/**
  * @brief    读取ADC 负基准
  * @rmtoll   CFGR1    REFNSEL    FL_ADC_GetNegativePeference
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_Negative_Peference_VSSA
  *           @arg @ref FL_ADC_Negative_Peference_VREFN
  */
__STATIC_INLINE uint32_t FL_ADC_GetNegativePeference(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_REFNSEL_Msk));
}

/**
  * @brief    设置ADC基准源
  * @rmtoll   CFGR1    PEFSEL    FL_ADC_SetReferenceSource
  * @param    ADCx ADC instance
  * @param    ref This parameter can be one of the following values:
  *           @arg @ref FL_ADC_REF_SOURCE_VDDA
  *           @arg @ref FL_ADC_REF_SOURCE_VREFP
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetReferenceSource(ADC_Type *ADCx, uint32_t ref)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_PEFSEL_Msk, ref);
}

/**
  * @brief    读取ADC基准源
  * @rmtoll   CFGR1    PEFSEL    FL_ADC_GetReferenceSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_REF_SOURCE_VDDA
  *           @arg @ref FL_ADC_REF_SOURCE_VREFP
  */
__STATIC_INLINE uint32_t FL_ADC_GetReferenceSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_PEFSEL_Msk));
}

/**
  * @brief    设置ADC过采样移位
  * @rmtoll   CFGR2    AVGR_OVSS    FL_ADC_SetOverSamplingShift
  * @param    ADCx ADC instance
  * @param    shift This parameter can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_0B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_1B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_2B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_3B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_4B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_5B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_6B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_7B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_8B
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetOverSamplingShift(ADC_Type *ADCx, uint32_t shift)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_AVGR_OVSS_Msk, shift);
}

/**
  * @brief    读取ADC过采样移位
  * @rmtoll   CFGR2    AVGR_OVSS    FL_ADC_GetOverSamplingShift
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_0B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_1B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_2B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_3B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_4B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_5B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_6B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_7B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_8B
  */
__STATIC_INLINE uint32_t FL_ADC_GetOverSamplingShift(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_AVGR_OVSS_Msk));
}

/**
  * @brief    设置ADC过采样倍数
  * @rmtoll   CFGR2    AVGR_OVSR    FL_ADC_SetOverSamplingMultiplier
  * @param    ADCx ADC instance
  * @param    mul This parameter can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_2X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_4X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_8X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_16X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_32X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_64X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_128X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_256X
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetOverSamplingMultiplier(ADC_Type *ADCx, uint32_t mul)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_AVGR_OVSR_Msk, mul);
}

/**
  * @brief    读取ADC过采样倍数
  * @rmtoll   CFGR2    AVGR_OVSR    FL_ADC_GetOverSamplingMultiplier
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_2X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_4X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_8X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_16X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_32X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_64X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_128X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_256X
  */
__STATIC_INLINE uint32_t FL_ADC_GetOverSamplingMultiplier(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_AVGR_OVSR_Msk));
}

/**
  * @brief    设置ADC过采样倍数
  * @rmtoll   CFGR2    AVGEN    FL_ADC_SetOverSamplingMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_MODE_DISABLE
  *           @arg @ref FL_ADC_OVERSAMPLING_MODE_ENABLE_AVERAGE
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetOverSamplingMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_AVGEN_Msk, mode);
}

/**
  * @brief    读取ADC过采样倍数
  * @rmtoll   CFGR2    AVGEN    FL_ADC_GetOverSamplingMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_MODE_DISABLE
  *           @arg @ref FL_ADC_OVERSAMPLING_MODE_ENABLE_AVERAGE
  */
__STATIC_INLINE uint32_t FL_ADC_GetOverSamplingMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_AVGEN_Msk));
}

/**
  * @brief    使能ADC 等待模式
  * @rmtoll   CFGR2    WAIT_F    FL_ADC_EnableWaitMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableWaitMode(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_WAIT_F_Msk);
}

/**
  * @brief    失能ADC 等待模式
  * @rmtoll   CFGR2    WAIT_F    FL_ADC_DisableWaitMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableWaitMode(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_WAIT_F_Msk);
}

/**
  * @brief    获取ADC 等待模式使能状态
  * @rmtoll   CFGR2    WAIT_F    FL_ADC_IsEnabledWaitMode
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledWaitMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_WAIT_F_Msk) == ADC_CFGR2_WAIT_F_Msk);
}

/**
  * @brief    设置ADC SCAN_ACQ自动转换模式
  * @rmtoll   CFGR2    AUTO_SCAN    FL_ADC_SetScanACQConversionAutoMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_CONV_MODE_SEMIAUTO
  *           @arg @ref FL_ADC_SCANACQ_CONV_MODE_AUTO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetScanACQConversionAutoMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_AUTO_SCAN_Msk, mode);
}

/**
  * @brief    读取ADC SCAN_ACQ自动转换模式
  * @rmtoll   CFGR2    AUTO_SCAN    FL_ADC_GetScanACQConversionAutoMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_CONV_MODE_SEMIAUTO
  *           @arg @ref FL_ADC_SCANACQ_CONV_MODE_AUTO
  */
__STATIC_INLINE uint32_t FL_ADC_GetScanACQConversionAutoMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_AUTO_SCAN_Msk));
}

/**
  * @brief    使能ADC Overrun模式
  * @rmtoll   CFGR2    CONT_MOD    FL_ADC_EnableContinuousMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableContinuousMode(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_CONT_MOD_Msk);
}

/**
  * @brief    失能ADC Overrun模式
  * @rmtoll   CFGR2    CONT_MOD    FL_ADC_DisableContinuousMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableContinuousMode(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_CONT_MOD_Msk);
}

/**
  * @brief    获取ADC Overrun模式使能状态
  * @rmtoll   CFGR2    CONT_MOD    FL_ADC_IsEnabledContinuousMode
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledContinuousMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_CONT_MOD_Msk) == ADC_CFGR2_CONT_MOD_Msk);
}

/**
  * @brief    使能ADC Overrun模式
  * @rmtoll   CFGR2    OVRM    FL_ADC_EnableOverrunMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableOverrunMode(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_OVRM_Msk);
}

/**
  * @brief    失能ADC Overrun模式
  * @rmtoll   CFGR2    OVRM    FL_ADC_DisableOverrunMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableOverrunMode(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_OVRM_Msk);
}

/**
  * @brief    获取ADC Overrun模式使能状态
  * @rmtoll   CFGR2    OVRM    FL_ADC_IsEnabledOverrunMode
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledOverrunMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_OVRM_Msk) == ADC_CFGR2_OVRM_Msk);
}

/**
  * @brief    设置ADC通道扫描顺序
  * @rmtoll   CFGR2    SCANDIR    FL_ADC_SetSequenceScanDirection
  * @param    ADCx ADC instance
  * @param    dir This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_SCAN_DIR_BACKWARD
  *           @arg @ref FL_ADC_SCANACQ_SCAN_DIR_FORWARD
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetSequenceScanDirection(ADC_Type *ADCx, uint32_t dir)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_SCANDIR_Msk, dir);
}

/**
  * @brief    读取ADC通道扫描顺序
  * @rmtoll   CFGR2    SCANDIR    FL_ADC_GetSequenceScanDirection
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_SCAN_DIR_BACKWARD
  *           @arg @ref FL_ADC_SCANACQ_SCAN_DIR_FORWARD
  */
__STATIC_INLINE uint32_t FL_ADC_GetSequenceScanDirection(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_SCANDIR_Msk));
}

/**
  * @brief    使能ADC DMA
  * @rmtoll   CFGR2    DMAEN    FL_ADC_EnableDMAReq
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableDMAReq(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_DMAEN_Msk);
}

/**
  * @brief    失能ADC DMA
  * @rmtoll   CFGR2    DMAEN    FL_ADC_DisableDMAReq
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableDMAReq(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_DMAEN_Msk);
}

/**
  * @brief    获取ADC DMA使能状态
  * @rmtoll   CFGR2    DMAEN    FL_ADC_IsEnabledDMAReq
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledDMAReq(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_DMAEN_Msk) == ADC_CFGR2_DMAEN_Msk);
}

/**
  * @brief    使能ADC校准
  * @rmtoll   OSR    CALEN    FL_ADC_EnableCalibration
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableCalibration(ADC_Type *ADCx)
{
    SET_BIT(ADCx->OSR, ADC_OSR_CALEN_Msk);
}

/**
  * @brief    失能ADC校准
  * @rmtoll   OSR    CALEN    FL_ADC_DisableCalibration
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableCalibration(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->OSR, ADC_OSR_CALEN_Msk);
}

/**
  * @brief    获取ADC校准使能状态
  * @rmtoll   OSR    CALEN    FL_ADC_IsEnabledCalibration
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledCalibration(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->OSR, ADC_OSR_CALEN_Msk) == ADC_OSR_CALEN_Msk);
}

/**
  * @brief    写入通道校准值
  * @rmtoll   OSR    OS_CALI    FL_ADC_WriteChannelCalibration
  * @param    ADCx ADC instance
  * @param    calibration 
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_WriteChannelCalibration(ADC_Type *ADCx, uint32_t calibration)
{
    MODIFY_REG(ADCx->OSR, (0x1fffU << 0U), (calibration << 0U));
}

/**
  * @brief    获取通道校准值
  * @rmtoll   OSR    OS_CALI    FL_ADC_ReadChannelCalibration
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadChannelCalibration(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->OSR, (0x1fffU << 0U)) >> 0U);
}

/**
  * @brief    读取ACQx的Pending 标志

  * @rmtoll   ACQ_SR    REQ    FL_ADC_IsActiveFlag_ACQxPending
  * @param    ADCx ADC instance
  * @param    acqx_pending This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_ACQxPending(ADC_Type *ADCx, uint32_t acqx_pending)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_SR, ((acqx_pending & 0x1f) << 0x0U)) == ((acqx_pending & 0x1f) << 0x0U));
}

/**
  * @brief    使能ADC SCAN 通道
  * @rmtoll   ACQ_SACR        FL_ADC_Enable_SCANACQ_SequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH0
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH1
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH2
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH3
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH4
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH5
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH6
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH7
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH8
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH9
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH10
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH11
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_TS
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_AVREF
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_OPA1
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_OPA2
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFP
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFN
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_Enable_SCANACQ_SequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    SET_BIT(ADCx->ACQ_SACR, ((channel & 0x3ffff) << 0x0U));
}

/**
  * @brief    失能ADC SCAN 通道
  * @rmtoll   ACQ_SACR        FL_ADC_Disable_SCANACQ_SequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH0
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH1
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH2
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH3
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH4
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH5
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH6
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH7
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH8
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH9
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH10
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH11
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_TS
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_AVREF
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_OPA1
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_OPA2
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFP
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFN
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_Disable_SCANACQ_SequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    CLEAR_BIT(ADCx->ACQ_SACR, ((channel & 0x3ffff) << 0x0U));
}

/**
  * @brief    获取ADC SCAN 通道
  * @rmtoll   ACQ_SACR        FL_ADC_IsEnabled_SCANACQ_SequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH0
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH1
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH2
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH3
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH4
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH5
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH6
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH7
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH8
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH9
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH10
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH11
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_TS
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_AVREF
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_OPA1
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_OPA2
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFP
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFN
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabled_SCANACQ_SequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_SACR, ((channel & 0x3ffff) << 0x0U)) == ((channel & 0x3ffff) << 0x0U));
}

/**
  * @brief    写入ADC模拟看门狗上限阈值
  * @rmtoll   HLTR    AWD_HT    FL_ADC_Write_AnalogWDGHighThreshold
  * @param    ADCx ADC instance
  * @param    threshold 
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_Write_AnalogWDGHighThreshold(ADC_Type *ADCx, uint32_t threshold)
{
    MODIFY_REG(ADCx->HLTR, (0xffffU << 16U), (threshold << 16U));
}

/**
  * @brief    读取ADC模拟看门狗上限阈值
  * @rmtoll   HLTR    AWD_HT    FL_ADC_Read_AnalogWDGHighThreshold
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_Read_AnalogWDGHighThreshold(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->HLTR, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    写入ADC模拟看门狗下限阈值
  * @rmtoll   HLTR    AWD_LT    FL_ADC_Write_AnalogWDGLowThreshold
  * @param    ADCx ADC instance
  * @param    threshold 
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_Write_AnalogWDGLowThreshold(ADC_Type *ADCx, uint32_t threshold)
{
    MODIFY_REG(ADCx->HLTR, (0xffffU << 0U), (threshold << 0U));
}

/**
  * @brief    读取ADC模拟看门狗下限阈值
  * @rmtoll   HLTR    AWD_LT    FL_ADC_Read_AnalogWDGLowThreshold
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_Read_AnalogWDGLowThreshold(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->HLTR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    使能ADC ADC模拟看门狗通道
  * @rmtoll   AWDCR        FL_ADC_Enable_AnalogWDGSequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH0
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH1
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH2
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH3
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH4
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH5
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH6
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH7
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH8
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH9
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH10
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH11
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_TS
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_AVREF
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_OPA1
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_OPA2
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFP
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFN
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_Enable_AnalogWDGSequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    SET_BIT(ADCx->AWDCR, ((channel & 0x3ffff) << 0x0U));
}

/**
  * @brief    失能ADC ADC模拟看门狗通道
  * @rmtoll   AWDCR        FL_ADC_Disable_AnalogWDGSequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH0
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH1
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH2
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH3
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH4
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH5
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH6
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH7
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH8
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH9
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH10
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH11
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_TS
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_AVREF
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_OPA1
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_OPA2
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFP
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFN
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_Disable_AnalogWDGSequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    CLEAR_BIT(ADCx->AWDCR, ((channel & 0x3ffff) << 0x0U));
}

/**
  * @brief    获取ADC ADC模拟看门狗通道
  * @rmtoll   AWDCR        FL_ADC_IsEnabled_AnalogWDGSequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH0
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH1
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH2
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH3
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH4
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH5
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH6
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH7
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH8
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH9
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH10
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH11
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_TS
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_AVREF
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_OPA1
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_OPA2
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFP
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFN
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabled_AnalogWDGSequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(ADCx->AWDCR, ((channel & 0x3ffff) << 0x0U)) == ((channel & 0x3ffff) << 0x0U));
}

/**
  * @brief    设置ACQ0通道
  * @rmtoll   ACQ0_CR    CHSEL    FL_ADC_SetACQ0ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH0
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH3
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH4
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH5
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH6
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH7
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH8
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH9
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH10
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH11
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TS
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_AVREF
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_OPA1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_OPA2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ0ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ0_CR, ADC_ACQ0_CR_CHSEL_Msk, channel);
}

/**
  * @brief    读取ACQ0通道
  * @rmtoll   ACQ0_CR    CHSEL    FL_ADC_GetACQ0ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH0
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH3
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH4
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH5
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH6
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH7
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH8
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH9
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH10
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH11
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TS
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_AVREF
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_OPA1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_OPA2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ0ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ0_CR, ADC_ACQ0_CR_CHSEL_Msk));
}

/**
  * @brief    设置ACQ0触发源
  * @rmtoll   ACQ0_CR    TRIGSEL    FL_ADC_SetACQ0TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_TRGI_SOFE_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT0_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT3_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO2
  *           @arg @ref FL_ADC_ACQ_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP3_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP4_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LPTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_BSTIM_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ0TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ0_CR, ADC_ACQ0_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    读取ACQ0触发源
  * @rmtoll   ACQ0_CR    TRIGSEL    FL_ADC_GetACQ0TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_TRGI_SOFE_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT0_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT3_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO2
  *           @arg @ref FL_ADC_ACQ_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP3_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP4_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LPTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_BSTIM_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ0TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ0_CR, ADC_ACQ0_CR_TRIGSEL_Msk));
}

/**
  * @brief    设置ACQ0采样时间
  * @rmtoll   ACQ0_CR    SMTS    FL_ADC_SetACQ0SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ0SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ0_CR, ADC_ACQ0_CR_SMTS_Msk, time);
}

/**
  * @brief    读取ACQ0采样时间
  * @rmtoll   ACQ0_CR    SMTS    FL_ADC_GeACQ0SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ0SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ0_CR, ADC_ACQ0_CR_SMTS_Msk));
}

/**
  * @brief    设置ACQ1通道
  * @rmtoll   ACQ1_CR    CHSEL    FL_ADC_SetACQ1ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH0
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH3
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH4
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH5
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH6
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH7
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH8
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH9
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH10
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH11
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TS
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_AVREF
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_OPA1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_OPA2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ1ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ1_CR, ADC_ACQ1_CR_CHSEL_Msk, channel);
}

/**
  * @brief    读取ACQ1通道
  * @rmtoll   ACQ1_CR    CHSEL    FL_ADC_GetACQ1ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH0
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH3
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH4
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH5
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH6
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH7
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH8
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH9
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH10
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH11
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TS
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_AVREF
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_OPA1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_OPA2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ1ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ1_CR, ADC_ACQ1_CR_CHSEL_Msk));
}

/**
  * @brief    设置ACQ1触发源
  * @rmtoll   ACQ1_CR    TRIGSEL    FL_ADC_SetACQ1TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_TRGI_SOFE_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT0_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT3_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO2
  *           @arg @ref FL_ADC_ACQ_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP3_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP4_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LPTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_BSTIM_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ1TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ1_CR, ADC_ACQ1_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    读取ACQ1触发源
  * @rmtoll   ACQ1_CR    TRIGSEL    FL_ADC_GetACQ1TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_TRGI_SOFE_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT0_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT3_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO2
  *           @arg @ref FL_ADC_ACQ_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP3_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP4_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LPTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_BSTIM_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ1TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ1_CR, ADC_ACQ1_CR_TRIGSEL_Msk));
}

/**
  * @brief    设置ACQ1采样时间
  * @rmtoll   ACQ1_CR    SMTS    FL_ADC_SetACQ1SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ1SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ1_CR, ADC_ACQ1_CR_SMTS_Msk, time);
}

/**
  * @brief    读取ACQ1采样时间
  * @rmtoll   ACQ1_CR    SMTS    FL_ADC_GeACQ1SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ1SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ1_CR, ADC_ACQ1_CR_SMTS_Msk));
}

/**
  * @brief    设置ACQ2通道
  * @rmtoll   ACQ2_CR    CHSEL    FL_ADC_SetACQ2ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH0
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH3
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH4
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH5
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH6
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH7
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH8
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH9
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH10
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH11
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TS
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_AVREF
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_OPA1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_OPA2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ2ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ2_CR, ADC_ACQ2_CR_CHSEL_Msk, channel);
}

/**
  * @brief    读取ACQ2通道
  * @rmtoll   ACQ2_CR    CHSEL    FL_ADC_GetACQ2ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH0
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH3
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH4
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH5
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH6
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH7
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH8
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH9
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH10
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH11
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TS
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_AVREF
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_OPA1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_OPA2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ2ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ2_CR, ADC_ACQ2_CR_CHSEL_Msk));
}

/**
  * @brief    设置ACQ2触发源
  * @rmtoll   ACQ2_CR    TRIGSEL    FL_ADC_SetACQ2TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_TRGI_SOFE_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT0_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT3_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO2
  *           @arg @ref FL_ADC_ACQ_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP3_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP4_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LPTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_BSTIM_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ2TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ2_CR, ADC_ACQ2_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    读取ACQ2触发源
  * @rmtoll   ACQ2_CR    TRIGSEL    FL_ADC_GetACQ2TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_TRGI_SOFE_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT0_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT3_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO2
  *           @arg @ref FL_ADC_ACQ_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP3_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP4_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LPTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_BSTIM_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ2TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ2_CR, ADC_ACQ2_CR_TRIGSEL_Msk));
}

/**
  * @brief    设置ACQ2采样时间
  * @rmtoll   ACQ2_CR    SMTS    FL_ADC_SetACQ2SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ2SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ2_CR, ADC_ACQ2_CR_SMTS_Msk, time);
}

/**
  * @brief    读取ACQ2采样时间
  * @rmtoll   ACQ2_CR    SMTS    FL_ADC_GeACQ2SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ2SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ2_CR, ADC_ACQ2_CR_SMTS_Msk));
}

/**
  * @brief    设置ACQ3通道
  * @rmtoll   ACQ3_CR    CHSEL    FL_ADC_SetACQ3ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH0
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH3
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH4
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH5
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH6
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH7
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH8
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH9
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH10
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH11
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TS
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_AVREF
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_OPA1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_OPA2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ3ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ3_CR, ADC_ACQ3_CR_CHSEL_Msk, channel);
}

/**
  * @brief    读取ACQ3通道
  * @rmtoll   ACQ3_CR    CHSEL    FL_ADC_GetACQ3ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH0
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH3
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH4
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH5
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH6
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH7
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH8
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH9
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH10
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH11
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TS
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_AVREF
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_OPA1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_OPA2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ3ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ3_CR, ADC_ACQ3_CR_CHSEL_Msk));
}

/**
  * @brief    设置ACQ3触发源
  * @rmtoll   ACQ3_CR    TRIGSEL    FL_ADC_SetACQ3TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_TRGI_SOFE_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT0_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT3_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO2
  *           @arg @ref FL_ADC_ACQ_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP3_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP4_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LPTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_BSTIM_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ3TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ3_CR, ADC_ACQ3_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    读取ACQ3触发源
  * @rmtoll   ACQ3_CR    TRIGSEL    FL_ADC_GetACQ3TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_TRGI_SOFE_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT0_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LUT3_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO2
  *           @arg @ref FL_ADC_ACQ_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP3_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP4_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LPTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_BSTIM_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ3TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ3_CR, ADC_ACQ3_CR_TRIGSEL_Msk));
}

/**
  * @brief    设置ACQ3采样时间
  * @rmtoll   ACQ3_CR    SMTS    FL_ADC_SetACQ3SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ3SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ3_CR, ADC_ACQ3_CR_SMTS_Msk, time);
}

/**
  * @brief    读取ACQ3采样时间
  * @rmtoll   ACQ3_CR    SMTS    FL_ADC_GeACQ3SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ3SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ3_CR, ADC_ACQ3_CR_SMTS_Msk));
}

/**
  * @brief    设置SCAN ACQ触发源
  * @rmtoll   SCANACQ_CR    TRIGSEL    FL_ADC_SetSCANACQTriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_TRGI_SOFE_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_LUT0_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_LUT1_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_LUT2_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_LUT3_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_ATIM_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_ATIM_TRGO2
  *           @arg @ref FL_ADC_SCANACQ_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_COMP3_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_COMP4_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_LPTIM_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_BSTIM_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetSCANACQTriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->SCANACQ_CR, ADC_SCANACQ_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    读取SCAN ACQ触发源
  * @rmtoll   SCANACQ_CR    TRIGSEL    FL_ADC_GetSCANACQTriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_TRGI_SOFE_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_LUT0_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_LUT1_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_LUT2_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_LUT3_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_ATIM_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_ATIM_TRGO2
  *           @arg @ref FL_ADC_SCANACQ_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_COMP3_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_COMP4_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_LPTIM_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_BSTIM_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetSCANACQTriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->SCANACQ_CR, ADC_SCANACQ_CR_TRIGSEL_Msk));
}

/**
  * @brief    设置SCAN ACQ采样时间
  * @rmtoll   SCANACQ_CR    SMTS    FL_ADC_SetSCANACQSamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetSCANACQSamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->SCANACQ_CR, ADC_SCANACQ_CR_SMTS_Msk, time);
}

/**
  * @brief    读取SCAN ACQ采样时间
  * @rmtoll   SCANACQ_CR    SMTS    FL_ADC_GeSCANACQSamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeSCANACQSamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->SCANACQ_CR, ADC_SCANACQ_CR_SMTS_Msk));
}

/**
  * @brief    获取ACQ0转换数据
  * @rmtoll   ACQ0_DR    RESULT    FL_ADC_ReadACQ0ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadACQ0ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ0_DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    获取ACQ1转换数据
  * @rmtoll   ACQ1_DR    RESULT    FL_ADC_ReadACQ1ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadACQ1ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ1_DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    获取ACQ2转换数据
  * @rmtoll   ACQ2_DR    RESULT    FL_ADC_ReadACQ2ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadACQ2ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ2_DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    获取ACQ3转换数据
  * @rmtoll   ACQ3_DR    RESULT    FL_ADC_ReadACQ3ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadACQ3ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ3_DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    获取ACQ4转换数据
  * @rmtoll   SCANACQ_DR    RESULT    FL_ADC_ReadSCANACQConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadSCANACQConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->SCANACQ_DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    获取SCAN_ACQ 通道ID
  * @rmtoll   SCANACQ_DR    CHID    FL_ADC_ReadSCANChannelID
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadSCANChannelID(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->SCANACQ_DR, (0x1fU << 16U)) >> 16U);
}

/**
  * @}
  */

/** @defgroup ADC_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_ADC_CommonDeInit(void);
FL_ErrorStatus FL_ADC_CommonInit(FL_ADC_CommonInitTypeDef *ADC_CommonInitStruct);
void FL_ADC_CommonStructInit(FL_ADC_CommonInitTypeDef *ADC_CommonInitStruct);
FL_ErrorStatus  FL_ADC_DeInit(ADC_Type *ADCx);
FL_ErrorStatus FL_ADC_Init(ADC_Type *ADCx, FL_ADC_InitTypeDef  *ADC_InitStruct,uint32_t ACQx_ID);
void FL_ADC_StructInit(FL_ADC_InitTypeDef *ADC_InitStruct);


/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LF0XX_FL_ADC_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-06-25*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
