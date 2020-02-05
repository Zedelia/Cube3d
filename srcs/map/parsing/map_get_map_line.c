/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_map_line.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 20:11:04 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 13:59:00 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool	map_get_map_in_one_line(t_map *map, int fd, char *line)
{
	char	*temp;
	char	*join;

	if (!(temp = ft_strdup(line)))
		return (return_false(__func__, "[FAIL] strdup"));
	map->map_lines += 3;
	while (get_next_line(fd, &line) && map->map_lines++ > 0)
	{
		if (line[0] == '\0')
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
	return (True);
}
