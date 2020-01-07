/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays_init.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:24:48 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 16:45:53 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ray_init_directions(t_rays *ray)
{
	if (ray->x > 0)
		ray->facing_right = True;
	else if (ray->x < 0 || ray->x == 0)
		ray->facing_right = False;
	if (ray->x != 0)
		ray->facing_left = !ray->facing_right;
	else
		ray->facing_left = False;
	if (ray->y > 0)
		ray->facing_down = True;
	else if (ray->y < 0 || ray->y == 0)
		ray->facing_down = False;
	if (ray->y != 0)
		ray->facing_up = !ray->facing_down;
	else
		ray->facing_up = False;
}

t_rays  ray_init(float angle)
{
	t_rays	ray;

	ray.x = sin(degrees_to_radian(angle));
	ray.y = -cos(degrees_to_radian(angle));
	ray.wall_hit_x = 0;
	ray.wall_hit_y = 0;
	ray.distance = 0;
	ray.angle = degrees_to_radian(angle);
	ray_init_directions(&ray);
	return (ray);
}

t_bool	rays_tab_init(t_mlx *mlx)
{
    int		i;
	float	r_angle;

    i = 0;
	if(!(mlx->cam.ray_tab = malloc(sizeof(t_rays) * mlx->map->r_width)))
		return (return_false(__func__, "[FAIL] malloc rays tab"));
    mlx->cam.ray_tab[i] = ray_init((-(FOV_DEGREE/2)));
    i++;
    while (i < mlx->map->r_width)
    {
		r_angle =(i - mlx->map->r_width * 0.5) * FOV_DEGREE / mlx->map->r_width;
        mlx->cam.ray_tab[i] = ray_init(r_angle);
        i++;
    }
    return (True);
}