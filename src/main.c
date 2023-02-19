#include "../include/main.h"

/**
 * main - Entry point
 *
 * Return: 0 (Success)
 */
int main(void)
{
	SDL_Instance instance;

	if (init_instance(&instance) != 0)
		return (1);
	while ("C is awesome")
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		draw_something(instance);
		SDL_RenderPresent(instance.renderer);
	}
	return (0);
}
