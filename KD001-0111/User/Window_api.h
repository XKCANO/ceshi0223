#ifndef __WINDOW_API_H
#define __WINDOW_API_H

#include "fm33lf0xx_fl_conf.h"
#include "stdint.h"
#include "Macro_definition.h"
#include "Lcd_api.h"
#include "FM33LF0_IIC.h"
#include "Adc_api.h"
#include "FM33LF0_Timer.h"


typedef struct  
{
	unsigned char BACKLEDState;
	unsigned char BACKLEDCount;
	
	unsigned char HtCount;
	unsigned char Lppm_idx;
	unsigned char BatCount;
	unsigned char DCCount;
	unsigned char WarnCount;
	unsigned char LVCount;
	unsigned short EndCount;
	unsigned char FlautAlarmCount;
}Lptimer_typedef;

typedef struct
{
	unsigned char PowerMode;
	unsigned char WakeupMode;
	unsigned char Step;
}System_Typedef;

typedef struct
{
	unsigned char Mode;
	unsigned char Step;
	unsigned char i;
	bool CalHunderd;
}Debug_Typedef;


typedef struct
{
	bool ZeroFlag;
	bool HunderdFlag;
	unsigned char State;
	unsigned short Average[10];
	
	unsigned short ZeroPpm;
	unsigned short HunderdPpm;
	unsigned char Count;
	unsigned char product_id;
	unsigned char id[4];
	unsigned char reserved[2];
	unsigned short year;
	unsigned char month;
	unsigned char day;
	unsigned int UID[3];
	unsigned int day_time;
	unsigned char Version;
}LowRom_typedef;

typedef struct
{
	unsigned char Mode;
	unsigned char Step;
}DayTimer_typedef;



void Debug_Mode(void);
void SysPowerOn(void);
void Day_TimerPrco(void);
uint16_t GetAveragePrco(uint16_t arr[]);


extern Lptimer_typedef Lptimer;
extern System_Typedef System;
extern Debug_Typedef Debug;
extern LowRom_typedef LowRom;
extern DayTimer_typedef DayTimer;


#endif

