/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:18:12 by mbos              #+#    #+#             */
/*   Updated: 2020/02/24 17:33:24 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	display_update(t_mlx *mlx)
{
	rays_casting(mlx);
	display_sky(mlx);
	display_floor(mlx);
	display_walls(mlx);
	display_sprite(mlx);
	if (mlx->bonus2)
		display_bonus(mlx, mlx->map->frame);
	display_mini_map(mlx, mlx->map);
	if (mlx->bonus1)
		display_bonus(mlx, mlx->map->life);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}
