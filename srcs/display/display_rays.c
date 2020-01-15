/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_rays.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 17:55:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 16:38:48 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"


t_bool	display_rays_vt(t_mlx *mlx, t_rays r)
{
	int temp_y;
	int i;

	i = 0;
	temp_y = mlx->cam.pos.y * mlx->map->tile;
	while (!mlx->map->tab[temp_y / mlx->map->tile][(int)mlx->cam.pos.x])
	{
		ft_pixel_put(mlx, mlx->cam.pos.x * mlx->map->tile, temp_y, 0x000000AA);
		if (r.y > 0)
			temp_y++;
		else
			temp_y--;
		i++;
	}
	return (True);
}

t_bool	display_rays_hz(t_mlx *mlx, t_rays r)
{
	int temp_x;
	int i;

	i = 0;
	temp_x = mlx->cam.pos.x * mlx->map->tile;
	while (!mlx->map->tab[(int)mlx->cam.pos.y][temp_x / mlx->map->tile])
	{
		ft_pixel_put(mlx, temp_x, mlx->cam.pos.y * mlx->map->tile, 0x000000AA);
		if (r.x > 0)
			temp_x++;
		else
			temp_x--;
		i++;
	}
	return (True);
}

t_bool	display_rays_y(t_mlx *mlx, t_rays r)
{
	float a;
	float b;
	int temp_y;
	int i;
	t_vect 	wall;

	a = r.y / r.x;
	if (!a)
		return (True);
	wall.x = r.wall.vt ? r.wall.vt_hit.x : r.wall.hz_hit.x ;
	wall.y = r.wall.vt ? r.wall.vt_hit.y : r.wall.hz_hit.y ;
	wall.x = wall.x < 0 ? 0 : wall.x;
	wall.x = wall.x > mlx->map->map_col ? mlx->map->map_col - 1 : wall.x;
	wall.y = wall.y < 0 ? 0 : wall.y;
	wall.y = wall.y > mlx->map->map_lines ?  mlx->map->map_lines - 1 : wall.y;
	i = 0;
	b = (mlx->cam.pos.y - a * mlx->cam.pos.x) * mlx->map->tile;
	temp_y = mlx->cam.pos.y * mlx->map->tile;
	// while (!mlx->map->tab[temp_y / mlx->map->tile][(int)((temp_y - b) / (a * mlx->map->tile))])
	while (mlx->map->tab[temp_y / mlx->map->tile][(int)((temp_y - b) / (a * mlx->map->tile))] != mlx->map->tab[(int)wall.y][(int)wall.x])
	{
		ft_pixel_put(mlx, (temp_y - b) / a, temp_y, 0x000000AA);
		if (r.y > 0)
			temp_y++;
		else
			temp_y--;
		i++;
	}
	return (True);

}

t_bool	display_rays_x(t_mlx *mlx, t_rays r)
{
	float a;
	float b;
	int temp_x;
	int i;
	t_vect	wall;

	a = r.y / r.x;
	wall.x = r.wall.vt ? r.wall.vt_hit.x : r.wall.hz_hit.x ;
	wall.y = r.wall.vt ? r.wall.vt_hit.y : r.wall.hz_hit.y ;
	wall.x = wall.x < 0 ? 0 : wall.x;
	wall.x = wall.x > mlx->map->map_col ? mlx->map->map_col - 1 : wall.x;
	wall.y = wall.y < 0 ? 0 : wall.y;
	wall.y = wall.y > mlx->map->map_lines ?  mlx->map->map_lines - 1 : wall.y;
	b = (mlx->cam.pos.y - a * mlx->cam.pos.x) * mlx->map->tile;
	i = 0;
	temp_x = mlx->cam.pos.x * mlx->map->tile;
	// while (!mlx->map->tab[(int)((a * temp_x + b) / mlx->map->tile)][(int)temp_x / mlx->map->tile])
	while (mlx->map->tab[(int)((a * temp_x + b) / mlx->map->tile)][(int)temp_x / mlx->map->tile] != mlx->map->tab[(int)wall.y][(int)wall.x])
	{
		ft_pixel_put(mlx, temp_x, (a * temp_x + b), 0x000000AA);
		if (r.x > 0)
			temp_x++;
		else
			temp_x--;
		i++;
	}
	return (True);
}

t_bool	display_rays(t_mlx *mlx, t_rays *r)
{
	int i;

	i = 0;
	while (i < mlx->map->r_width)
	{
		if (!r[i].x)
			display_rays_vt(mlx, r[i]);
		else if (!r[i].y)
			display_rays_hz(mlx, r[i]);
		else if (fabs(r[i].x) >= fabs(r[i].y))
			display_rays_x(mlx, r[i]);
		else
			display_rays_y(mlx, r[i]);
	i++;
	}
	return (True);
}
