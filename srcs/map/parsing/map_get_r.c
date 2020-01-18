/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_r.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 16:48:39 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 22:52:49 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static char		*check_between_digit(char *line)
{
	int i;

	i = 0;
	while (line[i] && ft_isdigit(line[i]) == False)
	{
		if (line[i] > 32)
			return (NULL);
		i++;
	}
	return (&line[i]);
}

static t_bool		check_incorrect_inputs(char c, char *line)
{
	size_t	i;

	i = 1;
	while (line[i] && line[i] != c)
		i++;
	i++;
	if (!(line = check_between_digit(&line[i])))
		return (return_false(__func__, "[FAIL] wrong input in resolution"));
	while (line[i] && ft_isdigit(line[i]) == True)
		i++;
	if (!(line = check_between_digit(&line[i])))
		return (return_false(__func__, "[FAIL] wrong input in resolution"));
	while (line[i] && ft_isdigit(line[i]) == True)
		i++;
	if (!(line = check_between_digit(&line[i])))
		return (return_false(__func__, "[FAIL] wrong input in resolution"));
	return (True);
}


t_bool	map_parse_r(t_map *map, char *line)
{
	size_t	i;

	i = 1;
	check_incorrect_inputs('R', line);
	while (ft_isdigit(line[i]) == 0)
		i++;
	map->r_width = ft_atoi(&line[i]);
	if (map->r_width > WIN_WIDTH)
		map->r_width = WIN_WIDTH;
	while (ft_isdigit(line[i]) == 1)
		i++;
	i++;
	map->r_height = ft_atoi(&line[i]);
	if (map->r_height > WIN_HEIGHT)
		map->r_height = WIN_HEIGHT;
	return (True);
}
