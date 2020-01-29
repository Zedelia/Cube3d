/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_draw_column.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 11:38:34 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 16:10:36 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static double	get_delta_to_center_sprite(double h, t_img img, t_sprite sp)
{
	double width;
	double delta;

	width = h * img.width / img.height;
	delta = (((sp.last_ray_print - sp.fst_ray_print) / 2) - (width / 2));
	delta = delta > 0 ? delta : -delta;
	return (delta);
}

t_bool 	sprite_draw_column_from_start(t_sprite *sp, t_mlx *mlx, t_rays r)
{

	t_utils		utils;
	t_vect 		pixget;
	t_fromto 	scrn_y;

	utils.dist_inter = dist_correct_fish_eye(r, mlx, ft_math_dist(r.inter_sprite.x, r.inter_sprite.y, mlx));
	scrn_y.from = mlx->map->r_height * 0.5 - mlx->map->r_height / utils.dist_inter * 0.5;
	scrn_y.to = mlx->map->r_height * 0.5 + mlx->map->r_height / utils.dist_inter * 0.5;
	utils.y = scrn_y.from;
	utils.delta = get_delta_to_center_sprite(scrn_y.to - scrn_y.from, mlx->map->sprite, *sp);
	sp->start = sp->start == -1 ? r.id + utils.delta : sp->start;
	pixget.x = (float)(r.id - sp->fst_ray_print) * mlx->map->sprite.height * utils.dist_inter / mlx->map->r_height;
	while (utils.y < scrn_y.to)
	{
		pixget.y = (float)(utils.y - scrn_y.from) * mlx->map->sprite.height * utils.dist_inter / mlx->map->r_height;
		if ((utils.color = ft_pixel_get_color(mlx->map->sprite, pixget.x, pixget.y)) > 0)
			ft_pixel_put(mlx, sp->start, utils.y, utils.color);
		utils.y++;
	}
	sp->start++;
	return (True);
}

t_bool 	sprite_draw_column_from_end(t_sprite *sp, t_mlx *mlx, t_rays r)
{
	t_utils 	utils;
	t_fromto 	scrn_y;
	t_vect 		pixget;

	utils.dist_inter = dist_correct_fish_eye(r, mlx, ft_math_dist(r.inter_sprite.x, r.inter_sprite.y, mlx));
	scrn_y.from = mlx->map->r_height * 0.5 - mlx->map->r_height / utils.dist_inter * 0.5;
	scrn_y.to = mlx->map->r_height * 0.5 + mlx->map->r_height / utils.dist_inter * 0.5;
	utils.y = scrn_y.from;
	utils.delta = get_delta_to_center_sprite(scrn_y.to - scrn_y.from, mlx->map->sprite, *sp);
	sp->start = sp->start == -1 ? r.id - utils.delta : sp->start;
	pixget.x = (float)(sp->last_ray_print - r.id) * mlx->map->sprite.height * utils.dist_inter / mlx->map->r_height;
	while (utils.y < scrn_y.to)
	{
		pixget.y = (float)(utils.y - scrn_y.from) * mlx->map->sprite.height * utils.dist_inter / mlx->map->r_height;
		if ((utils.color = ft_pixel_get_color(mlx->map->sprite, mlx->map->sprite.width - pixget.x, pixget.y)) > 0 )
			ft_pixel_put(mlx, sp->start, utils.y, utils.color);
		utils.y++;
	}
	sp->start++;
	return (True);
}
