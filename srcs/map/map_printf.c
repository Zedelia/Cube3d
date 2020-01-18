/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_printf.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 15:08:12 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 14:12:46 by mbos        ###    #+. /#+    ###.fr     */
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
// TODO supprimer les printf
void	map_printf(t_map *map)
{
	if (!map)
		return ;
	if (map->map_file)
		ft_printf(YELLOW"--- MAP_FILE: %s---\n"RESET, map->map_file);
	ft_printf("r_width: %d\nr_height: %d\nmap-col: %d\nmap-lines: %d\ncell: %d\nfloor: %d\n",
		map->r_width, map->r_height, map->map_col, map->map_lines, map->cell, map->floor);
	if (map->text_north)
		ft_printf("north: %s\n", map->text_north);
	if (map->text_south)
		ft_printf("south: %s\n", map->text_south);
	if (map->text_west)
		ft_printf("west: %s\n", map->text_west);
	if (map->text_east)
		ft_printf("east: %s\n", map->text_east);
	if (map->text_sprite)
		ft_printf("sprite: %s\n", map->text_sprite);
	if (map->map_char)
		ft_printf("map_char: %s\n", map->map_char);
	if (map->tab)
		map_tab_printf(map);
}