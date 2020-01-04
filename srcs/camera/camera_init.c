/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   camera_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/04 12:03:43 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/04 14:33:32 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	get_camera(t_camera *cam, t_map *map)
{
	int	x;
	int	y;
	float	f;

	y = 0;
	while (y < map->map_lines)
	{
		x = 0;
		while (x < map->map_col)
		{
			if ((f = get_tile(map, x, y)) > 2)
				break ;
			x++;
		}
		if (f > 2)
			break ;
		y++;
	}
	cam->pos_x = x;
	cam->pos_y = y;
	cam->rotation_angle = f;
}

static void	get_camera_rotation_angle(t_camera *cam)
{
	cam->rotation_angle += 48;
	if (cam->rotation_angle == 78)
		cam->rotation_angle = 0;
	else if (cam->rotation_angle == 83)
		cam->rotation_angle = degrees_to_radian(180);
	else if (cam->rotation_angle == 69)
		cam->rotation_angle = degrees_to_radian(90);
	else if (cam->rotation_angle == 87)
		cam->rotation_angle = degrees_to_radian(270);
}


void		camera_init(t_mlx *mlx)
{
	get_camera(&mlx->camera, mlx->map);
	mlx->camera.turn_direction = 0;
	mlx->camera.walk_direction = 0;
	get_camera_rotation_angle(&mlx->camera);
	mlx->camera.direction.y = 1;
	rotate_vect(&mlx->camera.direction, mlx->camera.rotation_angle);
	// cam->walk_speed = 100;
	// cam->turn_speed = degrees_to_radian(35);
}