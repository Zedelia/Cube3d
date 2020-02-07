/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_draw.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 17:21:31 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 15:11:31 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_draw_pix(t_mlx *mlx, t_vect v, int size_obj)
{
	int y;
	int x;
	int tile;

	tile = mlx->map->tile / MINI_MAP_SCALE;
	y = -size_obj / 2;
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
