/*
 * pong.h
 *
 *  Created on: 4 dec. 2019
 *      Author: Donovan
 */

#include <stdlib.h>
#include <stdio.h>
#include "input_control.h"

#ifndef PONG_H_
#define PONG_H_

#define FIELD_WIDTH						80
#define FIELD_HEIGHT					60
#define PADDLE_WIDTH					3
#define PADDLE_HEIGHT					8
#define BALL_DIAMETER					3

//typedef int screen[FIELD_WIDTH][FIELD_HEIGHT];

void initPong();//int ** window);
void printField();
void drawPadlleL(float position_float);
void drawPadlleR(float position_float);
void drawball(int x_pos, int y_pos);
void deletePaddleR();
void deletePaddleL();
void deleteBall();
int randomStart();
void calculateNewFrame();
void detectCollision();
void gameRestart();
#endif /* PONG_H_ */
