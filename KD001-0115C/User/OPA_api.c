#include "OPA_api.h"


OPAOffset_typedef OPAOffset;

uint32_t val;

void OPA_Offset(void)
{
	switch(OPAOffset.Step)
	{
		case 0:
			CMU->PCLKCR2 |= FL_CMU_GROUP2_BUSCLK_OPA;
			OPA2->CR &= ~OPA_CR_VPSEL_Msk;
			OPA2->CR |= FL_OPA_INP_SOURCE_INP2;
			OPA2->CALR &= ~OPA_CALR_TRIM_MODE_Msk;
			OPA2->CALR |= FL_OPA_TRIM_MODE_AUTO;
			OPA2->CALR |= OPA_CALR_NCAL_EN_Msk;
			OPA2->CR |= OPA_CR_EN_Msk;
			OPAOffset.Step++;
			break;
		case 1:
			if(OPA2->COR & 0x1)
			{
				val = 0x00;
				OPAOffset.Step++;
			}
			else
			{
				val = 0x20;
				OPAOffset.Step += 3;
			}
			break;
		case 2:
			OPA2->CALR &= ~(0xFF << 16);
			OPA2->CALR = val << 16;
			val++;
			OPAOffset.Step++;
			break;
		case 3:
			if((OPA2->COR & 0x1) == 0)
			{
				OPAOffset.Step += 3;
			}
			else
			{
				OPAOffset.Step--;
			}
			break;
		case 4:
			OPA2->CALR &= ~(0xFF << 16);
			OPA2->CALR = val << 16;
			val++;
			OPAOffset.Step++;
			break;
		case 5:
			if((OPA2->COR & 0x1) == 1)
			{
				OPAOffset.Step++;
			}
			else
			{
				OPAOffset.Step--;
			}
			break;
		case 6:
			if(OPA2->CALR & OPA_CALR_PCAL_EN_Msk)
			{
				OPA2->CALR &= ~OPA_CALR_PCAL_EN_Msk;
				OPA2->CR &= ~OPA_CR_EN_Msk;
				OPAOffset.Step = 0;
				OPAOffset.Mode = _idle;
			}
			else
			{
				OPA2->CALR &= ~OPA_CALR_NCAL_EN_Msk;
				OPA2->CR &= ~OPA_CR_EN_Msk;
				OPAOffset.Step++;
			}
			break;
		case 7:
			OPA2->CALR |= OPA_CALR_PCAL_EN_Msk;
			OPA2->CR |= OPA_CR_EN_Msk;
			OPAOffset.Step = 1;
			break;
	}
}

