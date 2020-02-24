/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:23:13 by mbos              #+#    #+#             */
/*   Updated: 2020/02/24 13:08:21 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void		sp_get_relativ_position(t_sprite *sp, t_mlx *mlx)
{
	sp->temp_pos.x = sp->y;
	sp->temp_pos.y = sp->x;
	sp->pos.x = sp->temp_pos.x + 0.5 - mlx->cam.pos.y;
	sp->pos.y = sp->temp_pos.y + 0.5 - mlx->cam.pos.x;
}

static void		sp_tform(t_sprite *sp, t_mlx *mlx)
{
	double		ratio;
	t_rays		mid;

	mid = mlx->cam.ray_tab[mlx->map->w / 2];
	ratio = 1.0 / (mlx->cam.plan.y * mid.x - mid.y * mlx->cam.plan.x);
	sp->tform.x = ratio * (mid.x * sp->pos.x - mid.y * sp->pos.y);
	sp->tform.y = ratio * (-mlx->cam.plan.x
			* sp->pos.x + mlx->cam.plan.y * sp->pos.y);
	sp->screenx = (int)((mlx->map->w / 2) * (1 + sp->tform.x / sp->tform.y));
	sp->h = abs((int)(mlx->map->h / sp->tform.y));
	sp->fty.from = -sp->h / 2 + mlx->map->h / 2;
	sp->fty.from = sp->fty.from < 0 ? 0 : sp->fty.from;
	sp->fty.to = sp->h / 2 + mlx->map->h / 2;
	sp->fty.to = sp->fty.to >= mlx->map->h ? mlx->map->h - 1 : sp->fty.to;
	sp->w = abs((int)(mlx->map->h / (sp->tform.y)));
	sp->ftx.from = -sp->w / 2 + sp->screenx;
	sp->ftx.from = sp->ftx.from < 0 ? 0 : sp->ftx.from;
	sp->ftx.to = sp->w / 2 + sp->screenx;
	sp->ftx.to = sp->ftx.to >= mlx->map->w ? mlx->map->w - 1 : sp->ftx.to;
}

static void		sp_draw_column(t_sprite *sp, t_mlx *mlx, int x)
{
	int		d;
	int		y;
	int		color;

	y = sp->fty.from;
	while (y < sp->fty.to)
	{
		d = (y) * 256 - mlx->map->h * 128 + sp->h * 128;
		sp->pixget.y = ((d * sp->img->height) / sp->h) / 256;
		if ((color = get_pixel_color(*(sp->img),
				sp->pixget.x, sp->pixget.y)) >= 0)
			pixel_put(mlx, x, y, color);
		y++;
	}
}

t_bool			sprite_draw(t_sprite *sp, t_mlx *mlx)
{
	int		x;

	sp_get_relativ_position(sp, mlx);
	sp_tform(sp, mlx);
	x = sp->ftx.from;
	while (x < sp->ftx.to)
	{
		if (mlx->cam.ray_tab[x].distance > sp->dist)
		{
			sp->pixget.x = (int)(256 * (x - (-sp->w / 2 + sp->screenx))
					* sp->img->width / sp->w) / 256;
			if (sp->tform.y > 0 && x < mlx->map->w && sp->tform.y < 100)
				sp_draw_column(sp, mlx, x);
		}
		x++;
	}
	sp->visible = False;
	return (True);
}
