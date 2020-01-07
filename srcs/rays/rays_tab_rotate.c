/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   r_r_rotate.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 14:47:39 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 14:51:05 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	rays_rotate(t_mlx *mlx)
{
	t_rays *r;
	int		i;
	float	a;

	i = 0;
	a = mlx->cam.rotation_angle;
	r = mlx->cam.ray_tab;
	while (i < mlx->map->r_width)
	{
		r[i].x = r[i].x * cos(a) - r[i].y * sin(a);
		r[i].y = r[i].x * sin(a) + r[i].y * cos(a);
		ray_init_directions(&r[i]);
		i++;
	}
	return (True);
}