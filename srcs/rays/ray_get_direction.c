/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_get_direction.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 20:20:22 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 19:11:55 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ray_get_direction(t_rays *ray)
{
	if (ray->x > 0)
		ray->facing_right = True;
	else if (ray->x < 0 || ray->x == 0)
		ray->facing_right = False;
	if (ray->x != 0)
		ray->facing_left = !ray->facing_right;
	else
		ray->facing_left = False;
	if (ray->y > 0)
		ray->facing_down = True;
	else if (ray->y < 0 || ray->y == 0)
		ray->facing_down = False;
	if (ray->y != 0)
		ray->facing_up = !ray->facing_down;
	else
		ray->facing_up = False;
}
