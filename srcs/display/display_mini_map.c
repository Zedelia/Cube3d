/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mini_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:17:56 by mbos              #+#    #+#             */
/*   Updated: 2020/02/24 12:12:03 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void		draw_minimap_square(t_mlx *mlx, t_vect v, int size_obj)
{
	int y;
	int x;
	int tile;

	tile = mlx->map->tile / MAP_SCALE;
	y = -size_obj / 2;
	while (y < size_obj / 2)
	{
		x = -size_obj / 2;
		while (x < size_obj / 2)
		{
			pixel_put(mlx, (v.x) * tile + x, (v.y) * tile + y, 0x000000);
			x++;
		}
		y++;
	}
}

static t_bool	display_color_cub(t_mlx *mlx, int l, int c, int color)
{
	t_vect_int	index;
	int			tile_s;

	tile_s = mlx->map->tile / MAP_SCALE;
	index.y = 0;
	while (index.y < tile_s)
	{
		index.x = 0;
		while (index.x < tile_s)
		{
			mlx->img.data[((l * tile_s) + index.y)
					* mlx->map->w + (index.x + c * tile_s)] = color;
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
			if (map->tab[l][c] >= 2 && map->tab[l][c] < 6)
				display_color_cub(mlx, l, c, 0xC200AD);
			if (map->tab[l][c] >= 5)
				display_color_cub(mlx, l, c, 0x33fff9);
			c++;
		}
		l++;
	}
	draw_minimap_square(mlx, mlx->cam.pos, 5);
	display_rays(mlx, mlx->cam.ray_tab);
	return (True);
}
