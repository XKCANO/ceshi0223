 /**   
  *******************************************************************************************************
  * @file    fm33lf0xx_fl_fscan.h
  * @author  FMSH Application Team
  * @brief   Head file of FSCAN FL Module 
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

/* Define to prevent recursive inclusion---------------------------------------------------------------*/
#ifndef __FM33LF0XX_FL_FSCAN_H
#define __FM33LF0XX_FL_FSCAN_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33lf0xx_fl_def.h"
/** @addtogroup FM33LF0XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup FSCAN_FL_ES_INIT FSCAN Exported Init structures
  * @{
  */

/**
  * @brief FL FSCAN Init Sturcture definition
  */
typedef struct
{
    /*工作模式*/
    uint8_t mode;
    /*同步段长度*/
    uint8_t SJW;
    /*时间段1*/
    uint8_t TS1;
    /*时间段2*/
    uint8_t TS2;
    /*波特率预分频*/
    uint32_t BRP;
    /*时钟源选择*/
    uint32_t clockSource;
    /*发送优先级选择*/
    uint32_t TXPriority;
    /*唤醒使能*/
    FL_FunState wakeup;
    /*自动总线管理*/
    uint32_t ABOM;
    /*自动重发使能*/
    FL_FunState AREN;
} FL_FSCAN_InitTypeDef;
/**
  * @brief  FSCAN filter init structure definition
  */
typedef struct
{

    /*滤波器SRR位*/
    uint32_t filterIdSRR;
    /*滤波器IDE位*/
    uint32_t filterIdIDE;
    /*滤波器RTR位*/
    uint32_t filterIdRTR;
    /*滤波器标准ID*/
    uint32_t filterIdStandard;
    /*滤波器扩展ID*/
    uint32_t filterIdExtend;

    /*16位滤波器1IDE位*/
    uint32_t filterSTD1IdIDE;
    /*16位滤波器1SRR位*/
    uint32_t filterSTD1IdSRR;
    /*16位滤波器1标准ID*/
    uint32_t filterSTD1IdStandard;
    /*16位滤波器1扩展ID*/
    uint32_t filterSTD1IdExtend;

    /*16位滤波器2IDE位*/
    uint32_t filterSTD2IdIDE;
    /*16位滤波器2SRR位*/
    uint32_t filterSTD2IdSRR;
    /*16位滤波器2标准ID*/
    uint32_t filterSTD2IdStandard;
    /*16位滤波器2扩展ID*/
    uint32_t filterSTD2IdExtend;

    /*滤波器ID高11位掩码*/
    uint32_t filterMaskIdStandard;
    /*滤波器SRR位掩码*/
    FL_FunState filterMaskIdSRR;
    /*滤波器IDE位掩码*/
    FL_FunState filterMaskIdIDE;
    /*滤波器ID低18位掩码*/
    uint32_t filterMaskIdExtend;
    /*滤波器RTR位掩码*/
    FL_FunState filterMaskIdRTR;

    /*16位滤波器1ID高11位掩码*/
    uint32_t filterSTD1MaskIdStandard;
    /*16位滤波器1IDE位掩码*/
    FL_FunState filterSTD1MaskIdIDE;
    /*16位滤波器1ID低18位掩码*/
    uint32_t filterSTD1MaskIdExtend;
    /*16位滤波器1SRR位掩码*/
    FL_FunState filterSTD1MaskIdSRR;

    /*16位滤波器2ID高11位掩码*/
    uint32_t filterSTD2MaskIdStandard;
    /*16位滤波器2IDE位掩码*/
    FL_FunState filterSTD2MaskIdIDE;
    /*16位滤波器2ID低18位掩码*/
    uint32_t filterSTD2MaskIdExtend;
    /*16位滤波器2SRR位掩码*/
    FL_FunState filterSTD2MaskIdSRR;

    /*滤波器RTR位掩码*/
    uint32_t filterMaskMode;
    /*滤波器RTR位掩码*/
    uint32_t filterIDMode;
    /*滤波器使能*/
    FL_FunState  filterEn;
} FL_FSCAN_FilterInitTypeDef;

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup FSCAN_FL_Exported_Constants FSCAN Exported Constants
  * @{
  */

#define    FSCAN_CR_CEN_Pos                                         (1U)
#define    FSCAN_CR_CEN_Msk                                         (0x1U << FSCAN_CR_CEN_Pos)
#define    FSCAN_CR_CEN                                             FSCAN_CR_CEN_Msk

#define    FSCAN_CR_SRST_Pos                                        (0U)
#define    FSCAN_CR_SRST_Msk                                        (0x1U << FSCAN_CR_SRST_Pos)
#define    FSCAN_CR_SRST                                            FSCAN_CR_SRST_Msk

#define    FSCAN_MSR_RX_PRESYNC_EN_Pos                              (13U)
#define    FSCAN_MSR_RX_PRESYNC_EN_Msk                              (0x1U << FSCAN_MSR_RX_PRESYNC_EN_Pos)
#define    FSCAN_MSR_RX_PRESYNC_EN                                  FSCAN_MSR_RX_PRESYNC_EN_Msk

#define    FSCAN_MSR_TPRI_Pos                                       (12U)
#define    FSCAN_MSR_TPRI_Msk                                       (0x1U << FSCAN_MSR_TPRI_Pos)
#define    FSCAN_MSR_TPRI                                           FSCAN_MSR_TPRI_Msk

#define    FSCAN_MSR_WUPE_Pos                                       (11U)
#define    FSCAN_MSR_WUPE_Msk                                       (0x1U << FSCAN_MSR_WUPE_Pos)
#define    FSCAN_MSR_WUPE                                           FSCAN_MSR_WUPE_Msk

#define    FSCAN_MSR_AREN_Pos                                       (10U)
#define    FSCAN_MSR_AREN_Msk                                       (0x1U << FSCAN_MSR_AREN_Pos)
#define    FSCAN_MSR_AREN                                           FSCAN_MSR_AREN_Msk

#define    FSCAN_MSR_ABOM_Pos                                       (8U)
#define    FSCAN_MSR_ABOM_Msk                                       (0x3U << FSCAN_MSR_ABOM_Pos)
#define    FSCAN_MSR_ABOM                                           FSCAN_MSR_ABOM_Msk

#define    FSCAN_MSR_RTBO_Pos                                       (7U)
#define    FSCAN_MSR_RTBO_Msk                                       (0x1U << FSCAN_MSR_RTBO_Pos)
#define    FSCAN_MSR_RTBO                                           FSCAN_MSR_RTBO_Msk

#define    FSCAN_MSR_LPBACK_Pos                                     (1U)
#define    FSCAN_MSR_LPBACK_Msk                                     (0x1U << FSCAN_MSR_LPBACK_Pos)
#define    FSCAN_MSR_LPBACK                                         FSCAN_MSR_LPBACK_Msk

#define    FSCAN_MSR_SLEEP_Pos                                      (0U)
#define    FSCAN_MSR_SLEEP_Msk                                      (0x1U << FSCAN_MSR_SLEEP_Pos)
#define    FSCAN_MSR_SLEEP                                          FSCAN_MSR_SLEEP_Msk

#define    FSCAN_BRPR_BRP_Pos                                       (0U)
#define    FSCAN_BRPR_BRP_Msk                                       (0xffU << FSCAN_BRPR_BRP_Pos)
#define    FSCAN_BRPR_BRP                                           FSCAN_BRPR_BRP_Msk

#define    FSCAN_BTR_SJW_Pos                                        (7U)
#define    FSCAN_BTR_SJW_Msk                                        (0x3U << FSCAN_BTR_SJW_Pos)
#define    FSCAN_BTR_SJW                                            FSCAN_BTR_SJW_Msk

#define    FSCAN_BTR_TS2_Pos                                        (4U)
#define    FSCAN_BTR_TS2_Msk                                        (0x7U << FSCAN_BTR_TS2_Pos)
#define    FSCAN_BTR_TS2                                            FSCAN_BTR_TS2_Msk

#define    FSCAN_BTR_TS1_Pos                                        (0U)
#define    FSCAN_BTR_TS1_Msk                                        (0xfU << FSCAN_BTR_TS1_Pos)
#define    FSCAN_BTR_TS1                                            FSCAN_BTR_TS1_Msk

#define    FSCAN_ECR_REC_Pos                                        (8U)
#define    FSCAN_ECR_REC_Msk                                        (0xffU << FSCAN_ECR_REC_Pos)
#define    FSCAN_ECR_REC                                            FSCAN_ECR_REC_Msk

#define    FSCAN_ECR_TEC_Pos                                        (0U)
#define    FSCAN_ECR_TEC_Msk                                        (0xffU << FSCAN_ECR_TEC_Pos)
#define    FSCAN_ECR_TEC                                            FSCAN_ECR_TEC_Msk

#define    FSCAN_ESR_OVLF_Pos                                       (8U)
#define    FSCAN_ESR_OVLF_Msk                                       (0x1U << FSCAN_ESR_OVLF_Pos)
#define    FSCAN_ESR_OVLF                                           FSCAN_ESR_OVLF_Msk

#define    FSCAN_ESR_BLF_Pos                                        (7U)
#define    FSCAN_ESR_BLF_Msk                                        (0x1U << FSCAN_ESR_BLF_Pos)
#define    FSCAN_ESR_BLF                                            FSCAN_ESR_BLF_Msk

#define    FSCAN_ESR_ADERR_Pos                                      (6U)
#define    FSCAN_ESR_ADERR_Msk                                      (0x1U << FSCAN_ESR_ADERR_Pos)
#define    FSCAN_ESR_ADERR                                          FSCAN_ESR_ADERR_Msk

#define    FSCAN_ESR_ACKER_Pos                                      (5U)
#define    FSCAN_ESR_ACKER_Msk                                      (0x1U << FSCAN_ESR_ACKER_Pos)
#define    FSCAN_ESR_ACKER                                          FSCAN_ESR_ACKER_Msk

#define    FSCAN_ESR_B0ERR_Pos                                      (4U)
#define    FSCAN_ESR_B0ERR_Msk                                      (0x1U << FSCAN_ESR_B0ERR_Pos)
#define    FSCAN_ESR_B0ERR                                          FSCAN_ESR_B0ERR_Msk

#define    FSCAN_ESR_B1ERR_Pos                                      (3U)
#define    FSCAN_ESR_B1ERR_Msk                                      (0x1U << FSCAN_ESR_B1ERR_Pos)
#define    FSCAN_ESR_B1ERR                                          FSCAN_ESR_B1ERR_Msk

#define    FSCAN_ESR_STER_Pos                                       (2U)
#define    FSCAN_ESR_STER_Msk                                       (0x1U << FSCAN_ESR_STER_Pos)
#define    FSCAN_ESR_STER                                           FSCAN_ESR_STER_Msk

#define    FSCAN_ESR_FMER_Pos                                       (1U)
#define    FSCAN_ESR_FMER_Msk                                       (0x1U << FSCAN_ESR_FMER_Pos)
#define    FSCAN_ESR_FMER                                           FSCAN_ESR_FMER_Msk

#define    FSCAN_ESR_CRCER_Pos                                      (0U)
#define    FSCAN_ESR_CRCER_Msk                                      (0x1U << FSCAN_ESR_CRCER_Pos)
#define    FSCAN_ESR_CRCER                                          FSCAN_ESR_CRCER_Msk

#define    FSCAN_SR_ACFBSY_Pos                                      (11U)
#define    FSCAN_SR_ACFBSY_Msk                                      (0x1U << FSCAN_SR_ACFBSY_Pos)
#define    FSCAN_SR_ACFBSY                                          FSCAN_SR_ACFBSY_Msk

#define    FSCAN_SR_RXFE_Pos                                        (10U)
#define    FSCAN_SR_RXFE_Msk                                        (0x1U << FSCAN_SR_RXFE_Pos)
#define    FSCAN_SR_RXFE                                            FSCAN_SR_RXFE_Msk

#define    FSCAN_SR_RSTS_Pos                                        (8U)
#define    FSCAN_SR_RSTS_Msk                                        (0x3U << FSCAN_SR_RSTS_Pos)
#define    FSCAN_SR_RSTS                                            FSCAN_SR_RSTS_Msk

#define    FSCAN_SR_TSTS_Pos                                        (6U)
#define    FSCAN_SR_TSTS_Msk                                        (0x3U << FSCAN_SR_TSTS_Pos)
#define    FSCAN_SR_TSTS                                            FSCAN_SR_TSTS_Msk

#define    FSCAN_SR_BBSY_Pos                                        (5U)
#define    FSCAN_SR_BBSY_Msk                                        (0x1U << FSCAN_SR_BBSY_Pos)
#define    FSCAN_SR_BBSY                                            FSCAN_SR_BBSY_Msk

#define    FSCAN_SR_BIDLE_Pos                                       (4U)
#define    FSCAN_SR_BIDLE_Msk                                       (0x1U << FSCAN_SR_BIDLE_Pos)
#define    FSCAN_SR_BIDLE                                           FSCAN_SR_BIDLE_Msk

#define    FSCAN_SR_NORMAL_Pos                                      (3U)
#define    FSCAN_SR_NORMAL_Msk                                      (0x1U << FSCAN_SR_NORMAL_Pos)
#define    FSCAN_SR_NORMAL                                          FSCAN_SR_NORMAL_Msk

#define    FSCAN_SR_SLEEP_Pos                                       (2U)
#define    FSCAN_SR_SLEEP_Msk                                       (0x1U << FSCAN_SR_SLEEP_Pos)
#define    FSCAN_SR_SLEEP                                           FSCAN_SR_SLEEP_Msk

#define    FSCAN_SR_LBACK_Pos                                       (1U)
#define    FSCAN_SR_LBACK_Msk                                       (0x1U << FSCAN_SR_LBACK_Pos)
#define    FSCAN_SR_LBACK                                           FSCAN_SR_LBACK_Msk

#define    FSCAN_SR_CONFIG_Pos                                      (0U)
#define    FSCAN_SR_CONFIG_Msk                                      (0x1U << FSCAN_SR_CONFIG_Pos)
#define    FSCAN_SR_CONFIG                                          FSCAN_SR_CONFIG_Msk

#define    FSCAN_RXISR_RXFIFO_MC_Pos                               (16U)
#define    FSCAN_RXISR_RXFIFO_MC_Msk                               (0xfU << FSCAN_RXISR_RXFIFO_MC_Pos)
#define    FSCAN_RXISR_RXFIFO_MC                                   FSCAN_RXISR_RXFIFO_MC_Msk

#define    FSCAN_RXISR_BORF_Pos                                    (12U)
#define    FSCAN_RXISR_BORF_Msk                                    (0x1U << FSCAN_RXISR_BORF_Pos)
#define    FSCAN_RXISR_BORF                                        FSCAN_RXISR_BORF_Msk

#define    FSCAN_RXISR_WUPF_Pos                                    (11U)
#define    FSCAN_RXISR_WUPF_Msk                                    (0x1U << FSCAN_RXISR_WUPF_Pos)
#define    FSCAN_RXISR_WUPF                                        FSCAN_RXISR_WUPF_Msk

#define    FSCAN_RXISR_SLPIF_Pos                                   (10U)
#define    FSCAN_RXISR_SLPIF_Msk                                   (0x1U << FSCAN_RXISR_SLPIF_Pos)
#define    FSCAN_RXISR_SLPIF                                       FSCAN_RXISR_SLPIF_Msk

#define    FSCAN_RXISR_ESCF_Pos                                    (9U)
#define    FSCAN_RXISR_ESCF_Msk                                    (0x1U << FSCAN_RXISR_ESCF_Pos)
#define    FSCAN_RXISR_ESCF                                        FSCAN_RXISR_ESCF_Msk

#define    FSCAN_RXISR_ERROR_Pos                                   (8U)
#define    FSCAN_RXISR_ERROR_Msk                                   (0x1U << FSCAN_RXISR_ERROR_Pos)
#define    FSCAN_RXISR_ERROR                                       FSCAN_RXISR_ERROR_Msk

#define    FSCAN_RXISR_RXNEMP_Pos                                  (7U)
#define    FSCAN_RXISR_RXNEMP_Msk                                  (0x1U << FSCAN_RXISR_RXNEMP_Pos)
#define    FSCAN_RXISR_RXNEMP                                      FSCAN_RXISR_RXNEMP_Msk

#define    FSCAN_RXISR_RXOFLW_Pos                                  (6U)
#define    FSCAN_RXISR_RXOFLW_Msk                                  (0x1U << FSCAN_RXISR_RXOFLW_Pos)
#define    FSCAN_RXISR_RXOFLW                                      FSCAN_RXISR_RXOFLW_Msk

#define    FSCAN_RXISR_RXUFLW_Pos                                  (5U)
#define    FSCAN_RXISR_RXUFLW_Msk                                  (0x1U << FSCAN_RXISR_RXUFLW_Pos)
#define    FSCAN_RXISR_RXUFLW                                      FSCAN_RXISR_RXUFLW_Msk

#define    FSCAN_RXISR_RXOK_Pos                                    (4U)
#define    FSCAN_RXISR_RXOK_Msk                                    (0x1U << FSCAN_RXISR_RXOK_Pos)
#define    FSCAN_RXISR_RXOK                                        FSCAN_RXISR_RXOK_Msk

#define    FSCAN_RXISR_ARBLST_Pos                                  (0U)
#define    FSCAN_RXISR_ARBLST_Msk                                  (0x1U << FSCAN_RXISR_ARBLST_Pos)
#define    FSCAN_RXISR_ARBLST                                      FSCAN_RXISR_ARBLST_Msk

#define    FSCAN_RXIER_BORFIE_Pos                                  (12U)
#define    FSCAN_RXIER_BORFIE_Msk                                  (0x1U << FSCAN_RXIER_BORFIE_Pos)
#define    FSCAN_RXIER_BORFIE                                      FSCAN_RXIER_BORFIE_Msk

#define    FSCAN_RXIER_WKUPIE_Pos                                  (11U)
#define    FSCAN_RXIER_WKUPIE_Msk                                  (0x1U << FSCAN_RXIER_WKUPIE_Pos)
#define    FSCAN_RXIER_WKUPIE                                      FSCAN_RXIER_WKUPIE_Msk

#define    FSCAN_RXIER_SLPIE_Pos                                   (10U)
#define    FSCAN_RXIER_SLPIE_Msk                                   (0x1U << FSCAN_RXIER_SLPIE_Pos)
#define    FSCAN_RXIER_SLPIE                                       FSCAN_RXIER_SLPIE_Msk

#define    FSCAN_RXIER_EESCFIE_Pos                                 (9U)
#define    FSCAN_RXIER_EESCFIE_Msk                                 (0x1U << FSCAN_RXIER_EESCFIE_Pos)
#define    FSCAN_RXIER_EESCFIE                                     FSCAN_RXIER_EESCFIE_Msk

#define    FSCAN_RXIER_ERRORIE_Pos                                 (8U)
#define    FSCAN_RXIER_ERRORIE_Msk                                 (0x1U << FSCAN_RXIER_ERRORIE_Pos)
#define    FSCAN_RXIER_ERRORIE                                     FSCAN_RXIER_ERRORIE_Msk

#define    FSCAN_RXIER_RXNEMPIE_Pos                                (7U)
#define    FSCAN_RXIER_RXNEMPIE_Msk                                (0x1U << FSCAN_RXIER_RXNEMPIE_Pos)
#define    FSCAN_RXIER_RXNEMPIE                                    FSCAN_RXIER_RXNEMPIE_Msk

#define    FSCAN_RXIER_RXOFLWIE_Pos                                (6U)
#define    FSCAN_RXIER_RXOFLWIE_Msk                                (0x1U << FSCAN_RXIER_RXOFLWIE_Pos)
#define    FSCAN_RXIER_RXOFLWIE                                    FSCAN_RXIER_RXOFLWIE_Msk

#define    FSCAN_RXIER_RXUFLWIE_Pos                                (5U)
#define    FSCAN_RXIER_RXUFLWIE_Msk                                (0x1U << FSCAN_RXIER_RXUFLWIE_Pos)
#define    FSCAN_RXIER_RXUFLWIE                                    FSCAN_RXIER_RXUFLWIE_Msk

#define    FSCAN_RXIER_RXOKIE_Pos                                  (4U)
#define    FSCAN_RXIER_RXOKIE_Msk                                  (0x1U << FSCAN_RXIER_RXOKIE_Pos)
#define    FSCAN_RXIER_RXOKIE                                      FSCAN_RXIER_RXOKIE_Msk

#define    FSCAN_RXIER_ARBLSTIE_Pos                                (0U)
#define    FSCAN_RXIER_ARBLSTIE_Msk                                (0x1U << FSCAN_RXIER_ARBLSTIE_Pos)
#define    FSCAN_RXIER_ARBLSTIE                                    FSCAN_RXIER_ARBLSTIE_Msk

#define    FSCAN_TXBCR_TXAR_Pos                                     (8U)
#define    FSCAN_TXBCR_TXAR_Msk                                     (0x7U << FSCAN_TXBCR_TXAR_Pos)
#define    FSCAN_TXBCR_TXAR                                         FSCAN_TXBCR_TXAR_Msk

#define    FSCAN_TXBCR_TXIE_Pos                                     (0U)
#define    FSCAN_TXBCR_TXIE_Msk                                     (0x7U << FSCAN_TXBCR_TXIE_Pos)
#define    FSCAN_TXBCR_TXIE                                         FSCAN_TXBCR_TXIE_Msk

#define    FSCAN_TXBSR_TXRF_Pos                                     (8U)
#define    FSCAN_TXBSR_TXRF_Msk                                     (0x3U << FSCAN_TXBSR_TXRF_Pos)
#define    FSCAN_TXBSR_TXRF                                         FSCAN_TXBSR_TXRF_Msk

#define    FSCAN_TXBSR_TXS_Pos                                      (3U)
#define    FSCAN_TXBSR_TXS_Msk                                      (0x7U << FSCAN_TXBSR_TXS_Pos)
#define    FSCAN_TXBSR_TXS                                          FSCAN_TXBSR_TXS_Msk

#define    FSCAN_TXBSR_TXE0_Pos                                      (0U)
#define    FSCAN_TXBSR_TXE0_Msk                                      (0x1U << FSCAN_TXBSR_TXE0_Pos)
#define    FSCAN_TXBSR_TXE0                                          FSCAN_TXBSR_TXE0_Msk

#define    FSCAN_TXBSR_TXE1_Pos                                      (1U)
#define    FSCAN_TXBSR_TXE1_Msk                                      (0x1U << FSCAN_TXBSR_TXE1_Pos)
#define    FSCAN_TXBSR_TXE1                                          FSCAN_TXBSR_TXE1_Msk

#define    FSCAN_TXBSR_TXE2_Pos                                      (2U)
#define    FSCAN_TXBSR_TXE2_Msk                                      (0x1U << FSCAN_TXBSR_TXE2_Pos)
#define    FSCAN_TXBSR_TXE2                                          FSCAN_TXBSR_TXE2_Msk


#define    FSCAN_TXBIDR_IDR_Pos                                     (0U)
#define    FSCAN_TXBIDR_IDR_Msk                                     (0xffffffffU << FSCAN_TXBIDR_IDR_Pos)
#define    FSCAN_TXBIDR_IDR                                         FSCAN_TXBIDR_IDR_Msk

#define    FSCAN_TXBDLCR_DLC_Pos                                    (0U)
#define    FSCAN_TXBDLCR_DLC_Msk                                    (0xfU << FSCAN_TXBDLCR_DLC_Pos)
#define    FSCAN_TXBDLCR_DLC                                        FSCAN_TXBDLCR_DLC_Msk

#define    FSCAN_TXBDW1R_DB_Pos                                     (0U)
#define    FSCAN_TXBDW1R_DB_Msk                                     (0xffffffffU << FSCAN_TXBDW1R_DB_Pos)
#define    FSCAN_TXBDW1R_DB                                         FSCAN_TXBDW1R_DB_Msk

#define    FSCAN_TXBDW2R_DB_Pos                                     (0U)
#define    FSCAN_TXBDW2R_DB_Msk                                     (0xffffffffU << FSCAN_TXBDW2R_DB_Pos)
#define    FSCAN_TXBDW2R_DB                                         FSCAN_TXBDW2R_DB_Msk

#define    FSCAN_RXFIDR_IDR_Pos                                     (0U)
#define    FSCAN_RXFIDR_IDR_Msk                                     (0xffffffffU << FSCAN_RXFIDR_IDR_Pos)
#define    FSCAN_RXFIDR_IDR                                         FSCAN_RXFIDR_IDR_Msk

#define    FSCAN_RXFDLCR_DLC_Pos                                    (0U)
#define    FSCAN_RXFDLCR_DLC_Msk                                    (0xfU << FSCAN_RXFDLCR_DLC_Pos)
#define    FSCAN_RXFDLCR_DLC                                        FSCAN_RXFDLCR_DLC_Msk

#define    FSCAN_RXFDW1R_DB_Pos                                     (0U)
#define    FSCAN_RXFDW1R_DB_Msk                                     (0xffffffffU << FSCAN_RXFDW1R_DB_Pos)
#define    FSCAN_RXFDW1R_DB                                         FSCAN_RXFDW1R_DB_Msk

#define    FSCAN_RXFDW2R_DB_Pos                                     (0U)
#define    FSCAN_RXFDW2R_DB_Msk                                     (0xffffffffU << FSCAN_RXFDW2R_DB_Pos)
#define    FSCAN_RXFDW2R_DB                                         FSCAN_RXFDW2R_DB_Msk

#define    FSCAN_AFCR_UAF_Pos                                       (0U)
#define    FSCAN_AFCR_UAF_Msk                                       (0x1U << FSCAN_AFCR_UAF_Pos)
#define    FSCAN_AFCR_UAF                                           FSCAN_AFCR_UAF_Msk

#define    FSCAN_AFCFGR_MSKM_Pos                                    (16U)
#define    FSCAN_AFCFGR_MSKM_Msk                                    (0x1U << FSCAN_AFCFGR_MSKM_Pos)
#define    FSCAN_AFCFGR_MSKM                                        FSCAN_AFCFGR_MSKM_Msk

#define    FSCAN_AFCFGR_FSC_Pos                                     (0U)
#define    FSCAN_AFCFGR_FSC_Msk                                     (0x1U << FSCAN_AFCFGR_FSC_Pos)
#define    FSCAN_AFCFGR_FSC                                         FSCAN_AFCFGR_FSC_Msk

#define    FSCAN_AFMR_AMRTR_Pos                                     (31U)
#define    FSCAN_AFMR_AMRTR_Msk                                     (0x1U << FSCAN_AFMR_AMRTR_Pos)
#define    FSCAN_AFMR_AMRTR                                         FSCAN_AFMR_AMRTR_Msk

#define    FSCAN_AFMR_AMID18_Pos                                    (13U)
#define    FSCAN_AFMR_AMID18_Msk                                    (0x3ffffU << FSCAN_AFMR_AMID18_Pos)
#define    FSCAN_AFMR_AMID18                                        FSCAN_AFMR_AMID18_Msk

#define    FSCAN_AFMR_AMIDE_Pos                                     (12U)
#define    FSCAN_AFMR_AMIDE_Msk                                     (0x1U << FSCAN_AFMR_AMIDE_Pos)
#define    FSCAN_AFMR_AMIDE                                         FSCAN_AFMR_AMIDE_Msk

#define    FSCAN_AFMR_AMSRR_Pos                                     (11U)
#define    FSCAN_AFMR_AMSRR_Msk                                     (0x1U << FSCAN_AFMR_AMSRR_Pos)
#define    FSCAN_AFMR_AMSRR                                         FSCAN_AFMR_AMSRR_Msk

#define    FSCAN_AFMR_AMID11_Pos                                    (0U)
#define    FSCAN_AFMR_AMID11_Msk                                    (0x7ffU << FSCAN_AFMR_AMID11_Pos)
#define    FSCAN_AFMR_AMID11                                        FSCAN_AFMR_AMID11_Msk




#define    FSCAN_AFMRSTD2_AMID3_Pos                                 (29U)
#define    FSCAN_AFMRSTD2_AMID3_Msk                                 (0x7U << FSCAN_AFMRSTD2_AMID3_Pos)
#define    FSCAN_AFMRSTD2_AMID3                                      FSCAN_AFMRSTD2_AMID3_Msk

#define    FSCAN_AFMRSTD2_AMIDE_Pos                                 (28U)
#define    FSCAN_AFMRSTD2_AMIDE_Msk                                 (0x1U << FSCAN_AFMRSTD2_AMIDE_Pos)
#define    FSCAN_AFMRSTD2_AMIDE                                      FSCAN_AFMRSTD2_AMIDE_Msk

#define    FSCAN_AFMRSTD2_AMSRR_Pos                                 (27U)
#define    FSCAN_AFMRSTD2_AMSRR_Msk                                 (0x1U << FSCAN_AFMRSTD2_AMSRR_Pos)
#define    FSCAN_AFMRSTD2_AMSRR                                      FSCAN_AFMRSTD2_AMSRR_Msk

#define    FSCAN_AFMRSTD2_AMID11_Pos                                (16U)
#define    FSCAN_AFMRSTD2_AMID11_Msk                                (0x7ffU << FSCAN_AFMRSTD2_AMID11_Pos)
#define    FSCAN_AFMRSTD2_AMID11                                     FSCAN_AFMRSTD2_AMID11_Msk

#define    FSCAN_AFMRSTD1_AMID3_Pos                                 (13U)
#define    FSCAN_AFMRSTD1_AMID3_Msk                                 (0x7U << FSCAN_AFMRSTD1_AMID3_Pos)
#define    FSCAN_AFMRSTD1_AMID3                                      FSCAN_AFMRSTD1_AMID3_Msk

#define    FSCAN_AFMRSTD1_AMIDE_Pos                                 (12U)
#define    FSCAN_AFMRSTD1_AMIDE_Msk                                 (0x1U << FSCAN_AFMRSTD1_AMIDE_Pos)
#define    FSCAN_AFMRSTD1_AMIDE                                     FSCAN_AFMRSTD1_AMIDE_Msk

#define    FSCAN_AFMRSTD1_AMSRR_Pos                                 (11U)
#define    FSCAN_AFMRSTD1_AMSRR_Msk                                 (0x1U << FSCAN_AFMRSTD1_AMSRR_Pos)
#define    FSCAN_AFMRSTD1_AMSRR                                      FSCAN_AFMRSTD1_AMSRR_Msk

#define    FSCAN_AFMRSTD1_AMID11_Pos                                (0U)
#define    FSCAN_AFMRSTD1_AMID11_Msk                                (0x7ffU << FSCAN_AFMRSTD1_AMID11_Pos)
#define    FSCAN_AFMRSTD1_AMID11                                    FSCAN_AFMRSTD1_AMID11_Msk





#define    FSCAN_AFIR_AIRTR_Pos                                     (31U)
#define    FSCAN_AFIR_AIRTR_Msk                                     (0x1U << FSCAN_AFIR_AIRTR_Pos)
#define    FSCAN_AFIR_AIRTR                                         FSCAN_AFIR_AIRTR_Msk

#define    FSCAN_AFIR_AIID18_Pos                                    (13U)
#define    FSCAN_AFIR_AIID18_Msk                                    (0x3ffffU << FSCAN_AFIR_AIID18_Pos)
#define    FSCAN_AFIR_AIID18                                        FSCAN_AFIR_AIID18_Msk

#define    FSCAN_AFIR_AIIDE_Pos                                     (12U)
#define    FSCAN_AFIR_AIIDE_Msk                                     (0x1U << FSCAN_AFIR_AIIDE_Pos)
#define    FSCAN_AFIR_AIIDE                                         FSCAN_AFIR_AIIDE_Msk

#define    FSCAN_AFIR_AISRR_Pos                                     (11U)
#define    FSCAN_AFIR_AISRR_Msk                                     (0x1U << FSCAN_AFIR_AISRR_Pos)
#define    FSCAN_AFIR_AISRR                                         FSCAN_AFIR_AISRR_Msk

#define    FSCAN_AFIR_AIID11_Pos                                    (0U)
#define    FSCAN_AFIR_AIID11_Msk                                    (0x7ffU << FSCAN_AFIR_AIID11_Pos)
#define    FSCAN_AFIR_AIID11                                        FSCAN_AFIR_AIID11_Msk




#define    FSCAN_AFIRSTD2_AIID3_Pos                                  (29U)
#define    FSCAN_AFIRSTD2_AIID3_Msk                                  (0x7U << FSCAN_AFIRSTD2_AIID3_Pos)
#define    FSCAN_AFIRSTD2_AIID3                                      FSCAN_AFIRSTD2_AIID3_Msk

#define    FSCAN_AFIRSTD2_AIIDE_Pos                                  (28U)
#define    FSCAN_AFIRSTD2_AIIDE_Msk                                  (0x1U << FSCAN_AFIRSTD2_AIIDE_Pos)
#define    FSCAN_AFIRSTD2_AIIDE                                      FSCAN_AFIRSTD2_AIIDE_Msk

#define    FSCAN_AFIRSTD2_AISRR_Pos                                  (27U)
#define    FSCAN_AFIRSTD2_AISRR_Msk                                  (0x1U << FSCAN_AFIRSTD2_AISRR_Pos)
#define    FSCAN_AFIRSTD2_AISRR                                      FSCAN_AFIRSTD2_AISRR_Msk

#define    FSCAN_AFIRSTD2_AIID11_Pos                                 (16U)
#define    FSCAN_AFIRSTD2_AIID11_Msk                                 (0x7ffU << FSCAN_AFIRSTD2_AIID11_Pos)
#define    FSCAN_AFIRSTD2_AIID11                                     FSCAN_AFIRSTD2_AIID11_Msk

#define    FSCAN_AFIRSTD1_AIID3_Pos                                  (13U)
#define    FSCAN_AFIRSTD1_AIID3_Msk                                  (0x7U << FSCAN_AFIRSTD1_AIID3_Pos)
#define    FSCAN_AFIRSTD1_AIID3                                      FSCAN_AFIRSTD1_AIID3_Msk

#define    FSCAN_AFIRSTD1_AIIDE_Pos                                  (12U)
#define    FSCAN_AFIRSTD1_AIIDE_Msk                                  (0x1U << FSCAN_AFIRSTD1_AIIDE_Pos)
#define    FSCAN_AFIRSTD1_AIIDE                                      FSCAN_AFIRSTD1_AIIDE_Msk

#define    FSCAN_AFIRSTD1_AISRR_Pos                                  (11U)
#define    FSCAN_AFIRSTD1_AISRR_Msk                                  (0x1U << FSCAN_AFIRSTD1_AISRR_Pos)
#define    FSCAN_AFIRSTD1_AISRR                                      FSCAN_AFIRSTD1_AISRR_Msk

#define    FSCAN_AFIRSTD1_AIID11_Pos                                 (0U)
#define    FSCAN_AFIRSTD1_AIID11_Msk                                 (0x7ffU << FSCAN_AFIRSTD1_AIID11_Pos)
#define    FSCAN_AFIRSTD1_AIID11                                     FSCAN_AFIRSTD1_AIID11_Msk



#define    FL_FSCAN_SOFTWARE_NO_RESET                               (0x0U << FSCAN_CR_SRST_Pos)
#define    FL_FSCAN_SOFTWARE_RESET                                  (0x1U << FSCAN_CR_SRST_Pos)


#define    FL_FSCAN_TX_PRIORITY_ID                                  (0x0U << FSCAN_MSR_TPRI_Pos)
#define    FL_FSCAN_TX_PRIORITY_BUFFER                              (0x1U << FSCAN_MSR_TPRI_Pos)


#define    FL_FSCAN_AUTO_MANAGE_HARDWARE                            (0x0U << FSCAN_MSR_ABOM_Pos)
#define    FL_FSCAN_AUTO_MANAGE_SOFTWARE_WAIT                       (0x1U << FSCAN_MSR_ABOM_Pos)
#define    FL_FSCAN_AUTO_MANAGE_SOFTWARE_INTERGRATION               (0x2U << FSCAN_MSR_ABOM_Pos)


#define    FL_FSCAN_RX_STATUS_NORMAL                                (0x0U << FSCAN_SR_RSTS_Pos)
#define    FL_FSCAN_RX_STATUS_WARNING                               (0x1U << FSCAN_SR_RSTS_Pos)
#define    FL_FSCAN_RX_STATUS_ERROR                                 (0x2U << FSCAN_SR_RSTS_Pos)
#define    FL_FSCAN_RX_STATUS_BUSOFF                               (0x3U << FSCAN_SR_RSTS_Pos)

#define    FL_FSCAN_TX_STATUS_NORMAL                                (0x0U << FSCAN_SR_TSTS_Pos)
#define    FL_FSCAN_TX_STATUS_WARNING                               (0x1U << FSCAN_SR_TSTS_Pos)
#define    FL_FSCAN_TX_STATUS_ERROR                                 (0x2U << FSCAN_SR_TSTS_Pos)
#define    FL_FSCAN_TX_STATUS_BUSOFF                               (0x3U << FSCAN_SR_TSTS_Pos)

#define    FL_FSCAN_TX_ABORT_NONE                                   (0x0U << FSCAN_TXBCR_TXAR_Pos)
#define    FL_FSCAN_TX_ABORT_BUFFER_0                               (0x1U << FSCAN_TXBCR_TXAR_Pos)
#define    FL_FSCAN_TX_ABORT_BUFFER_1                               (0x2U << FSCAN_TXBCR_TXAR_Pos)
#define    FL_FSCAN_TX_ABORT_BUFFER_0AND1                           (0x3U << FSCAN_TXBCR_TXAR_Pos)
#define    FL_FSCAN_TX_ABORT_BUFFER_2                               (0x4U << FSCAN_TXBCR_TXAR_Pos)
#define    FL_FSCAN_TX_ABORT_BUFFER_0AND2                           (0x5U << FSCAN_TXBCR_TXAR_Pos)
#define    FL_FSCAN_TX_ABORT_BUFFER_1AND2                           (0x6U << FSCAN_TXBCR_TXAR_Pos)
#define    FL_FSCAN_TX_ABORT_ALL                                    (0x7U << FSCAN_TXBCR_TXAR_Pos)


#define    FL_FSCAN_TX_RESULT_NONE                                  (0x0U << FSCAN_TXBSR_TXRF_Pos)
#define    FL_FSCAN_TX_RESULT_ABORT                                 (0x1U << FSCAN_TXBSR_TXRF_Pos)
#define    FL_FSCAN_TX_RESULT_OK_NOABORT                            (0x2U << FSCAN_TXBSR_TXRF_Pos)
#define    FL_FSCAN_TX_RESULT_OK_ABORT                              (0x3U << FSCAN_TXBSR_TXRF_Pos)

#define    FL_FSCAN_TX_BUFFER_ALL_IDLE                              (0x0U << FSCAN_TXBSR_TXS_Pos)
#define    FL_FSCAN_TX_BUFFER_0_BUSY                                (0x1U << FSCAN_TXBSR_TXS_Pos)
#define    FL_FSCAN_TX_BUFFER_1_BUSY                                (0x2U << FSCAN_TXBSR_TXS_Pos)
#define    FL_FSCAN_TX_BUFFER_0AND1_BUSY                            (0x3U << FSCAN_TXBSR_TXS_Pos)
#define    FL_FSCAN_TX_BUFFER_2_BUSY                                (0x4U << FSCAN_TXBSR_TXS_Pos)
#define    FL_FSCAN_TX_BUFFER_0AND2_BUSY                            (0x5U << FSCAN_TXBSR_TXS_Pos)
#define    FL_FSCAN_TX_BUFFER_1AND2_BUSY                            (0x6U << FSCAN_TXBSR_TXS_Pos)
#define    FL_FSCAN_TX_BUFFER_ALL_BUSY                              (0x7U << FSCAN_TXBSR_TXS_Pos)

#define    FL_FSCAN_RTR_BIT_LOW                                     (0x0U << FSCAN_AFIR_AIRTR_Pos)
#define    FL_FSCAN_RTR_BIT_HIGH                                    (0x1U << FSCAN_AFIR_AIRTR_Pos)


#define    FL_FSCAN_IDE_BIT_LOW                                     (0x0U << FSCAN_AFIR_AIIDE_Pos)
#define    FL_FSCAN_IDE_BIT_HIGH                                    (0x1U << FSCAN_AFIR_AIIDE_Pos)


#define    FL_FSCAN_SRR_BIT_LOW                                     (0x0U << FSCAN_AFIR_AISRR_Pos)
#define    FL_FSCAN_SRR_BIT_HIGH                                    (0x1U << FSCAN_AFIR_AISRR_Pos)

#define    FL_FSCAN_STD1IDE_BIT_LOW                               (0x0U << FSCAN_AFIRSTD1_AIIDE_Pos)
#define    FL_FSCAN_STD1IDE_BIT_HIGH                              (0x1U << FSCAN_AFIRSTD1_AIIDE_Pos)

#define    FL_FSCAN_STD1SRR_BIT_LOW                               (0x0U << FSCAN_AFIRSTD1_AISRR_Pos)
#define    FL_FSCAN_STD1SRR_BIT_HIGH                              (0x1U << FSCAN_AFIRSTD1_AISRR_Pos)

#define    FL_FSCAN_STD2IDE_BIT_LOW                               (0x0U << FSCAN_AFIRSTD2_AIIDE_Pos)
#define    FL_FSCAN_STD2IDE_BIT_HIGH                              (0x1U << FSCAN_AFIRSTD2_AIIDE_Pos)

#define    FL_FSCAN_STD2SRR_BIT_LOW                               (0x0U << FSCAN_AFIRSTD2_AISRR_Pos)
#define    FL_FSCAN_STD2SRR_BIT_HIGH                              (0x1U << FSCAN_AFIRSTD2_AISRR_Pos)


#define    FL_FSCAN_MASKMODE_ID                                     (0x1U << FSCAN_AFCFGR_MSKM_Pos)
#define    FL_FSCAN_MASKMODE_MASK                                   (0x0U << FSCAN_AFCFGR_MSKM_Pos)

#define    FL_FSCAN_IDMODE_16BIT                                     (0x1U << FSCAN_AFCFGR_FSC_Pos)
#define    FL_FSCAN_IDMODE_32BIT                                     (0x0U << FSCAN_AFCFGR_FSC_Pos)

#define    FL_FSCAN_FILTER1                                         0x0U
#define    FL_FSCAN_FILTER2                                         0x1U
#define    FL_FSCAN_FILTER3                                         0x2U
#define    FL_FSCAN_FILTER4                                         0x3U
#define    FL_FSCAN_FILTER5                                         0x4U
#define    FL_FSCAN_FILTER6                                         0x5U
#define    FL_FSCAN_FILTER7                                         0x6U
#define    FL_FSCAN_FILTER8                                         0x7U
#define    FL_FSCAN_FILTER9                                         0x8U
#define    FL_FSCAN_FILTER10                                        0x9U
#define    FL_FSCAN_FILTER11                                        0xAU
#define    FL_FSCAN_FILTER12                                        0xBU
#define    FL_FSCAN_FILTER13                                        0xCU
#define    FL_FSCAN_FILTER14                                        0xDU
#define    FL_FSCAN_FILTER15                                        0xEU
#define    FL_FSCAN_FILTER16                                        0xFU

#define    FL_FSCAN_FILTERMASK1                                     0x1U<<0U
#define    FL_FSCAN_FILTERMASK2                                     0x1U<<1U
#define    FL_FSCAN_FILTERMASK3                                     0x1U<<2U
#define    FL_FSCAN_FILTERMASK4                                     0x1U<<3U

#define    FL_FSCAN_FILTERID1                                        0x1U
#define    FL_FSCAN_FILTERID2                                        0x2U
#define    FL_FSCAN_FILTERID3                                        0x3U
#define    FL_FSCAN_FILTERID4                                        0x4U

#define    FL_FSCAN_BUFFER0                                         0x1U<<0U
#define    FL_FSCAN_BUFFER1                                         0x1U<<1U
#define    FL_FSCAN_BUFFER2                                         0x1U<<2U



#define FL_FSCAN_TS1_1Tq  0U
#define FL_FSCAN_TS1_2Tq  1U
#define FL_FSCAN_TS1_3Tq  2U
#define FL_FSCAN_TS1_4Tq  3U
#define FL_FSCAN_TS1_5Tq  4U
#define FL_FSCAN_TS1_6Tq  5U
#define FL_FSCAN_TS1_7Tq  6U
#define FL_FSCAN_TS1_8Tq  7U
#define FL_FSCAN_TS1_9Tq  8U
#define FL_FSCAN_TS1_10Tq  9U
#define FL_FSCAN_TS1_11Tq  10U
#define FL_FSCAN_TS1_12Tq  11U
#define FL_FSCAN_TS1_13Tq  12U
#define FL_FSCAN_TS1_14Tq  13U
#define FL_FSCAN_TS1_15Tq  14U
#define FL_FSCAN_TS1_16Tq  15U

#define FL_FSCAN_TS2_1Tq  0U
#define FL_FSCAN_TS2_2Tq  1U
#define FL_FSCAN_TS2_3Tq  2U
#define FL_FSCAN_TS2_4Tq  3U
#define FL_FSCAN_TS2_5Tq  4U
#define FL_FSCAN_TS2_6Tq  5U
#define FL_FSCAN_TS2_7Tq  6U
#define FL_FSCAN_TS2_8Tq  7U


#define FL_FSCAN_SJW_1Tq  0U
#define FL_FSCAN_SJW_2Tq  1U
#define FL_FSCAN_SJW_3Tq  2U
#define FL_FSCAN_SJW_4Tq  3U

#define FL_FSCAN_MODE_NORMAL    0U
#define FL_FSCAN_MODE_LOOPBACK  1U
#define FL_FSCAN_MODE_CONFIG    2U
#define FL_FSCAN_MODE_SLEEP     3U



#define FL_FSCAN_FORMAT_STANDARD_DATA    0
#define FL_FSCAN_FORMAT_STANDARD_REMOTE  1
#define FL_FSCAN_FORMAT_EXTEND_DATA      2
#define FL_FSCAN_FORMAT_EXTEND_REMOTE    3

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup FSCAN_FL_Exported_Functions FSCAN Exported Functions
  * @{
  */

/**
  * @brief    FSCAN enable
  * @rmtoll   CR    CEN    FL_FSCAN_Enable
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_Enable(FSCAN_Type* FSCANx)
{
    SET_BIT(FSCANx->CR, FSCAN_CR_CEN_Msk);
}

/**
  * @brief    Get FSCAN enable status 
  * @rmtoll   CR    CEN    FL_FSCAN_IsEnabled
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsEnabled(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->CR, FSCAN_CR_CEN_Msk) == FSCAN_CR_CEN_Msk);
}

/**
  * @brief    FSCAN disable
  * @rmtoll   CR    CEN    FL_FSCAN_Disable
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_Disable(FSCAN_Type* FSCANx)
{
    CLEAR_BIT(FSCANx->CR, FSCAN_CR_CEN_Msk);
}

/**
  * @brief    Set FSCAN software reset
  * @rmtoll   CR    SRST    FL_FSCAN_EnableSoftwareReset
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_EnableSoftwareReset(FSCAN_Type *FSCANx)
{
    SET_BIT(FSCANx->CR, FSCAN_CR_SRST_Msk);
}

/**
  * @brief    Rx Presync enable
  * @rmtoll   MSR    RX_PRESYNC_EN    FL_FSCAN_EnableRXPresync
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_EnableRXPresync(FSCAN_Type* FSCANx)
{
    SET_BIT(FSCANx->MSR, FSCAN_MSR_RX_PRESYNC_EN_Msk);
}

/**
  * @brief    Rx Presync disable
  * @rmtoll   MSR    RX_PRESYNC_EN    FL_FSCAN_DisableRXPresync
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_DisableRXPresync(FSCAN_Type* FSCANx)
{
    CLEAR_BIT(FSCANx->MSR, FSCAN_MSR_RX_PRESYNC_EN_Msk);
}

/**
  * @brief    Get Rx Presync enable status
  * @rmtoll   MSR    RX_PRESYNC_EN    FL_FSCAN_IsEnabledRXPresync
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsEnabledRXPresync(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->MSR, FSCAN_MSR_RX_PRESYNC_EN_Msk) == FSCAN_MSR_RX_PRESYNC_EN_Msk);
}

/**
  * @brief    Set TX priority
  * @rmtoll   MSR    TPRI    FL_FSCAN_SetTXPriority
  * @param    FSCAN FSCAN instance
  * @param    priority This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_TX_PRIORITY_ID
  *           @arg @ref FL_FSCAN_TX_PRIORITY_BUFFER
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_SetTXPriority(FSCAN_Type* FSCANx, uint32_t priority)
{
    MODIFY_REG(FSCANx->MSR, FSCAN_MSR_TPRI_Msk, priority);
}

/**
  * @brief    Get Tx priority
  * @rmtoll   MSR    TPRI    FL_FSCAN_GetTXPriority
  * @param    FSCAN FSCAN instance
  * @retval   Returned value fscan be one of the following values:
  *           @arg @ref FL_FSCAN_TX_PRIORITY_ID
  *           @arg @ref FL_FSCAN_TX_PRIORITY_BUFFER
  */
__STATIC_INLINE uint32_t FL_FSCAN_GetTXPriority(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->MSR, FSCAN_MSR_TPRI_Msk));
}

/**
  * @brief    wakeup enable
  * @rmtoll   MSR    WUPE    FL_FSCAN_EnableWakeup
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_EnableWakeup(FSCAN_Type* FSCANx)
{
    SET_BIT(FSCANx->MSR, FSCAN_MSR_WUPE_Msk);
}

/**
  * @brief    wakeup disable
  * @rmtoll   MSR    WUPE    FL_FSCAN_DisableWakeup
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_DisableWakeup(FSCAN_Type* FSCANx)
{
    CLEAR_BIT(FSCANx->MSR, FSCAN_MSR_WUPE_Msk);
}

/**
  * @brief    Get wakeup enable status
  * @rmtoll   MSR    WUPE    FL_FSCAN_IsEnabledWakeup
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsEnabledWakeup(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->MSR, FSCAN_MSR_WUPE_Msk) == FSCAN_MSR_WUPE_Msk);
}

/**
  * @brief    Auto resend enable
  * @rmtoll   MSR    AREN    FL_FSCAN_EnableAutoResend
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_EnableAutoResend(FSCAN_Type* FSCANx)
{
    SET_BIT(FSCANx->MSR, FSCAN_MSR_AREN_Msk);
}

/**
  * @brief    Auto resend disable
  * @rmtoll   MSR    AREN    FL_FSCAN_DisableAutoResend
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_DisableAutoResend(FSCAN_Type* FSCANx)
{
    CLEAR_BIT(FSCANx->MSR, FSCAN_MSR_AREN_Msk);
}

/**
  * @brief    Get Auto resend enable status
  * @rmtoll   MSR    AREN    FL_FSCAN_IsEnabledAutoResend
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsEnabledAutoResend(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->MSR, FSCAN_MSR_AREN_Msk) == FSCAN_MSR_AREN_Msk);
}

/**
  * @brief    Set auto bus off management
  * @rmtoll   MSR    ABOM    FL_FSCAN_SetAutoBusOffManagement
  * @param    FSCAN FSCAN instance
  * @param    state This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_AUTO_MANAGE_HARDWARE
  *           @arg @ref FL_FSCAN_AUTO_MANAGE_SOFTWARE_WAIT
  *           @arg @ref FL_FSCAN_AUTO_MANAGE_SOFTWARE_INTEERGRATION
  *           @arg @ref FL_FSCAN_AUTO_MANAGE_HARDWARE
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_SetAutoBusOffManagement(FSCAN_Type* FSCANx, uint32_t state)
{
    MODIFY_REG(FSCANx->MSR, FSCAN_MSR_ABOM_Msk, state);
}

/**
  * @brief    Get auto bus off management
  * @rmtoll   MSR    ABOM    FL_FSCAN_GetAutoBusOffManagement
  * @param    FSCAN FSCAN instance
  * @retval   Returned value fscan be one of the following values:
  *           @arg @ref FL_FSCAN_AUTO_MANAGE_HARDWARE
  *           @arg @ref FL_FSCAN_AUTO_MANAGE_SOFTWARE_WAIT
  *           @arg @ref FL_FSCAN_AUTO_MANAGE_SOFTWARE_INTEERGRATION
  *           @arg @ref FL_FSCAN_AUTO_MANAGE_HARDWARE
  */
__STATIC_INLINE uint32_t FL_FSCAN_GetAutoBusOffManagement(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->MSR, FSCAN_MSR_ABOM_Msk));
}

/**
  * @brief    Software exit busoff enable 
  * @rmtoll   MSR    RTBO    FL_FSCAN_EnableSoftwareExitBusoff
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_EnableSoftwareExitBusoff(FSCAN_Type* FSCANx)
{
    SET_BIT(FSCANx->MSR, FSCAN_MSR_RTBO_Msk);
}

/**
  * @brief    Software exit busoff disable 
  * @rmtoll   MSR    RTBO    FL_FSCAN_DisableSoftwareExitBusoff
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_DisableSoftwareExitBusoff(FSCAN_Type* FSCANx)
{
    CLEAR_BIT(FSCANx->MSR, FSCAN_MSR_RTBO_Msk);
}

/**
  * @brief    Get software exit busoff enable status
  * @rmtoll   MSR    RTBO    FL_FSCAN_IsEnabledSoftwareExitBusoff
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsEnabledSoftwareExitBusoff(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->MSR, FSCAN_MSR_RTBO_Msk) == FSCAN_MSR_RTBO_Msk);
}

/**
  * @brief    Enable loop back mode
  * @rmtoll   MSR    LPBACK    FL_FSCAN_EnableLoopBackMode
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_EnableLoopBackMode(FSCAN_Type* FSCANx)
{
    SET_BIT(FSCANx->MSR, FSCAN_MSR_LPBACK_Msk);
}

/**
  * @brief    Disable loop back mode
  * @rmtoll   MSR    LPBACK    FL_FSCAN_DisableLoopBackMode
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_DisableLoopBackMode(FSCAN_Type* FSCANx)
{
    CLEAR_BIT(FSCANx->MSR, FSCAN_MSR_LPBACK_Msk);
}

/**
  * @brief    Get loop back mode Enable Status
  * @rmtoll   MSR    LPBACK    FL_FSCAN_IsEnabledLoopBackMode
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsEnabledLoopBackMode(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->MSR, FSCAN_MSR_LPBACK_Msk) == FSCAN_MSR_LPBACK_Msk);
}

/**
  * @brief    Enable Sleep mode
  * @rmtoll   MSR    SLEEP    FL_FSCAN_EnableSleepMode
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_EnableSleepMode(FSCAN_Type* FSCANx)
{
    SET_BIT(FSCANx->MSR, FSCAN_MSR_SLEEP_Msk);
}

/**
  * @brief    Disable Sleep mode
  * @rmtoll   MSR    SLEEP    FL_FSCAN_DisableSleepMode
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_DisableSleepMode(FSCAN_Type* FSCANx)
{
    CLEAR_BIT(FSCANx->MSR, FSCAN_MSR_SLEEP_Msk);
}

/**
  * @brief    Get Sleep mode Enable Status
  * @rmtoll   MSR    SLEEP    FL_FSCAN_IsEnabledSleepMode
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsEnabledSleepMode(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->MSR, FSCAN_MSR_SLEEP_Msk) == FSCAN_MSR_SLEEP_Msk);
}

/**
  * @brief    Set baud rate prescaler
  * @rmtoll   BRPR    BRP    FL_FSCAN_WriteBaudRatePrescaler
  * @param    FSCAN FSCAN instance
  * @param    psc 
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_WriteBaudRatePrescaler(FSCAN_Type* FSCANx, uint32_t psc)
{
    MODIFY_REG(FSCANx->BRPR, FSCAN_BRPR_BRP_Msk, (psc << FSCAN_BRPR_BRP_Pos));
}

/**
  * @brief    Get baud rate prescaler
  * @rmtoll   BRPR    BRP    FL_FSCAN_ReadBaudRatePrescaler
  * @param    FSCAN FSCAN instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_FSCAN_ReadBaudRatePrescaler(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->BRPR, FSCAN_BRPR_BRP_Msk) >> FSCAN_BRPR_BRP_Pos);
}

/**
  * @brief    Set synchronization jump width
  * @rmtoll   BTR    SJW    FL_FSCAN_WriteSyncJumpWidth
  * @param    FSCAN FSCAN instance
  * @param    width 
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_WriteSyncJumpWidth(FSCAN_Type* FSCANx, uint32_t width)
{
    MODIFY_REG(FSCANx->BTR, FSCAN_BTR_SJW_Msk, (width << FSCAN_BTR_SJW_Pos));
}

/**
  * @brief    Get synchronization jump width
  * @rmtoll   BTR    SJW    FL_FSCAN_ReadSyncJumpWidth
  * @param    FSCAN FSCAN instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_FSCAN_ReadSyncJumpWidth(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->BTR, FSCAN_BTR_SJW_Msk) >> FSCAN_BTR_SJW_Pos);
}

/**
  * @brief    Set time segment2 length
  * @rmtoll   BTR    TS2    FL_FSCAN_WriteTimeSegment2Length
  * @param    FSCAN FSCAN instance
  * @param    length 
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_WriteTimeSegment2Length(FSCAN_Type* FSCANx, uint32_t length)
{
    MODIFY_REG(FSCANx->BTR, FSCAN_BTR_TS2_Msk, (length << FSCAN_BTR_TS2_Pos));
}

/**
  * @brief    Get time segment2 length
  * @rmtoll   BTR    TS2    FL_FSCAN_ReadTimeSegment2Length
  * @param    FSCAN FSCAN instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_FSCAN_ReadTimeSegment2Length(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->BTR, FSCAN_BTR_TS2_Msk) >> FSCAN_BTR_TS2_Pos);
}

/**
  * @brief    Set time segment2 length
  * @rmtoll   BTR    TS1    FL_FSCAN_WriteTimeSegment1Length
  * @param    FSCAN FSCAN instance
  * @param    length 
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_WriteTimeSegment1Length(FSCAN_Type* FSCANx, uint32_t length)
{
    MODIFY_REG(FSCANx->BTR, FSCAN_BTR_TS1_Msk, (length << FSCAN_BTR_TS1_Pos));
}

/**
  * @brief    Get time segment2 length
  * @rmtoll   BTR    TS1    FL_FSCAN_ReadTimeSegment1Length
  * @param    FSCAN FSCAN instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_FSCAN_ReadTimeSegment1Length(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->BTR, FSCAN_BTR_TS1_Msk) >> FSCAN_BTR_TS1_Pos);
}

/**
  * @brief    Get receive error number 
  * @rmtoll   ECR    REC    FL_FSCAN_ReadRXErrorCount
  * @param    FSCAN FSCAN instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_FSCAN_ReadRXErrorCount(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->ECR, FSCAN_ECR_REC_Msk) >> FSCAN_ECR_REC_Pos);
}

/**
  * @brief    Get transmit error number
  * @rmtoll   ECR    TEC    FL_FSCAN_ReadTXErrorCount
  * @param    FSCAN FSCAN instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_FSCAN_ReadTXErrorCount(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->ECR, FSCAN_ECR_TEC_Msk) >> FSCAN_ECR_TEC_Pos);
}

/**
  * @brief    Get Overload flag
  * @rmtoll   ESR    OVLF    FL_FSCAN_IsActiveFlag_Overload
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_Overload(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->ESR, FSCAN_ESR_OVLF_Msk) == (FSCAN_ESR_OVLF_Msk));
}

/**
  * @brief    Clear Overload flag
  * @rmtoll   ESR    OVLF    FL_FSCAN_ClearFlag_Overload
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_ClearFlag_Overload(FSCAN_Type* FSCANx)
{
    WRITE_REG(FSCANx->ESR, FSCAN_ESR_OVLF_Msk);
}

/**
  * @brief    Get Bus Lock flag
  * @rmtoll   ESR    BLF    FL_FSCAN_IsActiveFlag_Buslock
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_Buslock(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->ESR, FSCAN_ESR_BLF_Msk) == (FSCAN_ESR_BLF_Msk));
}

/**
  * @brief    Clear Bus Lock flag
  * @rmtoll   ESR    BLF    FL_FSCAN_ClearFlag_Buslock
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_ClearFlag_Buslock(FSCAN_Type* FSCANx)
{
    WRITE_REG(FSCANx->ESR, FSCAN_ESR_BLF_Msk);
}

/**
  * @brief    Get ACK Delimiter error flag
  * @rmtoll   ESR    ADERR    FL_FSCAN_IsActiveFlag_AckDelimiterError
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_AckDelimiterError(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->ESR, FSCAN_ESR_ADERR_Msk) == (FSCAN_ESR_ADERR_Msk));
}

/**
  * @brief    Clear ACK Delimiter error flag
  * @rmtoll   ESR    ADERR    FL_FSCAN_ClearFlag_AckDelimiterError
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_ClearFlag_AckDelimiterError(FSCAN_Type* FSCANx)
{
    WRITE_REG(FSCANx->ESR, FSCAN_ESR_ADERR_Msk);
}

/**
  * @brief    Get ACK error flag
  * @rmtoll   ESR    ACKER    FL_FSCAN_IsActiveFlag_AckError
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_AckError(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->ESR, FSCAN_ESR_ACKER_Msk) == (FSCAN_ESR_ACKER_Msk));
}

/**
  * @brief    Clear ACK error flag
  * @rmtoll   ESR    ACKER    FL_FSCAN_ClearFlag_AckError
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_ClearFlag_AckError(FSCAN_Type* FSCANx)
{
    WRITE_REG(FSCANx->ESR, FSCAN_ESR_ACKER_Msk);
}

/**
  * @brief    Get receive bit 0 error flag
  * @rmtoll   ESR    B0ERR    FL_FSCAN_IsActiveFlag_Bit0Error
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_Bit0Error(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->ESR, FSCAN_ESR_B0ERR_Msk) == (FSCAN_ESR_B0ERR_Msk));
}

/**
  * @brief    Clear receive bit 0 error flag
  * @rmtoll   ESR    B0ERR    FL_FSCAN_ClearFlag_Bit0Error
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_ClearFlag_Bit0Error(FSCAN_Type* FSCANx)
{
    WRITE_REG(FSCANx->ESR, FSCAN_ESR_B0ERR_Msk);
}

/**
  * @brief    Get receive bit 1 error flag
  * @rmtoll   ESR    B1ERR    FL_FSCAN_IsActiveFlag_Bit1Error
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_Bit1Error(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->ESR, FSCAN_ESR_B1ERR_Msk) == (FSCAN_ESR_B1ERR_Msk));
}

/**
  * @brief    Clear receive bit 1 error flag
  * @rmtoll   ESR    B1ERR    FL_FSCAN_ClearFlag_Bit1Error
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_ClearFlag_Bit1Error(FSCAN_Type* FSCANx)
{
    WRITE_REG(FSCANx->ESR, FSCAN_ESR_B1ERR_Msk);
}

/**
  * @brief    Get stuffing error flag
  * @rmtoll   ESR    STER    FL_FSCAN_IsActiveFlag_StuffError
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_StuffError(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->ESR, FSCAN_ESR_STER_Msk) == (FSCAN_ESR_STER_Msk));
}

/**
  * @brief    Clear stuffing error flag
  * @rmtoll   ESR    STER    FL_FSCAN_ClearFlag_StuffError
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_ClearFlag_StuffError(FSCAN_Type* FSCANx)
{
    WRITE_REG(FSCANx->ESR, FSCAN_ESR_STER_Msk);
}

/**
  * @brief    Get form error flag
  * @rmtoll   ESR    FMER    FL_FSCAN_IsActiveFlag_FormatError
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_FormatError(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->ESR, FSCAN_ESR_FMER_Msk) == (FSCAN_ESR_FMER_Msk));
}

/**
  * @brief    Clear form error flag
  * @rmtoll   ESR    FMER    FL_FSCAN_ClearFlag_FormatError
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_ClearFlag_FormatError(FSCAN_Type* FSCANx)
{
    WRITE_REG(FSCANx->ESR, FSCAN_ESR_FMER_Msk);
}

/**
  * @brief    Get CRC error fiag
  * @rmtoll   ESR    CRCER    FL_FSCAN_IsActiveFlag_CRCError
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_CRCError(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->ESR, FSCAN_ESR_CRCER_Msk) == (FSCAN_ESR_CRCER_Msk));
}

/**
  * @brief    Clear CRC error flag
  * @rmtoll   ESR    CRCER    FL_FSCAN_ClearFlag_CRCError
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_ClearFlag_CRCError(FSCAN_Type* FSCANx)
{
    WRITE_REG(FSCANx->ESR, FSCAN_ESR_CRCER_Msk);
}

/**
  * @brief    Get acceptance filter busy flag
  * @rmtoll   SR    ACFBSY    FL_FSCAN_IsActiveFlag_FilterBusy
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_FilterBusy(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->SR, FSCAN_SR_ACFBSY_Msk) == (FSCAN_SR_ACFBSY_Msk));
}

/**
  * @brief    Get transmit FIFO FULL interrupt flag 
  * @rmtoll   SR    RXFE    FL_FSCAN_IsActiveFlag_RXBuffEmpty
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_RXBufferEmpty(FSCAN_Type *FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->SR, FSCAN_SR_RXFE_Msk) == (FSCAN_SR_RXFE_Msk));
}

/**
  * @brief    Get RX error status
  * @rmtoll   SR    RSTS    FL_FSCAN_GetRXErrorStatus
  * @param    FSCAN FSCAN instance
  * @retval   Returned value fscan be one of the following values:
  *           @arg @ref FL_FSCAN_RX_STATUS_NORMAL
  *           @arg @ref FL_FSCAN_RX_STATUS_WARNING
  *           @arg @ref FL_FSCAN_RX_STATUS_ERROR
  *           @arg @ref FL_FSCAN_RX_STATUS_BUS_OFF
  */
__STATIC_INLINE uint32_t FL_FSCAN_GetRXErrorStatus(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->SR, FSCAN_SR_RSTS_Msk));
}

/**
  * @brief    Get TX error status 
  * @rmtoll   SR    TSTS    FL_FSCAN_GetTXErrorStatus
  * @param    FSCAN FSCAN instance
  * @retval   Returned value fscan be one of the following values:
  *           @arg @ref FL_FSCAN_TX_STATUS_NORMAL
  *           @arg @ref FL_FSCAN_TX_STATUS_WARNING
  *           @arg @ref FL_FSCAN_TX_STATUS_ERROR
  *           @arg @ref FL_FSCAN_TX_STATUS_BUS_OFF
  */
__STATIC_INLINE uint32_t FL_FSCAN_GetTXErrorStatus(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->SR, FSCAN_SR_TSTS_Msk));
}

/**
  * @brief    Get bus busy flag
  * @rmtoll   SR    BBSY    FL_FSCAN_IsActiveFlag_BusBusy
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_BusBusy(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->SR, FSCAN_SR_BBSY_Msk) == (FSCAN_SR_BBSY_Msk));
}

/**
  * @brief    Get bus IDLE flag 
  * @rmtoll   SR    BIDLE    FL_FSCAN_IsActiveFlag_BusIdle
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_BusIdle(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->SR, FSCAN_SR_BIDLE_Msk) == (FSCAN_SR_BIDLE_Msk));
}

/**
  * @brief    Get normal mode flag
  * @rmtoll   SR    NORMAL    FL_FSCAN_IsActiveFlag_NormalMode
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_NormalMode(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->SR, FSCAN_SR_NORMAL_Msk) == (FSCAN_SR_NORMAL_Msk));
}

/**
  * @brief    Get sleep mode flag 
  * @rmtoll   SR    SLEEP    FL_FSCAN_IsActiveFlag_Sleep
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_SleepMode(FSCAN_Type *FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->SR, FSCAN_SR_SLEEP_Msk) == (FSCAN_SR_SLEEP_Msk));
}

/**
  * @brief    Get loop back mode flag 
  * @rmtoll   SR    LBACK    FL_FSCAN_IsActiveFlag_LoopbackMode
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_LoopbackMode(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->SR, FSCAN_SR_LBACK_Msk) == (FSCAN_SR_LBACK_Msk));
}

/**
  * @brief    Get configuration mode flag
  * @rmtoll   SR    CONFIG    FL_FSCAN_IsActiveFlag_ConfigMode
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_ConfigMode(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->SR, FSCAN_SR_CONFIG_Msk) == (FSCAN_SR_CONFIG_Msk));
}

/**
  * @brief    Get bus off recovery interrupt flag
  * @rmtoll   RXISR    BORF    FL_FSCAN_IsActiveFlag_BusOffRecovery
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_BusOffRecovery(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXISR, FSCAN_RXISR_BORF_Msk) == (FSCAN_RXISR_BORF_Msk));
}

/**
  * @brief    Clear bus off recovery interrupt flag
  * @rmtoll   RXISR    BORF    FL_FSCAN_ClearFlag_ErrorStatusChange
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_ClearFlag_BusOffRecovery(FSCAN_Type *FSCANx)
{
    WRITE_REG(FSCANx->RXISR, FSCAN_RXISR_BORF_Msk);
}

/**
  * @brief    Get wakeup interrupt flag
  * @rmtoll   RXISR    WUPF    FL_FSCAN_IsActiveFlag_Wakeup
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_Wakeup(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXISR, FSCAN_RXISR_WUPF_Msk) == (FSCAN_RXISR_WUPF_Msk));
}

/**
  * @brief    Clear wakeup interrupt flag
  * @rmtoll   RXISR    WUPF    FL_FSCAN_ClearFlag_Wakeup
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_ClearFlag_Wakeup(FSCAN_Type* FSCANx)
{
    WRITE_REG(FSCANx->RXISR, FSCAN_RXISR_WUPF_Msk);
}

/**
  * @brief    Get wakeup interrupt flag
  * @rmtoll   RXISR    SLPIF    FL_FSCAN_IsActiveFlag_Sleep
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_Sleep(FSCAN_Type *FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXISR, FSCAN_RXISR_SLPIF_Msk) == (FSCAN_RXISR_SLPIF_Msk));
}

/**
  * @brief    Clear sleep interrupt flag
  * @rmtoll   RXISR    SLPIF    FL_FSCAN_ClearFlag_Sleep
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_ClearFlag_Sleep(FSCAN_Type* FSCANx)
{
    WRITE_REG(FSCANx->RXISR, FSCAN_RXISR_SLPIF_Msk);
}

/**
  * @brief    Get error status change interrupt flag
  * @rmtoll   RXISR    ESCF    FL_FSCAN_IsActiveFlag_ErrorChange
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_ErrorChange(FSCAN_Type *FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXISR, FSCAN_RXISR_ESCF_Msk) == (FSCAN_RXISR_ESCF_Msk));
}

/**
  * @brief    Clear error status change interrupt flag
  * @rmtoll   RXISR    ESCF    FL_FSCAN_ClearFlag_ErrorChange
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_ClearFlag_ErrorChange(FSCAN_Type *FSCANx)
{
    WRITE_REG(FSCANx->RXISR, FSCAN_RXISR_ESCF_Msk);
}

/**
  * @brief    Get error interrupt  flag
  * @rmtoll   RXISR    ERROR    FL_FSCAN_IsActiveFlag_Error
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_Error(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXISR, FSCAN_RXISR_ERROR_Msk) == (FSCAN_RXISR_ERROR_Msk));
}

/**
  * @brief    Clear error interrupt flag
  * @rmtoll   RXISR    ERROR    FL_FSCAN_ClearFlag_Error
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_ClearFlag_Error(FSCAN_Type* FSCANx)
{
    WRITE_REG(FSCANx->RXISR, FSCAN_RXISR_ERROR_Msk);
}

/**
  * @brief    Get receive FIFO not empty interrupt flag
  * @rmtoll   RXISR    RXNEMP    FL_FSCAN_IsActiveFlag_RXNotEmpty
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_RXNotEmpty(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXISR, FSCAN_RXISR_RXNEMP_Msk) == (FSCAN_RXISR_RXNEMP_Msk));
}

/**
  * @brief    Clear receive FIFO not empty interrupt flag
  * @rmtoll   RXISR    RXNEMP    FL_FSCAN_ClearFlag_RXNotEmpty
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_ClearFlag_RXNotEmpty(FSCAN_Type* FSCANx)
{
    WRITE_REG(FSCANx->RXISR, FSCAN_RXISR_RXNEMP_Msk);
}

/**
  * @brief    Get receive FIFO overflow interrupt flag
  * @rmtoll   RXISR    RXOFLW    FL_FSCAN_IsActiveFlag_RXOverflow
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_RXOverflow(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXISR, FSCAN_RXISR_RXOFLW_Msk) == (FSCAN_RXISR_RXOFLW_Msk));
}

/**
  * @brief    Clear  receive FIFO overflow interrupt flag
  * @rmtoll   RXISR    RXOFLW    FL_FSCAN_ClearFlag_RXOverflow
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_ClearFlag_RXOverflow(FSCAN_Type* FSCANx)
{
    WRITE_REG(FSCANx->RXISR, FSCAN_RXISR_RXOFLW_Msk);
}

/**
  * @brief    Get receive FIFO empty interrupt flag
  * @rmtoll   RXISR    RXUFLW    FL_FSCAN_IsActiveFlag_RXEmpty
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_RXUnderflow(FSCAN_Type *FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXISR, FSCAN_RXISR_RXUFLW_Msk) == (FSCAN_RXISR_RXUFLW_Msk));
}

/**
  * @brief    Clear receive FIFO underflow interrupt flag
  * @rmtoll   RXISR    RXUFLW    FL_FSCAN_ClearFlag_RXEmpty
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_ClearFlag_RXUnderflow(FSCAN_Type *FSCANx)
{
    WRITE_REG(FSCANx->RXISR, FSCAN_RXISR_RXUFLW_Msk);
}

/**
  * @brief    Get receive Ok interrupt flag
  * @rmtoll   RXISR    RXOK    FL_FSCAN_IsActiveFlag_RXOK
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_RXOK(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXISR, FSCAN_RXISR_RXOK_Msk) == (FSCAN_RXISR_RXOK_Msk));
}

/**
  * @brief    Clear receive OK interrupt flag
  * @rmtoll   RXISR    RXOK    FL_FSCAN_ClearFlag_CRXOK
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_ClearFlag_RXOK(FSCAN_Type *FSCANx)
{
    WRITE_REG(FSCANx->RXISR, FSCAN_RXISR_RXOK_Msk);
}

/**
  * @brief    Get arbitration lost interrupt flag 
  * @rmtoll   RXISR    ARBLST    FL_FSCAN_IsActiveFlag_ArbitrationLost
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_ArbitrationLost(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXISR, FSCAN_RXISR_ARBLST_Msk) == (FSCAN_RXISR_ARBLST_Msk));
}

/**
  * @brief    Clear arbitration lost interrupt flag
  * @rmtoll   RXISR    ARBLST    FL_FSCAN_ClearFlag_ArbitrationLost
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_ClearFlag_ArbitrationLost(FSCAN_Type* FSCANx)
{
    WRITE_REG(FSCANx->RXISR, FSCAN_RXISR_ARBLST_Msk);
}

/**
  * @brief    Bus off recovery interrupt enable 
  * @rmtoll   RXIER    BORFIE    FL_FSCAN_EnableIT_BusOffRecovery
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_EnableIT_BusOffRecovery(FSCAN_Type* FSCANx)
{
    SET_BIT(FSCANx->RXIER, FSCAN_RXIER_BORFIE_Msk);
}

/**
  * @brief    Bus off recovery  interrupt enable status 
  * @rmtoll   RXIER    BORFIE    FL_FSCAN_IsEnabledIT_BusOffRecovery
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsEnabledIT_BusOffRecovery(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXIER, FSCAN_RXIER_BORFIE_Msk) == FSCAN_RXIER_BORFIE_Msk);
}

/**
  * @brief    Bus off recovery  interrupt disable 
  * @rmtoll   RXIER    BORFIE    FL_FSCAN_DisableIT_BusOffRecovery
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_DisableIT_BusOffRecovery(FSCAN_Type* FSCANx)
{
    CLEAR_BIT(FSCANx->RXIER, FSCAN_RXIER_BORFIE_Msk);
}

/**
  * @brief    Wakeup interrupt enable 
  * @rmtoll   RXIER    WKUPIE    FL_FSCAN_EnableIT_Wakeup
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_EnableIT_Wakeup(FSCAN_Type* FSCANx)
{
    SET_BIT(FSCANx->RXIER, FSCAN_RXIER_WKUPIE_Msk);
}

/**
  * @brief    Wakeup  interrupt enable status 
  * @rmtoll   RXIER    WKUPIE    FL_FSCAN_IsEnabledIT_Wakeup
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsEnabledIT_Wakeup(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXIER, FSCAN_RXIER_WKUPIE_Msk) == FSCAN_RXIER_WKUPIE_Msk);
}

/**
  * @brief    Wakeup  interrupt disable 
  * @rmtoll   RXIER    WKUPIE    FL_FSCAN_DisableIT_Wakeup
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_DisableIT_Wakeup(FSCAN_Type* FSCANx)
{
    CLEAR_BIT(FSCANx->RXIER, FSCAN_RXIER_WKUPIE_Msk);
}

/**
  * @brief    Sleep interrupt enable 
  * @rmtoll   RXIER    SLPIE    FL_FSCAN_EnableIT_Sleep
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_EnableIT_Sleep(FSCAN_Type* FSCANx)
{
    SET_BIT(FSCANx->RXIER, FSCAN_RXIER_SLPIE_Msk);
}

/**
  * @brief    Sleep  interrupt enable status 
  * @rmtoll   RXIER    SLPIE    FL_FSCAN_IsEnabledIT_Sleep
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsEnabledIT_Sleep(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXIER, FSCAN_RXIER_SLPIE_Msk) == FSCAN_RXIER_SLPIE_Msk);
}

/**
  * @brief    Sleep  interrupt disable 
  * @rmtoll   RXIER    SLPIE    FL_FSCAN_DisableIT_Sleep
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_DisableIT_Sleep(FSCAN_Type* FSCANx)
{
    CLEAR_BIT(FSCANx->RXIER, FSCAN_RXIER_SLPIE_Msk);
}

/**
  * @brief    Error change interrupt enable 
  * @rmtoll   RXIER    EESCFIE    FL_FSCAN_EnableIT_ErrorChange
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_EnableIT_ErrorChange(FSCAN_Type* FSCANx)
{
    SET_BIT(FSCANx->RXIER, FSCAN_RXIER_EESCFIE_Msk);
}

/**
  * @brief    Get Error change  interrupt enable status 
  * @rmtoll   RXIER    EESCFIE    FL_FSCAN_IsEnabledIT_ErrorChange
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsEnabledIT_ErrorChange(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXIER, FSCAN_RXIER_EESCFIE_Msk) == FSCAN_RXIER_EESCFIE_Msk);
}

/**
  * @brief    Error change  interrupt disable 
  * @rmtoll   RXIER    EESCFIE    FL_FSCAN_DisableIT_ErrorChange
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_DisableIT_ErrorChange(FSCAN_Type* FSCANx)
{
    CLEAR_BIT(FSCANx->RXIER, FSCAN_RXIER_EESCFIE_Msk);
}

/**
  * @brief    Error interrupt enable
  * @rmtoll   RXIER    ERRORIE    FL_FSCAN_EnableIT_Error
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_EnableIT_Error(FSCAN_Type* FSCANx)
{
    SET_BIT(FSCANx->RXIER, FSCAN_RXIER_ERRORIE_Msk);
}

/**
  * @brief    Get error interrupt enable status
  * @rmtoll   RXIER    ERRORIE    FL_FSCAN_IsEnabledIT_Error
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsEnabledIT_Error(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXIER, FSCAN_RXIER_ERRORIE_Msk) == FSCAN_RXIER_ERRORIE_Msk);
}

/**
  * @brief    Error interrupt disable
  * @rmtoll   RXIER    ERRORIE    FL_FSCAN_DisableIT_Error
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_DisableIT_Error(FSCAN_Type* FSCANx)
{
    CLEAR_BIT(FSCANx->RXIER, FSCAN_RXIER_ERRORIE_Msk);
}

/**
  * @brief    Receive FIFO not empty interrupt enable
  * @rmtoll   RXIER    RXNEMPIE    FL_FSCAN_EnableIT_RXNotEmpty
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_EnableIT_RXNotEmpty(FSCAN_Type* FSCANx)
{
    SET_BIT(FSCANx->RXIER, FSCAN_RXIER_RXNEMPIE_Msk);
}

/**
  * @brief    Get receive FIFO not empty interrupt enable status
  * @rmtoll   RXIER    RXNEMPIE    FL_FSCAN_IsEnabledIT_RXNotEmpty
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsEnabledIT_RXNotEmpty(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXIER, FSCAN_RXIER_RXNEMPIE_Msk) == FSCAN_RXIER_RXNEMPIE_Msk);
}

/**
  * @brief    Receive FIFO not empty interrupt disable
  * @rmtoll   RXIER    RXNEMPIE    FL_FSCAN_DisableIT_RXNotEmpty
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_DisableIT_RXNotEmpty(FSCAN_Type* FSCANx)
{
    CLEAR_BIT(FSCANx->RXIER, FSCAN_RXIER_RXNEMPIE_Msk);
}

/**
  * @brief    Receive FIFO overflow interrupt ennable
  * @rmtoll   RXIER    RXOFLWIE    FL_FSCAN_EnableIT_RXOverflow
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_EnableIT_RXOverflow(FSCAN_Type* FSCANx)
{
    SET_BIT(FSCANx->RXIER, FSCAN_RXIER_RXOFLWIE_Msk);
}

/**
  * @brief    Get receive FIFO overflow interrupt enable status
  * @rmtoll   RXIER    RXOFLWIE    FL_FSCAN_IsEnabledIT_RXOverflow
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsEnabledIT_RXOverflow(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXIER, FSCAN_RXIER_RXOFLWIE_Msk) == FSCAN_RXIER_RXOFLWIE_Msk);
}

/**
  * @brief    Receive FIFO overflow interrupt disable
  * @rmtoll   RXIER    RXOFLWIE    FL_FSCAN_DisableIT_RXOverflow
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_DisableIT_RXOverflow(FSCAN_Type* FSCANx)
{
    CLEAR_BIT(FSCANx->RXIER, FSCAN_RXIER_RXOFLWIE_Msk);
}

/**
  * @brief    Receive FIFO empty interrupt enable 
  * @rmtoll   RXIER    RXUFLWIE    FL_FSCAN_EnableIT_RXEmpty
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_EnableIT_RXUnderflow(FSCAN_Type *FSCANx)
{
    SET_BIT(FSCANx->RXIER, FSCAN_RXIER_RXUFLWIE_Msk);
}

/**
  * @brief    Get receive FIFO empty interrupt enable status
  * @rmtoll   RXIER    RXUFLWIE    FL_FSCAN_IsEnabledIT_RXEmpty
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsEnabledIT_RXUnderflow(FSCAN_Type *FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXIER, FSCAN_RXIER_RXUFLWIE_Msk) == FSCAN_RXIER_RXUFLWIE_Msk);
}

/**
  * @brief    Receive FIFO empty interrupt disable 
  * @rmtoll   RXIER    RXUFLWIE    FL_FSCAN_DisableIT_RXEmpty
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_DisableIT_RXUnderflow(FSCAN_Type *FSCANx)
{
    CLEAR_BIT(FSCANx->RXIER, FSCAN_RXIER_RXUFLWIE_Msk);
}

/**
  * @brief    Receive OK interrupt enable
  * @rmtoll   RXIER    RXOKIE    FL_FSCAN_EnableIT_RXOK
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_EnableIT_RXOK(FSCAN_Type* FSCANx)
{
    SET_BIT(FSCANx->RXIER, FSCAN_RXIER_RXOKIE_Msk);
}

/**
  * @brief    Get receive OK interrupt enable
  * @rmtoll   RXIER    RXOKIE    FL_FSCAN_IsEnabledIT_RXOK
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsEnabledIT_RXOK(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXIER, FSCAN_RXIER_RXOKIE_Msk) == FSCAN_RXIER_RXOKIE_Msk);
}

/**
  * @brief    Receive OK interrupt disable
  * @rmtoll   RXIER    RXOKIE    FL_FSCAN_DisableIT_RXOK
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_DisableIT_RXOK(FSCAN_Type* FSCANx)
{
    CLEAR_BIT(FSCANx->RXIER, FSCAN_RXIER_RXOKIE_Msk);
}

/**
  * @brief    Arbitration lost interrupt enable
  * @rmtoll   RXIER    ARBLSTIE    FL_FSCAN_EnableIT_ArbitrationLost
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_EnableIT_ArbitrationLost(FSCAN_Type* FSCANx)
{
    SET_BIT(FSCANx->RXIER, FSCAN_RXIER_ARBLSTIE_Msk);
}

/**
  * @brief    Get arbitration lost interrupt enable
  * @rmtoll   RXIER    ARBLSTIE    FL_FSCAN_IsEnabledIT_ArbitrationLost
  * @param    FSCAN FSCAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsEnabledIT_ArbitrationLost(FSCAN_Type* FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXIER, FSCAN_RXIER_ARBLSTIE_Msk) == FSCAN_RXIER_ARBLSTIE_Msk);
}

/**
  * @brief    Arbitration lost interrupt disable
  * @rmtoll   RXIER    ARBLSTIE    FL_FSCAN_DisableIT_ArbitrationLost
  * @param    FSCAN FSCAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_DisableIT_ArbitrationLost(FSCAN_Type* FSCANx)
{
    CLEAR_BIT(FSCANx->RXIER, FSCAN_RXIER_ARBLSTIE_Msk);
}

/**
  * @brief    Set Tx abort request
  * @rmtoll   TXBCR    TXAR    FL_FSCAN_SetTXAbortRequest
  * @param    FSCAN FSCAN instance
  * @param    buffer This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_TX_ABORT_NONE
  *           @arg @ref FL_FSCAN_TX_ABORT_BUFFER_0
  *           @arg @ref FL_FSCAN_TX_ABORT_BUFFER_1
  *           @arg @ref FL_FSCAN_TX_ABORT_BUFFER_0AND1
  *           @arg @ref FL_FSCAN_TX_ABORT_BUFFER_2
  *           @arg @ref FL_FSCAN_TX_ABORT_BUFFER_0AND2
  *           @arg @ref FL_FSCAN_TX_ABORT_BUFFER_1AND2
  *           @arg @ref FL_FSCAN_TX_ABORT_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_SetTXAbortRequest(FSCAN_Type *FSCANx, uint32_t bufferX)
{
    MODIFY_REG(FSCANx->TXBCR, FSCAN_TXBCR_TXAR_Msk, bufferX);
}

/**
  * @brief    Get TX abort request
  * @rmtoll   TXBCR    TXAR    FL_FSCAN_GetTXAbortRequest
  * @param    FSCAN FSCAN instance
  * @retval   Returned value fscan be one of the following values:
  *           @arg @ref FL_FSCAN_TX_ABORT_NONE
  *           @arg @ref FL_FSCAN_TX_ABORT_BUFFER_0
  *           @arg @ref FL_FSCAN_TX_ABORT_BUFFER_1
  *           @arg @ref FL_FSCAN_TX_ABORT_BUFFER_0AND1
  *           @arg @ref FL_FSCAN_TX_ABORT_BUFFER_2
  *           @arg @ref FL_FSCAN_TX_ABORT_BUFFER_0AND2
  *           @arg @ref FL_FSCAN_TX_ABORT_BUFFER_1AND2
  *           @arg @ref FL_FSCAN_TX_ABORT_ALL
  */
__STATIC_INLINE uint32_t FL_FSCAN_GetTXAbortRequest(FSCAN_Type *FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->TXBCR, FSCAN_TXBCR_TXAR_Msk));
}

/**
  * @brief    TX buffer empty interrupt enable
  * @rmtoll   TXBCR    TXIE    FL_FSCAN_EnableIT_TXBufferEmpty
  * @param    FSCAN FSCAN instance
  * @param    bufferX This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_BUFFER0
  *           @arg @ref FL_FSCAN_BUFFER1
  *           @arg @ref FL_FSCAN_BUFFER2
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_EnableIT_TXBufferEmpty(FSCAN_Type *FSCANx, uint32_t bufferX)
{
    SET_BIT(FSCANx->TXBCR, ((bufferX & 0x7U) << 0x0U));
}

/**
  * @brief    Get TX buffer empty interrupt enable status
  * @rmtoll   TXBCR    TXIE    FL_FSCAN_IsEnabledIT_TXBufferEmpty
  * @param    FSCAN FSCAN instance
  * @param    bufferX This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_BUFFER0
  *           @arg @ref FL_FSCAN_BUFFER1
  *           @arg @ref FL_FSCAN_BUFFER2
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsEnabledIT_TXBufferEmpty(FSCAN_Type *FSCANx, uint32_t bufferX)
{
    return (uint32_t)(READ_BIT(FSCANx->TXBCR, ((bufferX & 0x7U) << 0x0U)) == ((bufferX & 0x7U) << 0x0U));
}

/**
  * @brief    TX buffer empty interrupt disable
  * @rmtoll   TXBCR    TXIE    FL_FSCAN_DisableIT_TXBufferEmpty
  * @param    FSCAN FSCAN instance
  * @param    bufferX This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_BUFFER0
  *           @arg @ref FL_FSCAN_BUFFER1
  *           @arg @ref FL_FSCAN_BUFFER2
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_DisableIT_TXBufferEmpty(FSCAN_Type *FSCANx, uint32_t bufferX)
{
    CLEAR_BIT(FSCANx->TXBCR, ((bufferX & 0x7U) << 0x0U));
}

/**
  * @brief    Get TX result flag
  * @rmtoll   TXBSR    TXRF    FL_FSCAN_GetTXRsultFlag
  * @param    FSCAN FSCAN instance
  * @param    bufferX This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_BUFFER0
  *           @arg @ref FL_FSCAN_BUFFER1
  *           @arg @ref FL_FSCAN_BUFFER2
  * @retval   Returned value fscan be one of the following values:
  *           @arg @ref FL_FSCAN_TX_RESULT_NONE
  *           @arg @ref FL_FSCAN_TX_RESULT_ABORT
  *           @arg @ref FL_FSCAN_TX_RESULT_OK_NOABORT
  *           @arg @ref FL_FSCAN_TX_RESULT_OK_ABORT
  */
__STATIC_INLINE uint32_t FL_FSCAN_GetTXRsultFlag(FSCAN_Type *FSCANx, uint32_t bufferX)
{
    if(bufferX == FL_FSCAN_BUFFER0)
    {
        return (uint32_t)(READ_BIT(FSCANx->TXBSR, (FSCAN_TXBSR_TXRF_Msk << 0U)));
    }
    else
    {
        return (uint32_t)(READ_BIT(FSCANx->TXBSR, (FSCAN_TXBSR_TXRF_Msk << bufferX)));
    }
}

/**
  * @brief    Get TX buffer status
  * @rmtoll   TXBSR    TXS    FL_FSCAN_GetTXBufferStatus
  * @param    FSCAN FSCAN instance
  * @retval   Returned value fscan be one of the following values:
  *           @arg @ref FL_FSCAN_TX_BUFFER_ALL_IDLE
  *           @arg @ref FL_FSCAN_TX_BUFFER_0_BUSY
  *           @arg @ref FL_FSCAN_TX_BUFFER_1_BUSY
  *           @arg @ref FL_FSCAN_TX_BUFFER_0AND1_BUSY
  *           @arg @ref FL_FSCAN_TX_BUFFER_2_BUSY
  *           @arg @ref FL_FSCAN_TX_BUFFER_0AND2_BUSY
  *           @arg @ref FL_FSCAN_TX_BUFFER_1AND2_BUSY
  *           @arg @ref FL_FSCAN_TX_BUFFER_ALL_BUSY
  */
__STATIC_INLINE uint32_t FL_FSCAN_GetTXBufferStatus(FSCAN_Type *FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->TXBSR, FSCAN_TXBSR_TXS_Msk));
}

/**
  * @brief    Clear TX buffer empty flag
  * @rmtoll   TXBSR    TXE    FL_FSCAN_ClearFlag_TXBufferEmpty
  * @param    FSCAN FSCAN instance
  * @param    bufferX This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_BUFFER0
  *           @arg @ref FL_FSCAN_BUFFER1
  *           @arg @ref FL_FSCAN_BUFFER2
  */
__STATIC_INLINE void FL_FSCAN_ClearFlag_TXBufferEmpty(FSCAN_Type *FSCANx, uint32_t bufferX)
{
    WRITE_REG(FSCANx->TXBSR, (bufferX & 0x07U) << 0x0U);
}

/**
  * @brief    Get TX buffer empty flag
  * @rmtoll   TXBSR    TXE    FL_FSCAN_IsActiveFlag_TXBuffer1Empty
  * @param    FSCAN FSCAN instance
  *           @arg @ref FL_FSCAN_BUFFER0
  *           @arg @ref FL_FSCAN_BUFFER1
  *           @arg @ref FL_FSCAN_BUFFER2
  */
__STATIC_INLINE uint32_t FL_FSCAN_IsActiveFlag_TXBufferEmpty(FSCAN_Type *FSCANx, uint32_t bufferX)
{
    return (uint32_t)(READ_BIT(FSCANx->TXBSR, ((bufferX & 0x07U) << 0x0U)) == ((bufferX & 0x07) << 0x0U));
}

/**
  * @brief    Set TXFIFO message identifier code
  * @rmtoll   TXBIDR    IDR    FL_FSCAN_WriteTXMessageID
  * @param    FSCAN FSCAN instance
  * @param    id
  * @param    bufferX This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_BUFFER0
  *           @arg @ref FL_FSCAN_BUFFER1
  *           @arg @ref FL_FSCAN_BUFFER2
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_WriteTXMessageID(FSCAN_Type *FSCANx, uint32_t id, uint32_t bufferX)
{
    if(bufferX == FL_FSCAN_BUFFER2)
    {
        MODIFY_REG(*(&(FSCANx->TXB0IDR) + 4 * (bufferX - 2)), FSCAN_TXBIDR_IDR_Msk, (id << FSCAN_TXBIDR_IDR_Pos));
    }
    else
    {
        MODIFY_REG(*(&(FSCANx->TXB0IDR) + 4 * (bufferX - 1)), FSCAN_TXBIDR_IDR_Msk, (id << FSCAN_TXBIDR_IDR_Pos));
    }
}

/**
  * @brief    Get TXFIFO message identifier code
  * @rmtoll   TXBIDR    IDR    FL_FSCAN_ReadTXMessageID
  * @param    FSCAN FSCAN instance
  * @param    bufferX This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_BUFFER0
  *           @arg @ref FL_FSCAN_BUFFER1
  *           @arg @ref FL_FSCAN_BUFFER2
  * @retval
  */
__STATIC_INLINE uint32_t FL_FSCAN_ReadTXMessageID(FSCAN_Type *FSCANx, uint32_t bufferX)
{
    if(bufferX == FL_FSCAN_BUFFER2)
    {
        return (uint32_t)(READ_BIT(*(&(FSCANx->TXB0IDR) + 4 * (bufferX - 2)), FSCAN_TXBIDR_IDR_Msk) >> FSCAN_TXBIDR_IDR_Pos);
    }
    else
    {
        return (uint32_t)(READ_BIT(*(&(FSCANx->TXB0IDR) + 4 * (bufferX - 1)), FSCAN_TXBIDR_IDR_Msk) >> FSCAN_TXBIDR_IDR_Pos);
    }
}

/**
  * @brief    Set TXFIFO data length code
  * @rmtoll   TXBDLCR    DLC    FL_FSCAN_WriteTXMessageLength
  * @param    FSCAN FSCAN instance
  * @param    length
  * @param    bufferX This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_BUFFER0
  *           @arg @ref FL_FSCAN_BUFFER1
  *           @arg @ref FL_FSCAN_BUFFER2
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_WriteTXMessageLength(FSCAN_Type *FSCANx, uint32_t length, uint32_t bufferX)
{
    if(bufferX == FL_FSCAN_BUFFER2)
    {
        MODIFY_REG(*(&(FSCANx->TXB0DLCR) + 4 * (bufferX - 2)), FSCAN_TXBDLCR_DLC_Msk, (length << FSCAN_TXBDLCR_DLC_Pos));
    }
    else
    {
        MODIFY_REG(*(&(FSCANx->TXB0DLCR) + 4 * (bufferX - 1)), FSCAN_TXBDLCR_DLC_Msk, (length << FSCAN_TXBDLCR_DLC_Pos));
    }
}

/**
  * @brief    Get TXFIFO data length code
  * @rmtoll   TXBDLCR    DLC    FL_FSCAN_ReadTXMessageLength
  * @param    FSCAN FSCAN instance
  * @param    bufferX This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_BUFFER0
  *           @arg @ref FL_FSCAN_BUFFER1
  *           @arg @ref FL_FSCAN_BUFFER2
  * @retval
  */
__STATIC_INLINE uint32_t FL_FSCAN_ReadTXMessageLength(FSCAN_Type *FSCANx, uint32_t bufferX)
{
    if(bufferX == FL_FSCAN_BUFFER2)
    {
        return (uint32_t)(READ_BIT(*(&(FSCANx->TXB0DLCR) + 4 * (bufferX - 2)), FSCAN_TXBDLCR_DLC_Msk) >> FSCAN_TXBDLCR_DLC_Pos);
    }
    else
    {
        return (uint32_t)(READ_BIT(*(&(FSCANx->TXB0DLCR) + 4 * (bufferX - 1)), FSCAN_TXBDLCR_DLC_Msk) >> FSCAN_TXBDLCR_DLC_Pos);
    }
}

/**
  * @brief    Set TXFIFO data word1
  * @rmtoll   TXBDW1R    DB    FL_FSCAN_WriteTXMessageWord1
  * @param    FSCAN FSCAN instance
  * @param    word
  * @param    bufferX This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_BUFFER0
  *           @arg @ref FL_FSCAN_BUFFER1
  *           @arg @ref FL_FSCAN_BUFFER2
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_WriteTXMessageWord1(FSCAN_Type *FSCANx, uint32_t word, uint32_t bufferX)
{
    if(bufferX == FL_FSCAN_BUFFER2)
    {
        MODIFY_REG(*(&(FSCANx->TXB0DW1R) + 4 * (bufferX - 2)), FSCAN_TXBDW1R_DB_Msk, (word << FSCAN_TXBDW1R_DB_Pos));
    }
    else
    {
        MODIFY_REG(*(&(FSCANx->TXB0DW1R) + 4 * (bufferX - 1)), FSCAN_TXBDW1R_DB_Msk, (word << FSCAN_TXBDW1R_DB_Pos));
    }
}

/**
  * @brief    Get TXFIFO data word1
  * @rmtoll   TXBDW1R    DB    FL_FSCAN_ReadTXMessageWord1
  * @param    FSCAN FSCAN instance
  * @param    bufferX This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_BUFFER0
  *           @arg @ref FL_FSCAN_BUFFER1
  *           @arg @ref FL_FSCAN_BUFFER2
  * @retval
  */
__STATIC_INLINE uint32_t FL_FSCAN_ReadTXMessageWord1(FSCAN_Type *FSCANx, uint32_t bufferX)
{
    if(bufferX == FL_FSCAN_BUFFER2)
    {
        return (uint32_t)(READ_BIT(*(&(FSCANx->TXB0DW1R) + 4 * (bufferX - 2)), FSCAN_TXBDW1R_DB_Msk) >> FSCAN_TXBDW1R_DB_Pos);
    }
    else
    {
        return (uint32_t)(READ_BIT(*(&(FSCANx->TXB0DW1R) + 4 * (bufferX - 1)), FSCAN_TXBDW1R_DB_Msk) >> FSCAN_TXBDW1R_DB_Pos);
    }
}

/**
  * @brief    Set TXFIFO data word2
  * @rmtoll   TXBDW2R    DB    FL_FSCAN_WriteTXMessageWord2
  * @param    FSCAN FSCAN instance
  * @param    word
  * @param    bufferX This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_BUFFER0
  *           @arg @ref FL_FSCAN_BUFFER1
  *           @arg @ref FL_FSCAN_BUFFER2
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_WriteTXMessageWord2(FSCAN_Type *FSCANx, uint32_t word, uint32_t bufferX)
{
    if(bufferX == FL_FSCAN_BUFFER2)
    {
        MODIFY_REG(*(&(FSCANx->TXB0DW2R) + 4 * (bufferX - 2)), FSCAN_TXBDW2R_DB_Msk, (word << FSCAN_TXBDW2R_DB_Pos));
    }
    else
    {
        MODIFY_REG(*(&(FSCANx->TXB0DW2R) + 4 * (bufferX - 1)), FSCAN_TXBDW2R_DB_Msk, (word << FSCAN_TXBDW2R_DB_Pos));
    }
}

/**
  * @brief    Get TXFIFO data word2
  * @rmtoll   TXBDW2R    DB    FL_FSCAN_ReadTXMessageWord2
  * @param    FSCAN FSCAN instance
  * @param    bufferX This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_BUFFER0
  *           @arg @ref FL_FSCAN_BUFFER1
  *           @arg @ref FL_FSCAN_BUFFER2
  * @retval
  */
__STATIC_INLINE uint32_t FL_FSCAN_ReadTXMessageWord2(FSCAN_Type *FSCANx, uint32_t bufferX)
{
    if(bufferX == FL_FSCAN_BUFFER2)
    {
        return (uint32_t)(READ_BIT(*(&(FSCANx->TXB0DW2R) + 4 * (bufferX - 2)), FSCAN_TXBDW2R_DB_Msk) >> FSCAN_TXBDW2R_DB_Pos);
    }
    else
    {
        return (uint32_t)(READ_BIT(*(&(FSCANx->TXB0DW2R) + 4 * (bufferX - 1)), FSCAN_TXBDW2R_DB_Msk) >> FSCAN_TXBDW2R_DB_Pos);
    }
}

/**
  * @brief    Set RXFIFO message identifier code
  * @rmtoll   RXFIDR    IDR    FL_FSCAN_WriteRXMessageID
  * @param    FSCAN FSCAN instance
  * @param    id
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_WriteRXMessageID(FSCAN_Type *FSCANx, uint32_t id)
{
    MODIFY_REG(FSCANx->RXFIDR, FSCAN_RXFIDR_IDR_Msk, (id << FSCAN_RXFIDR_IDR_Pos));
}

/**
  * @brief    Get RXFIFO message identifier code
  * @rmtoll   RXFIDR    IDR    FL_FSCAN_ReadRXMessageID
  * @param    FSCAN FSCAN instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_FSCAN_ReadRXMessageID(FSCAN_Type *FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXFIDR, FSCAN_RXFIDR_IDR_Msk) >> FSCAN_RXFIDR_IDR_Pos);
}

/**
  * @brief    Set RXFIFO data length code
  * @rmtoll   RXFDLCR    DLC    FL_FSCAN_WriteRXMessageLength
  * @param    FSCAN FSCAN instance
  * @param    length
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_WriteRXMessageLength(FSCAN_Type *FSCANx, uint32_t length)
{
    MODIFY_REG(FSCANx->RXFDLCR, FSCAN_RXFDLCR_DLC_Msk, (length << FSCAN_RXFDLCR_DLC_Pos));
}

/**
  * @brief    Get RXFIFO data length code
  * @rmtoll   RXFDLCR    DLC    FL_FSCAN_ReadRXMessageLength
  * @param    FSCAN FSCAN instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_FSCAN_ReadRXMessageLength(FSCAN_Type *FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXFDLCR, FSCAN_RXFDLCR_DLC_Msk) >> FSCAN_RXFDLCR_DLC_Pos);
}

/**
  * @brief    Set RXFIFO data word1
  * @rmtoll   RXFDW1R    DB    FL_FSCAN_WriteRXMessageWord1
  * @param    FSCAN FSCAN instance
  * @param    word
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_WriteRXMessageWord1(FSCAN_Type *FSCANx, uint32_t word)
{
    MODIFY_REG(FSCANx->RXFDW1R, FSCAN_RXFDW1R_DB_Msk, (word << FSCAN_RXFDW1R_DB_Pos));
}

/**
  * @brief    Get RXFIFO data word1
  * @rmtoll   RXFDW1R    DB    FL_FSCAN_ReadRXMessageWord1
  * @param    FSCAN FSCAN instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_FSCAN_ReadRXMessageWord1(FSCAN_Type *FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXFDW1R, FSCAN_RXFDW1R_DB_Msk) >> FSCAN_RXFDW1R_DB_Pos);
}

/**
  * @brief    Set RXFIFO data word2
  * @rmtoll   RXFDW2R    DB    FL_FSCAN_WriteRXMessageWord2
  * @param    FSCAN FSCAN instance
  * @param    word
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_WriteRXMessageWord2(FSCAN_Type *FSCANx, uint32_t word)
{
    MODIFY_REG(FSCANx->RXFDW2R, FSCAN_RXFDW2R_DB_Msk, (word << FSCAN_RXFDW2R_DB_Pos));
}

/**
  * @brief    Get RXFIFO data word2
  * @rmtoll   RXFDW2R    DB    FL_FSCAN_ReadRXMessageWord2
  * @param    FSCAN FSCAN instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_FSCAN_ReadRXMessageWord2(FSCAN_Type *FSCANx)
{
    return (uint32_t)(READ_BIT(FSCANx->RXFDW2R, FSCAN_RXFDW2R_DB_Msk) >> FSCAN_RXFDW2R_DB_Pos);
}

/**
  * @brief    Acceptance filter 4 enable
  * @rmtoll   AFR    MSKM    FL_FSCAN_Filter_SetMaskMode
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    mode This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_MASKMODE_MASK
  *           @arg @ref FL_FSCAN_MASKMODE_ID
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_Filter_SetMaskMode(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t mode)
{
    MODIFY_REG(FSCANx->AFCFGR, (FSCAN_AFCFGR_MSKM_Msk << filterX), (mode << filterX));
}

/**
  * @brief    Acceptance filter 4 enable
  * @rmtoll   AFR    MSKM    FL_FSCAN_Filter_GetMaskMode
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    mode This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_MASKMODE_MASK
  *           @arg @ref FL_FSCAN_MASKMODE_ID
  * @retval   None
  */
__STATIC_INLINE uint32_t FL_FSCAN_Filter_GetMaskMode(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)((READ_BIT(FSCANx->AFCFGR, (FSCAN_AFCFGR_MSKM_Msk << filterX))) >> filterX);
}


/**
  * @brief    Acceptance filter 4 enable
  * @rmtoll   AFR    FSC    FL_FSCAN_Filter_SetIDMode
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    mode This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_IDMODE_32BIT
  *           @arg @ref FL_FSCAN_IDMODE_16BIT
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_Filter_SetIDMode(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t mode)
{
    MODIFY_REG(FSCANx->AFCFGR, (FSCAN_AFCFGR_FSC_Msk << filterX), (mode << filterX));
}

/**
  * @brief    Acceptance filter 4 enable
  * @rmtoll   AFR    FSC    FL_FSCAN_Filter_GetIDMode
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    mode This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_MASKMODE_MASK
  *           @arg @ref FL_FSCAN_MASKMODE_ID
  * @retval   None
  */
__STATIC_INLINE uint32_t FL_FSCAN_Filter_GetIDMode(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)((READ_BIT(FSCANx->AFCFGR, (FSCAN_AFCFGR_FSC_Msk << filterX))) >> filterX);
}


/**
  * @brief    Acceptance filter 4 enable
  * @rmtoll   AFR    UAF    FL_FSCAN_Filter_Enable
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_Filter_Enable(FSCAN_Type *FSCANx, uint32_t filterX)
{
    SET_BIT(FSCANx->AFCR, FSCAN_AFCR_UAF_Msk << filterX);
}

/**
  * @brief    Get acceptance filter 4 enable status
  * @rmtoll   AFR    UAF    FL_FSCAN_Filter_IsEnabled
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_Filter_IsEnabled(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(FSCANx->AFCR, ((FSCAN_AFCR_UAF_Msk << filterX) & 0xffff)) == ((FSCAN_AFCR_UAF_Msk << filterX) & 0xffff));
}

/**
  * @brief    Acceptance filter 4 disable
  * @rmtoll   AFR    UAF    FL_FSCAN_Filter_Disable
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_Filter_Disable(FSCAN_Type *FSCANx, uint32_t filterX)
{
    CLEAR_BIT(FSCANx->AFCR, ((FSCAN_AFCR_UAF_Msk << filterX) & 0xffff));
}
/**
  * @brief    Enable RTR participate filter compare
  * @rmtoll   AFMR    AMRTR    FL_FSCAN_FilterEXT_EnableRTRCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterEXT_EnableRTRCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    SET_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMR_AMRTR_Msk);
}

/**
  * @brief    Disable RTR participate filter compare
  * @rmtoll   AFMR    AMRTR    FL_FSCAN_FilterEXT_DisableRTRCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   Returned value fscan be one of the following values:
  */
__STATIC_INLINE void FL_FSCAN_FilterEXT_DisableRTRCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    CLEAR_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMR_AMRTR_Msk);
}

/**
  * @brief    Get RTR participate filter compare Enable Status
  * @rmtoll   AFMR    AMRTR    FL_FSCAN_FilterEXT_IsEnabledRTRCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   None
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterEXT_IsEnabledRTRCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMR_AMRTR_Msk) == FSCAN_AFMR_AMRTR_Msk);
}

/**
  * @brief    Set ID low 18bit participate filter compare
  * @rmtoll   AFMR    AMID18    FL_FSCAN_FilterEXT_WriteEXTIDCompareMask
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    id18
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterEXT_WriteEXTIDCompareMask(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t id18)
{
    MODIFY_REG(*(&(FSCANx->AFMR0) + 2 * filterX), (0x3ffffU << FSCAN_AFMR_AMID18_Pos), (id18 << FSCAN_AFMR_AMID18_Pos));
}

/**
  * @brief    Get ID low 18bit participate filter compare
  * @rmtoll   AFMR    AMID18    FL_FSCAN_FilterEXT_ReadEXTIDCompareMask
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterEXT_ReadEXTIDCompareMask(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), (0x3ffffU << FSCAN_AFMR_AMID18_Pos)) >> FSCAN_AFMR_AMID18_Pos);
}

/**
  * @brief    Set EXTID  high 3bit participate filter compare
  * @rmtoll   AFMR    AMID3    FL_FSCAN_FilterSTD1_WriteEXTIDCompareMask
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    id18
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterSTD1_WriteEXTIDCompareMask(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t id3)
{
    MODIFY_REG(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMRSTD1_AMID3_Msk, (id3 << FSCAN_AFMRSTD1_AMID3_Pos));
}

/**
  * @brief
  * @rmtoll   AFMR    AMID3    FL_FSCAN_FilterSTD1_ReadEXTIDCompareMask
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterSTD1_ReadEXTIDCompareMask(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMRSTD1_AMID3_Msk) >> FSCAN_AFMRSTD1_AMID3_Pos);
}

/**
  * @brief
  * @rmtoll   AFMR    AMID3    FL_FSCAN_FilterSTD2_WriteEXTIDCompareMask
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    id18
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterSTD2_WriteEXTIDCompareMask(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t id3)
{
    MODIFY_REG(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMRSTD2_AMID3_Msk, (id3 << FSCAN_AFMRSTD2_AMID3_Pos));
}

/**
  * @brief
  * @rmtoll   AFMR    AMID3    FL_FSCAN_FilterSTD2_ReadEXTIDCompareMask
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterSTD2_ReadEXTIDCompareMask(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMRSTD2_AMID3_Msk) >> FSCAN_AFMRSTD2_AMID3_Pos);
}

/**
  * @brief    Enable IDE participate filter compare
  * @rmtoll   AFMR    AMIDE    FL_FSCAN_FilterEXT_EnableIDECompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterEXT_EnableIDECompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    SET_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMR_AMIDE_Msk);
}

/**
  * @brief    Disable IDE participate filter compare
  * @rmtoll   AFMR    AMIDE    FL_FSCAN_FilterEXT_DisableIDECompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterEXT_DisableIDECompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    CLEAR_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMR_AMIDE_Msk);
}

/**
  * @brief    Get IDE participate filter compare Enable Status
  * @rmtoll   AFMR    AMIDE    FL_FSCAN_FilterEXT_IsEnabledIDECompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterEXT_IsEnabledIDECompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMR_AMIDE_Msk) == FSCAN_AFMR_AMIDE_Msk);
}

/**
  * @brief    Enable IDE participate filter compare
  * @rmtoll   AFMR    AMIDE    FL_FSCAN_FilterSTD1_EnableIDECompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterSTD1_EnableIDECompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    SET_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMRSTD1_AMIDE_Msk);
}

/**
  * @brief    Disable IDE participate filter compare
  * @rmtoll   AFMR    AMIDE    FL_FSCAN_FilterSTD1_DisableIDECompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterSTD1_DisableIDECompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    CLEAR_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMRSTD1_AMIDE_Msk);
}

/**
  * @brief    Get IDE participate filter compare Enable Status
  * @rmtoll   AFMR    AMIDE    FL_FSCAN_FilterSTD1_IsEnabledIDECompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterSTD1_IsEnabledIDECompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMRSTD1_AMIDE_Msk) == FSCAN_AFMRSTD1_AMIDE_Msk);
}

/**
  * @brief    Enable IDE participate filter compare
  * @rmtoll   AFMR    AMIDE    FL_FSCAN_FilterSTD2_EnableIDECompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterSTD2_EnableIDECompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    SET_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMRSTD2_AMIDE_Msk);
}

/**
  * @brief    Disable IDE participate filter compare
  * @rmtoll   AFMR    AMIDE    FL_FSCAN_FilterSTD2_DisableIDECompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterSTD2_DisableIDECompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    CLEAR_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMRSTD2_AMIDE_Msk);
}

/**
  * @brief    Get IDE participate filter compare Enable Status
  * @rmtoll   AFMR    AMIDE    FL_FSCAN_FilterSTD2_IsEnabledIDECompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterSTD2_IsEnabledIDECompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMRSTD2_AMIDE_Msk) == FSCAN_AFMRSTD2_AMIDE_Msk);
}

/**
  * @brief    Enable SRR participate filter compare
  * @rmtoll   AFMR    AMSRR    FL_FSCAN_Filter_EnableSRRCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterEXT_EnableSRRCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    SET_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMR_AMSRR_Msk);
}

/**
  * @brief    Disable SRR participate filter compare
  * @rmtoll   AFMR    AMSRR    FL_FSCAN_Filter_DisableSRRCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterEXT_DisableSRRCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    CLEAR_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMR_AMSRR_Msk);
}

/**
  * @brief    Get SRR participate filter compare Enable Status
  * @rmtoll   AFMR    AMSRR    FL_FSCAN_Filter_IsEnabledSRRCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterEXT_IsEnabledSRRCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMR_AMSRR_Msk) == FSCAN_AFMR_AMSRR_Msk);
}


/**
  * @brief    Enable SRR participate filter compare
  * @rmtoll   AFMR    AMSRR    FL_FSCAN_FilterSTD1_EnableSRRCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterSTD1_EnableSRRCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    SET_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMRSTD1_AMSRR_Msk);
}

/**
  * @brief    Disable SRR participate filter compare
  * @rmtoll   AFMR    AMSRR    FL_FSCAN_FilterSTD1_DisableSRRCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterSTD1_DisableSRRCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    CLEAR_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMRSTD1_AMSRR_Msk);
}

/**
  * @brief    Get SRR participate filter compare Enable Status
  * @rmtoll   AFMR    AMSRR    FL_FSCAN_FilterSTD1_IsEnabledSRRCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterSTD1_IsEnabledSRRCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMRSTD1_AMSRR_Msk) == FSCAN_AFMRSTD1_AMSRR_Msk);
}


/**
  * @brief    Enable SRR participate filter compare
  * @rmtoll   AFMR    AMSRR    FL_FSCAN_FilterSTD2_EnableSRRCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterSTD2_EnableSRRCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    SET_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMRSTD2_AMSRR_Msk);
}

/**
  * @brief    Disable SRR participate filter compare
  * @rmtoll   AFMR    AMSRR    FL_FSCAN_FilterSTD2_DisableSRRCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterSTD2_DisableSRRCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    CLEAR_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMRSTD2_AMSRR_Msk);
}

/**
  * @brief    Get SRR participate filter compare Enable Status
  * @rmtoll   AFMR    AMSRR    FL_FSCAN_FilterSTD2_IsEnabledSRRCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterSTD2_IsEnabledSRRCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(FSCANx->AFMR0) + 2 * filterX), FSCAN_AFMRSTD2_AMSRR_Msk) == FSCAN_AFMRSTD2_AMSRR_Msk);
}

/**
  * @brief    Set ID high 11bit participate filter compare
  * @rmtoll   AFMR    AMID11    FL_FSCAN_FilterEXT_WriteIDCompareMask
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    id11
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterEXT_WriteIDCompareMask(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t id11)
{
    MODIFY_REG(*((&(FSCANx->AFMR0)) + 2 * filterX), (0x7ffU << FSCAN_AFMR_AMID11_Pos), id11 << FSCAN_AFMR_AMID11_Pos);
}

/**
  * @brief    Get ID high 11bit participate filter compare
  * @rmtoll   AFMR    AMID11    FL_FSCAN_FilterEXT_ReadIDCompareMask
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterEXT_ReadIDCompareMask(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(FSCANx->AFMR0)) + 2 * filterX), (0x7ffU << FSCAN_AFMR_AMID11_Pos)) >> FSCAN_AFMR_AMID11_Pos);
}

/**
  * @brief    Set ID high 11bit participate filter compare
  * @rmtoll   AFMR    AMID11    FL_FSCAN_FilterSTD1_WriteIDCompareMask
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    id11
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterSTD1_WriteIDCompareMask(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t id11)
{
    MODIFY_REG(*((&(FSCANx->AFMR0)) + 2 * filterX), (0x7ffU << FSCAN_AFMRSTD1_AMID11_Pos), id11 << FSCAN_AFMRSTD1_AMID11_Pos);
}

/**
  * @brief    Get ID high 11bit participate filter compare
  * @rmtoll   AFMR    AMID11    FL_FSCAN_FilterSTD1_ReadIDCompareMask
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterSTD1_ReadIDCompareMask(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(FSCANx->AFMR0)) + 2 * filterX), (0x7ffU << FSCAN_AFMRSTD1_AMID11_Pos)) >> FSCAN_AFMRSTD1_AMID11_Pos);
}

/**
  * @brief    Set ID high 11bit participate filter compare
  * @rmtoll   AFMR    AMID11    FL_FSCAN_FilterSTD2_WriteIDCompareMask
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    id11
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterSTD2_WriteIDCompareMask(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t id11)
{
    MODIFY_REG(*((&(FSCANx->AFMR0)) + 2 * filterX), (0x7ffU << FSCAN_AFMRSTD2_AMID11_Pos), id11 << FSCAN_AFMRSTD2_AMID11_Pos);
}

/**
  * @brief    Get ID high 11bit participate filter compare
  * @rmtoll   AFMR    AMID11    FL_FSCAN_FilterSTD1_ReadIDCompareMask
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterSTD2_ReadIDCompareMask(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(FSCANx->AFMR0)) + 2 * filterX), (0x7ffU << FSCAN_AFMRSTD2_AMID11_Pos)) >> FSCAN_AFMRSTD2_AMID11_Pos);
}

/**
  * @brief    Set filter RTR
  * @rmtoll   AFIR    AIRTR    FL_FSCAN_FilterEXT_SetRTRCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    rtr This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_RTR_BIT_LOW
  *           @arg @ref FL_FSCAN_RTR_BIT_HIGH
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterEXT_SetRTRCompare(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t rtr)
{
    MODIFY_REG(*((&(FSCANx->AFIR0)) + 2 * filterX), FSCAN_AFIR_AIRTR_Msk, rtr);
}

/**
  * @brief    Get filter RTR
  * @rmtoll   AFIR    AIRTR    FL_FSCAN_FilterEXT_GetRTRCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   Returned value fscan be one of the following values:
  *           @arg @ref FL_FSCAN_RTR_BIT_LOW
  *           @arg @ref FL_FSCAN_RTR_BIT_HIGH
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterEXT_GetRTRCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(FSCANx->AFIR0)) + 2 * filterX), FSCAN_AFIR_AIRTR_Msk));
}

/**
  * @brief    Set filter ID[17:0]
  * @rmtoll   AFIR    AIID18    FL_FSCAN_FilterEXT_WriteEXTIDCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    id18
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterEXT_WriteEXTIDCompare(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t id18)
{
    MODIFY_REG(*(&(FSCANx->AFIR0) + 2 * filterX), (0x3ffffU << FSCAN_AFIR_AIID18_Pos), (id18 << FSCAN_AFIR_AIID18_Pos));
}

/**
  * @brief    Get filter ID[17:0]
  * @rmtoll   AFIR    AIID18    FL_FSCAN_FilterEXT_ReadEXTIDCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterEXT_ReadEXTIDCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(FSCANx->AFIR0) + 2 * filterX), (0x3ffffU << FSCAN_AFIR_AIID18_Pos)) >> FSCAN_AFIR_AIID18_Pos);
}


/**
  * @brief    Set filter ID[17:15]
  * @rmtoll   AFIR    AIID3    FL_FSCAN_FilterSTD1_WriteEXTIDCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    id18
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterSTD1_WriteEXTIDCompare(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t id3)
{
    MODIFY_REG(*(&(FSCANx->AFIR0) + 2 * filterX), FSCAN_AFIRSTD1_AIID3_Msk, (id3 << FSCAN_AFIRSTD1_AIID3_Pos));
}

/**
  * @brief    Get filter ID[17:15]
  * @rmtoll   AFIR    AIID3    FL_FSCAN_FilterSTD1_ReadEXTIDCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterSTD1_ReadEXTIDCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(FSCANx->AFIR0) + 2 * filterX), FSCAN_AFIRSTD1_AIID3_Msk) >> FSCAN_AFIRSTD1_AIID3_Pos);
}

/**
  * @brief    Set filter ID[17:15]
  * @rmtoll   AFIR    AIID3    FL_FSCAN_FilterSTD2_WriteEXTIDCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    id18
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterSTD2_WriteEXTIDCompare(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t id3)
{
    MODIFY_REG(*(&(FSCANx->AFIR0) + 2 * filterX), FSCAN_AFIRSTD2_AIID3_Msk, (id3 << FSCAN_AFIRSTD2_AIID3_Pos));
}

/**
  * @brief    Get filter ID[17:15]
  * @rmtoll   AFIR    AIID3    FL_FSCAN_FilterSTD2_ReadEXTIDCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterSTD2_ReadEXTIDCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(FSCANx->AFIR0) + 2 * filterX), FSCAN_AFIRSTD2_AIID3_Msk) >> FSCAN_AFIRSTD2_AIID3_Pos);
}
/**
  * @brief    Set filter IDE
  * @rmtoll   AFIR    AIIDE    FL_FSCAN_FilterEXT_SetIDECompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    ide This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_IDE_BIT_LOW
  *           @arg @ref FL_FSCAN_IDE_BIT_HIGH
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterEXT_SetIDECompare(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t ide)
{
    MODIFY_REG(*((&(FSCANx->AFIR0)) + 2 * filterX), FSCAN_AFIR_AIIDE_Msk, ide);
}

/**
  * @brief    Get filter IDE
  * @rmtoll   AFIR    AIIDE    FL_FSCAN_FilterEXT_GetIDECompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   Returned value fscan be one of the following values:
  *           @arg @ref FL_FSCAN_IDE_BIT_LOW
  *           @arg @ref FL_FSCAN_IDE_BIT_HIGH
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterEXT_GetIDECompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(FSCANx->AFIR0)) + 2 * filterX), FSCAN_AFIR_AIIDE_Msk));
}

/**
  * @brief    Set filter IDE
  * @rmtoll   AFIR    AIIDE    FL_FSCAN_FilterSTD1_SetIDECompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    ide This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_STD1IDE_BIT_LOW
  *           @arg @ref FL_FSCAN_STD1IDE_BIT_HIGH
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterSTD1_SetIDECompare(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t ide)
{
    MODIFY_REG(*((&(FSCANx->AFIR0)) + 2 * filterX), FSCAN_AFIRSTD1_AIIDE_Msk, ide);
}

/**
  * @brief    Get filter IDE
  * @rmtoll   AFIR    AIIDE    FL_FSCAN_FilterSTD1_GetIDECompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   Returned value fscan be one of the following values:
  *           @arg @ref FL_FSCAN_STD1IDE_BIT_LOW
  *           @arg @ref FL_FSCAN_STD1IDE_BIT_HIGH
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterSTD1_GetIDECompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(FSCANx->AFIR0)) + 2 * filterX), FSCAN_AFIRSTD1_AIIDE_Msk));
}

/**
  * @brief    Set filter IDE
  * @rmtoll   AFIR    AIIDE    FL_FSCAN_FilterSTD2_SetIDECompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    ide This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_STD2IDE_BIT_LOW
  *           @arg @ref FL_FSCAN_STD2IDE_BIT_HIGH
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterSTD2_SetIDECompare(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t ide)
{
    MODIFY_REG(*((&(FSCANx->AFIR0)) + 2 * filterX), FSCAN_AFIRSTD2_AIIDE_Msk, ide);
}

/**
  * @brief    Get filter IDE
  * @rmtoll   AFIR    AIIDE    FL_FSCAN_FilterSTD2_GetIDECompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   Returned value fscan be one of the following values:
  *           @arg @ref FL_FSCAN_STD2IDE_BIT_LOW
  *           @arg @ref FL_FSCAN_STD2IDE_BIT_HIGH
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterSTD2_GetIDECompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(FSCANx->AFIR0)) + 2 * filterX), FSCAN_AFIRSTD2_AIIDE_Msk));
}
/**
  * @brief    Set filter SRR
  * @rmtoll   AFIR    AISRR    FL_FSCAN_FilterEXT_SetSRRCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    srr This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_SRR_BIT_LOW
  *           @arg @ref FL_FSCAN_SRR_BIT_HIGH
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterEXT_SetSRRCompare(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t srr)
{
    MODIFY_REG(*((&(FSCANx->AFIR0)) + 2 * filterX), FSCAN_AFIR_AISRR_Msk, srr);
}

/**
  * @brief    Get filter SRR
  * @rmtoll   AFIR    AISRR    FL_FSCAN_FilterEXT_GetSRRCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   Returned value fscan be one of the following values:
  *           @arg @ref FL_FSCAN_SRR_BIT_LOW
  *           @arg @ref FL_FSCAN_SRR_BIT_HIGH
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterEXT_GetSRRCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(FSCANx->AFIR0)) + 2 * filterX), FSCAN_AFIR_AISRR_Msk));
}

/**
  * @brief    Set filter SRR
  * @rmtoll   AFIR    AISRR    FL_FSCAN_FilterSTD1_SetSRRCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    srr This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_STD1SRR_BIT_LOW
  *           @arg @ref FL_FSCAN_STD1SRR_BIT_HIGH
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterSTD1_SetSRRCompare(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t srr)
{
    MODIFY_REG(*((&(FSCANx->AFIR0)) + 2 * filterX), FSCAN_AFIRSTD1_AISRR_Msk, srr);
}

/**
  * @brief    Get filter SRR
  * @rmtoll   AFIR    AISRR    FL_FSCAN_FilterSTD1_GetSRRCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   Returned value fscan be one of the following values:
  *           @arg @ref FL_FSCAN_STD1SRR_BIT_LOW
  *           @arg @ref FL_FSCAN_STD1SRR_BIT_HIGH
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterSTD1_GetSRRCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(FSCANx->AFIR0)) + 2 * filterX), FSCAN_AFIRSTD1_AISRR_Msk));
}

/**
  * @brief    Set filter SRR
  * @rmtoll   AFIR    AISRR    FL_FSCAN_FilterSTD2_SetSRRCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    srr This parameter fscan be one of the following values:
  *           @arg @ref FL_FSCAN_STD2SRR_BIT_LOW
  *           @arg @ref FL_FSCAN_STD2SRR_BIT_HIGH
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterSTD2_SetSRRCompare(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t srr)
{
    MODIFY_REG(*((&(FSCANx->AFIR0)) + 2 * filterX), FSCAN_AFIRSTD2_AISRR_Msk, srr);
}

/**
  * @brief    Get filter SRR
  * @rmtoll   AFIR    AISRR    FL_FSCAN_FilterSTD2_GetSRRCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval   Returned value fscan be one of the following values:
  *           @arg @ref FL_FSCAN_STD2SRR_BIT_LOW
  *           @arg @ref FL_FSCAN_STD2SRR_BIT_HIGH
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterSTD2_GetSRRCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(FSCANx->AFIR0)) + 2 * filterX), FSCAN_AFIRSTD2_AISRR_Msk));
}
/**
  * @brief    Set filterID[28:18]
  * @rmtoll   AFIR    AIID11    FL_FSCAN_FilterEXT_WriteIDCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    id11
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterEXT_WriteIDCompare(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t id11)
{
    MODIFY_REG(*((&(FSCANx->AFIR0)) + 2 * filterX), FSCAN_AFIR_AIID11_Msk, id11 << FSCAN_AFIR_AIID11_Pos);
}

/**
  * @brief    Get filter ID[28:18]
  * @rmtoll   AFIR    AIID11    FL_FSCAN_FilterEXT_ReadIDCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterEXT_ReadIDCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(FSCANx->AFIR0)) + 2 * filterX), FSCAN_AFIR_AIID11_Msk) >> FSCAN_AFIR_AIID11_Pos);
}

/**
  * @brief    Set filterID[28:18]
  * @rmtoll   AFIR    AIID11    FL_FSCAN_FilterSTD1_WriteIDCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    id11
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterSTD1_WriteIDCompare(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t id11)
{
    MODIFY_REG(*((&(FSCANx->AFIR0)) + 2 * filterX), FSCAN_AFIRSTD1_AIID11_Msk, id11 << FSCAN_AFIRSTD1_AIID11_Pos);
}

/**
  * @brief    Get filter ID[28:18]
  * @rmtoll   AFIR    AIID11    FL_FSCAN_FilterSTD1_ReadIDCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterSTD1_ReadIDCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(FSCANx->AFIR0)) + 2 * filterX), FSCAN_AFIRSTD1_AIID11_Msk) >> FSCAN_AFIRSTD1_AIID11_Pos);
}

/**
  * @brief    Set filterID[28:18]
  * @rmtoll   AFIR    AIID11    FL_FSCAN_FilterSTD2_WriteIDCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @param    id11
  * @retval   None
  */
__STATIC_INLINE void FL_FSCAN_FilterSTD2_WriteIDCompare(FSCAN_Type *FSCANx, uint32_t filterX, uint32_t id11)
{
    MODIFY_REG(*((&(FSCANx->AFIR0)) + 2 * filterX), FSCAN_AFIRSTD2_AIID11_Msk, id11 << FSCAN_AFIRSTD2_AIID11_Pos);
}

/**
  * @brief    Get filter ID[28:18]
  * @rmtoll   AFIR    AIID11    FL_FSCAN_FilterSTD2_ReadIDCompare
  * @param    FSCAN FSCAN instance
  * @param    filterX This parameter fscan be one of the following values:
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
  * @retval
  */
__STATIC_INLINE uint32_t FL_FSCAN_FilterSTD2_ReadIDCompare(FSCAN_Type *FSCANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(FSCANx->AFIR0)) + 2 * filterX), FSCAN_AFIRSTD2_AIID11_Msk) >> FSCAN_AFIRSTD2_AIID11_Pos);
}
/**
  * @}
  */

/** @defgroup FSCAN_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_FSCAN_Init(FSCAN_Type *FSCANx, FL_FSCAN_InitTypeDef *FSCAN_InitStruct);
FL_ErrorStatus FL_FSCAN_FilterInit(FSCAN_Type *FSCANx, FL_FSCAN_FilterInitTypeDef *FSCAN_FilterInitStruct, uint32_t filterX);
void FL_FSCAN_StructInit(FL_FSCAN_InitTypeDef *FSCAN_InitStruct);
void FL_FSCAN_StructFilterInit(FL_FSCAN_FilterInitTypeDef *FSCAN_FilterInitStruct);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LF0XX_FL_FSCAN_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-04-07*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
