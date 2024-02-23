#ifndef __BATTERY_H
#define __BATTERY_H

#include "Window_api.h"
#include "Macro_definition.h"
/**********************************************************/

#define BATOUT_ON			  (GPIOC->DSET |= (1 << GPIO_PIN8))
#define BATOUT_OFF 			(GPIOC->DRST |= (1 << GPIO_PIN8))

#define ADC_TIMER  Timer.t[3]
/**********************************************************/
/*
**结构体
*/
typedef struct
{
	//ADC上电校准
	uint16_t ACQ0_Data;
	uint16_t ACQ1_Data;
	char CalStep;
	char CalFlag;
	char CalState;
	
	uint16_t Bat;
	char BatState;

 	uint16_t Lppm[3]; 
	char LppmState;
  
  uint16_t Hppm[3];  
  char HppmState;
	
	char DCState;
	char DCStep;
	uint16_t VAREF;
	
	char Step;
	char GatherMode;
	
}ADC_TYPEDEF;




void RunADC_GatherProc(void);
void ADC_Calibration(void);
void RunADC_BatteryProc(void);
void RunADC_LppmGetProc(void);
void RunEle_DischargeProc(void);


/**********************************************************/
extern ADC_TYPEDEF ADC_struct;
/**********************************************************/

#endif

