/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mlx_exit.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 11:24:08 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/25 15:18:28 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int mlx_exit(void *mlx)
{
    (void)mlx;
    exit(0);
}

t_bool	mlx_display_exit(t_mlx mlx)
{
	if (!(mlx_hook(mlx.win, 17, 0, &mlx_exit, &mlx)))
		return (false_ret(__func__));
	return (True);
}
