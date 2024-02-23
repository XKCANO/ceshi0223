#ifndef __APP_LCD_H
#define __APP_LCD_H

#include <string.h>
#include "Macro_definition.h"
#include "fm33lf0xx_fl_conf.h"
#include "Window_api.h"
#include "Message_Process.h"

#define LCD_BACKLIGHT_ON 	 (GPIOB->DRST |= (1 << GPIO_PIN8))
#define LCD_BACKLIGHT_OFF  (GPIOB->DSET |= (1 << GPIO_PIN8))


/*
**	LCD(PPM、BAT、 T/RH) 结构体
*/
typedef struct
{
	float Bat;
	uint16_t Lppm;
	uint16_t Hppm;
	uint16_t Rh;
	uint16_t T;
	uint16_t Hum;
	
	uint16_t Current;
  unsigned char Step;
  unsigned char Mode;
	bool Humiture;	//温湿度标志位 0：温度 1：湿度
  
}Display_typedef;
/*
**	LCD(En、---) 结构体
*/
typedef struct
{
	bool En;	// 0：--- 、1：En
  unsigned char Step;
  unsigned char Mode;
}LCDDisplayChar_typedef;

/*
**	Open LCD Service Funtion
*/
void OpenLCD(void);

/*
**	Run LCD Display Service Funtion(PPM、BAT、 T/RH)
*/
void LCDDisplay(void);

/*
**	Run LCD Display Char Service Funtion(En、---)
*/
void LCDDisplay_Char(void);

extern Display_typedef Display;
extern LCDDisplayChar_typedef DisplayChar;

#endif
