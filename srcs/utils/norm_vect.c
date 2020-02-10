/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   norm_vect.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 11:32:07 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 17:21:40 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_vect	norm_vect(t_vect v)
{
	t_vect	v_norm;
	double	v_size;

	v_size = sqrt(v.y * v.y + v.x * v.x);
	v_norm.x = v.x / v_size;
	v_norm.y = v.y / v_size;
	return (v_norm);
}
