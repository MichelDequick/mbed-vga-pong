#include <drivers/VGA/vga_driver.h>






///////////////////// VGA /////////////////////

int vga_line = 0;
int vga_state = 0;
int color_enable = 0;

/**
 * Method author: Michel Dequick
 *
 * The setupVGA method should be called before trying to draw to the screen.
 * It sets up the required ports and timers to insure correct operation of the driver
 *
 * Read in line commentary for further explanation
 */
void setupVGA()
{

	VGA_PORT_init();
	PIT_init();

	PIT_setup(0);
	PIT_set(0, 670);	// Theoretic calculation for timer length (16 * 1/25175000) / (1/60000000)
	PIT_enable(0);

	// Waits on startup screen while getting VGA timer in sync
	for(int i = 0; i < 1000000; i++ ){
					NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP;
		}
}

/**
 * Method author: Michel Dequick
 *
 * The PIT0_IRQHandler method is called after PIT timer 0 has reached its target value.
 * If the timings are correctly configured it should be called at the same frequency
 * as a horizontal line should be drawn on the vga screen. Correct timing is very important here
 * thats why we use NOP's (assembler No OPperation) to emulate one clock cycle
 * The line number is incremented each call so we can keep track of which line to draw or when to enable vertical sync.
 * Current array output is set to 80x60 but could be set at same resolution RGB or increased to 320x280 in black/white
 *
 * Read in line commentary for further explanation
 */
void PIT0_IRQHandler(void)
{

	// FRONT PORCH


	if(vga_line == 479)	// End visible area 480
	{
		color_enable = 0;
	}else{
		NOP;
	}

	if(vga_line == 489)	// Vsync puls 2 lines long starting at line 490
	{
		VSYNC_LOW;
	}else{
		NOP;
	}

	if(vga_line == 491)	// Vsync puls 2 lines long finishing at line 492
	{
		VSYNC_HIGH;
	}else{
		NOP;
	}

	// SYNC PULSE	3.8133068520357 us
	HSYNC_LOW;

	NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP;
	NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP;
	NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP;
	NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP;
	NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP;
	NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP;
	NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP;

	HSYNC_HIGH;


	// Back Porch	1.9066534260179 us
	vga_line++;

	if(vga_line > 524)	// 525 lines per frame
	{
		vga_line = 0;
		color_enable = 1;
	}else{
		NOP; NOP;
	}

	NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP;
	NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP;
	NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP;
	//NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP;
	//NOP; NOP;


	// Video Signal
	if(vga_line < 480){
		int y = vga_line / 8;

		// Manually unrolling this loop seems to be much more efficient
		//for (int x = 0; x < 80; x++){
		//	GPIOD->PDOR = ( screen[y][x] << PIN_BLUE);
		//}

		GPIOD->PDOR = ( screen[y][0] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][1] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][2] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][3] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][4] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][5] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][6] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][7] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][8] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][9] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][10] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][11] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][12] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][13] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][14] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][15] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][16] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][17] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][18] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][19] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][20] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][21] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][22] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][23] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][24] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][25] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][26] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][27] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][28] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][29] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][30] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][31] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][32] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][33] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][34] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][35] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][36] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][37] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][38] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][39] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][40] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][41] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][42] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][43] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][44] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][45] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][46] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][47] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][48] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][49] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][50] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][51] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][52] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][53] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][54] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][55] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][56] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][57] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][58] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][59] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][60] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][61] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][62] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][63] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][64] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][65] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][66] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][67] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][68] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][69] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][70] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][71] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][72] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][73] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][74] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][75] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][76] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][77] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][78] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		GPIOD->PDOR = ( screen[y][79] << PIN_BLUE);
		NOP; NOP; NOP; NOP;
		BLUE_LOW;
	}

	// enable interrupt flag
	PIT_reset(0);
}

