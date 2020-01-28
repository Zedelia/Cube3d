/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprites_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 15:23:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 15:57:57 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	sprites_init(t_map *map)
{
	int i;

	i = 0;
	while (map->sprite_tab && i < map->map_sprites)
	{
		map->sprite_tab[i].visible = False;
		map->sprite_tab[i].dist = -1;
		map->sprite_tab[i].r_before.id = -1;
		map->sprite_tab[i].r_after.id = -1;
		map->sprite_tab[i].fst_ray_print = -1;
		map->sprite_tab[i].last_ray_print = -1;
		i++;
	}
	return (True);
}
