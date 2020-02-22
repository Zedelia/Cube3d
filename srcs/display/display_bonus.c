/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_bonus.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/22 21:21:48 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/22 23:00:59 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	display_life(t_mlx *mlx)
{
	t_vect	img;
	t_vect	text;
	t_vect	ratio;
	int 	color;

	color = 0;
	ratio.x = (double)mlx->map->life.width / (double)mlx->map->W;
	ratio.y = (double)mlx->map->life.height / (double)mlx->map->H;
	img.x = 0;
	text.x = 0;
	while (img.x < mlx->map->W - 1)
	{
		img.y = 0;
		text.y = 0;
		while (img.y < mlx->map->H)
		{
			if ((color = get_pixel_color(mlx->map->life, (int)text.x, (int)text.y)) > 0)
					pixel_put(mlx, img.x, img.y, color);
			img.y++;
			text.y += ratio.y;
		}
		img.x++;
		text.x += ratio.x;
	}
}

void	display_frame(t_mlx *mlx)
{
	t_vect	img;
	t_vect	text;
	t_vect	ratio;
	int 	color;

	color = 0;
	ratio.x = (double)mlx->map->frame.width / (double)mlx->map->W;
	ratio.y = (double)mlx->map->frame.height / (double)mlx->map->H;
	img.x = 0;
	text.x = 0;
	while (img.x < mlx->map->W - 1)
	{
		img.y = 0;
		text.y = 0;
		while (img.y < mlx->map->H)
		{
			if ((color = get_pixel_color(mlx->map->frame, (int)text.x, (int)text.y)) > 0)
					pixel_put(mlx, img.x, img.y, color);
			img.y++;
			text.y += ratio.y;
		}
		img.x++;
		text.x += ratio.x;
	}
}
