#include "Alarm_api.h"
#include "Keyboard_api.h"

AlARM_TYPEDEF	Alarm;

FaultAlarm_typedef FaultAlarm;

//°´¼ü²âÊÔ±¨¾¯³ÌÐò
void OpenTestAlarm(void)
{
	BACK_LED_ON;
	Lptimer.BACKLEDState = 0x1;
	switch(Alarm.TestStep)
	{
		case 0:
			RED_LED_ON;
			PWM_ON;
			AlarmTimer = 0;
			Alarm.TestStep++;
			break;
		case 1:
			if(AlarmTimer > 149)
			{
				RED_LED_OFF;
				Alarm.TestStep++;
			}
			break;
		case 2:
			if(AlarmTimer > 199)
			{
				PWM_OFF;
				Alarm.TestStep++;
			}
			break;
		case 3:
			if(AlarmTimer > 249)
			{
				Alarm.TestStep = 0;
				AlarmTimer = 0;
			}
			break;
	}
}

/*
** Warning Alarm( < 50, >= 15 )
*/

void OpenWarningProc(void)
{
	switch(Alarm.Step)
	{
		case 0:
			RED_LED_ON;
			PWM_ON;
			AlarmTimer = 0;
			Alarm.Step++;
			break;
		case 1:
			if(AlarmTimer > 9)
			{
				RED_LED_OFF;
				Alarm.Step++;
			}
			break;
		case 2:
			if(AlarmTimer > 999)
			{
				PWM_OFF;
				Alarm.Step++;
			}
			break;
		case 3:
			if(AlarmTimer > 1499)
			{
				PWM_ON;
				RED_LED_ON;
				Alarm.Step++;
			}
			break;
		case 4:
			if(AlarmTimer > 1509)
			{
				RED_LED_OFF;
				Alarm.Step++;
			}
			break;
		case 5:
			if(AlarmTimer > 2499)
			{
				PWM_OFF;
				Alarm.Step = 0;
				AlarmTimer = 0;	
				Alarm.WarnState = 0x1;
				Alarm.WarnMode = _idle;
			}
			break;
	}
}


/*
** PPM Alarm(  >=50 )
*/
void OpenAlarmProc(void)
{
	switch(Alarm.Step)
	{
		case 0:
			RED_LED_ON;
			PWM_ON;
			AlarmTimer = 0;
			Alarm.Step++;
			break;
		case 1:
			if(AlarmTimer > 9)
			{
				RED_LED_OFF;
				Alarm.Step++;
			}
			break;
		case 2:
			if(AlarmTimer > 499)
			{
				PWM_OFF;
				Alarm.Step++;
			}
			break;
		case 3:
			if(AlarmTimer > 999)
			{
				Alarm.Step = 0;
				AlarmTimer = 0;
			}
			break;
	}
}


/*
** Fault Alarm Proc
*	 FaultAlarm.LowVState == 1£»µÍÑ¹±¨¾¯
*	 FaultAlarm.ShortCState == 1£»¶ÌÂ·±¨¾¯
*	 FaultAlarm.LifeFState == 1£»ÊÙÃüÖÕÖ¹±¨¾¯
*/ 

void FaultAlarmProc(void)
{
	switch(FaultAlarm.Step)
	{
		case 0:
			PWM_ON;
			YELLOW_LED_ON;
			Faultimer = 0;
			FaultAlarm.Step++;
			break;
		case 1:
			if(Faultimer > 9)
			{
			  PWM_OFF;
				if(FaultAlarm.LowVState)
				{
					FaultAlarm.Step = 6;
				}
				else
				{
				  FaultAlarm.Step++;
				}
			}
			break;
		case 2:
			if(Faultimer > 309)
			{
				PWM_ON;
				FaultAlarm.Step++;
			}
			break;
		case 3:
			if(Faultimer > 319)
			{
				PWM_OFF;
				if(FaultAlarm.ShortCState)
				{
					FaultAlarm.Step = 6;
				}
				else
				{
					FaultAlarm.Step++;
				}
			}
			break;
		case 4:
			if(Faultimer > 619)
			{
				PWM_ON;
				FaultAlarm.Step++;
			}
			break;
		case 5:
			if(Faultimer > 629)
			{
				PWM_OFF;
				FaultAlarm.Step++;
			}
			break;
		case 6:
			YELLOW_LED_OFF;
			FaultAlarm.Step = 0;
			Lptimer.FlautAlarmCount = 0;
			FaultAlarm.Mode = _idle;
			break;
	}
}



