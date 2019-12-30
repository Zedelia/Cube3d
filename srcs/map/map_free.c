/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_free.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:52:00 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/28 18:55:49 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	map_free_tab(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size_h)
	{
		ft_memdel((void**)&(map->map_tab[i]));
		i++;
	}
	ft_memdel((void**)&map->map_tab);
}

void		map_free(t_map **map)
{
	map_free_tab(*map);
	ft_memdel((void **)&(*map)->map_file);
	ft_memdel((void **)&(*map)->text_north);
	ft_memdel((void **)&(*map)->text_south);
	ft_memdel((void **)&(*map)->text_west);
	ft_memdel((void **)&(*map)->text_east);
	ft_memdel((void **)&(*map)->text_sprite);
	ft_memdel((void **)&(*map)->line_map);
}