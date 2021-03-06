/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:23:55 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 14:23:56 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int			color_to_int(t_color c)
{
	return (((c.r & 0xff) << 16) + ((c.g & 0xff) << 8) + (c.b & 0xff));
}

t_color		int_to_color(int n)
{
	t_color	a;

	a.r = (n & 0x00FF0000) >> 16;
	a.g = (n & 0x0000FF00) >> 8;
	a.b = (n & 0x000000FF);
	return (a);
}

int			shade_color(int color, double ratio)
{
	t_color	rgb;
	int		new_color;

	rgb = int_to_color(color);
	if ((rgb.r = ((-rgb.r * ratio) + rgb.r)) < 0)
		rgb.r = 0;
	if ((rgb.g = ((-rgb.g * ratio) + rgb.g)) < 0)
		rgb.g = 0;
	if ((rgb.b = ((-rgb.b * ratio) + rgb.b)) < 0)
		rgb.b = 0;
	new_color = color_to_int(rgb);
	return (new_color);
}
