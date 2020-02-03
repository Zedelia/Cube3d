/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:56:23 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 13:00:12 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include "cube3d.h"

typedef enum
{
	_r = 0,
	_no,
	_so,
	_we,
	_ea,
	_sp,
	_floor,
	_cell,
	_sp1,
	_sp2,
	_sp3,
	t_size
}	t_type_map;

/*
** Init variables
*/

void				map_printf(t_map *map);

t_bool				map_init(t_map **map, char *map_file, t_mlx *mlx);
t_bool				map_parser(t_map *map);
t_bool				map_textures_init(t_map *map, t_mlx *mlx);

/*
** create 2D map tab and save sprites position
*/

t_bool				map_get_map_in_one_line(t_map *map, int fd, char *line);
t_bool				map_tab_init(t_map *map);


t_bool				map_tabs_fill(t_map *map);

/*
** ptr on get_map_info_fct tab
*/

t_bool				map_get_line_info(t_map *map, char *line);
void				init_map_parser_fct_tab(void);
typedef t_bool		(t_map_parser_fct)(t_map *map , char *line);
t_map_parser_fct	*g_map_parser_fct[t_size];

t_bool				map_parse_r(t_map *map, char *line);
t_bool				map_parse_no(t_map *map, char *line);
t_bool				map_parse_so(t_map *map, char *line);
t_bool				map_parse_we(t_map *map, char *line);
t_bool				map_parse_ea(t_map *map, char *line);
t_bool				map_parse_sp(t_map *map, char *line);
t_bool				map_parse_floor(t_map *map, char *line);
t_bool				map_parse_cell(t_map *map, char *line);

/*
** Check map infos
*/

t_bool				map_check_infos(t_map *map);
t_bool				map_check_map(t_map *map);
t_bool				map_check_resolution(t_map *map);
t_bool				map_check_colors(t_map *map);
t_bool				map_check_texture(t_map *map);

/*
** Map utils function
*/

char		*check_incorrect_inputs_before_indicator(char *line);
size_t		map_get_index(char *line);
int			math_tab_lines(t_map *map, char *map_char);

/*
** Free map
*/

// TODO free map function

#endif