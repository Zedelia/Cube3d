/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_tile.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/03 17:07:57 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/03 18:32:08 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool display_color_cub(t_mlx *mlx, t_map *map, int l, int c, int color)
{
	int index_x = 0;
	int index_y = 0;
	int tile_size;

	tile_size = map->map_col > map->map_lines ? map->r_width/map->map_col : map->r_width/map->map_lines;

	while (index_y < tile_size)
	{
		index_x = 0;
		while (index_x < tile_size)
		{
			mlx->img.data[((l * tile_size) + index_y) * map->r_width + (index_x + c * tile_size)] = color;
			index_x++;
		}
		index_y++;
	}
	return (True);
}


t_bool	display_tile(t_mlx *mlx, t_map *map)
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