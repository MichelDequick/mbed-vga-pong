/*
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    mbed_vga_pong.c
 * @brief   Application entry point.
 */
#include "MK64F12.h"
#include "hardware_init.h"
#include "input_control.h"
#include "mbed_gpio.h"
#include "mbed_ADC.h"
#include "pong.h"
#include <stdio.h>
#include <stdint.h>

/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */

int main(void) {
	init();
	//initPinInputGPIO(PORT_C, PTC12);
	initPong();
	ballStart();
	ballMovement();
	ballMovement();
	printField();
	/*initPong();
	printField();*/
	/*drawPadlleL(0.03);
	drawPadlleR(0.05);
	drawball(10, 5);
	drawPadlleL(0);
	drawPadlleR(0);
	drawball(20, 5);
	printField();*/
	/*initPinInterrupt(PORT_C, PTC12);
	while(1){
		if (readButton(PORT_C, PTC12) == 1){
			interrupt();
		}
	}*/
	/*while(1){
		printf("The value is %i \n", readButton(PORT_C, PTC12));
	}*/
	//configPCR(PORT_B, PTB3, 0, GPIO);
	/*while(1){
		printf("Pot1: %i \n", readPot(POT1));
		printf("Pot2: %i \n", readPot(POT2));
	}*/
	return 0;
}
