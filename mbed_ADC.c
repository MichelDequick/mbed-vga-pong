/*
 * mbed_ADC.c
 *
 *  Created on: 30 okt. 2019
 *      Author: Donovan
 */

#include "mbed_ADC.h"
#include "MK64F12.h"
#include <stdint.h>
#include "enum_ports.h"

void initADC(){
	SIM->SCGC6 |= ADC_CGC;
	ADC0->CFG1 = 0xC;
	ADC0->SC1[0] = 0x1F;
}

uint16_t readPot(enum potentiometer pot){
	ADC0->SC1[0] = pot;
	while(ADC0->SC2 & ADC_SC2_ADACT_MASK);
	while(!(ADC0->SC1[0] & ADC_SC1_COCO_MASK));
	return ADC0->R[0];
}


