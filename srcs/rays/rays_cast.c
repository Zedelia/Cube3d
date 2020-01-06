/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays_cast.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/04 16:31:33 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 18:18:41 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	ray_cast_one(t_mlx *mlx)
{
	float x_intercept;
	float y_intercept;
	float x_step;
	float y_step;

	

}

t_bool	ray_cast_left(t_mlx *mlx, t_rays *rays)
{
	float	ray_angle;
	int		pix_id;
	int		delta;
	t_rays	ray;

	pix_id = mlx->map->r_width / 2;
	delta = FOV_DEGREE / mlx->map->r_width;
	ray_angle = mlx->camera.rotation_angle;
	while (pix_id > -1)
	{
		ray_cast_one(ray_angle, pix_id);
		ray = rays_init(mlx->camera.direction, ray_angle);
		ray_angle = mlx->camera.rotation_angle - delta;
		delta += delta;
		rays[pix_id] = ray;
		pix_id--;
	}
	return (True);
}

t_bool	ray_cast_right(t_mlx *mlx, t_rays *rays)
{
	float	ray_angle;
	int		pix_id;
	int		delta;
	t_rays	ray;

	pix_id = mlx->map->r_width / 2;
	delta = FOV_DEGREE / mlx->map->r_width;
	while (pix_id < mlx->map->r_width)
	{
		ray_angle = mlx->camera.rotation_angle - delta;
		ray = rays_init(mlx->camera.direction, ray_angle);
		ray_cast_one(ray_angle, pix_id);
		delta -= delta;
		rays[pix_id] = ray;
		pix_id++;
	}
	return (True);
}

t_bool	rays_cast_all(t_mlx *mlx)
{
	t_rays		rays[mlx->map->r_width]; // le nb de rayons
	ray_cast_left(mlx, rays);
	ray_cast_right(mlx, rays);
}