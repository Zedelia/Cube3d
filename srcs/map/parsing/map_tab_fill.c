/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_tab_fill.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 16:34:38 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 13:30:03 by mbos        ###    #+. /#+    ###.fr     */
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
	i = 0;
	while (map->map_char[i] && h < map->map_lines)
	{
		w = 0;
		while (map->map_char[i] && w < map->map_col)
		{
			if (map->map_char[i] > 32 && !ft_isincharset(map->map_char[i], "012NSEW"))
				return (return_false(__func__, "[FAIL] wrong input in map"));
			if (ft_isincharset(map->map_char[i], "012NSEW") == 1)
				map->tab[h][w++] = map->map_char[i] - 48;
			i++;
		}
		h++;
	}
	return (True);
}