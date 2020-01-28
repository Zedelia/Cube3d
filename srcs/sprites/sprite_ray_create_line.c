/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_ray_create_line.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 11:25:12 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 11:25:41 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	sprite_ray_create_line(t_rays *r, t_mlx *mlx)
{
	r->line_eq.a = r->y;
	r->line_eq.b = -r->x;
	r->line_eq.c = r->x * (mlx->cam.pos.y + 0.5) - r->y * (mlx->cam.pos.x + 0.5);
}
