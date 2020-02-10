/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_check_map.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 13:09:01 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 16:25:44 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static t_bool	map_check_map_size(t_map *map, t_mlx *mlx)
{
	if (map->nb_col < 3)
		return (return_false(__func__, "[FAIL] invalid map width", mlx));
	if (map->nb_lines < 3)
		return (return_false(__func__, "[FAIL] invalid map height", mlx));
	return (True);
}

static t_bool	map_check_integrity(t_maparse *lines, t_mlx *mlx)
{
	int			i;
	int			pos;
	t_maparse	*tmp;

	tmp = lines;
	pos = 0;
	while (tmp)
	{
		i = -1;
		while (tmp->line[++i])
		{
			if (ft_isincharset(tmp->line[i], MAP_INPUTS) != 1
					&& ft_isincharset(tmp->line[i], SPRITES) != 1
					&& tmp->line[i] != ' ')
				return (return_false(__func__, "[FAIL] bad char in map", mlx));
		}
		if ((occur_in_str('N', tmp->line) || occur_in_str('S', tmp->line)
				|| occur_in_str('E', tmp->line)
				|| occur_in_str('W', tmp->line)))
			pos++;
		tmp = tmp->next;
	}
	if (pos != 1)
		return (return_false(__func__, "[FAIL] invalid cam position", mlx));
	return (True);
}

static t_bool	map_check_walls(t_map *map, t_mlx *mlx)
{
	int w;
	int	h;

	w = 0;
	h = 0;
	while (w < map->nb_col)
	{
		if (map->tab[0][w] != 1)
			return (return_false(__func__, "[FAIL] map isn't closed", mlx));
		if (map->tab[map->nb_lines - 1][w] != 1)
			return (return_false(__func__, "[FAIL] map isnt closed", mlx));
		w++;
	}
	while (h < map->nb_lines)
	{
		if (map->tab[h][0] != 1)
			return (return_false(__func__, "[FAIL] map isn't closed", mlx));
		if (map->tab[h][map->nb_col - 1] != 1)
			return (return_false(__func__, "[FAIL] map isn't closed", mlx));
		h++;
	}
	return (True);
}

t_bool			map_check_map(t_map *map, t_mlx *mlx)
{
	map_check_walls(map, mlx);
	map_check_map_size(map, mlx);
	map_check_integrity(map->lines, mlx);
	return (True);
}
