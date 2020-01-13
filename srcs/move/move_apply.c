/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_apply.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 10:33:03 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 17:55:22 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static t_bool	wall_here(t_move *move, t_mlx *mlx)
{
	int x;
	int y;
// TODO gerer pbm d'arrondis et de float/int
	x = mlx->cam.pos.x + 0.5 + TURN_SPEED * move->x;
	y = mlx->cam.pos.y + 0.5 + WALK_SPEED * move->y;
	if (x < 0 || x > mlx->map->r_width || y < 0 || y > mlx->map->r_height)
		return (True);
	if (mlx->map->tab[y][x] !=0
			&& mlx->map->tab[y][x] < 21)
		return (True);
	return (False);
}

t_bool	move_apply(t_move *move, t_mlx *mlx)
{
	if (wall_here(move, mlx) == False)
	{
		mlx->cam.rotation_angle += TURN_SPEED;
		mlx->cam.pos.x += WALK_SPEED * move->x;
		mlx->cam.pos.y += WALK_SPEED * move->y;
	}
	return (True);
}