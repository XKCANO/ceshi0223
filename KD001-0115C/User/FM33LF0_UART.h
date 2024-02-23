#ifndef __FM33LF0_UART_H
#define __FM33LF0_UART_H

#include "fm33lf0xx_fl.h"


typedef struct
{
	unsigned char Step;
	unsigned char Mode;
}Serial0_TYPEDEF;

typedef struct
{
	unsigned char Step;
	unsigned char Mode;
	unsigned char Txbuff[15];
	unsigned char idx;
	unsigned short Count;
	unsigned short Bat;
}Serial0Tx_TYPEDEF;

typedef struct
{
	unsigned char Step;
	unsigned char Mode;
}Serial0Rx_TYPEDEF;



/*
**	Run UART0 Funtion
*/
void RunUART0Proc(void);

/*
**	Open UART0 Service Funtion
*/
void OpenUART0(void);

/*
**	Close UART0 Service Funtion
*/
void CloseUART0(void);

/*
**	Run UART0 Tx Funtion
*/
void RunUART0TxProc(void);

/*
**	Run UART0 Rx Funtion
*/
void RunUART0RxProc(void);

extern Serial0_TYPEDEF Serial0;
extern Serial0Tx_TYPEDEF Serial0Tx;
extern Serial0Rx_TYPEDEF Serial0Rx;

#endif

