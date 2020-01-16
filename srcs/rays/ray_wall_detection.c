/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_wall_detection.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 12:49:45 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 13:00:09 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"


t_bool	wall_detect_facing_up_left(t_rays *r, t_vect v, t_mlx *mlx)
{
	int	index_x;
	int index_y;

	index_x = v.x;
	index_y = v.y;
	index_y 
	if (v.x < 0 || v.x > mlx->map->map_col - 1 || v.y < 0 || v.y > mlx->map->map_lines - 1)
		return (True);
	if (mlx->map->tab[index_y][index_x] != 0 && mlx->map->tab[index_y][index_x]  < 21)
	{
		if (mlx->map->tab[index_y][index_x] == 1)
			r->wall.sprite = False;
		else
			r->wall.sprite = True;
		return (True);
	}
	return (False);
}

t_bool	wall_detection_facing_down_right(t_rays *r, t_vect v, t_mlx *mlx)
{

}


t_bool	ray_hits_vt_wall_at(t_rays *r, t_vect v, t_mlx *mlx)
{

	if (r->facing_left)
		return (wall_detect_facing_up_left(r, v, mlx));
	if (r->facing_right)
		return (wall_detection_facing_down_right(r, v, mlx));
	return (False);
}