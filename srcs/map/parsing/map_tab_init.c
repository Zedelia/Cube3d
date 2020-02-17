/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:20:02 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 14:20:03 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static void		map_tab_get_col_and_sp(t_map *map)
{
	int			col_max;
	int			sp;
	t_maparse	*tmp;

	tmp = map->lines;
	col_max = map->lines->columns;
	sp = tmp->sp;
	while (tmp)
	{
		col_max = tmp->columns > col_max ? tmp->columns : col_max;
		sp += tmp->sp;
		tmp = tmp->next;
	}
	map->nb_sprites = sp;
	map->nb_col = col_max;
}

t_bool			map_tab_init(t_map *map, t_mlx *mlx)
{
	int i;

	map_tab_get_col_and_sp(map);
	if (!(map->tab = malloc(map->nb_lines * sizeof(*(map->tab)))))
		return (return_false(__func__, "[FAIL] malloc", mlx));
	i = 0;
	while (i < map->nb_lines)
	{
		if (!(map->tab[i] = malloc(map->nb_col * sizeof(int))))
			return (return_false(__func__, "[FAIL] malloc", mlx));
		i++;
	}
	sprites_tab_init(map, mlx);
	map_tabs_fill(map, mlx);
	return (True);
}
