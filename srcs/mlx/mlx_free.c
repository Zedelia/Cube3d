/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:20:55 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 14:20:58 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	mlx_free(t_mlx *mlx)
{
	if (mlx)
	{
		if (mlx->map)
			map_free(mlx->map);
		if (mlx->cam.ray_tab)
			ft_memdel((void **)&mlx->cam.ray_tab);
		ft_memdel((void**)&mlx);
	}
}
