/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_exit.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/17 14:17:45 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/23 14:23:44 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int			display_exit(void *mlx)
{
	exit(EXIT_SUCCESS);
	mlx_free(mlx);
}

t_bool		display_exit_on_click(t_mlx *mlx)
{
	if (!(mlx_hook(mlx->win, 17, 0, &display_exit, &mlx)))
		return (return_false(__func__, "[FAIL] exit", mlx));
	return (True);
}
