/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_tab_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:22:56 by mbos              #+#    #+#             */
/*   Updated: 2020/02/24 12:12:03 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	rays_tab_init(t_mlx *mlx)
{
	int		i;
	double	r_angle;
	float	dist_ref;

	i = 0;
	if (!(mlx->cam.ray_tab = malloc(sizeof(t_rays) * mlx->map->w)))
		return (return_false(__func__, "[FAIL] malloc rays tab", mlx));
	dist_ref = tan(degrees_to_radian(FOV_DEGREE) * 0.5);
	while (i < mlx->map->w)
	{
		r_angle = atan(dist_ref / (mlx->map->w * 0.5)
				* (i - mlx->map->w * 0.5));
		mlx->cam.ray_tab[i] = ray_init(r_angle, mlx->cam.pos);
		ray_get_distance(&mlx->cam.ray_tab[i], mlx);
		mlx->cam.ray_tab[i].id = i;
		i++;
	}
	return (True);
}
