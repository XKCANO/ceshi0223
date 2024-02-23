#ifndef __MACRO_DEFINITION_H
#define __MACRO_DEFINITION_H

#include "fm33lf0xx_fl_gpio.h"
#include "fm33lf0xx_fl_lcd.h"


//LED->GPIO
#define BACK_LED_ON 			(GPIOB->DRST |=  FL_GPIO_PIN_8)
#define BACK_LED_OFF  		(GPIOB->DSET |=  FL_GPIO_PIN_8)
#define GREEN_LED_ON  		(GPIOB->DSET |=  FL_GPIO_PIN_9)
#define GREEN_LED_OFF 		(GPIOB->DRST |=  FL_GPIO_PIN_9)
#define YELLOW_LED_ON  		(GPIOB->DSET |=  FL_GPIO_PIN_11)
#define YELLOW_LED_OFF 		(GPIOB->DRST |=  FL_GPIO_PIN_11)
#define RED_LED_ON  			(GPIOB->DSET |=  FL_GPIO_PIN_10)
#define RED_LED_OFF 			(GPIOB->DRST |=  FL_GPIO_PIN_10)

//R-TEST
#define	RTEST_ON				(GPIOB->DSET |=  FL_GPIO_PIN_15)
#define	RTEST_OFF				(GPIOB->DRST |=  FL_GPIO_PIN_15)

//KEY->Timer
#define LongTimer  		Timer.t[0]
#define Key_Scan 			Timer.t[1]
#define PowerOnTimer	Timer.t[4]
#define AlarmTimer		Timer.t[5]
#define ShortTimer		Timer.t[6]
#define DCTimer				Timer.t[7]
#define DebugTimer		Timer.t[9]
#define LEDCalTimer	  Timer.t[10]
#define UARTTimer	  	Timer.t[11]
#define AlarmOnTimer	Timer.t[12]
#define CalTimer			Timer.t[13]


#define EndLifeTimer 			3650
#define CalibrateVoltage 	2.7

#define PWM_ON 				OpenPWM()
#define PWM_OFF 			ClosePWM()


#define TASK_FLAG 		System.PowerMode + System.WakeupMode + Display.Mode + DisplayChar.Mode + ADC_struct.DCState  + ADC_struct.GatherMode + CalLED.Mode +		\
											ADC_struct.CalState + PpmCount.Mode + AHT.mode + Key.State + Alarm.WarnMode + Alarm.AlarmMode + FaultAlarm.Mode + Serial0Tx.Mode

			

#define			_idle				0x00
#define			_exe				0x01
#define			_busy				0x10
#define			_end				0x20
#define			_err				0x40
#define			_finish			0x80

//#define			_normal			10000
//#define			_success		10000
//#define			_failed			10001
//#define			_error			10002

//#define  		_less  			0xFF
//#define  		_equal  		0
//#define  		_greater 		1

//#define			_update			0x01
//#define			_enable			0x01
//#define			_disable		0x00


#endif

