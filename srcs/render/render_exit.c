/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   render_exit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 17:45:33 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 17:45:37 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int render_exit(void *mlx)
{
    (void)mlx;
    exit(0);
}

t_bool	render_exit_on_click(t_mlx *mlx)
{
	if (!(mlx_hook(mlx->win, 17, 0, &render_exit, &mlx)))
		return (return_false(__func__, "[FAIL] exit"));
	return (True);
}
