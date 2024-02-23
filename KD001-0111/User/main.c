#include "main.h"
#include "FM33LF0_System.h"
#include "FM33LF0_Timer.h"
#include "Macro_definition.h"
#include "Window_api.h"
#include "Keyboard_api.h"
#include "Message_Process.h"
#include "Alarm_api.h"
#include "Ppm_Processing.h"
#include "Calibrate_LED.h"
#include "Flash.h"
#include "OPA_api.h"
#include <math.h>
#include "FM33LF0_UART.h"

int main(void)
{   
	ClearSRAM();
	
	SYS_CLOCK_Init();
	
	SYS_GPIO_Init();
	
	ADC_struct.CalState = _exe;
	
	SetSystemTickTimer();
	
  while(1)
  {
/************************************************************************
  * @brief  KEY
	* Timer.t[0]->LongTimer		������ʱ
	* Timer.t[1]->Key_Scan		����ɨ���ʱ
	*	Timer.t[6]->ShortTimer	�̰���ʱ���������죩
*************************************************************************/
		if((Key.State & _exe) != 0)
		{
      if(LongTimer >= 1000)
			{
				//������ʾ ---
				DisplayChar.En = 0;
				DisplayChar.Mode = _exe;
				Alarm.TestMode = _exe;
				Key.State = _finish;
			}
		}
		if(Key_Scan > 19)
		{
			Key_Scan = 0;
      ScanTestKeyProcess();
		  if((Key.test_value & 0x40) != 0 )
		  {
			  TestKeyDownEvent();
		  }
		  if((Key.test_value & 0x80) != 0 )
		  {
			  TestKeyUpEvent();
			}
	  }
		
	//�����̰�ʱ����������
	if(Key.State & _busy)
	{
		if(ShortTimer > 49)
		{
			ShortTimer = 0;
			PWM_OFF;
			Key.State = _idle;
			System.WakeupMode = _idle;
		}
	}
		
/************************************************************************
  * @brief  Humiture Function
  * Timer.t[2] ��ʱ��ʪ���ڲ�����ʱ�������ϵ���ʱ����λ��ʱ��
*************************************************************************/
	if(AHT.mode & _exe)
	{
		RunAHT21Proc();
	}
	if(I2C.mode & _exe)
	{
		RunIICServerProc();
	}

/************************************************************************
  * @brief  ADC Gather Function
	Timer.t[3]->ADC_TIMER ADC��OPA������ʱ
*************************************************************************/	
	if(ADC_struct.CalState & _exe)
	{
		ADC_Calibration();
	}
		
	if(ADC_struct.GatherMode & _exe)
	{
		RunADC_GatherProc();
	}
		
//	if(PpmCount.Mode & _exe)
//	{
//		PpmCountProc();
//	}
		
/************************************************************************
  * @brief  LCD Display Function
*************************************************************************/
	if(Display.Mode & _exe)
	{
		LCDDisplay();	
	}
		
	if(DisplayChar.Mode & _exe)
	{
		LCDDisplay_Char();
	}
	
/************************************************************************
  * @brief  PowerOn Function 
	* Timer.t[4]-> PowerOnTimer	�ϵ��ʱ
*************************************************************************/	
	if(System.PowerMode & _exe)
	{
	 SysPowerOn();
	}
	
/************************************************************************
	*@brief  Alarm Function
	* Timer.t[5] -> AlarmTimer
	* Timer.t[8] -> Faultimer		���ϱ�����ʱ
************************************************************************/
	//���Ա����ź�
//	if(Alarm.TestMode & _exe)
//	{
//		OpenTestAlarm();
//	}
	
	// PPM < 50   Ԥ���ź�
//	if(Alarm.WarnMode & _exe)
//	{
//		OpenWarningProc();
//	}
	
	// 50 <= PPM    �����ź�
//	if(Alarm.AlarmMode & _exe)
//	{
//		OpenAlarmProc();
//		if(AlarmOnTimer > 49999)
//		{
//			AlarmOnTimer = 0;
//			ADC_struct.LppmState = 0x1;
//			ADC_struct.GatherMode = _exe;
//		}
//	}
	
	//��ѹ����·����·��������ֹ�ȹ��ϱ���
//	if(FaultAlarm.Mode & _exe)
//	{
//		FaultAlarmProc();
//	}
	
/************************************************************************
	*@brief  Analog Discharge Function
	* Timer.t[7]->DCTimer	
************************************************************************/
//	if(ADC_struct.DCState & _exe)
//	{
//		RunEle_DischargeProc();
//	}
	
/************************************************************************
	*@brief  LifeTimer Function
	* 	
************************************************************************/	
//	if(Lptimer.EndCount > 8639)
//	{
//		Lptimer.EndCount = 0;
//		DayTimer.Mode = _exe;
//	}
//	if(DayTimer.Mode & _exe)
//	{
//		Day_TimerPrco();
//	}
//	if(*((uint32_t *)FLASH_Day_Time) >= EndLifeTimer && *((uint32_t *)FLASH_Day_Time) != 0xFFFFFFFF)
//	{
//		FaultAlarm.LifeEState = 1;
//		FaultAlarm.Mode = _exe;
//	}
/************************************************************************
	*@brief  UART0 
	* 		
************************************************************************/	
	if(Serial0Tx.Mode & _exe)
	{
		RunUART0TxProc();
	}
	
/************************************************************************
	*@brief  Calibrate 
	* Timer.t[9] -> DebugTimer		
************************************************************************/	
	if(Debug.Mode & _exe)
	{
		Debug_Mode();
	}
	
	if(CalLED.Mode & _exe)
	{
		LED_Calibration();
	}
	
//	if(OPAOffset.Mode & _exe)
//	{
//		OPA_Offset();
//	}
/************************************************************************
	*@brief  Flash 
	* 	
************************************************************************/	
//	if(Flash.Mode & _exe)
//	{
//		FlashFunctionPrco();
//	}
	
/************************************************************************
  * @brief  Message Process Function
*************************************************************************/
	Message_Process();
	
/************************************************************************
  * @brief  DEEPSLEEP Process Function
	* 	All TASK Are Completed -> DeepSleep
*************************************************************************/	
	if(TASK_FLAG == _idle) 
	{
//		AlarmOnTimer = 0;
		//�����͹��Ķ�ʱ��
		OpenLpTimer();
		//���ߺ���
		GotoDeepSleep();
	}
	
/************************************************************************
  * @brief  Check System Tick Timer
*************************************************************************/
	//ι���Ź�
	IWDT->SERV = IWDT_RELOAD_KEY;
	CheckSystemTickTimer();
  }
}

