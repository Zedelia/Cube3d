/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_draw.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 20:14:03 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 20:27:48 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// ca devrait beaucoup changer ici
t_bool	sprite_draw_col(t_sprite *sp, t_rays *r, t_mlx *mlx)
{
	int 	y;
	t_vect	start;
	int		sp_top;
	int		sp_bot;


	start.x = tan(M_PI * 0.25 - r->angle) * sp->dist;
	start.x = sp->x * mlx->map->tile - start.x;
	sp_top = mlx->map->r_height * 0.5 - mlx->map->r_height / sp->dist * 0.5;
	sp_bot =  mlx->map->r_height * 0.5 + mlx->map->r_height / sp->dist * 0.5;
	y = sp_top;
	while (y < sp_bot)
	{
		start.y =(y - sp_top) * ((double)mlx->map->sprite.height / (sp_bot - sp_top));
		ft_pixel_put(mlx, r->x_id, y, ft_pixel_get_color(mlx->map->sprite, start.x, start.y));
	}
	return (True);
}