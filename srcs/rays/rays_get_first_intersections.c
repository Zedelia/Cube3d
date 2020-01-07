/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays_get_first_intrsections.c                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 19:06:52 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 19:28:33 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	ray_get_vertical_intrsection(t_rays *r, t_mlx *mlx)
{

}

t_bool	ray_get_horizontal_intrsection(t_rays *r, t_mlx *mlx)
{
	float	y_intr;
	float	x_intr;

	if (r->facing_up == False && r->facing_down == False)
		y_intr = 0;
	else
	{
		y_intr = ft_floor(mlx->cam.pos_y / mlx->map->tile) * mlx->map->tile;
		if (r->facing_up == True)
			y_intr -= mlx->map->tile;
		else if (r->facing_down == True)
			y_intr += mlx->map->tile;
	}
	r->y_fst_hit.x = mlx->cam.pos_x + (y_intr - mlx->cam.pos_y) / tan(r->angle);
	return (True);
}

t_bool	ray_get_first_intrsections(t_rays *r, t_mlx *mlx)
{
	ray_get_horizontal_intrsection(r, mlx);
	ray_get_vertical_intrsection(r, mlx);
	return (True);
}
