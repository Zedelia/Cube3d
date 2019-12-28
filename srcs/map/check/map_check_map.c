/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_check_map.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 13:09:01 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/28 13:53:07 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static t_bool	map_check_map_size(t_map *map)
{
	if (map->size_w < 3)
		return (return_false(__func__, "[FAIL] invalid map width"));
	if (map->size_h < 3)
		return (return_false(__func__, "[FAIL] invalid map height"));
	return (True);
}

static t_bool	map_check_integrity(char *line_map)
{
	int i;

	i = 0;
	while (line_map[i])
	{
		if (ft_isincharset(line_map[i], "012NSEW ") != 1)
			return (return_false(__func__, "[FAIL] invalid char in map"));
		i++;
	}
	if ((occur_in_str('N', line_map) + occur_in_str('S', line_map) +
			occur_in_str('E', line_map) + occur_in_str('W', line_map)) != 1)
			return (return_false(__func__, "[FAIL] invalid camera position"));
	return (True);
}

static t_bool	map_check_walls(t_map *map)
{
	int w;
	int	h;

	w = 0;
	h = 0;
	while (w < map->size_w)
	{
		if (map->map_tab[0][w] != 1)
			return (return_false(__func__, "[FAIL] map isn't closed on top"));
		if (map->map_tab[map->size_h - 1][w] != 1)
			return (return_false(__func__, "[FAIL] map isnt closed on bottom"));
		w++;
	}
	while (h < map->size_h)
	{
		if (map->map_tab[h][0] != 1)
			return (return_false(__func__, "[FAIL] map isn't closed on left"));
		if (map->map_tab[h][map->size_w - 1] != 1)
			return (return_false(__func__, "[FAIL] map isn't closed on right"));
		h++;
	}
	return (True);
}

t_bool	map_check_map(t_map *map)
{
	if (!(map_check_map_size(map)))
		return (return_false(__func__, "[FAIL] invalid map size"));
	if (!(map_check_integrity(map->line_map)))
		return (return_false(__func__, "[FAIL] invalid map"));
	if (!(map_check_walls(map)))
		return (return_false(__func__, "[FAIL] map isn't closed"));
	return (True);
}