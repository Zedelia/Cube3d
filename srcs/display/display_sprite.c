/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 15:01:55 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 13:28:15 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// ca devrait beaucoup changer ici

// t_bool	draw_sprite(t_sprite sp)
// {

// }

// t_bool	display_sprite(t_mlx *mlx)
// {
// 	int i;

// 	i = 0;
// 	while (i < mlx->map->map_sprites)
// 	{
// 		if (mlx->map->sprite_tab[i].visible == 1)
// 			draw_sprite(mlx->map->sprite_tab[i]);
// 		i++;
// 	}

// 	return (True);
// }













	// int y;
	// double bottom;
	// double top;
	// double offset_x;
	// double	offset_y;

	// offset_x = (r.wall.sp.x - (int)r.wall.sp.x) * img.width;
	// offset_x = ft_abs(offset_x);
	// top = map->r_height * 0.5 - map->r_height / r.wall.sp.dist * 0.5;
	// bottom = map->r_height * 0.5 + map->r_height / r.wall.sp.dist * 0.5;
	// y = top;
	// while (y < bottom)
	// {
	// 	offset_y = (y - top) * ((double)img.height / (bottom - top));
	// 	ft_pixel_put(mlx, x, y, ft_pixel_get_color(img, offset_x, offset_y));
	// 	y++;
	// }