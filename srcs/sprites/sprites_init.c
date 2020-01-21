/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprites_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:57:50 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 18:52:29 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void		sprite_add_one(t_rays *r, t_sprite *new)
{
	t_sprite *temp;

	temp = r->sprite;
	if (temp)
	{
		r->sprite = new;
		new->next = temp;
	}
	else
		r->sprite = new;
}

t_bool	sprites_init(t_rays *r, t_pos pos, t_mlx *mlx)
{
	t_sprite 	*sprite;
	double		dist;

	if (!(sprite = malloc(sizeof(t_sprite))))
		return (return_false(__func__, "[FAIL] sprite malloc"));
	dist = ft_math_dist(pos.x, pos.y, mlx);
	dist = dist_correct_fish_eye(*r, mlx, dist);
	sprite->dist = dist;
	sprite->x = pos.x;
	sprite->y = pos.y;
	sprite->next = NULL;
	sprite_add_one(r, sprite);
	return (True);
}
