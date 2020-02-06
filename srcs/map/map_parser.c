/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_parser.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 15:07:42 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 16:17:23 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static t_bool	map_parsing_info(t_mlx *mlx, int fd, char *line)
{
	while ((get_next_line(fd, &line)) == 1 && line[0] != '1')
	{
		if (!(map_get_line_info(mlx->map, line)))
			return (return_false(__func__, NULL));
		ft_memdel((void**)&line);
	}
	map_textures_init(mlx->map, mlx);
	map_get_nb_lines(mlx->map, fd, line);
	return (True);
}

t_bool	map_parser(t_mlx *mlx)
{
	char	*line;
	int 	fd;

	line = NULL;
	init_map_parser_fct_tab();
	fd = open(mlx->map->map_file, O_RDONLY);
	map_parsing_info(mlx, fd, line);
	map_tab_init(mlx->map);
	map_check_infos(mlx->map);
	return (True);
}