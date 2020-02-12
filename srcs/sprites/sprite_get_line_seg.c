/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_get_line_seg.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 11:21:21 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 14:32:33 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	sprite_find_mid_ray(t_sprite *sp, t_mlx *mlx)
{
	t_rays mid_r;

	mid_r.x = mlx->cam.pos.x - sp->x - 0.5;
	mid_r.y = mlx->cam.pos.y - sp->y - 0.5;
	sp->mid_ray = mid_r;
}

double 	scale_product(t_vect u, t_vect v)
{
	return (u.x * v.x + u.y * v.y);
}
double	oriented_angle(t_vect u, t_vect v)
{
	double	tmp;

	tmp = scale_product(u, v);
	if (tmp < -1)
		tmp = -1;
	else if (tmp > 1)
		tmp = 1;
	rotate_vect(&u, 90);
	return (scale_product(u, v) < 0 ? -acos(tmp) : acos(tmp));
}


void	sprite_get_line_seg(t_sprite *sp, t_mlx *mlx)
{
	double angle;
	t_vect v1;
	t_vect v2;
	t_vect n;

	sprite_find_mid_ray(sp, mlx);
	sp->p1 = (t_vect){sp->x, sp->y + 0.5};
	sp->p2 = (t_vect){sp->x + 1, sp->y + 0.5};
	v1 = (t_vect){-0.5, 0};
	v2 = (t_vect){0.5, 0};
	n = (t_vect){0, 0.5};
	angle = oriented_angle(n, (t_vect){sp->mid_ray.x, sp->mid_ray.y});
	v1 = (t_vect){v1.x * cos(angle) - v1.y * sin(angle), v1.x * sin(angle) + v1.y * cos(angle)};
	v2 = (t_vect){v2.x * cos(angle) - v2.y * sin(angle), v2.x * sin(angle) + v2.y * cos(angle)};
	sp->p1 = (t_vect){sp->x + 0.5 + v1.x, sp->y + 0.5 + v1.y};
	sp->p2 = (t_vect){sp->x + 0.5 + v2.x, sp->y + 0.5 + v2.y};


	sp->line_eq.a = (sp->p2.y - sp->p1.y) / (sp->p2.x - sp->p1.x);
	sp->line_eq.b = -1;
	sp->line_eq.c = sp->p1.y - sp->line_eq.a * sp->p1.x;

}
