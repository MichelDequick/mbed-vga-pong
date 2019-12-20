#include <drivers/VGA/programmable_interval_timer.h>

/**
 * Method author: Michel Dequick
 *
 * Enables the correct registers to enable all the PITimers to be set up
 * Read in line commentary for further explanation
 *
 */
extern inline void PIT_init(void)
{
	// Enable clock
	SIM->SCGC6 |= (ENABLE <<  SIM_PIT);

	// Enable PIT Module control unit
	PIT->MCR = 0;	// Enable MCR
}

/**
 * Method author: Michel Dequick
 *
 * The PIT_set method sets the amount of clock cycles before the interrupt should be thrown
 * Read in line commentary for further explanation
 *
 */
extern inline void PIT_set(int n_pit, int timer)
{
	PIT->CHANNEL[n_pit].LDVAL = timer;					// Timer set to 1000 clock cycles (default 60MHz)
}

/**
 * Method author: Michel Dequick
 *
 * Enables a PIT timer, this means it starts counting
 *
 */
extern inline void PIT_enable(int n_pit)
{
	PIT->CHANNEL[n_pit].TCTRL |= ( ENABLE << TEN);		// Enable Timer
}

/**
 * Method author: Michel Dequick
 *
 * Disables a PIT timer, this means it stops counting
 *
 */
extern inline void PIT_disable(int n_pit)
{
	PIT->CHANNEL[n_pit].TCTRL &= ( DISABLE << TEN);		// Disable Timer
}

/**
 * Method author: Michel Dequick
 *
 * Resets the interrupt flag of said timer
 *
 */
extern inline void PIT_reset(int n_pit)
{
	PIT->CHANNEL[n_pit].TFLG = 1; // Clear flag
}

/**
 * Method author: Michel Dequick
 *
 * Sets all register variables to setup a PITimer
 * Read in line commentary for further explanation
 *
 */
extern inline void PIT_setup(int n_pit)
{
	if(n_pit >= 0 && n_pit < 4)
	{
		PIT_disable(n_pit);
		PIT->CHANNEL[n_pit].TCTRL &= ( DISABLE << CHN);		// Disable chained mode
		PIT->CHANNEL[n_pit].TCTRL |= ( ENABLE << TIE);		// Enable Interrupt
		PIT->CHANNEL[n_pit].TFLG = 1; 						// Reset interrupt flag
		NVIC_EnableIRQ(48 + n_pit);							// Enable Interrupt (pit 1 = 48; Pit 2 = 49, Pit 3 = 50, Pit 4 = 51)
		PIT->CHANNEL[n_pit].TFLG = 1; // Clear flag
	}
}
