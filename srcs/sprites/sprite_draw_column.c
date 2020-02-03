/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_draw_column.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 11:38:34 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 14:51:50 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// static double	get_delta_to_center_sprite(t_mlx *mlx, t_img img, t_sprite sp)
// {
// 	double delta;

// 	sp.img_w = (sp.last_ray_print - sp.fst_ray_print) * img.width / mlx->map->r_width;
// 	delta = (sp.last_ray_print - sp.fst_ray_print) * 0.5 - sp.img_w * 0.5;
// 	return (delta);
// }

// static void	get_start_x_end(t_mlx *mlx, t_sprite *sp, t_rays r, t_utils utils)
// {
// 	sp->start = (sp->start == -1 && mlx->cam.ray_tab[(int)(r.id - utils.delta)].distance > sp->dist) ? r.id + utils.delta : sp->start;
// 	if (sp->start != -1)
// 		return ;
// 	sp->start = r.id - utils.delta;
// 	while (mlx->cam.ray_tab[(int)(sp->start)].distance < sp->dist)
// 			sp->start++;
// 	return ;
// }

// static void	get_start_x_start(t_mlx *mlx, t_sprite *sp, t_rays r, t_utils utils)
// {
// 	sp->start = (sp->start == -1 && mlx->cam.ray_tab[(int)(r.id + utils.delta)].distance > sp->dist) ? r.id + utils.delta : sp->start;
// 	if (sp->start != -1)
// 		return ;
// 	sp->start = r.id + utils.delta;
// 	while (mlx->cam.ray_tab[(int)(sp->start)].distance < sp->dist)
// 		sp->start--;

// 	return ;
// }


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
		if ((utils.color = ft_pixel_get_color(*sp->img, pixget.x, pixget.y)) >= 0)
			ft_pixel_put(mlx, r.id, utils.y, utils.color);
		else
			ft_pixel_put(mlx, r.id, utils.y, 0x00);
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
	// if (sp->start == -1 && sp->last_ray_print - sp->fst_ray_print > sp->img->width)
	// {
	// 	sp->start = sp->fst_ray_print + sp->img->width;
	// }
	pixget.x = (float)(sp->last_ray_print - r.id) * sp->img->height * utils.dist_inter / mlx->map->r_height;
	while (utils.y < scrn_y.to)
	{
		pixget.y = (float)(utils.y - scrn_y.from) * sp->img->height * utils.dist_inter / mlx->map->r_height;
		if ((utils.color = ft_pixel_get_color(*sp->img, sp->img->width - pixget.x, pixget.y)) >= 0 )
			ft_pixel_put(mlx, r.id, utils.y, utils.color);
		else
			ft_pixel_put(mlx, r.id, utils.y, 0x00);
		utils.y++;
	}
	sp->start++;
	return (True);
}
