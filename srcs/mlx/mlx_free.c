/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mlx_free.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 13:51:09 by melodiebos   #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 14:24:25 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool  mlx_free(t_mlx *mlx)
{
	if (!mlx)
		return (false_ret(__func__));
	mlx->ptr = NULL;
	mlx->win = NULL;
	ft_memdel((void**)&mlx);
	return (True);
}