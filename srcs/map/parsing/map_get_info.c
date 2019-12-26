/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_info.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 16:35:23 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 16:46:12 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

int		map_get_index(char *line)
{
	int	index;

	if (line[0] == 'S' && line[1] == 'O')
		line[0] = 's';
	index = ft_index(line[0], MAP_INFOS);
	return (index);
}

t_bool	map_get_info(t_map *map, char *line)
{
	int 				index;
	t_map_parser_fct	*fonc;

	index = map_get_index(line);
	fonc = g_map_parser_fct[index];
	if (!(fonc(map, line)))
		return (false_ret(__func__));
	return (True);
}