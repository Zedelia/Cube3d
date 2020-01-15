/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_rotate.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 20:19:35 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 16:18:31 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	ray_rotate(t_rays *r, t_mlx *mlx)
{
	float a;
	float temp_x;

	temp_x = r->x;
	r->angle += degrees_to_radian(mlx->cam.rotation_angle);
	a = degrees_to_radian(mlx->cam.rotation_angle);
	r->x = r->x * cos(a) - r->y * sin(a);
	r->y = temp_x * sin(a) + r->y * cos(a);
	ray_get_direction(r);
	return (True);
}