/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_floor_sky.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:54:56 by mbos              #+#    #+#             */
/*   Updated: 2020/03/02 13:18:12 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool		display_sky(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	while (x < mlx->map->w)
	{
		y = 0;
		while (y < mlx->map->h / 2)
		{
			pixel_put(mlx, x, y, mlx->map->sky);
			y++;
		}
		x++;
	}
	return (True);
}

t_bool		display_floor(t_mlx *mlx)
{
	int		x;
	int		y;
	double	height;

	height = mlx->map->h;
	x = 0;
	while (x < mlx->map->w)
	{
		y = height / 2;
		while (y < height)
		{
			pixel_put(mlx, x, y,
					mlx->map->floor);
			y++;
		}
		x++;
	}
	return (True);
}
