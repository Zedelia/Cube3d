/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_sprites_tab_init.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 12:59:26 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 15:33:20 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool	map_sprites_tab_init(t_map *map)
{
	t_sprite 	*sprite_tab;
	int 		sp_max;

	sp_max = map->map_sprites;
	if (!(sprite_tab = malloc(sizeof(t_sprite) * sp_max)))
		return (return_false(__func__, "[FAIL] sprite_tab malloc"));
	ft_sprites_init(map);
	map->sprite_tab = sprite_tab;
	return (True);
}