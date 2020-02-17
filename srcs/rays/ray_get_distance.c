/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_get_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:22:18 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 14:22:19 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	ray_get_distance(t_rays *r, t_mlx *mlx)
{
	double	hz_distance;
	double	vt_distance;

	ray_get_intersections(r, mlx);
	ray_get_walls_hit(r, mlx);
	hz_distance = ft_math_dist(r->wall.hz_hit.x, r->wall.hz_hit.y, mlx);
	vt_distance = ft_math_dist(r->wall.vt_hit.x, r->wall.vt_hit.y, mlx);
	if (hz_distance < vt_distance)
	{
		r->distance = dist_correct_fish_eye(*r, mlx, hz_distance);
		r->wall.hz = True;
		r->wall.vt = False;
	}
	else
	{
		r->distance = dist_correct_fish_eye(*r, mlx, vt_distance);
		r->wall.vt = True;
		r->wall.hz = False;
	}
	return (True);
}
