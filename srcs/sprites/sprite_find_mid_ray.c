/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_find_mid_ray.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 11:26:25 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 11:26:44 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	sprite_find_mid_ray(t_sprite *sp, t_mlx *mlx)
{
	t_rays mid_r;

	mid_r.x = mlx->cam.pos.x - sp->x;
	mid_r.y = mlx->cam.pos.y - sp->y;
	sp->mid_ray = mid_r;
}
