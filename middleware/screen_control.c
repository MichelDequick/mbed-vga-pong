#include <middleware/screen_control.h>

/**
 * Method author: Michel Dequick
 *
 * The enableScreen method calls the needed drivers to enable the screen.
 * In this case, enable the vga driver.
 *
 */
void enableScreen()
{
	setupVGA();
}
