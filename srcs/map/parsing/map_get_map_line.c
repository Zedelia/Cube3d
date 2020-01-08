/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_map_line.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 20:11:04 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 11:27:12 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool	map_get_map_line(t_map *map, int fd, char *line)
{
	char	*temp;
	char	*join;
	int 	height;

	height = 2;
	if (!(temp = ft_strdup(line)))
		return (return_false(__func__, "[FAIL] strdup"));
	while (get_next_line(fd, &line) && height++ > -1) // supprimer le > -1
	{
		if (!(join = ft_strjoin(temp, line)))
			return (return_false(__func__, "[FAIL] strjoin"));
		ft_memdel((void**)&temp);
		if (!(temp = ft_strdup(join)))
			return (return_false(__func__, "[FAIL] strdup"));
		ft_memdel((void**)&join);
	}
	if (!(map->map_char = ft_strjoin(temp, line)))
		return (return_false(__func__, "[FAIL] strjoin"));
	map->map_lines = height;
	ft_memdel((void**)&temp);
	ft_memdel((void**)&line);
	return (True);
}
