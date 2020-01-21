/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_casting.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 20:19:11 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 19:06:54 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	rays_casting(t_mlx *mlx)
{
	t_rays *r;
	int		i;

	i = 0;
	r = mlx->cam.ray_tab;

	while (i < mlx->map->r_width)
	{
		r[i].sprite = NULL;
		ray_rotate(&r[i], mlx->cam.rotation_angle);
		ray_get_distance(&r[i], mlx);
		i++;
	}
	mlx->cam.rotation_angle = 0;
	return (True);
}