#include "../include/main.h"

/**
 * main - Entry point
 *
 * Return: 0 (Success)
 */
int main(void)
{
	SDL_Instance instance;
	Vector player;
	double time = 0; /* time of current frame */
	double oldTime = 0; /* time of previous frame */

	player.posX = 22;
	player.posY = 12;
	player.dirX = -1;
	player.dirY = 0;
	player.planeX = 0;
	player.planeY = 0.66;

	if (init_instance(&instance) != 0)
		return (1);
	while ("C is awesome")
	{
		raycaster(player, &time, &oldTime, &instance);
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		draw_something(instance);
		SDL_RenderPresent(instance.renderer);
	}
	return (0);
}
