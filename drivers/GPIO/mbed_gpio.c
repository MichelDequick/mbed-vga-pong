/*
 * mbed_gpio2.c
 *
 *  Created on: 9 okt. 2019
 *      Author: Donovan
 */


#include "mbed_gpio.h"

int toggle;

/**
 * Method author: Donovan
 * The initGPIO method enables the clock gate for every port available.
 * It uses the defines from the mbed_gpio.h file to set the bit for the corresponding port high.
 * Setting the port bit to one --> clock enabled for that port.
 * Setting the port bit to zero --> clock disabled for that port.
 * Corresponding bits for the ports:
 * 		 PORT_A bit = 9;
 * 		 PORT_B bit = 10;
 * 		 PORT_C bit = 11;
 * 		 PORT_D bit = 12;
 * 		 PORT_E bit = 13;
 */

void initGPIO() {
	SIM->SCGC5 |= PORT_A_CGC;
	SIM->SCGC5 |= PORT_B_CGC;
	SIM->SCGC5 |= PORT_C_CGC;
	SIM->SCGC5 |= PORT_D_CGC;
	SIM->SCGC5 |= PORT_E_CGC;
}

/**
 * Method author: Donovan
 * The configPCR method does the configuration of the pin control register.
 * The method can configure a pin for multiple configuration types (pin as interrupt or as GPIO).
 * On basis of the port, it configures the corresponding pin with the given configuration type
 * and sets the direction of the port (only for GPIO pins).
 * If the direction is zero, then the GPIO pin is configured as a general-purpose input.
 * If the direction is one, then the GPIO pin is configured as a general-purpose output.
 * For port_c, when the pin is configured as a interrupt, it enables the interrupt for
 * that port and clears the status flag.
 *
 * @param	enum portName port		This contains the port of the pin.
 * @param   int pin					This contains the pin number.
 * @param	int direction			This contains the value to determine the pins direction (input or output)
 * @param 	enum confType type		this contains the type that the pin needs to be configured as (GPIO or interrupt)
 *
 * The ports, pins and types are predefined in the file enum_ports.h
 */

void configPCR(enum portName port, int pin, int direction, enum confType type){
	switch(port){
		case PORT_A:
			PORTA->PCR[pin] = type;
			GPIOA->PDDR |= (direction << pin);
			break;
		case PORT_B:
			PORTB->PCR[pin] = type;
			GPIOB->PDDR |= (direction << pin);
			break;
		case PORT_C:
			PORTC->PCR[pin] = type;
			GPIOC->PDDR |= (direction << pin);
			if(type == INTERRUPT){
				PORTC->ISFR = PORT_ISFR_ISF(0x40);
				NVIC_EnableIRQ(PORTC_IRQn);
			}
			break;
		case PORT_D:
			PORTD->PCR[pin] = type;
			GPIOD->PDDR |= (direction << pin);
			break;
		case PORT_E:
			PORTE->PCR[pin] = type;
			GPIOE->PDDR |= (direction << pin);
			break;
	}
}

/**
 * Method author: Donovan
 * The setValueOnPin method sets a value on a GPIO pin. This method can only be used for pins set as an output.
 *
 * @param	enum portName port		This contains the port of the pin.
 * @param	int pin					This contains the number of the pin.
 * @param	int value				This contains the value that needs to be placed on the pin.
 *
 * The ports, pins and types are predefined in the file enum_ports.h
 */

void setValueOnPin(enum portName port, int pin, int value){
	switch(port){
		case PORT_A:
			GPIOA->PDOR = (value << pin);
			break;
		case PORT_B:
			GPIOB->PDOR = (value << pin);
			break;
		case PORT_C:
			GPIOC->PDOR = (value << pin);
			break;
		case PORT_D:
			GPIOD->PDOR = (value << pin);
			break;
		case PORT_E:
			GPIOE->PDOR = (value << pin);
			break;
		}
}

/**
 * Method author: Donovan
 * The getValueFromPin method gets a value from a GPIO pin. This method can only be used for pins set as an input.
 *
 * @param	enum portName port		This contains the port of the pin.
 * @param	int pin					This contains the number of the pin.
 * @return							It returns the value from the pin as a uint8_t type.
 *
 * The ports, pins and types are predefined in the file enum_ports.h
 */

uint8_t getValueFromPin(enum portName port, int pin){
	uint8_t retval;

	switch(port){
		case PORT_A:
			retval = ((GPIOA->PDIR & (1 << pin)) != 0);
			break;
		case PORT_B:
			retval = ((GPIOB->PDIR & (1 << pin)) != 0) ;
			break;
		case PORT_C:
			retval = ((GPIOC->PDIR & (1 << pin)) != 0) ;
			break;
		case PORT_D:
			retval = ((GPIOD->PDIR & (1 << pin)) != 0) ;
			break;
		case PORT_E:
			retval = ((GPIOE->PDIR & (1 << pin)) != 0) ;
			break;
	}
	return retval;
}

/**
 * Method author: Donovan
 * The PORTC_IRQHandler method is called when an interrupt has been fired.
 * It increments a integer value and afterwards clears the interrupt flag
 * that was set when the interrupt was fired.
 */

void PORTC_IRQHandler()
{
	toggle++;
	PORTC->ISFR = PORT_ISFR_ISF(0x40);
}

/**
 * Method author: Donovan
 * The getTog method returns an integer value named toggle.
 * It returns the value that was incremented by the interrupt.
 * @return				returns the integer value toggle.
 */

int getTog() {
	return toggle;
}

/**
 * Method author: Donovan
 * The setTog method sets an integer value into the variable named toggle.
 * @param	int value			contains the value to be set in the variable toggle.
 */

void setTog(int value) {
	toggle = value;
}


