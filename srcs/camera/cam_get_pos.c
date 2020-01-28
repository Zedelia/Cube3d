/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cam_get_pos.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 11:54:24 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 11:55:04 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	cam_get_pos(t_cam *cam, t_map *map)
{
	double	x;
	double	y;
	double	f;

	y = 0;
	while (y < map->map_lines)
	{
		x = 0;
		while (x < map->map_col)
		{
			if ((f = ft_get_tile(map, x, y)) > 2)
				break ;
			x++;
		}
		if (f > 2)
			break ;
		y++;
	}
	cam->pos.x = x + 0.2;
	cam->pos.y = y + 0.2;
	cam->rotation_angle = f;
}