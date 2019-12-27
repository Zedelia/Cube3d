/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_exit.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 11:24:08 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 18:46:56 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int display_exit(void *mlx)
{
    (void)mlx;
    exit(0);
}

t_bool	display_exit_on_click(t_mlx *mlx)
{
	if (!(mlx_hook(mlx->win, 17, 0, &display_exit, &mlx)))
		return (return_false(__func__, "[FAIL] init exit"));
	return (True);
}
