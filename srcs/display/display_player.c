/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_player.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 17:31:45 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 20:09:56 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// t_bool	display_player()
// {

// }

int		move_keydown(int key, t_mlx *mlx)
{
	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	if (key == K_LEFT)
		mlx->cam.pos.x--;
		// aplpiquer changement sur une var temporaire
	if (key == K_RIGHT)
		mlx->cam.pos.x++;
	if (key == K_UP)
		mlx->cam.pos.y--;
	if (key == K_DOWN)
		mlx->cam.pos.y++;
		// checker si la nouvelle position est dans un mur, si non, appliquer sur la vraie variable


	// TODO mettre [ci dessous] [mais pas exactement reflechis lol] dans une fonction loop a appeler apres chaque update
	display_tile(mlx, mlx->map);
	draw_pix(mlx, mlx->cam.pos, 10);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);

	return (0);
}