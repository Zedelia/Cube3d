/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays_cast.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/04 16:31:33 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 19:06:24 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	ray_cast_one(t_rays *ray, t_mlx *mlx);
{
	float x_intercept;
	float y_intercept;
	float x_step;
	float y_step;

////// HORIZONTAL RAY GRID INTERSECTION
// find the y-coordonate of the closest horizontal grid intersection
	y_intercept = ft_floor(mlx->cam.pos_y / mlx->cam.s_tile) * mlx->cam.s_tile;
	y_intercept += ray->facing_down ? mlx->cam.s_tile : 0;
// find the x-coordonate or the ...
	x_intercept = mlx->cam.pos_x + (y_intercept - mlx->cam.pos_y) / tan(ray->angle);
// calculate the increment x step and y step
	y_step = mlx->cam.s_tile;
	y_step *= 

}

t_bool	ray_cast_left(t_mlx *mlx, t_rays *rays)
{
	float	ray_angle;
	int		pix_id;
	int		delta;
	t_rays	ray;

	pix_id = mlx->map->r_width / 2;
	delta = FOV_DEGREE / mlx->map->r_width;
	ray_angle = mlx->cam.rotation_angle;
	while (pix_id > -1)
	{
		ray = rays_init(mlx->cam.direction, ray_angle);
		ray_cast_one(&ray, mlx);
		ray_angle = mlx->cam.rotation_angle - delta;
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
		ray_angle = mlx->cam.rotation_angle - delta;
		ray = rays_init(mlx->cam.direction, ray_angle);
		ray_cast_one(&ray, mlx);
		delta -= delta;
		rays[pix_id] = ray;
		pix_id++;
	}
	return (True);
}

t_bool	rays_cast_all(t_mlx *mlx)
{
	t_rays rays[mlx->map->r_width];

	ray_cast_left(mlx, rays);
	ray_cast_right(mlx, rays);
	// TO BE DELETED
	rays_printf_tab(mlx, rays);
}