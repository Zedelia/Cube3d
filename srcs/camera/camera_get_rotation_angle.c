/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_get_rotation_angle.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:17:27 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 14:17:27 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	cam_get_rotation_angle(t_cam *cam)
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
