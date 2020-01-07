/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays_get_distance.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 16:34:49 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 16:37:37 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	ray_get_distance(t_rays *r, t_mlx *mlx)
{
	float y_intercept;
	float x_intercept;

	y_intercept = rays_closest_hit_y(r, mlx);
	x_intercept = rays_closest_hit_x(r, mlx);

}