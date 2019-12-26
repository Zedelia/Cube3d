/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_init.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:30:13 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 16:04:10 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	map_init(t_map **map, char *map_file)
{
	if (!(*map = malloc(sizeof(t_map))))
		return (false_ret(__func__));
	(*map)->map_file = map_file;
	(*map)->r_width = 0;
	(*map)->r_height = 0;
	(*map)->cell = 0;
	(*map)->floor = 0;
	(*map)->s_width = 0;
	(*map)->s_height = 0;
	(*map)->text_north = NULL;
	(*map)->text_south = NULL;
	(*map)->text_west = NULL;
	(*map)->text_east = NULL;
	(*map)->text_sprite = NULL;
	if (!(map_parser(*map)))
		return (false_ret(__func__));
	return (True);
}