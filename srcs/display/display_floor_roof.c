/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_floor_roof.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/19 16:02:45 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 16:06:13 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"


t_bool		display_roof(t_mlx *mlx)
{
	int x = 0;
	int y = 0;
	while (x < mlx->map->r_width)
	{
		y = 0;
		while (y < mlx->map->r_height / 2 )
		{
			ft_pixel_put(mlx, x, y, 0x8074F9 );
			y++;
		}
		x++;
	}
	return (True);
}

t_bool		display_floor(t_mlx *mlx)
{
	int x = 0;
	int y = 0;
	while (x < mlx->map->r_width)
	{
		y = mlx->map->r_height / 2;
		while (y < mlx->map->r_height)
		{
			ft_pixel_put(mlx, x, y, 0xFFF877);
			y++;
		}
		x++;
	}
	return (True);
}