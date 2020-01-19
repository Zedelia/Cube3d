/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_tab_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 21:10:28 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 13:05:30 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static int		math_tab_lines(t_map *map, char *map_char)
{
	int i;
	int j;

	j = 0;
	i = ft_strlen(map_char) - 1;
	while (i > -1)
	{
		if (map_char[i] > 32 && !ft_isincharset(map_char[i], "012NSEW"))
			return (return_false(__func__, "[FAIL] wrong input in map"));
		if (ft_isincharset(map->map_char[i], "012NSEW") == 1)
			j++;;
		i--;
	}
	return (j / map->map_col);
}

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
	map_tab_fill(map);
	return (True);
}
