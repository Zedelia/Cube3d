/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_get_steps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:22:28 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 14:22:30 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void		get_hz_step(t_rays *r)
{
	double y_step;
	double x_step;

	y_step = r->facing_up ? -1 : 1;
	if (r->angle)
		x_step = 1 * tan(r->angle);
	else
		x_step = 0;
	x_step *= r->facing_left && x_step > 0 ? -1 : 1;
	x_step *= r->facing_right && x_step < 0 ? -1 : 1;
	r->hz_fst_inter.steps.x = x_step;
	r->hz_fst_inter.steps.y = y_step;
}

static void		get_vt_step(t_rays *r)
{
	double y_step;
	double x_step;

	x_step = r->facing_left ? -1 : 1;
	if (r->angle)
		y_step = 1 / tan(r->angle);
	else
		y_step = 0;
	y_step *= r->facing_up && y_step > 0 ? -1 : 1;
	y_step *= r->facing_down && y_step < 0 ? -1 : 1;
	r->vt_fst_inter.steps.x = x_step;
	r->vt_fst_inter.steps.y = y_step;
}

t_bool			ray_get_steps(t_rays *r, t_mlx *mlx)
{
	(void)mlx;
	get_hz_step(r);
	get_vt_step(r);
	return (True);
}
