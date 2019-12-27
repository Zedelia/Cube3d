/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_text.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 19:49:13 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 18:32:33 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	map_parse_no(t_map *map, char *line)
{
	int start;

	start = 0;
	while (line[start] != '.' && line[start])
		start++;
	if (!(map->text_north = strdup(&line[start])))
		return (return_false(__func__, "strdup [FAIL]"));
	return (True);
}

t_bool	map_parse_so(t_map *map, char *line)
{
	int start;

	start = 0;
	while (line[start] != '.' && line[start])
		start++;
	if (!(map->text_south = strdup(&line[start])))
		return (return_false(__func__, "strdup [FAIL]"));
	return (True);
}

t_bool	map_parse_we(t_map *map, char *line)
{
	int start;

	start = 0;
	while (line[start] != '.' && line[start])
		start++;
	if (!(map->text_west = strdup(&line[start])))
		return (return_false(__func__, "strdup [FAIL]"));
	return (True);
}

t_bool	map_parse_ea(t_map *map, char *line)
{
	int start;

	start = 0;
	while (line[start] != '.' && line[start])
		start++;
	if (!(map->text_east = strdup(&line[start])))
		return (return_false(__func__, "strdup [FAIL]"));
	return (True);
}

t_bool	map_parse_sp(t_map *map, char *line)
{
	int start;

	start = 0;
	while (line[start] != '.' && line[start])
		start++;
	if (!(map->text_sprite = strdup(&line[start])))
		return (return_false(__func__, "strdup [FAIL]"));
	return (True);
}