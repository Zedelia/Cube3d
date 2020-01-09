/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_apply.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 10:33:03 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 15:11:09 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static t_bool	wall_here(t_move *move, t_mlx *mlx)
{
	int x;
	int y;
// TODO gerer pbm d'arrondis et de float/int
	if (move->x < 0 || move->x > mlx->map->r_width || move->y < 0 || move->y > mlx->map->r_height)
		return (True);
	x = ft_floor(mlx->cam.pos.x + 0.5 + TURN_SPEED * move->x);
	y = ft_floor(mlx->cam.pos.y + 0.5 + WALK_SPEED * move->y);
	if (mlx->map->tab[y][x] !=0
			&& mlx->map->tab[y][x] < 21)
		return (True);
	return (False);
}

t_bool	move_apply(t_move *move, t_mlx *mlx)
{
	if (wall_here(move, mlx) == False)
	{
		mlx->cam.pos.x += TURN_SPEED * move->x;
		mlx->cam.pos.y += WALK_SPEED * move->y;
	}
	return (True);
}