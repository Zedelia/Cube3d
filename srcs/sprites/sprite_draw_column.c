/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_draw_column.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 11:38:34 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 17:28:37 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool 	sprite_draw_column_from_start(t_sprite *sp, t_mlx *mlx, t_rays r)
{

	t_utils		utils;
	t_vect 		pixget;
	t_fromto 	scrn_y;

	utils.dist_inter = dist_correct_fish_eye(r, mlx, ft_math_dist(r.inter_sprite.x, r.inter_sprite.y, mlx));
	scrn_y.from = mlx->map->r_height * 0.5 - mlx->map->r_height / utils.dist_inter * 0.5;
	scrn_y.to = mlx->map->r_height * 0.5 + mlx->map->r_height / utils.dist_inter * 0.5;
	utils.y = scrn_y.from;
	pixget.x = (float)(r.id - sp->fst_ray_print) * sp->img->height * utils.dist_inter / mlx->map->r_height;
	while (utils.y < scrn_y.to)
	{
		pixget.y = (float)(utils.y - scrn_y.from) * sp->img->height * utils.dist_inter / mlx->map->r_height;
		if ((utils.color = get_pixel_color(*sp->img, pixget.x, pixget.y)) >= 0)
			pixel_put(mlx, r.id, utils.y, utils.color);
		// else
		// 	pixel_put(mlx, r.id, utils.y, 0x00);
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
	pixget.x = (float)(sp->last_ray_print - r.id) * sp->img->height * utils.dist_inter / mlx->map->r_height;
	while (utils.y < scrn_y.to)
	{
		pixget.y = (float)(utils.y - scrn_y.from) * sp->img->height * utils.dist_inter / mlx->map->r_height;
		if ((utils.color = get_pixel_color(*sp->img, sp->img->width - pixget.x, pixget.y)) >= 0 )
			pixel_put(mlx, r.id, utils.y, utils.color);
		// else
		// 	pixel_put(mlx, r.id, utils.y, 0x00);
		utils.y++;
	}
	sp->start++;
	return (True);
}
