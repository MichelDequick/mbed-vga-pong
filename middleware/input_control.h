/*
 * input_control.h
 *
 *  Created on: 27 nov. 2019
 *      Author: Donovan
 */

#include "drivers/ADC/mbed_ADC.h"
#include "drivers/GPIO/mbed_gpio.h"
#include <stdio.h>
#include <stdint.h>

#ifndef INPUT_CONTROL_H_
#define INPUT_CONTROL_H_

//////////////////////////// METHODS ////////////////////////////

float readPotentiometer(enum potentiometer pot);
uint8_t readButton(enum portName port, int pin);

#endif /* INPUT_CONTROL_H_ */
