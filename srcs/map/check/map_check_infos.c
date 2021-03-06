/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_infos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:18:48 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 14:18:50 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool	map_check_infos(t_map *map, t_mlx *mlx)
{
	map_check_texture(map, mlx);
	map_check_colors(map, mlx);
	map_check_resolution(map, mlx);
	map_check_map(map, mlx);
	return (True);
}
