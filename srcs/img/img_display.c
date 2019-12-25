/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   img_display.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 15:24:49 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/25 15:28:00 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	img_display(t_mlx *mlx, t_img *img)
{
	img_load_xpm(mlx, "dragon.xpm", img);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->ptr, img->width, img->height);
	return (True);
}