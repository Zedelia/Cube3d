/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 15:01:55 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 12:54:42 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// ca devrait beaucoup changer ici

t_bool	display_sprite(t_rays r, t_map *map, t_img img, t_mlx *mlx, int x)
{

	return (True);
}













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