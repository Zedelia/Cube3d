/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_closest_hits.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 14:23:33 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 17:37:49 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

float	rays_closest_hit_x(t_rays *r, t_mlx *mlx)
{
	
}

float	rays_closest_hit_y(t_rays *r, t_mlx *mlx)
{
	float y_intercept;

	if (r->facing_up == False && r->facing_down == False)
		return (y_intercept = 0);
	y_intercept = ft_floor(mlx->cam.pos_y / mlx->map->tile) * mlx->map->tile;
	if (r->facing_up == True)
		y_intercept -= mlx->map->tile;
	else if (r->facing_down == True)
		y_intercept += mlx->map->tile;
	return (y_intercept);
}