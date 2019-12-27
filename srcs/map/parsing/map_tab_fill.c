/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_tab_fill.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 21:10:20 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 22:04:20 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

void	map_tab_fill(t_map *map)
{
	int w;
	int h;
	int i;

	h = 0;
	w = 0;
	i = 0;
	while (h < map->s_height)
	{
		while (w < map->s_width)
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
}