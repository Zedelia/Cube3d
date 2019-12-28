/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_check_texture.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 12:33:15 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/28 15:27:25 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

// (?) on part du principe qu'un path c'est un . suivit d'un / suivit d'une chaine

static t_bool	map_check_texture_one(char *texture_path)
{
	if (!texture_path)
		return (return_false(__func__, "[FAIL] no texture"));
	if (texture_path[0] == '.' && texture_path[1] == '/'
					&& ft_isascii(texture_path[2]))
		return (True);
	else
		return (return_false(__func__, "[FAIL] invalid texture path"));
}

t_bool	map_check_texture(t_map *map)
{
	if (!(map_check_texture_one(map->text_north)))
		return (return_false(__func__, "[FAIL] invalid texture path - north"));
	if (!(map_check_texture_one(map->text_south)))
		return (return_false(__func__, "[FAIL] invalid texture path - south"));
	if (!(map_check_texture_one(map->text_west)))
		return (return_false(__func__, "[FAIL] invalid texture path - west"));
	if (!(map_check_texture_one(map->text_east)))
		return (return_false(__func__, "[FAIL] invalid texture path - east"));
	if (!(map_check_texture_one(map->text_sprite)))
		return (return_false(__func__, "[FAIL] invalid texture path - sprite"));
	return (True);
}