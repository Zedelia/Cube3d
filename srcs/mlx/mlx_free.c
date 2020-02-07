/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mlx_free.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:56:00 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 11:45:42 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void  mlx_free(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	ft_memdel((void**)&mlx);
	map_free(&mlx->map);
	ft_memdel((void **)mlx->cam.ray_tab);
}