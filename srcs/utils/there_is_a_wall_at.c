/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   there_is_a_wall_at.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 15:28:47 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 17:21:01 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	there_is_a_wall_at(t_rays *r, t_vect v, t_mlx *mlx)
{
	int	index_x;
	int index_y;

	if (v.x < 0 || v.x > mlx->map->r_width || v.y < 0 || v.y > mlx->map->r_height)
		return (True);
	index_x = ft_floor(v.x / mlx->map->tile);
	index_y = ft_floor(v.y / mlx->map->tile);
	if (mlx->map->tab[index_y][index_y] != 0)
	{
		if (mlx->map->tab[index_y][index_y] == 1)
			r->wall.sprite = False;
		else
			r->wall.sprite = True;
		return (True);
	}
	return (False);
}