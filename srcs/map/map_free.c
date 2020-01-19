/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_free.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:52:00 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 13:35:46 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	map_free_tab(t_map *map)
{
	int i;

	i = 0;
	while (i < map->map_lines)
	{
		ft_memdel((void**)&(map->tab[i]));
		i++;
	}
	ft_memdel((void**)&map->tab);
}

void		map_free(t_map **map)
{
	map_free_tab(*map);
	ft_memdel((void **)&(*map)->map_file);
	// TODO function free image
	// img_free((*map)->north)
	// img_free((*map)->north)
	// img_free((*map)->north)
	// img_free((*map)->north)

	ft_memdel((void **)&(*map)->map_char);
}