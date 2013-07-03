#include <avr/io.h>
#include <util/delay.h>
#define DATAPIN 9
#define FANSTARTLEVEL 68
#define FANSTOPLEVEL 66

#ifndef F_CPU
#warning "F_CPU war noch nicht definiert, wird nun mit 3686400 definiert"
#define F_CPU 3686400UL     /* Quarz mit 3.6864 Mhz */
#endif

short GetCurrentHumidityLevel() 
{
	//assert(!"The method or operation is not implemented.");
	return 59;
}

int SwitchFanState( int fanRunning ) 
{
	if(fanRunning == 0 )
	{
		fanRunning = 1;
	}
	else	
	{
		fanRunning = 0;
	}
	return fanRunning;
	
	//assert(!"The method or operation is not implemented.");
}

int main(void)
{
	int fanRunning = 0;
	
	while(1)
	{
		short currentHumidityLevel = GetCurrentHumidityLevel();
		if(fanRunning && currentHumidityLevel <= FANSTOPLEVEL)
		{
			fanRunning = SwitchFanState(fanRunning);
		}
		else if(!fanRunning && currentHumidityLevel >= FANSTARTLEVEL)
		{
			fanRunning = SwitchFanState(fanRunning);
		}
		_delay_ms(5000);		
	}
}