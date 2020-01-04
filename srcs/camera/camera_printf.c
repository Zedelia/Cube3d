/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   camera_printf.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/04 13:04:12 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/04 13:56:55 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	camera_printf(t_camera *cam)
{
	ft_printf("pos x: %d\n", (int)cam->pos_x);
	ft_printf("pos y: %d\n", (int)cam->pos_y);
	ft_printf("direc x: %d\n", (int)cam->direction.x);
	ft_printf("direc y: %d\n", (int)cam->direction.y);
	ft_printf("rotation angle: %d\n", (int)cam->rotation_angle);
}