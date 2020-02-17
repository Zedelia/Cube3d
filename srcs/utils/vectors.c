/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:24:19 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 14:24:21 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_vect	norm_vect(t_vect v)
{
	t_vect	v_norm;
	double	v_size;

	v_size = sqrt(v.y * v.y + v.x * v.x);
	v_norm.x = v.x / v_size;
	v_norm.y = v.y / v_size;
	return (v_norm);
}

void	rotate_vect(t_vect *r, double angle)
{
	double c;

	c = degrees_to_radian(angle);
	r->x = r->x * cos(c) - r->y * sin(c);
	r->y = r->x * sin(c) + r->y * cos(c);
}
