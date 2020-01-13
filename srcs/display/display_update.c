/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_update.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 11:13:22 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 16:42:07 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// TODO mettre a jour une fois le rendu done

void	display_update(t_mlx *mlx)
{
	int i;
	int y;

	display_tile(mlx, mlx->map);
	draw_pix(mlx, mlx->cam.pos, 10);
	i = 0;
	y = mlx->map->r_height / 2;
	while (i < (mlx->map->r_width))
	{
		if (mlx->cam.ray_tab[i].distance < 2)
			ft_pixel_put(mlx, i, y, 0x000000);
		i++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}