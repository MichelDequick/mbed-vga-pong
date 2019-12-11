/*
 * enum_ports.h
 *
 *  Created on: 20 nov. 2019
 *      Author: Donovan
 */

#ifndef ENUM_PORTS_H_
#define ENUM_PORTS_H_

enum portName {PORT_A,
		   	   PORT_B,
			   PORT_C,
			   PORT_D,
			   PORT_E};

enum portA {PTA1 = 1,
			PTA2 = 2,
			PTA4 = 4};

enum portB {PTB2 = 2,
			PTB3 = 3,
			PTB9 = 9,
			PTB10 = 10,
			PTB11 = 11,
			PTB18 = 18,
			PTB19 = 19,
			PTB20 = 20,
			PTB21 = 21,
			PTB22 = 22,
			PTB23 = 23};

enum portC {PTC0 = 0,
			PTC1 = 1,
			PTC2 = 2,
			PTC3 = 3,
			PTC4 = 4,
			PTC5 = 5,
			PTC6 = 6,
			PTC7 = 7,
			PTC8 = 8,
			PTC9 = 9,
			PTC10 = 10,
			PTC11 = 11,
			PTC12 = 12,
			PTC14 = 14,
			PTC15 = 15,
			PTC16 = 16,
			PTC17 = 17,
			PTC18 = 18};

enum portD {PTD0 = 0,
			PTD1 = 1,
			PTD2 = 2,
			PTD3 = 3,
			PTD4 = 4,
			PTD5 = 5,
			PTD6 = 6,
			PTD7 = 7};

enum portE {PTE1 = 1,
			PTE2 = 2,
			PTE3 = 3,
			PTE4 = 4,
			PTE6 = 6,
			PTE24 = 24,
			PTE25 = 25,
			PTE26 = 26};

enum confType {GPIO = 0x100,
			   INTERRUPT = 0xA0103};

enum potentiometer { POT1 = 0xC,
		   	   	     POT2 = 0xD,
					 POT3 = 0xE};

#endif /* ENUM_PORTS_H_ */
