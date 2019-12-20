// READ ME!
// Loop unrolling needed in compiling parameters!
// Project properties -> C/C++ Build -> Settings -> Tool Settings -> Optimization -> Optimization Level -> Optimize more (-O2)

#ifndef VGA_DRIVER_H_
#define VGA_DRIVER_H_

///////////////////// INCLUDES /////////////////////
#include <drivers/VGA/programmable_interval_timer.h>
#include <drivers/VGA/vga_port.h>
#include <middleware/vga_screen.h>
#include "MK64F12.h"


///////////////////// VGA /////////////////////
#define PIX_CLK			25175000
#define NOP asm("nop")

extern int vga_state;
extern int vga_line;
extern int color_enable;

void setupVGA();

#endif /* VGA_DRIVER_H_ */
