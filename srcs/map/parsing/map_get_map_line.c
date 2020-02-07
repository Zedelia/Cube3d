/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_map_line.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 20:11:04 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 16:41:12 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static t_bool		strlen_spcount(t_maparse *line, t_mlx *mlx)
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
			return (return_false(__func__, "[FAIL] wrong input in map", mlx));
		i++;
	}
	return (True);
}

static t_bool	map_line_init(t_maparse **m_line, char *line, int id, t_mlx *mlx)
{
	if (!(*m_line = malloc(sizeof(t_maparse))))
		return (return_false(__func__, "[FAIL] malloc", mlx));
	if (!((*m_line)->line = ft_strdup(line)))
			return (return_false(__func__, "[FAIL] strdup", mlx));
	(*m_line)->next = NULL;
	strlen_spcount((*m_line), mlx);
	(*m_line)->id = id;
	return (True);
}

static void		map_add_line(t_maparse **list, t_maparse *tmp)
{
	t_maparse 	*temp;

	temp = *list;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = tmp;
	}
	else
		*list = tmp;
}

t_bool			map_get_map_lines(t_map *map, int fd, char *line, t_mlx *mlx)
{
	t_maparse 	*tmp;

	map->nb_lines = 0;
	tmp = NULL;
	while (line[0] == '1')
	{
		map_line_init(&tmp, line, map->nb_lines, mlx);
		map_add_line(&map->lines, tmp);
		map->nb_lines++;
		free(line);
		get_next_line(fd, &line);
	}
	free(line);
	line = NULL;
	map_check_end_file(fd, line, mlx);
	return (True);
}
