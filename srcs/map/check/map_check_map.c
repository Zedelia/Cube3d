/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_check_map.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 13:09:01 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/03 16:52:03 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static t_bool	map_check_map_size(t_map *map)
{
	if (map->map_col < 3)
		return (return_false(__func__, "[FAIL] invalid map width"));
	if (map->map_lines < 3)
		return (return_false(__func__, "[FAIL] invalid map height"));
	return (True);
}

static t_bool	map_check_integrity(char *map_char)
{
	int i;

	i = 0;
	while (map_char[i])
	{
		if (ft_isincharset(map_char[i], "012NSEW ") != 1)
			return (return_false(__func__, "[FAIL] invalid char in map"));
		i++;
	}
	if ((occur_in_str('N', map_char) + occur_in_str('S', map_char) +
			occur_in_str('E', map_char) + occur_in_str('W', map_char)) != 1)
			return (return_false(__func__, "[FAIL] invalid camera position"));
	return (True);
}

static t_bool	map_check_walls(t_map *map)
{
	int w;
	int	h;

	w = 0;
	h = 0;
	while (w < map->map_col)
	{
		if (map->tab[0][w] != 1)
			return (return_false(__func__, "[FAIL] map isn't closed on top"));
		if (map->tab[map->map_lines - 1][w] != 1)
			return (return_false(__func__, "[FAIL] map isnt closed on bottom"));
		w++;
	}
	while (h < map->map_lines)
	{
		if (map->tab[h][0] != 1)
			return (return_false(__func__, "[FAIL] map isn't closed on left"));
		if (map->tab[h][map->map_col - 1] != 1)
			return (return_false(__func__, "[FAIL] map isn't closed on right"));
		h++;
	}
	return (True);
}

t_bool	map_check_map(t_map *map)
{
	if (!(map_check_map_size(map)))
		return (return_false(__func__, "[FAIL] invalid map size"));
	if (!(map_check_integrity(map->map_char)))
		return (return_false(__func__, "[FAIL] invalid map"));
	if (!(map_check_walls(map)))
		return (return_false(__func__, "[FAIL] map isn't closed"));
	return (True);
}