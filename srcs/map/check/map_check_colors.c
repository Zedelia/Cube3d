/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_check_colors.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 13:03:00 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 13:19:40 by mbos        ###    #+. /#+    ###.fr     */
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
	map_check_colors_one(map->floor);
	map_check_colors_one(map->cell);
	return (True);
}