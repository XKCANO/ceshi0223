#ifndef __KEYBOARD_API_H
#define __KEYBOARD_API_H

#include "fm33lf0xx_fl_gpio.h"
#include "Macro_definition.h"
#include "FM33LF0_Timer.h"
#include "Window_api.h"
#include "FM33LF0_Timer.h"
#include "Message_Process.h"
#include "FM33LF0_System.h"


#define TEST_PIN 0x00008000
#define TEST_KEY (READ_BIT(GPIOA->DIN, TEST_PIN) == TEST_PIN)


typedef struct
{
	unsigned char test_value;
	unsigned char State;
}KEY_TYPEDEF;


void ScanTestKeyProcess(void);
void TestKeyUpEvent(void);
void TestKeyDownEvent(void);
void Test_Function(void);


extern  KEY_TYPEDEF Key;

#endif

