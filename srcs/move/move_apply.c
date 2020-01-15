/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_apply.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 10:33:03 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 16:41:34 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static t_bool	wall_here(t_move *move, t_mlx *mlx)
{
	int x;
	int y;
// TODO gerer pbm d'arrondis et de float/int
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
		mlx->cam.rotation_angle = move->x * TURN_SPEED;
		if (move->y < 0)
		{
			mlx->cam.pos.y += WALK_SPEED * mlx->cam.ray_tab[mlx->map->r_width / 2].y;
			mlx->cam.pos.x += WALK_SPEED * mlx->cam.ray_tab[mlx->map->r_width / 2].x;
		}
		else if (move->y > 0)
		{
			mlx->cam.pos.y -= WALK_SPEED * mlx->cam.ray_tab[mlx->map->r_width / 2].y;
			mlx->cam.pos.x -= WALK_SPEED * mlx->cam.ray_tab[mlx->map->r_width / 2].x;
		}
	}
	return (True);
}