/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_r.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 16:48:39 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 17:45:37 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	map_parse_r(t_map *map, char *line)
{
	size_t	i;
	size_t	j;
	char 	*atoi;

	i = 1;
	while (ft_isdigit(line[i]) == 0)
		i++;
	j = get_str_int_len(&line[i]);
	if (!(atoi = ft_strndup((const char *)&line[i], j - i)))
		return (false_ret(__func__));
	map->r_width = ft_atoi(atoi);
	ft_memdel((void**)&atoi);
	while (ft_isdigit(line[j]) == 0)
		j++;
	i = get_str_int_len(&line[j]);
	if (!(atoi = ft_strndup((const char *)&line[j], i - j)))
		return (false_ret(__func__));
	map->r_height = ft_atoi(atoi);
	ft_memdel((void**)&atoi);
	return (True);
}
