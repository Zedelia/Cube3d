/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_tab_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 21:10:28 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 14:27:00 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
	map->map_sprites = sp;
	map->map_col = col_max;
}

t_bool	map_tab_init(t_map *map)
{
	int i;

	map_tab_get_col_and_sp(map);
	if (!(map->tab = malloc(map->map_lines * sizeof(*(map->tab)))))
		return (return_false(__func__, "[FAIL] malloc"));
	i = 0;
	while (i < map->map_lines)
	{
		if (!(map->tab[i] = malloc(map->map_col * sizeof(int))))
			return (return_false(__func__, "[FAIL] malloc"));
		i++;
	}
	sprites_tab_init(map);
	map_tabs_fill(map);
	return (True);
}
