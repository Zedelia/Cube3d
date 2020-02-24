/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:24:06 by mbos              #+#    #+#             */
/*   Updated: 2020/02/24 12:12:11 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	pixel_put(t_mlx *mlx, int x, int y, int color)
{
	if (x >= mlx->map->w || y >= mlx->map->h || x < 0 || y < 0)
		return ;
	mlx->img.data[y * mlx->map->w + x] = color;
}

int		get_pixel_color(t_img img, int x, int y)
{
	int color;

	if (x >= img.width || y >= img.height || x < 0 || y < 0)
		return (-1);
	color = img.data[y * img.width + x];
	if ((color >> 24) & 0xff)
	{
		return (-1);
	}
	return (color);
}

int		get_correct_color(t_img img, t_mlx *mlx, t_vect offset, int y)
{
	int color;

	if ((color = get_pixel_color(img, offset.x, offset.y)) == -1)
		return (get_pixel_color(mlx->img, mlx->map->w / 2, y));
	return (color);
}
