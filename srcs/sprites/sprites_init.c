/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprites_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/17 14:23:36 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/22 16:54:08 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "../../includes/cube3d.h"

t_bool	sprites_init(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map->sprite_tab && i < map->nb_sprites)
	{
		map->sprite_tab[i].visible = False;
		map->sprite_tab[i].dist = -1;
		map->sprite_tab[i].r_fst_hit.id = -1;
		map->sprite_tab[i].r_last_hit.id = -1;
		i++;
	}
	return (True);
}
