/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_map.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 21:25:58 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 19:54:08 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	map_fill_map_tab(t_map *map, char *join);
{

}

t_bool	map_get_map_tab(t_map *map, int fd, char *line)
{
	int		result;
	char	*temp;
	char	*join;

	if (!(temp = ft_strdup(line)))
		return (return_false(__func__, "[FAIL] strdup"));
	ft_memdel((void**)&line);
	while ((result = get_next_line(fd, &line)) == 1 && line[0] == '1')
	{
		if (!(join = ft_strjoin(temp, line)))
			return (return_false(__func__, "[FAIL] strjoin"));
		ft_memdel((void**)&temp);
		if (!(temp = ft_strdup(join)))
			return (return_false(__func__, "[FAIL] strdup"));
		ft_memdel((void**)&join);
	}
	if (!(join = ft_strjoin(temp, line)))
		return (return_false(__func__, "[FAIL] strjoin"));
	map_fill_map_tab(map, join);
	ft_memdel((void**)&temp);
	ft_memdel((void**)&line);
	return (True);
}
