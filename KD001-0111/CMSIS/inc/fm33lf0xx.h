
/****************************************************************************************************//**
 * @file     FM33LF0XX.h
 *
 * @brief    CMSIS Cortex-M0 Peripheral Access Layer Header File for
 *           FM33LF0XX from Keil.
 *
 * @version  V0.0.1
 * @date     09. may 2023
 *
 * @note     Generated with SVDConv V2.87e 
 *           from CMSIS SVD File 'FM33LF0XX.SVD' Version 1.0,
 *
 * @par      ARM Limited (ARM) is supplying this software for use with Cortex-M
 *           processor based microcontroller, but can be equally used for other
 *           suitable processor architectures. This file can be freely distributed.
 *           Modifications to this file shall be clearly marked.
 *           
 *           THIS SOFTWARE IS PROVIDED "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 *           OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 *           MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 *           ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 *           CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER. 
 *
 *******************************************************************************************************/


/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup FM33LF0XX
  * @{
  */

#ifndef __FM33LF0XX_H
#define __FM33LF0XX_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
  * @brief Configuration of the Cortex-M0 Processor and Core Peripherals 
  */
#define __CM0_REV                    0x0100U /*!< Cortex-M0 Core Revision                                               */
#define __MPU_PRESENT                0U      /*!< MPU present or not                                                    */
#define __VTOR_PRESENT               1U      /*!< VTOR present or not                                                   */
#define __NVIC_PRIO_BITS             2U      /*!< Number of Bits used for Priority Levels                               */
#define __Vendor_SysTickConfig       0U      /*!< Set to 1 if different SysTick Config is used                          */


/**
 * @brief FM33LF0XX Interrupt Number Definition, according to the selected device 
 *        in @ref Library_configuration_section 
 */
typedef enum {
/******  Cortex-M0 Processor Exceptions Numbers ****************************************************************/
  Reset_IRQn                    = -15,     /*!<  1  Reset Vector, invoked on Power up and warm reset           */
  NMI_IRQn                      = -14,     /*!<  2  Non maskable Interrupt, cannot be stopped or preempted     */
  HardFault_IRQn                = -13,     /*!<  3  Hard Fault, all classes of Fault                           */
  SVCall_IRQn                   = -5,      /*!<  11  System Service Call via SVC instruction                   */
  PendSV_IRQn                   = -2,      /*!<  14  Pendable request for system service                       */
  SysTick_IRQn                  = -1,      /*!<  15  System Tick Timer                                         */
/******  FM33LF0XX specific Interrupt Numbers ******************************************************************/
  WDT_IRQn                      = 0,       /*!<  0    WWDT and IWDT Interrupt                                  */
  SVD_IRQn                      = 1,       /*!<  1    SVD Interrupt                                            */
  RTC_IRQn                      = 2,       /*!<  2    RTC Interrupt                                            */
  FLASH_IRQn                    = 3,       /*!<  3    FLASH global Interrupt                                   */ 
  FDET_IRQn                     = 4,       /*!<  4    FDET Interrupt                                           */
  ADC_IRQn                      = 5,       /*!<  5    ADC Interrupt                                            */
  RAMP_IRQn                     = 6,       /*!<  6    RAM parity check Interrupt                               */
  SPI0_IRQn                     = 7,       /*!<  7    SPI0 Interrupt                                           */
  SPI1_IRQn                     = 8,       /*!<  8    SPI1 Interrupt                                           */
  DAC_IRQn                      = 9,       /*!<  9    DAC Interrupt                                            */
  UART0_IRQn                    = 10,      /*!<  10   UART0 global Interrupt                                   */
  UART1_IRQn                    = 11,      /*!<  11   UART1 global Interrupt                                   */
  UART2_IRQn                    = 12,      /*!<  12   UART2 global Interrupt                                   */
  UART3_IRQn                    = 13,      /*!<  13   UART3 global Interrupt                                   */ 
  UART4_IRQn                    = 14,      /*!<  14   UART4 global Interrupt                                   */
  FSCAN_IRQn                    = 15,      /*!<  15   FSCAN Interrupt                                          */
  LPUARTx_IRQn                  = 16,      /*!<  16   LPUARTx Interrupt                                        */
  I2CSMBx_IRQn                  = 17,      /*!<  17   I2Cx global Interrupt                                    */
  CLM_PGL_IRQ                   = 18,      /*!<  18   CLM and PGL Interrupt                                    */
  AES_IRQn                      = 19,      /*!<  19   AES Interrupt                                            */ 
  LPTIM16_IRQn                  = 20,      /*!<  20   LPTIM16 Interrupt                                        */
  DMA_IRQn                      = 21,      /*!<  21   DMA Interrupt                                            */
  WKUPx_IRQn                    = 22,      /*!<  22   WKUP Interrupt                                           */
  SENTx_IRQn                    = 23,      /*!<  23   SENT Interrupt                                           */
  BSTIM16_IRQn                  = 24,      /*!<  24   BSTIM16 Interrupt                                        */
  COMPx_IRQn                    = 25,      /*!<  25   COMPx Interrupt                                          */
  GPTIM0_IRQn                   = 26,      /*!<  26   GTIM0 global Interrupt                                   */
  GPTIM1_IRQn                   = 27,      /*!<  27   GTIM1 global Interrupt                                   */
  ATIM_IRQn                     = 28,      /*!<  28   ATIM global Interrupt                                    */
  TAU0_IRQn                      = 29,      /*!<  29   TAU0 Interrupt                                          */
  GPIO_IRQn                     = 30,      /*!<  30   GPIO Interrupt                                           */
  LED_LCD_IRQn                  = 31       /*!<  31   LED and LCD Interrupt                                    */
} IRQn_Type;


/** @addtogroup Configuration_of_CMSIS
  * @{
  */


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */


#include "core_cm0plus.h"                            /*!< Cortex-M0 processor and core peripherals             */
#include "system_fm33lf0xx.h"                        /*!< FM33LF0XX System                                     */
#include <stdint.h>

/** @addtogroup Peripheral_registers_structures
  * @{
  */   

/** 
  * @brief Analog to Digital Converter  
  */
typedef struct
{
  __IO uint32_t ACQ_ISR;              	/*!< ACQ Interrupt and Status Flag Register,              Address offset: 0x00 */
  __IO uint32_t ACQ_IER;              	/*!< ACQ Interrupt Enable Register,                       Address offset: 0x04 */
  __IO uint32_t GISR;                	/*!< ADC General Interrupt and Status Flag Register,      Address offset: 0x08 */
  __IO uint32_t GIER;                	/*!< ADC General Interrupt Enable Register,               Address offset: 0x0C */
  __IO uint32_t CR1;                 	/*!< ADC Control Register1,                               Address offset: 0x10 */
  __IO uint32_t CR2;                 	/*!< ADC Control Register2,                               Address offset: 0x14 */
  __IO uint32_t RSV0;                	/*!< RESERVED REGISTER0,                                  Address offset: 0x18 */
  __IO uint32_t CFGR1;               	/*!< ADC Config Register1,                                Address offset: 0x1C */
  __IO uint32_t CFGR2;               	/*!< ADC Config Register2,                                Address offset: 0x20 */
  __IO uint32_t RSV1;                	/*!< RESERVED REGISTER1,                                  Address offset: 0x24 */
  __IO uint32_t RSV2;                	/*!< RESERVED REGISTER2,                                  Address offset: 0x28 */
  __IO uint32_t OSR;                 	/*!< ADC Channel Enable Register,                         Address offset: 0x2C */
  __IO uint32_t ACQ_SR;               	/*!< ADC Channel Enable Register,                         Address offset: 0x30 */
  __IO uint32_t ACQ_SACR;             	/*!< ADC Channel Enable Register,                         Address offset: 0x34 */
  __IO uint32_t HLTR;                	/*!< ADC Channel Enable Register,                         Address offset: 0x38 */
  __IO uint32_t AWDCR;               	/*!< ADC Channel Enable Register,                         Address offset: 0x3C */
  __IO uint32_t ACQ0_CR;              	/*!< ADC Channel Enable Register,                         Address offset: 0x40 */
  __IO uint32_t ACQ1_CR;              	/*!< ADC Channel Enable Register,                         Address offset: 0x44 */
  __IO uint32_t ACQ2_CR;              	/*!< ADC Channel Enable Register,                         Address offset: 0x48 */
  __IO uint32_t ACQ3_CR;              	/*!< ADC Channel Enable Register,                         Address offset: 0x4C */
  __IO uint32_t SCANACQ_CR;           	/*!< ADC Channel Enable Register,                         Address offset: 0x50 */
  __IO uint32_t RSV3[11];             	/*!< ADC Channel Enable Register,                         Address offset: 0x54 */
  __IO uint32_t ACQ0_DR;              	/*!< ADC Channel Enable Register,                         Address offset: 0x80 */
  __IO uint32_t ACQ1_DR;              	/*!< ADC Channel Enable Register,                         Address offset: 0x84 */
  __IO uint32_t ACQ2_DR;              	/*!< ADC Channel Enable Register,                         Address offset: 0x88 */
  __IO uint32_t ACQ3_DR;              	/*!< ADC Channel Enable Register,                         Address offset: 0x8C */
  __IO uint32_t SCANACQ_DR;           	/*!< ADC Channel Enable Register,                         Address offset: 0x90 */	
} ADC_Type;

typedef struct
{
  __IO uint32_t CR;               		/*!< AES Control Register,                                Address offset: 0x00 */
  __IO uint32_t IER;              		/*!< AES Interrupt Enable Register,                       Address offset: 0x04 */
  __IO uint32_t ISR;              		/*!< AES Interrupt Status Register,                       Address offset: 0x08 */
  __IO uint32_t DIR;              		/*!< AES Data Input Register,                             Address offset: 0x0C */
  __IO uint32_t DOR;              		/*!< AES Data Output Register,                            Address offset: 0x10 */
  __IO uint32_t KEY0;             		/*!< AES Key Register 0,                                  Address offset: 0x14 */
  __IO uint32_t KEY1;             		/*!< AES Key Register 1,                                  Address offset: 0x18 */
  __IO uint32_t KEY2;             		/*!< AES Key Register 2,                                  Address offset: 0x1C */
  __IO uint32_t KEY3;             		/*!< AES Key Register 3,                                  Address offset: 0x20 */    
  __IO uint32_t KEY4;             		/*!< AES Key Register 4,                                  Address offset: 0x24 */    
  __IO uint32_t KEY5;             		/*!< AES Key Register 5,                                  Address offset: 0x28 */    
  __IO uint32_t KEY6;             		/*!< AES Key Register 6,                                  Address offset: 0x2C */
  __IO uint32_t KEY7;             		/*!< AES Key Register 7,                                  Address offset: 0x30 */
  __IO uint32_t IVR0;             		/*!< AES Initial Vector Register 0,                       Address offset: 0x34 */
  __IO uint32_t IVR1;             		/*!< AES Initial Vector Register 1,                       Address offset: 0x38 */
  __IO uint32_t IVR2;             		/*!< AES Initial Vector Register 2,                       Address offset: 0x3C */
  __IO uint32_t IVR3;             		/*!< AES Initial Vector Register 3,                       Address offset: 0x40 */
  __IO uint32_t H0;               		/*!< AES MultH Parametre Register 0,                      Address offset: 0x44 */
  __IO uint32_t H1;               		/*!< AES MultH Parametre Register 0,                      Address offset: 0x48 */
  __IO uint32_t H2;               		/*!< AES MultH Parametre Register 0,                      Address offset: 0x4C */
  __IO uint32_t H3;               		/*!< AES MultH Parametre Register 0,                      Address offset: 0x50 */
} AES_Type;

typedef struct
{
  __IO uint32_t CR1;              		/*!< ATIM Control Register1,                              Address offset: 0x00 */
  __IO uint32_t CR2;              		/*!< ATIM Control Register2,                              Address offset: 0x04 */
  __IO uint32_t SMCR;             		/*!< ATIM Slave Mode Control Register,                    Address offset: 0x08 */
  __IO uint32_t DIER;             		/*!< ATIM DMA and Interrupt Enable Register,              Address offset: 0x0C */
  __IO uint32_t ISR;              		/*!< ATIM Interrupt Status Register,                      Address offset: 0x10 */
  __IO uint32_t EGR;              		/*!< ATIM Event Generation Register,                      Address offset: 0x14 */
  __IO uint32_t CCMR1;            		/*!< ATIM Capture/Compare Mode Register1,                 Address offset: 0x18 */
  __IO uint32_t CCMR2;            		/*!< ATIM Capture/Compare Mode Register2,                 Address offset: 0x1C */
  __IO uint32_t CCER;             		/*!< ATIM Capture/Compare Enable Register,                Address offset: 0x20 */
  __IO uint32_t CNT;              		/*!< ATIM Counter Register,                               Address offset: 0x24 */
  __IO uint32_t PSC;              		/*!< ATIM Prescaler Register,                             Address offset: 0x28 */
  __IO uint32_t ARR;              		/*!< ATIM Auto-Reload Register,                           Address offset: 0x2C */
  __IO uint32_t RCR;              		/*!< ATIM Repetition Counter Register,                    Address offset: 0x30 */
  __IO uint32_t CCR1;             		/*!< ATIM Capture/Compare Register1,                      Address offset: 0x34 */
  __IO uint32_t CCR2;             		/*!< ATIM Capture/Compare Register2,                      Address offset: 0x38 */
  __IO uint32_t CCR3;             		/*!< ATIM Capture/Compare Register3,                      Address offset: 0x3C */
  __IO uint32_t CCR4;             		/*!< ATIM Capture/Compare Register4,                      Address offset: 0x40 */
  __IO uint32_t BDTR;             		/*!< ATIM Break and Deadtime Register,                    Address offset: 0x44 */
  __IO uint32_t CCMR3;            		/*!< ATIM Capture/Compare Mode Register3,                 Address offset: 0x48 */
  __IO uint32_t CCR5;             		/*!< ATIM Capture/Compare Register5,                      Address offset: 0x4C */
  __IO uint32_t CCR6;             		/*!< ATIM Capture/Compare Register6,                      Address offset: 0x50 */
  __IO uint32_t ECR;              		/*!< ATIM Encoder Mode Control Register,                  Address offset: 0x54 */
  __IO uint32_t TISEL;            		/*!< ATIM timer input selection Register,                 Address offset: 0x58 */
  __IO uint32_t AFR;              		/*!< ATIM alternate function Register,                    Address offset: 0x5C */
  __IO uint32_t RSV0[38];          		/*!< RESERVED REGISTER,                                   Address offset: 0x60 */
  __IO uint32_t DCR;              		/*!< ATIM DMA Control Register,                           Address offset: 0xF8 */
  __IO uint32_t DMAR;             		/*!< ATIM DMA Access Register,                            Address offset: 0xFC */
 
} ATIM_Type;

typedef struct
{
  __IO uint32_t CR1;              		/*!< BSTIM Control Register1,                             Address offset: 0x00 */
  __IO uint32_t CR2;              		/*!< BSTIM Control Register2,                             Address offset: 0x04 */
  __IO uint32_t RSV0;             		/*!< RESERVED REGISTER0,                                  Address offset: 0x08 */
  __IO uint32_t IER;              		/*!< BSTIM Interrupt Enable Register,                     Address offset: 0x0C */
  __IO uint32_t ISR;              		/*!< BSTIM Interrupt Status Register,                     Address offset: 0x10 */
  __IO uint32_t EGR;              		/*!< BSTIM Event Generation Register,                     Address offset: 0x14 */
  __IO uint32_t RSV1;             		/*!< RESERVED REGISTER1,                                  Address offset: 0x18 */
  __IO uint32_t RSV2;             		/*!< RESERVED REGISTER2,                                  Address offset: 0x1C */
  __IO uint32_t RSV3;             		/*!< RESERVED REGISTER3,                                  Address offset: 0x20 */
  __IO uint32_t CNT;              		/*!< BSTIM Counter Register,                              Address offset: 0x24 */
  __IO uint32_t PSC;              		/*!< BSTIM Prescaler Register,                            Address offset: 0x28 */
  __IO uint32_t ARR;              		/*!< BSTIM Auto-Reload Register,                          Address offset: 0x2C */
} BSTIM16_Type;

typedef struct
{
  __IO uint32_t CR;              		/*!< ComparatorControl Register 1,                        Address offset: 0x00 */

} COMP_Type;

typedef struct
{
  __IO uint32_t ICR;             		/*!< Comparator Interrupt Config Register,                Address offset: 0x00 */
  __IO uint32_t ISR;             		/*!< Comparator Interrupt Status Register,                Address offset: 0x04 */
  __IO uint32_t RSV0;            		/*!< RESERVED REGISTER0,                                  Address offset: 0x08 */  
  __IO uint32_t BUFCR;           		/*!< Comparator Interrupt Status Register,                Address offset: 0x0C */
} COMP_COMMON_Type;

typedef struct
{
  __IO uint32_t DR;               		/*!< CRC Data Register,                                   Address offset: 0x00 */
  __IO uint32_t CR;               		/*!< CRC Control Register,                                Address offset: 0x04 */
  __IO uint32_t LFSR;             		/*!< CRC Linear Feedback Shift Register,                  Address offset: 0x08 */
  __IO uint32_t XOR;              		/*!< CRC output XOR Register,                             Address offset: 0x0C */
  __IO uint32_t RSV0;             		/*!< RESERVED REGISTER0,                                  Address offset: 0x10 */
  __IO uint32_t RSV1;             		/*!< RESERVED REGISTER1,                                  Address offset: 0x14 */
  __IO uint32_t RSV2;             		/*!< RESERVED REGISTER2,                                  Address offset: 0x18 */
  __IO uint32_t POLY;             		/*!< CRC Polynominal Register,                            Address offset: 0x1C */
} CRC_Type;

typedef struct
{
  __IO uint32_t RSV0;
  __IO uint32_t RSV1;    
  __IO uint32_t CR;               		/*!< Debug Configuration Register */
  __IO uint32_t HDFR;             		/*!< HardFault Flag Register*/
    
} DBG_Type;

typedef struct
{
  __IO uint32_t CH0CR;                  /*!<  Channel 0 Control Register,                           Address offset: 0x00 */
  __IO uint32_t CH0CFGR;                /*!<  Channel 0 Config Register,                            Address offset: 0x04 */
  __IO uint32_t CH0PAR;                 /*!<  Channel 0 Peripheral Address Register,                Address offset: 0x08 */
  __IO uint32_t CH0MAR0;                /*!<  Channel 0 Memory Address Register0,                   Address offset: 0x0C */
  __IO uint32_t CH0MAR1;                /*!<  Channel 0 Memory Address Register1,                   Address offset: 0x10 */
  __IO uint32_t RSV1[3];                /*!<  RESERVED REGISTER,                                    Address offset: 0x14 */
  __IO uint32_t CH1CR;                  /*!<  Channel 1 Control Register,                           Address offset: 0x20 */
  __IO uint32_t CH1CFGR;                /*!<  Channel 1 Config Register,                            Address offset: 0x24 */
  __IO uint32_t CH1PAR;                 /*!<  Channel 1 Peripheral Address Register,                Address offset: 0x28 */
  __IO uint32_t CH1MAR0;                /*!<  Channel 1 Memory Address Register0,                   Address offset: 0x2C */
  __IO uint32_t CH1MAR1;                /*!<  Channel 1 Memory Address Register1,                   Address offset: 0x30 */
  __IO uint32_t RSV2[3];                /*!<  RESERVED REGISTER,                                    Address offset: 0x34 */
  __IO uint32_t CH2CR;                  /*!<  Channel 2 Control Register,                           Address offset: 0x40 */
  __IO uint32_t CH2CFGR;                /*!<  Channel 2 Config Register,                            Address offset: 0x44 */
  __IO uint32_t CH2PAR;                 /*!<  Channel 2 Peripheral Address Register,                Address offset: 0x48 */
  __IO uint32_t CH2MAR0;                /*!<  Channel 2 Memory Address Register0,                   Address offset: 0x4C */
  __IO uint32_t CH2MAR1;                /*!<  Channel 2 Memory Address Register1,                   Address offset: 0x50 */
  __IO uint32_t RSV3[3];                /*!<  RESERVED REGISTER,                                    Address offset: 0x54 */
  __IO uint32_t CH3CR;                  /*!<  Channel 3 Control Register,                           Address offset: 0x60 */
  __IO uint32_t CH3CFGR;                /*!<  Channel 3 Config Register,                            Address offset: 0x64 */
  __IO uint32_t CH3PAR;                 /*!<  Channel 3 Peripheral Address Register,                Address offset: 0x68 */
  __IO uint32_t CH3MAR0;                /*!<  Channel 3 Memory Address Register0,                   Address offset: 0x6C */
  __IO uint32_t CH3MAR1;                /*!<  Channel 3 Memory Address Register1,                   Address offset: 0x70 */
  __IO uint32_t RSV4[27];               /*!<  RESERVED REGISTER,                                    Address offset: 0x74 */
  __IO uint32_t CH7CR;                  /*!<  Channel 7 Control Register,                           Address offset: 0xE0 */
  __IO uint32_t CH7FAR;                 /*!<  Channel 7 Flash Address Register,                     Address offset: 0xE4 */
  __IO uint32_t CH7RAR;                 /*!<  Channel 7 RAM Address Register,                       Address offset: 0xE8 */
  __IO uint32_t RSV5[69];               /*!<  RESERVED REGISTER,                                    Address offset: 0xEC */
  __IO uint32_t GCR;                    /*!<  DMA Global Control Register,                          Address offset: 0x200 */
  __IO uint32_t SWRR;                   /*!<  DMA Software Request Register,                        Address offset: 0x204 */
  __IO uint32_t RSV6[62];               /*!<  RESERVED REGISTER,                                    Address offset: 0x208 */
  __IO uint32_t ISR;                    /*!<  DMA Interrupt Status Register,                        Address offset: 0x300 */
  __I  uint32_t CH0TFSADDR;             /*!<  ,                                                     Address offset: 0x304 */
  __I  uint32_t CH1TFSADDR;             /*!<  ,                                                     Address offset: 0x308 */
  __I  uint32_t CH2TFSADDR;             /*!<  ,                                                     Address offset: 0x30C */
  __I  uint32_t CH3TFSADDR;             /*!<  ,                                                     Address offset: 0x310 */
}DMA_Type;


typedef struct
{
  __IO uint32_t IER;              		/*!< XTLF Oscillation Fail Detection Interrupt Enable Register, Address offset: 0x00 */
  __IO uint32_t ISR;              		/*!< XTLF Oscillation Fail Detection Interrupt Status Register, Address offset: 0x04 */
}FDET_Type;


typedef struct
{
  __IO uint32_t RDCR;                   /*!<  Flash Read Control Register,                          Address offset: 0x00 */
  __IO uint32_t PFCR;                   /*!<  Flash Prefetch Control Register,                      Address offset: 0x04 */
  __IO uint32_t OPTBR;                	/*!<  Flash Option Bytes Register,                          Address offset: 0x08 */
  __IO uint32_t ACLOCK1;				/*!<  Flash Application Code Lock Register1,                Address offset: 0x0C */
  __IO uint32_t RSV1[1];  				/*!<  RESERVED REGISTER,                                    Address offset: 0x10 */
  __IO uint32_t EPCR;                   /*!<  Flash Erase/Program Control Register,                 Address offset: 0x14 */
  __O  uint32_t KEY;                    /*!<  Flash Key Register,                                   Address offset: 0x18 */
  __IO uint32_t IER;                    /*!<  Flash Interrupt Enable Register,                      Address offset: 0x1C */
  __IO uint32_t ISR;                    /*!<  Flash Interrupt Status Register,                      Address offset: 0x20 */
}FLASH_Type;


typedef struct
{
  __IO uint32_t INEN;             		/*!< Input Enable Register,                                 Address offset: 0x00*/
  __IO uint32_t PUDEN;             		/*!< Pull-Up Enable Register,                               Address offset: 0x04*/
  __IO uint32_t ODEN;             		/*!< Open-Drain Enable Register,                            Address offset: 0x08*/
  __IO uint32_t FCR;              		/*!< Function Control Register,                             Address offset: 0x0C*/
  __IO uint32_t DO;               		/*!< Data Output Register,                                  Address offset: 0x10*/    
  __O  uint32_t DSET;             		/*!< Data Set Register,                                     Address offset: 0x14*/
  __O  uint32_t DRST;             		/*!< Data Reset Register,                                   Address offset: 0x18*/
  __I uint32_t  DIN;              		/*!< Data Input Register,                                   Address offset: 0x1C*/
  __IO uint32_t DFS;              		/*!< Digital Function Select Register,                      Address offset: 0x20*/
  __IO uint32_t RSV0;              		/*!< RESERVED REGISTER,                                     Address offset: 0x24*/
  __IO uint32_t ANEN;             		/*!< Analog channel Enable Register,                        Address offset: 0x28*/
  __IO uint32_t DSR;             		/*!< Voltage Input Low Register,                            Address offset: 0x2C*/
} GPIO_Type;        

typedef struct
{
  __IO uint32_t EXTISEL;               	/*!<  External Interrupt Input Select Register0,            Address offset: 0x00 */
  __IO uint32_t RSV1;               	/*!<  External Interrupt Input Select Register1,            Address offset: 0x04 */
  __IO uint32_t EXTIEDS;               	/*!<  External Interrupt Edge Select and Enable Register0,  Address offset: 0x08 */
  __IO uint32_t RSV2;               	/*!<  External Interrupt Edge Select and Enable Register1,  Address offset: 0x0C */
  __IO uint32_t EXTIDF;                 /*!<  External Interrupt Digital Filter Register,           Address offset: 0x10 */
  __IO uint32_t EXTIISR;                /*!<  External Interrupt and Status Register,               Address offset: 0x14 */
  __I  uint32_t EXTIDI;                 /*!<  External Interrupt Data Input Register,               Address offset: 0x18 */
  __IO uint32_t RSV3[9];                /*!<  RESERVED REGISTER,                                    Address offset: 0x1C */
  __IO uint32_t FOUTSEL;                /*!<  Frequency Output Select Register,                     Address offset: 0x40 */
  __IO uint32_t RSV4[63];               /*!<  RESERVED REGISTER,                                    Address offset: 0x44 */
  __IO uint32_t PINWKEN;                /*!<  Wakeup Enable Register,                               Address offset: 0x140 */
}GPIO_COMMON_Type;


typedef struct
{
  __IO uint32_t CR1;              		/*!< GPTIM Control Register1,                               Address offset: 0x00 */
  __IO uint32_t CR2;              		/*!< GPTIM Control Register2,                               Address offset: 0x04 */
  __IO uint32_t SMCR;             		/*!< GPTIM Slave Mode Control Register,                     Address offset: 0x08 */
  __IO uint32_t DIER;             		/*!< GPTIM DMA and Interrupt Enable Register,               Address offset: 0x0C */
  __IO uint32_t ISR;              		/*!< GPTIM Interrupt Status Register,                       Address offset: 0x10 */
  __IO uint32_t EGR;              		/*!< GPTIM EVENT GENERATE REGISTER,                         Address offset: 0x14 */
  __IO uint32_t CCMR1;            		/*!< GPTIM Capture/Compare Mode Register1,                  Address offset: 0x18 */
  __IO uint32_t CCMR2;            		/*!< GPTIM Capture/Compare Mode Register2,                  Address offset: 0x1C */
  __IO uint32_t CCER;             		/*!< GPTIM Capture/Compare Enable Register,                 Address offset: 0x20 */
  __IO uint32_t CNT;              		/*!< GPTIM Counter Register,                                Address offset: 0x24 */
  __IO uint32_t PSC;              		/*!< GPTIM Prescaler Register,                              Address offset: 0x28 */
  __IO uint32_t ARR;              		/*!< GPTIM Auto-Reload Register,                            Address offset: 0x2C */
  __IO uint32_t RSV0;             		/*!< RESERVED REGISTER0,                                    Address offset: 0x30 */
  __IO uint32_t CCR1;             		/*!< GPTIM Capture/Compare Register1,                       Address offset: 0x34 */
  __IO uint32_t CCR2;             		/*!< GPTIM Capture/Compare Register2,                       Address offset: 0x38 */
  __IO uint32_t CCR3;             		/*!< GPTIM Capture/Compare Register3,                       Address offset: 0x3C */
  __IO uint32_t CCR4;             		/*!< GPTIM Capture/Compare Register4,                       Address offset: 0x40 */
  __IO uint32_t RSV1[4];          		/*!< RESERVED REGISTER1,                                    Address offset: 0x44 */
  __IO uint32_t ECR;              		/*!< GPTIM Encoder Control Register,                        Address offset: 0x54 */
  __IO uint32_t ITRSEL;           		/*!< GPTIM Internal Trigger Select Register,                Address offset: 0x58 */
  __IO uint32_t AFR;              		/*!< GPTIM AF Register,                                     Address offset: 0x5C */
  __IO uint32_t RSV2[38];				/*!< RESERVED REGISTER2,                                    Address offset: 0x60 */
	__IO uint32_t DCR;              	/*!< GPTIM DMA Control Register,                            Address offset: 0xF8 */
  __IO uint32_t DMAR;             		/*!< GPTIM DMA Busrt Register,                              Address offset: 0xFC */
} GPTIM_Type; 

typedef struct
{
  __IO uint32_t OPRD;             		/*!< Dividend Register,                                     Address offset: 0x00 */
  __IO uint32_t SOR;              		/*!< Divisor Regsiter,                                      Address offset: 0x04 */
  __IO uint32_t QUOT;             		/*!< Quotient Register,                                     Address offset: 0x08 */
  __IO uint32_t REMD;             		/*!< Reminder Register,                                     Address offset: 0x0C */
  __IO uint32_t ROOT;             		/*!< ROOT Register,                                         Address offset: 0x10 */
  __IO uint32_t SR;               		/*!< Status Register,                                       Address offset: 0x14 */  
  __IO uint32_t CR;               		/*!< Control Register,                                      Address offset: 0x18 */ 
} DIVAS_Type;   


typedef struct
{
  __IO uint32_t CR1;                    /*!<  I2C SMBus Control Register,                           Address offset: 0x00 */
  __IO uint32_t CR2;                    /*!<  I2C SMBus Control Register,                           Address offset: 0x04 */
  __IO uint32_t IER;                    /*!<  I2C SMBus Intterupt Enable Register,                  Address offset: 0x08 */
  __IO uint32_t ISR;                    /*!<  I2C Master Interrupt Status Register,                 Address offset: 0x0C */
  __IO uint32_t BGR;                    /*!<  ,                                                     Address offset: 0x10 */
  __IO uint32_t TIMINGR;                /*!<  ,                                                     Address offset: 0x14 */
  __IO uint32_t TOR;                    /*!<  ,                                                     Address offset: 0x18 */
  __I  uint32_t RXDR;                   /*!<  ,                                                     Address offset: 0x1C */
  __IO uint32_t TXDR;                   /*!<  ,                                                     Address offset: 0x20 */
  __IO uint32_t SADR;                   /*!<  ,                                                     Address offset: 0x24 */
  __I  uint32_t CRC_DR;                 /*!<  ,                                                     Address offset: 0x28 */
  __IO uint32_t CRC_LFSR;               /*!<  ,                                                     Address offset: 0x2C */
  __IO uint32_t CRC_POLY;               /*!<  ,                                                     Address offset: 0x30 */
}I2CSMB_Type;

typedef struct
{
  __IO uint32_t SERV;             		/*!< IWDT Service Register,                                 Address offset: 0x00 */
  __IO uint32_t CR;               		/*!< IWDT Config Register,                                  Address offset: 0x04 */
  __I  uint32_t CNT;              		/*!< IWDT Counter Register,                                 Address offset: 0x08 */
  __IO uint32_t WIN;              		/*!< IWDT Window Register,                                  Address offset: 0x0C */
  __IO uint32_t IER;              		/*!< IWDT Status Register,                                  Address offset: 0x10 */
  __IO uint32_t ISR;              		/*!< IWDT Status Register,                                  Address offset: 0x10 */
} IWDT_Type;		    
		
typedef struct		
{		
  __IO uint32_t CR;               		/*!< LCD Control Register,                                  Address offset: 0x00 */
  __IO uint32_t TEST;             		/*!< LCD test Register,                                     Address offset: 0x04 */
  __IO uint32_t FCR;              		/*!< LCD Frequency Control Register,                        Address offset: 0x08 */
  __IO uint32_t FLKT;             		/*!< LCD Flick Time Register,                               Address offset: 0x0C */  
  __IO uint32_t RSV0;             		/*!< NULL,                                                  Address offset: 0x10 */
  __IO uint32_t IER;              		/*!< LCD Interrupt Enable Register,                         Address offset: 0x14 */
  __IO uint32_t ISR;              		/*!< LCD Interrupt Status Register,                         Address offset: 0x18 */
  __IO uint32_t RSV1;             		/*!< NULL,                                                  Address offset: 0x1C */    
  __IO uint32_t RSV2;             		/*!< NULL,                                                  Address offset: 0x20 */    
  __IO uint32_t DATA0;            		/*!< LCD data buffer registers 0,                           Address offset: 0x24 */    
  __IO uint32_t DATA1;            		/*!< LCD data buffer registers 1,                           Address offset: 0x28 */
  __IO uint32_t DATA2;            		/*!< LCD data buffer registers 2,                           Address offset: 0x2C */
  __IO uint32_t DATA3;            		/*!< LCD data buffer registers 3,                           Address offset: 0x30 */
  __IO uint32_t DATA4;            		/*!< LCD data buffer registers 4,                           Address offset: 0x34 */
  __IO uint32_t DATA5;            		/*!< LCD data buffer registers 5,                           Address offset: 0x38 */
  __IO uint32_t DATA6;            		/*!< LCD data buffer registers 6,                           Address offset: 0x3C */
  __IO uint32_t DATA7;            		/*!< LCD data buffer registers 7,                           Address offset: 0x40 */
  __IO uint32_t RSV3;             		/*!< NULL,                                                  Address offset: 0x44 */
  __IO uint32_t RSV4;             		/*!< NULL,                                                  Address offset: 0x48 */
  __IO uint32_t RSV5;             		/*!< NULL,                                                  Address offset: 0x4C */
  __IO uint32_t COMEN;            		/*!< LCD COM Enable Register,                               Address offset: 0x50 */
  __IO uint32_t SEGEN0;           		/*!< LCD SEG Enable Register0,                              Address offset: 0x54 */
} LCD_Type;

typedef struct
{
  __IO uint32_t CR;               		/*!< LCD Control Register,                                   Address offset: 0x00 */
  __IO uint32_t CFGR;             		/*!< LCD test Register,                                      Address offset: 0x04 */
  __IO uint32_t RSV0;              		/*!< LCD Frequency Control Register,                         Address offset: 0x08 */
  __IO uint32_t IER;             		/*!< LCD Flick Time Register,                                Address offset: 0x0C */  
  __IO uint32_t ISR;             		/*!< NULL,                                                   Address offset: 0x10 */
  __IO uint32_t RSV1[3];              	/*!< LCD Interrupt Enable Register,                          Address offset: 0x14 */
  __IO uint32_t PWMCRA;              	/*!< LCD Interrupt Status Register,                          Address offset: 0x18 */
  __IO uint32_t PWMCRB;             	/*!< NULL,                                                   Address offset: 0x1C */    
  __IO uint32_t PWMCRC;             	/*!< NULL,                                                   Address offset: 0x20 */    
  __IO uint32_t PWMCRD;            		/*!< LCD data buffer registers 0,                            Address offset: 0x24 */    
  __IO uint32_t RSV2[4];            	/*!< LCD data buffer registers 1,                            Address offset: 0x28 */
  __IO uint32_t DOT0DR;            		/*!< LCD data buffer registers 2,                            Address offset: 0x2C */
  __IO uint32_t DOT1DR;            		/*!< LCD data buffer registers 3,                            Address offset: 0x30 */
  __IO uint32_t DOT2DR;            		/*!< LCD data buffer registers 4,                            Address offset: 0x34 */
  __IO uint32_t DOT3DR;            		/*!< LCD data buffer registers 5,                            Address offset: 0x38 */
  __IO uint32_t DOT4DR;            		/*!< LCD data buffer registers 6,                            Address offset: 0x3C */
  __IO uint32_t DOT5DR;            		/*!< LCD data buffer registers 7,                            Address offset: 0x40 */
  __IO uint32_t DOT6DR;             	/*!< NULL,                                                   Address offset: 0x44 */
  __IO uint32_t DOT7DR;             	/*!< NULL,                                                   Address offset: 0x48 */
  __IO uint32_t DOT8DR;             	/*!< NULL,                                                   Address offset: 0x4C */
  __IO uint32_t DOT9DR;             	/*!< NULL,                                                   Address offset: 0x4C */
  __IO uint32_t RSV3[6];            	/*!< LCD data buffer registers 1,                            Address offset: 0x28 */
  __IO uint32_t DMACR;            		/*!< LCD COM Enable Register,                                Address offset: 0x50 */
  __IO uint32_t DPCAR;           		/*!< LCD SEG Enable Register0,                               Address offset: 0x54 */
  __IO uint32_t DDRAR;           		/*!< LCD SEG Enable Register0,                               Address offset: 0x54 */
  __IO uint32_t CCOM;           		/*!< LCD SEG Enable Register0,                               Address offset: 0x54 */
} LED_Type;

typedef struct
{
  __IO uint32_t CFGR;             		/*!< LPTIM Config Register,                                 Address offset: 0x00 */
  __IO uint32_t CNT;              		/*!< LPTIM Counter Register,                                Address offset: 0x04 */
  __IO uint32_t CCSR;             		/*!< LPTIM Capture/Compare Control and Status Register,     Address offset: 0x08 */
  __IO uint32_t ARR;              		/*!< LPTIM Auto-Reload Register,                            Address offset: 0x0C */
  __IO uint32_t IER;              		/*!< LPTIM Interrupt Enable Register,                       Address offset: 0x10 */
  __IO uint32_t ISR;              		/*!< LPTIM Interrupt Status Register,                       Address offset: 0x14 */
  __IO uint32_t CR;               		/*!< LPTIM Control Register,                                Address offset: 0x18 */    
  __IO uint32_t RSV0;              		/*!< RESERVED REGISTER,                                     Address offset: 0x1C */
  __IO uint32_t CCR1;             		/*!< LPTIM Capture/Compare Register1,                       Address offset: 0x20 */
  __IO uint32_t CCR2;             		/*!< LPTIM Capture/Compare Register2,                       Address offset: 0x24 */
} LPTIM16_Type;

typedef struct
{
  __IO uint32_t CSR;              		/*!< LPUART Control Status Register,                        Address offset: 0x00 */
  __IO uint32_t IER;              		/*!< LPUART Interrupt Enable Register,                      Address offset: 0x04 */
  __IO uint32_t ISR;              		/*!< LPUART Interrupt Status Register,                      Address offset: 0x08 */
  __IO uint32_t BMR;              		/*!< LPUART Baud rate Modulation Register,                  Address offset: 0x0C */
  __IO uint32_t RXBUF;            		/*!< LPUART Receive Buffer Register,                        Address offset: 0x10 */
  __IO uint32_t TXBUF;            		/*!< LPUART Transmit Buffer Register,                       Address offset: 0x14 */
  __IO uint32_t DMR;              		/*!< LPUART  data Matching Register,                        Address offset: 0x18 */    
} LPUART_Type;



typedef struct
{
  __IO uint32_t CR;                     /*!<  Power Management Control Register,                    Address offset: 0x00 */
  __IO uint32_t WKTR;                   /*!<  Wakeup Time Register,                                 Address offset: 0x04 */
  __IO uint32_t WKFR0;                  /*!<  Wakeup Source Flags Register,                         Address offset: 0x08 */
  __IO uint32_t WKFR1;                  /*!<  Wakeup Source Flags Register,                         Address offset: 0x0C */
  __IO uint32_t RSV1[11];               /*!<  RESERVED REGISTER,                                    Address offset: 0x10 */ 
  __IO uint32_t BUFCR;                 	/*!<   Analog Buffer Control Register,                      Address offset: 0x3C */
  __IO uint32_t RSV2[4];                /*!<  RESERVED REGISTER,                                    Address offset: 0x40 */
  __IO uint32_t PTATCR;                	/*!<  PMU PTAT Control Register,                            Address offset: 0x50 */
}PMU_Type;



typedef struct
{
  __IO uint32_t SYSCLKCR;         		/*!< System Clock Control Register               ,          Address offset: 0x0C */
  __IO uint32_t RCHFCR;           		/*!< RCHF Control Register                       ,          Address offset: 0x10 */
  __IO uint32_t RCHFTR;           		/*!< RCHF Trim Register                          ,          Address offset: 0x14 */
  __IO uint32_t PLLCR;            		/*!< PLL Control Register                        ,          Address offset: 0x18 */
  __IO uint32_t RCLPCR;          		/*!< LPOSC Control Register                      ,          Address offset: 0x1C */
  __IO uint32_t RCLPTR;          		/*!< LPOSC Trim Register                         ,          Address offset: 0x20 */
  __IO uint32_t XTLFCR;           		/*!< XTLF CONFIG REGISTER                        ,          Address offset: 0x24 */
  __IO uint32_t LSCLKSEL;         		/*!< LSCLK Select Register                       ,          Address offset: 0x38 */
  __IO uint32_t XTHFCR;           		/*!< XTHF Control Register                       ,          Address offset: 0x60 */
  __IO uint32_t RSV0[2];                /*!<  RESERVED REGISTER,                                    Address offset: 0x24 */
  __IO uint32_t IER;                    /*!<  Interrupt Enable Register,                            Address offset: 0x2C */
  __IO uint32_t ISR;                    /*!<  Interrupt Status Register,                            Address offset: 0x30 */
  __IO uint32_t PCLKCR1;          		/*!< Peripheral bus Clock Control Register1      ,          Address offset: 0x28 */
  __IO uint32_t PCLKCR2;          		/*!< Peripheral bus Clock Control Register2      ,          Address offset: 0x2C */
  __IO uint32_t PCLKCR3;          		/*!< Peripheral bus Clock Control Register3      ,          Address offset: 0x30 */
  __IO uint32_t PCLKCR4;          		/*!< Peripheral bus Clock Control Register4      ,          Address offset: 0x34 */
  __IO uint32_t OPCCR1;           		/*!< Peripheral Operation Clock Control Register1,          Address offset: 0x6C */    
  __IO uint32_t OPCCR2;           		/*!< Peripheral Operation Clock Control Register2,          Address offset: 0x70 */
  __IO uint32_t OPCER1;           		/*!< Peripheral Operation Clock Control Register2,          Address offset: 0x70 */
  __IO uint32_t OPCER2;           		/*!< Peripheral Operation Clock Control Register2,          Address offset: 0x70 */
  __IO uint32_t AHBMCR;           		/*!< AHB Master Control Register                 ,          Address offset: 0x44 */
} CMU_Type;

typedef struct
{
  __IO uint32_t CR;            			/*!< PDR Control Register  */
  __IO uint32_t CFGR;            		/*!< BOR Control Register  */
	__IO uint32_t CNTR;            		/*!< BOR Control Register  */
	__IO uint32_t ISR;            		/*!< BOR Control Register  */
	__IO uint32_t CMPH;            		/*!< BOR Control Register  */
	__IO uint32_t CMPL;            		/*!< BOR Control Register  */
} CLM_Type;

typedef struct
{
  __IO uint32_t PDRCR;                  /*!<  ,                                                     Address offset: 0x00 */
  __IO uint32_t BORCR;                  /*!<  ,                                                     Address offset: 0x04 */
  __IO uint32_t LKPCR;                  /*!<  ,                                                     Address offset: 0x08 */
  __O  uint32_t SOFTRST;                /*!<  ,                                                     Address offset: 0x0C */
  __IO uint32_t RSTFR;                  /*!<  ,                                                     Address offset: 0x10 */
  __O  uint32_t PRSTEN;                 /*!<  ,                                                     Address offset: 0x14 */
  __IO uint32_t AHBRSTCR;               /*!<  ,                                                     Address offset: 0x18 */
  __IO uint32_t APBRSTCR1;              /*!<  ,                                                     Address offset: 0x1C */
  __IO uint32_t APBRSTCR2;              /*!<  ,                                                     Address offset: 0x20 */
}RMU_Type;

typedef struct
{   
  __IO uint32_t CR;               		/*!< RESERVED REGISTER,                                     Address offset: 0x00 */
  __IO uint32_t DOR;              		/*!< RNG OUTPUT REGISTER,                                   Address offset: 0x04 */
  __IO uint32_t RSV0;             		/*!< RESERVED REGISTER,                                     Address offset: 0x08 */
  __IO uint32_t RSV1;             		/*!< RESERVED REGISTER,                                     Address offset: 0x0C */
  __IO uint32_t SR;               		/*!< RNG FLAG REGISTER,                                     Address offset: 0x10 */    
  __IO uint32_t CRCCR;            		/*!< RNG CRC CONTROL REGISTER,                              Address offset: 0x14 */    
  __IO uint32_t CRCDIR;           		/*!< RNG CRC INPUT REGISTER,                                Address offset: 0x18 */    
  __IO uint32_t CRCSR;            		/*!< RNG CRC FLAG REGISTER,                                 Address offset: 0x1C */        
} RNG_Type; 
    
typedef struct
{   
  __IO uint32_t WER;              		/*!< RTC Write Enable Register,                             Address offset: 0x00 */
  __IO uint32_t IER;              		/*!< RTC Interrupt Enable Register,                         Address offset: 0x04 */
  __IO uint32_t ISR;              		/*!< RTC Interrupt Status Register,                         Address offset: 0x08 */
  __IO uint32_t BCDSEC;           		/*!< RTC SECOND IN BCD REGISTER,                            Address offset: 0x0C */
  __IO uint32_t BCDMIN;           		/*!< RTC MINITE IN BCD REGISTER,                            Address offset: 0x10 */
  __IO uint32_t BCDHOUR;          		/*!< RTC HOUR IN BCD REGISTER,                              Address offset: 0x14 */
  __IO uint32_t BCDDAY;           		/*!< RTC DAY IN BCD REGISTER,                               Address offset: 0x18 */
  __IO uint32_t BCDWEEK;          		/*!< RTC WEEK IN BCD REGISTER,                              Address offset: 0x1C */    
  __IO uint32_t BCDMONTH;         		/*!< RTC MONTH IN BCD REGISTER,                             Address offset: 0x20 */    
  __IO uint32_t BCDYEAR;          		/*!< RTC YEAR IN BCD REGISTER,                              Address offset: 0x24 */    
  __IO uint32_t ALARM;            		/*!< RTC Alarm Register,                                    Address offset: 0x28 */
  __IO uint32_t TMSEL;            		/*!< RTC Time Mark Select,                                  Address offset: 0x2C */
  __IO uint32_t ADJUST;           		/*!< RTC time Adjust Register,                              Address offset: 0x30 */
  __IO uint32_t ADSIGN;           		/*!< RTC time Adjust Sign Register,                         Address offset: 0x34 */
  __IO uint32_t RSV0;             		/*!< NULL,                                                  Address offset: 0x38 */
  __IO uint32_t SBSCNT;           		/*!< RTC Sub-Second Counter,                                Address offset: 0x3C */
  __IO uint32_t CR;               		/*!< NULL,                                                  Address offset: 0x40 */
} RTC_Type; 

typedef struct
{
  __IO uint32_t T0CR;                   /*!<  ,                                                     Address offset: 0x00 */
  __IO uint32_t RSV0[3];                /*!< NULL,                                                  Address offset: 0x04 */
  __IO uint32_t T0CFGR;                 /*!<  ,                                                     Address offset: 0x10 */	
  __IO uint32_t T1CFGR;                 /*!<  ,                                                     Address offset: 0x14 */
  __IO uint32_t T2CFGR;                 /*!<  ,                                                     Address offset: 0x18 */
  __IO uint32_t T3CFGR;                 /*!<  ,                                                     Address offset: 0x1C */
  __IO uint32_t T4CFGR;                 /*!<  ,                                                     Address offset: 0x20 */
  __IO uint32_t T5CFGR;                 /*!<  ,                                                     Address offset: 0x24 */
  __IO uint32_t T6CFGR;                 /*!<  ,                                                     Address offset: 0x28 */
  __IO uint32_t T7CFGR;                 /*!<  ,                                                     Address offset: 0x2C */
  __IO uint32_t T0MDR;                  /*!<  ,                                                     Address offset: 0x30 */
  __IO uint32_t T1MDR;                  /*!<  ,                                                     Address offset: 0x34 */
  __IO uint32_t T2MDR;                  /*!<  ,                                                     Address offset: 0x38 */
  __IO uint32_t T3MDR;                  /*!<  ,                                                     Address offset: 0x3C */
  __IO uint32_t T4MDR;                  /*!<  ,                                                     Address offset: 0x40 */
  __IO uint32_t T5MDR;                  /*!<  ,                                                     Address offset: 0x44 */
  __IO uint32_t T6MDR;                  /*!<  ,                                                     Address offset: 0x48 */
  __IO uint32_t T7MDR;                  /*!<  ,                                                     Address offset: 0x4C */
  __IO uint32_t T0ARR;                  /*!<  ,                                                     Address offset: 0x50 */
  __IO uint32_t T1ARR;                  /*!<  ,                                                     Address offset: 0x54 */
  __IO uint32_t T2ARR;                  /*!<  ,                                                     Address offset: 0x58 */
  __IO uint32_t T3ARR;                  /*!<  ,                                                     Address offset: 0x5C */
  __IO uint32_t T4ARR;                  /*!<  ,                                                     Address offset: 0x60 */
  __IO uint32_t T5ARR;                  /*!<  ,                                                     Address offset: 0x64 */
  __IO uint32_t T6ARR;                  /*!<  ,                                                     Address offset: 0x68 */
  __IO uint32_t T7ARR;                  /*!<  ,                                                     Address offset: 0x6C */
  __IO uint32_t T0CCR;                  /*!<  ,                                                     Address offset: 0x70 */
  __IO uint32_t T1CCR;                  /*!<  ,                                                     Address offset: 0x74 */
  __IO uint32_t T2CCR;                  /*!<  ,                                                     Address offset: 0x78 */
  __IO uint32_t T3CCR;                  /*!<  ,                                                     Address offset: 0x7C */
  __IO uint32_t T4CCR;                  /*!<  ,                                                     Address offset: 0x80 */
  __IO uint32_t T5CCR;                  /*!<  ,                                                     Address offset: 0x84 */
  __IO uint32_t T6CCR;                  /*!<  ,                                                     Address offset: 0x88 */
  __IO uint32_t T7CCR;                  /*!<  ,                                                     Address offset: 0x8C */
  __IO uint32_t T0IER;                  /*!<  ,                                                     Address offset: 0x90 */
  __IO uint32_t T1IER;                  /*!<  ,                                                     Address offset: 0x94 */
  __IO uint32_t T2IER;                  /*!<  ,                                                     Address offset: 0x98 */
  __IO uint32_t T3IER;                  /*!<  ,                                                     Address offset: 0x9C */
  __IO uint32_t T4IER;                  /*!<  ,                                                     Address offset: 0xA0 */
  __IO uint32_t T5IER;                  /*!<  ,                                                     Address offset: 0xA4 */
  __IO uint32_t T6IER;                  /*!<  ,                                                     Address offset: 0xA8 */
  __IO uint32_t T7IER;                  /*!<  ,                                                     Address offset: 0xAC */
  __IO uint32_t T0ISR;                  /*!<  ,                                                     Address offset: 0xB0 */
  __IO uint32_t T1ISR;                  /*!<  ,                                                     Address offset: 0xB4 */
  __IO uint32_t T2ISR;                  /*!<  ,                                                     Address offset: 0xB8 */
  __IO uint32_t T3ISR;                  /*!<  ,                                                     Address offset: 0xBC */
  __IO uint32_t T4ISR;                  /*!<  ,                                                     Address offset: 0xC0 */
  __IO uint32_t T5ISR;                  /*!<  ,                                                     Address offset: 0xC4 */
  __IO uint32_t T6ISR;                  /*!<  ,                                                     Address offset: 0xC8 */
  __IO uint32_t T7ISR;                  /*!<  ,                                                     Address offset: 0xCC */
  __I  uint32_t T0CNTR;                 /*!<  ,                                                     Address offset: 0xD0 */
  __I  uint32_t T1CNTR;                 /*!<  ,                                                     Address offset: 0xD4 */
  __I  uint32_t T2CNTR;                 /*!<  ,                                                     Address offset: 0xD8 */
  __I  uint32_t T3CNTR;                 /*!<  ,                                                     Address offset: 0xDC */
  __I  uint32_t T4CNTR;                 /*!<  ,                                                     Address offset: 0xE0 */
  __I  uint32_t T5CNTR;                 /*!<  ,                                                     Address offset: 0xE4 */
  __I  uint32_t T6CNTR;                 /*!<  ,                                                     Address offset: 0xE8 */
  __I  uint32_t T7CNTR;                 /*!<  ,                                                     Address offset: 0xEC */
}TAU0_Type;

typedef struct
{
  __IO uint32_t CR;              	 	/*!< OPA Control Register               */
  __IO uint32_t CALR;             		/*!< OPA Calibration Register           */
  __IO uint32_t COR;              		/*!< OPA Calibration Output Register      */
} OPA_Type;

typedef struct
{
  __IO uint32_t CR1;              		/*!< SPI Control Register1         */
  __IO uint32_t CR2;              		/*!< SPI Control Register2         */
  __IO uint32_t CR3;              		/*!< SPI Control Register3         */
  __IO uint32_t IER;              		/*!< SPI Interrupt Enable Register */
  __IO uint32_t ISR;              		/*!< SPI Status Register           */    
  __IO uint32_t TXBUF;            		/*!< SPI Transmit Buffer           */
  __IO uint32_t RXBUF;            		/*!< SPI Receive Buffer            */
  __IO uint32_t I2SCR;            		/*!< SPI I2S Control Register,                              Address offset: 0x20 */
  __IO uint32_t I2SPR;            		/*!< SPI I2S Prescaler Register,                            Address offset: 0x24 */
} SPI_Type;

typedef struct
{
  __IO uint32_t CR1;                    /*!<  DAC Control Register,                                 Address offset: 0x00 */
  __IO uint32_t CR2;                    /*!<  DAC Control Register,                                 Address offset: 0x04 */
  __IO uint32_t CFGR;                   /*!<  DAC Config Register,                                  Address offset: 0x08 */
  __O  uint32_t SWTRGR;                 /*!<  DAC Software Trigger Register,                        Address offset: 0x0C */
  __IO uint32_t DHR;                    /*!<  DAC Data Holding Register,                            Address offset: 0x10 */
  __IO uint32_t ISR;                    /*!<  DAC Interrupt Status Register,                        Address offset: 0x14 */
  __IO uint32_t IER;                    /*!<  DAC Interrupt Enable Register,                        Address offset: 0x18 */
}DAC_Type;

typedef struct
{
  __IO uint32_t CR;                     /*!<  PGL Control Register,                                 Address offset: 0x00 */
  __IO uint32_t CFGR0;                  /*!<  PGL Config Register0,                                 Address offset: 0x04 */
  __IO uint32_t CFGR1;                  /*!<  PGL Config Register1,                                 Address offset: 0x08 */
  __IO uint32_t CFGR2;                  /*!<  PGL Config Register2,                                 Address offset: 0x0C */
  __IO uint32_t CFGR3;                  /*!<  PGL Config Register3,                                 Address offset: 0x10 */
  __IO uint32_t IER;                    /*!<  PGL Interrupt Enable Register,                        Address offset: 0x14 */
  __IO uint32_t ISR;                    /*!<  PGL Interrupt Status Register,                        Address offset: 0x18 */
  __IO uint32_t LUT0;                   /*!<  Look Up Table0,                                       Address offset: 0x1C */
  __IO uint32_t LUT1;                   /*!<  Look Up Table1,                                       Address offset: 0x20 */
  __IO uint32_t LUT2;                   /*!<  Look Up Table2,                                       Address offset: 0x24 */
  __IO uint32_t LUT3;                   /*!<  Look Up Table3,                                       Address offset: 0x28 */
}PGL_Type;

typedef struct
{
  __IO uint32_t CR;                     /*!<  PGL Control Register,                                 Address offset: 0x00 */
  __IO uint32_t CFGR;                   /*!<  PGL Config Register,                                  Address offset: 0x04 */
  __IO uint32_t PSR;                    /*!<  PGL Prescaler Register1,                              Address offset: 0x08 */
  __IO uint32_t FTR;                    /*!<  PGL Config Register2,                                 Address offset: 0x0C */
  __IO uint32_t SR;                     /*!<  PGL Config Register3,                                 Address offset: 0x10 */
  __IO uint32_t DR;                     /*!<  PGL Interrupt Enable Register,                        Address offset: 0x14 */
  __IO uint32_t SYNC;                   /*!<  PGL Interrupt Status Register,                        Address offset: 0x18 */
  __IO uint32_t RCAL;                   /*!<  Look Up Table0,                                       Address offset: 0x1C */
}SENT_Type;

typedef struct
{
  __IO uint32_t CR;                     /*!<  CANControlRegister,                                   Address offset: 0x00 */
  __IO uint32_t MSR;                    /*!<  CANmodeselectregister,                                Address offset: 0x04 */
  __IO uint32_t BRPR;                   /*!<  CANBaudratePrescalerRegister,                         Address offset: 0x08 */
  __IO uint32_t BTR;                    /*!<  CANBitTimingRegister,                                 Address offset: 0x0C */
  __I  uint32_t ECR;                    /*!<  CANErrorCounterRegister,                              Address offset: 0x10 */
  __IO uint32_t ESR;                    /*!<  CANErrorStatusRegister,                               Address offset: 0x14 */
  __I  uint32_t SR;                     /*!<  CANStatusRegister,                                    Address offset: 0x18 */
  __IO uint32_t RXISR;                  /*!<  CANInterruptStatusRegister,                           Address offset: 0x1C */
  __IO uint32_t RXIER;                  /*!<  CANInterruptEnableRegister,                           Address offset: 0x20 */
  __IO uint32_t RSV0;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x24 */
  __IO uint32_t TXBCR;                  /*!<  CANTransmitBufferControlRegister,                     Address offset: 0x28 */
  __IO uint32_t TXBSR;                  /*!<  CANTransmitBufferStatusRegister,                      Address offset: 0x2C */
  __O  uint32_t TXB0IDR;                /*!<  CANTransmitBuffer0IDRegister,                         Address offset: 0x30 */
  __O  uint32_t TXB0DLCR;               /*!<  CANTransmitBuffer0DLCRegister,                        Address offset: 0x34 */
  __O  uint32_t TXB0DW1R;               /*!<  CANTransmitBuffer0DataWord1Register,                  Address offset: 0x38 */
  __O  uint32_t TXB0DW2R;               /*!<  CANTransmitBuffer0DataWord2Register,                  Address offset: 0x3C */
  __O  uint32_t TXB1IDR;                /*!<  CANTransmitBuffer1IDRegister,                         Address offset: 0x40 */
  __O  uint32_t TXB1DLCR;               /*!<  CANTransmitBuffer1DLCRegister,                        Address offset: 0x44 */
  __O  uint32_t TXB1DW1R;               /*!<  CANTransmitBuffer1DataWord1Register,                  Address offset: 0x48 */
  __O  uint32_t TXB1DW2R;               /*!<  CANTransmitBuffer1DataWord2Register,                  Address offset: 0x4C */
  __O  uint32_t TXB2IDR;                /*!<  CANTransmitBuffer2IDRegister,                         Address offset: 0x50 */
  __O  uint32_t TXB2DLCR;               /*!<  CANTransmitBuffer2DLCRegister,                        Address offset: 0x54 */
  __O  uint32_t TXB2DW1R;               /*!<  CANTransmitBuffer2DataWord1Register,                  Address offset: 0x58 */
  __O  uint32_t TXB2DW2R;               /*!<  CANTransmitBuffer2DataWord2Register,                  Address offset: 0x5C */
  __IO uint32_t AFCR;                   /*!<  AcceptanceFilterControlRegister,                      Address offset: 0x60 */
  __IO uint32_t AFCFGR;                 /*!<  AcceptanceFilterConfigRegister,                       Address offset: 0x64 */
  __IO uint32_t RSV1[6];                /*!<  RESERVED REGISTER,                                    Address offset: 0x68 */
  __IO uint32_t AFMR0;                  /*!<  AcceptanceFilterMaskRegister0,                        Address offset: 0x80 */
  __IO uint32_t AFIR0;                  /*!<  AcceptanceFilterIDRegister0,                          Address offset: 0x84 */
  __IO uint32_t AFMR1;                  /*!<  AcceptanceFilterMaskRegister1,                        Address offset: 0x88 */
  __IO uint32_t AFIR1;                  /*!<  AcceptanceFilterIDRegister1,                          Address offset: 0x8C */
  __IO uint32_t AFMR2;                  /*!<  ,                                                     Address offset: 0x90 */
  __IO uint32_t AFIR2;                  /*!<  ,                                                     Address offset: 0x94 */
  __IO uint32_t AFMR3;                  /*!<  ,                                                     Address offset: 0x98 */
  __IO uint32_t AFIR3;                  /*!<  ,                                                     Address offset: 0x9C */
  __IO uint32_t AFMR4;                  /*!<  ,                                                     Address offset: 0xA0 */
  __IO uint32_t AFIR4;                  /*!<  ,                                                     Address offset: 0xA4 */
  __IO uint32_t AFMR5;                  /*!<  ,                                                     Address offset: 0xA8 */
  __IO uint32_t AFIR5;                  /*!<  ,                                                     Address offset: 0xAC */
  __IO uint32_t AFMR6;                  /*!<  ,                                                     Address offset: 0xB0 */
  __IO uint32_t AFIR6;                  /*!<  ,                                                     Address offset: 0xB4 */
  __IO uint32_t AFMR7;                  /*!<  ,                                                     Address offset: 0xB8 */
  __IO uint32_t AFIR7;                  /*!<  ,                                                     Address offset: 0xBC */
  __IO uint32_t AFMR8;                  /*!<  ,                                                     Address offset: 0xC0 */
  __IO uint32_t AFIR8;                  /*!<  ,                                                     Address offset: 0xC4 */
  __IO uint32_t AFMR9;                  /*!<  ,                                                     Address offset: 0xC8 */
  __IO uint32_t AFIR9;                  /*!<  ,                                                     Address offset: 0xCC */
  __IO uint32_t AFMR10;                 /*!<  ,                                                     Address offset: 0xD0 */
  __IO uint32_t AFIR10;                 /*!<  ,                                                     Address offset: 0xD4 */
  __IO uint32_t AFMR11;                 /*!<  ,                                                     Address offset: 0xD8 */
  __IO uint32_t AFIR11;                 /*!<  ,                                                     Address offset: 0xDC */
  __IO uint32_t AFMR12;                 /*!<  ,                                                     Address offset: 0xE0 */
  __IO uint32_t AFIR12;                 /*!<  ,                                                     Address offset: 0xE4 */
  __IO uint32_t AFMR13;                 /*!<  ,                                                     Address offset: 0xE8 */
  __IO uint32_t AFIR13;                 /*!<  ,                                                     Address offset: 0xEC */
  __IO uint32_t AFMR14;                 /*!<  ,                                                     Address offset: 0xF0 */
  __IO uint32_t AFIR14;                 /*!<  ,                                                     Address offset: 0xF4 */
  __IO uint32_t AFMR15;                 /*!<  AcceptanceFilterMaskRegister15,                       Address offset: 0xF8 */
  __IO uint32_t AFIR15;                 /*!<  AcceptanceFilterIDRegister15,                         Address offset: 0xFC */
  __O  uint32_t RXFIDR;                 /*!<  CANRXFIFOIDRegister,                                  Address offset: 0x100 */
  __O  uint32_t RXFDLCR;                /*!<  CANRXFIFODLCRegister,                                 Address offset: 0x104 */
  __O  uint32_t RXFDW1R;                /*!<  CANRXFIFODataWord1Register,                           Address offset: 0x108 */
  __O  uint32_t RXFDW2R;                /*!<  CANRXFIFODataWord2Register,                           Address offset: 0x10C */
}FSCAN_Type;

typedef struct
{
  __IO uint32_t RAMP_CR;                /*!<  RAM Parity Control Register,                          Address offset: 0x00 */
  __IO uint32_t RAMP_SR;                /*!<  RAM Parity Status Register,                           Address offset: 0x04 */
  __IO uint32_t MAP_CR;                 /*!<  Memory Access Protection Control Register,            Address offset: 0x08 */
  __IO uint32_t MAP_SR;                 /*!<  Memory Access Protection Control Register,            Address offset: 0x0C */
}SFU_Type;

typedef struct
{
  __IO uint32_t CFGR;             		/*!< SVD Config Register,                                   Address offset: 0x24 */
  __IO uint32_t CR;               		/*!< SVD Control Register,                                  Address offset: 0x28 */
  __IO uint32_t IER;              		/*!< SVD Interrupt Enable Register,                         Address offset: 0x2C */
  __IO uint32_t ISR;              		/*!< SVD Interrupt Status Register,                         Address offset: 0x30 */
  __IO uint32_t VSR;              		/*!< SVD reference Voltage Select Register,                 Address offset: 0x34 */
} SVD_Type; 

typedef struct 
{
  __IO uint32_t IRCR;             		/*!< Infrared modulation Control Register */          
} UART_COMMON_Type;
     
typedef struct
{
  __IO uint32_t CSR;                    /*!<  UARTx Control Status Register,                        Address offset: 0x00 */
  __IO uint32_t IER;                    /*!<  UARTx Interrupt Enable Register,                      Address offset: 0x04 */
  __IO uint32_t ISR;                    /*!<  UARTx Interrupt Status Register,                      Address offset: 0x08 */
  __IO uint32_t TODR;                   /*!<  UARTx Time-Out and Delay Register,                    Address offset: 0x0C */
  __I  uint32_t RXBUF;                  /*!<  UARTx Receive Buffer,                                 Address offset: 0x10 */
  __O  uint32_t TXBUF;                  /*!<  UARTx Transmit Buffer,                                Address offset: 0x14 */
  __IO uint32_t BGR;                    /*!<  UARTx Baud rate Generator Register,                   Address offset: 0x18 */
  __IO uint32_t RSV0;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x1C */
  __IO uint32_t MCR;                    /*!<  UARTx Mode Control Register,                          Address offset: 0x20 */
  __IO uint32_t LINCR;                  /*!<  UARTx LIN Control Register,                           Address offset: 0x24 */
  __IO  uint32_t LINBSR;                /*!<  UARTx LIN Baud Sync Register,                         Address offset: 0x28 */
  __IO uint32_t LINFTR;               	/*!<  UARTx LIN Frame Timeout Register,                     Address offset: 0x2C */
  __IO uint32_t LINTTR;              	/*!<  UARTx LIN Time Register,                              Address offset: 0x30 */
  __IO uint32_t LINPSR;               	/*!<  UARTx LIN Pre Sync Register,                          Address offset: 0x34 */
  __IO uint32_t LINBKR;					/*!<  UARTx LIN Break LEN Register                          Address offset: 0x38 */
  __IO uint32_t RSV1;               	/*!<  RESERVED REGISTER,                                   	Address offset: 0x3C */
  __IO uint32_t SCISR;                  /*!<  UARTx Smart Card Interrupt Status Register,           Address offset: 0x40 */
  __IO uint32_t SCIER;                  /*!<  UARTx Smart Card Interrupt Enable Register,           Address offset: 0x44 */
  __IO uint32_t FFCR;                   /*!<  UARTx Smart Card Frame Format Control Register,       Address offset: 0x48 */
  __IO uint32_t EGTR;                   /*!<  UARTx Smart Card Extra Guard Time Register,           Address offset: 0x4C */
  __IO uint32_t CODR;                   /*!<  UARTx Smart Card Clock Output Register,               Address offset: 0x50 */
  __IO uint32_t RSV2[11];				/*!<  RESERVED REGISTER,  									Address offset: 0x54 */
  __IO uint32_t LINSCCR;                /*!<  UARTx LIN Self-Test Control Register, 				Address offset: 0x80 */
}UART_Type;

typedef struct
{
  __IO uint32_t CR;               		/*!< WWDT Control Register,                                 Address offset: 0x00 */
  __IO uint32_t CFGR;             		/*!< WWDT Config Register,                                  Address offset: 0x04 */
  __IO uint32_t CNT;              		/*!< WWDT Counter Register,                                 Address offset: 0x08 */
  __IO uint32_t IER;              		/*!< WWDT Interrupt Enable Register,                        Address offset: 0x0C */
  __IO uint32_t ISR;              		/*!< WWDT Interrupt Status Register,                        Address offset: 0x10 */
  __IO uint32_t PSC;              		/*!< WWDT Prescaler Register,                               Address offset: 0x14 */    
} WWDT_Type;    



/** @addtogroup Peripheral_memory_map
  * @{
  */       
#define FLASH_BASE            0x00000000UL /*!< FLASH(up to 1 MB) base address in the alias region      */    
#define SRAM_BASE             0x20000000UL
#define PERIPH_BASE           0x40000000UL

/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

/*!< Peripheral memory map */
#define DBG_BASE              (PERIPH_BASE + 0x00000000UL)
#define DMA_BASE              (PERIPH_BASE + 0x00000400UL)
#define GPIOA_BASE            (PERIPH_BASE + 0x00000C00UL)
#define GPIOB_BASE            (PERIPH_BASE + 0x00000C40UL)
#define GPIOC_BASE            (PERIPH_BASE + 0x00000C80UL)
#define GPIOD_BASE            (PERIPH_BASE + 0x00000CC0UL)
#define GPIO_COMMON_BASE      (PERIPH_BASE + 0x00000DC0UL)
#define SFU_BASE              (PERIPH_BASE + 0x00002C00UL)
#define CRC_BASE              (PERIPH_BASE + 0x00010000UL) 
#define FLS_BASE              (PERIPH_BASE + 0x00001000UL)
#define PMU_BASE              (PERIPH_BASE + 0x00002000UL)
#define CMU_BASE              (PERIPH_BASE + 0x00002400UL)
#define RMU_BASE              (PERIPH_BASE + 0x00002800UL)
#define SPI0_BASE             (PERIPH_BASE + 0x00010400UL)
#define SPI1_BASE             (PERIPH_BASE + 0x00010800UL)
#define LCD_BASE              (PERIPH_BASE + 0x00010C00UL) 
#define RTC_BASE              (PERIPH_BASE + 0x00011000UL)
#define IWDT_BASE             (PERIPH_BASE + 0x00011400UL)    
#define WWDT_BASE             (PERIPH_BASE + 0x00011800UL)
#define I2CSMB0_BASE          (PERIPH_BASE + 0x00011C00UL)
#define UART0_BASE            (PERIPH_BASE + 0x00012000UL)
#define I2CSMB1_BASE          (PERIPH_BASE + 0x00012400UL)
#define SVD_BASE              (PERIPH_BASE + 0x00012800UL)
#define TAU0_BASE             (PERIPH_BASE + 0x00013000UL)
#define AES_BASE              (PERIPH_BASE + 0x00013800UL)
#define RNG_BASE              (PERIPH_BASE + 0x00013C00UL)
#define LPUART0_BASE          (PERIPH_BASE + 0x00014000UL)
#define LPUART1_BASE          (PERIPH_BASE + 0x00014400UL)
#define GPTIM0_BASE           (PERIPH_BASE + 0x00014C00UL)
#define COMP1_BASE            (PERIPH_BASE + 0x00015400UL)
#define COMP2_BASE            (PERIPH_BASE + 0x00015404UL)
#define COMP3_BASE            (PERIPH_BASE + 0x00015408UL)
#define COMP4_BASE            (PERIPH_BASE + 0x0001540CUL)
#define COMP_COMMON_BASE      (PERIPH_BASE + 0x00015410UL)
#define OPA1_BASE             (PERIPH_BASE + 0x00015800UL)
#define OPA2_BASE             (PERIPH_BASE + 0x00015820UL)
#define ADC_BASE              (PERIPH_BASE + 0x00015C00UL)
#define DAC_BASE              (PERIPH_BASE + 0x00016000UL)
#define GPTIM1_BASE           (PERIPH_BASE + 0x00016400UL)
#define UART1_BASE            (PERIPH_BASE + 0x00016800UL)
#define PGL_BASE              (PERIPH_BASE + 0x00016C00UL)
#define UART2_BASE            (PERIPH_BASE + 0x00017000UL)
#define UART3_BASE            (PERIPH_BASE + 0x00017400UL)
#define UART4_BASE            (PERIPH_BASE + 0x00017800UL)
#define UART_COMMON_BASE      (PERIPH_BASE + 0x00017C00UL) 
#define ATIM_BASE             (PERIPH_BASE + 0x00018000UL)
#define LPTIM16_BASE          (PERIPH_BASE + 0x00018800UL)
#define BSTIM16_BASE          (PERIPH_BASE + 0x00018C00UL)
#define DIVAS_BASE            (PERIPH_BASE + 0x00019C00UL)  
#define SENT0_BASE            (PERIPH_BASE + 0x0001A000UL)  
#define FSCAN_BASE            (PERIPH_BASE + 0x0001A400UL) 
#define SENT1_BASE            (PERIPH_BASE + 0x0001A800UL)  
#define LED_BASE              (PERIPH_BASE + 0x0001AC00UL)  
#define CLM0_BASE             (PERIPH_BASE + 0x0001B000UL) 
#define CLM1_BASE             (PERIPH_BASE + 0x0001B400UL) 
/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

#define DBG                   ((DBG_Type *) DBG_BASE)
#define DMA                   ((DMA_Type *) DMA_BASE)
#define GPIOA                 ((GPIO_Type *) GPIOA_BASE)
#define GPIOB                 ((GPIO_Type *) GPIOB_BASE)
#define GPIOC                 ((GPIO_Type *) GPIOC_BASE)
#define GPIOD                 ((GPIO_Type *) GPIOD_BASE)
#define GPIO                  ((GPIO_COMMON_Type *) GPIO_COMMON_BASE)
#define SFU                   ((SFU_Type *) SFU_BASE)
#define CRC                   ((CRC_Type *) CRC_BASE)
#define FLASH                 ((FLASH_Type *) FLS_BASE)
#define PMU                   ((PMU_Type *) PMU_BASE)
#define CMU                   ((CMU_Type *) CMU_BASE)
#define RMU                   ((RMU_Type *) RMU_BASE)
#define SPI0                  ((SPI_Type *) SPI0_BASE)
#define SPI1                  ((SPI_Type *) SPI1_BASE)
#define LCD                   ((LCD_Type *) LCD_BASE)
#define RTC                   ((RTC_Type *) RTC_BASE)
#define IWDT                  ((IWDT_Type *) IWDT_BASE)
#define WWDT                  ((WWDT_Type *) WWDT_BASE)
#define I2CSMB0               ((I2CSMB_Type *) I2CSMB0_BASE)
#define UART0                 ((UART_Type *) UART0_BASE)
#define I2CSMB1               ((I2CSMB_Type *) I2CSMB1_BASE)
#define SVD                   ((SVD_Type *) SVD_BASE)
#define TAU0                  ((TAU0_Type *) TAU0_BASE)
#define AES                   ((AES_Type *) AES_BASE)
#define RNG                   ((RNG_Type *) RNG_BASE)
#define LPUART0               ((LPUART_Type *) LPUART0_BASE)
#define LPUART1               ((LPUART_Type *) LPUART1_BASE)
#define GPTIM0                ((GPTIM_Type *) GPTIM0_BASE)
#define COMP1                 ((COMP_Type *) COMP1_BASE)
#define COMP2                 ((COMP_Type *) COMP2_BASE)
#define COMP3                 ((COMP_Type *) COMP3_BASE)
#define COMP4                 ((COMP_Type *) COMP4_BASE)
#define COMP                  ((COMP_COMMON_Type*) COMP_COMMON_BASE)
#define OPA1                  ((OPA_Type*) OPA1_BASE)
#define OPA2                  ((OPA_Type*) OPA2_BASE)
#define ADC                   ((ADC_Type *) ADC_BASE)
#define DAC                   ((DAC_Type *) DAC_BASE)
#define GPTIM1                ((GPTIM_Type *) GPTIM1_BASE)
#define UART1                 ((UART_Type *) UART1_BASE)
#define PGL                   ((PGL_Type *) PGL_BASE)
#define UART2                 ((UART_Type *) UART2_BASE)
#define UART3                 ((UART_Type *) UART3_BASE)
#define UART4                 ((UART_Type *) UART4_BASE)
#define UART                  ((UART_COMMON_Type *) UART_COMMON_BASE)
#define ATIM                  ((ATIM_Type *) ATIM_BASE)
#define LPTIM16               ((LPTIM16_Type *) LPTIM16_BASE)
#define BSTIM16               ((BSTIM16_Type *) BSTIM16_BASE)
#define DIVAS                 ((DIVAS_Type *) DIVAS_BASE)
#define FSCAN                 ((FSCAN_Type *) FSCAN_BASE)
#define SENT0                 ((SENT_Type *) SENT0_BASE)
#define SENT1                 ((SENT_Type *) SENT1_BASE)
#define LED                   ((LED_Type *) LED_BASE)
#define CLM0                  ((CLM_Type *) CLM0_BASE)
#define CLM1                  ((CLM_Type *) CLM1_BASE)
/* ================================================================================ */
/* ================             Peripheral include                 ================ */
/* ================================================================================ */

/** @} */ /* End of group Device_Peripheral_Registers */
/** @} */ /* End of group FM33LF0XX */
/** @} */ /* End of group Keil */

#ifdef __cplusplus
}
#endif

#endif  /* FM33LF0XX_H */
