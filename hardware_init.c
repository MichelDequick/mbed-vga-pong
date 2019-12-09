/*
 * hardware_init.c
 *
 *  Created on: 20 nov. 2019
 *      Author: Donovan
 */

#include "mbed_ADC.h"
#include "mbed_gpio.h"
#include "enum_ports.h"

void init(){
	initGPIO();
	initADC();
}

//Example: for buttons
void initPinInputGPIO(enum portName port, int pin){
	configPCR(port, pin, 0, GPIO);
}

//Example: Used for leds
void initPinOutputGPIO(enum portName port, int pin){
	configPCR(port, pin, 1, GPIO);
}

//Example: Used for interrupt buttons
void initPinInterrupt(enum portName port, int pin){
	configPCR(port, pin, 0, INTERRUPT);
}
