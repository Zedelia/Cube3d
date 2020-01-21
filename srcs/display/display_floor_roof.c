/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_floor_roof.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/19 16:02:45 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 19:43:13 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"


t_bool		display_roof(t_mlx *mlx, int x, double stop)
{
	int y;

	y = 0;
	while (y < stop + 10)
	{
		ft_pixel_put(mlx, x, y, ROOF_COLOR);
		y++;
	}
	return (True);
}

t_bool		display_floor(t_mlx *mlx, int x, double start)
{
	int y;

	y = start - 1;
	while (y < mlx->map->r_height)
	{
		ft_pixel_put(mlx, x, y, FLOOR_COLOR);
		y++;
	}
	return (True);
}