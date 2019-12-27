/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   img_load_xpm.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 11:03:50 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 18:23:13 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool		img_load_xpm(t_mlx *mlx, char *file, t_img *img)
{
	if (!(img->ptr = mlx_xpm_file_to_image(mlx->ptr, file, 			\
								&img->width, &img->height)))
		return (return_false(__func__, "init mlx->ptr [FAIL]"));
	if (!(img->data = (int *)mlx_get_data_addr(img->ptr, &img->bpp, 	\
								&img->size_l, &img->endian)))
		return (return_false(__func__, "init mlx->data [FAIL]"));
	return (True);
}