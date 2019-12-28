/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_check_colors.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 13:03:00 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/28 13:06:13 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static t_bool	map_check_colors_one(int color)
{
	if (color < 0)
		return (return_false(__func__, "[FAIL] invalid color"));
	return (True);
}

t_bool			map_check_colors(t_map *map)
{
	if (!(map_check_colors_one(map->floor)))
		return (return_false(__func__, "[FAIL] invalid floor color"));
	if (!(map_check_colors_one(map->cell)))
		return (return_false(__func__, "[FAIL] invalid cell color"));
	return (True);
}