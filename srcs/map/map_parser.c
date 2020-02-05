/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_parser.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 15:07:42 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 14:02:42 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static t_bool	map_parsing_info(t_map *map, int fd, char *line)
{
	while ((get_next_line(fd, &line)) == 1 && line[0] != '1')
	{
		if (!(map_get_line_info(map, line)))
			return (return_false(__func__, NULL));
		ft_memdel((void**)&line);
	}
	map->map_col = occur_in_str('1', line);
	map_get_map_in_one_line(map, fd, line);
	return (True);
}

t_bool	map_parser(t_map *map, t_mlx *mlx)
{
	char	*line;
	int 	fd;

	line = NULL;
	init_map_parser_fct_tab();
	fd = open(map->map_file, O_RDONLY);
	map_parsing_info(map, fd, line);
	map_textures_init(map, mlx);
	map_tab_init(map);
	map_check_infos(map);
	return (True);
}