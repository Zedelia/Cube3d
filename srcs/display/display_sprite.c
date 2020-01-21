/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 15:01:55 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 18:44:04 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// ca devrait beaucoup changer ici
// t_bool	draw_sprite(t_sprite sprite, t_mlx *mlx, int x)
// {
// 	int 	y;
// 	double	angle;
// 	int		start_px;
// 	int		sp_top;
// 	int		sp_bot;
// 	int		offset_x;

// 	angle = M_PI * 0.25 - sprite.ray_hit_angle;
// 	start_px = tan(angle) * sprite.dist;
// 	start_px = sprite.x * mlx->map->tile - start_px;
// 	sp_top = mlx->map->r_height * 0.5 - mlx->map->r_height / sprite.dist * 0.5;
// 	sp_bot =  mlx->map->r_height * 0.5 + mlx->map->r_height / sprite.dist * 0.5;
// 	y = sp_top;
// 	while ()
// 	while (y < sp_bot)
// 	{
// 		ft_pixel_put(mlx, x, y, ft_pixel_get_color(mlx->map->sprite, offset_x, offset_y));
// 	}

// }

// t_bool	display_sprite(t_mlx *mlx)
// {
// 	int i;

// 	i = 0;
// 	ft_sort_sprite(mlx->map->sprite_tab, mlx->map->map_sprites);
// 	while (i < mlx->map->map_sprites)
// 	{
// 		if (mlx->map->sprite_tab[i].visible == 1)
// 			draw_sprite();
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