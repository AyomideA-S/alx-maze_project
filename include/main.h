#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <SDL2/SDL.h>
#include "applied_math.h"
#include "colors.h"
#include "raycaster.h"

/* Dimensional constants */
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAP_HEIGHT 24
#define MAP_WIDTH 24
#define BLOCK_HEIGHT 64
#define PLAYER_HEIGHT 32
#define FOV 66

/**
 * struct SDL_Instance - Typedef for struct of type SDL_Instance
 * @window: SDL Window
 * @renderer: SDL Renderer
 * @screenSurface: SDL Screen Surface
 *
 * Description: A struct for the SDL_Instance.
 */
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Surface *screenSurface;
} SDL_Instance;

int init_instance(SDL_Instance *);
int raycaster(Vector object, double *time, double *oldTime,
			SDL_Instance *instance);
void draw_something(SDL_Instance);

#endif /*_MAIN_H_*/
