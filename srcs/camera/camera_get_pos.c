/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   camera_get_pos.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 11:54:24 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 15:12:33 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int		ft_get_tile(t_map *m, int x, int y)
{
	if (x < 0 || y < 0 || x > m->nb_col || y > m->nb_lines - 1)
		return (0);
	return (m->tab[y][x]);
}

void			cam_get_pos(t_cam *cam, t_map *map)
{
	double	x;
	double	y;
	double	f;

	y = 0;
	while (y < map->nb_lines)
	{
		x = 0;
		while (x < map->nb_col)
		{
			if ((f = ft_get_tile(map, x, y)) > 10)
				break ;
			x++;
		}
		if (f > 2)
			break ;
		y++;
	}
	cam->pos.x = x + 0.5;
	cam->pos.y = y + 0.5;
	cam->rotation_angle = f;
}