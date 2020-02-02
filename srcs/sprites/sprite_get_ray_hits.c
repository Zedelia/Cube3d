/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_get_ray_hits.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 11:03:15 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/02 21:21:14 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	sprite_get_ray_hits(t_rays r, t_mlx *mlx, int i)
{
	int temp;

	if (mlx->map->sprite_tab[i].r_fst_hit.id == -1)
	{
		mlx->map->sprite_tab[i].r_fst_hit = r;
		temp = r.id <= 1 ? 0 : r.id - 1;
		mlx->map->sprite_tab[i].r_before = mlx->cam.ray_tab[temp];
	}
	mlx->map->sprite_tab[i].r_last_hit = r;
	temp = r.id >= mlx->map->r_width - 2 ?  mlx->map->r_width - 2 : r.id + 1;
	mlx->map->sprite_tab[i].r_after = mlx->cam.ray_tab[temp];
	return (True);
}