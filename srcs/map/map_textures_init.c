/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_textures_init.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/18 17:32:49 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 13:37:24 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool		map_textures_init(t_map *map, t_mlx *mlx)
{
	if (!img_load_xpm(mlx, map->north.file, &map->north))
		return (return_false(__func__, "[FAIL] init north texture"));
	if (!img_load_xpm(mlx, map->south.file, &map->south))
		return (return_false(__func__, "[FAIL] init south texture"));
	if(!img_load_xpm(mlx, map->west.file, &map->west))
		return (return_false(__func__, "[FAIL] init west texture"));
	if (!img_load_xpm(mlx, map->east.file, &map->east))
		return (return_false(__func__, "[FAIL] init east texture"));
	if (!img_load_xpm(mlx, map->sprite.file, &map->sprite))
		return (return_false(__func__, "[FAIL] init east texture"));
	return (True);
}
