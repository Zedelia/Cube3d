/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_update.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/17 14:18:12 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/22 21:48:40 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "../../includes/cube3d.h"

void	display_update(t_mlx *mlx)
{
	rays_casting(mlx);
	display_sky(mlx);
	display_floor(mlx);
	display_walls(mlx);
	display_sprite(mlx);
	display_mini_map(mlx, mlx->map);
	display_life(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}
