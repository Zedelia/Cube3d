/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_draw_column.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 11:38:34 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 11:39:18 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool 	sprite_draw_column(t_vect inter, t_sprite *sp, t_mlx *mlx, t_rays r)
{
	double	inter_size;
	double	d_inter;
	double 	pixgetx;
	int 		y;
	t_fromto scrn_y;
	(void)sp;

	inter_size = sqrt(inter.y * inter.y + inter.x * inter.x);
// dist entre inter et position
//	r_height / dist
	// inter_norm = norm_vect(inter);
	pixgetx = (inter_size + 0.5) * mlx->map->sprite.width;
	d_inter = dist_correct_fish_eye(r, mlx, ft_math_dist(inter.x, inter.y, mlx));
	scrn_y.from = mlx->map->r_height * 0.5 - mlx->map->r_height / d_inter * 0.5;
	scrn_y.to = mlx->map->r_height * 0.5 + mlx->map->r_height / d_inter * 0.5;
	y = scrn_y.from;
	while (y < scrn_y.to)
	{
		// offset_y = (y - top) * ((double)img.height / (bottom - top));
		ft_pixel_put(mlx, r.id, y, 0x5493cf);
		y++;
	}
	return (True);
}