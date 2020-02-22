/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_get_ray_hits.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/17 14:23:27 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/22 16:51:52 by mbos        ###    #+. /#+    ###.fr     */
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
	}
	mlx->map->sprite_tab[i].r_last_hit = r;
	temp = r.id >= mlx->map->r_width - 2 ? mlx->map->r_width - 2 : r.id + 1;
	return (True);
}
