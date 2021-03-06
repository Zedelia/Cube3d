/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 20:06:28 by mbos              #+#    #+#             */
/*   Updated: 2020/03/05 15:05:37 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static t_bool	check_incorrect_inputs(char *line, t_mlx *mlx)
{
	int i;
	int coma;

	i = 0;
	coma = 0;
	while (line[i])
	{
		if (line[i] == ',')
		{
			coma += 1;
			i++;
		}
		while (line[i] && ft_isdigit(line[i]))
			i++;
		if ((line[i] > 32 && !ft_isdigit(line[i]) && line[i] != ',')
				|| coma > 2)
			return (return_false(__func__, "[FAIL] incorrect colors", mlx));
		if (line[i] && line[i] != ',')
			i++;
	}
	return (True);
}

static t_color	get_colors(char *line, t_mlx *mlx)
{
	int		i;
	t_color	colors;

	i = 0;
	colors.r = -1;
	colors.g = -1;
	colors.b = -1;
	while (ft_isincharset(line[i], MAP_INFOS) == False)
		i++;
	if (line[i + 1] == '\0')
		return (colors);
	i++;
	check_incorrect_inputs(&line[i], mlx);
	colors.r = ft_atoi(&line[i]);
	i += get_str_int_len(&line[i]);
	colors.g = ft_atoi(&line[i]);
	i += get_str_int_len(&line[i]);
	colors.b = ft_atoi(&line[i]);
	i += get_str_int_len(&line[i]);
	return (colors);
}

t_bool			map_parse_floor(t_map *map, char *line, t_mlx *mlx)
{
	t_color	colors;
	int		i;

	if (map->floor != -1)
		return (return_false(__func__, "[FAIL] several times same info ", mlx));
	i = 0;
	colors = get_colors(line, mlx);
	if (colors.r > 255 || colors.g > 255 || colors.b > 255
				|| colors.r < 0 || colors.g < 0 || colors.b < 0)
		return (return_false(__func__, "[FAIL] floor: not RGB colors", mlx));
	map->floor = color_to_int(colors);
	return (True);
}

t_bool			map_parse_sky(t_map *map, char *line, t_mlx *mlx)
{
	t_color		colors;
	int			i;

	if (map->sky != -1)
		return (return_false(__func__, "[FAIL] several times same info", mlx));
	i = 0;
	colors = get_colors(line, mlx);
	if (colors.r > 255 || colors.g > 255 || colors.b > 255
				|| colors.r < 0 || colors.g < 0 || colors.b < 0)
		return (return_false(__func__, "[FAIL] Sky: not RGB colors", mlx));
	map->sky = color_to_int(colors);
	return (True);
}
