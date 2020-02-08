/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_wall_detection.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 12:49:45 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/08 11:53:22 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	ray_hit_sprite(t_rays *r, t_vect_int wall, t_mlx *mlx, t_vect v)
{
	int i;

	i = 0;
	while (i < mlx->map->nb_sprites)
	{
		if (mlx->map->sprite_tab[i].x == wall.x
				&& mlx->map->sprite_tab[i].y == wall.y)
		{
			mlx->map->sprite_tab[i].visible = True;
			sprite_get_ray_hits(*r, mlx, i);
			sprite_get_dist(r, mlx, v, i);
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
	if (mlx->map->tab[index.y][index.x] >=2
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
	if (mlx->map->tab[index.y][index.x] >=2
			&& mlx->map->tab[index.y][index.x] < 6)
		ray_hit_sprite(r, index, mlx, v);
	return (False);
}

