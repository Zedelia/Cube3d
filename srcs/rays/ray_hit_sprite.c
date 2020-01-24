/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_hit_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 14:06:37 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 11:08:11 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// TODO REVIEW Par pitie fais des objets sprite et reoganise tout ca
t_bool	ray_hit_sprite(t_rays *r, t_vect_int wall, t_mlx *mlx, t_vect v)
{
	int i;

	i = 0;
	while (i < mlx->map->map_sprites)
	{
		if (mlx->map->sprite_tab[i].x == wall.x && mlx->map->sprite_tab[i].y == wall.y)
		{
			mlx->map->sprite_tab[i].visible = True;
			sprite_get_ray_hits(*r, mlx, v, i);
			sprite_get_dist(r, mlx, v, i);
		}
		i++;
	}
	return (True);
}