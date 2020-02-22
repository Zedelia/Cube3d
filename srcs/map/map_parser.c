/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_parser.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/17 14:20:42 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/22 22:59:46 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "../../includes/cube3d.h"

static size_t		map_get_index(char *line, t_mlx *mlx)
{
	int i;

	i = 0;
	if (!(line = map_check_incorrect_inputs_before_indicator(line)))
		return (return_false(__func__, "[FAIL] inputs before identifier", mlx));
	if (line && line[i] == 'S' && line[i + 1] == 'O')
		line[i] = 's';
	if (line)
		return (ft_index(line[i], MAP_INFOS));
	return (-1);
}

static t_bool		map_get_line_info(t_map *map, char *line, t_mlx *mlx)
{
	size_t				index;
	t_map_parser_fct	*fonc;

	index = map_get_index(line, mlx);
	if (index == 10)
		return (True);
	fonc = g_map_parser_fct[index];
	if (!(fonc(map, line, mlx)))
		return (return_false(__func__, "[FAIL] map get info", mlx));
	return (True);
}

static t_bool		map_parsing_info(t_mlx *mlx, int fd, char *line)
{
	while ((get_next_line(fd, &line)) == 1 && line[0] != '1')
	{
		if (!(map_get_line_info(mlx->map, line, mlx)))
			return (return_false(__func__, NULL, mlx));
		ft_memdel((void**)&line);
	}
	map_textures_init(mlx->map, mlx);
	map_get_map_lines(mlx->map, fd, line, mlx);
	map_tab_init(mlx->map, mlx);
	return (True);
}

t_bool				map_parser(t_mlx *mlx)
{
	char	*line;
	int		fd;

	line = NULL;
	init_map_parser_fct_tab();
	fd = open(mlx->map->map_file, O_RDONLY);
	map_parsing_info(mlx, fd, line);
	map_check_infos(mlx->map, mlx);
	return (True);
}
