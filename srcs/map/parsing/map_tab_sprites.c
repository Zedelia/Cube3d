/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_tab_sprites.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 12:59:26 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 13:25:56 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool	map_sprites_tab_init(t_map *map)
{
	t_fst_hit *sprite_tab;
	int sp_max;
	int i;

	sp_max = (map->map_col - 1) * (map->map_lines - 1);
	if (!(sprite_tab = malloc(sizeof(t_fst_hit) * sp_max)))
		return (return_false(__func__, "[FAIL] sprite_tab malloc"));
	i = 0;
	while (i < sp_max)
	{
		sprite_tab[i].x = 0;
		sprite_tab[i].y = 0;
		sprite_tab[i].dist = -1;
		i++;
	}
	map->sprite_tab = sprite_tab;
	return (True);
}