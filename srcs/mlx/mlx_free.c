/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mlx_free.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:56:00 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 14:56:01 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void  mlx_free(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	ft_memdel((void**)&mlx);
}