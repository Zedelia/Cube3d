/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_draw.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 11:39:49 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 14:45:12 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void		get_fst_last_printed_rays(t_sprite *sp, t_mlx *mlx)
{
	int i;

	i = sp->r_before.id;
	while (i <= sp->r_after.id)
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
	int i;

	i = sp->fst_ray_print;
	while (i <= sp->last_ray_print)
	{
		printf("%d\n", i);
		if (sp->fst_ray_print > mlx->map->r_width / 2)
			sprite_draw_column_from_start(sp, mlx, mlx->cam.ray_tab[i]);
		else if (sp->fst_ray_print <= mlx->map->r_width / 2)
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