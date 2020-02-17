/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_get_dist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:23:18 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 14:23:19 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	sprite_get_dist(t_rays *r, t_mlx *mlx, t_vect v, int i)
{
	double dist;

	dist = dist_correct_fish_eye(*r, mlx, ft_math_dist(v.x, v.y, mlx));
	if (dist > mlx->map->sprite_tab[i].dist)
		mlx->map->sprite_tab[i].dist = dist;
	return (True);
}
