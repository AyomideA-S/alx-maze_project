#include "../include/main.h"

/**
 * main - Entry point
 *
 * Return: 0 (Success)
 */
int main(void)
{
	SDL_Instance instance;

	/* Start up SDL and create window */
	if (!initialize_SDL(&instance))
	{
		fprintf(stderr, "Failed to initialize!\n");
	} else
	{
		/* Load media */
		if (!loadMedia(&instance, "resources/images/hello_world.bmp"))
		{
			fprintf(stderr, "Failed to load media!\n");
		} else
		{
			/* Hello world! */
			draw_image(&instance);
			/* Hack to get window to stay up */
			keep_window();
		}
	}
	/* Deallocate surface */
	SDL_FreeSurface(instance.image);
	instance.image = NULL;
	/* Destroy window */
	SDL_DestroyWindow(instance.window);
	instance.window = NULL;
	/* Free resources and Quit SDL subsystems */
	SDL_Quit();

	return (0);
}
