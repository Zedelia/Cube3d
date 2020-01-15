/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_get_distance.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 20:21:04 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 17:44:06 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

float	utils_dist_obstacle_cam(t_vect obs, t_vect cam_pos)
{
	float dist;

	dist = sqrt((cam_pos.x - obs.x) * (cam_pos.x - obs.x)
					+ (cam_pos.y - obs.y) * (cam_pos.y - obs.y));
	return (dist);
}

t_bool	ray_get_distance(t_rays *r, t_mlx *mlx)
{
	float	hz_distance;
	float	vt_distance;

	if (!(ray_get_intersections(r, mlx)))
		return (return_false(__func__, "[FAIL] rays/grid intersec not found"));
	ray_get_walls_hit(r, mlx);
	hz_distance = utils_dist_obstacle_cam(r->wall.hz_hit, mlx->cam.pos);
	vt_distance = utils_dist_obstacle_cam(r->wall.vt_hit, mlx->cam.pos);
	if (hz_distance < vt_distance)
	{
		r->distance = hz_distance;
		r->wall.hz = True;
		r->wall.vt = False;
	}
	else
	{
		r->distance = vt_distance;
		r->wall.vt = True;
		r->wall.hz = False;
	}
	return (True);
}

