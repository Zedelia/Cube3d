/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprites_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/17 14:23:36 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/22 17:12:03 by mbos        ###    #+. /#+    ###.fr     */
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

t_bool		sprites_tab_init(t_map *map, t_mlx *mlx)
{
	t_sprite	*sprite_tab;
	int			sp_max;

	sp_max = map->nb_sprites;
	if (!(sprite_tab = malloc(sizeof(t_sprite) * sp_max)))
		return (return_false(__func__, "[FAIL] sprite_tab malloc", mlx));
	sprites_init(map);
	map->sprite_tab = sprite_tab;
	return (True);
}
