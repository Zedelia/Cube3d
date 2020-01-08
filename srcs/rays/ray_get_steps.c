/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_get_steps.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 12:57:12 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 14:04:01 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static t_bool get_hz_step(t_rays *r, t_mlx *mlx)
{
	float y_step;
	float x_step;

	y_step = mlx->map->tile;
	y_step *= r->facing_up ? -1 : 1;
	x_step = mlx->map->tile / tan(r->angle);
	x_step *= (r->facing_left && x_step > 0) ? -1 : 1;
	x_step *= (r->facing_right && x_step < 0) ? -1 : 1;
	r->hz_fst_inter.steps.x = x_step;
	r->hz_fst_inter.steps.y = y_step;
	if (!x_step || !y_step)
		return (return_false(__func__, "[FAIL] ray hz step not found"));
	return (True);
}

static t_bool get_vt_step(t_rays *r, t_mlx *mlx)
{
	float y_step;
	float x_step;

	x_step = mlx->map->tile;
	x_step *= r->facing_left ? -1 : 1;
	y_step = mlx->map->tile / tan(r->angle);
	y_step *= (r->facing_down && y_step > 0) ? -1 : 1;
	y_step *= (r->facing_up && y_step < 0) ? -1 : 1;
	r->hz_fst_inter.steps.x = x_step;
	r->hz_fst_inter.steps.y = y_step;
	if (!x_step || !y_step)
		return (return_false(__func__, "[FAIL] ray hz step not found"));
	return (True);
}

t_bool ray_get_steps(t_rays *r, t_mlx *mlx)
{
	if(!(get_hz_step(r, mlx)))
		return (return_false(__func__, "[FAIL] ray hz step not found"));
	if (!(get_vt_step(r, mlx)))
		return (return_false(__func__, "[FAIL] ray vt step not found"));
	return (True);
}