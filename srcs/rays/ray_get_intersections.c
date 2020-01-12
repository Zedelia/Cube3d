/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_get_intersections.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 20:21:37 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 15:31:23 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static t_bool	ray_get_fst_vertical_intersection(t_rays *r, t_mlx *mlx)
{
	float	y_intr;
	float	x_intr;

	if (r->facing_left == False && r->facing_right == False)
		x_intr = 0;
	else
	{
		x_intr = (int)mlx->cam.pos.x;
		if (r->facing_left == True)
			x_intr += 1;
	}
	if (!(y_intr = (x_intr - mlx->cam.pos.x) / tan(M_PI * 0.5 - r->angle)))
		return (return_false(__func__, "[FAIL] ray first hit not found"));
	y_intr = y_intr < 0 ? -y_intr : y_intr;
	y_intr = (r->facing_up == True) ? (int)mlx->cam.pos.y - y_intr : (int)mlx->cam.pos.y + 1 + y_intr;
	r->vt_fst_inter.x = x_intr;
	r->vt_fst_inter.y = y_intr;
	return (True);
}

static t_bool	ray_get_fst_horizontal_intersection(t_rays *r, t_mlx *mlx)
{
	float	y_intr;
	float	x_intr;

	if (r->facing_up == False && r->facing_down == False)
		y_intr = 0;
	else
	{
		y_intr = (int)mlx->cam.pos.y;
		if (r->facing_down == True)
			y_intr += 1;
	}
	if (!(x_intr = ((y_intr - mlx->cam.pos.y) / tan(M_PI * 0.5 - r->angle))))
		return (return_false(__func__, "[FAIL] ray first hit not found"));
	x_intr = x_intr < 0 ? -x_intr : x_intr;
	x_intr = (r->facing_left == True) ? (int)mlx->cam.pos.x + x_intr : mlx->cam.pos.x + x_intr;
	r->hz_fst_inter.x = x_intr;
	r->hz_fst_inter.y = y_intr;
	return (True);
}

t_bool	ray_get_intersections(t_rays *r, t_mlx *mlx)
{
	ray_get_fst_horizontal_intersection(r, mlx);
	ray_get_fst_vertical_intersection(r, mlx);
	ray_get_steps(r, mlx);
	return (True);
}
