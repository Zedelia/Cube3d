/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_get_distance.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 20:21:04 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 13:39:43 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	ray_get_distance(t_rays *r, t_mlx *mlx)
{
	double	hz_distance;
	double	vt_distance;

	if (!(ray_get_intersections(r, mlx)))
		return (return_false(__func__, "[FAIL] rays/grid intersec not found"));
	ray_get_walls_hit(r, mlx);
	hz_distance = ray_math_dist(r->wall.hz_hit, mlx);
	vt_distance = ray_math_dist(r->wall.vt_hit, mlx);
	if (hz_distance < vt_distance)
	{
		r->distance = dist_correct_fish_eye(*r, mlx, hz_distance);
		r->wall.hz = True;
		r->wall.vt = False;
	}
	else
	{
		r->distance = dist_correct_fish_eye(*r, mlx, vt_distance);
		r->wall.vt = True;
		r->wall.hz = False;
	}
	return (True);
}

