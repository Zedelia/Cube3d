/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprites_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 15:23:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 16:17:01 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	sprites_init(t_map *map)
{
	int i;

	i = 0;
	while (map->sprite_tab && i < map->nb_sprites)
	{
		map->sprite_tab[i].visible = False;
		map->sprite_tab[i].dist = -1;
		map->sprite_tab[i].r_fst_hit.id = -1;
		map->sprite_tab[i].r_last_hit.id = -1;
		map->sprite_tab[i].fst_ray_print = -1;
		map->sprite_tab[i].last_ray_print = -1;
		map->sprite_tab[i].start = -1;
		i++;
	}
	return (True);
}
