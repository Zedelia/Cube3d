/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_colors.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 20:06:28 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/28 15:58:30 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static void	get_colors(int *red, int *green, int *blue, char *line)
{
	int i;

	i = 0;
	while (ft_isdigit(line[i]) == False)
		i++;
	*red = ft_atoi(&line[i]);
	i += get_str_int_len(&line[i]) + 1;
	*green = ft_atoi(&line[i]);
	i += get_str_int_len(&line[i]) + 1;
	*blue = ft_atoi(&line[i]);
}

t_bool	map_parse_floor(t_map *map, char *line)
{
	int red;
	int green;
	int blue;

	red = -1;
	green = -1;
	blue = -1;
	get_colors(&red, &green, &blue, line);
	if (red == -1 || green == -1 || blue == -1)
		return (return_false(__func__, "[FAIL] get RGB floor colors"));
	map->floor = (red * 65536) + (green * 256) + blue;
	return (True);
}

t_bool	map_parse_cell(t_map *map, char *line)
{
	int red;
	int green;
	int blue;

	red = -1;
	green = -1;
	blue = -1;
	get_colors(&red, &green, &blue, line);
	if (red == -1 || green == -1 || blue == -1)
		return (return_false(__func__, "[FAIL] get RGB cell colors"));
	map->cell = (red * 65536) + (green * 256) + blue;
	return (True);
}