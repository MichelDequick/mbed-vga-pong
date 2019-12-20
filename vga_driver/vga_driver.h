#ifndef VGA_DRIVER_H_
#define VGA_DRIVER_H_

///////////////////// INCLUDES /////////////////////
#include "MK64F12.h"

// DEBUG
#include "middleware/hardware_init.h"
#include "middleware/input_control.h"
#include "drivers/enum_ports.h"
#include <stdio.h>


///////////////////// GPIO /////////////////////
#define PORT_A_CGC 					0x0200
#define PORT_B_CGC 					0x0400
#define PORT_C_CGC 					0x0800
#define PORT_D_CGC 					0x1000
#define PORT_E_CGC 					0x2000

#define PIN_HSYNC 			2
#define PIN_VSYNC 			3
#define PIN_RED				3
#define PIN_GREEN			2
#define PIN_BLUE			0
#define PIN_ENABLE			4

#define OUTPUT				1
#define INPUT				0
#define HIGH				1
#define LOW					0


///////////////////// PIT /////////////////////
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


///////////////////// VGA /////////////////////

#define WINDOW_HIGHT		60
#define WINDOW_WIDTH		80

#define PIX_CLK			25175000
#define NOP asm("nop")

extern int vga_state;
extern int vga_line;
extern int color_enable;

typedef int* frame;
//int window[WINDOW_HIGHT][WINDOW_WIDTH];
//int ** screen;

extern int screen[WINDOW_HIGHT][WINDOW_WIDTH];


void setupVGA();
int ** getWindow();

#endif /* VGA_DRIVER_H_ */
