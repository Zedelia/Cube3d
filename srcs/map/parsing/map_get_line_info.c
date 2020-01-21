/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_line_info.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 16:35:23 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 13:18:06 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool	map_get_line_info(t_map *map, char *line)
{
	size_t 				index;
	t_map_parser_fct	*fonc;

	index = map_get_index(line);
	if (index == 8)
		return (True);
	fonc = g_map_parser_fct[index];
	if (!(fonc(map, line)))
		return (return_false(__func__, "[FAIL] map get info"));
	return (True);
}