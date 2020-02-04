/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_text.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 19:49:13 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 09:53:36 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool	map_parse_no(t_map *map, char *line)
{
	int start;

	if (map->north.file != NULL)
		return (return_false(__func__, "[FAIL] info provided several times"));
	start = 0;
	ft_check_incorrect_input_text('N', 'O', line);
	while (line[start] && line[start] != '.')
		start++;
	if (!(map->north.file = strdup(&line[start])))
		return (return_false(__func__, "[FAIL] strdup"));
	return (True);
}

t_bool	map_parse_so(t_map *map, char *line)
{
	int start;

	if (map->south.file != NULL)
		return (return_false(__func__, "[FAIL] info provided several times"));
	start = 0;
	ft_check_incorrect_input_text('s', 'O', line);
	while (line[start] && line[start] != '.')
		start++;
	if (!(map->south.file = strdup(&line[start])))
		return (return_false(__func__, "[FAIL] strdup"));
	return (True);
}

t_bool	map_parse_we(t_map *map, char *line)
{
	int start;

	if (map->west.file != NULL)
		return (return_false(__func__, "[FAIL] info provided several times"));
	start = 0;
	ft_check_incorrect_input_text('W', 'E', line);
	while (line[start] && line[start] != '.')
		start++;
	if (!(map->west.file = strdup(&line[start])))
		return (return_false(__func__, "[FAIL] strdup"));
	return (True);
}

t_bool	map_parse_ea(t_map *map, char *line)
{
	int start;

	if (map->east.file != NULL)
		return (return_false(__func__, "[FAIL] info provided several times"));
	start = 0;
	ft_check_incorrect_input_text('E', 'A', line);
	while (line[start] && line[start] != '.')
		start++;
	if (!(map->east.file = strdup(&line[start])))
		return (return_false(__func__, "[FAIL] strdup"));
	return (True);
}

t_bool	map_parse_sp(t_map *map, char *line)
{
	int 	start;
	t_img 	*tab[4];
	int i;

	start = 0;
	ft_check_incorrect_input_text('S', 0, line);
	while (line[start] && line[start] != '.')
		start++;
	i = 0;
	tab[0] = &map->sprite;
	tab[1] = &map->sprite1;
	tab[2] = &map->sprite2;
	tab[3] = &map->sprite3;
	while (tab[i]->file != NULL)
		i++;
	if (i > 3)
		return (return_false(__func__,
				"[FAIL] sorry, only 4 types of sprites allowed"));
	if (!(tab[i]->file = strdup(&line[start])))
		return (return_false(__func__, "[FAIL] strdup"));
	return (True);
}
