/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays_parser.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 16:33:08 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 16:34:42 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	rays_parser(t_mlx *mlx)
{
	t_rays *r;
	int		i;

	i = 0;
	r = mlx->cam.ray_tab;
	while (i < mlx->map->r_width)
	{
		ray_rotate(&r[i], mlx);
		ray_get_distance(&r[i], mlx);
		i++;
	}
	return (True);
}
