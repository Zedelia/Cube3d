/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cam_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/04 12:03:43 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 17:09:31 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	get_cam(t_cam *cam, t_map *map)
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

static void	get_cam_rotation_angle(t_cam *cam)
{
	cam->rotation_angle += 48;
	if (cam->rotation_angle == 'N')
		cam->rotation_angle = 0;
	else if (cam->rotation_angle == 'S')
		cam->rotation_angle = 180;
	else if (cam->rotation_angle == 'E')
		cam->rotation_angle = 90;
	else if (cam->rotation_angle == 'W')
		cam->rotation_angle = 270;
}


t_bool		cam_init(t_mlx *mlx)
{
	get_cam(&mlx->cam, mlx->map);
	get_cam_rotation_angle(&mlx->cam);
	mlx->cam.direction.y = 1;
	rotate_vect(&mlx->cam.direction, mlx->cam.rotation_angle); // ici on trouve le vecteur directionnel initial
	rays_tab_init(mlx);
	rays_casting(mlx);
	return (True);
}