/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_get_ray_hits.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 11:03:15 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 11:08:11 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	sprite_get_ray_hits(t_rays r, t_mlx *mlx, t_vect v, int i)
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