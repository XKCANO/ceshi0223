#include "Message_Process.h"
#include "Macro_definition.h"
#include "FM33LF0_System.h"
#include "Alarm_api.h"
#include "Flash.h"
#include "Calibrate_LED.h"

/*
**	标志位处理
*/
void Message_Process(void)
{
	//50s->温湿度数据采集，电源指示灯亮，Lppm采集
	if(Lptimer.HtCount > 4)
	{
		GREEN_LED_ON;
		AHT.mode = _exe;
		Lptimer.HtCount = 0;
		ADC_struct.LppmState = 0x1;
		ADC_struct.GatherMode = _exe;
	}
	//80s->电压数据采集
	if(Lptimer.BatCount > 7)
	{
		ADC_struct.BatState = 0x1;
		ADC_struct.GatherMode = _exe;
		Lptimer.BatCount = 0;
	}
	//320s->模拟放电数据采集
//	if(Lptimer.DCCount > 31)
//	{
//		ADC_struct.BatState = 0;
//		ADC_struct.DCState = _exe;
//		Lptimer.DCCount = 0;
//	}
	//第一PPM等级警报延时计数 120s
//	if(Lptimer.WarnCount > 11 && Alarm.WarnState != 0)
//	{
//		Alarm.WarnMode = _exe;
//		Lptimer.WarnCount = 0;
//	}
	
	//故障警报延时计数 60s
//	if(Lptimer.FlautAlarmCount > 4)
//	{
//		if(FaultAlarm.LifeEState != 0 || FaultAlarm.LowVState != 0 || FaultAlarm.ShortCState != 0)
//		{
//			FaultAlarm.Mode = _exe;
//		}
//	}
	
	//LED背景灯关闭使能
	if(Lptimer.BACKLEDCount == 1 && Lptimer.BACKLEDState != 0)
	{
		BACK_LED_OFF;
		Lptimer.BACKLEDState = 0;
		Lptimer.BACKLEDCount = 0;
	}
}



	
	
	
