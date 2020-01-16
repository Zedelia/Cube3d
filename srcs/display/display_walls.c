/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_walls.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 18:16:25 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 18:17:53 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// TODO mettre a jour une fois le rendu done

t_bool	display_walls(t_mlx *mlx)
{
	int x = 0;
	int y = 0;
	while (x < (mlx->map->r_width))
	{
	y = mlx->map->r_height / 2 - mlx->map->r_height / mlx->cam.ray_tab[x].distance / 2;
		while (y < mlx->map->r_height / 2 + mlx->map->r_height / mlx->cam.ray_tab[x].distance / 2)
		{
			ft_pixel_put(mlx, x, y,0x320085 );
			y++;
		}
		x++;
	}
	return (True);
}
