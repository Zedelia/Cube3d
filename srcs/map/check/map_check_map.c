/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_check_map.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 13:09:01 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 16:17:23 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static t_bool	map_check_map_size(t_map *map)
{
	if (map->nb_col < 3)
		return (return_false(__func__, "[FAIL] invalid map width"));
	if (map->nb_lines < 3)
		return (return_false(__func__, "[FAIL] invalid map height"));
	return (True);
}

static t_bool	map_check_integrity(t_maparse *lines)
{
	int 		i;
	int			pos;
	t_maparse 	*tmp;

	tmp = lines;
	pos = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (ft_isincharset(tmp->line[i], MAP_INPUTS) != 1
					&& ft_isincharset(tmp->line[i], SPRITES) != 1
						&& tmp->line[i] != ' ')
				return (return_false(__func__, "[FAIL] invalid char in map"));
			i++;
		}
		if ((occur_in_str('N', tmp->line) || occur_in_str('S', tmp->line) ||
				occur_in_str('E', tmp->line) || occur_in_str('W', tmp->line)))
			pos++;
		tmp = tmp->next;
	}
	if (pos != 1)
		return (return_false(__func__, "[FAIL] invalid cam position"));
	return (True);
}

static t_bool	map_check_walls(t_map *map)
{
	int w;
	int	h;

	w = 0;
	h = 0;
	while (w < map->nb_col)
	{
		if (map->tab[0][w] != 1)
			return (return_false(__func__, "[FAIL] map isn't closed"));
		if (map->tab[map->nb_lines - 1][w] != 1)
			return (return_false(__func__, "[FAIL] map isnt closed"));
		w++;
	}
	while (h < map->nb_lines)
	{
		if (map->tab[h][0] != 1)
			return (return_false(__func__, "[FAIL] map isn't closed"));
		if (map->tab[h][map->nb_col - 1] != 1)
			return (return_false(__func__, "[FAIL] map isn't closed"));
		h++;
	}
	return (True);
}

t_bool	map_check_map(t_map *map)
{
	map_check_walls(map);
	map_check_map_size(map);
	map_check_integrity(map->lines);
	return (True);
}