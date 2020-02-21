/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:23:13 by mbos              #+#    #+#             */
/*   Updated: 2020/02/21 16:31:15 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void			sp_get_info(t_sprite *sp, t_mlx *mlx)
{
	double temp;
	temp = sp->x;
	sp->x = sp->y ;
	sp->y  = temp;
	sp->relapos.x = (int)(sp->x + 0.5 - mlx->cam.pos.x);
	sp->relapos.y = (int)(sp->y + 0.5 - mlx->cam.pos.y);
	printf("%f | %f\n",sp->relapos.x, sp->relapos.y);
	sp->dist = sqrt(sp->relapos.x * sp->relapos.x + sp->relapos.y * sp->relapos.y);
}

void			sp_transform(t_sprite *sp, t_mlx *mlx)
{
	double		invdet;
	t_rays		mid;


	mid = mlx->cam.ray_tab[mlx->map->r_width / 2];
	invdet = 1.0 / (mlx->cam.plane.y * mid.x - mid.y * mlx->cam.plane.x);
	sp->transform.x = invdet * (mid.x * sp->relapos.x - mid.y * sp->relapos.y);
	sp->transform.y = invdet * (-mlx->cam.plane.x * sp->relapos.x + mlx->cam.plane.y * sp->relapos.y);
	sp->screenx = (int)((mlx->map->r_width  / 2) * (1 + sp->transform.x / sp->transform.y));
	sp->h = abs((int)(mlx->map->r_height / (sp->transform.y)));
    sp->fty.from = -sp->h / 2 + mlx->map->r_height / 2;
    sp->fty.from = sp->fty.from < 0 ? 0 : sp->fty.from;
    sp->fty.to = sp->h / 2 + mlx->map->r_height / 2;
    sp->fty.to = sp->fty.to >= mlx->map->r_height ? mlx->map->r_height - 1 : sp->fty.to;
    sp->w = abs((int)(mlx->map->r_height / (sp->transform.y)));
    sp->ftx.from = -sp->w / 2 + sp->screenx ;
    sp->ftx.from = sp->ftx.from < 0 ? 0 : sp->ftx.from;
    sp->ftx.to = sp->w / 2 + sp->screenx;
    sp->ftx.to = sp->ftx.to >= mlx->map->r_width ? mlx->map->r_width - 1 : sp->ftx.to;
}

void			sp_draw_column(t_sprite *sp, t_mlx *mlx, int x)
{
	int			d;
	int 		y;
	int 		color;

	y = sp->fty.from;
	while (y < sp->fty.to)
	{
		d = (y) * 256 - mlx->map->r_height * 128 + sp->h * 128;
		sp->pixget.y = ((d * sp->img->height) / sp->h) / 256;
		color = sp->img->data[sp->pixget.y * sp->img->width + sp->pixget.x];
		pixel_put(mlx, x, y, color);
		y++;
	}

}

t_bool			sprite_draw(t_sprite *sp, t_mlx *mlx)
{
	int 		x;

	sp_get_info(sp, mlx);
	sp_transform(sp, mlx);
	x = sp->ftx.from;
	while (x < sp->ftx.to)
	{
		sp->pixget.x = (int)(256 * (x - (-sp->w / 2 + sp->screenx)) * sp->img->width / sp->w) / 256;
		if (sp->transform.y > 0 && x < mlx->map->r_width && sp->transform.y < 100)
			sp_draw_column(sp, mlx, x);
		x++;
	}
	return (True);
}
