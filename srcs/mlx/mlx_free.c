/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mlx_free.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:56:00 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 13:29:30 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	mlx_free(t_mlx *mlx)
{
	if (mlx)
	{
		if (mlx->map)
			map_free(mlx->map);
		if (mlx->cam.ray_tab)
			ft_memdel((void **)&mlx->cam.ray_tab);
		ft_memdel((void**)&mlx);
	}
}
