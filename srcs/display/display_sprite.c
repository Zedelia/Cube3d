/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 15:01:55 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 16:51:50 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// ca devrait beaucoup changer ici

t_bool	draw_sprite(t_sprite sp, t_img img, t_mlx *mlx)
{
	t_fromto	sprite;
	int	x;
	int	y;
	int i;

	sprite.from = 0;
	sprite.to = img.width;
	if (sp.r_before.distance < sp.dist)
		sprite.from = ft_abs((sp.fst_hit.x - (int)sp.fst_hit.x) * img.width);
	if (sp.r_after.distance < sp.dist)
		sprite.to = ft_abs((int)sp.last_hit.x + 1 - sp.last_hit.x * img.width);
	y = mlx->map->r_height * 0.5 - mlx->map->r_height / sp.dist * 0.5;
	x = (tan(degrees_to_radian(60) - sp.r_before.angle) * sp.dist) *mlx->map->tile;
	i = 0;
	while (i < img.height)
	{
		while (sprite.from < sprite.to)
		{
			ft_pixel_put(mlx, x, y, ft_pixel_get_color(img, sprite.from, i));
			sprite.from++;
			x++;
		}
		y++;
		i++;
	}
	return (True);
}

t_bool	display_sprite(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < mlx->map->map_sprites)
	{
		if (mlx->map->sprite_tab[i].visible == 1)
			draw_sprite(mlx->map->sprite_tab[i], mlx->map->sprite, mlx);
		i++;
	}

	return (True);
}