/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rotate_vect.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/04 12:53:55 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 16:28:01 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	rotate_vect(t_cam *cam, float angle)
{
	float c;
	float s;

	c = cos(degrees_to_radian(angle));
	s = sin(degrees_to_radian(angle));
	cam->direction.x = cam->pos.x * c -  s * cam->pos.y;
	cam->direction.y = cam->pos.x * s + cam->pos.y * c;
}


// attention aux pointeurs a malloc ?