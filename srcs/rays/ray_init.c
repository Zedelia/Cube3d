/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:22:40 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 14:22:41 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_rays		ray_init(double angle, t_vect cam_pos)
{
	t_rays	ray;

	(void)cam_pos;
	ray.x = sin(angle);
	ray.y = -cos(angle);
	ray.distance = 0;
	ray.angle = angle;
	ray_get_direction(&ray);
	return (ray);
}
