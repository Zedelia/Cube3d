/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_printf.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 15:08:12 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 16:04:10 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	map_printf(t_map *map)
{
	if (!map)
		return ;
	if (map->map_file)
		ft_printf(YELLOW"north: %s\n"RESET, map->map_file);
	ft_printf("r_width: %d\nr_height: %d\ns_width: %d\ns_height: %d\ncell: %d\n floor: %d",
		map->r_width, map->r_height, map->s_width, map->s_height, map->cell, map->floor);
	if (map->text_north)
		ft_printf("north: %s\n", map->text_north);
	if (map->text_south)
		ft_printf("north: %s\n", map->text_south);
	if (map->text_west)
		ft_printf("north: %s\n", map->text_west);
	if (map->text_east)
		ft_printf("north: %s\n", map->text_east);
	if (map->text_sprite)
		ft_printf("north: %s\n", map->text_sprite);
}