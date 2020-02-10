/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_mini_map.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/08 11:25:20 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 16:10:45 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static t_bool	display_color_cub(t_mlx *mlx, int l, int c, int color)
{
	t_vect_int	index;
	int			tile_s;

	tile_s = mlx->map->tile / MINI_MAP_SCALE;
	index.y = 0;
	while (index.y < tile_s)
	{
		index.x = 0;
		while (index.x < tile_s)
		{
			mlx->img.data[((l * tile_s) + index.y)
					* mlx->map->r_width + (index.x + c * tile_s)] = color;
			index.x++;
		}
		index.y++;
	}
	return (True);
}

t_bool			display_mini_map(t_mlx *mlx, t_map *map)
{
	int l;
	int c;

	l = 0;
	while (l < map->nb_lines)
	{
		c = 0;
		while (c < map->nb_col)
		{
			if (map->tab[l][c] == 1)
				display_color_cub(mlx, l, c, 0xffba33);
			if (map->tab[l][c] == 0)
				display_color_cub(mlx, l, c, 0x33fff9);
			if (map->tab[l][c] == 2)
				display_color_cub(mlx, l, c, 0xff33fc);
			if (map->tab[l][c] > 2)
				display_color_cub(mlx, l, c, 0x79d4e7);
			c++;
		}
		l++;
	}
	ft_draw_pix(mlx, mlx->cam.pos, 5);
	display_rays(mlx, mlx->cam.ray_tab);
	return (True);
}
