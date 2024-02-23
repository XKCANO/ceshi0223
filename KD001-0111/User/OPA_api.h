#ifndef __OPA_API_H
#define __OPA_API_H

#include "fm33lf0xx_fl_opa.h"
#include "Macro_definition.h"
#include "fm33lf0xx_fl_cmu.h"


typedef struct
{
	unsigned char Mode;
	unsigned char Step;
	
}OPAOffset_typedef;

void OPA_Offset(void);

extern OPAOffset_typedef OPAOffset;

#endif

