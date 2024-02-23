#ifndef __FLASH_H
#define __FLASH_H

#include "fm33lf0xx_fl_flash.h"
#include "fm33lf0xx_fl_cmu.h"
#include "Macro_definition.h"


//flash ¥Ê¥¢µÿ÷∑
#define FLASH_Count        			0x0000F000
#define FLASH_ZeroPpm       		0x0000F004
#define FLASH_HunderdPpm        0x0000F008
#define FLASH_Day_Time 		      0x0000F00C
#define FLASH_Version 		      0x0000F010

typedef struct
{
	unsigned char Mode;
	unsigned char Step;
	unsigned char len;
	unsigned char i;
	unsigned char data[10];
	unsigned char State;

}Flash_typedef;



void FlashFunctionPrco(void);

extern Flash_typedef Flash;

#endif

