#ifndef _COLORS_H_
#define _COLORS_H_

/**
 * struct ColorRGBA - Typedef for a struct of type Vector
 * @red: The R value of the color
 * @green: The G value of the color
 * @blue: The B value of the color
 * @alpha: A value between 0.0 (fully transparent) and 1.0 (fully opaque)
 *
 * Description: A struct containing the RGBA values of a color.
 */
typedef struct ColorRGBA
{
	int red;
	int green;
	int blue;
	float alpha;
} ColorRGBA;

ColorRGBA rgba_color_code(char *color);
void color_walls(int **worldMap, int mapX, int mapY, ColorRGBA *color,
				int side);
ColorRGBA rgba_color_add(ColorRGBA color1, ColorRGBA color2);
void rgba_add(ColorRGBA *color, int n, float a);
ColorRGBA rgba_color_sub(ColorRGBA color1, ColorRGBA color2);
void rgba_sub(ColorRGBA *color, int n, float a);
ColorRGBA rgba_color_mul(ColorRGBA color1, ColorRGBA color2);
void rgba_mul(ColorRGBA *color, int n, float a);
ColorRGBA rgba_color_div(ColorRGBA color1, ColorRGBA color2);
void rgba_div(ColorRGBA *color, int n, float a);
int rgba_color_comp(ColorRGBA color1, ColorRGBA color2);

#endif /* _COLORS_H_ */
