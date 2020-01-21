/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_free.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 18:05:39 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 18:53:18 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool		sprites_free(t_sprite **sprite)
{
	t_sprite *temp;

	while(*sprite)
	{
		temp = (*sprite)->next;
		ft_memdel((void *)sprite);
		*sprite = temp;
	}
	sprite = NULL;
	return (True);
}
