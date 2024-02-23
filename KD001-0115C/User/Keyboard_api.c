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
		if(!TEST_KEY) //按下
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
		if(TEST_KEY) //非按下
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


void TestKeyUpEvent(void) //按键弹起事件
{
	//长按结束，关闭蜂鸣器，
	if(Key.State & _finish)
	{
		PWM_OFF;
		RED_LED_OFF;
		Alarm.TestStep = 0;
		Alarm.TestMode = _idle;
		
		//显示温度,电量，PPM的值
		Display.Humiture = 0;
		Display.Mode = _exe;
		Key.State = _idle;
		System.WakeupMode = _idle;
	}
	//短按：亮屏、切换温湿度、蜂鸣器响
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
		//短按
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




