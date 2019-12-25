/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mlx_ft_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 11:01:28 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/25 12:19:56 by mbos        ###    #+. /#+    ###.fr     */
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
	(*mlx)->img = NULL;
	return (True);
}