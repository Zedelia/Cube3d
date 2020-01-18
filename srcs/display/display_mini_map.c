/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_mini_map.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 17:45:46 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 18:24:31 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool display_color_cub(t_mlx *mlx, t_map *map, int l, int c, int color)
{
	int index_x = 0;
	int index_y = 0;
	int tile_s;
// TODO recoder cette merde, enlever les contours blancs une fois tout finit et reduire les fonctions avec pixel_put

	tile_s = map->tile / 4;

	while (index_x < tile_s - 1) // contours blancs
	{
		ft_pixel_put(mlx, (index_x + c * tile_s), ((l * tile_s) + index_y), 0xFFFFFF);
		index_x++;
	}
	index_y = 1;
	while (index_y < tile_s)
	{
		index_x = 0;
		while (index_x < tile_s - 1)
		{
			mlx->img.data[((l * tile_s) + index_y) * map->r_width + (index_x + c * tile_s)] = color;
			index_x++;
		}
		if ( index_x == tile_s - 1) // coutour blanc
		{
			mlx->img.data[((l * tile_s) + index_y) * map->r_width + (index_x + c * tile_s)] = 0xFFFFFF;
			index_x++;
		}
		index_y++;
	}
	return (True);
}


t_bool	display_mini_map(t_mlx *mlx, t_map *map)
{
	int l = 0;
	int c = 0;

	while (l < map->map_lines)
	{
		while (c < map->map_col )
		{
			if (map->tab[l][c] == 1)
				display_color_cub(mlx, map, l, c, 0xffba33);
			if (map->tab[l][c] == 0)
				display_color_cub(mlx, map, l, c, 0x33fff9);
			if (map->tab[l][c] == 2)
				display_color_cub(mlx, map, l, c, 0xff33fc);
			if (map->tab[l][c] > 2)
				display_color_cub(mlx, map, l, c, 0x4aff33);
			c++;
		}
		c = 0;
		l++;
	}
	return (True);
}