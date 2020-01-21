/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_wall_detection.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 12:49:45 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 12:54:24 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"


t_bool	ray_hits_vt_wall_at(t_rays *r, t_vect v, t_mlx *mlx)
{
	int	index_x;
	int index_y;

	index_x = r->facing_left ? v.x - 1 : v.x;
	index_y = v.y;
	if (v.x < 0 || v.x > mlx->map->map_col - 1 || v.y < 0 || v.y > mlx->map->map_lines - 1)
		return (True);
	if (mlx->map->tab[index_y][index_x] == 1)
		return (True);
	// if (mlx->map->tab[index_y][index_x] == 2)
	// {
	// 	r->wall.sprite = True;
	// 	r->wall.sp.x = v.x;
	// 	r->wall.sp.y = v.y;
	// 	return (False);
	// }
	return (False);
}

t_bool	ray_hits_hz_wall_at(t_rays *r, t_vect v, t_mlx *mlx)
{
	int	index_x;
	int index_y;


	index_y = r->facing_up ? v.y - 1 : v.y;
	index_x = v.x;
	if (v.x < 0 || v.x > mlx->map->map_col - 1 || v.y < 0 || v.y > mlx->map->map_lines - 1)
		return (True);
	if (mlx->map->tab[index_y][index_x] == 1)
		return (True);
	// TODO delete sprite
	// if (!r->wall.sprite && mlx->map->tab[index_y][index_x] == 2)
	// {
	// 	r->wall.sprite = True;
	// 	r->wall.sp.x = v.x;
	// 	r->wall.sp.y = v.y;
	// 	return (False);
	// }
	return (False);
}

