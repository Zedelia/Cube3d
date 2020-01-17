/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_apply.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 10:33:03 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 12:03:29 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static t_bool	wall_here(t_move *move, t_mlx *mlx)
{
	int x;
	int y;

	x = mlx->cam.pos.x + WALK_SPEED * move->x;
	y = mlx->cam.pos.y + WALK_SPEED * move->y;
	if (x < 0 || x > mlx->map->map_col - 1 || y < 0 || y > mlx->map->map_lines - 1)
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
		printf("\n\nmy %f mx %f mr %f\n", move->y, move->x, move->r);
		mlx->cam.rotation_angle = move->r * TURN_SPEED;
		mlx->cam.pos.y += WALK_SPEED * move->y;
		mlx->cam.pos.x += WALK_SPEED * move->x;
	}
	return (True);
}