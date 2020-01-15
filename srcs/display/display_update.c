/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_update.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 11:13:22 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 18:44:17 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// TODO mettre a jour une fois le rendu done

void	display_walls(t_mlx *mlx)
{
	int x = 0;
	int y = 0;
	while (x < (mlx->map->r_width))
	{
	y = mlx->map->r_height / 2 - mlx->map->r_height / mlx->cam.ray_tab[x].distance / 2;
		while (y < mlx->map->r_height / 2 + mlx->map->r_height / mlx->cam.ray_tab[x].distance / 2)
		{
			ft_pixel_put(mlx, x, y, 0xFFFFFF);
			y++;
		}
		x++;
	}
}
void	display_update(t_mlx *mlx)
{
	rays_casting(mlx);
	display_tile(mlx, mlx->map);
	// display_walls(mlx);
	draw_pix(mlx, mlx->cam.pos, 10);
	display_rays(mlx, mlx->cam.ray_tab);
	rays_printf_tab(mlx, mlx->cam.ray_tab);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}



