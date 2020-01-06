/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays_init.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:24:48 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 18:23:58 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// TODO

static void	rays_init_directions(t_rays *ray, t_vect vect)
{
	if (vect.x >= 0)
		ray->facing_right = True;
	else if (vect.x < 0)
		ray->facing_right = False;
	ray->facing_left = !ray->facing_right;
	if (vect.y >= 0)
		ray->facing_down = True;
	else if (vect.y < 0)
		ray->facing_down = False;
	ray->facing_up = !ray->facing_down;
}

t_rays  rays_init(t_vect vect, float angle)
{
	t_rays	ray;

	ray.wall_hit_x = 0;
	ray.wall_hit_y = 0;
	ray.distance = 0;
	ray.angle = angle;
	rays_init_directions(&ray, vect);
	return (ray);
}