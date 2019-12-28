/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_map_line.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 20:11:04 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/28 13:34:55 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool	map_get_map_line(t_map *map, int fd, char *line)
{
	char	*temp;
	char	*join;
	int 	height;

	height = 0;
	if (!(temp = ft_strdup(line)))
		return (return_false(__func__, "[FAIL] strdup"));
	while (line && height++ > -1)
	{
		get_next_line(fd, &line);
		if (!(join = ft_strjoin(temp, line)))
			return (return_false(__func__, "[FAIL] strjoin"));
		ft_memdel((void**)&temp);
		if (!(temp = ft_strdup(join)))
			return (return_false(__func__, "[FAIL] strdup"));
		ft_memdel((void**)&join);
	}
	if (!(map->line_map = ft_strjoin(temp, line)))
		return (return_false(__func__, "[FAIL] strjoin"));
	map->size_h = height;
	ft_memdel((void**)&temp);
	ft_memdel((void**)&line);
	return (True);
}
