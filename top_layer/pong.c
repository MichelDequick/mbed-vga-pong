/*
 * pong.c
 *
 *  Created on: 4 dec. 2019
 *      Author: Donovan
 */
#include "pong.h"
#include "middleware/vga_screen.h"

///////////////////// GLOBAL GAME VARIABLES /////////////////////
int OldPaddleL = 0;
int OldPaddleR = 0;
int ballx = ((FIELD_WIDTH/2) - 1)*100;
int bally = ((FIELD_HEIGHT/2) - 1)*100;
int dx, dy;
int scoreL, scoreR = 0;

///////////////////// METHODS /////////////////////

/**
 * The initPong method will initialize the whole game.
 * It calls the init method and initPinInterrupt from the hardware_init middeleware file.
 * The first method will initizalize all the hardware components and the second will set PORT_C pin 12 as interrupt.
 * Thereafter the game will be loaded, the field will be generated along with the ball and the paddles.
 * By calling the randomStart method, it will generate random values for the x and y direction/speed of the ball,
 * so it gets a random start when the game starts.
 */
void initPong(){
	enableScreen();
	init();
	initPinInterrupt(PORT_C, PTC12);
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

/**
 * The drawPadlleL method will draw the left paddle.
 * First it will calculate it's new position. Before drawing the new paddle position, it deletes the old paddle position
 * by calling the deletePaddleL method, then it will draw the new paddle position. Afterwards it stores the new position
 * in the old position to keep track of where the paddle has been.
 *
 * @param	float position_float		This will contain the current position of the potentiometer
 * 										-> see readPotentiometer method from input_control middleware file.
 */
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

/**
 * The drawPadlleR method will draw the right paddle.
 * First it will calculate it's new position. Before drawing the new paddle position, it deletes the old paddle position
 * by calling the deletePaddleR method, then it will draw the new paddle position. Afterwards it stores the new position
 * in the old position to keep track of where the paddle has been.
 *
 * @param	float position_float		This will contain the current position of the potentiometer
 * 										-> see readPotentiometer method from input_control middleware file.
 */
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

/**
 * The drawball method will draw the ball.
 * First it will calculate it's new x and y position. Before drawing the new ball position, it deletes the old ball position
 * by calling the deleteBall method, then it will draw the new ball position. Afterwards it stores the new position in the
 * old position to keep track of where the ball has been.
 *
 * @param	int x_pos			contains the new x position of the ball.
 * @param	int x_pos			contains the new y position of the ball.
 */
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

/**
 * The deletePaddleL method will delete the left paddle's old position.
 */
void deletePaddleL(){
	for (int y = OldPaddleL; y < PADDLE_HEIGHT + OldPaddleL; y++){
		for (int x = PADDLE_WIDTH; x < 2*PADDLE_WIDTH; x++){
			screen[y][x] = 0;
		}
	}
}

/**
 * The deletePaddleR method will delete the right paddle's old position.
 */
void deletePaddleR(){
	for (int y = OldPaddleR; y < PADDLE_HEIGHT + OldPaddleR; y++){
		for (int x = FIELD_WIDTH - 2*PADDLE_WIDTH; x < FIELD_WIDTH - PADDLE_WIDTH; x++){
			screen[y][x] = 0;
		}
	}
}

/**
 * The deleteBall method will delete the balls old position.
 */
void deleteBall(){
	int x_pos = ((ballx - dx)/100);
	int y_pos = ((bally - dy)/100);
	for (int y = y_pos - 1; y < y_pos + BALL_DIAMETER - 1; y++){
		for (int x = x_pos - 1; x < x_pos + BALL_DIAMETER - 1; x++){
			screen[y][x] = 0;
		}
	}
}

/**
 * The randomStart method will generate a random integer value between -50 and 50.
 * If smaller than 0 -> the value will be subtracted with 50.
 * If bigger than 0 -> the value will be added up with 50.
 * The srand method seeds the randomness with the current time.
 *
 * @return 				integer value betwee -100 and 100.
 */
int randomStart(){
	time_t t;
	srand((unsigned) time(&t));
	int random = (rand() + rand()) % 50;
	if (random < 0 ){
		return random - 50;
	} else {
		return random + 50;
	}
}

/**
 * The calculateNewFrame method will draw the new positions of the paddles and the ball.
 * It will also check if the ball made any collision with the borders of the field or the paddles.
 */
void calculateNewFrame(){
	drawPadlleL(readPotentiometer(POT1));
	drawPadlleR(readPotentiometer(POT2));
	ballx = ballx + dx;
	bally = bally + dy;
	drawball(ballx, bally);
	detectCollision();
}

/**
 * The detectCollision method will check if there has been a collision with the borders of the field or the paddles.
 * The first two if statements checks if there was a collision with the upper or bottom border. If there was a collision,
 * the y direction of the ball will be inverted. The last two if statements will check if there was a collision with the
 * left or right border or if there was a collision with the paddles. If there was a collision with the paddles,
 * the x direction will be in inverted. If the ball hits the left or right border, then the other side gets a point and
 * the game restarts from start position.
 */
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

/**
 *	The gameRestart method will set the game back to it's starting point and will generate a new random start
 *	for the ball. This is not the same as restarting the game from zero, it will keep track of the players scores.
 */
void gameRestart(){
	dx = 0;
	dy = 0;
	deleteBall();
	ballx = ((FIELD_WIDTH/2) - 1)*100;
	bally = ((FIELD_HEIGHT/2) - 1)*100;
	dx = randomStart();
	dy = randomStart()/2;

}

/**
 *	The startPong method runs the game
 */
void startPong(){
	while(1){
			// this defines the physics speed
			for(int i = 0; i < 15000; i++ ){
				asm("nop");
			}
			calculateNewFrame();
		}
}



