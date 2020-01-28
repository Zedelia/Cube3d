/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_draw.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 11:39:49 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 11:40:16 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	is_inter_in_seg(t_vect inter, t_sprite *sp)
{
	return (((inter.x <= sp->p2.x && inter.x >= sp->p1.x) 		\
				|| (inter.x <= sp->p1.x && inter.x >= sp->p2.x)) 	\
			&& ((inter.y <= sp->p2.y && inter.y >= sp->p1.y) 		\
				|| (inter.y <= sp->p1.y && inter.y >= sp->p2.y)));
}

t_bool	sprite_draw(t_sprite *sp, t_mlx *mlx)
{
	t_vect	inter;
	int i;

	sprite_get_line_seg(sp, mlx);
	i = sp->r_before.id;
	while (i < sp->r_after.id)
	{
		sprite_ray_create_line(&mlx->cam.ray_tab[i], mlx);
		inter = line_inter_line(sp->line_eq, mlx->cam.ray_tab[i].line_eq);
		if (is_inter_in_seg(inter, sp) == True)
			sprite_draw_column(inter, sp, mlx, mlx->cam.ray_tab[i]);
		i++;
	}
	return (True);
}