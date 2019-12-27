/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_r.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 16:48:39 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 22:04:06 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool	map_parse_r(t_map *map, char *line)
{
	size_t	i;

	i = 1;
	while (ft_isdigit(line[i]) == 0)
		i++;
	map->r_width = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]) == 1)
		i++;
	i++;
	map->r_height = ft_atoi(&line[i]);
	return (True);
}
