/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 14:52:00 by mbos              #+#    #+#             */
/*   Updated: 2020/02/24 12:12:03 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void			map_free_tab(t_map *map)
{
	int i;

	i = 0;
	if (map->tab)
	{
		while (i < map->nb_lines)
		{
			ft_memdel((void**)&(map->tab[i]));
			i++;
		}
		ft_memdel((void**)&map->tab);
	}
}

static void			map_free_all_text(t_map *map)
{
	ft_memdel((void**)&map->west.file);
	ft_memdel((void**)&map->east.file);
	ft_memdel((void**)&map->north.file);
	ft_memdel((void**)&map->south.file);
	ft_memdel((void**)&map->sprite.file);
	ft_memdel((void**)&map->sp1.file);
	ft_memdel((void**)&map->sp1.file);
	ft_memdel((void**)&map->sp1.file);
	ft_memdel((void**)&map->life.file);
	ft_memdel((void**)&map->frame.file);
}

static void			map_free_lines(t_maparse **lines)
{
	t_maparse	*tmp;

	while (*lines)
	{
		tmp = (*lines)->next;
		ft_memdel((void **)&((*lines)->line));
		*lines = tmp;
	}
	lines = NULL;
}

void				map_free(t_map *map)
{
	if (map)
	{
		if (map->tab)
			map_free_tab(map);
		map_free_all_text(map);
		if (map->lines)
			map_free_lines(&(map)->lines);
		ft_memdel((void **)&(map)->sprite_tab);
		ft_memdel((void **)&(map));
	}
}
