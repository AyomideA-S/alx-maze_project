#include "../include/main.h"

/**
 * draw_something - A basic function to draw a line
 *
 * @instance: An SDL instance of type struct SDL_Instance
 */
void draw_something(SDL_Instance *instance)
{
	SDL_SetRenderDrawColor(instance->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawLine(instance->renderer, 10, 10, 100, 100);
}

/**
 * draw_image - A function to draw an image onto the SDL Screen Surface
 *
 * @instance: An SDL instance of type struct SDL_Instance
 */
void draw_image(SDL_Instance *instance)
{
	/* Apply the image */
	SDL_BlitSurface(instance->image, NULL, instance->screenSurface, NULL);
	/* Update the surface */
	SDL_UpdateWindowSurface(instance->window);
}
