/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_keydown.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 10:43:31 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 17:53:54 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int		move_keydown(int key, t_mlx *mlx)
{
	t_move	move;

	move.turn = 0;
	move.walk = 0;
	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	if (key == K_LEFT)
		move.turn--;
	if (key == K_RIGHT)
		move.turn++;
	if (key == K_UP)
		move.walk--;
	if (key == K_DOWN)
		move.walk++;
	move_apply(&move, mlx);
	rays_casting(mlx);
	display_update(mlx);
	return (0);
}