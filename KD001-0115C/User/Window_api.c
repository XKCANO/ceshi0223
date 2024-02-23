#include "Window_api.h"
#include "Message_Process.h"
#include "Alarm_api.h"
#include "Flash.h"
#include "Calibrate_LED.h"
#include "main.h"
#include <math.h>
#include <stdlib.h>
#include "FM33LF0_UART.h"



Lptimer_typedef Lptimer;
System_Typedef System;
Debug_Typedef Debug;
LowRom_typedef LowRom;
DayTimer_typedef DayTimer;

void LPTIM16_IRQHandler(void)
{
	if(FL_LPTIM16_IsActiveFlag_Update(LPTIM16))
  {
		FL_LPTIM16_ClearFlag_Update(LPTIM16);
		SYS_CLOCK_Init();
		CloseLpTimer();
//		if(*((uint32_t *)FLASH_Count) == 0x1)
//		{
			Lptimer.HtCount++;
			Lptimer.BatCount++;
//			Lptimer.WarnCount++;
//			Lptimer.LVCount++;
//			Lptimer.EndCount++;
//			Lptimer.FlautAlarmCount++;
			Lptimer.BACKLEDCount = 1;
//		}
	}
}

void SysPowerOn(void)
{
	switch(System.Step)
	{
		case 0:
			PWM_ON;YELLOW_LED_ON;GREEN_LED_ON;RED_LED_ON;BACK_LED_ON;
			Key.test_value = 0x01;
			KEY_GPIO();
			DisplayChar.En = 1;
			DisplayChar.Mode = _exe;
			PowerOnTimer = 0;
			System.Step++;
			break;
		case 1:
			if(PowerOnTimer > 199)
			{
				YELLOW_LED_OFF;
				GREEN_LED_OFF;
				RED_LED_OFF;
				BACK_LED_OFF;
				PWM_OFF;
				System.Step++;
			}
			break;
		case 2:
			if(PowerOnTimer > 999)
			{
				AHT.mode = _exe;
				ADC_struct.BatState = 0x1;
//				ADC_struct.LppmState = 0x1;
				ADC_struct.GatherMode = _exe;
				System.Step++;
			}
		  break;
		case 3:
			System.Step = 0;
			System.PowerMode = _idle;
			break;
	}
}


void Debug_Mode(void)
{
	switch(Debug.Step)
	{
		case 0:
			DebugTimer = 0;
			Debug.Step++;
			break;
		case 1:
			if(DebugTimer > 4999 && ADC_struct.GatherMode == _idle)
			{
				ADC_struct.BatState = 1;
				ADC_struct.GatherMode = _exe;
				Debug.Step++;
			}
			break;
		case 2:
			if(ADC_struct.GatherMode == _idle)
			{
				if(Display.Bat < CalibrateVoltage)
				{
					ADC_struct.HppmState = 1;
					ADC_struct.GatherMode = _exe;
					Debug.Step++;
					Debug.i++;
				}
				else
				{
					Debug.Step = 0;
				}
			}
			break;
		case 3:
			if(ADC_struct.GatherMode == _idle)
			{
				LowRom.Average[Debug.i] = ADC_struct.Ppm[2];
				if(Debug.i < 10)
				{
					DebugTimer = 0;
					Debug.Step = 7;
				}
				else
				{
					if(Debug.CalHunderd == 0)	//第一次标0
					{
						LowRom.ZeroPpm = GetAveragePrco(LowRom.Average);
						LowRom.Count = 0x0;
						Flash.State = 1;
						Flash.len = 2;
						Debug.Step++;	
					}
					else	//第二次标100，取三次的平均值
					{
						LowRom.HunderdPpm = GetAveragePrco(LowRom.Average);
						LowRom.ZeroPpm = *((uint32_t *)FLASH_ZeroPpm);
						Flash.State = 0;
						Debug.Step += 2;
					}
					Debug.i = 0;
					Flash.Mode = _exe;
				}
			}
			break;
		case 4:
			if(Flash.Mode == _idle)
			{
				LowRom.ZeroPpm = *((uint32_t *)FLASH_ZeroPpm);
				if(abs(ADC_struct.Ppm[2] - LowRom.ZeroPpm) <= 5)
				{
					//标0成功
					LowRom.ZeroFlag = 1;
					LowRom.State = 1;
					YELLOW_LED_OFF;RED_LED_OFF;GREEN_LED_OFF;
					Display.Ppm = 100;
					Display.Step = 0;
					Display.Mode = _exe;
				}
				else
				{
					//标0失败
					LowRom.ZeroFlag = 0;
					LowRom.State = 2;
					CalLED.Mode = _exe;
				}
				Debug.Step = 0;
				Debug.Mode = _idle;
			}
			break;
		case 5:
			if(Flash.Mode == _idle)
			{
				LowRom.day_time = 0;
				LowRom.Version = 3;
				LowRom.Count = 0x1;
				Flash.State = 1;
				Flash.len = 5;
				Flash.Mode = _exe;
				Debug.Step++;
			}
			break;
		case 6:
			if(Flash.Mode == _idle)
			{
				if(abs((int)LowRom.HunderdPpm - *((int *)FLASH_HunderdPpm)) <= 5 && abs((int)LowRom.ZeroPpm - *((int *)FLASH_ZeroPpm)) <= 5)
				{
					//标100成功
					LowRom.HunderdFlag = 1;
					LowRom.State = 3;
					YELLOW_LED_OFF;RED_LED_OFF;GREEN_LED_OFF;
					Display.Ppm = 100;
					Display.Step = 0;
					Display.Mode = _exe;
				}
				else
				{
					//标100失败
					LowRom.HunderdFlag = 0;
					LowRom.State = 2;
					CalLED.Mode = _exe;
				}
				Debug.Step = 0;
				Debug.Mode = _idle;
			}
			break;
		case 7:
			if(DebugTimer > 999)
			{
				Debug.Step = 2;
			}
			break;
	}

}

void Day_TimerPrco(void)
{
	switch(DayTimer.Step)
	{
		case 0:
			if(Flash.Mode == _idle)
			{
				LowRom.Count = *((uint32_t *)FLASH_Count);
				LowRom.ZeroPpm = *((uint32_t *)FLASH_ZeroPpm);
				LowRom.HunderdPpm = *((uint32_t *)FLASH_HunderdPpm);
				LowRom.day_time = *((uint32_t *)FLASH_Day_Time);
				LowRom.day_time += 1;
				LowRom.Version = *((uint32_t *)FLASH_Version);
				Flash.State = 0;
				Flash.Mode = _exe;
				DayTimer.Step++;
			}
			break;
		case 1:
			if(Flash.Mode == _idle)
			{
				Flash.State = 1;
				Flash.len = 5;
				Flash.Mode = _exe;
				DayTimer.Step++;
			}
			break;
		case 2:
			if(Flash.Mode == _idle)
			{
				DayTimer.Step = 0;
				DayTimer.Mode = _idle;
			}
			break;
	}

}

uint16_t GetAveragePrco(uint16_t arr[])
{
	uint16_t Max = arr[0];
	uint16_t Min = arr[0];
	uint16_t Sum = 0;
	
	for(uint8_t i = 0;i < 10; i++)
	{
		if(arr[i] > Max)
		{
			Max = arr[i];
		}
		if (arr[i] < Min)
		{
			Min = arr[i];
		}
     Sum += arr[i];
	}
	Sum -= (Max + Min);
	Sum = Sum / 8;
	
	return Sum;
}





