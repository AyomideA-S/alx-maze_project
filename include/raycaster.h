#ifndef _RAYCASTER_H_
#define _RAYCASTER_H_

/**
 * struct Vector - Typedef for a struct of type Vector
 * @posX: x-coordinate of an object at a starting time
 * @posY: y-coordinate of an object at a starting time
 * @dirX: x-coordinate direction vector of an object at a time
 * @dirY: y-coordinate direction vector  of an object at a time
 * @planeX: x-coordinate of an object on the camera plane at a time
 * @planeY: y-coordinate of an object on the camera plane at a time
 *
 * Description: It is a struct containing all cordinates of an object at a time
 */
typedef struct Vector
{
	int posX;
	int posY;
	int dirX;
	int dirY;
	int planeX;
	int planeY;
} Vector;

/**
 * struct Projection - Typedef for a struct of type Projection
 * @drawStart: The coordinate of the first pixel to be drawn
 * @drawEnd: The coordinate of the last pixel to be drawn
 *
 * Description: It is a struct containing the start and stop cordinates for
 * camera projection.
 */
typedef struct Projection
{
	int drawStart;
	int drawEnd;
} Projection;

void generate_map(Vector object, double rayDirX, double rayDirY,
				double *sideDistX, double *sideDistY, int *stepX, int *stepY,
				int *mapX, int *mapY, double deltaDistX, double deltaDistY,
				ColorRGBA *color, int *side, int *hit);
void calculate_distances(Vector object, double rayDirX, double rayDirY,
						double *sideDistX, double *sideDistY, int *stepX,
						int *stepY, int mapX, int mapY, double deltaDistX,
						double deltaDistY);
Projection calcuate_projection(int side, double sideDistX, double sideDistY,
						double deltaDistX, double deltaDistY,
						double *perpWallDist);

#endif /* _RAYCASTER_H_ */
