/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_textures.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/18 15:56:48 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 13:06:05 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	draw_column_hz_hit(t_rays r, t_mlx *mlx, t_img img, int x)
{
	int y;
	double wall_end;
	double wall_start;
	double offset_x;
	double	offset_y;

	offset_x = (r.wall.hz_hit.x - (int)r.wall.hz_hit.x) * mlx->map->north.width;
	offset_x = offset_x < 0 ? -offset_x : offset_x;
	wall_start = mlx->map->r_height / 2 - mlx->map->r_height / r.distance / 2;;
	wall_end = mlx->map->r_height / 2 + mlx->map->r_height / r.distance / 2;
	y = wall_start;
	while (y < wall_end)
	{
		offset_y = (y - wall_start) * ((double)mlx->map->north.height / (wall_end - wall_start));
		ft_pixel_put(mlx, x, y, ft_pixel_get_color(img, offset_x, offset_y));
		y++;
	}
	return (True);
}

t_bool	 draw_column_vt_hit(t_rays r, t_mlx *mlx, t_img img, int x)
{
	int y;
	double	color;
	double	wall_end;
	double	wall_start;
	double 	offset_x;
	double	offset_y;

	color = 0x0;
	offset_x = (r.wall.vt_hit.y - (int)r.wall.hz_hit.y) * mlx->map->east.width;
	offset_x = offset_x < 0 ? -offset_x : offset_x;
	while (offset_x > mlx->map->east.height)
	{
		offset_x = mlx->map->east.height - offset_x;
		offset_x = offset_x < 0 ? -offset_x : offset_x;
	}
	wall_start = mlx->map->r_height / 2 - mlx->map->r_height / r.distance / 2;;
	wall_end = mlx->map->r_height / 2 + mlx->map->r_height / r.distance / 2;
	y = wall_start;
	while (y < wall_end)
	{
		offset_y = (y - wall_start) * ((double)mlx->map->west.height / (wall_end - wall_start));
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
			draw_column_hz_hit(temp, mlx, mlx->map->north, x);
		else if (temp.facing_down && temp.wall.hz)
			draw_column_hz_hit(temp, mlx, mlx->map->south, x);
		else if (temp.facing_left && temp.wall.vt)
			draw_column_vt_hit(temp, mlx, mlx->map->west, x);
		else if (temp.facing_right && temp.wall.vt)
			draw_column_vt_hit(temp, mlx, mlx->map->east, x);
		x++;
	}
	return (True);
}