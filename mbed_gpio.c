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

void configPCR(int port, int pin, int direction){
	if(port == 0){
		PORTA->PCR[pin] = 0x100;
		GPIOA->PDDR |= (direction << pin);
	} else if(port == 1){
		PORTB->PCR[pin] = 0x100;
		GPIOB->PDDR |= (direction << pin);
	} else if(port == 2){
		PORTC->PCR[pin] = 0x100;
		GPIOC->PDDR |= (direction << pin);
	} else if(port == 3){
		PORTD->PCR[pin] = 0x100;
		GPIOD->PDDR |= (direction << pin);
	} else if(port == 4){
		PORTE->PCR[pin] = 0x100;
		GPIOE->PDDR |= (direction << pin);
	}
}
