/**
  *******************************************************************************************************
  * @file    fm33lf0xx_fl_sent.c
  * @author  FMSH Application Team
  * @brief   Src file of SENT FL Module
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

/** @addtogroup SENT
  * @{
  */

#ifdef FL_SENT_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup SENT_FL_Private_Macros
  * @{
  */
#define    IS_FL_SENT_INSTANCE(INTANCE)                     (((INTANCE) == SENT0)||\
                                                             ((INTANCE) == SENT1))

#define    IS_FL_SENT_TRANSFER_DIRECTION(__VALUE__)         (((__VALUE__) == FL_SENT_MODE_RX)||\
                                                             ((__VALUE__) == FL_SENT_MODE_TX))

#define    IS_FL_SENT_PSC(__VALUE__)                        ((__VALUE__) <= 0x0000FFFF)

#define    IS_FL_SENT_TRANSMIT_MODE(__VALUE__)              (((__VALUE__) == FL_SENT_TXMODE_SOFTWARE)||\
                                                             ((__VALUE__) == FL_SENT_TXMODE_SERIAL))

#define    IS_FL_SENT_NIBBLE_NUMBER(__VALUE__)              (((__VALUE__) == FL_SENT_DATANIBBLES_COUNT_FORBIDDEN)||\
                                                             ((__VALUE__) == FL_SENT_DATANIBBLES_COUNT_1N)||\
                                                             ((__VALUE__) == FL_SENT_DATANIBBLES_COUNT_2N)||\
                                                             ((__VALUE__) == FL_SENT_DATANIBBLES_COUNT_3N)||\
                                                             ((__VALUE__) == FL_SENT_DATANIBBLES_COUNT_4N)||\
                                                             ((__VALUE__) == FL_SENT_DATANIBBLES_COUNT_5N)||\
                                                             ((__VALUE__) == FL_SENT_DATANIBBLES_COUNT_6N))

#define    IS_FL_SENT_CRCMODE(__VALUE__)                    (((__VALUE__) == FL_SENT_CRCMODE_RECOMMENDED)||\
                                                             ((__VALUE__) == FL_SENT_CRCMODE_LEGACY))

#define    IS_FL_SENT_IDLEPULSE(__VALUE__)                  (((__VALUE__) == FL_SENT_IDLEOUTPUT_HIGH)||\
                                                             ((__VALUE__) == FL_SENT_IDLEOUTPUT_LOW))

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup SENT_FL_EF_Init
  * @{
  */

/**
  * @brief  ��λSENT ����
  * @param  ������ڵ�ַ
  * @retval ���ش���״̬������ֵ��
  *         -FL_PASS ����Ĵ���ֵ�ָ���λֵ
  *         -FL_FAIL δ�ɹ�ִ��
  */
FL_ErrorStatus FL_SENT_DeInit(SENT_Type *SENTx)
{
    /* ������� */
    assert_param(IS_FL_SENT_INSTANCE(SENTx));
    /* ʹ�����踴λ */
    FL_RMU_EnablePeripheralReset(RMU);

    if(SENTx == SENT0)
    {
        /* ��λ����Ĵ��� */
        FL_RMU_EnableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_SENT0);
        FL_RMU_DisableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_SENT0);
        /* �ر���������ʱ�Ӻ͹���ʱ�� */
        FL_CMU_DisableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_SENT0);
     }
    else if(SENTx == SENT1)
    {
        /* ��λ����Ĵ��� */
        FL_RMU_EnableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_SENT1);
        FL_RMU_DisableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_SENT1);
        /* �ر���������ʱ�Ӻ͹���ʱ�� */
        FL_CMU_DisableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_SENT1);
     }
    else
    {
        return FL_FAIL;
    }
    /* �������踴λ */
    FL_RMU_DisablePeripheralReset(RMU);
    return FL_PASS;
}


/**
  * @brief  ������Ҫ����SETN
  *
  * @param  SENTx  ������ڵ�ַ
  * @param  initStructָ��һ��FL_SENT_InitTypeDef���͵Ľṹ��,����������SENT��������Ϣ
  *
  * @retval ErrorStatusö��ֵ
  *         -FL_FAIL ���ù��̷�������
  *         -FL_PASS ���óɹ�
  */
FL_ErrorStatus FL_SENT_Init(SENT_Type *SENTx, FL_SENT_InitTypeDef *initStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    /* ������� */
    assert_param(IS_FL_SENT_INSTANCE(SENTx));
    assert_param(IS_FL_SENT_TRANSFER_DIRECTION(initStruct->transferDirection));
    assert_param(IS_FL_SENT_PSC(initStruct->prescaler));
    assert_param(IS_FL_SENT_TRANSMIT_MODE(initStruct->transmitMode));
    assert_param(IS_FL_SENT_NIBBLE_NUMBER(initStruct->dataNibbleNumber));
    assert_param(IS_FL_SENT_CRCMODE(initStruct->CRCMode));
    assert_param(IS_FL_SENT_IDLEPULSE(initStruct->idleoutputpulse));

    if(SENTx == SENT0)
    {
        /*ʹ�ܹ���ʱ��*/
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_SENT0);
    }
    else if(SENTx == SENT1)
    {
        /*ʹ�ܹ���ʱ��*/
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_SENT1);
    }
    /*��������*/
    if(initStruct->transferDirection == FL_SENT_MODE_TX)
    {
        FL_SENT_SetModeSelect(SENTx, FL_SENT_MODE_TX);

        /*���÷���ʱ��Ԥ��Ƶprescaler
         * Fsent = APBCLK/(prescaler + 1)
         * tickʱ�� T = 8/Fsent
        */
        FL_SENT_WritePrescaler(SENTx, initStruct->prescaler);

        /*���÷���ģʽ*/
        if(initStruct->transmitMode == FL_SENT_TXMODE_SOFTWARE)
        {
            FL_SENT_SetTXModeSelect(SENTx, FL_SENT_TXMODE_SOFTWARE);
        }
        else if(initStruct->transmitMode == FL_SENT_TXMODE_SERIAL)
        {
            FL_SENT_SetTXModeSelect(SENTx, FL_SENT_TXMODE_SERIAL);
        }

        /*����֡��Data Nibbles����*/
        FL_SENT_SetDataNibblesCount(SENTx, initStruct->dataNibbleNumber);

        /*����Ӳ��CRCʹ��*/
        if(initStruct->hardwareCRC == FL_ENABLE)
        {
            FL_SENT_EnableCRCHardware(SENTx);
        }
        else if(initStruct->hardwareCRC == FL_DISABLE)
        {
            FL_SENT_DisableCRCHardware(SENTx);
        }
        /*����CRCģʽ*/
        FL_SENT_SetCRCModeSelect(SENTx, initStruct->CRCMode);

        /*������ͣ����ʹ��*/
        if(initStruct->pausePulse == FL_ENABLE)
        {
            FL_SENT_EnablePausePulse(SENTx);
            FL_SENT_WriteFrameTimeLength(SENTx, initStruct->frameTime);
        }
        else if(initStruct->pausePulse == FL_DISABLE)
        {
            FL_SENT_DisablePausePulse(SENTx);
        }

        /*���ÿ���ʱTX�����ƽ*/
        if(initStruct->idleoutputpulse == FL_SENT_IDLEOUTPUT_LOW)
        {
            FL_SENT_SetIdleTXOutputPulse(SENTx, FL_SENT_IDLEOUTPUT_LOW);
        }
        else if(initStruct->idleoutputpulse == FL_SENT_IDLEOUTPUT_HIGH)
        {
            FL_SENT_SetIdleTXOutputPulse(SENTx, FL_SENT_IDLEOUTPUT_HIGH);
        }
    }

    /*��������*/
    if(initStruct->transferDirection == FL_SENT_MODE_RX)
    {
        FL_SENT_SetModeSelect(SENTx, FL_SENT_MODE_RX);

        /*���÷���ʱ��Ԥ��Ƶprescaler
         * Fsent = APBCLK/(prescaler + 1)
         * tickʱ�� T = 8/Fsent
        */
        FL_SENT_WritePrescaler(SENTx, initStruct->prescaler);

        /*����֡��Data Nibbles����*/
        FL_SENT_SetDataNibblesCount(SENTx, initStruct->dataNibbleNumber);

        /*����Ӳ��CRCʹ��*/
        if(initStruct->hardwareCRC == FL_ENABLE)
        {
            FL_SENT_EnableCRCHardware(SENTx);
        }
        else if(initStruct->hardwareCRC == FL_DISABLE)
        {
            FL_SENT_DisableCRCHardware(SENTx);
        }
        /*����CRCģʽ*/
        FL_SENT_SetCRCModeSelect(SENTx, initStruct->CRCMode);
        /*������ͣ����ʹ��*/
        if(initStruct->pausePulse == FL_ENABLE)
        {
            FL_SENT_EnablePausePulse(SENTx);
        }
        else if(initStruct->pausePulse == FL_DISABLE)
        {
            FL_SENT_DisablePausePulse(SENTx);
        }

        /*sync���ȷ�Χ*/
        FL_SENT_WriteSyncMaxLength(SENTx, initStruct->syncPulseMax);
        FL_SENT_WriteSyncMinLength(SENTx, initStruct->syncPulseMin);
    }
    status = FL_PASS;
    return status;
}

/**
  * @brief  SENTx ΪĬ������
  * @param  initStruct ָ����Ҫ��ֵ����ΪĬ������ �Ľṹ��@ref FL_SENT_InitTypeDef structure �ṹ��
  *         �ṹ��
  * @retval None
  */
void FL_SENT_StructInit(FL_SENT_InitTypeDef *initStruct)
{
    if(initStruct != NULL)
    {
        initStruct->transmitMode          = FL_SENT_TXMODE_SOFTWARE;
        initStruct->dataNibbleNumber      = FL_SENT_DATANIBBLES_COUNT_6N;
        initStruct->hardwareCRC           = FL_ENABLE;
        initStruct->CRCMode               = FL_SENT_CRCMODE_RECOMMENDED ;
        initStruct->transferDirection     = FL_SENT_MODE_RX;
        initStruct->pausePulse            = FL_ENABLE;
    }
}


/**
  * @}
  */

#endif /* FL_SENT_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
