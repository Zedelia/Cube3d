/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_hit_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 14:06:37 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 16:17:01 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	ray_hit_sprite(t_rays *r, t_vect_int wall, t_mlx *mlx, t_vect v)
{
	int i;

	i = 0;
	while (i < mlx->map->nb_sprites)
	{
		if (mlx->map->sprite_tab[i].x == wall.x && mlx->map->sprite_tab[i].y == wall.y)
		{
			mlx->map->sprite_tab[i].visible = True;
			sprite_get_ray_hits(*r, mlx, i);
			sprite_get_dist(r, mlx, v, i);
		}
		i++;
	}
	return (True);
}