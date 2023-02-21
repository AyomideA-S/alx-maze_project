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
