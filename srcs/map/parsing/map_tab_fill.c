/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_tab_fill.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 16:34:38 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/04 14:36:02 by mbos        ###    #+. /#+    ###.fr     */
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
	while (map->map_char[i] && h < map->map_lines)
	{
		while (map->map_char[i] && w < map->map_col)
		{
			if (ft_isincharset(map->map_char[i], "012NSEW") == 1)
			{
				map->tab[h][w] = map->map_char[i] - 48;
				w++;
			}
			i++;
		}
		w = 0;
		h++;
	}
	if (h != map->map_lines)
		return (return_false(__func__, "[FAIL] empty lines in map"));
	return (True);
}