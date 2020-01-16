/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_02.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 15:28:47 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 18:09:16 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"


int 	arrondi(double nombre)
{
	return (nombre + 0.5);
}

double	utils_dist_obstacle_cam(t_vect obs, t_vect cam_pos)
{
	double dist;

	dist = sqrt((cam_pos.x - obs.x) * (cam_pos.x - obs.x)
					+ (cam_pos.y - obs.y) * (cam_pos.y - obs.y));
	return (dist);
}

void	rotate_vect(t_vect *r, double angle)
{
	double c;

	c = degrees_to_radian(angle);
	r->x = r->x * cos(c) - r->y * sin(c);
	r->y = r->x * sin(c) + r->y * cos(c);
}
