/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:21:48 by mbos              #+#    #+#             */
/*   Updated: 2020/02/24 12:12:11 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	display_bonus(t_mlx *mlx, t_img img)
{
	t_vect	put;
	t_vect	get;
	t_vect	ratio;
	int		color;

	ratio.x = (double)img.width / (double)mlx->map->w;
	ratio.y = (double)img.height / (double)mlx->map->h;
	put.x = 0;
	get.x = 0;
	while (put.x < mlx->map->w - 1)
	{
		put.y = 0;
		get.y = 0;
		while (put.y < mlx->map->h)
		{
			if ((color = get_pixel_color(img, (int)get.x, (int)get.y)) > 0)
				pixel_put(mlx, put.x, put.y, color);
			put.y++;
			get.y += ratio.y;
		}
		put.x++;
		get.x += ratio.x;
	}
}
