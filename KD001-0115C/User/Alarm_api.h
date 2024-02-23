#ifndef __ALARM_API_H
#define __ALARM_API_H

#include "Macro_definition.h"

#define  Faultimer	Timer.t[8]

typedef struct
{
	unsigned char Step;
	unsigned char WarnMode;
	unsigned char WarnState;
	unsigned char AlarmMode;
	
	unsigned char TestStep;
	unsigned char TestMode;
}AlARM_TYPEDEF;

typedef struct
{
	unsigned char Mode;
	unsigned char Step;
	unsigned char LowVState;
	unsigned char ShortCState;
	unsigned char LifeEState;
}FaultAlarm_typedef;


void OpenWarningProc(void);
void OpenAlarmProc(void);
void OpenTestAlarm(void);
void FaultAlarmProc(void);


extern AlARM_TYPEDEF	Alarm;
extern FaultAlarm_typedef FaultAlarm;

#endif

