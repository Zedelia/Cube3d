/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays_setup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:24:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 14:24:46 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_rays	ray_setup(double angle)
{
	t_rays	ray;
	double	radian_a;

	radian_a = degrees_to_radian(angle);
	ray = rays_init();
	ray.x = -sin(radian_a);
	ray.y = cos(radian_a);
	return (ray);
}