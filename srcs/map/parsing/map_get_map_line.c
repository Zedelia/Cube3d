/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_map_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 20:11:04 by mbos              #+#    #+#             */
/*   Updated: 2020/03/02 13:16:55 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static t_bool	strlen_spcount(t_maparse *line, t_mlx *mlx)
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
		else if (ft_isincharset(line->line[i], INPUTS))
			line->columns++;
		else if (line->line[i] > 32)
			return (return_false(__func__, "[FAIL] wrong input in map", mlx));
		i++;
	}
	return (True);
}

static t_bool	map_line_init(t_maparse **self, char *line, int id, t_mlx *mlx)
{
	if (!(*self = malloc(sizeof(t_maparse))))
		return (return_false(__func__, "[FAIL] malloc", mlx));
	if (!((*self)->line = ft_strdup(line)))
		return (return_false(__func__, "[FAIL] strdup", mlx));
	(*self)->next = NULL;
	strlen_spcount((*self), mlx);
	(*self)->id = id;
	return (True);
}

static void		map_add_line(t_maparse **list, t_maparse *tmp)
{
	t_maparse	*temp;

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
	t_maparse	*tmp;

	map->nb_lines = 0;
	tmp = NULL;
	while (line[0] == '1')
	{
		map_line_init(&tmp, line, map->nb_lines, mlx);
		map_add_line(&map->lines, tmp);
		map->nb_lines++;
		ft_memdel((void**)&line);
		get_next_line(fd, &line);
	}
	map_check_end_file(fd, line, mlx);
	ft_memdel((void**)&line);
	return (True);
}
