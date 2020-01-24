/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_sort_tab.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 11:13:52 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 11:17:44 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	sprite_sort_tab(t_sprite *tab, int size)
{
	int i;
	int j;
	t_sprite temp[size];

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		while (j < size - 1)
		{
			if (tab[j].dist > tab[j + 1].dist)
			{
				temp[j] = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp[j];
			}
			j++;
		}
		j = 0;
		i++;
	}
}