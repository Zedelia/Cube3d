/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_draw_column.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 11:38:34 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 17:30:14 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool 	sprite_draw_column_from_start(t_sprite *sp, t_mlx *mlx, t_rays r)
{
	t_utils		utils;
	t_vect 		pixget;
	t_fromto 	scrn_y;
	double 		ratio;
	t_vect 		new;
	//double 		temp;

	t_vect tmp = (t_vect){sp->mid_ray.x, sp->mid_ray.y};
	rotate_vect(&tmp, -90);
	new = (t_vect){r.inter_sprite.x - sp->p1.x, r.inter_sprite.y - sp->p1.y};
	if (tmp.x * new.x + tmp.y * new.y <= 0)
		new = (t_vect){r.inter_sprite.x - sp->p2.x, r.inter_sprite.y - sp->p2.y};
	ratio = sqrt(new.x * new.x + new.y * new.y);
	//temp = (double)sp->img->width / sp->img->height;
	// ratio *= temp;
	//ratio += temp * 0.5;
	//printf("temp %f\n", temp);
	// printf("ratio %f\n\n", ratio);
	if (ratio < 0 || ratio >= 1)
		return (False);
	printf("p1 %f | p1 %f \n", sp->p1.x , sp->p1.y);
	printf("p2 %f | p2 %f \n", sp->p2.x , sp->p2.y);
	printf("inter %f | inter %f \n\n", r.inter_sprite.x , r.inter_sprite.y);





	utils.dist_inter = dist_correct_fish_eye(r, mlx, ft_math_dist(r.inter_sprite.x, r.inter_sprite.y, mlx));
	scrn_y.from = mlx->map->r_height * 0.5 - mlx->map->r_height / utils.dist_inter * 0.5;
	scrn_y.to = mlx->map->r_height * 0.5 + mlx->map->r_height / utils.dist_inter * 0.5;
	utils.y = scrn_y.from;
	pixget.x = ratio * sp->img->width;

	while (utils.y < scrn_y.to)
	{
		pixget.y = (float)(utils.y - scrn_y.from) * sp->img->height * utils.dist_inter / mlx->map->r_height;
		if ((utils.color = get_pixel_color(*sp->img, pixget.x, pixget.y)) >= 0)
			pixel_put(mlx, r.id, utils.y, utils.color);
		//else
		//	pixel_put(mlx, r.id, utils.y, 0x00);
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
		else
			pixel_put(mlx, r.id, utils.y, 0x00);
		utils.y++;
	}
	sp->start++;
	return (True);
}
