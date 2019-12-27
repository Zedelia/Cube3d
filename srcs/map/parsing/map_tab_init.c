/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_tab_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 21:10:28 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 22:04:21 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool	map_tab_init(t_map *map)
{
	int i;

	if (!(map->map_tab = malloc(map->s_height * sizeof(*(map->map_tab)))))
		return (return_false(__func__, "[FAIL] malloc"));
	i = 0;
	while (i < map->s_height)
	{
		if (!(map->map_tab[i] = malloc(map->s_width * sizeof(int))))
			return (return_false(__func__, "[FAIL] malloc"));
		i++;
	}
	return (True);
}
