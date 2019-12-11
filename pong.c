/*
 * pong.c
 *
 *  Created on: 4 dec. 2019
 *      Author: Donovan
 */
#include "pong.h"
#include "vga_driver/vga_driver.h"

//typedef int screen[FIELD_WIDTH][FIELD_HEIGHT];
//int window[FIELD_WIDTH][FIELD_HEIGHT];
int OldPaddleL = 0;
int OldPaddleR = 0;
int ballx = ((FIELD_WIDTH/2) - 1)*100;
int bally = ((FIELD_HEIGHT/2) - 1)*100;
int dx, dy;
int scoreL, scoreR = 0;
//int ** window;


void initPong(){//int ** screen){
	//window = screen;
	dx = randomStart();
	dy = randomStart()/2;
	for (int y = 0; y < FIELD_HEIGHT; y++){
		for (int x = 0; x < FIELD_WIDTH; x++){
			screen[y][x] = 0;
		}
	}
	drawball(ballx, bally);
	drawPadlleL(readPotentiometer(POT1));
	drawPadlleR(readPotentiometer(POT2));
}

void drawPadlleL(float position_float){
	int position = (int)((FIELD_HEIGHT - PADDLE_HEIGHT)* position_float);
	deletePaddleL();
	for (int y = position; y < PADDLE_HEIGHT + position; y++){
		for (int x = PADDLE_WIDTH; x < 2*PADDLE_WIDTH; x++){
			screen[y][x] = 1;
		}
	}
	OldPaddleL = position;
}

void drawPadlleR(float position_float){
	int position = (int)((FIELD_HEIGHT - PADDLE_HEIGHT) * position_float);
	deletePaddleR();
	for (int y = position; y < PADDLE_HEIGHT + position; y++){
		for (int x = FIELD_WIDTH - 2*PADDLE_WIDTH; x < FIELD_WIDTH - PADDLE_WIDTH; x++){
			screen[y][x] = 1;
		}
	}
	OldPaddleR = position;
}

void drawball(int x_pos, int y_pos){
	x_pos = (x_pos/100);
	y_pos = (y_pos/100);
	deleteBall();
	for (int y = y_pos - 1; y < y_pos + BALL_DIAMETER - 1; y++){
		for (int x = x_pos - 1; x < x_pos + BALL_DIAMETER - 1; x++){
			screen[y][x] = 1;
		}
	}
}

void deletePaddleL(){
	for (int y = OldPaddleL; y < PADDLE_HEIGHT + OldPaddleL; y++){
		for (int x = PADDLE_WIDTH; x < 2*PADDLE_WIDTH; x++){
			screen[y][x] = 0;
		}
	}
}

void deletePaddleR(){
	for (int y = OldPaddleR; y < PADDLE_HEIGHT + OldPaddleR; y++){
		for (int x = FIELD_WIDTH - 2*PADDLE_WIDTH; x < FIELD_WIDTH - PADDLE_WIDTH; x++){
			screen[y][x] = 0;
		}
	}
}

void deleteBall(){
	int x_pos = ((ballx - dx)/100);
	int y_pos = ((bally - dy)/100);
	for (int y = y_pos - 1; y < y_pos + BALL_DIAMETER - 1; y++){
		for (int x = x_pos - 1; x < x_pos + BALL_DIAMETER - 1; x++){
			screen[y][x] = 0;
		}
	}
}

int randomStart(){
	time_t t;
	srand((unsigned) time(&t)); //srand(time(0));
	int random = (rand() + rand()) % 50;
	if (random < 0 ){
		return random - 50;
	} else {
		return random + 50;
	}
}

void calculateNewFrame(){
	drawPadlleL(readPotentiometer(POT1));
	drawPadlleR(readPotentiometer(POT2));
	ballx = ballx + dx;
	bally = bally + dy;
	drawball(ballx, bally);
	detectCollision();
}

void detectCollision(){
	if(bally / 100 < 2){
		dy = -dy;
	}

	if(bally / 100 > FIELD_HEIGHT - BALL_DIAMETER - 2){
		dy = -dy;
	}

	if(ballx / 100 <= (2 * PADDLE_WIDTH + 1)){
		if((bally / 100) > OldPaddleL - BALL_DIAMETER && (bally / 100) < OldPaddleL + PADDLE_HEIGHT){
			dx = -dx;
		} else {
			scoreR++;
			gameRestart();
		}
	}

	if((ballx / 100) > (FIELD_WIDTH - (2 * PADDLE_WIDTH) - BALL_DIAMETER)) {
		if((bally / 100) > OldPaddleR - BALL_DIAMETER && (bally / 100) < OldPaddleR + PADDLE_HEIGHT){
			dx = -dx;
		} else {
			scoreL++;
			gameRestart();
		}
	}
}

void gameRestart(){
	dx = 0;
	dy = 0;
	deleteBall();
	ballx = ((FIELD_WIDTH/2) - 1)*100;
	bally = ((FIELD_HEIGHT/2) - 1)*100;
	dx = -100;//randomStart();
	dy = 50;//randomStart()/2;

}



