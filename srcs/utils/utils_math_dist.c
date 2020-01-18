/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_math_dist.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/18 13:10:13 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 13:17:18 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

double	dist_correct_fish_eye(t_rays r, t_mlx *mlx, double dist)
{
	double	ok_dist;
	double	angle;

	angle = r.angle - mlx->cam.ray_tab[mlx->map->r_width / 2].angle;
	ok_dist = dist * cos(angle);
	return (ok_dist);
}

double	ray_math_dist(t_vect hit, t_mlx *mlx)
{
	double dist;

	dist = sqrt((mlx->cam.pos.x - hit.x) * (mlx->cam.pos.x - hit.x)
					+ (mlx->cam.pos.y - hit.y) * (mlx->cam.pos.y - hit.y));
	return (dist);
}