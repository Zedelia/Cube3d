/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_check_texture.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 12:33:15 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 11:56:15 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

// TODO (?) on part du principe qu'un path c'est un . suivit d'un / suivit d'une chaine

static t_bool	map_check_texture_one(char *texture_path, t_mlx *mlx)
{
	int i;

	i = 0;
	if (!texture_path)
		return (return_false(__func__, "[FAIL] a texture is missing", mlx));
	if (texture_path[0] == '.' && texture_path[1] == '/')
	{
		while (texture_path[i] && texture_path[i] > 32 && texture_path[i] < 127)
			i++;
	}
	if (!texture_path[i])
		return (True);
	else
		return (return_false(__func__, "[FAIL] invalid texture path", mlx));
}

t_bool	map_check_texture(t_map *map, t_mlx *mlx)
{
	map_check_texture_one(map->north.file, mlx);
	map_check_texture_one(map->south.file, mlx);
	map_check_texture_one(map->west.file, mlx);
	map_check_texture_one(map->east.file, mlx);
	map_check_texture_one(map->sprite.file, mlx);
	if (map->sprite1.file)
		map_check_texture_one(map->sprite1.file, mlx);
	if (map->sprite2.file)
		map_check_texture_one(map->sprite2.file, mlx);
	if (map->sprite3.file)
		map_check_texture_one(map->sprite3.file, mlx);
	return (True);
}