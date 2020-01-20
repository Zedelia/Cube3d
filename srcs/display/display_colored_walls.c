/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_colored_walls.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 18:16:25 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 15:08:24 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// TODO mettre a jour les couleurs pour les textures

static int		give_wall_color(t_rays r)
{
	int north;
	int	south;
	int	west;
	int	east;

	north = 0xb140ac;
	south = 0xa5ffa7;
	west = 0xf64a8a;
	east = 0xffcf40;
	if (r.facing_up && r.wall.hz)
		return(north);
	if (r.facing_down && r.wall.hz)
		return(south);
	if (r.facing_left && r.wall.vt)
		return(west);
	if (r.facing_right && r.wall.vt)
		return(east);
	return (0);
}

t_bool	display_colored_walls(t_mlx *mlx)
{
	int x = 0;
	int y = 0;
	int	color;

	while (x < (mlx->map->r_width))
	{
	y = mlx->map->r_height / 2 - mlx->map->r_height / mlx->cam.ray_tab[x].distance / 2;
		while (y < mlx->map->r_height / 2 + mlx->map->r_height / mlx->cam.ray_tab[x].distance / 2)
		{
			color = give_wall_color(mlx->cam.ray_tab[x]);
			ft_pixel_put(mlx, x, y,color);
			y++;
		}
		x++;
	}
	return (True);
}
