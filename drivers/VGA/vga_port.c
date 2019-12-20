#include <drivers/VGA/vga_port.h>

/**
 * Method author: Michel Dequick
 *
 * Enables and configures all needed GPIO pins for the VGA port
 * Read in line commentary for further explanation
 *
 */
extern inline void VGA_PORT_init(void)
{
	// Enable Port C Clock Gate Control
	SIM->SCGC5 |= PORT_C_CGC;

	// Enable pins Port C
	PORTC->PCR[PIN_HSYNC] = 0x100;
	PORTC->PCR[PIN_VSYNC] = 0x100;
	PORTC->PCR[PIN_ENABLE] = 0x100;

	// Set pins as output
	GPIOC->PDDR |= (OUTPUT << PIN_HSYNC);
	GPIOC->PDDR |= (OUTPUT << PIN_VSYNC);
	GPIOC->PDDR |= (OUTPUT << PIN_ENABLE);


	// Enable Port D Clock Gate Control
	SIM->SCGC5 |= PORT_D_CGC;

	// Enable pins Port D
	PORTD->PCR[PIN_RED] = 0x100;
	PORTD->PCR[PIN_GREEN] = 0x100;
	PORTD->PCR[PIN_BLUE] = 0x100;

	// Set pins as output
	GPIOD->PDDR |= (OUTPUT << PIN_RED);
	GPIOD->PDDR |= (OUTPUT << PIN_GREEN);
	GPIOD->PDDR |= (OUTPUT << PIN_BLUE);

	// Enable LVL shifter
	//GPIOC->PDOR |= ( HIGH << PIN_ENABLE);

	// Set HSync and VSync to HIGH
	GPIOC->PDOR |= ( HIGH << PIN_HSYNC);
	GPIOC->PDOR |= ( HIGH << PIN_VSYNC);

	// Colors to low
	GPIOD->PDOR |= ( LOW << PIN_RED);
	GPIOD->PDOR |= ( LOW << PIN_BLUE);
	GPIOD->PDOR |= ( HIGH << PIN_GREEN);
}
