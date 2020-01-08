/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   distance_obstacle_cam.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 16:47:02 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 16:55:59 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "../../includes/cube3d.h"

float	distance_obstacle_cam(t_vect obs, t_vect cam_pos)
{
	float dist;

	dist = sqrt((cam_pos.x - obs.x) * (cam_pos.x - obs.x)
					+ (cam_pos.y - obs.y) * (cam_pos.y - obs.y));
	return (dist);
}
