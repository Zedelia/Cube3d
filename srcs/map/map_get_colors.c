/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_colors.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 20:06:28 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 21:16:28 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	get_colors(int *red, int *green, int *blue, char *line)
{
	int i;
	int j;

	i = 0;
	while (ft_isdigit(line[i]) == 0)
		i++;
	j = get_str_int_len(&line[i]);
	*red = ft_atoi(&line[i]);
	i = get_str_int_len(&line[j]);
	*green = ft_atoi(&line[j]);
	i = get_str_int_len(&line[j]);
	*blue = ft_atoi(&line[j]);
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
		return (false_ret(__func__));
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
		return (false_ret(__func__));
	map->cell = (red * 65536) + (green * 256) + blue;
	return (True);
}