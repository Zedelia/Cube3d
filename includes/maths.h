/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   maths.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/31 10:14:37 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 10:16:14 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

#include "cube3d.h"

double		degrees_to_radian(double angle_in_degrees);
int			color_to_int(t_color c);
t_color		int_to_color(int n);

#endif