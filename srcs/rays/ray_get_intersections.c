/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_get_intersections.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 13:38:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 15:35:12 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static t_bool	ray_get_fst_vertical_intersection(t_rays *r, t_mlx *mlx)
{
	float	y_intr;
	float	x_intr;

	if (r->facing_right == False && r->facing_left == False)
		x_intr = 0;
	else
	{
		x_intr = ft_floor(mlx->cam.pos.x / mlx->map->tile) * mlx->map->tile;
		if (r->facing_right == True)
			x_intr += mlx->map->tile;
		else if (r->facing_left == True)
			x_intr -= mlx->map->tile;
	}
	if (!(y_intr = mlx->cam.pos.y + (x_intr - mlx->cam.pos.x) / tan(r->angle)))
		return (return_false(__func__, "[FAIL] ray first hit not found"));
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
		y_intr = ft_floor(mlx->cam.pos.y / mlx->map->tile) * mlx->map->tile;
		if (r->facing_up == True)
			y_intr -= mlx->map->tile;
		else if (r->facing_down == True)
			y_intr += mlx->map->tile;
	}
	if (!(x_intr = mlx->cam.pos.x + (y_intr - mlx->cam.pos.y) / tan(r->angle)))
		return (return_false(__func__, "[FAIL] ray first hit not found"));
	r->hz_fst_inter.x = x_intr;
	r->hz_fst_inter.y = y_intr;
	return (True);
}

t_bool	ray_get_intersections(t_rays *r, t_mlx *mlx)
{
	if (!(ray_get_fst_horizontal_intersection(r, mlx)))
		return (return_false(__func__, "[FAIL] ray first hz inter not found"));
	if (!(ray_get_fst_vertical_intersection(r, mlx)))
		return (return_false(__func__, "[FAIL] ray first vt inter not found"));
	ray_get_steps(r, mlx);
	return (True);
}