#ifndef __VALIBRATE_VALUE_H
#define __VALIBRATE_VALUE_H

#include "fm33lf0xx_fl.h"

typedef struct
{
	unsigned char Mode;
	unsigned char Step;
}CalLED_typedef;

void LED_Calibration(void);

extern CalLED_typedef CalLED;

#endif

