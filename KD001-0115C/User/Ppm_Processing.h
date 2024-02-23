#ifndef __PPM_PROCESSING_H
#define __PPM_PROCESSING_H

#include "Macro_definition.h"
#include "Lcd_api.h"
#include "Alarm_api.h"

typedef struct
{
	unsigned char Mode;
	unsigned char Step;
	unsigned char Len;
	
	unsigned char Oneidx;
	unsigned char OneCount;
	unsigned char Twoidx;
	unsigned char TwoCount;
	unsigned char Threeidx;
	unsigned char ThreeCount;
	unsigned char Fouridx;
	unsigned char FourCount;
	unsigned char Fiveidx;
	unsigned char FiveCount;
	
	uint32_t OneSum;
	uint32_t TwoSum;
	uint32_t ThreeSum;
	uint32_t FourSum;
	uint32_t FiveSum;
}PPMCOUNTER_typedef;


extern PPMCOUNTER_typedef PpmCount;

#endif

