#include "includes/cube3d.h"

void line_dda(t_img *img, t_map *map, t_vect pt1, t_vect pt2)
{
    t_vect	pt1c;
	t_vect	pt2c;
	pt1c = pt1;
	pt2c = pt2;
	if (pt1.x < 0 && pt1.y < 0 && pt2.x < 0 && pt2.y < 0)
		return ;
	if (pt1.x > WIN_WIDTH && pt1.y > WIN_HEIGHT && pt2.x > WIN_WIDTH && pt2.y > WIN_HEIGHT)
		return ;
	//point_clip(&pt1c, &pt2c);
    int dx = pt2c.x - pt1c.x;
    int dy = pt2c.y - pt1c.y;
    float steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / steps;
    float Yinc = dy / steps;
    float X = pt1c.x;
    float Y = pt1c.y;
    double p;
    for (int i = 0; i <= steps; i++)
    {
        if (dy > dx)
            p = percent(pt1c.y, pt2c.y, Y);
        else
            p = percent(pt1c.x, pt2c.x, X);
		umlx_putpixel(img, X, Y, test(pt1.color, pt2.color, p));
        X += Xinc;
        Y += Yinc;
    }
}
void	bresen(t_mlx_img *img, t_map *map, t_data pt1, t_data pt2)
{
	int dx = abs(pt2.x - pt1.x);
	int sx = pt1.x  < pt2.x ? 1 : -1;
	int dy = abs(pt2.y - pt1.y);
	int sy = pt1.y < pt2.y ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2;
	int e2;
	int x;
	int y;
	x = pt1.x;
	y = pt1.y;
	while (1)
	{
		umlx_putpixel(img, x, y, pt1.color);
		if (x == pt2.x && y == pt2.y)
			break;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y += sy;
		}
	}
}