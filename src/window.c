#include "../include/main.h"

/**
 * initialize_SDL - A function to initialize SDL
 *
 * @instance: An SDL instance of type struct SDL_Instance
 * Return: Boolean success flag (true or flase)
 */
bool initialize_SDL(SDL_Instance *instance)
{
	/* Initialization flag */
	bool success = true;
	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Failed to initialize SDL! SDL_Error: %s\n",
				SDL_GetError());
				success = false;
	} else
	{
		/* Create window */
		instance->window = SDL_CreateWindow("The Maze Project",
							SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
							SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (instance->window == NULL)
		{
			fprintf(stderr, "SDL failed to create Window! SDL_Error: %s\n",
					SDL_GetError());
			success = false;
		} else
		{
			/* Get window surface */
			instance->screenSurface = SDL_GetWindowSurface(instance->window);
			/* Color the screen surface */
			colorFill(instance, "black");
		}
	}
	return (success);
}

/**
 * keep_window - A function to keep the SDL window open.
 */
void keep_window(void)
{
	SDL_Event event;
	bool quit = false;

	while (quit == false)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			quit = true;
		}
	}
}

/**
 * colorFill - A function to fill an SDL Screen Surface with a specified color
 *
 * @instance: An SDL instance of type struct SDL_Instance
 * @color_name: The name of the color as a string
 */
void colorFill(SDL_Instance *instance, char *color_name)
{
	/* Retrieve a color */
	ColorRGBA fill_color = rgba_color_code(color_name);
	/* Fill the surface with color */
	SDL_FillRect(instance->screenSurface, NULL,
				SDL_MapRGBA(instance->screenSurface->format,
				fill_color.red, fill_color.green, fill_color.blue,
				255 * fill_color.alpha));
	/* Update the surface */
	SDL_UpdateWindowSurface(instance->window);
}

/**
 * loadMedia - A function to load media into an SDL_Surface.
 *
 * @instance: An SDL instance of type struct SDL_Instance
 * @media_path: The relative path to the media
 * Return: Boolean success flag (true or flase)
 */
bool loadMedia(SDL_Instance *instance, char *media_path)
{
	/* Loading success flag */
	bool success = true;

	/* Load splash image */
	instance->image = SDL_LoadBMP(media_path);
	if (instance->image == NULL)
	{
		fprintf(stderr, "Unable to load image %s! SDL Error: %s\n", media_path,
				SDL_GetError());
		success = false;
	}

	return (success);
}
