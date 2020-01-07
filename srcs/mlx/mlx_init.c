/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mlx_init.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 15:38:27 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 15:06:57 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	mlx_ft_init(t_mlx **mlx, char *file)
{
	if (!(*mlx = malloc(sizeof(t_mlx))))
		return (return_false(__func__, "[FAIL] malloc"));
	if(!(map_init(&(*mlx)->map, file)))
		return (return_false(__func__, "[FAIL] init map"));
	if (!((*mlx)->ptr = mlx_init()))
		return (return_false(__func__, "[FAIL] init mlx->ptr"));
	if(!(cam_init(*mlx)))
		return (return_false(__func__, "[FAIL] init cam"));
	(*mlx)->win = mlx_new_window((*mlx)->ptr, (*mlx)->map->r_width, (*mlx)->map->r_height, "DISPLAY");
	(*mlx)->img.ptr = mlx_new_image((*mlx)->ptr, (*mlx)->map->r_width, (*mlx)->map->r_height);
	(*mlx)->img.data = (int *)mlx_get_data_addr((*mlx)->img.ptr, &(*mlx)->img.bpp, &(*mlx)->img.size_l,
		&(*mlx)->img.endian);
	return (True);
}
