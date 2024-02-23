#include "Flash.h"
#include "Calibrate_LED.h"
#include "Window_api.h"

Flash_typedef Flash;

/*
** Flash Function Prco
** Flash struct
*/

void FlashFunctionPrco(void)
{
	uint32_t primask = 0;
	switch(Flash.Step)
	{
		case 0:
			CMU->PCLKCR2 |= FL_CMU_GROUP2_BUSCLK_FLASH;
			CMU->OPCER1 |= FL_CMU_GROUP1_OPCLKEN_FLASH;
			//State = 0 Ò³²Á³ý²Ù×÷;State = 1 Ð´²Ù×÷;
			if(Flash.State == 0)
			{
				FLASH->EPCR |= FLASH_EPCR_ERTYPE_Msk;
				FLASH->EPCR &= ~FLASH_EPCR_PREQ_Msk;
				FLASH->EPCR |=  FLASH_EPCR_EREQ_Msk;
			}
			else
			{
				FLASH->EPCR &= ~FLASH_EPCR_EREQ_Msk;
				FLASH->EPCR |=  FLASH_EPCR_PREQ_Msk;
			}
			primask = __get_PRIMASK();
			__disable_irq();
			if(Flash.State == 0)
			{
				FLASH->KEY |= FL_FLASH_ERASE_KEY;
				FLASH->KEY |= FL_FLASH_PAGE_ERASE_KEY;
				Flash.Step += 3;
			}
			else
			{
				FLASH->KEY |= FL_FLASH_PROGRAM_KEY1;
				FLASH->KEY |= FL_FLASH_PROGRAM_KEY2;
				Flash.Step++;				
			}
			__set_PRIMASK(primask);
			FLASH->ISR |= FLASH_ISR_ERD_Msk + FLASH_ISR_CKERR_Msk + FLASH_ISR_KEYERR_Msk + FLASH_ISR_AUTHERR_Msk;
			break;
		case 1:
			FLASH->EPCR &= ~FLASH_EPCR_EREQ_Msk;
			FLASH->EPCR |=  FLASH_EPCR_PREQ_Msk;
			if(Flash.len == 5)
			{
				*((uint32_t *)FLASH_Version) = LowRom.Version;
			}
			else if(Flash.len == 4)
			{
				*((uint32_t *)FLASH_Day_Time) = LowRom.day_time;
			}
			else if(Flash.len == 3)
			{
				*((uint32_t *)FLASH_HunderdPpm) = LowRom.HunderdPpm;
			}
			else if(Flash.len == 2)
			{
				*((uint32_t *)FLASH_ZeroPpm) = LowRom.ZeroPpm;
			}
			else if(Flash.len == 1)
			{
				*((uint32_t *)FLASH_Count) = LowRom.Count;
			}
			Flash.Step++;
			break;
		case 2:
			if(FLASH->ISR & FLASH_ISR_PRD_Msk)
			{
				FLASH->ISR |= FLASH_ISR_PRD_Msk;
				if(Flash.len > 1)
				{
					Flash.len--;
					Flash.Step--;
				}
				else
				{
					Flash.Step += 3;
				}
			}
			break;
		case 3:
			*((uint32_t *)FLASH_Count) = FL_FLASH_ERASE_REQUEST;
			Flash.Step++;
			break;
		case 4:
			if(FLASH->ISR & FLASH_ISR_ERD_Msk)
			{
				FLASH->ISR |= FLASH_ISR_ERD_Msk;
				Flash.Step++;
			}
			break;
		case 5:
			FLASH->KEY = 0xFFFFFFFF;
			CMU->OPCER1 &= ~FL_CMU_GROUP1_OPCLKEN_FLASH;
			CMU->PCLKCR2 &= ~FL_CMU_GROUP2_BUSCLK_FLASH;
			Flash.Step = 0;
			Flash.len = 0;
			Flash.i = 0;
			Flash.Mode = _idle;
			break;
	}
}


