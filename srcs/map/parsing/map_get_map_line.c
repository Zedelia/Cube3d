/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_map_line.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 20:11:04 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 16:03:22 by mbos        ###    #+. /#+    ###.fr     */
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

t_bool			map_get_map_in_one_line(t_map *map, int fd, char *line)
{
	char	*temp;
	char	*join;

	if (!(temp = ft_strdup(line)))
		return (return_false(__func__, "[FAIL] strdup"));
	map->map_lines += 3;
	while (get_next_line(fd, &line) && map->map_lines++ > 0)
	{
		if (line[0] == '\0' || line[0] == '\n')
			break ;
		if (!(join = ft_strjoin(temp, line)))
			return (return_false(__func__, "[FAIL] strjoin"));
		ft_memdel((void**)&temp);
		if (!(temp = ft_strdup(join)))
			return (return_false(__func__, "[FAIL] strdup"));
		ft_memdel((void**)&join);
	}
	if (!(map->map_char = ft_strjoin(temp, line)))
		return (return_false(__func__, "[FAIL] strjoin"));
	ft_memdel((void**)&temp);
	ft_memdel((void**)&line);
	map_check_end_file(fd, line);
	return (True);
}
