/*
 * hardware_init.c
 *
 *  Created on: 20 nov. 2019
 *      Author: Donovan
 */

#include "hardware_init.h"

/**
 * Method author: Donovan
 * The init method will call the initialization methods from the GPIO and ADC driver.
 * By doing this, it will initialize both drivers at once.
 */
void init(){
	initGPIO();
	initADC();
}

/**
 * Method author: Donovan
 * The initPinInputGPIO method will call the configPCR method from the GPIO driver.
 * The configPCR method will get the port and the pin from the parameters of the initPinInputGPIO method.
 * The direction and type will already be filled in, because this method will specifically initialize the
 * pin as a GPIO input. This means that the direction is 0 and the type is GPIO.
 * For example: this can be used to initialize buttons.
 *
 * @param	enum portName port			port of the pin.
 * @param	int pin						pin number.
 */
void initPinInputGPIO(enum portName port, int pin){
	configPCR(port, pin, 0, GPIO);
}

/**
 * Method author: Donovan
 * The initPinOutputGPIO method will call the configPCR method from the GPIO driver.
 * The configPCR method will get the port and the pin from the parameters of the initPinOutputGPIO method.
 * The direction and type will already be filled in, because this method will specifically initialize the
 * pin as a GPIO output. This means that the direction is 1 and the type is GPIO.
 * For example: this can be used to initialize leds.
 *
 * @param	enum portName port			port of the pin.
 * @param	int pin						pin number.
 */
void initPinOutputGPIO(enum portName port, int pin){
	configPCR(port, pin, 1, GPIO);
}

/**
 * Method author: Donovan
 * The initPinInterrupt method will call the configPCR method from the GPIO driver.
 * The configPCR method will get the port and the pin from the parameters of the initPinInterrupt method.
 * The direction and type will already be filled in, because this method will specifically initialize the
 * pin as a interrupt. This means that the direction is 0 and the type is INTERRUPT.
 * For example: this can be used to initialize interrupt buttons.
 *
 * @param	enum portName port			port of the pin.
 * @param	int pin						pin number.
 */
void initPinInterrupt(enum portName port, int pin){
	configPCR(port, pin, 0, INTERRUPT);
}
