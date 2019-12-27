/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_parser.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 15:07:42 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 22:06:22 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static t_bool	map_parsing_info(t_map *map, int fd, char *line)
{
	while ((get_next_line(fd, &line)) == 1 && line[0] != '1')
	{
		if (!(map_get_info(map, line)))
			return (return_false(__func__, NULL));
		ft_memdel((void**)&line);
	}
	map->s_width = occurence_in_charset('1', line);
	if (!(map_get_map_line(map, fd, line)))
		return (return_false(__func__, "[FAIL] map's mapping parsing"));
	if (!(map_tab_init(map)))
		return (return_false(__func__, "[FAIL] init map two dimensional tab"));
	map_tab_fill(map);
	return (True);
}

t_bool	map_parser(t_map *map)
{
	char	*line;
	int 	fd;

	line = NULL;
	init_map_parser_fct_tab();
	fd = open(map->map_file, O_RDONLY);
	if (!(map_parsing_info(map, fd, line)))
		return (return_false(__func__, "[FAIL] map's info parsing"));
	// if (!(map_checker(map)))
	// 	return (return_false(__func__, "[FAIL] map's itegrity compromised"));
	return (True);
}