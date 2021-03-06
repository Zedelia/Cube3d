/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:21:02 by mbos              #+#    #+#             */
/*   Updated: 2020/03/02 13:10:50 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	mlx_ft_init(t_mlx **mlx, char *file)
{
	if (!(*mlx = malloc(sizeof(t_mlx))))
		return (return_false(__func__, "[FAIL] malloc", *mlx));
	if (!((*mlx)->ptr = mlx_init()))
		return (return_false(__func__, "[FAIL] init mlx->ptr", *mlx));
	(*mlx)->map = NULL;
	(*mlx)->cam.ray_tab = NULL;
	(*mlx)->bonus1 = False;
	(*mlx)->bonus2 = False;
	map_init(&(*mlx)->map, file, *mlx);
	cam_init(*mlx);
	(*mlx)->win = mlx_new_window((*mlx)->ptr, (*mlx)->map->w,
					(*mlx)->map->h, "Cube3d");
	(*mlx)->img.ptr = mlx_new_image((*mlx)->ptr, (*mlx)->map->w,
					(*mlx)->map->h);
	(*mlx)->img.data = (int *)mlx_get_data_addr((*mlx)->img.ptr,
					&(*mlx)->img.bpp, &(*mlx)->img.size_l, &(*mlx)->img.endian);
	return (True);
}
