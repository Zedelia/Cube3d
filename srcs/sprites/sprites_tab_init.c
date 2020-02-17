/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_tab_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:23:42 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 14:23:44 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

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
