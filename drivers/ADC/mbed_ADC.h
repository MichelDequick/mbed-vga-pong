/*
 * mbed_ADC.h
 *
 *  Created on: 30 okt. 2019
 *      Author: Donovan
 */

#include <stdint.h>
#include "drivers/enum_ports.h"
#include "MK64F12.h"


#ifndef MBED_ADC_H_
#define MBED_ADC_H_

///////////////////// DEFINE FOR CLOCK GATE CONTROL (hex value) /////////////////////
#define ADC_CGC 				0x8000000

///////////////////// METHODS /////////////////////
void initADC();
uint16_t readPot(enum potentiometer pot);

#endif /* MBED_ADC_H_ */
