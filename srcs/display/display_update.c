/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_update.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 11:13:22 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 14:06:31 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	display_update(t_mlx *mlx)
{
	display_roof(mlx);
	display_floor(mlx);
	rays_casting(mlx);
	display_textured_walls(mlx);
	display_mini_map(mlx, mlx->map);
	ft_draw_pix(mlx, mlx->cam.pos, 10);
	display_rays(mlx, mlx->cam.ray_tab);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}



