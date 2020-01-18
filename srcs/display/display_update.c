/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_update.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 11:13:22 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 14:11:29 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	display_update(t_mlx *mlx)
{
	// TODO a supprimer une fois que la map d'adaptera
	int x = 0;
	int y = 0;
	while (x < mlx->map->r_width)
	{
		y = 0;
		while (y < mlx->map->r_height )
		{
			ft_pixel_put(mlx, x, y, 0x8074F9 );
			y++;
		}
		x++;
	}
	rays_casting(mlx);
	display_walls(mlx);
	display_mini_map(mlx, mlx->map);
	draw_pix(mlx, mlx->cam.pos, 10);
	display_rays(mlx, mlx->cam.ray_tab);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}



