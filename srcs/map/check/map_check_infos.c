/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_check_infoss.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 13:54:15 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/28 13:54:17 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool	map_check_infos(t_map *map, t_mlx *mlx)
{
	map_check_texture(map, mlx);
	map_check_colors(map, mlx);
	map_check_resolution(map, mlx);
	map_check_map(map, mlx);
	return (True);
}