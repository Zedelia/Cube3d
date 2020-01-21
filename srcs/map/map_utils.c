/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_utils.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 13:12:14 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 14:06:04 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

char	 *check_incorrect_inputs_before_indicator(char *line)
{
	int i;

	i = 0;
	while (line[i] && ft_isincharset(line[i], MAP_INFOS) == 0)
	{
		if (line[i] > 32 && line [i + 1])
			return (NULL);
		i++;
	}
	return (&line[i]);
}

/*
** Get index of indicator in ptr ptr tab
*/

size_t		map_get_index(char *line)
{
	int i;

	i = 0;
	if (!(line = check_incorrect_inputs_before_indicator(line)))
		return (return_false(__func__, "[FAIL] inputs before identifier"));
	if (line && line[i] == 'S' && line[i + 1] == 'O')
		line[i] = 's';
	if (line)
		return(ft_index(line[i], MAP_INFOS));
	return (-1);
}

/*
** Math how many lines (== [y]) in the 2D map AND Count Sprites number
*/

// REVIEW you can code better than this shit

int		math_tab_lines(t_map *map, char *map_char)
{
	int i;
	int j;
	int s;

	j = 0;
	s = 0;
	i = ft_strlen(map_char) - 1;
	while (i > -1)
	{
		if (map_char[i] > 32
			&& !ft_isincharset(map_char[i], MAP_INPUTS)
				&& !ft_isincharset(map_char[i], SPRITES))
			return (return_false(__func__, "[FAIL] wrong input in map"));
		if (ft_isincharset(map_char[i], SPRITES))
			s++;
		if (ft_isincharset(map->map_char[i], MAP_INPUTS)
			|| ft_isincharset(map_char[i], SPRITES))
			j++;;
		i--;
	}
	map->map_sprites = s;
	return (j / map->map_col);
}