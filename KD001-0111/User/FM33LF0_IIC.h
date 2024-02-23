#ifndef __FM33LF0_IIC_H
#define __FM33LF0_IIC_H

#include "fm33lf0xx_fl.h"
#include <string.h>
#include "Window_api.h"


#define AHT21_POWER_ON  (GPIOC->DSET |= (1 << GPIO_PIN10))
#define AHT21_POWER_OFF (GPIOC->DRST |= (1 << GPIO_PIN10))

#define AHT_TIMER  Timer.t[2]
#define STEP_END 16

typedef struct
{
	unsigned char counter;
	unsigned char step;
	unsigned char mode;
}AHT21_TypeDef;


#define IIC_BUFFER_SIZE 11
/*
**	IIC ½á¹¹Ìå
*/
typedef struct
{
  uint32_t RH;
  uint32_t Temp;
  uint32_t CrcResult;
	
	unsigned char buffer[IIC_BUFFER_SIZE];
	
	unsigned char total;
	unsigned char pos;
	unsigned char flag;
	
	unsigned char step;
	unsigned char mode;
}IIC_TYPEDEF;

/*
**	Run AHT21 Funtion
*/
void RunAHT21Proc(void);

/*
**	Open IIC Service Funtion
*/
void OpenIIC(void);

/*
**	Close IIC Service Funtion
*/
void CloseIIC(void);

/*
**	Run IIC Service Funtion
*/
void RunIICServerProc(void);





extern IIC_TYPEDEF I2C;
extern AHT21_TypeDef AHT;

#endif
