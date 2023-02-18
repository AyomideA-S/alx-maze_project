#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <SDL2/SDL.h>

/**
 * struct SDL_Instance - Typedef for struct of type SDL_Instance
 * @window: SDL Window
 * @renderer: SDL Renderer
 *
 * Description: A struct for the SDL_Instance.
 */
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

int init_instance(SDL_Instance *);

#endif /*_MAIN_H_*/
