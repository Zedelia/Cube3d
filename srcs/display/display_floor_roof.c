/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_floor_roof.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:17:51 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 14:17:52 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool		display_roof(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	while (x < mlx->map->r_width)
	{
		y = 0;
		while (y < mlx->map->r_height / 2)
		{
			pixel_put(mlx, x, y,
					shade_color(mlx->map->cell, 1.50 * y / mlx->map->r_height));
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

	height = mlx->map->r_height;
	x = 0;
	while (x < mlx->map->r_width)
	{
		y = height / 2;
		while (y < height)
		{
			pixel_put(mlx, x, y,
					shade_color(mlx->map->floor,
					1 - (1.50 * (y - height * 0.5) / height)));
			y++;
		}
		x++;
	}
	return (True);
}
