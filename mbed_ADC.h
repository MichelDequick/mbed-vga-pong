/*
 * mbed_ADC.h
 *
 *  Created on: 30 okt. 2019
 *      Author: Donovan
 */

#include <stdint.h>
#include "enum_ports.h"

#ifndef MBED_ADC_H_
#define MBED_ADC_H_

#define ADC_CGC 				0x8000000

void initADC();
uint16_t readPot(enum potentiometer pot);

#endif /* MBED_ADC_H_ */
