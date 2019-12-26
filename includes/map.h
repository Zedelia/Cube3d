/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:56:23 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 21:13:35 by mbos        ###    #+. /#+    ###.fr     */
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
	_map,
	t_size
}	t_type_map;

void 				mlx_free(t_mlx *mlx);
t_bool				map_init(t_map **map, char *map_file);
t_bool				map_parser(t_map *map);
void				map_printf(t_map *map);
t_bool				map_parser(t_map *map);
t_bool				map_get_info(t_map *map, char *line);

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
t_bool				map_parse_map(t_map *map, char *line);


#endif