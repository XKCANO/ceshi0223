#include "Calibrate_LED.h"
#include "Macro_definition.h"
#include "Adc_api.h"
#include "Flash.h"
#include "FM33LF0_UART.h"


CalLED_typedef CalLED;

void LED_Calibration(void)
{
	switch(CalLED.Step)
	{
		case 0:
			if(LowRom.State == 0 && *((uint32_t *)FLASH_Count) == 0xFFFFFFFF)
			{
				//�궨0֮ǰ
				YELLOW_LED_ON;
				GREEN_LED_OFF;
				RED_LED_ON;
			}
			else if(LowRom.State == 0 && *((uint32_t *)FLASH_Count) == 0)
			{
				//�궨100֮ǰ
				GREEN_LED_ON;
				RED_LED_ON;
				YELLOW_LED_OFF;
			}
			else if(LowRom.State == 1)
			{
				//�궨0�ɹ�
				YELLOW_LED_ON;
				GREEN_LED_ON;
				RED_LED_OFF;
			}
			else if(LowRom.State == 2)
			{
				//�궨0ʧ��
				RED_LED_ON;
				YELLOW_LED_OFF;
				GREEN_LED_OFF;
			}
			else if(LowRom.State == 3)
			{
				//�궨100�ɹ�
				GREEN_LED_ON;
				RED_LED_ON;
				YELLOW_LED_OFF;
			}
			LEDCalTimer = 0;
			CalLED.Step++;
			break;
		case 1:
			if(LEDCalTimer > 99)
			{
				if(LowRom.State == 0 && *((uint32_t *)FLASH_Count) == 0xFFFFFFFF)
				{
					//�궨0֮ǰ
					YELLOW_LED_ON;
					GREEN_LED_OFF;
					RED_LED_OFF;
				}
				else if(LowRom.State == 0 && *((uint32_t *)FLASH_Count) == 0)
				{
					//�궨100֮ǰ
					GREEN_LED_ON;
					RED_LED_OFF;
					YELLOW_LED_OFF;
				}
				else if(LowRom.State == 1)
				{
					//�궨0�ɹ�
					YELLOW_LED_ON;
					GREEN_LED_OFF;
					RED_LED_ON;
				}
				else if(LowRom.State == 2)
				{
					//�궨0ʧ�� �궨100ʧ��
					RED_LED_ON;
					YELLOW_LED_OFF;
					GREEN_LED_OFF;
				}
				else if(LowRom.State == 3)
				{
					//�궨100�ɹ�
					GREEN_LED_ON;
					RED_LED_OFF;
					YELLOW_LED_ON;
				}
				CalLED.Step++;
			}
			break;
		case 2:
			if(LEDCalTimer > 199)
			{
				CalLED.Step = 0;
			}
			break;
	}
}


