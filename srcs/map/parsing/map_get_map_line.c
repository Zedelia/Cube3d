/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_map_line.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 20:11:04 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 18:36:46 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static	int	ft_strlen_map(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		
	}

}

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

static t_bool	map_line_init(t_maparse **m_line, char *line, int id)
{
	if (!(*m_line = malloc(sizeof(t_maparse))))
		return (return_false(__func__, "[FAIL] malloc"));
	if (!((*m_line)->line = ft_strdup(line)))
			return (return_false(__func__, "[FAIL] strdup"));
	(*m_line)->column = ft_strlen_map((*m_line)->line);
	(*m_line)->id = id;
}

static t_bool	map_add_line(t_maparse *list, t_maparse *tmp)
{
	t_maparse 	*temp;

	temp = list;
	if (temp->next)
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
	t_maparse 	*list;

	map->map_lines = 1;
	map_line_init(&tmp, line, map->map_lines);
	while (get_next_line(fd, &line) && line[0] == '1')
	{
		map_line_init(&tmp, line, map->map_lines);
		map_add_line(list, tmp);
		ft_memdel((void**)line);
		map->map_lines++;
	}
	map->lines = list;
	map_check_end_file(fd, line);
	ft_memdel((void**)line);
	return (True);
}
