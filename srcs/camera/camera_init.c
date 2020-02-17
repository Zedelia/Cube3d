/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:17:33 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 14:17:34 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool		cam_init(t_mlx *mlx)
{
	cam_get_pos(&mlx->cam, mlx->map);
	cam_get_rotation_angle(&mlx->cam);
	mlx->cam.direction.y = 1;
	rotate_vect(&mlx->cam.direction, mlx->cam.rotation_angle);
	rays_tab_init(mlx);
	rays_casting(mlx);
	return (True);
}
