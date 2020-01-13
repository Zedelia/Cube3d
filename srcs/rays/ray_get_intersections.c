/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_get_intersections.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 20:21:37 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 13:08:30 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static t_bool	ray_get_fst_vertical_intersection(t_rays *r, t_mlx *mlx)
{
	t_vect	inter;

	if (r->facing_left == False && r->facing_right == False)
	{
		r->vt_fst_inter.x = 0;
		r->vt_fst_inter.y = 0;
		return (True);
	}
	else
	{
		inter.x = (int)mlx->cam.pos.x;
		if (r->facing_right == True)
			inter.x += 1;
	}
	inter.y = (inter.x - mlx->cam.pos.x) / tan(M_PI * 0.5 - r->angle);
	inter.y = inter.y < 0 ? -inter.y : inter.y;
	inter.y = (r->facing_up == True) ? (int)mlx->cam.pos.y + inter.y : mlx->cam.pos.y + 1 + inter.y;
	r->vt_fst_inter.x = inter.x;
	r->vt_fst_inter.y = inter.y;
	r->vt_fst_inter.dist = utils_dist_obstacle_cam(inter, mlx->cam.pos);
	return (True);
}

static t_bool	ray_get_fst_horizontal_intersection(t_rays *r, t_mlx *mlx)
{
	t_vect	inter;

	if (r->facing_up == False && r->facing_down == False)
	{
		r->hz_fst_inter.x = 0;
		r->hz_fst_inter.y = 0;
		return (True);
	}
	else
	{
		inter.y = (int)mlx->cam.pos.y;
		if (r->facing_down == True)
			inter.y += 1;
	}
	inter.x = ((inter.y - mlx->cam.pos.y) / tan(M_PI * 0.5 - r->angle));
	inter.x = inter.x < 0 ? -inter.x : inter.x;
	inter.x = (r->facing_left == True) ? (int)mlx->cam.pos.x + inter.x : mlx->cam.pos.x + inter.x;
	r->hz_fst_inter.x = inter.x;
	r->hz_fst_inter.y = inter.y;
	r->hz_fst_inter.dist = utils_dist_obstacle_cam(inter, mlx->cam.pos);
	return (True);
}

t_bool	ray_get_intersections(t_rays *r, t_mlx *mlx)
{
	ray_get_fst_horizontal_intersection(r, mlx);
	ray_get_fst_vertical_intersection(r, mlx);
	ray_get_steps(r, mlx);
	return (True);
}
