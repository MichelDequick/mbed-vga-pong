/*
 * input_control.c
 *
 *  Created on: 27 nov. 2019
 *      Author: Donovan
 */

#include "input_control.h"

/**
 * Method author: Donovan
 * The readPotentiometer method will call the readPot method from the ADC driver.
 * It will calculate a float value of the potentiometers position and return this value.
 *
 * @param	enum potentiometer pot			contains potentiometer hex value.
 * @return									float value of the potentiometers position.
 */
float readPotentiometer(enum potentiometer pot){
	return (float)readPot(pot)/65536;
}

/**
 * Method author: Donovan
 * The readButton method will call the getValueFromPin method from the GPIO driver.
 * It will return a uint8_t value if the button is pushed in or not.
 * If the button is pushed in, it will return a one. (tested on the pong/vga shield)
 * If the button is not pushed in, it will return a zero. (tested on the pong/vga shield)
 *
 * @param	enum portName port			contains potentiometer hex value.
 * @return								uint8_t value (0 or 1).
 */
uint8_t readButton(enum portName port, int pin){
	return getValueFromPin(port, pin) == 0 ? 0 : 1;
}
