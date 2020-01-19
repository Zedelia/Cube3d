/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mlx_init.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 15:38:27 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 13:25:23 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	mlx_ft_init(t_mlx **mlx, char *file)
{
	if (!(*mlx = malloc(sizeof(t_mlx))))
		return (return_false(__func__, "[FAIL] malloc"));
	if (!((*mlx)->ptr = mlx_init()))
		return (return_false(__func__, "[FAIL] init mlx->ptr"));
	map_init(&(*mlx)->map, file, *mlx);
	cam_init(*mlx);
	(*mlx)->win = mlx_new_window((*mlx)->ptr, (*mlx)->map->r_width,
					(*mlx)->map->r_height, "DISPLAY");
	(*mlx)->img.ptr = mlx_new_image((*mlx)->ptr, (*mlx)->map->r_width,
					(*mlx)->map->r_height);
	(*mlx)->img.data = (int *)mlx_get_data_addr((*mlx)->img.ptr,
					&(*mlx)->img.bpp, &(*mlx)->img.size_l, &(*mlx)->img.endian);
	return (True);
}
