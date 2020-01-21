/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_tab_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 21:10:28 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 13:31:25 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool	map_tab_init(t_map *map)
{
	int i;

	if (!(map->tab = malloc(map->map_lines * sizeof(*(map->tab)))))
		return (return_false(__func__, "[FAIL] malloc"));
	i = 0;
	map->map_lines = math_tab_lines(map, map->map_char);
	while (i < map->map_lines)
	{
		if (!(map->tab[i] = malloc(map->map_col * sizeof(int))))
			return (return_false(__func__, "[FAIL] malloc"));
		i++;
	}
	map_sprites_tab_init(map);
	map_tabs_fill(map);
	return (True);
}
