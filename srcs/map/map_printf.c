/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_printf.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 15:08:12 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 18:39:16 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void 	map_tab_printf(t_map *map)
{
	int h;
	int w;

	h = 0;
	w = 0;
	ft_printf("\nMAP:\n");
	while (h < map->map_lines)
	{
		while (w < map->map_col)
		{
			ft_printf("%d ", map->tab[h][w]);
			w++;
		}
		ft_printf("\n");
		w = 0;
		h++;
	}
}

 void 	sprite_tab_printf(t_map *map)
{
	int i;
	t_sprite temp;

	i = 0;
	ft_printf("\nSPRITES:\n");
	while (i < map->map_sprites)
	{
		temp = map->sprite_tab[i];
		printf("\nsp x: %d | sp y: %d\ndist: %f\nvisible? %d\n", temp.x, temp.y, temp.dist, temp.visible);
		printf("sp p1: %f | sp p2: %f\n", temp.p1.x, temp.p2.x);
		printf("fst ray printed id : %d\nlast ray printed id : %d\n", temp.fst_ray_print, temp.last_ray_print );
		i++;
	}
}

// TODO supprimer les printf
void	map_printf(t_map *map)
{
	if (!map)
		return ;
	if (map->map_file)
		ft_printf(YELLOW"--- MAP_FILE: %s---\n"RESET, map->map_file);
	ft_printf("r_width: %d\nr_height: %d\nmap-col: %d\nmap-lines: %d\ncell: %d\nfloor: %d\n",
		map->r_width, map->r_height, map->map_col, map->map_lines, map->cell, map->floor);
	if (map->north.file)
		ft_printf("north: %s\n", map->north.file);
	if (map->south.file)
		ft_printf("south: %s\n", map->south.file);
	if (map->west.file)
		ft_printf("west: %s\n", map->west.file);
	if (map->east.file)
		ft_printf("east: %s\n", map->east.file);
	if (map->sprite.file)
		ft_printf("sprite: %s\n", map->sprite.file);
	if (map->map_char)
		ft_printf("map_char: %s\n", map->map_char);
	if (map->tab)
		map_tab_printf(map);
}