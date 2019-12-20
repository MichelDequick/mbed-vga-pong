#ifndef PROGRAMMABLE_INTERVAL_TIMER_H_
#define PROGRAMMABLE_INTERVAL_TIMER_H_

#include "MK64F12.h"

#define ENABLE 			1
#define DISABLE			~ENABLE
#define SIM_PIT			23
#define FRZ				0
#define MDIS			1
#define TEN				0
#define TIE				1
#define CHN				2
#define TIF				0

#define PIT_CLK			60000000

void PIT_init(void);
void PIT_setup(int n_pit);
void PIT_set(int n_pit, int timer);
void PIT_enable(int n_pit);
void PIT_disable(int n_pit);
void PIT_reset(int n_pit);


#endif /* PROGRAMMABLE_INTERVAL_TIMER_H_ */
