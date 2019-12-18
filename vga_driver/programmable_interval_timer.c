#include "programmable_interval_timer.h"


extern inline void initPIT(void)
{
	// Enable clock
	SIM->SCGC6 |= (ENABLE <<  SIM_PIT);

	// Enable PIT Module control unit
	PIT->MCR = 0;	// Enable MCR
}

extern inline void setupPIT(int n_pit)
{
	if(n_pit >= 0 && n_pit < 4)
	{
		disablePIT(n_pit);
		PIT->CHANNEL[n_pit].TCTRL &= ( DISABLE << CHN);		// Disable chained mode
		PIT->CHANNEL[n_pit].TCTRL |= ( ENABLE << TIE);		// Enable Interrupt
		PIT->CHANNEL[n_pit].TFLG = 1; 						// Reset interrupt flag
		NVIC_EnableIRQ(47 + n_pit);							// Enable Interrupt (pit 1 = 48; Pit 2 = 49, Pit 3 = 50, Pit 4 = 51)
	}
}

extern inline void setPIT(int n_pit, int timer)
{
	PIT->CHANNEL[n_pit].LDVAL = timer;					// Timer set to 1000 clock cycles (default 60MHz)
}

extern inline void enablePIT(int n_pit)
{
	PIT->CHANNEL[n_pit].TCTRL |= ( ENABLE << TEN);		// Enable Timer
}

extern inline void disablePIT(int n_pit)
{
	PIT->CHANNEL[n_pit].TCTRL &= ( DISABLE << TEN);		// Disable Timer
}
