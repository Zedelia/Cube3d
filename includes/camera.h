/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cam.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/04 12:00:00 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/04 13:55:22 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef cam_H
# define cam_H

#include "cube3d.h"

void		cam_printf(t_cam *cam);
t_bool		cam_init(t_mlx *mlx);
void		cam_get_rotation_angle(t_cam *cam);
void		cam_get_pos(t_cam *cam, t_map *map);

#endif