/*
 * input_control.c
 *
 *  Created on: 27 nov. 2019
 *      Author: Donovan
 */

#include "enum_ports.h"
#include "mbed_ADC.h"
#include "mbed_gpio.h"
#include "input_control.h"
#include "MK64F12.h"
#include <stdio.h>

float readPotentiometer(enum potentiometer pot){
	return (float)readPot(pot)/65536;
}

uint8_t readButton(enum portName port, int pin){ //for button port c ptc 12
	return getValueFromPin(port, pin) == 0 ? 0 : 1; //push in = 1, not pushed in = 0
}
