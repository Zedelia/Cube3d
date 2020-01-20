/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_keydown.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 10:43:31 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 18:24:48 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int		move_keydown(int key, t_mlx *mlx)
{
	t_move	move;

	move.x = 0;
	move.y = 0;
	move.r = 0;
	// TODO tableau d'int avec les key dedans deja remplis (static)
	// remplacer key = par tab[i]
	// creer une enum
	// ajouter la fonction pour la pression du bouton
	// mlx_hook(mlx->win, 2, 0, &move_keydown, mlx); ==> key release qui remet a zero les valeurs du tableau
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
	if (key == K_TURN_LEFT)
		move.r--;
	if (key == K_TURN_RIGHT)
		move.r++;
	move_apply(&move, mlx);
	display_update(mlx);
	return (0);
}