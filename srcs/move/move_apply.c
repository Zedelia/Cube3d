/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_apply.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 10:33:03 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 14:37:33 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static t_bool	wall_here(t_move move, t_mlx *mlx)
{
	int x;
	int y;

	x = move.x;
	y = move.y;
	if (x < 0 || x > mlx->map->nb_col - 1 || y < 0 || y > mlx->map->nb_lines - 1)
		return (True);
	if (mlx->map->tab[y][x] == 1)
		return (True);
	return (False);
}

static t_bool to_check_hz(t_move *move, t_rays mid, t_mlx *mlx)
{
	double	delta_y;

	delta_y = WALK_SPEED * mid.y < 0 ? -0.3 : 0.3;
	move->x = mlx->cam.pos.x + WALK_SPEED * mid.x;
	move->y = mlx->cam.pos.y + WALK_SPEED * mid.y + delta_y;
	if (wall_here(*move, mlx) == False)
	{
		mlx->cam.pos.y += WALK_SPEED * mid.y;
		mlx->cam.pos.x += WALK_SPEED * mid.x;
	}
	return (True);
}

static t_bool to_check_vt(t_move *move, t_rays mid, t_mlx *mlx)
{
	double	delta_x;

	delta_x = WALK_SPEED * mid.x < 0 ? 0.3 : -0.3;
	move->x = mlx->cam.pos.x + WALK_SPEED * mid.x + delta_x;
	move->y = mlx->cam.pos.y + WALK_SPEED * mid.y;
	if (wall_here(*move, mlx) == False)
	{
		mlx->cam.pos.y += WALK_SPEED * mid.y;
		mlx->cam.pos.x += WALK_SPEED * mid.x;
	}
	return (True);
}

t_bool	move_apply(t_move *move, t_mlx *mlx)
{
	t_rays 	mid;

	mid = mlx->cam.ray_tab[mlx->map->r_width / 2];
	if (move->r)
		mlx->cam.rotation_angle = move->r * TURN_SPEED;
	else if (move->y)
	{
		move->y > 0 ? ray_rotate(&mid, 180) : ray_rotate(&mid, 0);
		to_check_hz(move, mid, mlx);
	}
	else if (move->x)
	{
		move->x > 0 ? ray_rotate(&mid, 90) : ray_rotate(&mid, -90);
		to_check_vt(move, mid, mlx);
	}
	return (True);
}