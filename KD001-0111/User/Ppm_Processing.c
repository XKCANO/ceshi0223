#include "Ppm_Processing.h"

PPMCOUNTER_typedef PpmCount;


void PpmCountProc(void)
{
	switch(PpmCount.Step)
	{
		case 0:
			if(Display.Lppm < 15)
			{
				PpmCount.OneCount = 0;
				PpmCount.TwoCount = 0;
				PpmCount.ThreeCount = 0;
				PpmCount.FourCount = 0;
				PpmCount.FiveCount = 0;
				Alarm.WarnState = 0;
				if(Alarm.AlarmMode & _exe)
				{
					Alarm.AlarmMode = _idle;
				}
			}
			else if(Display.Lppm < 24)
			{
				PpmCount.OneCount++;
			}
			else if(Display.Lppm < 50)
			{
				PpmCount.TwoCount++;
			}
			else if(Display.Lppm < 100)
			{
				PpmCount.ThreeCount++;
			}
			else if(Display.Lppm < 300)
			{
				PpmCount.FourCount++;
			}
			else
			{
				PpmCount.FiveCount++;
			}
			PpmCount.Oneidx++;
			PpmCount.Twoidx++;
			PpmCount.Threeidx++;
			PpmCount.Fouridx++;
			PpmCount.Fiveidx++;
			PpmCount.Step++;
			break;
		case 1:
			if(PpmCount.Fiveidx > 1 && PpmCount.FiveCount > 1)
			{
				//±¨¾¯
				Alarm.AlarmMode = _exe;
				PpmCount.FiveCount = 0;
				PpmCount.Fiveidx = 0;
			}
			if(PpmCount.Fouridx > 29 && PpmCount.FourCount > 29)
			{
				Alarm.AlarmMode = _exe;
				PpmCount.FourCount = 0;
				PpmCount.Fouridx = 0;
			}
			if(PpmCount.Threeidx > 89 && PpmCount.ThreeCount > 89)
			{
				Alarm.AlarmMode = _exe;
				PpmCount.ThreeCount = 0;
				PpmCount.Threeidx = 0;
			}
			if(PpmCount.Twoidx > 17 && PpmCount.TwoCount > 17)
			{
				Alarm.WarnMode = _exe;
				Lptimer.WarnCount = 0;
				PpmCount.TwoCount = 0;
				PpmCount.Twoidx = 0;
			}
			if(PpmCount.Oneidx > 35 && PpmCount.OneCount > 35)
			{
				Alarm.WarnMode = _exe;
				Lptimer.WarnCount = 0;
				PpmCount.OneCount = 0;
				PpmCount.Oneidx = 0;
			}
			//½áÊø
			PpmCount.Mode = _idle;
			PpmCount.Step = 0;
			break;
	}
}


