#include "../include/main.h"

/**
 * init_instance - A function to initialize SDL
 *
 * @instance: An SDL instance of type struct SDL_Instance
 * Return: 0 (Success) else 1 (Error)
 */
int init_instance(SDL_Instance *instance)
{
	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Failed to initialize SDL! SDL_Error: %s\n",
				SDL_GetError());
		return (1);
	}
	/* Create a new Window instance */
	instance->window = SDL_CreateWindow("The Maze Project",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
		SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (instance->window == NULL)
	{
		fprintf(stderr, "SDL failed to create Window! SDL_Error: %s\n",
				SDL_GetError());
		SDL_Quit();
		return (1);
	}
	/* Create a new Renderer instance linked to the Window */
	instance->renderer = SDL_CreateRenderer(instance->window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (instance->renderer == NULL)
	{
		SDL_DestroyWindow(instance->window);
		fprintf(stderr, "SDL failed to create Renderer! SDL_Error: %s\n",
				SDL_GetError());
		SDL_Quit();
		return (1);
	}
	return (0);
}

/**
 * draw_something - A basic function to draw a line
 *
 * @instance: An SDL instance of type struct SDL_Instance
 */
void draw_something(SDL_Instance instance)
{
	SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawLine(instance.renderer, 10, 10, 100, 100);
}
