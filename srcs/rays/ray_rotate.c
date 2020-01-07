/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_rotate.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 16:33:26 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 16:33:41 by mbos        ###    #+. /#+    ###.fr     */
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
	ray_init_directions(r);
	r->angle += a;
	return (True);
}