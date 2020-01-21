/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_free.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 18:05:39 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 19:32:19 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool		sprites_free(t_rays *r)
{
	t_sprite **temp;
	t_sprite **head;

	head = &r->sprite;
	while((*head))
	{
		temp = &(*head)->next;
		ft_memdel((void **)head);
		head = temp;
	}
	head = NULL;
	temp = NULL;
	r->sprite = NULL;
	return (True);
}

t_bool		sprites_free_all(t_mlx *mlx)
{
	int		i;

	i = 0;
	while (i < mlx->map->r_width)
	{
		if (mlx->cam.ray_tab[i].sprite != NULL)
			sprites_free(&mlx->cam.ray_tab[i]);
		i++;
	}
	return (True);
}