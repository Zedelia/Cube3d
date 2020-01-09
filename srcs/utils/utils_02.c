/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_02.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 15:28:47 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 17:09:31 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	utils_there_is_a_wall_at(t_rays *r, t_vect v, t_mlx *mlx)
{
	int	index_x;
	int index_y;

	if (v.x < 0 || v.x > mlx->map->r_width || v.y < 0 || v.y > mlx->map->r_height)
		return (True);
	index_x = ft_floor(v.x / mlx->map->tile);
	index_y = ft_floor(v.y / mlx->map->tile);
	if (mlx->map->tab[index_y][index_x] != 0 && mlx->map->tab[index_y][index_x]  < 21)
	{
		if (mlx->map->tab[index_y][index_y] == 1)
			r->wall.sprite = False;
		else
			r->wall.sprite = True;
		return (True);
	}
	return (False);
}

float	utils_dist_obstacle_cam(t_vect obs, t_vect cam_pos)
{
	float dist;

	dist = sqrt((cam_pos.x - obs.x) * (cam_pos.x - obs.x)
					+ (cam_pos.y - obs.y) * (cam_pos.y - obs.y));
	return (dist);
}

void	rotate_vect(t_vect *r, float angle)
{
	float c;

	c = degrees_to_radian(angle);
	r->x = r->x * cos(c) - r->y * sin(c);
	r->y = r->x * sin(c) + r->y * cos(c);
}
