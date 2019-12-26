/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_parser.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 15:07:42 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 21:35:48 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	map_parser(t_map *map)
{
	char	*line;
	int		result;
	int 	fd;

	init_map_parser_fct_tab();
	fd = open(map->map_file, O_RDONLY);
	while ((result = get_next_line(fd, &line)) == 1 && line[0] != '1')
	{
		if (!(map_get_info(map, line)))
			return (false_ret(__func__));
		ft_memdel((void**)&line);
	}
	if (!(map_get_info(map, line)))
		return (false_ret(__func__));
	ft_memdel((void**)&line);
	return (True);
}