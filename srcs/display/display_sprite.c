/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:18:07 by mbos              #+#    #+#             */
/*   Updated: 2020/02/24 11:54:49 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	display_sprite(t_mlx *mlx)
{
	int i;

	i = 0;
	sprite_sort_tab(mlx->map->sprite_tab, mlx->map->nb_sprites);
	while (i < mlx->map->nb_sprites)
	{
		if (mlx->map->sprite_tab[i].visible == 1)
			sprite_draw(&mlx->map->sprite_tab[i], mlx);
		i++;
	}
	return (True);
}
