/*
 * pong.h
 *
 *  Created on: 4 dec. 2019
 *      Author: Donovan
 */

#include <stdio.h>

#ifndef PONG_H_
#define PONG_H_

#define FIELD_WIDTH						80
#define FIELD_HEIGHT					60
#define PADDLE_WIDTH					2
#define PADDLE_HEIGHT					6
#define BALL_DIAMETER					3

void initField();
void printField();
void drawPadlleL(float position_float);
void drawPadlleR(float position_float);
void drawball(int x_pos, int y_pos);

#endif /* PONG_H_ */
