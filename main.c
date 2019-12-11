#include "MK64F12.h"
#include "vga_driver/vga_driver.h"
#include "input_control.h"

#include "pong.h"
#include "hardware_init.h"
#include "mbed_gpio.h"

#define NOP asm("nop")

#include <stdio.h>
// Loop unrolling needed!
// Project properties -> C/C++ Build -> Settings -> Tool Settings -> Optimization -> Optimization Level -> Optimize more (-O2)


int main(void) {
	init();
	//initPinInterrupt(PORT_C, PTC12);
	setupVGA();
	for(int i = 0; i < 1000000; i++ ){
				NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP;

	}

	//int ** window = getWindow();
	//screen[2][2] = 1;

	initPong();
	while(1){
		for(int i = 0; i < 10000; i++ ){
			NOP;
		}
		//if(getTog() == 1){
		//	while(getTog() == 1) {
		//		NOP;
		//	}
		//	setTog(0);
		//}
		calculateNewFrame();
	}


	return 0;
}
