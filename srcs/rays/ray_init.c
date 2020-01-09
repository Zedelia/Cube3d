/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_init.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:24:48 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 16:10:39 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_rays  ray_init(float angle, t_vect cam_pos)
{
	t_rays	ray;
	(void)cam_pos;

	ray.x = sin(degrees_to_radian(angle));
	ray.y = -cos(degrees_to_radian(angle));
	ray.distance = 0;
	ray.angle = degrees_to_radian(angle);
	ray_get_direction(&ray);
	return (ray);
}
