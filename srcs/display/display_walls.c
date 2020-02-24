/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:18:22 by mbos              #+#    #+#             */
/*   Updated: 2020/02/24 12:12:03 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static t_bool	walls_cases(t_rays temp, t_mlx *mlx, int x)
{
	if (temp.facing_up && temp.wall.hz)
		display_wall_hz(temp, mlx->map->south, mlx, x);
	else if (temp.facing_down && temp.wall.hz)
		display_wall_hz(temp, mlx->map->north, mlx, x);
	else if (temp.facing_left && temp.wall.vt)
		display_wall_vt(temp, mlx->map->east, mlx, x);
	else if (temp.facing_right && temp.wall.vt)
		display_wall_vt(temp, mlx->map->west, mlx, x);
	return (True);
}

t_bool			display_walls(t_mlx *mlx)
{
	int		x;
	t_rays	temp;

	x = 0;
	while (x < mlx->map->w)
	{
		temp = mlx->cam.ray_tab[x];
		walls_cases(temp, mlx, x);
		x++;
	}
	return (True);
}
