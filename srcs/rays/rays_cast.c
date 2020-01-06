/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays_cast.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/04 16:31:33 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 16:46:28 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"



t_bool	ray_cast_one(float ray_angle, int pix_index)
{
	// all the crazy logic for horz, vert, ....
	ray_angle,

}

t_bool	rays_cast_all(t_mlx *mlx)
{
	float	ray_angle;
	int		pix_id;
	t_rays ray;
	int	rays[mlx->map->r_width]; // le nb de rayons

	pix_id = 0;
	// start first ray substracting half of the FOV
	ray_angle = mlx->camera.rotation_angle - (FOV_DEGREE / 2);
	while (pix_id < mlx->map->r_width)
	{
		ray_cast_one(ray_angle, pix_id);
		// TODO : ray_cast()
		ray_angle += FOV_DEGREE / mlx->map->r_width;
		pix_id++;
	}

}