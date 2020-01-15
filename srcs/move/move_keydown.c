/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_keydown.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 10:43:31 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 16:02:15 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int		move_keydown(int key, t_mlx *mlx)
{
	t_move	move;

	move.x = 0;
	move.y = 0;
	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	if (key == K_LEFT)
		move.x--;
	if (key == K_RIGHT)
		move.x++;
	if (key == K_UP)
		move.y--;
	if (key == K_DOWN)
		move.y++;
	move_apply(&move, mlx);
	display_update(mlx);
	return (0);
}