/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_map_line.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 20:11:04 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 15:32:59 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static t_bool 	map_check_end_file(int fd, char *line)
{
	int i ;

	i = 0;
	while (get_next_line(fd, &line))
	{
		while (line[i])
		{
			if (line[i] > 32)
				return (return_false(__func__, "[FAIL] map isn't the EOF"));
		}
		ft_memdel((void**)&line);
	}
	return (True);
}

static t_bool		strlen_spcount(t_maparse *line)
{
	int i;

	i = 0;
	line->columns = 0;
	line->sp = 0;
	while (line->line[i])
	{
		if (ft_isincharset(line->line[i], SPRITES))
		{
			line->sp++;
			line->columns++;
		}
		else if (ft_isincharset(line->line[i], MAP_INPUTS))
			line->columns++;
		else if (line->line[i] > 32)
			return (return_false(__func__, "[FAIL] wrong input in map"));
		i++;
	}
	return (True);
}

static t_bool	map_line_init(t_maparse **m_line, char *line, int id)
{
	if (!(*m_line = malloc(sizeof(t_maparse))))
		return (return_false(__func__, "[FAIL] malloc"));
	if (!((*m_line)->line = ft_strdup(line)))
			return (return_false(__func__, "[FAIL] strdup"));
	(*m_line)->next = NULL;
	strlen_spcount((*m_line));
	(*m_line)->id = id;
	return (True);
}

static void		map_add_line(t_maparse *list, t_maparse *tmp)
{
	t_maparse 	*temp;

	temp = list;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = tmp;
	}
	else
		list = tmp;
}

t_bool			map_get_map_lines(t_map *map, int fd, char *line)
{
	t_maparse 	*tmp;

	map->map_lines = 1;
	tmp = NULL;
	map_line_init(&tmp, line, map->map_lines);
	map->lines = tmp;
	while (get_next_line(fd, &line) && line[0] == '1')
	{
		map_line_init(&tmp, line, map->map_lines);
		map_add_line(map->lines, tmp);
		map->map_lines++;
	}
	if (line[0] == '0')
		return (return_false(__func__, "[FAIL] map isn't closed on left"));
	ft_memdel((void*)line);
	map_check_end_file(fd, line);
	return (True);
}
