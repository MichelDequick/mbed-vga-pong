/*
 * mbed_gpio.h
 *
 *  Created on: 9 okt. 2019
 *      Author: Donovan
 */

#include <stdint.h>
#include "drivers/enum_ports.h"
#include "MK64F12.h"

#ifndef MBED_GPIO_H_
#define MBED_GPIO_H_

///////////////////// DEFINES FOR CLOCK GATE CONTROL (hex values) /////////////////////
#define PORT_A_CGC 					0x0200
#define PORT_B_CGC 					0x0400
#define PORT_C_CGC 					0x0800
#define PORT_D_CGC 					0x1000
#define PORT_E_CGC 					0x2000

///////////////////// METHODS /////////////////////
void initGPIO();
void configPCR(enum portName port, int pin, int direction, enum confType type);
void setValueOnPin(enum portName port, int pin, int value);
uint8_t getValueFromPin(enum portName port, int pin);
void PORTC_IRQHandler();
int getTog();
void setTog(int value);

#endif /* MBED_GPIO_H_ */
