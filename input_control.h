/*
 * input_control.h
 *
 *  Created on: 27 nov. 2019
 *      Author: Donovan
 */

#include <stdint.h>
#include "enum_ports.h"

#ifndef INPUT_CONTROL_H_
#define INPUT_CONTROL_H_

float readPotentiometer(enum potentiometer pot);
uint8_t readButton(enum portName port, int pin);
int getToggle();

#endif /* INPUT_CONTROL_H_ */
