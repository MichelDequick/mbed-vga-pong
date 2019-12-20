/*
 * hardware_init.h
 *
 *  Created on: 20 nov. 2019
 *      Author: Donovan
 */

#include "drivers/ADC/mbed_ADC.h"
#include "drivers/GPIO/mbed_gpio.h"

#ifndef HARDWARE_INIT_H_
#define HARDWARE_INIT_H_

//////////////////////////// METHODS ////////////////////////////

void init();
void initPinInputGPIO(enum portName port, int pin);
void initPinOutputGPIO(enum portName port, int pin);
void initPinInterrupt(enum portName port, int pin);

#endif /* HARDWARE_INIT_H_ */
