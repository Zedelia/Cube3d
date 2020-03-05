/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:18:43 by mbos              #+#    #+#             */
/*   Updated: 2020/03/05 14:53:24 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static t_bool	map_check_colors_one(int color, t_mlx *mlx)
{
	if (color < 0)
		return (return_false(__func__, "[FAIL] invalid color", mlx));
	return (True);
}

t_bool			map_check_colors(t_map *map, t_mlx *mlx)
{
	map_check_colors_one(map->floor, mlx);
	map_check_colors_one(map->sky, mlx);
	return (True);
}
