/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cam_printf.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/04 13:04:12 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 18:41:05 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// attention au printf a supprimer

void	cam_printf(t_cam *cam)
{
	printf("pos x: %f\n", cam->pos.x);
	printf("pos y: %f\n", cam->pos.y);
	printf("direc x: %f\n", cam->direction.x);
	printf("direc y: %f\n", cam->direction.y);
	ft_printf("rotation angle: %d\n", (int)cam->rotation_angle);
}