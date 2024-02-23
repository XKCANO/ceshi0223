/**
  *******************************************************************************************************
  * @file    fm33lf0xx_fl_rcc.h
  * @author  FMSH Application Team
  * @brief   Head file of CMU FL Module
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


/* Define to prevent recursive inclusion---------------------------------------------------------------*/
#ifndef __FM33LF0XX_FL_CMU_H
#define __FM33LF0XX_FL_CMU_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33lf0xx_fl_def.h"
/** @addtogroup FM33LF0XX_FL_Driver
  * @{
  */

/** @defgroup  CMU
  * @brief CMU FL driver
  * @{
  */

/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup CMU_FL_ES_INIT CMU Exported Init structures
  * @{
  */

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup CMU_FL_Exported_Constants CMU Exported Constants
  * @{
  */
#define    CMU_SYSCLKCR_SLP_ENEXTI_Pos                            (25U)
#define    CMU_SYSCLKCR_SLP_ENEXTI_Msk                            (0x1U << CMU_SYSCLKCR_SLP_ENEXTI_Pos)
#define    CMU_SYSCLKCR_SLP_ENEXTI                                CMU_SYSCLKCR_SLP_ENEXTI_Msk

#define    CMU_SYSCLKCR_APBPRES_Pos                               (16U)
#define    CMU_SYSCLKCR_APBPRES_Msk                               (0x7U << CMU_SYSCLKCR_APBPRES_Pos)
#define    CMU_SYSCLKCR_APBPRES                                   CMU_SYSCLKCR_APBPRES_Msk

#define    CMU_SYSCLKCR_AHBPRES_Pos                               (8U)
#define    CMU_SYSCLKCR_AHBPRES_Msk                               (0x7U << CMU_SYSCLKCR_AHBPRES_Pos)
#define    CMU_SYSCLKCR_AHBPRES                                   CMU_SYSCLKCR_AHBPRES_Msk

#define    CMU_SYSCLKCR_STCLKSEL_Pos                              (6U)
#define    CMU_SYSCLKCR_STCLKSEL_Msk                              (0x3U << CMU_SYSCLKCR_STCLKSEL_Pos)
#define    CMU_SYSCLKCR_STCLKSEL                                  CMU_SYSCLKCR_STCLKSEL_Msk

#define    CMU_SYSCLKCR_SYSCLKSEL_Pos                             (0U)
#define    CMU_SYSCLKCR_SYSCLKSEL_Msk                             (0x7U << CMU_SYSCLKCR_SYSCLKSEL_Pos)
#define    CMU_SYSCLKCR_SYSCLKSEL                                 CMU_SYSCLKCR_SYSCLKSEL_Msk

#define    CMU_RCHFCR_FSEL_Pos                                    (16U)
#define    CMU_RCHFCR_FSEL_Msk                                    (0xfU << CMU_RCHFCR_FSEL_Pos)
#define    CMU_RCHFCR_FSEL                                        CMU_RCHFCR_FSEL_Msk

#define    CMU_RCHFCR_EN_Pos                                      (0U)
#define    CMU_RCHFCR_EN_Msk                                      (0x1U << CMU_RCHFCR_EN_Pos)
#define    CMU_RCHFCR_EN                                          CMU_RCHFCR_EN_Msk

#define    CMU_RCHFTR_TRIM_Pos                                    (0U)
#define    CMU_RCHFTR_TRIM_Msk                                    (0xffU << CMU_RCHFTR_TRIM_Pos)
#define    CMU_RCHFTR_TRIM                                        CMU_RCHFTR_TRIM_Msk

#define    CMU_PLLCR_EN_Pos                                       (0U)
#define    CMU_PLLCR_EN_Msk                                       (0x1U << CMU_PLLCR_EN_Pos)
#define    CMU_PLLCR_EN                                           CMU_PLLCR_EN_Msk

#define    CMU_PLLCR_INSEL_Pos                                    (1U)
#define    CMU_PLLCR_INSEL_Msk                                    (0x3U << CMU_PLLCR_INSEL_Pos)
#define    CMU_PLLCR_INSEL                                        CMU_PLLCR_INSEL_Msk

#define    CMU_PLLCR_REFPRSC_Pos                                  (4U)
#define    CMU_PLLCR_REFPRSC_Msk                                  (0x7U << CMU_PLLCR_REFPRSC_Pos)
#define    CMU_PLLCR_REFPRSC                                      CMU_PLLCR_REFPRSC_Msk

#define    CMU_PLLCR_LOCKED_Pos                                   (7U)
#define    CMU_PLLCR_LOCKED_Msk                                   (0x1U << CMU_PLLCR_LOCKED_Pos)
#define    CMU_PLLCR_LOCKED                                       CMU_PLLCR_LOCKED_Msk

#define    CMU_PLLCR_DB_Pos                                       (16U)
#define    CMU_PLLCR_DB_Msk                                       (0x3ffU << CMU_PLLCR_DB_Pos)
#define    CMU_PLLCR_DB                                           CMU_PLLCR_DB_Msk

#define    CMU_RCLPCR_ENB_Pos                                     (0U)
#define    CMU_RCLPCR_ENB_Msk                                     (0x1U << CMU_RCLPCR_ENB_Pos)
#define    CMU_RCLPCR_ENB                                         CMU_RCLPCR_ENB_Msk

#define    CMU_RCLPTR_TRIM_Pos                                    (0U)
#define    CMU_RCLPTR_TRIM_Msk                                    (0xffU << CMU_RCLPTR_TRIM_Pos)
#define    CMU_RCLPTR_TRIM                                        CMU_RCLPTR_TRIM_Msk

#define    CMU_XTLFCR_WAIT_Pos                                    (13U)
#define    CMU_XTLFCR_WAIT_Msk                                    (0x7U << CMU_XTLFCR_WAIT_Pos)
#define    CMU_XTLFCR_WAIT                                        CMU_XTLFCR_WAIT_Msk

#define    CMU_XTLFCR_EXCKSEN_Pos                                 (12U)
#define    CMU_XTLFCR_EXCKSEN_Msk                                 (0x1U << CMU_XTLFCR_EXCKSEN_Pos)
#define    CMU_XTLFCR_EXCKSEN                                     CMU_XTLFCR_EXCKSEN_Msk

#define    CMU_XTLFCR_EN_Pos                                      (8U)
#define    CMU_XTLFCR_EN_Msk                                      (0xfU << CMU_XTLFCR_EN_Pos)
#define    CMU_XTLFCR_EN                                          CMU_XTLFCR_EN_Msk

#define    CMU_XTLFCR_RDY_Pos                                     (7U)
#define    CMU_XTLFCR_RDY_Msk                                     (0x1U << CMU_XTLFCR_RDY_Pos)
#define    CMU_XTLFCR_RDY                                         CMU_XTLFCR_RDY_Msk

#define    CMU_LSCLKSEL_SEL_Pos                                   (0U)
#define    CMU_LSCLKSEL_SEL_Msk                                   (0xffU << CMU_LSCLKSEL_SEL_Pos)
#define    CMU_LSCLKSEL_SEL                                       CMU_LSCLKSEL_SEL_Msk

#define    CMU_XTHFCR_WAIT_Pos                                    (13U)
#define    CMU_XTHFCR_WAIT_Msk                                    (0x7U << CMU_XTHFCR_WAIT_Pos)
#define    CMU_XTHFCR_WAIT                                        CMU_XTHFCR_WAIT_Msk

#define    CMU_XTHFCR_CFG_Pos                                     (8U)
#define    CMU_XTHFCR_CFG_Msk                                     (0xfU << CMU_XTHFCR_CFG_Pos)
#define    CMU_XTHFCR_CFG                                         CMU_XTHFCR_CFG_Msk

#define    CMU_XTHFCR_BYPASS_Pos                                  (4U)
#define    CMU_XTHFCR_BYPASS_Msk                                  (0x1U << CMU_XTHFCR_BYPASS_Pos)
#define    CMU_XTHFCR_BYPASS                                      CMU_XTHFCR_BYPASS_Msk

#define    CMU_XTHFCR_RDY_Pos                                     (1U)
#define    CMU_XTHFCR_RDY_Msk                                     (0x1U << CMU_XTHFCR_RDY_Pos)
#define    CMU_XTHFCR_RDY                                         CMU_XTHFCR_RDY_Msk

#define    CMU_XTHFCR_EN_Pos                                      (0U)
#define    CMU_XTHFCR_EN_Msk                                      (0x1U << CMU_XTHFCR_EN_Pos)
#define    CMU_XTHFCR_EN                                          CMU_XTHFCR_EN_Msk

#define    CMU_IER_SYSCSE_IE_Pos                                  (2U)
#define    CMU_IER_SYSCSE_IE_Msk                                  (0x1U << CMU_IER_SYSCSE_IE_Pos)
#define    CMU_IER_SYSCSE_IE                                      CMU_IER_SYSCSE_IE_Msk

#define    CMU_IER_HFDET_IE_Pos                                   (1U)
#define    CMU_IER_HFDET_IE_Msk                                   (0x1U << CMU_IER_HFDET_IE_Pos)
#define    CMU_IER_HFDET_IE                                       CMU_IER_HFDET_IE_Msk

#define    CMU_IER_LFDET_IE_Pos                                   (0U)
#define    CMU_IER_LFDET_IE_Msk                                   (0x1U << CMU_IER_LFDET_IE_Pos)
#define    CMU_IER_LFDET_IE                                       CMU_IER_LFDET_IE_Msk

#define    CMU_ISR_HFDETO_Pos                                     (9U)
#define    CMU_ISR_HFDETO_Msk                                     (0x1U << CMU_ISR_HFDETO_Pos)
#define    CMU_ISR_HFDETO                                         CMU_ISR_HFDETO_Msk

#define    CMU_ISR_LFDETO_Pos                                     (8U)
#define    CMU_ISR_LFDETO_Msk                                     (0x1U << CMU_ISR_LFDETO_Pos)
#define    CMU_ISR_LFDETO                                         CMU_ISR_LFDETO_Msk

#define    CMU_ISR_SYSCSE_IF_Pos                                  (2U)
#define    CMU_ISR_SYSCSE_IF_Msk                                  (0x1U << CMU_ISR_SYSCSE_IF_Pos)
#define    CMU_ISR_SYSCSE_IF                                      CMU_ISR_SYSCSE_IF_Msk

#define    CMU_ISR_HFDETIF_Pos                                    (1U)
#define    CMU_ISR_HFDETIF_Msk                                    (0x1U << CMU_ISR_HFDETIF_Pos)
#define    CMU_ISR_HFDETIF                                        CMU_ISR_HFDETIF_Msk

#define    CMU_ISR_LFDETIF_Pos                                    (0U)
#define    CMU_ISR_LFDETIF_Msk                                    (0x1U << CMU_ISR_LFDETIF_Pos)
#define    CMU_ISR_LFDETIF                                        CMU_ISR_LFDETIF_Msk

#define    CMU_OPCCR1_EXTICKS_Pos                                 (30U)
#define    CMU_OPCCR1_EXTICKS_Msk                                 (0x1U << CMU_OPCCR1_EXTICKS_Pos)
#define    CMU_OPCCR1_EXTICKS                                     CMU_OPCCR1_EXTICKS_Msk

#define    CMU_OPCCR1_LPUART1CKS_Pos                              (26U)
#define    CMU_OPCCR1_LPUART1CKS_Msk                              (0x3U << CMU_OPCCR1_LPUART1CKS_Pos)
#define    CMU_OPCCR1_LPUART1CKS                                  CMU_OPCCR1_LPUART1CKS_Msk

#define    CMU_OPCCR1_LPUART0CKS_Pos                              (24U)
#define    CMU_OPCCR1_LPUART0CKS_Msk                              (0x3U << CMU_OPCCR1_LPUART0CKS_Pos)
#define    CMU_OPCCR1_LPUART0CKS                                  CMU_OPCCR1_LPUART0CKS_Msk

#define    CMU_OPCCR1_I2CSMB1CKS_Pos                              (18U)
#define    CMU_OPCCR1_I2CSMB1CKS_Msk                              (0x3U << CMU_OPCCR1_I2CSMB1CKS_Pos)
#define    CMU_OPCCR1_I2CSMB1CKS                                   CMU_OPCCR1_I2CSMB1CKS_Msk

#define    CMU_OPCCR1_I2CSMB0CKS_Pos                              (16U)
#define    CMU_OPCCR1_I2CSMB0CKS_Msk                              (0x3U << CMU_OPCCR1_I2CSMB0CKS_Pos)
#define    CMU_OPCCR1_I2CSMB0CKS                                   CMU_OPCCR1_I2CSMB0CKS_Msk

#define    CMU_OPCCR1_BT16CKS_Pos                                 (14U)
#define    CMU_OPCCR1_BT16CKS_Msk                                 (0x3U << CMU_OPCCR1_BT16CKS_Pos)
#define    CMU_OPCCR1_BT16CKS                                     CMU_OPCCR1_BT16CKS_Msk

#define    CMU_OPCCR1_UART3CKS_Pos                                (12U)
#define    CMU_OPCCR1_UART3CKS_Msk                                (0x3U << CMU_OPCCR1_UART3CKS_Pos)
#define    CMU_OPCCR1_UART3CKS                                    CMU_OPCCR1_UART3CKS_Msk

#define    CMU_OPCCR1_LPT16CKS_Pos                                 (10U)
#define    CMU_OPCCR1_LPT16CKS_Msk                                 (0x3U << CMU_OPCCR1_LPT16CKS_Pos)
#define    CMU_OPCCR1_LPT16CKS                                    CMU_OPCCR1_LPT16CKS_Msk

#define    CMU_OPCCR1_UART2CKS_Pos                                (8U)
#define    CMU_OPCCR1_UART2CKS_Msk                                (0x3U << CMU_OPCCR1_UART2CKS_Pos)
#define    CMU_OPCCR1_UART2CKS                                    CMU_OPCCR1_UART2CKS_Msk

#define    CMU_OPCCR1_ATIMCKS_Pos                                 (4U)
#define    CMU_OPCCR1_ATIMCKS_Msk                                 (0x3U << CMU_OPCCR1_ATIMCKS_Pos)
#define    CMU_OPCCR1_ATIMCKS                                     CMU_OPCCR1_ATIMCKS_Msk

#define    CMU_OPCCR1_UART1CKS_Pos                                (2U)
#define    CMU_OPCCR1_UART1CKS_Msk                                (0x3U << CMU_OPCCR1_UART1CKS_Pos)
#define    CMU_OPCCR1_UART1CKS                                    CMU_OPCCR1_UART1CKS_Msk

#define    CMU_OPCCR1_UART0CKS_Pos                                (0U)
#define    CMU_OPCCR1_UART0CKS_Msk                                (0x3U << CMU_OPCCR1_UART0CKS_Pos)
#define    CMU_OPCCR1_UART0CKS                                    CMU_OPCCR1_UART0CKS_Msk

#define    CMU_OPCCR2_RTCPRSC_Pos                                 (22U)
#define    CMU_OPCCR2_RTCPRSC_Msk                                 (0x3ffU << CMU_OPCCR2_RTCPRSC_Pos)
#define    CMU_OPCCR2_RTCPRSC                                     CMU_OPCCR2_RTCPRSC_Msk

#define    CMU_OPCCR2_RTCCKS_Pos                                  (20U)
#define    CMU_OPCCR2_RTCCKS_Msk                                  (0x1U << CMU_OPCCR2_RTCCKS_Pos)
#define    CMU_OPCCR2_RTCCKS                                      CMU_OPCCR2_RTCCKS_Msk

#define    CMU_OPCCR2_FSCANCKS_Pos                                (16U)
#define    CMU_OPCCR2_FSCANCKS_Msk                                (0x3U << CMU_OPCCR2_FSCANCKS_Pos)
#define    CMU_OPCCR2_FSCANCKS                                     CMU_OPCCR2_FSCANCKS_Msk

#define    CMU_OPCCR2_LEDCKS_Pos                                  (14U)
#define    CMU_OPCCR2_LEDCKS_Msk                                  (0x3U << CMU_OPCCR2_LEDCKS_Pos)
#define    CMU_OPCCR2_LEDCKS                                       CMU_OPCCR2_LEDCKS_Msk

#define    CMU_OPCCR2_RNGPRSC_Pos                                 (10U)
#define    CMU_OPCCR2_RNGPRSC_Msk                                 (0x7U << CMU_OPCCR2_RNGPRSC_Pos)
#define    CMU_OPCCR2_RNGPRSC                                     CMU_OPCCR2_RNGPRSC_Msk

#define    CMU_OPCCR2_LEDPRSC_Pos                                 (5U)
#define    CMU_OPCCR2_LEDPRSC_Msk                                 (0x7U << CMU_OPCCR2_LEDPRSC_Pos)
#define    CMU_OPCCR2_LEDPRSC                                     CMU_OPCCR2_LEDPRSC_Msk

#define    CMU_AHBMCR_MPRIL_Pos                                   (0U)
#define    CMU_AHBMCR_MPRIL_Msk                                   (0x1U << CMU_AHBMCR_MPRIL_Pos)
#define    CMU_AHBMCR_MPRIL                                       CMU_AHBMCR_MPRIL_Msk

#define    FL_CMU_GROUP1_BUSCLK_LPTIM16                           (0x1U << 0U)
#define    FL_CMU_GROUP1_BUSCLK_RTC                               (0x1U << 2U)
#define    FL_CMU_GROUP1_BUSCLK_PMU                               (0x1U << 3U)
#define    FL_CMU_GROUP1_BUSCLK_SCU                               (0x1U << 4U)
#define    FL_CMU_GROUP1_BUSCLK_IWDT                              (0x1U << 5U)
#define    FL_CMU_GROUP1_BUSCLK_ANAC                              (0x1U << 6U)
#define    FL_CMU_GROUP1_BUSCLK_PAD                               (0x1U << 7U)
#define    FL_CMU_GROUP1_BUSCLK_SVD                               (0x1U << 8U)
#define    FL_CMU_GROUP1_BUSCLK_COMP                              (0x1U << 9U)
#define    FL_CMU_GROUP1_BUSCLK_SENT0                             (0x1U << 19U)
#define    FL_CMU_GROUP1_BUSCLK_SENT1                             (0x1U << 20U)
#define    FL_CMU_GROUP1_BUSCLK_LED                               (0x1U << 24U)
#define    FL_CMU_GROUP1_BUSCLK_LCD                               (0x1U << 25U)
#define    FL_CMU_GROUP1_BUSCLK_CLM1                              (0x1U << 26U)
#define    FL_CMU_GROUP1_BUSCLK_CLM0                              (0x1U << 27U)

#define    FL_CMU_GROUP2_BUSCLK_CRC                               (0x1U << 0U)
#define    FL_CMU_GROUP2_BUSCLK_RNG                               (0x1U << 1U)
#define    FL_CMU_GROUP2_BUSCLK_AES                               (0x1U << 2U)
#define    FL_CMU_GROUP2_BUSCLK_DMA                               (0x1U << 4U)
#define    FL_CMU_GROUP2_BUSCLK_FLASH                             (0x1U << 5U)
#define    FL_CMU_GROUP2_BUSCLK_RAMBIST                           (0x1U << 6U)
#define    FL_CMU_GROUP2_BUSCLK_WWDT                              (0x1U << 7U)
#define    FL_CMU_GROUP2_BUSCLK_ADC                               (0x1U << 8U)
#define    FL_CMU_GROUP2_BUSCLK_DAC                               (0x1U << 9U)
#define    FL_CMU_GROUP2_BUSCLK_OPA                               (0x1U << 10U)
#define    FL_CMU_GROUP2_BUSCLK_PGL                               (0x1U << 11U)

#define    FL_CMU_GROUP3_BUSCLK_SPI0                              (0x1U << 0U)
#define    FL_CMU_GROUP3_BUSCLK_SPI1                              (0x1U << 1U)
#define    FL_CMU_GROUP3_BUSCLK_UART0                             (0x1U << 8U)
#define    FL_CMU_GROUP3_BUSCLK_UART1                             (0x1U << 9U)
#define    FL_CMU_GROUP3_BUSCLK_UART2                             (0x1U << 10U)
#define    FL_CMU_GROUP3_BUSCLK_UART3                             (0x1U << 11U)
#define    FL_CMU_GROUP3_BUSCLK_UART4                             (0x1U << 12U)
#define    FL_CMU_GROUP3_BUSCLK_LPUART0                           (0x1U << 16U)
#define    FL_CMU_GROUP3_BUSCLK_LPUART1                           (0x1U << 17U)
#define    FL_CMU_GROUP3_BUSCLK_FSCAN                             (0x1U << 19U)
#define    FL_CMU_GROUP3_BUSCLK_UARTIR                            (0x1U << 23U)
#define    FL_CMU_GROUP3_BUSCLK_I2CSMB0                           (0x1U << 28U)
#define    FL_CMU_GROUP3_BUSCLK_I2CSMB1                           (0x1U << 29U)

#define    FL_CMU_GROUP4_BUSCLK_GPTIM0                            (0x1U << 1U)
#define    FL_CMU_GROUP4_BUSCLK_GPTIM1                            (0x1U << 2U)
#define    FL_CMU_GROUP4_BUSCLK_ATIM                              (0x1U << 4U)
#define    FL_CMU_GROUP4_BUSCLK_BSTIM16                           (0x1U << 8U)
#define    FL_CMU_GROUP4_BUSCLK_TAU0                              (0x1U << 10U)
#define    FL_CMU_GROUP4_BUSCLK_DIVAS                             (0x1U << 11U)

#define    FL_CMU_GROUP1_OPCLKEN_EXTI                             (0x1U << 31U)
#define    FL_CMU_GROUP1_OPCLKEN_FLASH                            (0x1U << 30U)
#define    FL_CMU_GROUP1_OPCLKEN_LPUART1                          (0x1U << 29U)
#define    FL_CMU_GROUP1_OPCLKEN_LPUART0                          (0x1U << 28U)
#define    FL_CMU_GROUP1_OPCLKEN_LED                              (0x1U << 25U)
#define    FL_CMU_GROUP1_OPCLKEN_RNG                              (0x1U << 24U)
#define    FL_CMU_GROUP1_OPCLKEN_I2CSMB1                          (0x1U << 21U)
#define    FL_CMU_GROUP1_OPCLKEN_I2CSMB0                          (0x1U << 20U)
#define    FL_CMU_GROUP1_OPCLKEN_ATIM                             (0x1U << 14U)
#define    FL_CMU_GROUP1_OPCLKEN_UART3                            (0x1U << 7U)
#define    FL_CMU_GROUP1_OPCLKEN_UART2                            (0x1U << 6U)
#define    FL_CMU_GROUP1_OPCLKEN_UART1                            (0x1U << 5U)
#define    FL_CMU_GROUP1_OPCLKEN_UART0                            (0x1U << 4U)
#define    FL_CMU_GROUP1_OPCLKEN_BSTIM16                          (0x1U << 3U)
#define    FL_CMU_GROUP1_OPCLKEN_LPTIM16                          (0x1U << 1U)
#define    FL_CMU_GROUP2_OPCLKEN_FSCAN                            (0x1U << 8U)

#define    FL_CMU_APBCLK_PSC_DIV1                                (0x0U << CMU_SYSCLKCR_APBPRES_Pos)
#define    FL_CMU_APBCLK_PSC_DIV2                                (0x4U << CMU_SYSCLKCR_APBPRES_Pos)
#define    FL_CMU_APBCLK_PSC_DIV4                                (0x5U << CMU_SYSCLKCR_APBPRES_Pos)
#define    FL_CMU_APBCLK_PSC_DIV8                                (0x6U << CMU_SYSCLKCR_APBPRES_Pos)
#define    FL_CMU_APBCLK_PSC_DIV16                               (0x7U << CMU_SYSCLKCR_APBPRES_Pos)


#define    FL_CMU_AHBCLK_PSC_DIV1                                 (0x0U << CMU_SYSCLKCR_AHBPRES_Pos)
#define    FL_CMU_AHBCLK_PSC_DIV2                                 (0x4U << CMU_SYSCLKCR_AHBPRES_Pos)
#define    FL_CMU_AHBCLK_PSC_DIV4                                 (0x5U << CMU_SYSCLKCR_AHBPRES_Pos)
#define    FL_CMU_AHBCLK_PSC_DIV8                                 (0x6U << CMU_SYSCLKCR_AHBPRES_Pos)
#define    FL_CMU_AHBCLK_PSC_DIV16                                (0x7U << CMU_SYSCLKCR_AHBPRES_Pos)


#define    FL_CMU_SYSTICK_CLK_SOURCE_AHBCLK_DIV8                  (0x0U << CMU_SYSCLKCR_STCLKSEL_Pos)
#define    FL_CMU_SYSTICK_CLK_SOURCE_XTLF                         (0x1U << CMU_SYSCLKCR_STCLKSEL_Pos)
#define    FL_CMU_SYSTICK_CLK_SOURCE_RCLP                         (0x2U << CMU_SYSCLKCR_STCLKSEL_Pos)


#define    FL_CMU_SYSTEM_CLK_SOURCE_RCHF                          (0x0U << CMU_SYSCLKCR_SYSCLKSEL_Pos)
#define    FL_CMU_SYSTEM_CLK_SOURCE_XTHF                          (0x1U << CMU_SYSCLKCR_SYSCLKSEL_Pos)
#define    FL_CMU_SYSTEM_CLK_SOURCE_PLL                           (0x2U << CMU_SYSCLKCR_SYSCLKSEL_Pos)
#define    FL_CMU_SYSTEM_CLK_SOURCE_XTLF                          (0x5U << CMU_SYSCLKCR_SYSCLKSEL_Pos)
#define    FL_CMU_SYSTEM_CLK_SOURCE_RCLP                          (0x6U << CMU_SYSCLKCR_SYSCLKSEL_Pos)


#define    FL_CMU_RCHF_FREQUENCY_8MHZ                             (0x0U << CMU_RCHFCR_FSEL_Pos)
#define    FL_CMU_RCHF_FREQUENCY_16MHZ                            (0x1U << CMU_RCHFCR_FSEL_Pos)
#define    FL_CMU_RCHF_FREQUENCY_24MHZ                            (0x2U << CMU_RCHFCR_FSEL_Pos)
#define    FL_CMU_RCHF_FREQUENCY_32MHZ                            (0x3U << CMU_RCHFCR_FSEL_Pos)


#define    FL_CMU_PLL_CLK_SOURCE_RCHF                             (0x0U << CMU_PLLCR_INSEL_Pos)
#define    FL_CMU_PLL_CLK_SOURCE_XTHF                             (0x1U << CMU_PLLCR_INSEL_Pos)


#define    FL_CMU_PLL_MUL_32                                      (0x1fU << CMU_PLLCR_DB_Pos)
#define    FL_CMU_PLL_MUL_72                                      (0x47U << CMU_PLLCR_DB_Pos)

#define    FL_CMU_PLL_PSC_DIV1                                    (0x0U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV2                                    (0x1U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV4                                    (0x2U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV8                                    (0x3U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV12                                   (0x4U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV16                                   (0x5U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV24                                   (0x6U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV32                                   (0x7U << CMU_PLLCR_REFPRSC_Pos)

#define    FL_CMU_XTLF_START_WAIT_CYCLE_128                       (0x0U << CMU_XTLFCR_WAIT_Pos)
#define    FL_CMU_XTLF_START_WAIT_CYCLE_256                       (0x1U << CMU_XTLFCR_WAIT_Pos)
#define    FL_CMU_XTLF_START_WAIT_CYCLE_512                       (0x2U << CMU_XTLFCR_WAIT_Pos)
#define    FL_CMU_XTLF_START_WAIT_CYCLE_1024                      (0x3U << CMU_XTLFCR_WAIT_Pos)
#define    FL_CMU_XTLF_START_WAIT_CYCLE_2048                      (0x4U << CMU_XTLFCR_WAIT_Pos)
#define    FL_CMU_XTLF_START_WAIT_CYCLE_4096                      (0x5U << CMU_XTLFCR_WAIT_Pos)
#define    FL_CMU_XTLF_START_WAIT_CYCLE_8192                      (0x6U << CMU_XTLFCR_WAIT_Pos)
#define    FL_CMU_XTLF_START_WAIT_CYCLE_16384                     (0x7U << CMU_XTLFCR_WAIT_Pos)

#define    FL_CMU_XTLF_ENABLE                                     (0x5U << CMU_XTLFCR_EN_Pos)
#define    FL_CMU_XTLF_DISABLE                                    (0xAU << CMU_XTLFCR_EN_Pos)


#define    FL_CMU_XTHF_START_WAIT_CYCLE_128                       (0x0U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_256                       (0x1U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_512                       (0x2U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_1024                      (0x3U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_2048                      (0x4U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_4096                      (0x5U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_8192                      (0x6U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_16384                     (0x7U << CMU_XTHFCR_WAIT_Pos)

#define    FL_CMU_EXTI_CLK_SOURCE_AHBCLK                          (0x0U << CMU_OPCCR1_EXTICKS_Pos)
#define    FL_CMU_EXTI_CLK_SOURCE_RCLP                            (0x1U << CMU_OPCCR1_EXTICKS_Pos)


#define    FL_CMU_LPUART1_CLK_SOURCE_XTLF                         (0x0U << CMU_OPCCR1_LPUART1CKS_Pos)
#define    FL_CMU_LPUART1_CLK_SOURCE_RCHF                         (0x1U << CMU_OPCCR1_LPUART1CKS_Pos)
#define    FL_CMU_LPUART1_CLK_SOURCE_RCLP                         (0x2U << CMU_OPCCR1_LPUART1CKS_Pos)


#define    FL_CMU_LPUART0_CLK_SOURCE_XTLF                         (0x0U << CMU_OPCCR1_LPUART0CKS_Pos)
#define    FL_CMU_LPUART0_CLK_SOURCE_RCHF                         (0x1U << CMU_OPCCR1_LPUART0CKS_Pos)
#define    FL_CMU_LPUART0_CLK_SOURCE_RCLP                         (0x2U << CMU_OPCCR1_LPUART0CKS_Pos)

#define    FL_CMU_LPUART_CLK_SOURCE_XTLF                          0x0U
#define    FL_CMU_LPUART_CLK_SOURCE_RCHF                          0x1U
#define    FL_CMU_LPUART_CLK_SOURCE_RCLP                          0x2U

#define    FL_CMU_I2CSMB1_CLK_SOURCE_APBCLK                       (0x0U << CMU_OPCCR1_I2CSMB1CKS_Pos)
#define    FL_CMU_I2CSMB1_CLK_SOURCE_RCHF                         (0x1U << CMU_OPCCR1_I2CSMB1CKS_Pos)
#define    FL_CMU_I2CSMB1_CLK_SOURCE_SYSCLK                       (0x2U << CMU_OPCCR1_I2CSMB1CKS_Pos)

#define    FL_CMU_I2CSMB0_CLK_SOURCE_APBCLK                       (0x0U << CMU_OPCCR1_I2CSMB0CKS_Pos)
#define    FL_CMU_I2CSMB0_CLK_SOURCE_RCHF                         (0x1U << CMU_OPCCR1_I2CSMB0CKS_Pos)
#define    FL_CMU_I2CSMB0_CLK_SOURCE_SYSCLK                       (0x2U << CMU_OPCCR1_I2CSMB0CKS_Pos)

#define    FL_CMU_BSTIM16_CLK_SOURCE_APBCLK                       (0x0U << CMU_OPCCR1_BT16CKS_Pos)
#define    FL_CMU_BSTIM16_CLK_SOURCE_XTLF                         (0x1U << CMU_OPCCR1_BT16CKS_Pos)
#define    FL_CMU_BSTIM16_CLK_SOURCE_RCLP                         (0x2U << CMU_OPCCR1_BT16CKS_Pos)


#define    FL_CMU_UART3_CLK_SOURCE_APBCLK                         (0x0U << CMU_OPCCR1_UART3CKS_Pos)
#define    FL_CMU_UART3_CLK_SOURCE_RCHF                           (0x1U << CMU_OPCCR1_UART3CKS_Pos)
#define    FL_CMU_UART3_CLK_SOURCE_SYSCLK                         (0x2U << CMU_OPCCR1_UART3CKS_Pos)
#define    FL_CMU_UART3_CLK_SOURCE_XTHF                           (0x3U << CMU_OPCCR1_UART3CKS_Pos)


#define    FL_CMU_LPTIM16_CLK_SOURCE_APBCLK                       (0x0U << CMU_OPCCR1_LPT16CKS_Pos)
#define    FL_CMU_LPTIM16_CLK_SOURCE_XTLF                         (0x1U << CMU_OPCCR1_LPT16CKS_Pos)
#define    FL_CMU_LPTIM16_CLK_SOURCE_RCLP                         (0x2U << CMU_OPCCR1_LPT16CKS_Pos)


#define    FL_CMU_UART2_CLK_SOURCE_APBCLK                         (0x0U << CMU_OPCCR1_UART2CKS_Pos)
#define    FL_CMU_UART2_CLK_SOURCE_RCHF                           (0x1U << CMU_OPCCR1_UART2CKS_Pos)
#define    FL_CMU_UART2_CLK_SOURCE_SYSCLK                         (0x2U << CMU_OPCCR1_UART2CKS_Pos)
#define    FL_CMU_UART2_CLK_SOURCE_XTHF                           (0x3U << CMU_OPCCR1_UART2CKS_Pos)


#define    FL_CMU_ATIM_CLK_SOURCE_APBCLK                          (0x0U << CMU_OPCCR1_ATIMCKS_Pos)
#define    FL_CMU_ATIM_CLK_SOURCE_PLL                             (0x1U << CMU_OPCCR1_ATIMCKS_Pos)


#define    FL_CMU_UART1_CLK_SOURCE_APBCLK                         (0x0U << CMU_OPCCR1_UART1CKS_Pos)
#define    FL_CMU_UART1_CLK_SOURCE_RCHF                           (0x1U << CMU_OPCCR1_UART1CKS_Pos)
#define    FL_CMU_UART1_CLK_SOURCE_SYSCLK                         (0x2U << CMU_OPCCR1_UART1CKS_Pos)
#define    FL_CMU_UART1_CLK_SOURCE_XTHF                           (0x3U << CMU_OPCCR1_UART1CKS_Pos)

#define    FL_CMU_UART0_CLK_SOURCE_APBCLK                         (0x0U << CMU_OPCCR1_UART0CKS_Pos)
#define    FL_CMU_UART0_CLK_SOURCE_RCHF                           (0x1U << CMU_OPCCR1_UART0CKS_Pos)
#define    FL_CMU_UART0_CLK_SOURCE_SYSCLK                         (0x2U << CMU_OPCCR1_UART0CKS_Pos)
#define    FL_CMU_UART0_CLK_SOURCE_XTHF                           (0x3U << CMU_OPCCR1_UART0CKS_Pos)

#define    FL_CMU_RTC_CLK_SOURCE_LSCLK                            (0x0U << CMU_OPCCR2_RTCCKS_Pos)
#define    FL_CMU_RTC_CLK_SOURCE_XTHF                             (0x1U << CMU_OPCCR2_RTCCKS_Pos)

#define    FL_CMU_FSCAN_CLK_SOURCE_RCHF                           (0x0U << CMU_OPCCR2_FSCANCKS_Pos)
#define    FL_CMU_FSCAN_CLK_SOURCE_XTHF                           (0x1U << CMU_OPCCR2_FSCANCKS_Pos)
#define    FL_CMU_FSCAN_CLK_SOURCE_PLL                            (0x2U << CMU_OPCCR2_FSCANCKS_Pos)
#define    FL_CMU_FSCAN_CLK_SOURCE_APBCLK                         (0x3U << CMU_OPCCR2_FSCANCKS_Pos)


#define    FL_CMU_LED_CLK_SOURCE_RCHF                             (0x0U << CMU_OPCCR2_LEDCKS_Pos)
#define    FL_CMU_LED_CLK_SOURCE_XTHF                             (0x1U << CMU_OPCCR2_LEDCKS_Pos)
#define    FL_CMU_LED_CLK_SOURCE_PLL                              (0x2U << CMU_OPCCR2_LEDCKS_Pos)
#define    FL_CMU_LED_CLK_SOURCE_APBCLK                           (0x3U << CMU_OPCCR2_LEDCKS_Pos)

#define    FL_CMU_RNG_PSC_DIV1                                    (0x0U << CMU_OPCCR2_RNGPRSC_Pos)
#define    FL_CMU_RNG_PSC_DIV2                                    (0x1U << CMU_OPCCR2_RNGPRSC_Pos)
#define    FL_CMU_RNG_PSC_DIV4                                    (0x2U << CMU_OPCCR2_RNGPRSC_Pos)
#define    FL_CMU_RNG_PSC_DIV8                                    (0x3U << CMU_OPCCR2_RNGPRSC_Pos)
#define    FL_CMU_RNG_PSC_DIV16                                   (0x4U << CMU_OPCCR2_RNGPRSC_Pos)
#define    FL_CMU_RNG_PSC_DIV32                                   (0x5U << CMU_OPCCR2_RNGPRSC_Pos)


#define    FL_CMU_LED_PSC_DIV1                                    (0x0U << CMU_OPCCR2_LEDPRSC_Pos)
#define    FL_CMU_LED_PSC_DIV2                                    (0x1U << CMU_OPCCR2_LEDPRSC_Pos)
#define    FL_CMU_LED_PSC_DIV4                                    (0x2U << CMU_OPCCR2_LEDPRSC_Pos)
#define    FL_CMU_LED_PSC_DIV8                                    (0x3U << CMU_OPCCR2_LEDPRSC_Pos)
#define    FL_CMU_LED_PSC_DIV16                                   (0x4U << CMU_OPCCR2_LEDPRSC_Pos)
#define    FL_CMU_LED_PSC_DIV32                                   (0x5U << CMU_OPCCR2_LEDPRSC_Pos)

#define    FL_CMU_AHB_MASTER_PRIORITY_DMA_FIRST                   (0x0U << CMU_AHBMCR_MPRIL_Pos)
#define    FL_CMU_AHB_MASTER_PRIORITY_CPU_FIRST                   (0x1U << CMU_AHBMCR_MPRIL_Pos)

#define    FL_CMU_LSCLK_CLK_SOURCE_RCLP                           (0x55U << CMU_LSCLKSEL_SEL_Pos)
#define    FL_CMU_LSCLK_CLK_SOURCE_XTLF                           (0xAAU << CMU_LSCLKSEL_SEL_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup CMU_FL_Exported_Functions CMU Exported Functions
  * @{
  */
/**
  * @brief    Enable Sleep/DeepSleep Mode External Interrupt
  * @rmtoll   SYSCLKCR    SLP_ENEXTI    FL_CMU_EnableEXTIOnSleep
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableEXTIOnSleep(void)
{
    SET_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_SLP_ENEXTI_Msk);
}

/**
  * @brief    Get Sleep/DeepSleep Mode External Interrupt Enable Status
  * @rmtoll   SYSCLKCR    SLP_ENEXTI    FL_CMU_IsEnabledEXTIOnSleep
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledEXTIOnSleep(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_SLP_ENEXTI_Msk) == CMU_SYSCLKCR_SLP_ENEXTI_Msk);
}

/**
  * @brief    Disable Sleep/DeepSleep Mode External Interrupt
  * @rmtoll   SYSCLKCR    SLP_ENEXTI    FL_CMU_DisableEXTIOnSleep
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableEXTIOnSleep(void)
{
    CLEAR_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_SLP_ENEXTI_Msk);
}

/**
  * @brief    Set APB Prescaler
  * @rmtoll   SYSCLKCR    APBPRES    FL_CMU_SetAPBPrescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref FL_CMU_APBCLK_PSC_DIV1
  *           @arg @ref FL_CMU_APBCLK_PSC_DIV2
  *           @arg @ref FL_CMU_APBCLK_PSC_DIV4
  *           @arg @ref FL_CMU_APBCLK_PSC_DIV8
  *           @arg @ref FL_CMU_APBCLK_PSC_DIV16
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetAPBPrescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->SYSCLKCR, CMU_SYSCLKCR_APBPRES_Msk, prescaler);
}

/**
  * @brief    Get APB Prescaler
  * @rmtoll   SYSCLKCR    APBPRES    FL_CMU_GetAPBPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_APBCLK_PSC_DIV1
  *           @arg @ref FL_CMU_APBCLK_PSC_DIV2
  *           @arg @ref FL_CMU_APBCLK_PSC_DIV4
  *           @arg @ref FL_CMU_APBCLK_PSC_DIV8
  *           @arg @ref FL_CMU_APBCLK_PSC_DIV16
  */
__STATIC_INLINE uint32_t FL_CMU_GetAPBPrescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_APBPRES_Msk));
}

/**
  * @brief    Set AHB Prescaler
  * @rmtoll   SYSCLKCR    AHBPRES    FL_CMU_SetAHBPrescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV1
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV2
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV4
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV8
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV16
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetAHBPrescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->SYSCLKCR, CMU_SYSCLKCR_AHBPRES_Msk, prescaler);
}

/**
  * @brief    Get AHB Prescaler
  * @rmtoll   SYSCLKCR    AHBPRES    FL_CMU_GetAHBPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV1
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV2
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV4
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV8
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV16
  */
__STATIC_INLINE uint32_t FL_CMU_GetAHBPrescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_AHBPRES_Msk));
}

/**
  * @brief    Set SysTick Clock Source
  * @rmtoll   SYSCLKCR    STCLKSEL    FL_CMU_SetSysTickClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_SYSTICK_CLK_SOURCE_AHBCLK_DIV8
  *           @arg @ref FL_CMU_SYSTICK_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_SYSTICK_CLK_SOURCE_RCLP
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetSysTickClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->SYSCLKCR, CMU_SYSCLKCR_STCLKSEL_Msk, clock);
}

/**
  * @brief    Get SysTick Clock Source
  * @rmtoll   SYSCLKCR    STCLKSEL    FL_CMU_GetSysTickClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_SYSTICK_CLK_SOURCE_AHBCLK_DIV8
  *           @arg @ref FL_CMU_SYSTICK_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_SYSTICK_CLK_SOURCE_RCLP
  */
__STATIC_INLINE uint32_t FL_CMU_GetSysTickClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_STCLKSEL_Msk));
}

/**
  * @brief    Set System Clock Source
  * @rmtoll   SYSCLKCR    SYSCLKSEL    FL_CMU_SetSystemClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_PLL
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_RCLP
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetSystemClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->SYSCLKCR, CMU_SYSCLKCR_SYSCLKSEL_Msk, clock);
}

/**
  * @brief    Set System Clock Source Setting
  * @rmtoll   SYSCLKCR    SYSCLKSEL    FL_CMU_GetSystemClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_PLL
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_RCLP
  */
__STATIC_INLINE uint32_t FL_CMU_GetSystemClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_SYSCLKSEL_Msk));
}

/**
  * @brief    Set RCHF Frequency
  * @rmtoll   RCHFCR    FSEL    FL_CMU_RCHF_SetFrequency
  * @param    frequency This parameter can be one of the following values:
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_8MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_16MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_24MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_32MHZ
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_RCHF_SetFrequency(uint32_t frequency)
{
    MODIFY_REG(CMU->RCHFCR, CMU_RCHFCR_FSEL_Msk, frequency);
}

/**
  * @brief    Get RCHF Frequency Setting
  * @rmtoll   RCHFCR    FSEL    FL_CMU_RCHF_GetFrequency
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_8MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_16MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_24MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_32MHZ
  */
__STATIC_INLINE uint32_t FL_CMU_RCHF_GetFrequency(void)
{
    return (uint32_t)(READ_BIT(CMU->RCHFCR, CMU_RCHFCR_FSEL_Msk));
}

/**
  * @brief    Enable RCHF
  * @rmtoll   RCHFCR    EN    FL_CMU_RCHF_Enable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_RCHF_Enable(void)
{
    SET_BIT(CMU->RCHFCR, CMU_RCHFCR_EN_Msk);
}

/**
  * @brief    Get RCHF Enable Status
  * @rmtoll   RCHFCR    EN    FL_CMU_RCHF_IsEnabled
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_RCHF_IsEnabled(void)
{
    return (uint32_t)(READ_BIT(CMU->RCHFCR, CMU_RCHFCR_EN_Msk) == CMU_RCHFCR_EN_Msk);
}

/**
  * @brief    Disable RCHF
  * @rmtoll   RCHFCR    EN    FL_CMU_RCHF_Disable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_RCHF_Disable(void)
{
    CLEAR_BIT(CMU->RCHFCR, CMU_RCHFCR_EN_Msk);
}

/**
  * @brief    Set RCHF Freqency Trim Value
  * @rmtoll   RCHFTR    TRIM    FL_CMU_RCHF_WriteTrimValue
  * @param    value TrimValue The value of RCHF trim
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_RCHF_WriteTrimValue(uint32_t value)
{
    MODIFY_REG(CMU->RCHFTR, (0xffU << 0U), (value << 0U));
}

/**
  * @brief    Get RCHF Freqency Trim Value
  * @rmtoll   RCHFTR    TRIM    FL_CMU_RCHF_ReadTrimValue
  * @retval   The value of RCHF trim
  */
__STATIC_INLINE uint32_t FL_CMU_RCHF_ReadTrimValue(void)
{
    return (uint32_t)(READ_BIT(CMU->RCHFTR, (0xffU << 0U)) >> 0U);
}

/**
  * @brief    Enable PLL
  * @rmtoll   PLLCR    EN    FL_CMU_PLL_Enable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_PLL_Enable(void)
{
    SET_BIT(CMU->PLLCR, CMU_PLLCR_EN_Msk);
}

/**
  * @brief    Disable PLL
  * @rmtoll   PLLCR    EN    FL_CMU_PLL_Disable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_PLL_Disable(void)
{
    CLEAR_BIT(CMU->PLLCR, CMU_PLLCR_EN_Msk);
}

/**
  * @brief    Get PLL Enable Status
  * @rmtoll   PLLCR    EN    FL_CMU_PLL_IsEnabled
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_PLL_IsEnabled(void)
{
    return (uint32_t)(READ_BIT(CMU->PLLCR, CMU_PLLCR_EN_Msk) == CMU_PLLCR_EN_Msk);
}

/**
  * @brief    Get PLL Ready Status
  * @rmtoll   PLLCR    LOCKED    FL_CMU_IsActiveFlag_PLLReady
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsActiveFlag_PLLReady(void)
{
    return (uint32_t)(READ_BIT(CMU->PLLCR, CMU_PLLCR_LOCKED_Msk) == (CMU_PLLCR_LOCKED_Msk));
}

/**
  * @brief    Set PLL Input Source
  * @rmtoll   PLLCR    INSEL    FL_CMU_PLL_SetClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_PLL_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_PLL_CLK_SOURCE_XTHF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_PLL_SetClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->PLLCR, CMU_PLLCR_INSEL_Msk, clock);
}

/**
  * @brief    Get PLL Input Source Setting
  * @rmtoll   PLLCR    INSEL    FL_CMU_PLL_GetClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_PLL_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_PLL_CLK_SOURCE_XTHF
  */
__STATIC_INLINE uint32_t FL_CMU_PLL_GetClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->PLLCR, CMU_PLLCR_INSEL_Msk));
}

/**
  * @brief    Set PLL Multiplier
  * @rmtoll   PLLCR    DB    FL_CMU_PLL_WriteMultiplier
  * @param    multiplier
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_PLL_WriteMultiplier(uint32_t multiplier)
{
    MODIFY_REG(CMU->PLLCR, (0x3ffU << 16U), (multiplier << 16U));
}

/**
  * @brief    Get PLL Multiplier Setting
  * @rmtoll   PLLCR    DB    FL_CMU_PLL_ReadMultiplier
  * @retval
  */
__STATIC_INLINE uint32_t FL_CMU_PLL_ReadMultiplier(void)
{
    return (uint32_t)(READ_BIT(CMU->PLLCR, (0x3ffU << 16U)) >> 16U);
}

/**
  * @brief    Set PLL Prescaler
  * @rmtoll   PLLCR    REFPRSC    FL_CMU_PLL_SetPrescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref FL_CMU_PLL_PSC_DIV1
  *           @arg @ref FL_CMU_PLL_PSC_DIV2
  *           @arg @ref FL_CMU_PLL_PSC_DIV4
  *           @arg @ref FL_CMU_PLL_PSC_DIV8
  *           @arg @ref FL_CMU_PLL_PSC_DIV12
  *           @arg @ref FL_CMU_PLL_PSC_DIV16
  *           @arg @ref FL_CMU_PLL_PSC_DIV24
  *           @arg @ref FL_CMU_PLL_PSC_DIV32
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_PLL_SetPrescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->PLLCR, CMU_PLLCR_REFPRSC_Msk, prescaler);
}

/**
  * @brief    Get PLL Prescaler Setting
  * @rmtoll   PLLCR    REFPRSC    FL_CMU_PLL_GetPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_PLL_PSC_DIV1
  *           @arg @ref FL_CMU_PLL_PSC_DIV2
  *           @arg @ref FL_CMU_PLL_PSC_DIV4
  *           @arg @ref FL_CMU_PLL_PSC_DIV8
  *           @arg @ref FL_CMU_PLL_PSC_DIV12
  *           @arg @ref FL_CMU_PLL_PSC_DIV16
  *           @arg @ref FL_CMU_PLL_PSC_DIV24
  *           @arg @ref FL_CMU_PLL_PSC_DIV32
  */
__STATIC_INLINE uint32_t FL_CMU_PLL_GetPrescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->PLLCR, CMU_PLLCR_REFPRSC_Msk));
}

/**
  * @brief    Enable RCLP
  * @rmtoll   RCLP    LPOENB    FL_CMU_RCLP_Enable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_RCLP_Enable(void)
{
    CLEAR_BIT(CMU->RCLPCR, CMU_RCLPCR_ENB_Msk);
}

/**
  * @brief    Disable RCLP
  * @rmtoll   RCLP   LPOENB    FL_CMU_RCLP_Disable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_RCLP_Disable(void)
{
    SET_BIT(CMU->RCLPCR, CMU_RCLPCR_ENB_Msk);
}

/**
  * @brief    Get RCLP Enable Flag
  * @rmtoll   RCLPCR    LPOENB    FL_CMU_RCLP_IsEnabled
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_RCLP_IsEnabled(void)
{
    return (uint32_t)!(READ_BIT(CMU->RCLPCR, CMU_RCLPCR_ENB_Msk) == CMU_RCLPCR_ENB_Msk);
}

/**
  * @brief    Set RCLP Frequency Trim Value
  * @rmtoll   RCLPTR    TRIM    FL_CMU_RCLP_WriteTrimValue
  * @param    value TrimValue The value of RCLP trim
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_RCLP_WriteTrimValue(uint32_t value)
{
    MODIFY_REG(CMU->RCLPTR, (0xffU << 0U), (value << 0U));
}

/**
  * @brief    Get RCLP Frequency Trim Value
  * @rmtoll   RCLPTR    TRIM    FL_CMU_RCLP_ReadTrimValue
  * @retval   The Value of RCLP trim
  */
__STATIC_INLINE uint32_t FL_CMU_RCLP_ReadTrimValue(void)
{
    return (uint32_t)(READ_BIT(CMU->RCLPTR, 0xffU) >> 0U);
}

/**
  * @brief    Set XTLF Start Wait Time
  * @rmtoll   XTLFCR    WAIT    FL_CMU_XTLF_SetStartWaitTime
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_128
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_256
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_512
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_1024
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_2048
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_4096
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_8192
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_16384
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTLF_SetStartWaitTime(uint32_t clock)
{
    MODIFY_REG(CMU->XTLFCR, CMU_XTLFCR_WAIT_Msk, clock);
}

/**
  * @brief    Get XTLF Start Wait Time
  * @rmtoll   XTLFCR    WAIT    FL_CMU_XTLF_GetStartWaitTime
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_128
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_256
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_512
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_1024
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_2048
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_4096
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_8192
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_16384
  */
__STATIC_INLINE uint32_t FL_CMU_XTLF_GetStartWaitTime(void)
{
    return (uint32_t)(READ_BIT(CMU->XTLFCR, CMU_XTLFCR_WAIT_Msk));
}

/**
  * @brief    Enable XT32KI
  * @rmtoll   XTLFCR    EXCKSEN    FL_CMU_Enable_XT32KI_Input
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_Enable_XT32KI_Input(void)
{
    SET_BIT(CMU->XTLFCR, CMU_XTLFCR_EXCKSEN_Msk);
}

/**
  * @brief    Disable XT32KI
  * @rmtoll   XTLFCR    EXCKSEN    FL_CMU_Disable_XT32KI_Input
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_Disable_XT32KI_Input(void)
{
    CLEAR_BIT(CMU->XTLFCR, CMU_XTLFCR_EXCKSEN_Msk);
}

/**
  * @brief    Get XT32KI Enable Status
  * @rmtoll   XTLFCR    EXCKSEN    FL_CMU_IsEnabled_XT32KI_Input
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabled_XT32KI_Input(void)
{
    return (uint32_t)(READ_BIT(CMU->XTLFCR, CMU_XTLFCR_EXCKSEN_Msk) == CMU_XTLFCR_EXCKSEN_Msk);
}

/**
  * @brief    Enable XTLF
  * @rmtoll   XTLFCR    EN    FL_CMU_XTLF_Enable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTLF_Enable(void)
{
    MODIFY_REG(CMU->XTLFCR, CMU_XTLFCR_EN_Msk, FL_CMU_XTLF_ENABLE);
}

/**
  * @brief    Disable XTLF
  * @rmtoll   XTLFCR    EN    FL_CMU_XTLF_Disable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTLF_Disable(void)
{
    MODIFY_REG(CMU->XTLFCR, CMU_XTLFCR_EN_Msk, FL_CMU_XTLF_DISABLE);
}

/**
  * @brief    Get XTLF Ready Status
  * @rmtoll   XTLFCR    RDY    FL_CMU_XTLF_IsReady
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_XTLF_IsReady(void)
{
    return (uint32_t)(READ_BIT(CMU->XTLFCR, CMU_XTLFCR_RDY_Msk) == CMU_XTLFCR_RDY_Msk);
}

/**
  * @brief    Set XTHF Start Wait Time
  * @rmtoll   XTHFCR    WAIT    FL_CMU_XTHF_SetStartWaitTime
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_128
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_256
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_512
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_1024
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_2048
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_4096
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_8192
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_16384
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTHF_SetStartWaitTime(uint32_t clock)
{
    MODIFY_REG(CMU->XTHFCR, CMU_XTHFCR_WAIT_Msk, clock);
}

/**
  * @brief    Get XTHF Start Wait Time
  * @rmtoll   XTHFCR    WAIT    FL_CMU_XTHF_GetStartWaitTime
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_128
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_256
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_512
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_1024
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_2048
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_4096
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_8192
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_16384
  */
__STATIC_INLINE uint32_t FL_CMU_XTHF_GetStartWaitTime(void)
{
    return (uint32_t)(READ_BIT(CMU->XTHFCR, CMU_XTHFCR_WAIT_Msk));
}

/**
  * @brief    Set XTHF Oscillation Strength
  * @rmtoll   XTHFCR    CFG    FL_CMU_XTHF_WriteDriverStrength
  * @param    strength
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTHF_WriteDriverStrength(uint32_t strength)
{
    MODIFY_REG(CMU->XTHFCR, (0xfU << 8U), (strength << 8U));
}

/**
  * @brief    Get XTHF Oscillation Strength Setting
  * @rmtoll   XTHFCR    CFG    FL_CMU_XTHF_ReadDriverStrength
  * @retval
  */
__STATIC_INLINE uint32_t FL_CMU_XTHF_ReadDriverStrength(void)
{
    return (uint32_t)(READ_BIT(CMU->XTHFCR, (0xfU << 8U)) >> 8U);
}

/**
  * @brief    Enable XTHF_IN pin input
  * @rmtoll   XTHFCR    BYPASS    FL_CMU_Enable_XTHF_Bypass
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_Enable_XTHF_Bypass(void)
{
    SET_BIT(CMU->XTHFCR, CMU_XTHFCR_BYPASS_Msk);
}

/**
  * @brief    Disable XTHF_IN pin input
  * @rmtoll   XTLFCR    BYPASS    FL_CMU_Disable_XTHF_Bypass
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_Disable_XTHF_Bypass(void)
{
    CLEAR_BIT(CMU->XTHFCR, CMU_XTHFCR_BYPASS_Msk);
}

/**
  * @brief    Get XTHF_IN pin Enable Status
  * @rmtoll   XTHFCR    BYPASS    FL_CMU_IsEnabled_XTHF_Bypass
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabled_XTHF_Bypass(void)
{
    return (uint32_t)(READ_BIT(CMU->XTHFCR, CMU_XTHFCR_BYPASS_Msk) == CMU_XTHFCR_BYPASS_Msk);
}

/**
  * @brief    Get XTHF Ready Status
  * @rmtoll   XTHFCR    RDY    FL_CMU_XTHF_IsReady
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_XTHF_IsReady(void)
{
    return (uint32_t)(READ_BIT(CMU->XTHFCR, CMU_XTHFCR_RDY_Msk) == CMU_XTHFCR_RDY_Msk);
}

/**
  * @brief    Enable XTHF
  * @rmtoll   XTHFCR    EN    FL_CMU_XTHF_Enable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTHF_Enable(void)
{
    SET_BIT(CMU->XTHFCR, CMU_XTHFCR_EN_Msk);
}

/**
  * @brief    Get XTHF Enable Status
  * @rmtoll   XTHFCR    EN    FL_CMU_XTHF_IsEnabled
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_XTHF_IsEnabled(void)
{
    return (uint32_t)(READ_BIT(CMU->XTHFCR, CMU_XTHFCR_EN_Msk) == CMU_XTHFCR_EN_Msk);
}

/**
  * @brief    Disable XTHF
  * @rmtoll   XTHFCR    EN    FL_CMU_XTHF_Disable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTHF_Disable(void)
{
    CLEAR_BIT(CMU->XTHFCR, CMU_XTHFCR_EN_Msk);
}

/**
  * @brief    Enable SYSCLK Select Error Interrupt
  * @rmtoll   IER    SYSCSE_IE    FL_CMU_EnableIT_SYSCLKSelectError
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableIT_SYSCLKSelectError(void)
{
    SET_BIT(CMU->IER, CMU_IER_SYSCSE_IE_Msk);
}

/**
  * @brief    Get SYSCLK Select Error Status
  * @rmtoll   IER    SYSCSE_IE    FL_CMU_IsEnabledIT_SYSCLKSelectError
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledIT_SYSCLKSelectError(void)
{
    return (uint32_t)(READ_BIT(CMU->IER, CMU_IER_SYSCSE_IE_Msk) == CMU_IER_SYSCSE_IE_Msk);
}

/**
  * @brief    Disable SYSCLK Select Error Interrupt
  * @rmtoll   IER    SYSCSE_IE    FL_CMU_DisableIT_SYSCLKSelectError
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableIT_SYSCLKSelectError(void)
{
    CLEAR_BIT(CMU->IER, CMU_IER_SYSCSE_IE_Msk);
}

/**
  * @brief    Enable XTHF Fail Interrupt
  * @rmtoll   IER    HFDET_IE    FL_CMU_EnableIT_XTHFFail
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableIT_XTHFFail(void)
{
    SET_BIT(CMU->IER, CMU_IER_HFDET_IE_Msk);
}

/**
  * @brief    Get XTHF Fail Interrupt Enable Status
  * @rmtoll   IER    HFDET_IE    FL_CMU_IsEnabledIT_XTHFFail
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledIT_XTHFFail(void)
{
    return (uint32_t)(READ_BIT(CMU->IER, CMU_IER_HFDET_IE_Msk) == CMU_IER_HFDET_IE_Msk);
}

/**
  * @brief    Disable XTHF Fail Interrupt
  * @rmtoll   IER    HFDET_IE    FL_CMU_DisableIT_XTHFFail
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableIT_XTHFFail(void)
{
    CLEAR_BIT(CMU->IER, CMU_IER_HFDET_IE_Msk);
}

/**
  * @brief    Enable XTLF Fail Interrupt
  * @rmtoll   IER    LFDET_IE    FL_CMU_EnableIT_XTLFFail
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableIT_XTLFFail(void)
{
    SET_BIT(CMU->IER, CMU_IER_LFDET_IE_Msk);
}

/**
  * @brief    Get XTLF Fail Interrupt Enable Status
  * @rmtoll   IER    LFDET_IE    FL_CMU_IsEnabledIT_XTLFFail
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledIT_XTLFFail(void)
{
    return (uint32_t)(READ_BIT(CMU->IER, CMU_IER_LFDET_IE_Msk) ==CMU_IER_LFDET_IE_Msk);
}

/**
  * @brief    Disable XTLF Fail Interrupt
  * @rmtoll   IER    LFDET_IE    FL_CMU_DisableIT_XTLFFail
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableIT_XTLFFail(void)
{
    CLEAR_BIT(CMU->IER, CMU_IER_LFDET_IE_Msk);
}

/**
  * @brief    Get XTHF Vibrating Output
  * @rmtoll   ISR    HFDETO    FL_CMU_IsActiveFlag_XTHFFailOutput
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsActiveFlag_XTHFFailOutput(void)
{
    return (uint32_t)(READ_BIT(CMU->ISR, CMU_ISR_HFDETO_Msk) == (CMU_ISR_HFDETO_Msk));
}

/**
  * @brief    Get XTLF Vibrating Output
  * @rmtoll   ISR    LFDETO    FL_CMU_IsActiveFlag_XTLFFailOutput
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsActiveFlag_XTLFFailOutput(void)
{
    return (uint32_t)(READ_BIT(CMU->ISR, CMU_ISR_LFDETO_Msk) == (CMU_ISR_LFDETO_Msk));
}

/**
  * @brief    Get SYSCLK Select Error Flag
  * @rmtoll   ISR    SYSCSEIF    FL_CMU_IsActiveFlag_SysclkSecleError
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsActiveFlag_SysclkSecleError(void)
{
    return (uint32_t)(READ_BIT(CMU->ISR, CMU_ISR_SYSCSE_IF_Msk) == (CMU_ISR_SYSCSE_IF_Msk));
}

/**
  * @brief    Clear SYSCLK Select Error Flag
  * @rmtoll   ISR    SYSCSEIF    FL_CMU_ClearFlag_SysclkSecleError
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_ClearFlag_SysclkSecleError(void)
{
    WRITE_REG(CMU->ISR, CMU_ISR_SYSCSE_IF_Msk);
}

/**
  * @brief    Get XTHF Vibrating Flag
  * @rmtoll   ISR    HFDETIF    FL_CMU_IsActiveFlag_XTHFFail
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsActiveFlag_XTHFFail(void)
{
    return (uint32_t)(READ_BIT(CMU->ISR, CMU_ISR_HFDETIF_Msk) == (CMU_ISR_HFDETIF_Msk));
}

/**
  * @brief    Clear XTHF Vibrating Flag
  * @rmtoll   ISR    HFDETIF    FL_CMU_ClearFlag_XTHFFail
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_ClearFlag_XTHFFail(void)
{
    WRITE_REG(CMU->ISR, CMU_ISR_HFDETIF_Msk);
}

/**
  * @brief    Get XTLF Vibrating Output
  * @rmtoll   ISR    LFDETIF    FL_CMU_IsActiveFlag_XTLFFail
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsActiveFlag_XTLFFail(void)
{
    return (uint32_t)(READ_BIT(CMU->ISR, CMU_ISR_LFDETIF_Msk) == (CMU_ISR_LFDETIF_Msk));
}

/**
  * @brief    Clear XTLF Vibrating Output
  * @rmtoll   ISR    LFDETIF    FL_CMU_ClearFlag_XTLFFail
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_ClearFlag_XTLFFail(void)
{
    WRITE_REG(CMU->ISR, CMU_ISR_LFDETIF_Msk);
}

/**
  * @brief    Enable Group1 Periph Bus Clock
  * @rmtoll   PCLKCR1        FL_CMU_EnableGroup1BusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref   FL_CMU_GROUP1_BUSCLK_LPTIM16
  *           @arg @ref   FL_CMU_GROUP1_BUSCLK_RTC
  *           @arg @ref   FL_CMU_GROUP1_BUSCLK_PMU
  *           @arg @ref   FL_CMU_GROUP1_BUSCLK_SCU
  *           @arg @ref   FL_CMU_GROUP1_BUSCLK_IWDT
  *           @arg @ref   FL_CMU_GROUP1_BUSCLK_ANAC
  *           @arg @ref   FL_CMU_GROUP1_BUSCLK_PAD
  *           @arg @ref   FL_CMU_GROUP1_BUSCLK_SVD
  *           @arg @ref   FL_CMU_GROUP1_BUSCLK_COMP
  *           @arg @ref   FL_CMU_GROUP1_BUSCLK_SENT0
  *           @arg @ref   FL_CMU_GROUP1_BUSCLK_SENT1
  *           @arg @ref   FL_CMU_GROUP1_BUSCLK_LED
  *           @arg @ref   FL_CMU_GROUP1_BUSCLK_LCD
  *           @arg @ref   FL_CMU_GROUP1_BUSCLK_CLM1 
  *           @arg @ref   FL_CMU_GROUP1_BUSCLK_CLM0
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableGroup1BusClock(uint32_t Peripheral)
{
    SET_BIT(CMU->PCLKCR1, ((Peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Enable Group2 Periph Bus Clock
  * @rmtoll   PCLKCR2        FL_CMU_EnableGroup2BusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_CRC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_RNG
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_AES
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_DMA
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_FLASH
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_RAMBIST
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_WWDT
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_ADC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_DAC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_OPA
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_PGL
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableGroup2BusClock(uint32_t Peripheral)
{
    SET_BIT(CMU->PCLKCR2, ((Peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Enable Group3 Periph Bus Clock
  * @rmtoll   PCLKCR3        FL_CMU_EnableGroup3BusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART2
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART3
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART4
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_FSCAN
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UARTIR
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB1
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableGroup3BusClock(uint32_t Peripheral)
{
    SET_BIT(CMU->PCLKCR3, ((Peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Enable Group4 Periph Bus Clock
  * @rmtoll   PCLKCR4        FL_CMU_EnableGroup4BusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GPTIM0
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GPTIM1
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_ATIM
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_BSTIM16
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_TAU0
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_DIVAS
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableGroup4BusClock(uint32_t Peripheral)
{
    SET_BIT(CMU->PCLKCR4, ((Peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable Group1 Periph Bus Clock
  * @rmtoll   PCLKCR1        FL_CMU_DisableGroup1BusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_LPTIM16
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_RTC
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_PMU
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_SCU
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_IWDT
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_ANAC
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_PAD
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_SVD
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_COMP
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_SENT0
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_SENT1
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_LED
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_LCD
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_CLM1
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_CLM0
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableGroup1BusClock(uint32_t Peripheral)
{
    CLEAR_BIT(CMU->PCLKCR1, ((Peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable Group2 Periph Bus Clock
  * @rmtoll   PCLKCR2        FL_CMU_DisableGroup2BusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_CRC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_RNG
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_AES
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_DMA
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_FLASH
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_RAMBIST
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_WWDT
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_ADC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_DAC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_OPA
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_PGL
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableGroup2BusClock(uint32_t Peripheral)
{
    CLEAR_BIT(CMU->PCLKCR2, ((Peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable Group3 Periph Bus Clock
  * @rmtoll   PCLKCR3        FL_CMU_DisableGroup3BusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART2
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART3
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART4
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_FSCAN
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UARTIR
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB1
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableGroup3BusClock(uint32_t Peripheral)
{
    CLEAR_BIT(CMU->PCLKCR3, ((Peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable Group4 Periph Bus Clock
  * @rmtoll   PCLKCR4        FL_CMU_DisableGroup4BusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GPTIM0
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GPTIM1
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_ATIM
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_BSTIM16
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_TAU0
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_DIVAS
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableGroup4BusClock(uint32_t Peripheral)
{
    CLEAR_BIT(CMU->PCLKCR4, ((Peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get Group1 Periph Bus Clock Enable Status
  * @rmtoll   PCLKCR1        FL_CMU_IsEnabledGroup1BusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_LPTIM16
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_RTC
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_PMU
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_SCU
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_IWDT
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_ANAC
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_PAD
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_SVD
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_COMP
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_SENT0
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_SENT1
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_LED
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_LCD
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_CLM1
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_CLM0
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledGroup1BusClock(uint32_t Peripheral)
{
    return (uint32_t)(READ_BIT(CMU->PCLKCR1, ((Peripheral & 0xffffffff) << 0x0U)) == ((Peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get Group2 Periph Bus Clock Enable Status
  * @rmtoll   PCLKCR2        FL_CMU_IsEnabledGroup2BusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_CRC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_RNG
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_AES
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_DMA
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_FLASH
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_RAMBIST
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_WWDT
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_ADC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_DAC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_OPA
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_PGL
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledGroup2BusClock(uint32_t Peripheral)
{
    return (uint32_t)(READ_BIT(CMU->PCLKCR2, ((Peripheral & 0xffffffff) << 0x0U)) == ((Peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get Group3 Periph Bus Clock Enable Status
  * @rmtoll   PCLKCR3        FL_CMU_IsEnabledGroup3BusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART2
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART3
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART4
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_FSCAN
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UARTIR
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB1
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledGroup3BusClock(uint32_t Peripheral)
{
    return (uint32_t)(READ_BIT(CMU->PCLKCR3, ((Peripheral & 0xffffffff) << 0x0U)) == ((Peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get Group4 Periph Bus Clock Enable Status
  * @rmtoll   PCLKCR4        FL_CMU_IsEnabledGroup4BusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GPTIM0
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GPTIM1
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_ATIM
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_BSTIM16
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_TAU0
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_DIVAS
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledGroup4BusClock(uint32_t Peripheral)
{
    return (uint32_t)(READ_BIT(CMU->PCLKCR4, ((Peripheral & 0xffffffff) << 0x0U)) == ((Peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Enable Group1 Periph Operation Clock
  * @rmtoll   OPCER1        FL_CMU_EnableGroupOperationClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_EXTI
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_FLASH
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_LPUART1
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_LPUART0
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_LED
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_RNG
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_I2CSMB1
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_I2CSMB0
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_ATIM
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_UART3
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_UART2
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_UART1
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_UART0
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_BSTIM16
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_LPTIM16
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableGroup1OperationClock(uint32_t Peripheral)
{
    SET_BIT(CMU->OPCER1, ((Peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable Group1 Periph Operation Clock
  * @rmtoll   OPCER1        FL_CMU_DisableGroupOperationClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_EXTI
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_FLASH
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_LPUART1
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_LPUART0
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_LED
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_RNG
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_I2CSMB1
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_I2CSMB0
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_ATIM
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_UART3
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_UART2
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_UART1
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_UART0
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_BSTIM16
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_LPTIM16
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableGroup1OperationClock(uint32_t Peripheral)
{
    CLEAR_BIT(CMU->OPCER1, ((Peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get Group1 Periph Operation Clock Enable Status
  * @rmtoll   OPCCR1        FL_CMU_IsEnabledGroupOperationClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_EXTI
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_FLASH
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_LPUART1
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_LPUART0
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_LED
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_RNG
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_I2CSMB1
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_I2CSMB0
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_ATIM
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_UART3
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_UART2
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_UART1
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_UART0
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_BSTIM16
  *           @arg @ref FL_CMU_GROUP1_OPCLKEN_LPTIM16
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledGroup1OperationClock(uint32_t Peripheral)
{
    return (uint32_t)(READ_BIT(CMU->OPCER1, ((Peripheral & 0xffffffff) << 0x0U)) == ((Peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Enable Group2 Periph Operation Clock
  * @rmtoll   OPCER2        FL_CMU_EnableGroup2OperationClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP2_OPCLKEN_FSCAN
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableGroup2OperationClock(uint32_t Peripheral)
{
    SET_BIT(CMU->OPCER2, ((Peripheral & 0xffffffff) << 0x0U));
}


/**
  * @brief    Disable Group2 Periph Operation Clock
  * @rmtoll   OPCER2        FL_CMU_DisableGroup2OperationClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP2_OPCLKEN_FSCAN
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableGroup2OperationClock(uint32_t Peripheral)
{
    CLEAR_BIT(CMU->OPCER2, ((Peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get Group2 Periph Operation Clock Enable Status
  * @rmtoll   OPCCR2        FL_CMU_IsEnabledGrou2pOperationClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP2_OPCLKEN_FSCAN
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledGroup2OperationClock(uint32_t Peripheral)
{
    return (uint32_t)(READ_BIT(CMU->OPCER2, ((Peripheral & 0xffffffff) << 0x0U)) == ((Peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Set EXTI Clock Source
  * @rmtoll   OPCCR1    EXTICKS    FL_CMU_SetEXTIClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_EXTI_CLK_SOURCE_AHBCLK
  *           @arg @ref FL_CMU_EXTI_CLK_SOURCE_RCLP
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetEXTIClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_EXTICKS_Msk, clock);
}

/**
  * @brief    Get EXTI Clock Source Setting
  * @rmtoll   OPCCR1    EXTICKS    FL_CMU_GetEXTIClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_EXTI_CLK_SOURCE_AHBCLK
  *           @arg @ref FL_CMU_EXTI_CLK_SOURCE_RCLP
  */
__STATIC_INLINE uint32_t FL_CMU_GetEXTIClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_EXTICKS_Msk));
}

/**
  * @brief    Set LPUART1 Clock Source
  * @rmtoll   OPCCR1    LPUART1CKS    FL_CMU_SetLPUART1ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_LPUART1_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_LPUART1_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_LPUART1_CLK_SOURCE_RCLP
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetLPUART1ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_LPUART1CKS_Msk, clock);
}

/**
  * @brief    Get LPUART1 Clock Source Setting
  * @rmtoll   OPCCR1    LPUART1CKS    FL_CMU_GetLPUART1ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_LPUART1_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_LPUART1_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_LPUART1_CLK_SOURCE_RCLP
  */
__STATIC_INLINE uint32_t FL_CMU_GetLPUART1ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_LPUART1CKS_Msk));
}

/**
  * @brief    Set LPUART0 Clock Source
  * @rmtoll   OPCCR1    LPUART0CKS    FL_CMU_SetLPUART0ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_LPUART0_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_LPUART0_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_LPUART0_CLK_SOURCE_RCLP
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetLPUART0ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_LPUART0CKS_Msk, clock);
}

/**
  * @brief    Get LPUART0 Clock Source Setting
  * @rmtoll   OPCCR1    LPUART0CKS    FL_CMU_GetLPUART0ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_LPUART0_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_LPUART0_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_LPUART0_CLK_SOURCE_RCLP
  */
__STATIC_INLINE uint32_t FL_CMU_GetLPUART0ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_LPUART0CKS_Msk));
}

/**
  * @brief    Set I2CSMB1 Clock Source
  * @rmtoll   OPCCR1    I2CSMB1CKS    FL_CMU_SetI2CSMB1ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_I2CSMB1_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_I2CSMB1_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_I2CSMB1_CLK_SOURCE_SYSCLK
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetI2CSMB1ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_I2CSMB1CKS_Msk, clock);
}

/**
  * @brief    Get I2CSMB1 Clock Source Setting
  * @rmtoll   OPCCR1    I2CSMB1CKS    FL_CMU_GetI2CSMB1ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_I2CSMB1_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_I2CSMB1_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_I2CSMB1_CLK_SOURCE_SYSCLK
  */
__STATIC_INLINE uint32_t FL_CMU_GetI2CSMB1ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_I2CSMB1CKS_Msk));
}

/**
  * @brief    Set I2CSMB0 Clock Source
  * @rmtoll   OPCCR1    I2CSMB0CKS    FL_CMU_SetI2CSMB0ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_I2CSMB0_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_I2CSMB0_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_I2CSMB0_CLK_SOURCE_SYSCLK
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetI2CSMB0ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_I2CSMB0CKS_Msk, clock);
}

/**
  * @brief    Get I2CSMB0 Clock Source Setting
  * @rmtoll   OPCCR1    I2CSMB0CKS    FL_CMU_GetI2CSMB0ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_I2CSMB0_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_I2CSMB0_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_I2CSMB0_CLK_SOURCE_SYSCLK
  */
__STATIC_INLINE uint32_t FL_CMU_GetI2CSMB0ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_I2CSMB0CKS_Msk));
}

/**
  * @brief    Set BSTIM16 Clock Source
  * @rmtoll   OPCCR1    BT16CKS    FL_CMU_SetBSTIM16ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_BSTIM16_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_BSTIM16_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_BSTIM16_CLK_SOURCE_RCLP
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetBSTIM16ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_BT16CKS_Msk, clock);
}

/**
  * @brief    Get BSTIM16 Clock Source Setting
  * @rmtoll   OPCCR1    BT16CKS    FL_CMU_GetBSTIM16ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_BSTIM16_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_BSTIM16_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_BSTIM16_CLK_SOURCE_RCLP
  */
__STATIC_INLINE uint32_t FL_CMU_GetBSTIM16ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_BT16CKS_Msk));
}

/**
  * @brief    Set UART3 Clock Source
  * @rmtoll   OPCCR1    UART3CKS    FL_CMU_SetUART3ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_XTHF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetUART3ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_UART3CKS_Msk, clock);
}

/**
  * @brief    Get UART3 Clock Source Setting
  * @rmtoll   OPCCR1    UART3CKS    FL_CMU_GetUART3ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_XTHF
  */
__STATIC_INLINE uint32_t FL_CMU_GetUART3ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_UART3CKS_Msk));
}

/**
  * @brief    Set LPTIM16 Clock Source
  * @rmtoll   OPCCR1    LPT16CKS    FL_CMU_SetLPTIM16ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_LPTIM16_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_LPTIM16_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_LPTIM16_CLK_SOURCE_RCLP
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetLPTIM16ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_LPT16CKS_Msk, clock);
}

/**
  * @brief    Get LPTIM16 Clock Source Setting
  * @rmtoll   OPCCR1    LPT16CKS    FL_CMU_GetLPTIM16ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_LPTIM16_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_LPTIM16_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_LPTIM16_CLK_SOURCE_RCLP
  */
__STATIC_INLINE uint32_t FL_CMU_GetLPTIM16ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_LPT16CKS_Msk));
}

/**
  * @brief    Set UART2 Clock Source
  * @rmtoll   OPCCR1    UART2CKS    FL_CMU_SetUART2ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_XTHF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetUART2ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_UART2CKS_Msk, clock);
}

/**
  * @brief    Get UART2 Clock Source Setting
  * @rmtoll   OPCCR1    UART2CKS    FL_CMU_GetUART2ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_XTHF
  */
__STATIC_INLINE uint32_t FL_CMU_GetUART2ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_UART2CKS_Msk));
}

/**
  * @brief    Set ATIM Clock Source
  * @rmtoll   OPCCR1    ATIMCKS    FL_CMU_SetATIMClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_ATIM_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_ATIM_CLK_SOURCE_PLL
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetATIMClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_ATIMCKS_Msk, clock);
}

/**
  * @brief    Get ATIM Clock Source Setting
  * @rmtoll   OPCCR1    ATIMCKS    FL_CMU_GetATIMClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_ATIM_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_ATIM_CLK_SOURCE_PLL
  */
__STATIC_INLINE uint32_t FL_CMU_GetATIMClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_ATIMCKS_Msk));
}

/**
  * @brief    Set UART1 Clock Source
  * @rmtoll   OPCCR1    UART1CKS    FL_CMU_SetUART1ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_XTHF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetUART1ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_UART1CKS_Msk, clock);
}

/**
  * @brief    Get UART1 Clock Source Setting
  * @rmtoll   OPCCR1    UART1CKS    FL_CMU_GetUART1ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_XTHF
  */
__STATIC_INLINE uint32_t FL_CMU_GetUART1ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_UART1CKS_Msk));
}

/**
  * @brief    Set UART0 Clock Source
  * @rmtoll   OPCCR1    UART0CKS    FL_CMU_SetUART0ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_XTHF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetUART0ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_UART0CKS_Msk, clock);
}

/**
  * @brief    Get UART0 Clock Source Setting
  * @rmtoll   OPCCR1    UART0CKS    FL_CMU_GetUART0ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_APB1CLK
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_XTHF
  */
__STATIC_INLINE uint32_t FL_CMU_GetUART0ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_UART0CKS_Msk));
}

/**
  * @brief    Set RTC Prescaler
  * @rmtoll   OPCCR2    RTCPRSC    FL_CMU_SetRTCPrescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref 
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetRTCPrescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->OPCCR2, (0x3ffU << 22U), (prescaler << 22U));
}

/**
  * @brief    Get RTC Prescaler Setting
  * @rmtoll   OPCCR2    RTCPRSC    FL_CMU_GetRTCPrescaler
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_CMU_GetRTCPrescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR2, (0x3ffU << 22U)) >> 22U);
}

/**
  * @brief    Set RTC Clock Source
  * @rmtoll   OPCCR2    RTCCKS    FL_CMU_SetRTCClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_RTC_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_RTC_CLK_SOURCE_XTHF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetRTCClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR2, CMU_OPCCR2_RTCCKS_Msk, clock);
}

/**
  * @brief    Get RTC Clock Source Setting
  * @rmtoll   OPCCR2    RTCCKS    FL_CMU_GetRTCClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_RTC_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_RTC_CLK_SOURCE_XTHF
  */
__STATIC_INLINE uint32_t FL_CMU_GetRTCClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR2, CMU_OPCCR2_RTCCKS_Msk));
}

/**
  * @brief    Set FSCAN Clock Source
  * @rmtoll   OPCCR2    FSCANCKS    FL_CMU_SetFSCANClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_PLL
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_APBCLK
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetFSCANClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR2, CMU_OPCCR2_FSCANCKS_Msk, clock);
}

/**
  * @brief    Get FSCAN Clock Source Setting
  * @rmtoll   OPCCR2    FSCANCKS    FL_CMU_GetFSCANClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_PLL
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_APBCLK
  */
__STATIC_INLINE uint32_t FL_CMU_GetFSCANClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR2, CMU_OPCCR2_FSCANCKS_Msk));
}

/**
  * @brief    Set LED Clock Source
  * @rmtoll   OPCCR2    LEDCKS    FL_CMU_SetLEDClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_LED_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_LED_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_LED_CLK_SOURCE_PLL
  *           @arg @ref FL_CMU_LED_CLK_SOURCE_APBCLK
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetLEDClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR2, CMU_OPCCR2_LEDCKS_Msk, clock);
}

/**
  * @brief    Get LED Clock Source Setting
  * @rmtoll   OPCCR2    LEDCKS    FL_CMU_GetLEDClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_LED_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_LED_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_LED_CLK_SOURCE_PLL
  *           @arg @ref FL_CMU_LED_CLK_SOURCE_APBCLK
  */
__STATIC_INLINE uint32_t FL_CMU_GetLEDClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR2, CMU_OPCCR2_LEDCKS_Msk));
}

/**
  * @brief    Set RNG Prescaler
  * @rmtoll   OPCCR2    RNGPRSC    FL_CMU_SetRNGPrescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref FL_CMU_RNG_PSC_DIV1
  *           @arg @ref FL_CMU_RNG_PSC_DIV2
  *           @arg @ref FL_CMU_RNG_PSC_DIV4
  *           @arg @ref FL_CMU_RNG_PSC_DIV8
  *           @arg @ref FL_CMU_RNG_PSC_DIV16
  *           @arg @ref FL_CMU_RNG_PSC_DIV32
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetRNGPrescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->OPCCR2, CMU_OPCCR2_RNGPRSC_Msk, prescaler);
}

/**
  * @brief    Get RNG Prescaler Setting
  * @rmtoll   OPCCR2    RNGPRSC    FL_CMU_GetRNGPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_RNG_PSC_DIV1
  *           @arg @ref FL_CMU_RNG_PSC_DIV2
  *           @arg @ref FL_CMU_RNG_PSC_DIV4
  *           @arg @ref FL_CMU_RNG_PSC_DIV8
  *           @arg @ref FL_CMU_RNG_PSC_DIV16
  *           @arg @ref FL_CMU_RNG_PSC_DIV32
  */
__STATIC_INLINE uint32_t FL_CMU_GetRNGPrescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR2, CMU_OPCCR2_RNGPRSC_Msk));
}

/**
  * @brief    Set LED Prescaler
  * @rmtoll   OPCCR2    LEDPRSC    FL_CMU_SetLEDPrescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref FL_CMU_LED_PSC_DIV1
  *           @arg @ref FL_CMU_LED_PSC_DIV2
  *           @arg @ref FL_CMU_LED_PSC_DIV4
  *           @arg @ref FL_CMU_LED_PSC_DIV8
  *           @arg @ref FL_CMU_LED_PSC_DIV16
  *           @arg @ref FL_CMU_LED_PSC_DIV32
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetLEDPrescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->OPCCR2, CMU_OPCCR2_LEDPRSC_Msk, prescaler);
}

/**
  * @brief    Get LED Prescaler Setting
  * @rmtoll   OPCCR2    LEDPRSC    FL_CMU_GetLEDPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_LED_PSC_DIV1
  *           @arg @ref FL_CMU_LED_PSC_DIV2
  *           @arg @ref FL_CMU_LED_PSC_DIV4
  *           @arg @ref FL_CMU_LED_PSC_DIV8
  *           @arg @ref FL_CMU_LED_PSC_DIV16
  *           @arg @ref FL_CMU_LED_PSC_DIV32
  */
__STATIC_INLINE uint32_t FL_CMU_GetLEDPrescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR2, CMU_OPCCR2_LEDPRSC_Msk));
}

/**
  * @brief    Set AHB Master Priority
  * @rmtoll   AHBMCR    MPRIL    FL_CMU_SetAHBMasterPriority
  * @param    priority This parameter can be one of the following values:
  *           @arg @ref FL_CMU_AHB_MASTER_PRIORITY_DMA_FIRST
  *           @arg @ref FL_CMU_AHB_MASTER_PRIORITY_CPU_FIRST
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetAHBMasterPriority(uint32_t priority)
{
    MODIFY_REG(CMU->AHBMCR, CMU_AHBMCR_MPRIL_Msk, priority);
}

/**
  * @brief    Get AHB Master Priority Setting
  * @rmtoll   AHBMCR    MPRIL    FL_CMU_GetAHBMasterPriority
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_AHB_MASTER_PRIORITY_DMA_FIRST
  *           @arg @ref FL_CMU_AHB_MASTER_PRIORITY_CPU_FIRST
  */
__STATIC_INLINE uint32_t FL_CMU_GetAHBMasterPriority(void)
{
    return (uint32_t)(READ_BIT(CMU->AHBMCR, CMU_AHBMCR_MPRIL_Msk));
}

/**
  * @brief    Set LSCLK Clock Source
  * @rmtoll   LSCLKSEL    SEL    FL_CMU_SetLSCLKClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_LSCLK_CLK_SOURCE_RCLP
  *           @arg @ref FL_CMU_LSCLK_CLK_SOURCE_XTLF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetLSCLKClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->LSCLKSEL, CMU_LSCLKSEL_SEL_Msk, clock);
}
/**
  * @}
  */

/** @defgroup CMU_FL_EF_Init Initialization and de-initialization functions
  * @{
  */

/**
  * @}
  */


/** @defgroup CMU_FL_EF_Operation Opeartion functions
  * @{
  */

uint32_t FL_CMU_GetSystemClockFreq(void);
uint32_t FL_CMU_GetAHBClockFreq(void);
uint32_t FL_CMU_GetAPBClockFreq(void);

uint32_t FL_CMU_GetRCMFClockFreq(void);
uint32_t FL_CMU_GetRCHFClockFreq(void);
uint32_t FL_CMU_GetPLLClockFreq(void);

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

#endif /* __FM33LE0XX_FL_CMU_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.2 @ 2021-07-08*************************/
/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
