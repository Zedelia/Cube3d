/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_get_intersections.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 20:21:37 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/08 11:50:06 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	ray_get_fst_vertical_intersection(t_rays *r, t_mlx *mlx)
{
	t_vect	inter;
	double 	x_temp;

	if (r->facing_left == False && r->facing_right == False)
	{
		r->vt_fst_inter.x = 0;
		r->vt_fst_inter.y = 0;
	}
	else
	{
		inter.x = (int)mlx->cam.pos.x;
		if (r->facing_right == True && inter.x != mlx->cam.pos.x)
			inter.x += 1;
	}
	x_temp = !(inter.x - mlx->cam.pos.x) ? 0.0001 : inter.x - mlx->cam.pos.x;
	inter.y = x_temp * tan(M_PI * 0.5 - r->angle);
	inter.y = inter.y > 0 ? inter.y : -inter.y;
	inter.y = (r->facing_up == True) ?
			mlx->cam.pos.y - inter.y : mlx->cam.pos.y + inter.y;
	r->vt_fst_inter.x = inter.x;
	r->vt_fst_inter.y = inter.y;
	r->vt_fst_inter.dist = ft_math_dist(inter.x, inter.y, mlx);
}

static void	ray_get_fst_horizontal_intersection(t_rays *r, t_mlx *mlx)
{
	t_vect	inter;
	double	y_temp;

	if (r->facing_up == False && r->facing_down == False)
	{
		r->hz_fst_inter.x = 0;
		r->hz_fst_inter.y = 0;
	}
	else
	{
		inter.y = (int)mlx->cam.pos.y;
		if (r->facing_down == True)
			inter.y += 1;
	}
	y_temp = !(inter.y - mlx->cam.pos.y) ? 0.0001 : inter.y - mlx->cam.pos.y;
	inter.x = y_temp / tan(M_PI * 0.5 - r->angle);
	inter.x = inter.x > 0 ? inter.x : -inter.x;
	inter.x = (r->facing_left == True) ?
			mlx->cam.pos.x - inter.x : mlx->cam.pos.x + inter.x;
	r->hz_fst_inter.x = inter.x;
	r->hz_fst_inter.y = inter.y;
	r->hz_fst_inter.dist = ft_math_dist(inter.x, inter.y, mlx);
}

t_bool		ray_get_intersections(t_rays *r, t_mlx *mlx)
{
	ray_get_fst_horizontal_intersection(r, mlx);
	ray_get_fst_vertical_intersection(r, mlx);
	ray_get_steps(r, mlx);
	return (True);
}
