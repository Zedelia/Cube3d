/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_printf.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 15:08:12 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 20:07:14 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	map_printf(t_map *map)
{
	if (!map)
		return ;
	if (map->map_file)
		ft_printf(YELLOW"--- MAP_FILE: %s---\n"RESET, map->map_file);
	ft_printf("r_width: %d\nr_height: %d\ns_width: %d\ns_height: %d\ncell: %d\nfloor: %d\n",
		map->r_width, map->r_height, map->s_width, map->s_height, map->cell, map->floor);
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
	if (map->line_map)
		ft_printf("line_map: %s\n", map->line_map);
}