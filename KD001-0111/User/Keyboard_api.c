#include "Keyboard_api.h"
#include "Alarm_api.h"

KEY_TYPEDEF Key;

void GPIO_IRQHandler(void)
{
  if(FL_GPIO_IsActiveFlag_EXTI(GPIO, FL_GPIO_EXTI_LINE_3))
  {
    FL_GPIO_ClearFlag_EXTI(GPIO, FL_GPIO_EXTI_LINE_3);
		SYS_CLOCK_Init();
		CloseLpTimer();
		System.WakeupMode = _exe;
  }
}

void ScanTestKeyProcess(void)
{
	if((Key.test_value & 0x01) != 0)
	{
		if(!TEST_KEY) //����
		{
			if((Key.test_value & 0x08) != 0)
			{
				Key.test_value = 0x40;
			}
			else
			{
				Key.test_value |= 0x08;
			}
		}
		else
		{
			Key.test_value &= ~0x08;
		}
	}
	else
	{
		if(TEST_KEY) //�ǰ���
		{
			if((Key.test_value & 0x08) != 0)
			{
				Key.test_value = 0x81;
			}
			else
			{
				Key.test_value |= 0x08;
			}
		}
		else
		{
			Key.test_value &= ~0x08;
		}
   }
}


void TestKeyUpEvent(void) //���������¼�
{
	//�����������رշ�������
	if(Key.State & _finish)
	{
		PWM_OFF;
		RED_LED_OFF;
		Alarm.TestStep = 0;
		Alarm.TestMode = _idle;
		
		//��ʾ�¶�,������PPM��ֵ
		Display.Humiture = 0;
		Display.Mode = _exe;
		Key.State = _idle;
		System.WakeupMode = _idle;
	}
	//�̰����������л���ʪ�ȡ���������
	else if(LongTimer < 1000 && Key.State & _exe)
	{
		LongTimer = 0;
		BACK_LED_ON;
		PWM_ON;
		if(Display.Humiture == 0)
		{
			Display.Humiture = 1;
		}
		else
		{
			Display.Humiture = 0;
		}
		//�̰�
		Display.Mode = _exe;
		ShortTimer = 0;
		Key.State = _busy;
		System.WakeupMode = _busy;
	}
	Lptimer.BACKLEDState = 0x1;
	Lptimer.BACKLEDCount = 0;
	Key.test_value = 0x01;
}


void TestKeyDownEvent(void)
{
	LongTimer = 0;
	Key.State = _exe;
	Key.test_value = 0x20;
}




