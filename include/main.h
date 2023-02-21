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

int init_instance(SDL_Instance *instance);
int raycaster(Vector object, double *time, double *oldTime,
			SDL_Instance *instance);
void DDA(int *hit, int *side, double *sideDistX, double *sideDistY,
		double deltaDistX, double deltaDistY, int *mapX, int *mapY, int stepX,
		int stepY, int (*worldMap)[MAP_WIDTH]);
void draw_something(SDL_Instance instance);
int verLine(int x, int y1, int y2, ColorRGBA *color, SDL_Instance *instance);
int fps_count(double *time, double *oldTime);
unsigned long getTicks(void);

/**
 * color_walls - Assigns a color code to each integer case
 *
 * @worldMap: A 2-dimensional array of integer values
 * @mapX: x-coordinate of current box of the map we're in
 * @mapY: y-coordinate of current box of the map we're in
 * @color: struct of type ColorRGBA containing the RGBA value of given color
 * @side: Side of the wall that was hit (NS or EW)
 */
void color_walls(int (*worldMap)[MAP_WIDTH], int mapX, int mapY,
				ColorRGBA *color, int side);

#endif /*_MAIN_H_*/
