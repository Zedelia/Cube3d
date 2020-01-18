/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_info.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 16:35:23 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 21:56:16 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

// TODO
// dans les map_parse ajouter la verifications que c'est bien SO NO etc
// ajouter les verifications qu'il n'y a pas de caracteres intruts dans la map


static char	 *check_incorrect_inputs(char *line)
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

size_t		map_get_index(char *line)
{
	int i;

	i = 0;
	if (!(line = check_incorrect_inputs(line)))
		return (return_false(__func__, "[FAIL] inputs before identifier"));
	if (line && line[i] == 'S' && line[i + 1] == 'O')
		line[i] = 's';
	if (line)
		return(ft_index(line[i], MAP_INFOS));
	return (-1);
}

t_bool	map_get_info(t_map *map, char *line)
{
	size_t 				index;
	t_map_parser_fct	*fonc;

	index = map_get_index(line);
	if (index == 8)
		return (True);
	fonc = g_map_parser_fct[index];
	if (!(fonc(map, line)))
		return (return_false(__func__, "[FAIL] map get info"));
	return (True);
}