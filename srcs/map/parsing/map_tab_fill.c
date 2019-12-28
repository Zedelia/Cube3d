/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_tab_fill.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 16:34:38 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/28 16:49:21 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool map_tab_fill(t_map *map)
{
	int w;
	int h;
	int i;

	h = 0;
	w = 0;
	i = 0;
	while (map->line_map[i] && h < map->size_h)
	{
		while (map->line_map[i] && w < map->size_w)
		{
			if (ft_isincharset(map->line_map[i], "012NSEW") == 1)
			{
				map->map_tab[h][w] = map->line_map[i] - 48;
				w++;
			}
			i++;
		}
		w = 0;
		h++;
	}
	if (h != map->size_h)
		return (return_false(__func__, "[FAIL] empty lines in map"));
	return (True);
}