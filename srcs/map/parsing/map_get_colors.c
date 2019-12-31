/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_colors.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 20:06:28 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 11:09:17 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static t_color	get_colors(char *line)
{
	int 	i;
	t_color	colors;

	i = 0;
	colors.r = -1;
	colors.g = -1;
	colors.b = -1;
	while (ft_isdigit(line[i]) == False)
		i++;
	colors.r = ft_atoi(&line[i]);
	i += get_str_int_len(&line[i]) + 1;
	colors.g = ft_atoi(&line[i]);
	i += get_str_int_len(&line[i]) + 1;
	colors.b = ft_atoi(&line[i]);
	return (colors);
}

t_bool	map_parse_floor(t_map *map, char *line)
{
	t_color	colors;

	colors = get_colors(line);
	if (colors.r == -1 || colors.g == -1 || colors.b == -1)
		return (return_false(__func__, "[FAIL] get RGB floor colors"));
	map->floor = color_to_int(colors);
	return (True);
}

t_bool	map_parse_cell(t_map *map, char *line)
{
	t_color	colors;

	colors = get_colors(line);
	if (colors.r == -1 || colors.g == -1 || colors.b == -1)
		return (return_false(__func__, "[FAIL] get RGB cell colors"));
	map->cell = color_to_int(colors);
	return (True);
}