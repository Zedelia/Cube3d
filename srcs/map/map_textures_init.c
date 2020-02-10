/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_textures_init.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/18 17:32:49 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/08 12:03:11 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool		map_textures_init(t_map *map, t_mlx *mlx)
{
	if (!img_load_xpm(mlx, map->north.file, &map->north))
		return (return_false(__func__, "[FAIL] init north texture", mlx));
	if (!img_load_xpm(mlx, map->south.file, &map->south))
		return (return_false(__func__, "[FAIL] init south texture", mlx));
	if(!img_load_xpm(mlx, map->west.file, &map->west))
		return (return_false(__func__, "[FAIL] init west texture", mlx));
	if (!img_load_xpm(mlx, map->east.file, &map->east))
		return (return_false(__func__, "[FAIL] init east texture", mlx));
	if (!img_load_xpm(mlx, map->sprite.file, &map->sprite))
		return (return_false(__func__, "[FAIL] init sprite texture", mlx));
	if (map->sp1.file &&!img_load_xpm(mlx, map->sp1.file, &map->sp1))
			return (return_false(__func__, "[FAIL] init sp1 texture", mlx));
	if (map->sp2.file && !img_load_xpm(mlx, map->sp2.file, &map->sp2))
		return (return_false(__func__, "[FAIL] init sp2 texture", mlx));
	if (map->sp3.file && !img_load_xpm(mlx, map->sp3.file, &map->sp3))
		return (return_false(__func__, "[FAIL] init sp3 texture", mlx));
	return (True);
}
