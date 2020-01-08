/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_get_distance.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 16:34:49 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 13:42:47 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	ray_get_distance(t_rays *r, t_mlx *mlx)
{
	ray_get_intersections(r, mlx);
	return (True);
}