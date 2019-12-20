#ifndef VGA_DRIVER_VGA_PORT_H_
#define VGA_DRIVER_VGA_PORT_H_

///////////////////// INCLUDES /////////////////////
#include "MK64F12.h"

///////////////////// VGA_PORT /////////////////////
#define PORT_A_CGC 					0x0200
#define PORT_B_CGC 					0x0400
#define PORT_C_CGC 					0x0800
#define PORT_D_CGC 					0x1000
#define PORT_E_CGC 					0x2000

#define PIN_HSYNC 			2
#define PIN_VSYNC 			3
#define PIN_RED				3
#define PIN_GREEN			2
#define PIN_BLUE			0
#define PIN_ENABLE			4

#define OUTPUT				1
#define INPUT				0
#define HIGH				1
#define LOW					0


// In line port control needed for timing tolerances

#define RED_HIGH			GPIOD->PDOR = ( HIGH << PIN_RED)
#define RED_LOW				GPIOD->PDOR = ( LOW << PIN_RED)
#define RED_TOGGLE			GPIOD->PTOR = ( HIGH << PIN_RED)

#define GREEN_HIGH			GPIOD->PDOR = ( HIGH << PIN_GREEN)
#define GREEN_LOW			GPIOD->PDOR = ( LOW << PIN_GREEN)
#define GREEN_TOGGLE		GPIOD->PTOR = ( HIGH << PIN_GREEN)

#define BLUE_HIGH			GPIOD->PDOR = ( HIGH << PIN_BLUE)
#define BLUE_LOW			GPIOD->PDOR = ( LOW << PIN_BLUE)
#define BLUE_TOGGLE			GPIOD->PTOR = ( HIGH << PIN_BLUE)

#define HSYNC_HIGH			GPIOC->PDOR = ( HIGH << PIN_HSYNC)
#define HSYNC_LOW			GPIOC->PDOR = ( LOW << PIN_HSYNC)
#define HSYNC_TOGGLE		GPIOC->PTOR = ( HIGH << PIN_HSYNC)

#define VSYNC_HIGH			GPIOC->PDOR = ( HIGH << PIN_VSYNC)
#define VSYNC_LOW			GPIOC->PDOR = ( LOW << PIN_VSYNC)
#define VSYNC_TOGGLE		GPIOC->PTOR = ( HIGH << PIN_VSYNC)


void VGA_PORT_init(void);

#endif /* VGA_DRIVER_VGA_PORT_H_ */
