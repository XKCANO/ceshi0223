#include <math.h>
#include <stdlib.h>
#include "Adc_api.h"
#include "Message_Process.h"
#include "Alarm_api.h"
#include "Ppm_Processing.h"
#include "Flash.h"
#include "Calibrate_LED.h"
#include "FM33LF0_UART.h"

ADC_TYPEDEF ADC_struct;

/*
** 开启 ADC
*/

void ADC_Open(void)
{
  PMU->PTATCR  |= PMU_PTATCR_PTAT_EN_Msk;  
  CMU->PCLKCR2 |= FL_CMU_GROUP2_BUSCLK_ADC;
 
  ADC->CFGR1   &= ~(0x7<<5U);
  ADC->CFGR1   |= FL_ADC_APBCLK_PSC_DIV1 + FL_ADC_REF_SOURCE_VDDA + FL_ADC_Negative_Peference_VSSA;

  ADC->CFGR2 = 0;
  ADC->CFGR2 |= (FL_ADC_OVERSAMPLING_MODE_ENABLE_AVERAGE + FL_ADC_OVERSAMPLING_SHIFT_4B + FL_ADC_OVERSAMPLING_MUL_16X +
                 ADC_CFGR2_OVRM_Msk + ADC_CFGR2_WAIT_F_Msk + ADC_CFGR2_CONT_MOD_Msk + FL_ADC_SCANACQ_CONV_MODE_AUTO + FL_ADC_SCANACQ_SCAN_DIR_FORWARD);
 
  ADC->SCANACQ_CR = FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK + FL_ADC_ACQ_TRGI_SOFE_TRG;
}

/*
** 关闭 ADC
*/
void ADC_Close(void)
{
  PMU->PTATCR  &= ~(PMU_PTATCR_PTAT_EN_Msk);  
  CMU->PCLKCR2 &= ~(FL_CMU_GROUP2_BUSCLK_ADC);

  ADC->CFGR1   = 0x300120U;
  ADC->CFGR2   = 0x500U;
  ADC->SCANACQ_CR  = 0x1U;
}


/*
** ADC上电校准
*/
void ADC_Calibration(void)
{
	switch(ADC_struct.CalStep)
	{
		case 0:
			PMU->PTATCR |= PMU_PTATCR_PTAT_EN_Msk;
			CMU->PCLKCR2 |= FL_CMU_GROUP2_BUSCLK_ADC + FL_CMU_GROUP2_BUSCLK_OPA;
			ADC->CFGR1 &= ~(0x7<<5U);
			ADC->CFGR1 |= FL_ADC_APBCLK_PSC_DIV1 + FL_ADC_REF_SOURCE_VDDA + FL_ADC_Negative_Peference_VSSA;
			ADC->CFGR2 &= 0xfe00ffffU;  
			ADC->CFGR2 |= FL_ADC_OVERSAMPLING_MUL_32X + FL_ADC_OVERSAMPLING_SHIFT_5B + FL_ADC_OVERSAMPLING_MODE_ENABLE_AVERAGE; 
			OPA2->CR = 0;
			OPA2->CR |= FL_OPA_INP_SOURCE_INP1 + OPA_CR_EN_Msk;
			ADC_TIMER = 0;
			ADC_struct.CalStep++;
			break;
		case 1:
			if(ADC_TIMER > 9)
			{
				ADC->CR1 |= ADC_CR1_ADEN_Msk; 
				ADC->OSR |= ADC_OSR_CALEN_Msk;
				ADC->ACQ0_CR &= ~(0x1f<<4U); 
				ADC->ACQ0_CR &= ~(0x1f<<9U);
				ADC->ACQ0_CR |= FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFP + FL_ADC_ACQ_TRGI_SOFE_TRG;
				ADC->CR1 |= FL_ADC_ACQ0  << 0x10U ;
				ADC->ACQ1_CR &= ~(0x1f<<4U); 
				ADC->ACQ1_CR &= ~(0x1f<<9U);
				ADC->ACQ1_CR |= FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN + FL_ADC_ACQ_TRGI_SOFE_TRG;
				ADC->CR1 |= FL_ADC_ACQ1 << 0x10U;
				ADC->CR2 |= 0x3U;   //ACQ触发转换 
				ADC_struct.CalStep++;
			}
			break;
		case 2:
			if(FL_ADC_IsActiveFlag_EndOfConversion(ADC, FL_ADC_ACQ0|FL_ADC_ACQ1))
			{
			 	ADC_struct.ACQ0_Data = (uint32_t)ADC->ACQ0_DR;
				ADC_struct.ACQ1_Data = (uint32_t)ADC->ACQ1_DR;
				ADC->OSR &= ~(0x1fffU);
				ADC->OSR |= ((ADC_struct.ACQ0_Data + ADC_struct.ACQ1_Data) - 4095)/2;	
				ADC->OSR &= ~(ADC_OSR_CALEN_Msk);
				ADC->CR1 &= ~(ADC_CR1_ADEN_Msk);
				ADC->CR1 &= ~(0x3U << 0x10U);     //关闭ACQ校准完成
				ADC_struct.CalStep++;
			}
			break;
		case 3:
			LowRom.Count = *((uint32_t *)FLASH_Count);
//			if(LowRom.Count == 0x1)
//			{
				//正常工作模式
				System.PowerMode = _exe;
//			}
//			else 
//			{
//				CalLED.Mode = _exe;
//				Debug.Mode = _exe;
//				Display.Mode = _exe;
//				if(LowRom.Count == 0xFF)
//				{
//					//标0
//					Debug.CalHunderd = 0;
//				}
//				else
//				{
//					//标100
//					Debug.CalHunderd = 1;
//				}
//			}
			ADC_struct.CalStep = 0;
			ADC_struct.CalState = _idle;
			break;
	}
}

/*
** ADC 采集函数
*/
void RunADC_GatherProc(void)
{
	switch(ADC_struct.Step)
	{
		case 0://设置优先级，电压采集 > Lppm采集
			if((ADC_struct.BatState == 0x1) && (ADC_struct.LppmState == 0x1))
			{
				ADC_struct.LppmState = 0x2;
			}
			if((ADC_struct.BatState == 0) && (ADC_struct.LppmState == 0x2))
			{
				ADC_struct.LppmState = 0x1;
			}
			ADC_struct.Step++;
			break;
		case 1:
			ADC_Open();
			if(ADC_struct.BatState == 0x1)
			{
				BATOUT_ON;
			}
			ADC_TIMER = 0;
			ADC_struct.Step++;
			break;
		case 2:
			if(ADC_TIMER > 9)
			{
				ADC->CR1 |= ADC_CR1_ADEN_Msk;    //开ADC
				PMU->BUFCR |= PMU_BUFCR_AVREFBUF_EN_Msk;  //使能VREF BUFFER
				if(ADC_struct.BatState == 1)
				{
					ADC->ACQ_SACR = FL_ADC_SCANACQ_EXTERNAL_CH8 + FL_ADC_SCANACQ_INTERNAL_AVREF;     //打开通道8
					ADC->ACQ_ISR |= FL_ADC_SCAN_ACQ;       //清除标志位    
					ADC->CR1 |= FL_ADC_SCAN_ACQ << 0x10U;  //使能SCAN_ACQ 清零
				}
				if(ADC_struct.LppmState == 0x1)
				{
					ADC->ACQ_SACR = FL_ADC_SCANACQ_EXTERNAL_CH11 + FL_ADC_SCANACQ_INTERNAL_AVREF;     //打开通道11
					ADC->ACQ_ISR |= FL_ADC_SCAN_ACQ;     //清除标志位
					ADC->CR1 &= ~(0x3fU << 16U);
					ADC->CR1 |= FL_ADC_SCAN_ACQ << 16U;  //使能SCAN_ACQ 清零
				}
				if(ADC_struct.HppmState == 0x1)
				{
					ADC->ACQ_SACR = FL_ADC_SCANACQ_EXTERNAL_CH10 + FL_ADC_SCANACQ_INTERNAL_AVREF;     //打开通道10
					ADC->ACQ_ISR |= FL_ADC_SCAN_ACQ;     //清除标志位
					ADC->CR1 &= ~(0x3fU << 16U);
					ADC->CR1 |= FL_ADC_SCAN_ACQ << 16U;  //使能SCAN_ACQ 清零
				}
				ADC->CR2 |= FL_ADC_SCAN_ACQ ;   //触发SCAN_ACQ转换
				ADC_struct.Step++;
			}
			break;
		case 3:
			if(((ADC->ACQ_ISR >> 0x4U) & 0x1U) == 0x1)
			{
				if(ADC_struct.BatState == 0x1)
				{
					ADC_struct.Bat = ((uint32_t)(ADC->SCANACQ_DR) * 2) > 4095 ? 4095:ADC_struct.Bat;
					Display.Bat = ADC_struct.Bat;
				}
				if(ADC_struct.LppmState == 0x1 || ADC_struct.HppmState == 0x1)
				{
					ADC_struct.Lppm[0] = (uint32_t)ADC->SCANACQ_DR;
				}
				ADC_struct.Step++;
			}
			break;
		case 4:
			if(((ADC->ACQ_ISR >> 0x4U) & 0x1U) == 0x1)
			{
        ADC_struct.VAREF = (uint32_t)(ADC->SCANACQ_DR);
				if(ADC_struct.BatState == 0x1)
				{
					Display.Bat = Display.Bat / ADC_struct.VAREF;
//					if(Display.Bat < 2.4)
//					{
//						FaultAlarm.LowVState = 1;
//						FaultAlarm.Mode = _exe;				
//					}
//					else
//					{
//						FaultAlarm.LowVState = 0;
//					}
					ADC_struct.Step += 2;
				}
				if(ADC_struct.LppmState == 0x1 || ADC_struct.HppmState == 0x1)
				{
					ADC_struct.Step++;
				}
			}
			break;
		case 5:
			if(((ADC->ACQ_ISR >> 0x4U) & 0x1U) == 0x1)
			{
				ADC_struct.Lppm[1] = (uint32_t)ADC->SCANACQ_DR;
				ADC_struct.Lppm[2] = (ADC_struct.Lppm[0] + ADC_struct.Lppm[1]) / 2;
				if(*((uint32_t *)FLASH_Count) == 0x1)
				{
					Display.Lppm = 0;
//					if(ADC_struct.Lppm[2] <= *((uint32_t *)FLASH_HunderdPpm))
//					{
//						Display.Lppm = 100.0 * ((int)ADC_struct.Lppm[2] - *((int *)FLASH_ZeroPpm)) / (*((int *)FLASH_HunderdPpm) - *((int *)FLASH_ZeroPpm));
//						Display.Lppm = Display.Lppm > 0 ?  Display.Lppm:0;
//					}
//					else
//					{
//						Display.Lppm = (float)(100 * (ADC_struct.Lppm[2] - *((int *)FLASH_ZeroPpm)) - 17 *  ADC_struct.VAREF * pow((float)((ADC_struct.Lppm[2] - *((int *)FLASH_HunderdPpm))/ ADC_struct.VAREF),1.6)) / (*((int *)FLASH_HunderdPpm) - *((int *)FLASH_ZeroPpm));
//					}
//					PpmCount.Mode = _exe;
				}
				ADC_struct.Step++;
				if(ADC_struct.Lppm[2] >= 0xFA0 && ADC_struct.LppmState == 1)
				{
					ADC_struct.LppmState = 0;
					ADC_struct.HppmState = 1;
					ADC_TIMER = 0;
					ADC_struct.Step = 2;
				}
			}
			break;
		case 6:
			ADC->CFGR2 &= 0x0 << 9; //关闭连续采样
      ADC->CR1 &= ~(FL_ADC_SCAN_ACQ << 0x10U);
      ADC->ACQ_SACR = 0x1U; //恢复默认值
      PMU->BUFCR &= ~(PMU_BUFCR_AVREFBUF_EN_Msk);
      ADC->CR1 &= ~(ADC_CR1_ADEN_Msk);
			ADC_struct.Step++;
			break;
		case 7:
			ADC_Close();
			if(ADC_struct.BatState == 0x1)
			{
				BATOUT_OFF;
				ADC_struct.BatState = 0;
			}
			else if(ADC_struct.LppmState == 0x1)
			{
				ADC_struct.LppmState = 0;
				Display.Mode = _exe;
			}
			else if(ADC_struct.HppmState == 0x1)
			{
				ADC_struct.HppmState = 0;
				Display.Mode = _exe;
			}
			ADC_struct.Step++;
			break;
		case 8:
			if(ADC_struct.LppmState == 0 && ADC_struct.BatState == 0 && ADC_struct.HppmState == 0)
			{
//				if(*((uint32_t *)FLASH_Count) == 0xFFFFFFFF)
//				{
//					Display.Lppm = 0;
//				}
				Display.Mode = _exe;
				ADC_struct.Step = 0;
				ADC_struct.GatherMode = _idle;			
			}
			else
			{
				ADC_struct.Step = 0;
			}
			break;
	}
}

/*
** 模拟放电函数
*/
void RunEle_DischargeProc(void)
{
	switch(ADC_struct.DCStep)
	{
		case 0:
			RTEST_ON;
			DCTimer = 0;
			ADC_struct.DCStep++;
			break;
		case 1:
			if(DCTimer > 9)
			{
				RTEST_OFF;
				ADC_struct.DCStep = 0;
				ADC_struct.BatState = 1;
				ADC_struct.GatherMode = _exe;
				ADC_struct.DCState = _idle;
			}
			break;
	}
}


