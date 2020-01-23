/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_hit_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 14:06:37 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 17:00:39 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// TODO REVIEW Par pitie fais des objets sprite et reoganise tout ca

static t_bool	sprite_get_hits(t_rays r, t_mlx *mlx, t_vect v, int i)
{
	if (mlx->map->sprite_tab[i].r_before.id == -1)
	{
		mlx->map->sprite_tab[i].r_before = r;
		mlx->map->sprite_tab[i].fst_hit.x = v.x;
		mlx->map->sprite_tab[i].fst_hit.x = v.y;
	}
	mlx->map->sprite_tab[i].r_after = r;
	mlx->map->sprite_tab[i].last_hit.x = v.x;
	mlx->map->sprite_tab[i].last_hit.y = v.y;
	return (True);
}

static t_bool	sprite_get_dist(t_rays *r, t_mlx *mlx, t_vect v, int i)
{
	double dist;

	dist = dist_correct_fish_eye(*r, mlx, ft_math_dist(v.x, v.y, mlx));
	if (dist > mlx->map->sprite_tab[i].dist)
		mlx->map->sprite_tab[i].dist = dist;
	return (True);
}

t_bool	ray_hit_sprite(t_rays *r, t_vect_int wall, t_mlx *mlx, t_vect v)
{
	int i;

	i = 0;
	while (i < mlx->map->map_sprites)
	{
		if (mlx->map->sprite_tab[i].x == wall.x && mlx->map->sprite_tab[i].y == wall.y)
		{
			mlx->map->sprite_tab[i].visible = True;
			sprite_get_hits(*r, mlx, v, i);
			sprite_get_dist(r, mlx, v, i);
		}
		i++;
	}
	return (True);
}