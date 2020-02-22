/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   camera_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/17 14:17:33 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/22 17:31:34 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "../../includes/cube3d.h"

t_bool		cam_init(t_mlx *mlx)
{
	cam_get_pos(&mlx->cam, mlx->map);
	mlx->cam.plan.y = 0;
	mlx->cam.plan.x = 0.66;
	// vect_rotate(&mlx->cam.plan, mlx->cam.rotation_angle);
	cam_get_rotation_angle(&mlx->cam);
	// mlx->cam.direction.y = 1;
	// vect_rotate(&mlx->cam.direction, mlx->cam.rotation_angle);
	rays_tab_init(mlx);
	rays_casting(mlx);
	return (True);
}
