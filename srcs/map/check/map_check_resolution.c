/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_check_resolution.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 13:06:40 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/28 13:08:43 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool	map_check_resolution(t_map *map)
{
	if (map->r_width < 0)
		return (return_false(__func__, "[FAIL] invalid width resolution"));
	if (map->r_height < 0)
		return (return_false(__func__, "[FAIL] invalid height resolution"));
	return (True);
}