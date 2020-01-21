/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_hit_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 14:06:37 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 15:59:21 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	ray_hit_sprite(t_rays r, int index_y, int index_x, t_mlx *mlx)
{
	int i;
	double dist;

	i = 0;
	while (i < mlx->map->map_sprites)
	{
		if (mlx->map->sprite_tab[i].x == index_x && mlx->map->sprite_tab[i].y == index_y)
		{
			mlx->map->sprite_tab[i].visible = True;
			dist = ft_math_dist(index_x, index_y, mlx);
			dist = dist_correct_fish_eye(r, mlx, mlx->map->sprite_tab[i].dist);
			if (dist > mlx->map->sprite_tab[i].dist)
				mlx->map->sprite_tab[i].dist = dist;
		}
		i++;
	}
	return (True);
}