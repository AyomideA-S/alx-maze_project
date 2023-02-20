#include "../include/main.h"

/**
 * raycaster - A function to perform raycasting operations.
 *
 * @object: struct of type Vector containing all coordinates of that oject
 * @time: Time of current frame
 * @oldTime: Time of previous frame
 * @instance: struct of type SDL_Instance
 * Return: 0 (Success)
 */
int raycaster(Vector object, double *time, double *oldTime,
			SDL_Instance *instance)
{
	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		/* calculate ray position and direction */
		double cameraX = 2 * x / SCREEN_WIDTH - 1; /* x-coord in camera space */
		double rayDirX = object.dirX + object.planeX * cameraX;
		double rayDirY = object.dirY + object.planeY * cameraX;
		/* length of ray from one x or y-side to next x or y-side */
		double deltaDistX = (rayDirX == 0) ? 1e30 : abs(1 / rayDirX);
		double deltaDistY = (rayDirX == 0) ? 1e30 : abs(1 / rayDirY);
		/* which box of the map we're in */
		int mapX = floor(object.posX);
		int mapY = floor(object.posY);
		/* World map */
		int **worldMap = generate_map(MAP_WIDTH, MAP_HEIGHT);
		/* length of ray from current position to next x or y-side */
		double sideDistX;
		double sideDistY;
		double perpWallDist;
		/* what direction to step in x or y-direction (either +1 or -1) */
		int stepX;
		int stepY;
		int hit = 0; /* was there a wall hit? */
		int side; /* was a NS or a EW wall hit? */
		ColorRGBA color; /* choose wall color */

		calculate_distances(object, rayDirX, rayDirY, &sideDistX, &sideDistY,
						&stepX, &stepY, mapX, mapY, deltaDistX, deltaDistY);
		DDA(&hit, &side, &sideDistX, &sideDistY, deltaDistX, deltaDistY, &mapX,
			&mapY, stepX, stepY, worldMap);
		color_walls(worldMap, mapX, mapY, &color, side);
		Projection pixels = calcuate_projection(side, sideDistX, sideDistY,
							deltaDistX, deltaDistY, &perpWallDist);
		int drawStart = pixels.drawStart;
		int drawEnd = pixels.drawEnd;
		/* draw the pixels of the stripe as a vertical line */
		verLine(x, drawStart, drawEnd, &color, &object);
		fps_count(time, oldTime, &instance, &color);
	}
	return (0);
}

/**
 * calculate_distances - A function to calculate all important coordinates at
 * a given point in time.
 *
 * @object: struct of type Vector containing all coordinates of that oject
 * @rayDirX: Ray position and direction in x-axis
 * @rayDirY: Ray position and direction in y-axis
 * @sideDistX: Length of ray from current position to next position on x-axis
 * @sideDistY: Length of ray from current position to next position on y-axis
 * @stepX: What direction to step in x-axis (either +1 or -1)
 * @stepY: What direction to step in y-axis (either +1 or -1)
 * @mapX: x-coordinate of current box of the map we're in
 * @mapY: y-coordinate of current box of the map we're in
 * @deltaDistX: Length of ray from one point to another on x-axis
 * @deltaDistY: Length of ray from one point to another on y-axis
 */
void calculate_distances(Vector object, double rayDirX, double rayDirY,
						double *sideDistX, double *sideDistY, int *stepX,
						int *stepY, int mapX, int mapY, double deltaDistX,
						double deltaDistY)
{
	/* calculate step and initial sideDist */
	if (rayDirX < 0)
	{
		*stepX = -1;
		*sideDistX = (object.posX - mapX) * deltaDistX;
	} else
	{
		*stepX = 1;
		*sideDistX = (mapX + 1.0 - object.posX) * deltaDistX;
	}

	if (rayDirY < 0)
	{
		*stepY = -1;
		*sideDistY = (object.posY - mapY) * deltaDistY;
	} else
	{
		*stepY = 1;
		*sideDistY = (mapY + 1.0 - object.posY) * deltaDistY;
	}
}

/**
 * DDA - Digital Differential Analysis
 *
 * @hit: Integer value (1 if wall was hit else 0)
 * @side: Side of the wall that was hit (NS or EW)
 * @sideDistX: Length of ray from current position to next position on x-axis
 * @sideDistY: Length of ray from current position to next position on y-axis
 * @deltaDistX: Length of ray from one point to another on x-axis
 * @deltaDistY: Length of ray from one point to another on y-axis
 * @mapX: x-coordinate of current box of the map we're in
 * @mapY: y-coordinate of current box of the map we're in
 * @stepX: What direction to step in x-axis (either +1 or -1)
 * @stepY: What direction to step in y-axis (either +1 or -1)
 * @worldMap: A 2-dimensional array of integer values
 */
void DDA(int *hit, int *side, double *sideDistX, double *sideDistY,
		double deltaDistX, double deltaDistY, int *mapX, int *mapY, int stepX,
		int stepY, int **worldMap)
{
	/* perform DDA */
	while (*hit == 0)
	{
		/* jump to next map square, either in x-axis, or in y-axis*/
		if (*sideDistX < *sideDistY)
		{
			*sideDistX += deltaDistX;
			*mapX += stepX;
			*side = 0;
		} else
		{
			*sideDistY += deltaDistY;
			*mapY += stepY;
			*side = 1;
		}

		/* Check if ray has hit a wall */
		if (worldMap[*mapX][*mapY] > 0)
			*hit = 1;
	}
}

/**
 * calculate_projection - A function that calculates the values necessary for
 * camera projection.
 *
 * @side: Side of the wall that was hit (NS or EW)
 * @sideDistX: Length of ray from current position to next position on x-axis
 * @sideDistY: Length of ray from current position to next position on y-axis
 * @deltaDistX: Length of ray from one point to another on x-axis
 * @deltaDistY: Length of ray from one point to another on y-axis
 * @perpWallDist: Perpendicular distance from ray to wall
 * Return: struct of type Projection
 */
Projection calcuate_projection(int side, double sideDistX, double sideDistY,
						double deltaDistX, double deltaDistY,
						double *perpWallDist)
{
	Projection pixel_coordinates;

	/*
	* Calculate distance projected on camera direction
	* (Euclidean distance would give fisheye effect!)
	*/
	if (side == 0)
		*perpWallDist = (sideDistX - deltaDistX);
	else
		*perpWallDist = (sideDistY - deltaDistY);

	/* Calculate height of line to draw on screen */
	int lineHeight = (int)(SCREEN_HEIGHT / *perpWallDist);

	/* calculate lowest and highest pixel to fill in current stripe */
	int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
	int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;

	if (drawStart < 0)
		drawStart = 0;
	if (drawEnd >= SCREEN_HEIGHT)
		drawEnd = SCREEN_HEIGHT - 1;

	pixel_coordinates.drawStart = drawStart;
	pixel_coordinates.drawEnd = drawEnd;

	return (pixel_coordinates);
}
