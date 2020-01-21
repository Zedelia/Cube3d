/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sprites_init.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 15:23:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 15:33:07 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	ft_sprites_init(t_map *map)
{
	int i;

	i = 0;
	while (map->sprite_tab && i < map->map_sprites)
	{
		map->sprite_tab[i].visible = False;
		map->sprite_tab[i].dist = -1;
		i++;
	}
	return (True);
}
