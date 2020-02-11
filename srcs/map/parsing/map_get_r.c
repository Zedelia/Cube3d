/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_r.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 16:48:39 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 15:15:19 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static char			*check_between_digit(char *line)
{
	int i;

	i = 0;
	while (line[i] && !ft_isdigit(line[i]))
	{
		if (line[i] > 32)
			return (NULL);
		i++;
	}
	while (line[i] && ft_isdigit(line[i]))
		i++;
	return (&line[i]);
}

static t_bool		check_incorrect_inputs(char c, char *line, t_mlx *mlx)
{
	size_t	i;

	i = 1;
	while (line[i] && line[i] != c)
		i++;
	i++;
	if (!(line = check_between_digit(&line[i])))
		return (return_false(__func__, "[FAIL] bad input in resolution", mlx));
	if (!(line = check_between_digit(&line[0])))
		return (return_false(__func__, "[FAIL] bad input in resolution", mlx));
	i = 0;
	while (line[i])
	{
		if (line[i] > 32)
			return (return_false(__func__, "[FAIL] char in resolution", mlx));
		i++;
	}
	return (True);
}

t_bool				map_parse_r(t_map *map, char *line, t_mlx *mlx)
{
	size_t	i;

	if (map->r_width != -1 || map->r_height != -1)
		return (return_false(__func__, "[FAIL] info several times", mlx));
	i = 0;
	check_incorrect_inputs('R', line, mlx);
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
