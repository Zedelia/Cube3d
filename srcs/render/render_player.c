/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   render_player.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 17:31:45 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 20:03:10 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// t_bool	render_player()
// {

// }

int		move_keydown(int key, t_mlx *mlx)
{
	printf("%d\n", key);
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
		
	render_tile(mlx, mlx->map);
	printf("%f y %f x", mlx->cam.pos.y, mlx->cam.pos.x);
	draw_pix(mlx, mlx->cam.pos, 10);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	return (0);
}