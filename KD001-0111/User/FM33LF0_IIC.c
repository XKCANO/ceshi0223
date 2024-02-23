
#include "FM33LF0_IIC.h"
#include "Message_Process.h"
#include "FM33LF0_UART.h"

#define STARTBIT    0
#define RESTARTBIT  1
#define STOPBIT     2

#define DEVICE_AHT21    0x70
#define AHT21 I2CSMB0

uint32_t AHT21_Pow(uint32_t Num, uint32_t Power);


uint8_t ReceiveArr[10] = {0};
uint8_t SendArr[10] = {0};

IIC_TYPEDEF I2C;
AHT21_TypeDef AHT;



/*
**	CRC校验（Array，Length）
*/
uint8_t CheckCrc8(uint8_t *pDat, uint8_t Length)
{
    uint8_t crc = 0xFF, i, j;

		pDat++;
    for (i = 0; i < Length; i++) 
		{
      crc = crc ^ *pDat; 
      for (j = 0; j < 8; j++) 
			{
        if (crc & 0x80) 
				{
          crc = (crc << 1) ^ 0x31; 
        } 
				else 
				{
          crc <<= 1; 
        }
			}
      pDat++;
    }
    return crc;
}


/*
**
*/
void RunAHT21Proc(void)
{
	switch(AHT.step)
	{
		case 0:
			OpenIIC();
		  AHT21_POWER_ON;
		  AHT_TIMER = 0;
		  AHT.step++;
			break;
		
		case 1:
			if(AHT_TIMER > 49)
			{
				AHT.counter = 0;
				AHT.step++;
				//关闭电源指示灯
				GREEN_LED_OFF;
			}
			break;
			
		case 2:
			I2C.buffer[0] = 0x71;
			I2C.total = 2;
			I2C.mode = _exe;
			AHT.step++;
			break;
		
		case 3:
			if(I2C.mode & _finish)
			{
				if(I2C.mode & _err)
				{
					AHT.counter++;
					if(AHT.counter >= 3)
					{
						AHT.step = STEP_END;
					}
					else
					{
						AHT_TIMER = 0;
						AHT.step++;
					}
				}
				else
				{
					if((I2C.buffer[1] & 0x08) != 0)
					{
						AHT.step = 9;
					}
					else
					{
						AHT.counter = 0;
						AHT.step += 2;
					}
				}
			}
			break;
		case 4:
			if(AHT_TIMER > 0)
			{
				AHT.step -= 2;
			}
			break;
			
		case 5:
			I2C.buffer[0] = 0x70;
			I2C.buffer[1] = 0xBE;
			I2C.buffer[2] = 0x08;
			I2C.buffer[3] = 0x00;
			I2C.total = 4;
			I2C.mode = _exe;
			AHT.step++;
			break;
		case 6:
			if(I2C.mode & _finish)
			{
				if(I2C.mode & _err)
				{
					AHT.counter++;
					if(AHT.counter >= 3)
					{
						AHT.step = STEP_END;
					}
					else
					{
						AHT.step++;
					}
				}
				else
				{
		      AHT.step += 2;
				}
				AHT_TIMER = 0;
			}
			break;
		case 7:
			if(AHT_TIMER > 0)
			{
				AHT.step -= 2;
			}
			break;
		case 8:
			if(AHT_TIMER > 9)
			{
				AHT.counter = 0;
				AHT.step++;
			}
			break;
			
	  case 9:
			I2C.buffer[0] = 0x70;
			I2C.buffer[1] = 0xAC;
			I2C.buffer[2] = 0x33;
			I2C.buffer[3] = 0x00;
			I2C.total = 4;
			I2C.mode = _exe;
			AHT.step++;
			break;
		case 10:
			if(I2C.mode & _finish)
			{
				if(I2C.mode & _err)
				{
					AHT.counter++;
					if(AHT.counter >= 3)
					{
						AHT.step = STEP_END;
					}
					else
					{
						AHT.step++;
					}
				}
				else
				{
		      AHT.step += 2;
				}
				AHT_TIMER = 0;
			}
			break;
		case 11:
			if(AHT_TIMER > 0)
			{
				AHT.step -= 2;
			}
			break;
		case 12:
			if(AHT_TIMER > 89)
			{
				AHT.counter = 0;
				AHT.step++;
			}
			break;
			
		case 13:
			I2C.buffer[0] = 0x71;
		  I2C.buffer[1] = 0xFF;
			I2C.total = 8;
			I2C.mode = _exe;
			AHT.step++;
			break;
		case 14:
			if(I2C.mode & _finish)
			{
				if(I2C.mode & _err)
				{
					AHT.counter++;
					if(AHT.counter >= 3)
					{
						AHT.step += 2;
					}
					else
					{
						AHT_TIMER = 0;
						AHT.step++;
					}
				}
				else
				{
					if((I2C.buffer[1] & 0x80) == 0)
					{
						if(CheckCrc8(I2C.buffer,6) == I2C.buffer[7])
						{
							I2C.RH = 0;
							I2C.RH = (I2C.RH | I2C.buffer[2]) << 8;
							I2C.RH = (I2C.RH | I2C.buffer[3]) << 8;	 
							I2C.RH = (I2C.RH| I2C.buffer[4]);
							I2C.RH = I2C.RH >> 4;
							Display.Rh = (float)I2C.RH/1048576*100;

							I2C.Temp = 0;
							I2C.Temp = (I2C.Temp | I2C.buffer[4]) << 8;	
							I2C.Temp = (I2C.Temp | I2C.buffer[5]) << 8; 
							I2C.Temp = (I2C.Temp | I2C.buffer[6]);
							I2C.Temp = I2C.Temp & 0x000fffff;
							Display.T = (float)I2C.Temp/1048576*200 - 50;
						}
						AHT.step += 2;
					}
					else
					{
						AHT_TIMER = 0;
		        AHT.step++;
					}
				}
			}
			
			break;
		case 15:
			if(AHT_TIMER > 1)
			{
				AHT.step -= 2;
			}
			break;
			
		case 16:
			if(I2C.Temp == I2C.RH && I2C.RH == 0)
				{
					AHT.step = 1;
					AHT_TIMER = 0;
				}
			else
			{
				AHT21_POWER_OFF;
				CloseIIC();
				AHT.step = 0;
				AHT.mode = _idle;
				I2C.mode = _idle;
				Lptimer.HtCount = 0;
				Display.Mode = _exe;
				Serial0Tx.Mode = _exe;
			}
			break;
	}
}




/*
**
*/
void OpenIIC(void)
{
	RMU->APBRSTCR1 &= 0xFFFFFFFB;
	
	CMU->PCLKCR3 |= FL_CMU_GROUP3_BUSCLK_I2CSMB0;
	//APBCLK:2MHz
	CMU->OPCCR1 &= ~CMU_OPCCR1_I2CSMB0CKS_Msk;
	CMU->OPCER1 |= FL_CMU_GROUP1_OPCLKEN_I2CSMB0;
	
	//Baud rate:10K = 2000K / 200;
	I2CSMB0->BGR = (200U << 16) + 200U;
	//SDA hold delay:100
	I2CSMB0->TIMINGR = (8U << 16) + 100U;
	
	I2CSMB0->CR1 = I2CSMB_CR1_EN_Msk;
	I2CSMB0->CR2 = 0;
	I2CSMB0->IER = 0;
	I2CSMB0->ISR |= 0x3F7F;
	
	GPIOA->FCR &= ~((3U << FCR_GPIO_PIN12) + (3U << FCR_GPIO_PIN11));
	GPIOA->FCR |= (FL_GPIO_MODE_DIGITAL << FCR_GPIO_PIN12) + (FL_GPIO_MODE_DIGITAL << FCR_GPIO_PIN11);
	GPIOA->DFS &= ~((3U << FCR_GPIO_PIN12) + (3U << FCR_GPIO_PIN11));
}
/*
**
*/
void CloseIIC(void)
{
	I2CSMB0->ISR |= 0x3F7F;
	I2CSMB0->CR1 = 0;
	CMU->OPCER1 &= ~FL_CMU_GROUP1_OPCLKEN_I2CSMB0;
	CMU->PCLKCR3 &= ~FL_CMU_GROUP3_BUSCLK_I2CSMB0;
	
	GPIOA->FCR &= ~((3U << FCR_GPIO_PIN12) + (3U << FCR_GPIO_PIN11));
	GPIOA->FCR |= (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN12) + (FL_GPIO_MODE_OUTPUT << FCR_GPIO_PIN11);
}
/*
**
*/
void RunIICServerProc(void)
{
	switch(I2C.step)
	{
		case 0:
			if(I2C.total <= IIC_BUFFER_SIZE)
			{
			  I2CSMB0->ISR |= 0x3F7F;
			  I2CSMB0->CR2 |= I2CSMB_CR2_START_Msk;
		    I2C.pos = 0;
		    I2C.step++;
			}
			else
			{
				I2C.mode = _finish;
			}
			break;
		case 1:
			if((I2CSMB0->CR2 & I2CSMB_CR2_START_Msk) == 0)
			{
				if((I2C.buffer[0] & 0x1) == 0)
				{
					//write
				  I2CSMB0->CR2 &= ~I2CSMB_CR2_RWN_Msk;
					I2C.flag = 0;
				}
				else
				{
					//read
					I2CSMB0->CR2 |= I2CSMB_CR2_RWN_Msk;
					I2C.flag = 1;
				}
				I2C.step++;
			}
			break;
			
		case 2:
			I2CSMB0->TXDR = I2C.buffer[I2C.pos++];
		  I2C.step++;
			break;
		
		case 3:
			if((I2CSMB0->ISR & I2CSMB_ISR_TXIF_Msk) != 0)
			{
				if(I2C.flag == 0)
				{
					if((I2CSMB0->ISR & I2CSMB_ISR_NACKIF_Msk) == 0)
					{
				    if(I2C.pos < I2C.total)
				    {
					    I2C.step--;
				    }
				    else
				    {
						  //end
					    I2C.step = 6;
				    }
				  }
					else
					{
						//error
						I2C.mode |= _err;
						I2C.step = 6;
					}
			  }
				else
				{
					if((I2CSMB0->ISR & I2CSMB_ISR_NACKIF_Msk) == 0)
					{
						if(I2C.pos == (I2C.total - 1))
					  {
						  I2C.flag = 0;
					  }
					  I2C.step++;
					}
					else
					{
						//error
						I2C.mode |= _err;
						I2C.step = 6;
					}
				}
				I2CSMB0->ISR |= I2CSMB_ISR_TXIF_Msk;
			}
			else
			{
				if((I2CSMB0->ISR & I2CSMB_ISR_ARLO_Msk) != 0)
				{
					//error
					I2C.mode |= _err;
					I2C.step = 6;
				}
			}
			break;
			
		case 4:
			I2CSMB0->CR2 |= I2CSMB_CR2_RWN_Msk;
		  if(I2C.flag == 0)
			{
				I2CSMB0->CR2 |= I2CSMB_CR2_ACKEN_Msk;  //1:NACK
			}
			else
			{
				I2CSMB0->CR2 &= ~I2CSMB_CR2_ACKEN_Msk; //0:ACK
			}
		  I2C.step++;
			break;
			
		case 5:
			if((I2CSMB0->ISR & I2CSMB_ISR_RXIF_Msk) != 0)
			{
				I2C.buffer[I2C.pos++] = I2CSMB0->RXDR;
				I2CSMB0->ISR |= I2CSMB_ISR_RXIF_Msk;
				if(I2C.pos < I2C.total)
				{
					if(I2C.pos == (I2C.total - 1))
					{
						I2C.flag = 0;
					}
					I2C.step--;
				}
				else
				{
					//end
					I2C.step++;
				}
			}
			else
			{
				if((I2CSMB0->ISR & I2CSMB_ISR_ARLO_Msk) != 0)
				{
					//error
					I2C.mode |= _err;
					I2C.step = 6;
				}
			}
			break;
			
		case 6:
			I2CSMB0->CR2 |= I2CSMB_CR2_STOP_Msk;
		  I2C.step++;
			break;
		case 7:
			if((I2CSMB0->CR2 & I2CSMB_CR2_STOP_Msk) == 0)
			{
				I2C.step = 0;
				I2C.mode &= ~_exe;
				I2C.mode |= _finish;
			}
			break;
	}
}





