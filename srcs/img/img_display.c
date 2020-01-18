/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   img_display.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 15:24:49 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 23:52:55 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool		img_display(t_mlx *mlx, t_img *img, char *file)
{
	img_load_xpm(mlx, file, img);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->ptr, img->width, img->height);
	return (True);
}