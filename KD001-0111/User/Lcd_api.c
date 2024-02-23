#include "Lcd_api.h"


uint32_t dispBuf[10] = {0};

Display_typedef Display;
LCDDisplayChar_typedef DisplayChar;

#define E 		10
#define n 		11
#define Test 	12
#define P1 		13
#define P2 		14
#define P3 		15
#define P4 		16
#define P5 		17
#define P6 		18
#define P9 		19

const unsigned char array[20][4] = 
{
	/*  0 */	0x4, 0x6, 0x2, 0x6,	//0
	/*  1 */	0x0, 0x2, 0x2, 0x0,	//1
	/*  2 */	0x4, 0x4, 0x6, 0x2,	//2
	/*  3 */	0x4, 0x2, 0x6, 0x2,	//3
	/*  4 */	0x0, 0x2, 0x6, 0x4,	//4
	/*  5 */	0x4, 0x2, 0x4, 0x6,	//5
	/*  6 */	0x4, 0x6, 0x4, 0x6,	//6
	/*  7 */	0x0, 0x2, 0x2, 0x2,	//7
	/*  8 */	0x4, 0x6, 0x6, 0x6,	//8
	/*  9 */	0x4, 0x2, 0x6, 0x6,	//9
	/* 10 */	0x4, 0x4, 0x4, 0x6, //E
	/* 11 */	0x0, 0x6, 0x2, 0x6, //n
	/* 12 */	0x0, 0x0, 0x4, 0x0, //-
	/* 13 */	0x1, 0x0, 0x0, 0x0,//p1 ��һλ������28λ
	/* 14 */	0x0, 0x0, 0x1, 0x0,//p2 ����λ������28λ
	/* 15 */	0x0, 0x0, 0x0, 0x1,//p3 ����λ������28λ
	/* 16 */	0x0, 0x1, 0x0, 0x0,//p4 �ڶ�λ������28λ
	/* 17 */	0x2, 0x0, 0x0, 0x0,//p5 ��һλ������28λ
	/* 18 */	0x2, 0x0, 0x0, 0x0,//p6
	/* 19 */	0x8, 0x0, 0x0, 0x0,//P9 ��һλ������28λ
};


void OpenLCD(void)
{
	RMU->APBRSTCR1 &= 0xBFFFFFFF;
	
	CMU->PCLKCR1 |= FL_CMU_GROUP1_BUSCLK_LCD;
	LCD->CR = 0x02008F39;//0x02008A39
	LCD->FCR = 0x40;
	LCD->FLKT = 0xAE00;
	LCD->IER = 0;
	//LCD COM ���ʹ��
	LCD->COMEN = 0xF;
	//LCD SEG ���ʹ�� SEG28-31��0-6
	LCD->SEGEN0 = 0xF000007F;
}

void LCDDisplay(void)
{
		switch(Display.Step)
		{
			case 0:
				OpenLCD();
				//�������ʾ��
				LCD->DATA0 = 0;
				LCD->DATA1 = 0;
				LCD->DATA2 = 0;
				LCD->DATA3 = 0;
				Display.Step++;
				break;
			case 1:
				Display.Lppm = Display.Lppm > 999 ?  999:Display.Lppm;
				Display.Current = (uint16_t)Display.Lppm / 100;	
				//��λ
				LCD->DATA0 |= array[Display.Current][0] << 4;
				LCD->DATA1 |= array[Display.Current][1] << 4;
				LCD->DATA2 |= array[Display.Current][2] << 4;
				LCD->DATA3 |= array[Display.Current][3] << 4;
				//ʮλ
				Display.Current =(uint16_t)(Display.Lppm / 10) % 10;
				LCD->DATA0 |= array[Display.Current][0] << 2;
				LCD->DATA1 |= array[Display.Current][1] << 2;
				LCD->DATA2 |= array[Display.Current][2] << 2;
				LCD->DATA3 |= array[Display.Current][3] << 2;
				Display.Step++;
				break;
			case 2:
				//��λ
				Display.Current = (uint16_t)Display.Lppm % 10;
				LCD->DATA0 |= array[Display.Current][0];
				LCD->DATA1 |= array[Display.Current][1];
				LCD->DATA2 |= array[Display.Current][2];
				LCD->DATA3 |= array[Display.Current][3];
				//��λ(P6)
				LCD->DATA0 |= array[P6][0];
				LCD->DATA1 |= array[P6][1];
				LCD->DATA2 |= array[P6][2];
				LCD->DATA3 |= array[P6][3];
				Display.Step++;
				break;
			case 3:
				if(Display.Bat >= 2.8)
				{
					Display.Step++;
				}
				else if(Display.Bat >= 2.6)
				{
					Display.Step += 2;
				}
				else if(Display.Bat >= 2.4)
				{
					Display.Step += 3;
				}
				else
				{
					Display.Step += 4;
				}
				break;
			case 4:
				LCD->DATA0 |= array[P1][0] << 28;
				LCD->DATA1 |= array[P1][1];
				LCD->DATA2 |= array[P1][2];
				LCD->DATA3 |= array[P1][3];
				Display.Step++;
				break;
			case 5:
				LCD->DATA0 |= array[P2][0];
				LCD->DATA1 |= array[P2][1];
				LCD->DATA2 |= array[P2][2] << 28;
				LCD->DATA3 |= array[P2][3];
				Display.Step++;
				break;
			case 6:
				LCD->DATA0 |= array[P3][0];
				LCD->DATA1 |= array[P3][1];
				LCD->DATA2 |= array[P3][2];
				LCD->DATA3 |= array[P3][3] << 28;
				Display.Step++;
				break;
			case 7:
				LCD->DATA0 |= array[P4][0];
				LCD->DATA1 |= array[P4][1] << 28;
				LCD->DATA2 |= array[P4][2];
				LCD->DATA3 |= array[P4][3];
				Display.Step++;
				break;
			case 8:
				if(Display.Humiture == 0)
				{
					Display.Current = Display.T;
					Display.Hum = Display.T;
					
					//�¶ȵ�λ P5 
					LCD->DATA0 |= array[P5][0] << 28;
					LCD->DATA1 |= array[P5][1];
					LCD->DATA2 |= array[P5][2];
					LCD->DATA3 |= array[P5][3];
				}
				else
				{
					Display.Current = Display.Rh;
					Display.Hum = Display.Rh;
					
					//ʪ�ȵ�λ P9
					LCD->DATA0 |= array[P9][0] << 28;
					LCD->DATA1 |= array[P9][1];
					LCD->DATA2 |= array[P9][2];
					LCD->DATA3 |= array[P9][3];
				}
				Display.Step++;
				break;
			case 9:
				//��ʪ����������
				Display.Hum = (Display.Hum -  Display.Current) >= 0.5 ? Display.Current+1:Display.Current;
				//ʮλ
				Display.Current =(uint16_t)(Display.Hum / 10) % 10;
				LCD->DATA0 |= (((array[Display.Current][0] & 0x2) << 30) + (array[Display.Current][0] >> 2));
				LCD->DATA1 |= (((array[Display.Current][1] & 0x2) << 30) + (array[Display.Current][1] >> 2));
				LCD->DATA2 |= (((array[Display.Current][2] & 0x2) << 30) + (array[Display.Current][2] >> 2));
				LCD->DATA3 |= (((array[Display.Current][3] & 0x2) << 30) + (array[Display.Current][3] >> 2));
				//��λ
				Display.Current = (uint16_t)Display.Hum % 10;
				LCD->DATA0 |= array[Display.Current][0] << 28;
				LCD->DATA1 |= array[Display.Current][1] << 28;
				LCD->DATA2 |= array[Display.Current][2] << 28;
				LCD->DATA3 |= array[Display.Current][3] << 28;
				Display.Mode = _idle;
				Display.Step = 0;
				break;
		}
}


void LCDDisplay_Char(void)
{
	switch(DisplayChar.Step)
	{
		case 0:
			OpenLCD();
			//�������ʾ��
			LCD->DATA0 = 0;
			LCD->DATA1 = 0;
			LCD->DATA2 = 0;
			LCD->DATA3 = 0;
			if(DisplayChar.En == true)
			{
				DisplayChar.Step += 2;
			}
			else
			  DisplayChar.Step++;
			break;
		case 1:
			//��ʾ ---
			for(unsigned char i = 0; i < 3; i++)
			{
				LCD->DATA0 |= (array[Test][0] << (i * 2));
				LCD->DATA1 |= (array[Test][1] << (i * 2));
				LCD->DATA2 |= (array[Test][2] << (i * 2));
				LCD->DATA3 |= (array[Test][3] << (i * 2));
			}
			DisplayChar.Step += 2;
			break;
		case 2:
			//��ʾEN
			LCD->DATA0 |= array[E][0] << 2;
			LCD->DATA1 |= array[E][1] << 2;
			LCD->DATA2 |= array[E][2] << 2;
			LCD->DATA3 |= array[E][3] << 2;
		
			LCD->DATA0 |= array[n][0] << 0;
			LCD->DATA1 |= array[n][1] << 0;
			LCD->DATA2 |= array[n][2] << 0;
			LCD->DATA3 |= array[n][3] << 0;
			DisplayChar.Step++;
			break;
		case 3:
			DisplayChar.Mode = _idle;
			DisplayChar.Step = 0;
			break;
	}
	
}


