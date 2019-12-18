#ifndef PROGRAMMABLE_INTERVAL_TIMER_H_
#define PROGRAMMABLE_INTERVAL_TIMER_H_

#include "MK64F12.h"

///////////////////// PIT /////////////////////
#define ENABLE 			1
#define DISABLE			!ENABLE
#define SIM_PIT			23
#define FRZ				0
#define MDIS			1
#define TEN				0
#define TIE				1
#define CHN				2
#define TIF				0

void initPIT(void);

void setupPIT(int n_pit);

void setPIT(int n_pit, int timer);

void enablePIT(int n_pit);
void disablePIT(int n_pit);


#endif /* PROGRAMMABLE_INTERVAL_TIMER_H_ */
