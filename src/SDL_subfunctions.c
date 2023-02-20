#include "../include/main.h"

/**
 * getTicks - A function that returns the time in milliseconds
 * since the program started.
 *
 * Return: unsigned long value of the time in milliseconds
 */
unsigned long getTicks(void)
{
	return (SDL_GetTicks());
}

/**
 * redraw - A function that updates the screen. Has to be called to view new
 * pixels, but use only after drawing the whole screen because it's slow.
 *
 * @scr: An SDL_Surface
 */
void redraw(SDL_Surface *scr)
{
	SDL_UpdateRect(scr, 0, 0, 0, 0);
	/**
	 * this could potentially be faster than SDL_UpdateRect
	 * if double buffering is used
	 */
	/* SDL_Flip(scr); */
}

/**
 * cls - A function that clears the screen to black
 *
 * @scr: An SDL_Surface
 * @color: struct of type ColorRGBA containing the RGBA value of given color
 */
void cls(SDL_Surface *scr, ColorRGBA *color)
{
	SDL_FillRect(scr, NULL,
				65536 * color->red + 256 * color->green + color->blue);
}
