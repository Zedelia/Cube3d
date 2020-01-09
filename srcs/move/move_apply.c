/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_apply.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 10:33:03 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 12:05:29 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static t_bool	there_is_a_wall_here(t_move *move, t_mlx *mlx)
{
	int x;
	int y;
// TODO gerer pbm d'arrondis et de float/int
	x = ft_floor(mlx->cam.pos.x + TURN_SPEED * move->x);
	y = ft_floor(mlx->cam.pos.y + WALK_SPEED * move->y);
	printf("cam x %f | cam y %f\n mx %f | my %f\nx %d, y %d\n\n",mlx->cam.pos.x, mlx->cam.pos.y, move->x, move->y, x, y );
	if (mlx->map->tab[y][x] !=0
			&& mlx->map->tab[y][x] < 21)
		return (True);
	return (False);
}

t_bool	move_apply(t_move *move, t_mlx *mlx)
{
	if (there_is_a_wall_here(move, mlx) == False)
	{
		mlx->cam.pos.x += TURN_SPEED * move->x;
		mlx->cam.pos.y += WALK_SPEED * move->y;
	}
	return (True);
}