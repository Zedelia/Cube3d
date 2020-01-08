/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_1_rotate.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 20:19:35 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 20:19:39 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	ray_rotate(t_rays *r, t_mlx *mlx)
{
	float a;

	a = degrees_to_radian(mlx->cam.rotation_angle);
	r->x = r->x * cos(a) - r->y * sin(a);
	r->y = r->x * sin(a) + r->y * cos(a);
	ray_get_direction(r);
	return (True);
}