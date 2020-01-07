/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays_init.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:24:48 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 13:47:27 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ray_init_directions(t_rays *ray)
{
	if (ray->x >= 0)
		ray->facing_right = True;
	else if (ray->x < 0)
		ray->facing_right = False;
	ray->facing_left = !ray->facing_right;
	if (ray->y >= 0)
		ray->facing_down = True;
	else if (ray->y < 0)
		ray->facing_down = False;
	ray->facing_up = !ray->facing_down;
}

t_rays  ray_init(float angle)
{
	t_rays	ray;

	ray.x = -sin(degrees_to_radian(angle));
	ray.y = cos(degrees_to_radian(angle));
	ray.wall_hit_x = 0;
	ray.wall_hit_y = 0;
	ray.distance = 0;
	ray.angle = degrees_to_radian(angle);
	ray_init_directions(&ray);
	return (ray);
}

t_bool	rays_tab_init(t_rays *rays, t_mlx *mlx)
{
    int	i;
	float r_angle;

    i = 0;
    rays[i] = ray_init((-(FOV_DEGREE/2)));
    i++;
    while (i < mlx->map->r_width)
    {
		r_angle =(i - mlx->map->r_width * 0.5) * FOV_DEGREE / mlx->map->r_width;
        rays[i] = ray_init(r_angle);
        i++;
    }
    return (True);
}