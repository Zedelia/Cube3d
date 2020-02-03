/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_draw.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 11:39:49 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 12:52:08 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void			sprite_ray_create_line(t_rays *r, t_mlx *mlx)
{
	r->line_eq.a = r->y;
	r->line_eq.b = -r->x;
	r->line_eq.c = r->x * (mlx->cam.pos.y + 0.5) - r->y * (mlx->cam.pos.x + 0.5);
}

static void		get_fst_last_printed_rays(t_sprite *sp, t_mlx *mlx)
{
	int i;

	i = sp->r_fst_hit.id;
	while (i <= sp->r_last_hit.id)
	{
		if (mlx->cam.ray_tab[i].distance > sp->dist)
		{
			sprite_ray_create_line(&mlx->cam.ray_tab[i], mlx);
			mlx->cam.ray_tab[i].inter_sprite = line_inter_line(sp->line_eq, mlx->cam.ray_tab[i].line_eq);
			if (is_inter_in_seg(mlx->cam.ray_tab[i].inter_sprite, sp) == True)
			{
				if (sp->fst_ray_print == -1)
					sp->fst_ray_print = mlx->cam.ray_tab[i].id;
				sp->last_ray_print = mlx->cam.ray_tab[i].id;
			}
		}
		i++;
	}
}

static t_bool	sprite_draw_columns(t_sprite *sp, t_mlx *mlx)
{
	int		i;
	double 	end;
	double mid;

	mid = sp->fst_ray_print + (sp->last_ray_print-sp->fst_ray_print) * 0.5;
	i = sp->fst_ray_print;
	end = sp->last_ray_print;
	while (i <= end)
	{
		if (sp->r_before.distance < sp->dist)
			sprite_draw_column_from_end(sp, mlx, mlx->cam.ray_tab[i]);
		else if (sp->r_after.distance < sp->dist)
			sprite_draw_column_from_start(sp, mlx, mlx->cam.ray_tab[i]);
		else if (mid > mlx->map->r_width / 2)
			sprite_draw_column_from_start(sp, mlx, mlx->cam.ray_tab[i]);
		else if (mid <= mlx->map->r_width / 2)
			sprite_draw_column_from_end(sp, mlx, mlx->cam.ray_tab[i]);
		i++;
	}
	return (True);
}

t_bool	sprite_draw(t_sprite *sp, t_mlx *mlx)
{
	sprite_get_line_seg(sp, mlx);
	get_fst_last_printed_rays(sp, mlx);
	sprite_draw_columns(sp, mlx);
	return (True);
}
