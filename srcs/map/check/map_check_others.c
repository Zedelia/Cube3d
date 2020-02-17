/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_others.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:19:00 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 14:19:01 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

char	*map_check_incorrect_inputs_before_indicator(char *line)
{
	int i;

	i = 0;
	while (line[i] && ft_isincharset(line[i], MAP_INFOS) == 0)
	{
		if (line[i] > 32)
			return (NULL);
		i++;
	}
	return (&line[i]);
}

t_bool	map_check_end_file(int fd, char *line, t_mlx *mlx)
{
	int i;

	i = 0;
	while (get_next_line(fd, &line))
	{
		while (line[i])
		{
			if (line[i] > 32)
				return (return_false(__func__,
						"[FAIL] map isn't the EOF", mlx));
		}
		ft_memdel((void**)&line);
	}
	ft_memdel((void**)&line);
	return (True);
}

t_bool	map_check_incorrect_input_text(char a, char b, char *line, t_mlx *mlx)
{
	int start;

	start = 0;
	while (line[start] != a && line[start])
		start++;
	if (line[start + 1] && b && line[start + 1] != b)
		return (return_false(__func__, "[FAIL] wrong texture identifier", mlx));
	start += b ? 2 : 1;
	while (line[start] < 33 && line[start])
		start++;
	if (line[start] != '.')
		return (return_false(__func__, "[FAIL] wrong texture input", mlx));
	return (True);
}
