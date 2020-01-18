/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_r.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 16:48:39 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 14:09:14 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool	map_parse_r(t_map *map, char *line)
{
	size_t	i;
	// int q;

	i = 1;
	while (ft_isdigit(line[i]) == 0)
		i++;
	map->r_width = ft_atoi(&line[i]);
	if (map->r_width > WIN_WIDTH)
	{

		map->r_width = WIN_WIDTH;
	}
	while (ft_isdigit(line[i]) == 1)
		i++;
	i++;
	map->r_height = ft_atoi(&line[i]);
	if (map->r_height > WIN_HEIGHT)
		map->r_height = WIN_HEIGHT;
	return (True);
}
