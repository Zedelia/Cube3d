/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   camera.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/04 12:00:00 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/04 13:55:22 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "cube3d.h"

void		camera_printf(t_camera *cam);
void		camera_init(t_mlx *mlx);

#endif