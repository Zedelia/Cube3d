/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rotate_vect.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/04 12:53:55 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/04 14:33:15 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	rotate_vect(t_vect *vect, float angle)
{
	float x;
	float c;
	float s;

	x = vect->x;
	c = cos(angle);
	s = sin(angle);
	vect->x = vect->x * c - vect->y * s;
	vect->y = x * s + vect->y * c;
}


// attention aux pointeurs a malloc ?