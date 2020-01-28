/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_inter_line.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 11:22:51 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 11:23:53 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_vect		line_inter_line(t_line l1, t_line l2)
{
	float	tmp;
	t_vect	result;

	result.y = 0;
	result.x = 0;
	if (!(tmp = l1.a * l2.b - l2.a * l1.b))
		return (result);
	tmp = 1. / tmp;
	result.x = (l1.b * l2.c - l2.b * l1.c) * tmp;
	result.y = (l1.c * l2.a - l2.c * l1.a) * tmp;
	return (result);
}
