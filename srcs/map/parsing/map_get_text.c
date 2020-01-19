/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_text.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 19:49:13 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 13:33:58 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool	map_parse_no(t_map *map, char *line)
{
	int start;

	start = 0;
	ft_check_incorrect_input_text('N', 'O', line);
	while (line[start] && line[start] != '.')
		start++;
	if (!(map->north.file = strdup(&line[start])))
		return (return_false(__func__, "[FAIL] strdup"));
	return (True);
}

t_bool	map_parse_so(t_map *map, char *line)
{
	int start;

	start = 0;
	ft_check_incorrect_input_text('s', 'O', line);
	while (line[start] && line[start] != '.')
		start++;
	if (!(map->south.file = strdup(&line[start])))
		return (return_false(__func__, "[FAIL] strdup"));
	return (True);
}

t_bool	map_parse_we(t_map *map, char *line)
{
	int start;

	start = 0;
	ft_check_incorrect_input_text('W', 'E', line);
	while (line[start] && line[start] != '.')
		start++;
	if (!(map->west.file = strdup(&line[start])))
		return (return_false(__func__, "[FAIL] strdup"));
	return (True);
}

t_bool	map_parse_ea(t_map *map, char *line)
{
	int start;

	start = 0;
	ft_check_incorrect_input_text('E', 'A', line);
	while (line[start] && line[start] != '.')
		start++;
	if (!(map->east.file = strdup(&line[start])))
		return (return_false(__func__, "[FAIL] strdup"));
	return (True);
}

t_bool	map_parse_sp(t_map *map, char *line)
{
	int start;

	start = 0;
	ft_check_incorrect_input_text('S', 0, line);
	while (line[start] && line[start] != '.')
		start++;
	if (!(map->sprite.file = strdup(&line[start])))
		return (return_false(__func__, "[FAIL] strdup"));
	return (True);
}