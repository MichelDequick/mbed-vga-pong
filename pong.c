/*
 * pong.c
 *
 *  Created on: 4 dec. 2019
 *      Author: Donovan
 */
#include "pong.h"

int window[FIELD_WIDTH][FIELD_HEIGHT];

void initField(){
	for (int y = 0; y <= FIELD_HEIGHT; y++){
		for (int x = 0; x <= FIELD_WIDTH; x++){
			window[x][y] = 0;
		}
	}
}

void printField(){
	for (int y = 0; y <= FIELD_HEIGHT; y++){
		for (int x = 0; x <= FIELD_WIDTH; x++){
			printf("%i", window[x][y]);
		}
		printf("\n");
	}
}

void drawPadlleL(float position_float){
	int position = (int)(FIELD_HEIGHT * position_float);
	for (int y = position; y < PADDLE_HEIGHT + position; y++){
		for (int x = PADDLE_WIDTH; x < 2*PADDLE_WIDTH; x++){
			window[x][y] = 1;
		}
	}
}

void drawPadlleR(float position_float){
	int position = (int)(FIELD_HEIGHT * position_float);
	for (int y = position; y < PADDLE_HEIGHT + position; y++){
		for (int x = FIELD_WIDTH - 2*PADDLE_WIDTH + 1; x <= FIELD_WIDTH - PADDLE_WIDTH; x++){
			window[x][y] = 1;
		}
	}
}

void drawball(int x_pos, int y_pos){
	for (int y = y_pos - 1; y < y_pos + BALL_DIAMETER - 1; y++){
		for (int x = x_pos - 1; x < x_pos + BALL_DIAMETER - 1; x++){
			window[x][y] = 1;
		}
	}
}



