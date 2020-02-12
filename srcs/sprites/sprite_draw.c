/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_draw.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 11:39:49 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 17:11:22 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void		sprite_ray_create_line(t_rays *r, t_mlx *mlx)
{
	r->line_eq.a = r->y / r->x;
	r->line_eq.b = -1;
	r->line_eq.c = mlx->cam.pos.y - r->line_eq.a * mlx->cam.pos.x;
}

static t_bool	sprite_draw_columns(t_sprite *sp, t_mlx *mlx)
{
	int		i;
	double	end;
	double	mid;

	mid = sp->fst_ray_print + (sp->last_ray_print - sp->fst_ray_print) * 0.5;
	i = -1;
	end = sp->last_ray_print;
	while (i < mlx->map->r_width)
	{
		sprite_ray_create_line(&mlx->cam.ray_tab[i], mlx);
		mlx->cam.ray_tab[i].inter_sprite = line_inter_line(sp->line_eq,
					mlx->cam.ray_tab[i].line_eq);
		if (sp->dist < mlx->cam.ray_tab[i].distance)
			sprite_draw_column_from_start(sp, mlx, mlx->cam.ray_tab[i]);
		i++;
	}
	return (True);
}

t_bool			sprite_draw(t_sprite *sp, t_mlx *mlx)
{
	sprite_get_line_seg(sp, mlx);
	sprite_draw_columns(sp, mlx);
	return (True);
}
