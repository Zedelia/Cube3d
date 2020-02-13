/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_get_line_seg.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 11:21:21 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 13:41:41 by mbos        ###    #+. /#+    ###.fr     */
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

void	sprite_get_line_seg(t_sprite *sp, t_mlx *mlx)
{
	t_rays line_ray;

	sprite_find_mid_ray(sp, mlx);
	line_ray.x = sp->mid_ray.x;
	line_ray.y = sp->mid_ray.y;
	ray_rotate(&line_ray, 90);
	sp->line_vect.x = line_ray.x;
	sp->line_vect.y = line_ray.y;
	sp->line_eq.a = line_ray.y;
	sp->line_eq.b = -line_ray.x;
	sp->line_eq.c = line_ray.x * (sp->y + 0.5) - line_ray.y * (sp->x + 0.5);
	sp->line_norm_v = norm_vect(sp->line_vect);
	sp->p1.x = sp->x + 0.5 + sp->line_norm_v.x * 0.5;
	sp->p1.y = sp->y + 0.5 + sp->line_norm_v.y * 0.5;
	sp->p2.x = sp->x + 0.5 - sp->line_norm_v.x * 0.5;
	sp->p2.y = sp->y + 0.5 - sp->line_norm_v.y * 0.5;
}
