/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_walls.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/18 15:56:48 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 16:20:32 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static t_bool	walls_cases(t_rays temp, t_mlx *mlx, int x)
{
	if (temp.facing_up && temp.wall.hz)
		display_wall_hz(temp, mlx->map, mlx->map->north, mlx, x);
	else if (temp.facing_down && temp.wall.hz)
		display_wall_hz(temp, mlx->map, mlx->map->south, mlx, x);
	else if (temp.facing_left && temp.wall.vt)
		display_wall_vt(temp, mlx->map, mlx->map->west, mlx, x);
	else if (temp.facing_right && temp.wall.vt)
		display_wall_vt(temp, mlx->map, mlx->map->east, mlx, x);
	return (True);
}

t_bool	 display_walls(t_mlx *mlx)
{
	int x;
	t_rays temp;

	x = 0;
	while (x < mlx->map->r_width)
	{
		temp = mlx->cam.ray_tab[x];
		walls_cases(temp, mlx, x);
		x++;
	}
	display_sprite(mlx);
	return (True);
}