#include "FM33LF0_UART.h"
#include "Flash.h"
#include "Adc_api.h"

Serial0_TYPEDEF Serial0;
Serial0Tx_TYPEDEF Serial0Tx;
Serial0Rx_TYPEDEF Serial0Rx;

void OpenUART0(void)
{    
  CMU->OPCCR1 &= ~CMU_OPCCR1_UART0CKS_Msk;
  CMU->PCLKCR3 |= FL_CMU_GROUP3_BUSCLK_UART0; 
  CMU->OPCER1  |= FL_CMU_GROUP1_OPCLKEN_UART0;
   
  /*ģʽѡ��--UART*/
  UART0->MCR   |= FL_UART_MODESEL_UART;
  /*���ò�����*/
  UART0->BGR = 2000000 / 9600 - 1;
  /*����ֹͣλ����*//*���ݳ���*//*������żУ��*//*���պͷ���ʹ��*/
  UART0->CSR  &= ~(UART_CSR_PDSEL_Msk + UART_CSR_PARITY_Msk);
  UART0->CSR  |= FL_UART_STOP_BIT_WIDTH_1B + FL_UART_DATA_WIDTH_8B + FL_UART_PARITY_NONE + UART_CSR_TXEN_Msk + UART_CSR_RXEN_Msk;   
}

void CloseUART0(void)
{    
  CMU->OPCCR1  &= ~CMU_OPCCR1_UART0CKS_Msk;
  CMU->PCLKCR3 &= ~FL_CMU_GROUP3_BUSCLK_UART0;
  CMU->OPCER1  &= ~FL_CMU_GROUP1_OPCLKEN_UART0;
  
  UART0->MCR = 0;
  UART0->BGR = 0; 
  UART0->CSR = 0;
}


void RunUART0TxProc(void)
{
	switch(Serial0Tx.Step)
	{
		case 0:
			Serial0Tx.Bat = Display.Bat * 100;
		
			Serial0Tx.Txbuff[0] = (Serial0Tx.Count >> 8)& 0xFF;
			Serial0Tx.Txbuff[1] = Serial0Tx.Count & 0xFF;
			Serial0Tx.Txbuff[2] = (ADC_struct.Ppm[2] >> 8)& 0xFF;
			Serial0Tx.Txbuff[3] = ADC_struct.Ppm[2] & 0xFF;
//			Serial0Tx.Txbuff[4] = (Serial0Tx.Bat >> 8)& 0xFF;
//			Serial0Tx.Txbuff[5] = Serial0Tx.Bat & 0xFF;
			Serial0Tx.Txbuff[4] = Display.T;
			Serial0Tx.Txbuff[5] = Display.Rh;
//			Serial0Tx.Txbuff[8] = (*((uint32_t *)FLASH_ZeroPpm) >> 8)& 0xFF;
//			Serial0Tx.Txbuff[9] = *((uint32_t *)FLASH_ZeroPpm) & 0xFF;
//			Serial0Tx.Txbuff[10] = (*((uint32_t *)FLASH_HunderdPpm) >> 8)& 0xFF;
//			Serial0Tx.Txbuff[11] = *((uint32_t *)FLASH_HunderdPpm) & 0xFF;
			Serial0Tx.Count++;
			Serial0Tx.Step++;
			break;
		case 1:
			OpenUART0();
			Serial0Tx.Step++;
			break;
		case 2:
			UART0->TXBUF = Serial0Tx.Txbuff[Serial0Tx.idx];	
			UART0->CSR |= UART_CSR_TXEN_Msk + UART_CSR_RXEN_Msk;
			Serial0Tx.idx++;
			Serial0Tx.Step++;
			break;
		case 3:
			if(UART0->ISR & UART_ISR_TXBE_Msk)
			{
				UART0->ISR |= 0x3;
				if(Serial0Tx.idx > 5)
				{
					Serial0Tx.Step++;
				}
				else
				{
					Serial0Tx.Step--;
				}
			}
			break;
		case 4:
			if((UART0->CSR & (0x1 << 24)) == 0)
			{
				CloseUART0();
				Serial0Tx.Step = 0;
				Serial0Tx.idx = 0;
				Serial0Tx.Mode = _idle;
			}
			break;
	}
}

