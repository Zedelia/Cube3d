/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays_get_distance.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 16:34:49 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 17:44:27 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	ray_get_distance(t_rays *r, t_mlx *mlx)
{
	ray_get_first_intersections(r, mlx);
	ray_get_steps(r, mlx);

}