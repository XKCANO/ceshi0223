/**
  *******************************************************************************************************
  * @file    fm33lf0xx_fl_spi.c
  * @author  FMSH Application Team
  * @brief   Src file of SPI FL Module
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

/** @addtogroup FM33LF0XX_FL_Driver
  * @{
  */

/** @addtogroup SPI
  * @{
  */

#ifdef FL_SPI_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup SPI_FL_Private_Macros
  * @{
  */
#define         IS_FL_SPI_INSTANCE(INTANCE)                     (((INTANCE) == SPI0)||\
                                                                 ((INTANCE) == SPI1))

#define         IS_FL_SPI_MODE(__VALUE__)                       (((__VALUE__) == FL_SPI_WORK_MODE_SLAVE)||\
                                                                 ((__VALUE__) == FL_SPI_WORK_MODE_MASTER))

#define         IS_FL_SPI_DATAWIDTH_L(__VALUE__)                (((__VALUE__) == FL_SPI_DATAL_LENGTH0)||\
                                                                 ((__VALUE__) == FL_SPI_DATAL_LENGTH1)||\
                                                                 ((__VALUE__) == FL_SPI_DATAL_LENGTH2)||\
                                                                 ((__VALUE__) == FL_SPI_DATAL_LENGTH3))

#define         IS_FL_SPI_DATAWIDTH_H(__VALUE__)                (((__VALUE__) == FL_SPI_DATAH_LENGTH0)||\
                                                                 ((__VALUE__) == FL_SPI_DATAH_LENGTH1)||\
                                                                 ((__VALUE__) == FL_SPI_DATAH_LENGTH2)||\
                                                                 ((__VALUE__) == FL_SPI_DATAH_LENGTH3)||\
                                                                 ((__VALUE__) == FL_SPI_DATAH_LENGTH4)||\
                                                                 ((__VALUE__) == FL_SPI_DATAH_LENGTH5)||\
                                                                 ((__VALUE__) == FL_SPI_DATAH_LENGTH6)||\
                                                                 ((__VALUE__) == FL_SPI_DATAH_LENGTH7))

#define         IS_FL_SPI_BITORDER(__VALUE__)                   (((__VALUE__) == FL_SPI_BIT_ORDER_MSB_FIRST)||\
                                                                 ((__VALUE__) == FL_SPI_BIT_ORDER_LSB_FIRST))


#define         IS_FL_SPI_CLOCK_PHASE(__VALUE__)                (((__VALUE__) == FL_SPI_PHASE_EDGE1)||\
                                                                 ((__VALUE__) == FL_SPI_PHASE_EDGE2))

#define         IS_FL_SPI_CLOCK_POLARITY(__VALUE__)             (((__VALUE__) == FL_SPI_POLARITY_NORMAL)||\
                                                                 ((__VALUE__) == FL_SPI_POLARITY_INVERT))

#define         IS_FL_SPI_BAUDRATE(__VALUE__)                   (((__VALUE__) == FL_SPI_PCLK_DIV2)||\
                                                                 ((__VALUE__) == FL_SPI_PCLK_DIV4)||\
                                                                 ((__VALUE__) == FL_SPI_PCLK_DIV8)||\
                                                                 ((__VALUE__) == FL_SPI_PCLK_DIV16)||\
                                                                 ((__VALUE__) == FL_SPI_PCLK_DIV32)||\
                                                                 ((__VALUE__) == FL_SPI_PCLK_DIV64)||\
                                                                 ((__VALUE__) == FL_SPI_PCLK_DIV128)||\
                                                                 ((__VALUE__) == FL_SPI_PCLK_DIV256))


#define         IS_FL_SPI_TANSFERMODE(__VALUE__)                (((__VALUE__) == FL_SPI_TRANSFER_MODE_FULL_DUPLEX)||\
                                                                 ((__VALUE__) == FL_SPI_TRANSFER_MODE_HALF_DUPLEX))
																																 
																																 
 
#define         IS_FL_I2S_MODE(__VALUE__)                       (((__VALUE__) == FL_I2S_MODE_SLAVE_RX)||\
                                                                 ((__VALUE__) == FL_I2S_MODE_SLAVE_TX)||\
                                                                 ((__VALUE__) == FL_I2S_MODE_MASTER_RX)||\
                                                                 ((__VALUE__) == FL_I2S_MODE_MASTER_TX))
                                                                 
#define         IS_FL_I2S_DATAFORMAT(__VALUE__)                 (((__VALUE__) == FL_I2S_DATAFORMAT_16B)||\
                                                                 ((__VALUE__) == FL_I2S_DATAFORMAT_16B_EXTENDED)||\
                                                                 ((__VALUE__) == FL_I2S_DATAFORMAT_24B)||\
                                                                 ((__VALUE__) == FL_I2S_DATAFORMAT_32B))   

#define         IS_FL_I2S_IDLE_POLARITY(__VALUE__)              (((__VALUE__) == FL_I2S_IDLE_POLARITY_LOW)||\
                                                                 ((__VALUE__) == FL_I2S_IDLE_POLARITY_HIGHT))  
                                                                 
#define         IS_FL_I2S_STANDARD(__VALUE__)                   (((__VALUE__) == FL_I2S_STANDARD_PHILIPS)||\
                                                                 ((__VALUE__) == FL_I2S_STANDARD_MSB)||\
                                                                 ((__VALUE__) == FL_I2S_STANDARD_LSB)||\
                                                                 ((__VALUE__) == FL_I2S_STANDARD_PCM_SHORT)||\
                                                                 ((__VALUE__) == FL_I2S_STANDARD_PCM_LONG))																																 


/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup SPI_FL_EF_Init
  * @{
  */

/**
  * @brief  ��λ��ӦSPI�Ĵ���.
  * @param  SPIx
  * @retval ErrorStatusö��ֵ:
  *         -FL_PASS ����Ĵ���ֵ�ָ���λֵ
  *         -FL_FAIL δ�ɹ�ִ��
  */
FL_ErrorStatus FL_SPI_DeInit(SPI_Type *SPIx)
{
    assert_param(IS_FL_SPI_INSTANCE(SPIx));
    /* ʹ�����踴λ */
    FL_RMU_EnablePeripheralReset(RMU);
    if(SPIx == SPI0)
    {
        /* ��λSPI����Ĵ��� */
        FL_RMU_EnableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_SPI0);
        FL_RMU_DisableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_SPI0);
        /* �ر���������ʼʱ�Ӻ͹���ʱ�� */
        FL_CMU_DisableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI0);
    }
    else
        if(SPIx == SPI1)
        {
            /* ��λSPI����Ĵ��� */
            FL_RMU_EnableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_SPI1);
            FL_RMU_DisableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_SPI1);
            /* �ر���������ʼʱ�Ӻ͹���ʱ�� */
            FL_CMU_DisableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI1);
        }
		else
		{
				FL_RMU_DisablePeripheralReset(RMU);
				return FL_FAIL;
		}
    /* �������踴λ */
    RMU->PRSTEN = ~(0x13579BDFUL);
    return FL_PASS;
}
/**
  * @brief  ���� SPI_InitStruct ��������Ϣ��ʼ����Ӧ������ڵ�ַ�ļĴ���ֵ.
  * @param  SPIx SPIx
  * @param  SPI_InitStruct ָ��һ�� @ref FL_SPI_InitTypeDef �ṹ��
  *         ���а�������������������Ϣ.
  * @retval ErrorStatusö��ֵ
  *         -FL_FAIL ���ù��̷�������
  *         -FL_PASS SPI���óɹ�
  */
FL_ErrorStatus FL_SPI_Init(SPI_Type *SPIx, FL_SPI_InitTypeDef *initStruct)
{
    assert_param(IS_FL_SPI_INSTANCE(SPIx));
    assert_param(IS_FL_SPI_MODE(initStruct->mode));
    assert_param(IS_FL_SPI_BITORDER(initStruct->bitOrder));
    assert_param(IS_FL_SPI_DATAWIDTH_L(initStruct->dataWidth_l));
    assert_param(IS_FL_SPI_DATAWIDTH_H(initStruct->dataWidth_h));
    assert_param(IS_FL_SPI_BAUDRATE(initStruct->baudRate));
    assert_param(IS_FL_SPI_CLOCK_PHASE(initStruct->clockPhase));
    assert_param(IS_FL_SPI_CLOCK_POLARITY(initStruct->clockPolarity));
    if(SPIx == SPI0)
    {
        /* ��������ʼʱ�� */
        FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI0);
    }
    else
        if(SPIx == SPI1)
        {
            /* ��������ʼʱ�� */
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI1);
        }
		else
		{
				return FL_FAIL;
		}
    /* ���蹤������ģʽ */
    FL_SPI_SetWorkMode(SPIx, initStruct->mode);
    if(initStruct->mode == FL_SPI_WORK_MODE_MASTER)
    {
        /*MASTERģʽSSN mode�£�����һ֡������ SSN*/
        FL_SPI_SetHardwareSSNMode(SPIx, FL_SPI_HARDWARE_SSN_AUTO_HIGH);
        /*Ĭ��֡��� 1 WAIT*/
        FL_SPI_SetSendWait(SPIx, FL_SPI_SEND_WAIT_1);
    }
    /* ѡ��NSS�ſ���ģʽ */
    if(initStruct->softControl == FL_ENABLE)
    {
        FL_SPI_EnableSSNSoftControl(SPIx);
        FL_SPI_SetHardwareSSNMode(SPIx, FL_SPI_HARDWARE_SSN_KEEP_LOW);
    }
    else
    {
        FL_SPI_DisableSSNSoftControl(SPIx);
    }
    /* ����ͨѶ���� */
    FL_SPI_SetBaudRate(SPIx, initStruct->baudRate);
    /* ����bit���� */
    FL_SPI_SetBitOrder(SPIx, initStruct->bitOrder);
    /* ��������λ�� 
     * CR2�Ĵ�����DLEN��DLEN2��� {DLEN2, DLEN} ������������λ��
     * ʵ���������ݿ�ȿɲ�ѯ��Ʒ˵����
     * ��������������λ������ȡ __STATIC_INLINE uint32_t FL_SPI_GetDataWidth(SPI_Type* SPIx)
     */
    FL_SPI_SetDataWidth(SPIx, initStruct->dataWidth_l, initStruct->dataWidth_h);
    /* ʱ����λ */
    FL_SPI_SetClockPhase(SPIx, initStruct->clockPhase);
    /* ����ģʽ ˫����˫��  */
    FL_SPI_SetTransferMode(SPIx, initStruct->transferMode);
    /* ʱ�Ӽ��� */
    FL_SPI_SetClockPolarity(SPIx, initStruct->clockPolarity);
    /* ʹ�� ����*/
    FL_SPI_Enable(SPIx);

    return FL_PASS;
}
/**
  * @brief  ���� SPI_InitStruct ΪĬ������
  * @param  SPI_InitStruct ָ����Ҫ��ֵ����ΪĬ�����õĽṹ�� @ref FL_SPI_InitTypeDef �ṹ��
  *
  * @retval None
  */

void FL_SPI_StructInit(FL_SPI_InitTypeDef *initStruct)
{
    initStruct->softControl         =   FL_DISABLE;
    initStruct->mode                =   FL_SPI_WORK_MODE_MASTER;
    initStruct->baudRate            =   FL_SPI_PCLK_DIV4;
    initStruct->bitOrder            =   FL_SPI_BIT_ORDER_MSB_FIRST;
    initStruct->dataWidth_l         =   FL_SPI_DATAL_LENGTH0;
    initStruct->dataWidth_h         =   FL_SPI_DATAH_LENGTH0;
    initStruct->clockPolarity       =   FL_SPI_POLARITY_NORMAL;
    initStruct->clockPhase          =   FL_SPI_PHASE_EDGE1;
    initStruct->transferMode        =   FL_SPI_TRANSFER_MODE_FULL_DUPLEX;
}

/**
  * @brief  ��λ��ӦI2S�Ĵ���.
  * @param  SPIx
  * @retval ErrorStatusö��ֵ:
  *         -FL_PASS ����Ĵ���ֵ�ָ���λֵ
  *         -FL_FAIL δ�ɹ�ִ��
  */
FL_ErrorStatus FL_I2S_DeInit(SPI_Type *SPIx)
{
    return FL_SPI_DeInit(SPIx);
}

/**
  * @brief  ���� I2S_InitStruct ��������Ϣ��ʼ����Ӧ������ڵ�ַ�ļĴ���ֵ.
  * @param  SPIx
  * @param  I2S_InitStruct ָ��һ�� @ref FL_I2S_InitTypeDef �ṹ��
  *         ���а�������������������Ϣ.
  * @retval ErrorStatusö��ֵ
  *         -FL_FAIL ���ù��̷�������
  *         -FL_PASS SPI���óɹ�
  */
FL_ErrorStatus FL_I2S_Init(SPI_Type *SPIx, FL_I2S_InitTypeDef *initStruct)
{
    uint32_t packetlength = 1U;
    uint32_t sourceclock;
    uint32_t tmp;
    uint32_t i2sdiv = 2U;
    uint32_t i2sodd = 0U;
    assert_param(IS_FL_SPI_INSTANCE(SPIx));
    assert_param(IS_FL_I2S_MODE(initStruct->mode));
    assert_param(IS_FL_I2S_DATAFORMAT(initStruct->dataFormat));
    assert_param(IS_FL_I2S_IDLE_POLARITY(initStruct->clockPolarity));
    assert_param(IS_FL_I2S_STANDARD(initStruct->standard));

    if(SPIx == SPI0)
    {
        /* ��������ʼʱ�� */
        FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI0);
    }
    else if(SPIx == SPI1)
		{
				/* ��������ʼʱ�� */
				FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI1);
		}
		else
		{
        return FL_FAIL;
		}

    FL_I2S_Disable(SPIx);
    /*! I2S���ӻ�ģʽ */  
    FL_I2S_SetTransferMode(SPIx, initStruct->mode);
    
    /*! I2S��׼ѡ��*/
    if((initStruct->standard == FL_I2S_STANDARD_PCM_SHORT) ||(initStruct->standard == FL_I2S_STANDARD_PCM_LONG))
    {
         FL_I2S_SetStandardMode(SPIx, initStruct->standard);   
         FL_I2S_SetPCMFrameSynchronization(SPIx, initStruct->standard);   
    }
    else
        FL_I2S_SetStandardMode(SPIx, initStruct->standard);
    
    /*! I2Sͨ�ų���*/
    if(initStruct->dataFormat != FL_I2S_DATAFORMAT_16B)
    {
        FL_I2S_SetVocalTractLength(SPIx,initStruct->dataFormat);
        FL_I2S_SetDataLength(SPIx,initStruct->dataFormat);
        packetlength = 2U;
    } 
    
   sourceclock = FL_CMU_GetAPBClockFreq();
    
     /*! I2S_MCLK���ʹ��*/ 
    if(initStruct->mclkOutput)
    {
        FL_I2S_EnableMasterClockOutput(SPIx);
        tmp = (((((sourceclock / 256U) * 10U) / initStruct->audioFreq)) + 5U);       
    }
    else
    {
        FL_I2S_DisableMasterClockOutput(SPIx); 
        tmp = (((((sourceclock / (32U * packetlength)) * 10U) / initStruct->audioFreq)) + 5U);        
    }
    
    tmp = tmp / 10U;
    i2sodd = (tmp & (uint16_t)0x0001U);
    i2sdiv = ((tmp - i2sodd) / 2U);    
    if(i2sodd)
        FL_I2S_SetPrescalerParity(SPIx,FL_I2S_PRESCALER_PARITY_ODD);
    else
        FL_I2S_SetPrescalerParity(SPIx,FL_I2S_PRESCALER_PARITY_EVEN); 
    
    FL_I2S_WritePrescalerLinear(SPIx,i2sdiv);

    /*! I2S����ʱ�Ӽ���*/  
    FL_I2S_SetIdleClockPolarity(SPIx, initStruct->clockPolarity);
    
    /*! ѡ��I2S*/  
    FL_I2S_SetPeriphralMode(SPIx,FL_I2S_PERIPHRAL_MODE_I2S);
    /* ʹ�� ����*/
    FL_I2S_Enable(SPIx);
    return FL_PASS;
}

/**
  * @brief  ���� I2S_InitStruct ΪĬ������
  * @param  I2S_InitStruct ָ����Ҫ��ֵ����ΪĬ�����õĽṹ�� @ref FL_I2S_InitTypeDef �ṹ��
  *
  * @retval None
  */

void FL_I2S_StructInit(FL_I2S_InitTypeDef *initStruct)
{
    initStruct->mode                =   FL_I2S_MODE_MASTER_TX;
    initStruct->standard            =   FL_I2S_STANDARD_PHILIPS;
    initStruct->dataFormat          =   FL_I2S_DATAFORMAT_16B;
    initStruct->clockPolarity       =   FL_I2S_IDLE_POLARITY_LOW;
    initStruct->audioFreq           =   FL_I2S_AUDIOFREQ_8K;
    initStruct->mclkOutput          =   FL_ENABLE;
}

/**
  * @}
  */

#endif /* FL_SPI_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
