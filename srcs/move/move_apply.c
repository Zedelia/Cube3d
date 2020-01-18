/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_apply.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 10:33:03 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 12:45:22 by mbos        ###    #+. /#+    ###.fr     */
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
	printf("\n y check %d - x check %d\n", y, x);
	if (x < 0 || x > mlx->map->map_col - 1 || y < 0 || y > mlx->map->map_lines - 1)
		return (True);
	if (mlx->map->tab[y][x] !=0	&& mlx->map->tab[y][x] < 21)
		return (True);
	return (False);
}

static t_bool to_check_hz(t_move *move, t_rays mid, t_mlx *mlx)
{
	double	delta;
	t_bool	go_up;

	go_up = (((mid.facing_up && move->y < 0) || (mid.facing_down && move->y > 0)) && !move->vt);
	delta = go_up ? -0.5 : 0;
	printf("GO UP %d\n", go_up);
	move->x = mlx->cam.pos.x + WALK_SPEED * mid.x;
	move->y = mlx->cam.pos.y + WALK_SPEED * mid.y + delta;
	if (wall_here(*move, mlx) == False)
	{
		mlx->cam.pos.y += WALK_SPEED * mid.y;
		mlx->cam.pos.x += WALK_SPEED * mid.x;
	}
	return (True);
}

static t_bool to_check_vt(t_move *move, t_rays mid, t_mlx *mlx)
{
	double	delta;
	t_bool	go_left;

	go_left = (((mid.facing_left && move->x < 0) || (mid.facing_right && move->x < 0)) && move->vt);
	delta = go_left ? -0.5 : 0;
	move->x = mlx->cam.pos.x + WALK_SPEED * mid.x + delta ;
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
		move->vt = False;
		move->y > 0 ? ray_rotate(&mid, 180) : ray_rotate(&mid, 0);
		to_check_hz(move, mid, mlx);
	}
	else if (move->x)
	{
		move->vt = True;
		move->x > 0 ? ray_rotate(&mid, 90) : ray_rotate(&mid, -90);
		to_check_vt(move, mid, mlx);
	}
	return (True);
}