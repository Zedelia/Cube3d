/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 15:01:55 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 16:00:11 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// ca devrait beaucoup changer ici

t_bool	draw_sprite(t_sprite sp, t_img img, t_mlx *mlx)
{
	int 		color;
	double 		sp_size;
	t_fromto 	x;
	t_fromto 	y;
	t_vect_int 	pixput;
	t_vect 	pixget;
	int 	start;



	sp_size = mlx->map->r_height / sp.dist;
	x.from = sp.r_before.id ;
	x.to = sp.r_after.id + 1;
	y.from = mlx->map->r_height * 0.5 - sp_size * 0.5;
	y.to = mlx->map->r_height * 0.5 + sp_size * 0.5;
	pixput.y = y.from;
	pixput.x = x.from;
	start = (sp.r_after.id == (mlx->map->r_width - 1)) ? img.width - (sp.r_after.id - sp.r_before.id) : 0;
	start = (sp.r_before.id == 0) ? img.width - sp.r_after.id  : 0;
	while (pixput.y < y.to)
	{
		pixput.x = x.from ;
		pixget.y = (pixput.y - y.from) * img.height / (y.to - y.from);
		pixget.x = start;
		while (pixput.x < x.to)
		{
			pixget.x += tan(sp.r_before.angle) * sp.dist;
			// printf("COUCOU %f\n", pixget.x);
			if((color = ft_pixel_get_color(img, pixget.x, pixget.y)) >= 0)
				ft_pixel_put(mlx, pixput.x, pixput.y, color);
			pixput.x++;
			pixget.x++;
		}
		pixput.y++;
		pixget.y++;
	}
	return (True);
}



// 	while (getpix.y < img.height)
// 	{
// 		getpix.x = sprite.from;
// 		print.x = screen.x;
// 		while (getpix.x < sprite.to)
// 		{
// 			if ((color = ft_pixel_get_color(img, getpix.x, getpix.y)) > 0)
// 				ft_pixel_put(mlx, print.x, screen.y, color );
// 			getpix.x++;
// 			print.x++;
// 		}
// 		screen.y++;
// 		getpix.y++;
// 	}
// 	// printf("sprite from %d\nsprite to %d\nx %d | y %d\nimgheigt %d\n\n", sprite.from, sprite.to,x,y, img.height);
// 	return (True);
// }

t_bool	display_sprite(t_mlx *mlx)
{
	int i;

	i = 0;
	sprite_sort_tab(mlx->map->sprite_tab, mlx->map->map_sprites);
	while (i < mlx->map->map_sprites)
	{
		if (mlx->map->sprite_tab[i].visible == 1)
			draw_sprite(mlx->map->sprite_tab[i], mlx->map->sprite, mlx);
		i++;
	}

	return (True);
}