/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_tab_fill.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 16:34:38 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 18:54:44 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool map_tab_fill(t_map *map)
{
	int x;
	int y;
	int i;
	int s;

	y = 0;
	i = 0;
	s = 0;
	while (map->map_char[i] && y < map->map_lines)
	{
		x = 0;
		while (map->map_char[i] && x < map->map_col)
		{
			// NOTE this part has already be done in math_tab_lines
			// REVIEW to be deleted after tests

			// if (map->map_char[i] > 32
			// 	&& !ft_isincharset(map->map_char[i], MAP_INPUTS)
			// 		&& !ft_isincharset(map->map_char[i], SPRITES))
			// 	return (return_false(__func__, "[FAIL] wrong input in map"));
			if (ft_isincharset(map->map_char[i], MAP_INPUTS)
					|| ft_isincharset(map->map_char[i], SPRITES))
			{
				map->tab[y][x] = map->map_char[i] - 48;
				x++;
			}
			i++;
		}
		y++;
	}
	return (True);
}