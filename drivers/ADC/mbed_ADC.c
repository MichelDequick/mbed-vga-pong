/*
 * mbed_ADC.c
 *
 *  Created on: 30 okt. 2019
 *      Author: Donovan
 */

#include "mbed_ADC.h"

/**
 * Method author: Donovan
 * The initADC method enables the clock gate for the ADC.
 * It sets bit 27 high of the System Clock Gating Control Register 6. This enables ADC0.
 * After enabling the clock gate, the conversion mode resolution is configured to a 16-bit resolution.
 * The last part configures the ADC channel input. For initialization this module will be disabled.
 */
void initADC(){
	SIM->SCGC6 |= ADC_CGC;
	ADC0->CFG1 = 0xC;
	ADC0->SC1[0] = 0x1F;
}

/**
 * Method author: Donovan
 * The readPot method will write to SC1[0] to start conversion by giving it the correct value
 * for the connected potentiometer (in our case).
 * It waits until the conversion is complete and returns the value as a uint16_t.
 *
 * @param	enum potentiometer pot		contains the hex value for the potentiometer.
 * @return								returns the converted value as a uint16_t.
 */
uint16_t readPot(enum potentiometer pot){
	ADC0->SC1[0] = pot;
	while(ADC0->SC2 & ADC_SC2_ADACT_MASK);
	while(!(ADC0->SC1[0] & ADC_SC1_COCO_MASK));
	return ADC0->R[0];
}


