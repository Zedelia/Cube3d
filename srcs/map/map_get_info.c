/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_info.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 16:35:23 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 18:48:19 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

size_t		map_get_index(char *line)
{
	int	index;
	index = 0;
	if (line && line[0] == 'S' && line[1] == 'O')
		line[0] = 's';
	if (line)
		return(ft_index(line[0], MAP_INFOS));
	return (-1);
}

t_bool	map_get_info(t_map *map, char *line)
{
	size_t 				index;
	t_map_parser_fct	*fonc;

	index = map_get_index(line);
	if (index == 9)
		return (True);
	fonc = g_map_parser_fct[index];
	if (!(fonc(map, line)))
		return (return_false(__func__, "[FAIL] map get info"));
	return (True);
}