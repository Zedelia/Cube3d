/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_check_resolution.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 13:06:40 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 16:13:20 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool	map_check_resolution(t_map *map, t_mlx *mlx)
{
	if (map->r_width < 1)
		return (return_false(__func__, "[FAIL] invalid width res.", mlx));
	if (map->r_height < 1)
		return (return_false(__func__, "[FAIL] invalid height res.", mlx));
	return (True);
}
