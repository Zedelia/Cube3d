/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_checker.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 21:57:04 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 22:02:21 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	map_checker(t_map *map)
{
	if (!(map_check_texture(map)))
		return (return_false(__func__, "[FAIL] invalid texture path"));
	if (!(map_check_colors(map)))
		return (return_false(__func__, "[FAIL] invalid cell & floor colors"));
	if (!(map_check_resolution(map)))
		return (return_false(__func__, "[FAIL] invalid resolution"));
	if (!(map_check_map(map)))
		return (return_false(__func__, "[FAIL] invalid map"));
	return (True);
}