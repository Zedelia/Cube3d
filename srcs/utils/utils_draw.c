/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_draw.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 17:21:31 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 11:29:02 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int		ft_get_tile(t_map *m, int x, int y)
{
	if (x < 0 || y < 0 || x > m->map_col || y > m->map_lines - 1)
		return (0);
	return (m->tab[y][x]);
}

void	ft_draw_pix(t_mlx *mlx, t_vect v, int size_obj)
{
	int y = -size_obj / 2;
	int x;
	int tile = mlx->map->tile / 4;

	while (y < size_obj / 2)
	{
		x = -size_obj / 2;
		while (x < size_obj / 2)
		{
			ft_pixel_put(mlx, (v.x) * tile + x, (v.y) * tile + y, 0x000000);
			x++;
		}
		y++;
	}
}

