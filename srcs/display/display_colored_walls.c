/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_colored_walls.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:17:41 by mbos              #+#    #+#             */
/*   Updated: 2020/02/24 12:12:11 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int		give_wall_color(t_rays r)
{
	int north;
	int	south;
	int	west;
	int	east;

	north = 0xb140ac;
	south = 0xa5ffa7;
	west = 0xf64a8a;
	east = 0xffcf40;
	if (r.facing_up && r.wall.hz)
		return (north);
	if (r.facing_down && r.wall.hz)
		return (south);
	if (r.facing_left && r.wall.vt)
		return (west);
	if (r.facing_right && r.wall.vt)
		return (east);
	return (0);
}

t_bool			display_colored_walls(t_mlx *mlx)
{
	int x;
	int y;
	int	color;
	int h;

	x = 0;
	h = mlx->map->h;
	while (x < (mlx->map->w))
	{
		y = h / 2 - h / mlx->cam.ray_tab[x].distance / 2;
		while (y < h / 2 + h / mlx->cam.ray_tab[x].distance / 2)
		{
			color = give_wall_color(mlx->cam.ray_tab[x]);
			pixel_put(mlx, x, y, color);
			y++;
		}
		x++;
	}
	return (True);
}
