/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays_setup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:24:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/04 14:32:32 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_rays	ray_setup(double angle)
{
	t_rays	ray;
	double	angle_radian;

	angle_radian = degrees_to_radian(angle);
	ray = rays_init();
	ray.x = -sin(angle_radian);
	ray.y = cos(angle_radian);
	return (ray);
}