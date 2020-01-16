/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_get_walls_hit.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 20:21:58 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 17:54:40 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void ray_get_vt_wall_hit(t_rays *r, t_mlx *mlx)
{
	t_vect	to_check;

	to_check.x = r->vt_fst_inter.x;
	to_check.y = r->vt_fst_inter.y;
	while (ray_hits_vt_wall_at(r, to_check, mlx) == False)
	{
		to_check.x += r->vt_fst_inter.steps.x;
		to_check.y += r->vt_fst_inter.steps.y;
	}
	r->wall.vt_hit.x = to_check.x;
	r->wall.vt_hit.y = to_check.y;
}

static void ray_get_hz_wall_hit(t_rays *r, t_mlx *mlx)
{
	t_vect	to_check;

	to_check.x = r->hz_fst_inter.x;
	to_check.y = r->hz_fst_inter.y;
	while (ray_hits_hz_wall_at(r, to_check, mlx) == False)
	{
		to_check.x += r->hz_fst_inter.steps.x;
		to_check.y += r->hz_fst_inter.steps.y;
	}
	r->wall.hz_hit.x = to_check.x ;
	r->wall.hz_hit.y = to_check.y;
}

t_bool	ray_get_walls_hit(t_rays *r, t_mlx *mlx)
{
	ray_get_hz_wall_hit(r, mlx);
	ray_get_vt_wall_hit(r, mlx);
	return (True);
}
