/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_textures.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/18 15:56:48 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 14:45:57 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	draw_wall_hz_hit(t_rays r, t_map *map, t_img img, t_mlx *mlx, int x)
{
	int y;
	double bottom;
	double top;
	double offset_x;
	double	offset_y;

	offset_x = (r.wall.hz_hit.x - (int)r.wall.hz_hit.x) * map->north.width;
	offset_x = ft_abs(offset_x);
	top = map->r_height / 2 - map->r_height / r.distance / 2;;
	bottom = map->r_height / 2 + map->r_height / r.distance / 2;
	y = top;
	while (y < bottom)
	{
		offset_y = (y - top) * ((double)map->north.height / (bottom - top));
		ft_pixel_put(mlx, x, y, ft_pixel_get_color(img, offset_x, offset_y));
		y++;
	}
	return (True);
}

t_bool	 draw_wall_vt_hit(t_rays r, t_map *map, t_img img, t_mlx *mlx, int x)
{
	int y;
	double	bottom;
	double	top;
	double 	offset_x;
	double	offset_y;

	offset_x = ((r.wall.vt_hit.y - (int)r.wall.vt_hit.y) * map->east.width);
	while ((offset_x = ft_abs(offset_x)) > map->east.width)
		offset_x = map->east.height - offset_x;
	top = map->r_height / 2 - map->r_height / r.distance / 2;;
	bottom = map->r_height / 2 + map->r_height / r.distance / 2;
	y = top;
	while (y < bottom)
	{
		offset_y = (y - top) * ((double)map->west.height / (bottom - top));
		ft_pixel_put(mlx, x, y,ft_pixel_get_color(img, offset_x, offset_y));
		y++;
	}
	return (True);
}

t_bool	 display_textured_walls(t_mlx *mlx)
{
	int x;
	t_rays temp;

	x = 0;
	while (x < (mlx->map->r_width))
	{
		temp = mlx->cam.ray_tab[x];
		if (temp.facing_up && temp.wall.hz)
			draw_wall_hz_hit(temp, mlx->map, mlx->map->north, mlx, x);
		else if (temp.facing_down && temp.wall.hz)
			draw_wall_hz_hit(temp, mlx->map, mlx->map->south, mlx, x);
		else if (temp.facing_left && temp.wall.vt)
			draw_wall_vt_hit(temp, mlx->map, mlx->map->west, mlx, x);
		else if (temp.facing_right && temp.wall.vt)
			draw_wall_vt_hit(temp, mlx->map, mlx->map->east, mlx, x);
		x++;
	}
	return (True);
}