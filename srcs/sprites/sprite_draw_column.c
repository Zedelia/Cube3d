/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_draw_column.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 11:38:34 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 16:13:29 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool 	sprite_draw_column_fstart(t_sprite *sp, t_mlx *mlx, t_rays r)
{

	double		d_inter;
	t_vect 		pixget;
	int 		y;
	t_fromto 	scrn_y;
	int			color;


	d_inter = dist_correct_fish_eye(r, mlx, ft_math_dist(r.inter_sprite.x, r.inter_sprite.y, mlx));
	scrn_y.from = mlx->map->r_height * 0.5 - mlx->map->r_height / d_inter * 0.5;
	scrn_y.to = mlx->map->r_height * 0.5 + mlx->map->r_height / d_inter * 0.5;
	y = scrn_y.from;
	pixget.x = (float)(r.id - sp->fst_ray_print) * mlx->map->sprite.height * d_inter / mlx->map->r_height;
	while (y < scrn_y.to)
	{
		pixget.y = (float)(y - scrn_y.from) * mlx->map->sprite.height * d_inter / mlx->map->r_height;
		if ((color = ft_pixel_get_color(mlx->map->sprite, pixget.x, pixget.y)) != -1)
			ft_pixel_put(mlx, r.id, y, color);
		y++;
	}
	return (True);
}

t_bool 	sprite_draw_column_fend(t_sprite *sp, t_mlx *mlx, t_rays r)
{

	double		d_inter;
	t_fromto 	scrn_y;
	t_vect 		pixget;
	int 		y;
	int			color;


	d_inter = dist_correct_fish_eye(r, mlx, ft_math_dist(r.inter_sprite.x, r.inter_sprite.y, mlx));
	scrn_y.from = mlx->map->r_height * 0.5 - mlx->map->r_height / d_inter * 0.5;
	scrn_y.to = mlx->map->r_height * 0.5 + mlx->map->r_height / d_inter * 0.5;
	y = scrn_y.from;
	pixget.x = (float)(sp->last_ray_print - r.id) * mlx->map->sprite.height * d_inter / mlx->map->r_height;
	while (y < scrn_y.to)
	{
		pixget.y = (float)(y - scrn_y.from) * mlx->map->sprite.height * d_inter / mlx->map->r_height;
		if ((color = ft_pixel_get_color(mlx->map->sprite, pixget.x, pixget.y)) != -1)
			ft_pixel_put(mlx, r.id, y, color);
		y++;
	}
	return (True);
}
