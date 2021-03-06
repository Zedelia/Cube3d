/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:22:46 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 14:22:47 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	ray_rotate(t_rays *r, float angle)
{
	double a;
	double temp_x;

	temp_x = r->x;
	a = degrees_to_radian(angle);
	r->angle += a;
	r->x = r->x * cos(a) - r->y * sin(a);
	r->y = temp_x * sin(a) + r->y * cos(a);
	ray_get_direction(r);
	return (True);
}
