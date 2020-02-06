/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprites_tab_init.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 11:00:40 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 16:17:01 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	sprites_tab_init(t_map *map)
{
	t_sprite 	*sprite_tab;
	int 		sp_max;

	sp_max = map->nb_sprites;
	if (!(sprite_tab = malloc(sizeof(t_sprite) * sp_max)))
		return (return_false(__func__, "[FAIL] sprite_tab malloc"));
	sprites_init(map);
	map->sprite_tab = sprite_tab;
	return (True);
}