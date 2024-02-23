#ifndef __FM33LF0_SYSTEM_H
#define __FM33LF0_SYSTEM_H

#include "mf_config.h"
#include "fm33lf0xx_fl.h"

#define	GPIO_PIN0			0
#define	GPIO_PIN1			1
#define	GPIO_PIN2			2
#define	GPIO_PIN3			3
#define	GPIO_PIN4			4
#define	GPIO_PIN5			5
#define	GPIO_PIN6			6
#define	GPIO_PIN7			7
#define	GPIO_PIN8			8
#define	GPIO_PIN9			9
#define	GPIO_PIN10		10
#define	GPIO_PIN11		11
#define	GPIO_PIN12		12
#define	GPIO_PIN13		13
#define	GPIO_PIN14		14
#define	GPIO_PIN15		15
/* --------------------------------------------------------------------------- */
#define	FCR_GPIO_PIN0			0
#define	FCR_GPIO_PIN1			2
#define	FCR_GPIO_PIN2			4
#define	FCR_GPIO_PIN3			6
#define	FCR_GPIO_PIN4			8
#define	FCR_GPIO_PIN5			10
#define	FCR_GPIO_PIN6			12
#define	FCR_GPIO_PIN7			14
#define	FCR_GPIO_PIN8			16
#define	FCR_GPIO_PIN9			18
#define	FCR_GPIO_PIN10		20
#define	FCR_GPIO_PIN11		22
#define	FCR_GPIO_PIN12		24
#define	FCR_GPIO_PIN13		26
#define	FCR_GPIO_PIN14		28
#define	FCR_GPIO_PIN15		30


void SYS_CLOCK_Init(void);
void SYS_GPIO_Init(void);
void ClearSRAM(void);
void GotoDeepSleep(void);
void KEY_GPIO(void);



#endif

