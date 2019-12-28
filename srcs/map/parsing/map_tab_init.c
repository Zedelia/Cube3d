/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_tab_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 21:10:28 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/28 13:27:55 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool	map_tab_init(t_map *map)
{
	int i;

	if (!(map->map_tab = malloc(map->size_h * sizeof(*(map->map_tab)))))
		return (return_false(__func__, "[FAIL] malloc"));
	i = 0;
	while (i < map->size_h)
	{
		if (!(map->map_tab[i] = malloc(map->size_w * sizeof(int))))
			return (return_false(__func__, "[FAIL] malloc"));
		i++;
	}
	return (True);
}
