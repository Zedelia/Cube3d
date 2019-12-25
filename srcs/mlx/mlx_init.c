/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mlx_init.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 15:38:27 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/25 17:17:00 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	mlx_ft_init(t_mlx	**mlx)
{
	if (!(*mlx = malloc(sizeof(t_mlx))))
		return (false_ret(__func__));
	if (!((*mlx)->ptr = mlx_init()))
		return (false_ret(__func__));
	(*mlx)->win = mlx_new_window((*mlx)->ptr, WIN_WIDTH, WIN_HEIGHT, "DISPLAY");
	(*mlx)->img.ptr = mlx_new_image((*mlx)->ptr, WIN_WIDTH, WIN_HEIGHT);
	(*mlx)->img.data = (int *)mlx_get_data_addr((*mlx)->img.ptr, &(*mlx)->img.bpp, &(*mlx)->img.size_l,
		&(*mlx)->img.endian);
	return (True);
}
