/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:19:49 by mbos              #+#    #+#             */
/*   Updated: 2020/02/24 12:12:03 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool	map_parse_no(t_map *map, char *line, t_mlx *mlx)
{
	int start;

	if (map->north.file != NULL)
		return (return_false(__func__, "[FAIL] info several times", mlx));
	start = 0;
	map_check_incorrect_input_text('N', 'O', line, mlx);
	while (line[start] && line[start] != '.')
		start++;
	if (!(map->north.file = strdup(&line[start])))
		return (return_false(__func__, "[FAIL] strdup", mlx));
	return (True);
}

t_bool	map_parse_so(t_map *map, char *line, t_mlx *mlx)
{
	int start;

	if (map->south.file != NULL)
		return (return_false(__func__, "[FAIL] info several times", mlx));
	start = 0;
	map_check_incorrect_input_text('s', 'O', line, mlx);
	while (line[start] && line[start] != '.')
		start++;
	if (!(map->south.file = strdup(&line[start])))
		return (return_false(__func__, "[FAIL] strdup", mlx));
	return (True);
}

t_bool	map_parse_we(t_map *map, char *line, t_mlx *mlx)
{
	int start;

	if (map->west.file != NULL)
		return (return_false(__func__, "[FAIL] info several times", mlx));
	start = 0;
	map_check_incorrect_input_text('W', 'E', line, mlx);
	while (line[start] && line[start] != '.')
		start++;
	if (!(map->west.file = strdup(&line[start])))
		return (return_false(__func__, "[FAIL] strdup", mlx));
	return (True);
}

t_bool	map_parse_ea(t_map *map, char *line, t_mlx *mlx)
{
	int start;

	if (map->east.file != NULL)
		return (return_false(__func__, "[FAIL] info several times", mlx));
	start = 0;
	map_check_incorrect_input_text('E', 'A', line, mlx);
	while (line[start] && line[start] != '.')
		start++;
	if (!(map->east.file = strdup(&line[start])))
		return (return_false(__func__, "[FAIL] strdup", mlx));
	return (True);
}

t_bool	map_parse_sp(t_map *map, char *line, t_mlx *mlx)
{
	int		start;
	t_img	*tab[4];
	int		i;

	start = 0;
	map_check_incorrect_input_text('S', 0, line, mlx);
	while (line[start] && line[start] != '.')
		start++;
	i = 0;
	tab[0] = &map->sprite;
	tab[1] = &map->sp1;
	tab[2] = &map->sp2;
	tab[3] = &map->sp3;
	while (tab[i]->file != NULL)
		i++;
	if (i > 3)
		return (return_false(__func__, "[FAIL] 4 sprites only allowed", mlx));
	if (!(tab[i]->file = strdup(&line[start])))
		return (return_false(__func__, "[FAIL] strdup", mlx));
	return (True);
}
