/*
 * mbed_gpio2.c
 *
 *  Created on: 9 okt. 2019
 *      Author: Donovan
 */


#include "MK64F12.h"
#include "mbed_gpio.h"
#include "enum_ports.h"

int toggle;

int getTog(void) {
	return toggle;
}
void setTog(int v) {
	toggle = v;
}

void initGPIO() {
	SIM->SCGC5 |= PORT_A_CGC; //Enable Port A Clock Gate Control
	SIM->SCGC5 |= PORT_B_CGC; //Enable Port B Clock Gate Control
	SIM->SCGC5 |= PORT_C_CGC; //Enable Port C Clock Gate Control
	SIM->SCGC5 |= PORT_D_CGC; //Enable Port D Clock Gate Control
	SIM->SCGC5 |= PORT_E_CGC; //Enable Port E Clock Gate Control
}

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
			PORTC->ISFR = PORT_ISFR_ISF(0x40);
			NVIC_EnableIRQ(PORTC_IRQn);
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

void PORTC_IRQHandler()
{
	toggle++;
	//NVIC_DisableIRQ(PORTC_IRQn);
	PORTC->ISFR = PORT_ISFR_ISF(0x40);
}


