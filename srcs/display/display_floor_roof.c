/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_floor_roof.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/19 16:02:45 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 18:33:24 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"


t_bool		display_roof(t_mlx *mlx)
{
	int 	x;
	int 	y;


	x = 0;
	while (x < mlx->map->r_width)
	{
		y = 0;

		while (y < mlx->map->r_height / 2 )
		{
			ft_pixel_put(mlx, x, y,
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
	double height;

	height = mlx->map->r_height;
	x = 0;
	while (x < mlx->map->r_width)
	{
		y = height / 2;
		while (y < height)
		{
			ft_pixel_put(mlx, x, y,
					shade_color(mlx->map->floor,
					1 - (1.50 * (y - height * 0.5) / height)));
			y++;
		}
		x++;
	}
	return (True);
}
