/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_colors.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 20:06:28 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 18:49:15 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static t_bool 	check_incorrect_inputs(char *line)
{
	int i;
	int coma;

	i = 0;
	coma = 0;
	while (line[i] && ft_isdigit(line[i]) == False)
	{
		if (line[i] == ',')
			coma += 1;
		if ((line[i] > 32 && line[i] != ',') || coma > 1)
			return (return_false(__func__, "[FAIL] incorrect input in colors"));
		i++;
	}
	return (True);
}

static t_color	get_colors(char *line)
{
	int 	i;
	t_color	colors;

	i = 0;
	colors.r = -1;
	colors.g = -1;
	colors.b = -1;
	while (ft_isincharset(line[i], MAP_INFOS) == False)
		i++;
	i++;
	check_incorrect_inputs(&line[i]);
	colors.r = ft_atoi(&line[i]);
	i += get_str_int_len(&line[i + 1]);
	check_incorrect_inputs(&line[i]);
	colors.g = ft_atoi(&line[i]);
	i += get_str_int_len(&line[i]);
	check_incorrect_inputs(&line[i]);
	colors.b = ft_atoi(&line[i]);
	i += get_str_int_len(&line[i]);
	check_incorrect_inputs(&line[i]);
	return (colors);
}

t_bool	map_parse_floor(t_map *map, char *line)
{
	t_color	colors;
	int i;

	i = 0;
	colors = get_colors(line);
	if (colors.r > 255 || colors.g > 255 || colors.b > 255
				|| colors.r < 0 || colors.g < 0 || colors.b < 0)
		return (return_false(__func__, "[FAIL] get RGB floor colors"));
	map->floor = color_to_int(colors);
	return (True);
}

t_bool	map_parse_cell(t_map *map, char *line)
{
	t_color	colors;
	int i;

	i = 0;
	colors = get_colors(line);
	if (colors.r > 255 || colors.g > 255 || colors.b > 255
				|| colors.r < 0 || colors.g < 0 || colors.b < 0)
		return (return_false(__func__, "[FAIL] get RGB cell colors"));
	map->cell = color_to_int(colors);
	return (True);
}