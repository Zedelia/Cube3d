/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_rays.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 17:55:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 13:52:15 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static t_bool	display_rays_vt(t_mlx *mlx, t_rays r, int color)
{
	int temp_y;
	int i;

	i = 0;
	temp_y = mlx->cam.pos.y * (mlx->map->tile / MAP_SCALE);
	while (i < mlx->map->tile / MAP_SCALE * 2)
	{
		pixel_put(mlx,
			mlx->cam.pos.x * (mlx->map->tile / MAP_SCALE), temp_y, color);
		if (r.y > 0)
			temp_y++;
		else
			temp_y--;
		i++;
	}
	return (True);
}

static t_bool	display_rays_hz(t_mlx *mlx, t_rays r, int color)
{
	int temp_x;
	int i;

	i = 0;
	temp_x = mlx->cam.pos.x * (mlx->map->tile / MAP_SCALE);
	while (i < mlx->map->tile / MAP_SCALE * 2)
	{
		pixel_put(mlx,
			temp_x, mlx->cam.pos.y * (mlx->map->tile / MAP_SCALE), color);
		if (r.x > 0)
			temp_x++;
		else
			temp_x--;
		i++;
	}
	return (True);
}

static t_bool	display_rays_y(t_mlx *mlx, t_rays r, int color)
{
	double	a;
	double	b;
	int		temp_y;
	int		i;

	a = r.y / r.x;
	if (!a)
		return (True);
	i = 0;
	b = (mlx->cam.pos.y - a * mlx->cam.pos.x) * (mlx->map->tile / MAP_SCALE);
	temp_y = mlx->cam.pos.y * (mlx->map->tile / MAP_SCALE);
	while (i < mlx->map->tile / MAP_SCALE * 2)
	{
		pixel_put(mlx, (temp_y - b) / a, temp_y, color);
		if (r.y > 0)
			temp_y++;
		else
			temp_y--;
		i++;
	}
	return (True);
}

static t_bool	display_rays_x(t_mlx *mlx, t_rays r, int color)
{
	double	a;
	double	b;
	int		temp_x;
	int		i;

	a = r.y / r.x;
	b = (mlx->cam.pos.y - a * mlx->cam.pos.x) * (mlx->map->tile / MAP_SCALE);
	i = 0;
	temp_x = mlx->cam.pos.x * (mlx->map->tile / MAP_SCALE);
	while (i < mlx->map->tile / MAP_SCALE * 2)
	{
		pixel_put(mlx, temp_x, (a * temp_x + b), color);
		if (r.x > 0)
			temp_x++;
		else
			temp_x--;
		i++;
	}
	return (True);
}

t_bool			display_rays(t_mlx *mlx, t_rays *r)
{
	int i;
	int color;

	color = 0x000000AA;
	i = mlx->map->r_width / 2;
	if (!r[i].x)
		display_rays_vt(mlx, r[i], color);
	else if (!r[i].y)
		display_rays_hz(mlx, r[i], color);
	else if (fabs(r[i].x) >= fabs(r[i].y))
		display_rays_x(mlx, r[i], color);
	else
		display_rays_y(mlx, r[i], color);
	return (True);
}
