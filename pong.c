/*
 * pong.c
 *
 *  Created on: 4 dec. 2019
 *      Author: Donovan
 */
#include "pong.h"

int window[FIELD_WIDTH][FIELD_HEIGHT];
int OldPositionL = 0;
int OldPositionR = 0;
int OldBallx_pos = 39;
int OldBally_pos = 29;
int direction; //based on kwadrant


void initPong(){
	//memset(window, 0x0, sizeof(window));
	for (int y = 0; y <= FIELD_HEIGHT; y++){
		for (int x = 0; x <= FIELD_WIDTH; x++){
			window[x][y] = 0;
		}
	}
	drawball(OldBallx_pos, OldBally_pos);
	drawPadlleL(readPotentiometer(POT1));
	drawPadlleR(readPotentiometer(POT2));
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
	int position = (int)((FIELD_HEIGHT - PADDLE_HEIGHT)* position_float);
	deletePaddleL();
	for (int y = position; y < PADDLE_HEIGHT + position; y++){
		for (int x = PADDLE_WIDTH; x < 2*PADDLE_WIDTH; x++){
			window[x][y] = 1;
		}
	}
	OldPositionL = position;
}

void drawPadlleR(float position_float){
	int position = (int)((FIELD_HEIGHT - PADDLE_HEIGHT) * position_float);
	deletePaddleR();
	for (int y = position; y < PADDLE_HEIGHT + position; y++){
		for (int x = FIELD_WIDTH - 2*PADDLE_WIDTH + 1; x <= FIELD_WIDTH - PADDLE_WIDTH; x++){
			window[x][y] = 1;
		}
	}
	OldPositionR = position;
}

void drawball(int x_pos, int y_pos){
	deleteBall();
	for (int y = y_pos - 1; y < y_pos + BALL_DIAMETER - 1; y++){
		for (int x = x_pos - 1; x < x_pos + BALL_DIAMETER - 1; x++){
			window[x][y] = 1;
		}
	}
	OldBallx_pos = x_pos;
	OldBally_pos = y_pos;
}

void deletePaddleL(){
	for (int y = OldPositionL; y < PADDLE_HEIGHT + OldPositionL; y++){
		for (int x = PADDLE_WIDTH; x < 2*PADDLE_WIDTH; x++){
			window[x][y] = 0;
		}
	}
}

void deletePaddleR(){
	for (int y = OldPositionR; y < PADDLE_HEIGHT + OldPositionR; y++){
		for (int x = FIELD_WIDTH - 2*PADDLE_WIDTH + 1; x <= FIELD_WIDTH - PADDLE_WIDTH; x++){
			window[x][y] = 0;
		}
	}
}

void deleteBall(){
	for (int y = OldBally_pos - 1; y < OldBally_pos + BALL_DIAMETER - 1; y++){
		for (int x = OldBallx_pos - 1; x < OldBallx_pos + BALL_DIAMETER - 1; x++){
			window[x][y] = 0;
		}
	}
}

int randomStart(){
	time_t t;
	srand((unsigned) time(&t));
	return rand() % 101;
}

void ballStart(){
	int randomInt = randomStart();
	printf("%i \n", randomInt);
	if(randomInt <= 25){
		drawball(OldBallx_pos + 1, OldBally_pos - 1); //richting: rechts boven
		direction = 1;								  //kwadrant 1
	} else if(randomInt > 25 && randomInt <= 50){
		drawball(OldBallx_pos - 1, OldBally_pos - 1); //richting: links boven
		direction = 2;								  //kwadrant 2
	} else if(randomInt > 50 && randomInt <= 75){
		drawball(OldBallx_pos - 1, OldBally_pos + 1); //richting: links onder
		direction = 3;								  //kwadrant 3
	} else if(randomInt > 75 && randomInt <= 100){
		drawball(OldBallx_pos + 1, OldBally_pos + 1); //richting rechts onder
		direction = 4;								  //kwadrant 4
	}
}

void ballMovement(){
	switch(direction){
	case 1:
		drawball(OldBallx_pos + 1, OldBally_pos - 1); //richting: rechts boven
		break;
	case 2:
		drawball(OldBallx_pos - 1, OldBally_pos - 1); //richting: links boven
		break;
	case 3:
		drawball(OldBallx_pos - 1, OldBally_pos + 1); //richting: links onder
		break;
	case 4:
		drawball(OldBallx_pos + 1, OldBally_pos + 1); //richting rechts onder
		break;
	}
}



