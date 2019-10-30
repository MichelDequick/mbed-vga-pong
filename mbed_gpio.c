/*
 * mbed_gpio2.c
 *
 *  Created on: 9 okt. 2019
 *      Author: Donovan
 */


#include "MK64F12.h"
#include "mbed_gpio.h"

void setClockGating() {
	SIM->SCGC5 |= PORT_A_CGC; //Enable Port A Clock Gate Control
	SIM->SCGC5 |= PORT_B_CGC; //Enable Port B Clock Gate Control
	SIM->SCGC5 |= PORT_C_CGC; //Enable Port C Clock Gate Control
	SIM->SCGC5 |= PORT_D_CGC; //Enable Port D Clock Gate Control
	SIM->SCGC5 |= PORT_E_CGC; //Enable Port E Clock Gate Control
}

void configPCR(enum portName port, int pin, int direction){
	switch(port){
		case PORT_A:
			PORTA->PCR[pin] = 0x100;
			GPIOA->PDDR |= (direction << pin);
			break;
		case PORT_B:
			PORTB->PCR[pin] = 0x100;
			GPIOB->PDDR |= (direction << pin);
			break;
		case PORT_C:
			PORTC->PCR[pin] = 0x100;
			GPIOC->PDDR |= (direction << pin);
			break;
		case PORT_D:
			PORTD->PCR[pin] = 0x100;
			GPIOD->PDDR |= (direction << pin);
			break;
		case PORT_E:
			PORTE->PCR[pin] = 0x100;
			GPIOE->PDDR |= (direction << pin);
			break;
	}
}

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
