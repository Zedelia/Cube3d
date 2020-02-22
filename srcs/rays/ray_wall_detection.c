/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_wall_detection.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/17 14:22:50 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/22 17:07:15 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "../../includes/cube3d.h"

t_bool	sprite_get_dist(t_rays *r, t_mlx *mlx, t_vect v, int i)
{
	double dist;

	dist = dist_correct_fish_eye(*r, mlx, ft_math_dist(v.x, v.y, mlx));
	if (dist > mlx->map->sprite_tab[i].dist)
		mlx->map->sprite_tab[i].dist = dist;
	return (True);
}

static void	ray_hit_sprite(t_rays *r, t_vect_int wall, t_mlx *mlx, t_vect v)
{
	int i;;

	i = 0;
	while (i < mlx->map->nb_sprites)
	{
		if (mlx->map->sprite_tab[i].x == wall.x
				&& mlx->map->sprite_tab[i].y == wall.y)
		{
			sprite_get_dist(r, mlx, v, i);
			mlx->map->sprite_tab[i].visible = True;
		}
		i++;
	}
}

t_bool		ray_hits_vt_wall_at(t_rays *r, t_vect v, t_mlx *mlx)
{
	t_vect_int	index;

	index.x = r->facing_left ? v.x - 1 : v.x;
	index.y = v.y;
	if (v.x < 0 || v.x > mlx->map->nb_col - 1
			|| v.y < 0 || v.y > mlx->map->nb_lines - 1)
		return (True);
	if (mlx->map->tab[index.y][index.x] == 1)
		return (True);
	if (mlx->map->tab[index.y][index.x] >= 2
			&& mlx->map->tab[index.y][index.x] < 6)
		ray_hit_sprite(r, index, mlx, v);
	return (False);
}

t_bool		ray_hits_hz_wall_at(t_rays *r, t_vect v, t_mlx *mlx)
{
	t_vect_int	index;

	index.y = r->facing_up ? v.y - 1 : v.y;
	index.x = v.x;
	if (v.x < 0 || v.x > mlx->map->nb_col - 1
			|| v.y < 0 || v.y > mlx->map->nb_lines - 1)
		return (True);
	if (mlx->map->tab[index.y][index.x] == 1)
		return (True);
	if (mlx->map->tab[index.y][index.x] >= 2
			&& mlx->map->tab[index.y][index.x] < 6)
		ray_hit_sprite(r, index, mlx, v);
	return (False);
}
